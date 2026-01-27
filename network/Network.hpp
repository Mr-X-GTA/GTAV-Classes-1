#pragma once
#include "../rage/rlMetric.hpp"
#include "../security/ObfVar.hpp"
#include "CNetComplaintMgr.hpp"
#include "snSession.hpp"
#include "MatchmakingAttributes.hpp"
#include <cstring>

#pragma pack(push, 1)

class MetricSessionMigrated : public rage::rlMetric
{
public:
	char pad_0008[828]; //0x0008
	uint32_t m_num_players; //0x0344
}; //Size: 0x0348
static_assert(sizeof(MetricSessionMigrated) == 0x348);

class NetworkBaseConfig
{
public:
	virtual ~NetworkBaseConfig() = default;
	virtual void Reset() {};

	uint32_t m_build_type; //0x0008
	uint32_t m_discriminator; //0x000C
	uint32_t m_discriminator_mapping; //0x0010
	uint32_t m_region_mapping; //0x0014
	uint32_t m_language_mapping; //0x0018
	uint32_t m_mm_group_1_mapping; //0x001C
	uint32_t m_mm_group_2_mapping; //0x0020
	uint32_t m_activity_type_mapping; //0x0024
	uint32_t m_activity_id_mapping; //0x0028
	uint32_t m_activity_players_mapping; //0x002C
};
static_assert(sizeof(NetworkBaseConfig) == 0x30);

class NetworkGameConfig : public NetworkBaseConfig
{
public:
	uint32_t m_public_slots; //0x0030
	uint32_t m_private_slots; //0x0034
	MatchmakingAttributes m_matchmaking_attributes; //0x0038
	char m_pad[0x4];
}; //Size: 0x0148
static_assert(sizeof(NetworkGameConfig) == 0x148);

// this is not MatchmakingAttributes
class NetworkGameFilterMatchmakingComponent
{
public:
	// do not use for actual network filters, this will break things
	inline void SetParameter(const char* name, int index, int value)
	{
		std::strcpy(m_param_names[index], name);
		m_param_mappings[index] = index;
		m_param_values[index] = value;
		m_enabled_params_bitset |= (1 << index);

		if (m_num_parameters <= (uint32_t)index)
			m_num_parameters++;
	}

	uint32_t m_filter_type;            //0x0000
	char m_filter_name[24];            //0x0004
	uint32_t m_num_parameters;         //0x001C
	uint16_t m_game_mode;              //0x0020
	uint16_t m_session_type;           //0x0022
	uint32_t m_param_unk[8];           //0x0024
	char m_param_names[8][24];         //0x0044
	char pad_0104[4];                  //0x0104
	uint32_t m_param_mappings[8];      //0x0108
	char pad_0128[352];                //0x0128
	uint32_t m_param_values[8];        //0x0288
	char pad_02A8[96];                 //0x02A8
	uint32_t m_enabled_params_bitset;  //0x0308
	char pad_030C[8];                  //0x030C
}; //Size: 0x0314
static_assert(sizeof(NetworkGameFilterMatchmakingComponent) == 0x314);

class NetworkGameFilter : public NetworkBaseConfig
{
public:
	class NetworkGameFilterMatchmakingComponent m_matchmaking_component; //0x0030
}; //Size: 0x0344
static_assert(sizeof(NetworkGameFilter) == 0x344);

class SessionInfoBackup
{
public:
	class rage::rlSessionInfo m_session_info;
	uint32_t m_unk; //0x0070
	char pad_0074[4]; //0x0074
	uint32_t m_flags; //0x0078
}; //Size: 0x007C
static_assert(sizeof(SessionInfoBackup) == 0xDC);

class MatchmakingSessionResult
{
public:
	class rage::rlSessionDetail m_detail;
	char pad_03B8[88]; //0x03B8
}; //Size: 0x03D0
static_assert(sizeof(MatchmakingSessionResult) == 0x4D0);

class PlayerNameMapNode
{
public:
	char m_name[16]; //0x0000
	class rage::rlGamerHandle m_handle; //0x0010
	class PlayerNameMapNode* m_next; //0x0020
	class PlayerNameMapNode* m_prev; //0x0028
}; //Size: 0x0030
static_assert(sizeof(PlayerNameMapNode) == 0x30);

class JoiningPlayerNameMap
{
public:
	class PlayerNameMapNode m_names[100]; //0x0000
	char pad_12C0[40]; //0x12C0
	uint32_t m_num_name_nodes; //0x12E8
	char pad_12EC[796]; //0x12EC
}; //Size: 0x1608
static_assert(sizeof(JoiningPlayerNameMap) == 0x1608);

class CNetBlacklistNode
{
public:
	class rage::rlGamerHandle m_handle; //0x0000
	uint32_t m_added_time; //0x0010
	uint32_t unk_0014; //0x0014
	class CNetBlacklistNode* m_next; //0x0018
	class CNetBlacklistNode* m_prev; //0x0020
}; //Size: 0x0028
static_assert(sizeof(CNetBlacklistNode) == 0x28);

class CNetBlacklist
{
public:
	class CNetBlacklistNode m_nodes[32]; //0x0000
	class CNetBlacklistNode* m_head; //0x0500
	class CNetBlacklistNode* m_tail; //0x0508
	uint32_t m_free_nodes; //0x0510
	char pad_0514[4]; //0x0514
	class CNetBlacklistNode* m_start; //0x0518
	char pad_0520[24]; //0x0520
}; //Size: 0x0538
static_assert(sizeof(CNetBlacklist) == 0x538);

class RemotePlayerData
{
public:
	class rage::netGamePlayerData m_data[32]; //0x0000
	uint32_t m_count; //0x1C00
	char pad_0604[4]; //0x1C04
}; //Size: 0x1C08
static_assert(sizeof(RemotePlayerData) == 0x1C08);

class InvitedGamer
{
public:
	class rage::rlGamerHandle m_handle;
	char pad_0010[12]; //0x0010
	uint32_t m_flags; //0x001C
}; //Size: 0x0020
static_assert(sizeof(InvitedGamer) == 0x20);

class InvitedGamers
{
public:
	class InvitedGamer m_invited_gamers[100]; //0x0000
	uint32_t m_num_invited_gamers; //0x0C80
	char pad_0C84[4]; //0x0C84
}; //Size: 0x0C88
static_assert(sizeof(InvitedGamers) == 0xC88);
#pragma pack(pop)

class alignas(8) Network
{
public:
	bool m_steam_presence_allow_private_sessions; //0x0000
	rage::rlSessionInfo m_steam_presence_session; //0x0008
	rage::Obf32 m_num_dinput8_instances; //0x00D8
	rage::Obf32 m_last_time_dinput8_checked; //0x00E8
	rage::snSession m_game_session; //0x00F8
	rage::snSession m_transition_session; //0x5580
	char pad_AA08[16]; //0xAA08
	rage::snSession* m_game_session_ptr_2; //0xAA18
	rage::snSession* m_transition_session_ptr_2; //0xAA20
	char pad_AA28[16]; //0xAA28
	rage::snSession* m_game_session_ptr; //0xAA38
	rage::snSession* m_transition_session_ptr; //0xAA40
	char pad_AA48[24]; //0xAA48
	NetworkGameConfig m_network_game_config; //0xAA60
	NetworkGameConfig m_network_transition_config; //0xABA8
	char pad_ACF0[1028]; //0xACF0
	uint32_t m_game_session_state; //0xB0F4
	char pad_B0F8[79536]; //0xB0F8
	rage::rlSessionInfo m_last_joined_session; //0x1E7A8
	char pad_1E878[65632]; //0x1E878
	uint32_t m_host_candidates_sort_type[2]; //0x2E8D8 -- added b3337
	char pad_2E8E0[24]; //0x2E8E0
	CNetComplaintMgr m_game_complaint_mgr; //0x2E8F8
	CNetComplaintMgr m_transition_complaint_mgr; //0x2F990
	char pad_30A28[120304]; // 0x30A28
}; //Size: 0x4E018
static_assert(sizeof(Network) == 0x4E018);