#pragma once

#include "../rage/rlGamerInfo.hpp"
#include "../player/CNonPhysicalPlayerData.hpp"
#include "PlatformAccountId.hpp"

namespace rage
{
#pragma pack(push, 8)
    class netPlayer
    {
    public:
        virtual void* _0x00();
        virtual void* _0x08();
        virtual uint32_t _0x10();
        virtual netPlayer* _0x18(void*);
        virtual bool _0x20(void*);
        virtual bool _0x28(void**);
        virtual void destructor();
        virtual void reset();
        virtual bool is_valid();
        virtual const char* get_name();
        virtual std::uint64_t get_host_token();
        virtual void _0x58();
        virtual bool is_host();
        virtual rage::rlGamerInfo* get_net_data();
        virtual void _0x70();

        int m_account_id; //0x0008 -- added b3504
        int64_t m_rockstar_id; //0x0010 -- added b3504
        PlatformAccountId m_platform_account_id; //0x0018 -- added b3504
        uint32_t m_player_type; //0x00A8
        CNonPhysicalPlayerData* m_non_physical_player; //0x00B0
        uint32_t m_msg_id; //0x00B8
        char pad_001C[4]; //0x00BC
        uint8_t m_active_id; //0x00C0
        uint8_t m_player_id; //0x00C1
        char pad_0022[3]; //0x00C2
        uint16_t m_complaints; //0x00C6
        char pad_0027[17]; //0x00C8
        class CNetGamePlayer* m_unk_net_player_list[10]; //0x00E0
        char pad_0090[4]; //0x0130
        uint64_t pad_0098; //0x0138
    };
    static_assert(sizeof(netPlayer) == 0x140);
#pragma pack(pop)
}