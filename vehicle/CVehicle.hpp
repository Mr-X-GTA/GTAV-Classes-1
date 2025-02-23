#pragma once

#include "../entities/CPhysical.hpp"
#include "CHandlingData.hpp"

#include <cstdint>
#include <cmath>

#pragma pack(push, 1)
class CDeformation
{
public:
	char pad_0000[732]; //0x0000
}; //Size: 0x02DC
static_assert(sizeof(CDeformation) == 0x2DC);

class CVehicleDamage
{
public:
	char pad_0000[16]; //0x0000
	class CDeformation m_deformation; //0x0010
	char pad_02EC[284]; //0x02EC
	class CVehicle* m_vehicle; //0x0408
	float m_body_health; //0x0410
	float m_petrol_tank_health; //0x0414
}; //Size: 0x0418
static_assert(sizeof(CVehicleDamage) == 0x418);


class CVehicle : public rage::CPhysical
{
public:
	char pad_02EC[12]; //0x02EC
	bool m_boosting; //0x02F8
	char pad_02F9[2]; //0x02F9
	bool m_boost_allow_recharge; //0x02FB
	char pad_02FC[4]; //0x02FC
	float m_boost; //0x0300
	float m_rocket_recharge_speed; //0x0304
	char pad_0308[152]; //0x0308
	float m_jump_boost_charge; //0x03A0
	bool m_can_boost_jump; //0x03A4
	char pad_03A5[123]; //0x03A5
	class CVehicleDamage m_vehicle_damage; //0x0420
	char pad_0838[72]; //0x0838
	int16_t m_next_gear; //0x0880
	int16_t m_current_gear; //0x0882
	char pad_0884[2]; //0x0884
	int8_t m_top_gear; //0x0886
	char pad_0887[137]; //0x0887
	float m_engine_health; //0x0910
	char pad_0914[24]; //0x0914
	float m_kers_boost_max; //0x092C
	float m_kers_boost; //0x0930
	char pad_0934[44]; //0x0934
	class CHandlingData* m_handling_data; //0x0960
	char pad_0968[2]; //0x0968
	uint8_t m_drivable_bitset; //0x096A
	uint8_t m_tyre_burst_bitset; //0x096B
	uint8_t m_deform_god; //0x096C
	char pad_096D[179]; //0x096D
	float m_dirt_level; //0x0A20
	char pad_0A24[202]; //0x0A24
	bool m_is_targetable; //0x0AEE
	char pad_0AEF[313]; //0x0AEF
	uint32_t m_type; //0x0C28
	char pad_0C2C[112]; //0x0C2C
	float m_gravity; //0x0C9C
	uint8_t m_max_passengers; //0x0CA0
	char pad_0CA1[1]; //0x0CA1
	uint8_t m_num_of_passengers; //0x0CA2
	char pad_0CA3[5]; //0x0CA3
	class CPed* m_driver; //0x0CA8
	class CPed* m_passengers[15]; //0x0CB0
	class CPed* m_last_driver; //0x0CB0
	char pad_0D30[1696]; //0x0D30
	uint32_t m_door_lock_status; //0x13D0
	char pad_13D4[204]; //0x13D4
}; //Size: 0x14A0
static_assert(sizeof(CVehicle) == 0x14A0);
#pragma pack(pop)