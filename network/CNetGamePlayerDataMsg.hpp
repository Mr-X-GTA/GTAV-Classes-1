#pragma once

#include <cstdint>

#include "PlatformAccountId.hpp"

class datBitBuffer;

#pragma pack(push, 8)
namespace rage {
    class playerDataMsg
    {
    public:
        virtual ~playerDataMsg() = default;
        virtual int GetBufferSize() { return 0; };
        virtual void Log() {};
        virtual bool Serialize(datBitBuffer* buffer) { return true; };
        virtual bool Deserialize(datBitBuffer* buffer) { return true; };

        uint32_t m_game_version; //0x0008
        uint32_t m_nat_type; //0x000C
    }; //Size: 0x0010
    static_assert(sizeof(playerDataMsg) == 0x10);
}

class CNetGamePlayerDataMsg : public rage::playerDataMsg
{
public:
    int32_t m_account_id; //0x0010
    int64_t m_rockstar_id; //0x0018
    PlatformAccountId m_platform_account_id; //0x0020
    uint32_t m_player_type; //0x00B0
    uint32_t m_matchmaking_group; //0x00B4
    uint32_t m_flags; //0x00B8
    int32_t m_team; //0x00BC
    int64_t m_crew_id; //0x00C0
    int32_t m_aim_preference; //0x00C8
    uint16_t m_rank; //0x00CC
    uint16_t m_rating; //0x00CE
    uint32_t m_region; //0x00D0
}; //Size: 0x00D8
static_assert(sizeof(CNetGamePlayerDataMsg) == 0xD8);
#pragma pack(pop)