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
        uint32_t m_player_type; //0x0048
        CNonPhysicalPlayerData* m_non_physical_player; //0x0050
        uint32_t m_msg_id; //0x0058
        char pad_001C[4]; //0x005C
        uint8_t m_active_id; //0x0060
        uint8_t m_player_id; //0x0061
        uint32_t m_nat_type; //0x0064
        char pad_0068[120]; //0x0068
    };
    static_assert(sizeof(netPlayer) == 0xE0);
#pragma pack(pop)
}