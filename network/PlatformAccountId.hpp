#pragma once

#include <cstdint>

struct PlatformAccountId
{
	enum Platform : uint8_t
	{
		PLATFORM_INVALID = 0,
		PLATFORM_XBOX = 1,
		PLATFORM_STEAM = 10,
		PLATFORM_EPIC = 15
	};

	union
	{
		uint64_t m_xbox_user_id; //0x0000
		uint64_t m_steam_id;
		char m_epic_account_id[128 + 1];
		char m_pad[136];
	};

	Platform m_platform; //0x0088
};
static_assert(sizeof(PlatformAccountId) == 0x90);