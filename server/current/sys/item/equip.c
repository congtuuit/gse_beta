
#include <ansi.h>
#include <item.h>
#include <equip.h>

// 函数：生成二进制码
void SAVE_BINARY() { }

int* b_weapon = ({ 10, 0, 56, 0, 0, 0, 0, 50, 0,
			20, 0, 56, 0, 0, 0, 0, 0, 0,
			11, 0, 60, 0, 0, 0, 60, 0, 0,
			22, 0, 60, 0, 0, 0, 60, 0, 0,
			10, 0, 52, 40, 0, 0, 72, 0, 0,
			20, 0, 52, 40, 0, 0, 72, 0, 0,
			12, 0, 63, 0, 240, 0, 0, 0, 0,
			24, 0, 63, 0, 240, 0, 0, 0, 0,
			10, 0, 52, 0, 220, 0, 0, 0, 0,
			20, 0, 52, 0, 220, 0, 0, 0, 0,
			9, 0, 32, 0, 0, 0, 0, 70, 0,
			18, 0, 32, 0, 0, 0, 0, 70, 0,
			10, 0, 0, 50, 0, 0, 0, 50, 0,
			20, 0, 0, 50, 0, 0, 0, 50, 0,
			10, 0, 0, 53, 0, 160, 0, 0, 0,
			20, 0, 0, 53, 0, 160, 0, 0, 0,
			10, 0, 0, 48, 140, 0, 0, 0, 0,
			20, 0, 0, 48, 140, 0, 0, 0, 0,
			12, 12, 63, 53, 0, 0, 0, 0, 0,
			24, 24, 63, 53, 0, 0, 0, 0, 0, });
int* b_cloth = ({ 11, 7, 400, 0, 100, 0, 0, 22, 14, 400, 0, 100, 0, 0, 11, 7, 0, 0, 110, 0, 40, 22, 14, 0, 0, 110, 0, 40, 12, 6, 450, 0, 80, 0, 0, 24, 12, 450, 0, 80, 0, 0, 10, 7, 0, 0, 60, 0, 72, 20, 14, 0, 0, 60, 0, 72, 6, 12, 0, 480, 0, 68, 0, 12, 24, 0, 480, 0, 68, 0, 6, 12, 0, 400, 0, 75, 0, 12, 24, 0, 400, 0, 75, 0, 7, 12, 0, 0, 55, 70, 0, 14, 24, 0, 0, 55, 70, 0, 12, 12, 0, 0, 110, 75, 0, 24, 24, 0, 0, 110, 75, 0, });
int* b_head = ({ 6, 3, 200, 0, 60, 0, 0, 12, 6, 200, 0, 60, 0, 0, 6, 3, 0, 0, 62, 48, 0, 13, 7, 0, 0, 62, 48, 0, 7, 2, 280, 0, 55, 0, 0, 14, 5, 280, 0, 55, 0, 0, 4, 3, 0, 0, 40, 0, 60, 8, 6, 0, 0, 40, 0, 60, 3, 5, 0, 250, 0, 60, 0, 6, 10, 0, 250, 0, 60, 0, 3, 5, 0, 0, 30, 64, 0, 6, 10, 0, 0, 30, 64, 0, 4, 5, 100, 200, 0, 0, 0, 8, 10, 100, 200, 0, 0, 0, 7, 5, 0, 0, 62, 64, 0, 14, 10, 0, 0, 62, 64, 0, });
int* b_shoe = ({ 3, 3, 0, 180, 0, 50, 0, 0,
			6, 6, 0, 180, 0, 50, 0, 0,
			3, 4, 0, 0, 0, 54, 30, 0,
			6, 8, 0, 0, 0, 54, 30, 0,
			3, 3, 0, 220, 0, 46, 0, 0,
			6, 6, 0, 220, 0, 46, 0, 0,
			1, 6, 0, 0, 0, 35, 0, 80,
			2, 12, 0, 0, 0, 35, 0, 80,
			1, 2, 0, 0, 200, 0, 60, 0,
			2, 4, 0, 0, 200, 0, 60, 0,
			1, 2, 0, 0, 0, 30, 65, 0,
			2, 4, 0, 0, 0, 30, 65, 0,
			1, 2, 0, 80, 180, 0, 0, 0,
			2, 4, 0, 80, 180, 0, 0, 0,
			3, 0, 3, 0, 0, 54, 65, 0,
			6, 0, 6, 0, 0, 54, 65, 0, });
int* b_waist = ({ 5, 5, 250, 0, 60, 0, 0, 10, 10, 250, 0, 60, 0, 0, 5, 5, 0, 0, 66, 40, 0, 10, 10, 0, 0, 66, 40, 0, 5, 5, 300, 0, 55, 0, 0, 10, 10, 300, 0, 55, 0, 0, 5, 5, 0, 0, 0, 45, 30, 10, 10, 0, 0, 0, 45, 30, 5, 5, 0, 300, 0, 55, 0, 10, 10, 0, 300, 0, 55, 0, 5, 5, 0, 0, 40, 57, 0, 10, 10, 0, 0, 40, 57, 0, 5, 5, 100, 250, 0, 0, 0, 10, 10, 100, 250, 0, 0, 0, 5, 5, 0, 0, 66, 57, 0, 10, 10, 0, 0, 66, 57, 0, });
int* b_neck = ({ 0, 5, 0, 0, 0, 400, 0, 0, 50, 0, 0, 10, 0, 0, 0, 400, 0, 0, 50, 0, 0, 5, 0, 0, 30, 400, 0, 0, 0, 0, 0, 10, 0, 0, 30, 400, 0, 0, 0, 0, 0, 5, 0, 0, 0, 400, 0, 0, 50, 0, 0, 10, 0, 0, 0, 400, 0, 0, 50, 0, 0, 5, 0, 0, 0, 0, 0, 0, 50, 20, 0, 10, 0, 0, 0, 0, 0, 0, 50, 20, 10, 6, 0, 0, 30, 0, 0, 0, 70, 0, 20, 12, 0, 0, 30, 0, 0, 0, 70, 0, 10, 5, 0, 0, 0, 200, 0, 0, 80, 0, 20, 10, 0, 0, 0, 200, 0, 0, 80, 0, 10, 5, 0, 0, 0, 250, 400, 0, 0, 0, 20, 10, 0, 0, 0, 250, 400, 0, 0, 0, 10, 0, 10, 30, 30, 0, 0, 0, 0, 0, 20, 0, 20, 30, 30, 0, 0, 0, 0, 0, });

int* y_weapon =
({
		20, 0, 56, 0, 180, 0, 0, 50, 0,
		40, 0, 56, 0, 180, 0, 0, 50, 0,
		22, 0, 60, 0, 240, 0, 60, 0, 0,
		44, 0, 60, 0, 240, 0, 60, 0, 0,
		20, 0, 0, 40, 0, 0, 72, 51, 0,
		40, 0, 0, 40, 0, 0, 72, 51, 0,
		24, 0, 63, 0, 240, 0, 0, 0, 22,
		48, 0, 63, 0, 240, 0, 0, 0, 22,
		20, 0, 52, 0, 220, 0, 72, 0, 0,
		40, 0, 52, 0, 220, 0, 72, 0, 0,
		18, 0, 32, 0, 0, 80, 0, 70, 0,
		36, 0, 32, 0, 0, 80, 0, 70, 0,
		20, 0, 0, 50, 140, 0, 0, 50, 0,
		40, 0, 0, 50, 140, 0, 0, 50, 0,
		20, 0, 0, 53, 0, 160, 0, 50, 0,
		40, 0, 0, 53, 0, 160, 0, 50, 0,
		20, 0, 0, 48, 140, 140, 0, 0, 0,
		40, 0, 0, 48, 140, 140, 0, 0, 0,
		22, 20, 63, 53, 0, 0, 0, 0, 0,
		44, 40, 63, 53, 0, 0, 0, 0, 0, });

int* y_cloth = ({ 22, 14, 400, 0, 100, 0, 35, 44, 28, 400, 0, 100, 0, 35, 22, 14, 0, 0, 110, 40, 40, 44, 28, 0, 0, 110, 40, 40, 24, 12, 450, 0, 80, 0, 20, 48, 24, 450, 0, 80, 0, 20, 20, 14, 0, 0, 60, 50, 72, 40, 28, 0, 0, 60, 50, 72, 12, 24, 0, 480, 40, 68, 0, 24, 48, 0, 480, 40, 68, 0, 12, 24, 0, 400, 45, 75, 0, 24, 48, 0, 400, 45, 75, 0, 14, 24, 200, 0, 55, 70, 0, 28, 48, 200, 0, 55, 70, 0, 24, 24, 0, 0, 110, 75, 0, 48, 48, 0, 0, 110, 75, 0, });
int* y_head = ({ 12, 6, 200, 0, 60, 40, 0, 24, 12, 200, 0, 60, 40, 0, 12, 6, 0, 0, 62, 48, 40, 26, 14, 0, 0, 62, 48, 40, 14, 4, 280, 0, 55, 25, 0, 28, 10, 280, 0, 55, 25, 0, 8, 6, 0, 0, 40, 50, 60, 16, 12, 0, 0, 40, 50, 60, 6, 10, 0, 250, 30, 60, 0, 12, 20, 0, 250, 30, 60, 0, 6, 10, 100, 0, 30, 64, 0, 12, 20, 100, 0, 30, 64, 0, 8, 10, 100, 200, 35, 0, 0, 16, 20, 100, 200, 35, 0, 0, 14, 10, 0, 0, 62, 64, 0, 28, 20, 0, 0, 62, 64, 0, });
int* y_shoe = ({ 6, 6, 0, 180, 0, 50, 0, 50, 12, 12, 0, 180, 0, 50, 0, 50, 6, 8, 0, 0, 0, 54, 30, 55, 12, 16, 0, 0, 0, 54, 30, 55, 6, 6, 0, 220, 0, 46, 20, 0, 12, 12, 0, 220, 0, 46, 20, 0, 2, 12, 0, 130, 0, 35, 0, 80, 4, 24, 0, 130, 0, 35, 0, 80, 2, 4, 0, 0, 200, 30, 60, 0, 4, 8, 0, 0, 200, 30, 60, 0, 2, 4, 0, 0, 180, 30, 65, 0, 4, 8, 0, 0, 180, 30, 65, 0, 2, 4, 0, 80, 180, 0, 60, 0, 4, 8, 0, 80, 180, 0, 60, 0, 6, 0, 6, 0, 0, 54, 65, 0, 12, 0, 12, 0, 0, 54, 65, 0, });
int* y_waist = ({ 10, 10, 250, 0, 60, 35, 0, 20, 20, 250, 0, 60, 35, 0, 10, 10, 0, 0, 66, 40, 15, 20, 20, 0, 0, 66, 40, 15, 10, 10, 300, 0, 55, 25, 0, 20, 20, 300, 0, 55, 25, 0, 10, 10, 0, 0, 40, 45, 30, 20, 20, 0, 0, 40, 45, 30, 10, 10, 0, 300, 40, 55, 0, 20, 20, 0, 300, 40, 55, 0, 10, 10, 0, 250, 40, 57, 0, 20, 20, 0, 250, 40, 57, 0, 10, 10, 100, 250, 0, 57, 0, 10, 10, 0, 0, 66, 57, 0, 20, 20, 0, 0, 66, 57, 0, });
int* y_neck = ({ 0, 10, 0, 0, 0, 400, 0, 0, 50, 10, 0, 20, 0, 0, 0, 400, 0, 0, 50, 10, 0, 10, 0, 0, 30, 400, 0, 0, 54, 0, 0, 20, 0, 0, 30, 400, 0, 0, 54, 0, 0, 10, 0, 0, 0, 400, 0, 0, 50, 10, 0, 20, 0, 0, 0, 400, 0, 0, 50, 10, 0, 10, 0, 0, 0, 300, 0, 0, 50, 20, 0, 20, 0, 0, 0, 300, 0, 0, 50, 20, 20, 12, 0, 0, 30, 0, 400, 0, 70, 0, 40, 24, 0, 0, 30, 0, 400, 0, 70, 0, 20, 10, 0, 0, 0, 200, 350, 0, 80, 0, 40, 20, 0, 0, 0, 200, 350, 0, 80, 0, 20, 10, 0, 0, 0, 250, 400, 0, 75, 0, 40, 20, 0, 0, 0, 250, 400, 0, 75, 0, 20, 0, 20, 30, 30, 0, 0, 0, 0, 0, 40, 0, 40, 30, 30, 0, 0, 0, 0, 0, });

mapping mpHole = ([
	101:"Hồng Ngọc Cấp 1",
	102 : "Hoàng Ngọc Cấp 1",
	103 : "Ngọc Bích Cấp 1",
	104 : "Lam Ngọc Cấp 1",
	105 : "Ngọc Lục Bảo Cấp 1",

		201 : "Hồng Ngọc Cấp 2",
		202 : "Hoàng Ngọc Cấp 2",
		203 : "Ngọc Bích Cấp 2",
		204 : "Lam Ngọc Cấp 2",
		205 : "Ngọc Lục Bảo Cấp 2",

		301 : "Hồng Ngọc Cấp 3",
		302 : "Hoàng Ngọc Cấp 3",
		303 : "Ngọc Bích Cấp 3",
		304 : "Lam Ngọc Cấp 3",
		305 : "Ngọc Lục Bảo Cấp 3",
]);

void init_equip_prop_1(object item);
void init_equip_prop_3(object item);
int get_hole_used_amount(object item);
// 函数：增添基本属性
int add_base_prop()
{
	switch (random(10000))
	{
	case 0..6839: return 1;
	case 6840..8439: return 2;
	case 8440..9239: return 3;
	case 9240..9639: return 4;
	case 9640..9839: return 5;
	case 9840..9939: return 6;
	case 9940..9989: return 7;
	default: return 8;
	}
}

// 函数：增添特殊属性
int add_spec_prop()
{
	switch (random(10000))
	{
	case 0..8271: return 1;
	case 8272..9471: return 2;
	case 9472..9871: return 3;
	case 9872..9971: return 4;
	case 9972..9991: return 5;
	case 9992..9996: return 6;
	case 9997..9998: return 7;
	default: return 8;
	}
}

// 函数：特殊属性个数
int sizeof_spec_props(int prop)
{
	switch (random(100000))    // 注意：100000
	{
	case 0..6999: return range_value(1, 0, prop);
	case 7000..7499: return range_value(2, 0, prop);
	case 7500..7949: return range_value(3, 0, prop);
	case 7950..7974: return range_value(4, 0, prop);
	case 7975..7999: return range_value(5, 0, prop);
	default: return 0;
	}
}

// 函数：初始化装备 (普通怪物掉装备专用)
void init_equip_prop(object item)
{
	int i, color;
	i = random(10000);
	color = item->get_item_color();
	if (color == 1 || color == 2 || color == 3) return;
	if (i < 9950) return;
	init_equip_prop_1(item);
}

// 函数：初始化装备(具有特殊属性) 蓝色装备
void init_equip_prop_1(object item)
{
	int pos, family, level, ran, i, less, value, point;
	if (!clonep(item)) return;    // 只对复制物品！
	family = item->get_family();
	if (family == 9) family = 2;  // 法剑按蜀山的剑的能力
	if (family > 8) family = 8;
	if (family <= 0) family = 8;
	level = item->get_level();
	point = level / 12 + random(1 + level / 20);
	switch (item->get_equip_type())
	{
	case WEAPON_TYPE:
		switch (family)
		{
		case 1: pos = 8 * 9; break;
		case 2:
			if (item->get_weapon_type() == SWORD) pos = 4 * 9;
			else pos = 0;
			break;
		case 3:
			if (item->get_weapon_type() == SPEAR) pos = 2 * 9;
			else pos = 6 * 9;
			break;
		case 4: pos = 10 * 9; break;
		case 5: pos = 12 * 9; break;
		case 6: pos = 14 * 9; break;
		case 7: pos = 16 * 9; break;
		default: pos = 18 * 9; break;
		}
		if (level >= 80) pos += 9;
		if (pos >= sizeof(b_weapon)) return;
		item->add("ap", b_weapon[pos]);		// 增加攻击力
		item->add("cp", b_weapon[pos + 1]);		// 增加法术攻击力
		ran = random(10000);
		less = 10000;
		for (i = 2; i < 9; i++)
		{
			if (b_weapon[pos + i] != 0)
			{
				value = b_weapon[pos + i] * point * ran / 100000;
				less -= ran;
				ran = less;
				switch (i)
				{
				case 2: item->add("ap", value); break;
				case 3: item->add("cp", value); break;
				case 4: item->add("hp", value); break;
				case 5: item->add("mp", value); break;
				case 6: item->add("dp", value); break;
				case 7: item->add("pp", value); break;
				case 8: item->add("sp", value); break;
				}
				if (less <= 0) break;
			}
		}
		break;
	case ARMOR_TYPE:
		pos = (family - 1) * 14;
		if (pos < 0) pos = 0;
		if (level >= 80) pos += 7;
		if (pos >= sizeof(b_cloth)) return;
		item->add("dp", b_cloth[pos]);
		item->add("pp", b_cloth[pos + 1]);
		ran = random(10000);
		less = 10000;
		for (i = 2; i < 7; i++)
		{
			if (b_cloth[pos + i] != 0)
			{
				value = b_cloth[pos + i] * point * ran / 100000;
				less -= ran;
				ran = less;
				switch (i)
				{
				case 2: item->add("hp", value); break;
				case 3: item->add("mp", value); break;
				case 4: item->add("dp", value); break;
				case 5: item->add("pp", value); break;
				case 6: item->add("sp", value); break;
				}
				if (less <= 0) break;
			}
		}
		break;
	case HEAD_TYPE:
		pos = (family - 1) * 14;
		if (pos < 0) pos = 0;
		if (level >= 80) pos += 7;
		if (pos >= sizeof(b_head)) return;
		item->add("dp", b_head[pos]);
		item->add("pp", b_head[pos + 1]);
		ran = random(10000);
		less = 10000;
		for (i = 2; i < 7; i++)
		{
			if (b_head[pos + i] != 0)
			{
				value = b_head[pos + i] * point * ran / 100000;
				less -= ran;
				ran = less;
				switch (i)
				{
				case 2: item->add("hp", value); break;
				case 3: item->add("mp", value); break;
				case 4: item->add("dp", value); break;
				case 5: item->add("pp", value); break;
				case 6: item->add("sp", value); break;
				}
				if (less <= 0) break;
			}
		}
		break;
	case BOOTS_TYPE:
		pos = (family - 1) * 16;
		if (pos < 0) pos = 0;
		if (level >= 80) pos += 8;
		if (pos >= sizeof(b_shoe)) return;
		item->add("dp", b_shoe[pos]);
		item->add("sp", b_shoe[pos + 1]);
		item->add("pp", b_shoe[pos + 2]);
		ran = random(10000);
		less = 10000;
		for (i = 3; i < 8; i++)
		{
			if (b_shoe[pos + i] != 0)
			{
				value = b_shoe[pos + i] * point * ran / 100000;
				less -= ran;
				ran = less;
				switch (i)
				{
				case 3: item->add("hp", value); break;
				case 4: item->add("mp", value); break;
				case 5: item->add("dp", value); break;
				case 6: item->add("pp", value); break;
				case 7: item->add("sp", value); break;
				}
				if (less <= 0) break;
			}
		}
		break;
	case WAIST_TYPE:
		pos = (family - 1) * 14;
		if (pos < 0) pos = 0;
		if (level >= 80) pos += 7;
		if (pos >= sizeof(b_waist)) return;
		item->add("dp", b_waist[pos]);
		item->add("pp", b_waist[pos + 1]);
		ran = random(10000);
		less = 10000;
		for (i = 2; i < 7; i++)
		{
			if (b_waist[pos + i] != 0)
			{
				value = b_waist[pos + i] * point * ran / 100000;
				less -= ran;
				ran = less;
				switch (i)
				{
				case 2: item->add("hp", value); break;
				case 3: item->add("mp", value); break;
				case 4: item->add("dp", value); break;
				case 5: item->add("pp", value); break;
				case 6: item->add("sp", value); break;
				}
				if (less <= 0) break;
			}
		}
		break;
	case NECK_TYPE:
		pos = (family - 1) * 20;
		if (pos < 0) pos = 0;
		if (level >= 80) pos += 10;
		if (pos >= sizeof(b_neck)) return;
		item->add("cp", b_neck[pos]);
		item->add("pp", b_neck[pos + 1]);
		item->add("ap", b_neck[pos + 2]);
		ran = random(10000);
		less = 10000;
		for (i = 3; i < 10; i++)
		{
			if (b_neck[pos + i] != 0)
			{
				value = b_neck[pos + i] * point * ran / 100000;
				less -= ran;
				ran = less;
				switch (i)
				{
				case 3: item->add("ap", value); break;
				case 4: item->add("cp", value); break;
				case 5: item->add("hp", value); break;
				case 6: item->add("mp", value); break;
				case 7: item->add("dp", value); break;
				case 8: item->add("pp", value); break;
				case 9: item->add("sp", value); break;
				}
				if (less <= 0) break;
			}
		}
		break;
	}
	item->set_item_color(1);
	item->set_bind(1);
	"/sys/sys/count"->add_equip("blue", 1);
}

// 函数：初始化装备(全部特殊属性)  金色装备
void init_equip_prop_3(object item)
{
	int pos, family, level, ran, i, j, less, value, point;
	object me = this_player();
	if (!clonep(item)) return;    // 只对复制物品！
	family = item->get_family();
	if (family == 9) family = 2;
	if (family > 8) family = 8;
	if (family <= 0) family = 8;
	level = item->get_level();
	point = level / 6 + random(3 + level / 24);
	switch (item->get_equip_type())
	{
	case WEAPON_TYPE:
		switch (family)
		{
		case 1: pos = 8 * 9; break;
		case 2:
			if (item->get_weapon_type() == SWORD) pos = 4 * 9;
			else pos = 0;
			break;
		case 3:
			if (item->get_weapon_type() == SPEAR) pos = 2 * 9;
			else pos = 6 * 9;
			break;
		case 4: pos = 10 * 9; break;
		case 5: pos = 12 * 9; break;
		case 6: pos = 14 * 9; break;
		case 7: pos = 16 * 9; break;
		default: pos = 18 * 9; break;
		}
		if (level >= 80) pos += 9;
		if (pos >= sizeof(y_weapon)) return;
		item->add("ap", y_weapon[pos]);		// 增加攻击力
		item->add("cp", y_weapon[pos + 1]);	// 增加法术攻击力
		ran = random(10000);
		less = 10000;
		j = 0;
		for (i = 2; i < 9; i++)
		{
			if (y_weapon[pos + i] != 0)
			{
				value = y_weapon[pos + i] * point * ran / 100000;
				less -= ran;
				j++;
				if (j >= 2)
					ran = less;
				else
					ran = random(less);
				switch (i)
				{
				case 2: item->add("ap", value); break;
				case 3: item->add("cp", value); break;
				case 4: item->add("hp", value); break;
				case 5: item->add("mp", value); break;
				case 6: item->add("dp", value); break;
				case 7: item->add("pp", value); break;
				case 8: item->add("sp", value); break;
				}
				if (less <= 0) break;
			}
		}
		break;
	case ARMOR_TYPE:
		pos = (family - 1) * 14;
		if (pos < 0) pos = 0;
		if (level >= 80) pos += 7;
		if (pos >= sizeof(y_cloth)) return;
		item->add("dp", y_cloth[pos]);
		item->add("pp", y_cloth[pos + 1]);
		ran = random(10000);
		less = 10000;
		j = 0;
		for (i = 2; i < 7; i++)
		{
			if (y_cloth[pos + i] != 0)
			{
				value = y_cloth[pos + i] * point * ran / 100000;
				less -= ran;
				j++;
				if (j >= 2)
					ran = less;
				else
					ran = random(less);
				switch (i)
				{
				case 2: item->add("hp", value); break;
				case 3: item->add("mp", value); break;
				case 4: item->add("dp", value); break;
				case 5: item->add("pp", value); break;
				case 6: item->add("sp", value); break;
				}
				if (less <= 0) break;
			}
		}
		break;
	case HEAD_TYPE:
		pos = (family - 1) * 14;
		if (pos < 0) pos = 0;
		if (level >= 80) pos += 7;
		if (pos >= sizeof(y_head)) return;
		item->add("dp", y_head[pos]);
		item->add("pp", y_head[pos + 1]);
		ran = random(10000);
		less = 10000;
		j = 0;
		for (i = 2; i < 7; i++)
		{
			if (y_head[pos + i] != 0)
			{
				value = y_head[pos + i] * point * ran / 100000;
				less -= ran;
				j++;
				if (j >= 2)
					ran = less;
				else
					ran = random(less);
				switch (i)
				{
				case 2: item->add("hp", value); break;
				case 3: item->add("mp", value); break;
				case 4: item->add("dp", value); break;
				case 5: item->add("pp", value); break;
				case 6: item->add("sp", value); break;
				}
				if (less <= 0) break;
			}
		}
		break;
	case BOOTS_TYPE:
		pos = (family - 1) * 16;
		if (pos < 0) pos = 0;
		if (level >= 80) pos += 8;
		if (pos >= sizeof(y_shoe)) return;
		item->add("dp", y_shoe[pos]);
		item->add("sp", y_shoe[pos + 1]);
		item->add("pp", y_shoe[pos + 2]);
		ran = random(10000);
		less = 10000;
		j = 0;
		for (i = 3; i < 8; i++)
		{
			if (y_shoe[pos + i] != 0)
			{
				value = y_shoe[pos + i] * point * ran / 100000;
				less -= ran;
				j++;
				if (j >= 2)
					ran = less;
				else
					ran = random(less);
				switch (i)
				{
				case 3: item->add("hp", value); break;
				case 4: item->add("mp", value); break;
				case 5: item->add("dp", value); break;
				case 6: item->add("pp", value); break;
				case 7: item->add("sp", value); break;
				}
				if (less <= 0) break;
			}
		}
		break;
	case WAIST_TYPE:
		pos = (family - 1) * 14;
		if (pos < 0) pos = 0;
		if (level >= 80) pos += 7;
		if (pos >= sizeof(y_waist)) return;
		item->add("dp", y_waist[pos]);
		item->add("pp", y_waist[pos + 1]);
		ran = random(10000);
		less = 10000;
		j = 0;
		for (i = 2; i < 7; i++)
		{
			if (y_waist[pos + i] != 0)
			{
				value = y_waist[pos + i] * point * ran / 100000;
				less -= ran;
				j++;
				if (j >= 2)
					ran = less;
				else
					ran = random(less);
				switch (i)
				{
				case 2: item->add("hp", value); break;
				case 3: item->add("mp", value); break;
				case 4: item->add("dp", value); break;
				case 5: item->add("pp", value); break;
				case 6: item->add("sp", value); break;
				}
				if (less <= 0) break;
			}
		}
		break;
	case NECK_TYPE:
		pos = (family - 1) * 20;
		if (pos < 0) pos = 0;
		if (level >= 80) pos += 10;
		if (pos >= sizeof(y_neck)) return;
		item->add("cp", y_neck[pos]);
		item->add("pp", y_neck[pos + 1]);
		item->add("ap", y_neck[pos + 2]);
		ran = random(10000);
		less = 10000;
		j = 0;
		for (i = 3; i < 10; i++)
		{
			if (y_neck[pos + i] != 0)
			{
				value = y_neck[pos + i] * point * ran / 100000;
				less -= ran;
				j++;
				if (j >= 2)
					ran = less;
				else
					ran = random(less);
				switch (i)
				{
				case 3: item->add("ap", value); break;
				case 4: item->add("cp", value); break;
				case 5: item->add("hp", value); break;
				case 6: item->add("mp", value); break;
				case 7: item->add("dp", value); break;
				case 8: item->add("pp", value); break;
				case 9: item->add("sp", value); break;
				}
				if (less <= 0) break;
			}
		}
		break;
	}
	item->set_item_color(2);
	item->set_bind(1);
	"/sys/sys/count"->add_equip("yellow", 1);
}

// 函数：初始化装备(全部特殊属性)  金色装备
void init_equip_prop_12345(object item)
{
	int pos, family, level, ran, i, j, less, value, point;
	object me = this_player();
	if (!clonep(item)) return;    // 只对复制物品！
	family = item->get_family();
	if (family == 9) family = 2;
	if (family > 8) family = 8;
	if (family <= 0) family = 8;
	level = item->get_level();
	point = level / 6 + random(3 + level / 24);
	switch (item->get_equip_type())
	{
	case WEAPON_TYPE:
		switch (family)
		{
		case 1: pos = 8 * 9; break;
		case 2:
			if (item->get_weapon_type() == SWORD) pos = 4 * 9;
			else pos = 0;
			break;
		case 3:
			if (item->get_weapon_type() == SPEAR) pos = 2 * 9;
			else pos = 6 * 9;
			break;
		case 4: pos = 10 * 9; break;
		case 5: pos = 12 * 9; break;
		case 6: pos = 14 * 9; break;
		case 7: pos = 16 * 9; break;
		default: pos = 18 * 9; break;
		}
		if (level >= 80) pos += 9;
		if (pos >= sizeof(y_weapon)) return;
		item->add("ap", y_weapon[pos]);		// 增加攻击力
		item->add("cp", y_weapon[pos + 1]);	// 增加法术攻击力
		ran = random(10000);
		less = 10000;
		j = 0;
		for (i = 2; i < 9; i++)
		{
			if (y_weapon[pos + i] != 0)
			{
				value = y_weapon[pos + i] * point * ran / 100000;
				less -= ran;
				j++;
				if (j >= 2)
					ran = less;
				else
					ran = random(less);
				switch (i)
				{
				case 2: item->add("ap", value); break;
				case 3: item->add("cp", value); break;
				case 4: item->add("hp", value); break;
				case 5: item->add("mp", value); break;
				case 6: item->add("dp", value); break;
				case 7: item->add("pp", value); break;
				case 8: item->add("sp", value); break;
				}
				if (less <= 0) break;
			}
		}
		break;
	case ARMOR_TYPE:
		pos = (family - 1) * 14;
		if (pos < 0) pos = 0;
		if (level >= 80) pos += 7;
		if (pos >= sizeof(y_cloth)) return;
		item->add("dp", y_cloth[pos]);
		item->add("pp", y_cloth[pos + 1]);
		ran = random(10000);
		less = 10000;
		j = 0;
		for (i = 2; i < 7; i++)
		{
			if (y_cloth[pos + i] != 0)
			{
				value = y_cloth[pos + i] * point * ran / 100000;
				less -= ran;
				j++;
				if (j >= 2)
					ran = less;
				else
					ran = random(less);
				switch (i)
				{
				case 2: item->add("hp", value); break;
				case 3: item->add("mp", value); break;
				case 4: item->add("dp", value); break;
				case 5: item->add("pp", value); break;
				case 6: item->add("sp", value); break;
				}
				if (less <= 0) break;
			}
		}
		break;
	case HEAD_TYPE:
		pos = (family - 1) * 14;
		if (pos < 0) pos = 0;
		if (level >= 80) pos += 7;
		if (pos >= sizeof(y_head)) return;
		item->add("dp", y_head[pos]);
		item->add("pp", y_head[pos + 1]);
		ran = random(10000);
		less = 10000;
		j = 0;
		for (i = 2; i < 7; i++)
		{
			if (y_head[pos + i] != 0)
			{
				value = y_head[pos + i] * point * ran / 100000;
				less -= ran;
				j++;
				if (j >= 2)
					ran = less;
				else
					ran = random(less);
				switch (i)
				{
				case 2: item->add("hp", value); break;
				case 3: item->add("mp", value); break;
				case 4: item->add("dp", value); break;
				case 5: item->add("pp", value); break;
				case 6: item->add("sp", value); break;
				}
				if (less <= 0) break;
			}
		}
		break;
	case BOOTS_TYPE:
		pos = (family - 1) * 16;
		if (pos < 0) pos = 0;
		if (level >= 80) pos += 8;
		if (pos >= sizeof(y_shoe)) return;
		item->add("dp", y_shoe[pos]);
		item->add("sp", y_shoe[pos + 1]);
		item->add("pp", y_shoe[pos + 2]);
		ran = random(10000);
		less = 10000;
		j = 0;
		for (i = 3; i < 8; i++)
		{
			if (y_shoe[pos + i] != 0)
			{
				value = y_shoe[pos + i] * point * ran / 100000;
				less -= ran;
				j++;
				if (j >= 2)
					ran = less;
				else
					ran = random(less);
				switch (i)
				{
				case 3: item->add("hp", value); break;
				case 4: item->add("mp", value); break;
				case 5: item->add("dp", value); break;
				case 6: item->add("pp", value); break;
				case 7: item->add("sp", value); break;
				}
				if (less <= 0) break;
			}
		}
		break;
	case WAIST_TYPE:
		pos = (family - 1) * 14;
		if (pos < 0) pos = 0;
		if (level >= 80) pos += 7;
		if (pos >= sizeof(y_waist)) return;
		item->add("dp", y_waist[pos]);
		item->add("pp", y_waist[pos + 1]);
		ran = random(10000);
		less = 10000;
		j = 0;
		for (i = 2; i < 7; i++)
		{
			if (y_waist[pos + i] != 0)
			{
				value = y_waist[pos + i] * point * ran / 100000;
				less -= ran;
				j++;
				if (j >= 2)
					ran = less;
				else
					ran = random(less);
				switch (i)
				{
				case 2: item->add("hp", value); break;
				case 3: item->add("mp", value); break;
				case 4: item->add("dp", value); break;
				case 5: item->add("pp", value); break;
				case 6: item->add("sp", value); break;
				}
				if (less <= 0) break;
			}
		}
		break;
	case NECK_TYPE:
		pos = (family - 1) * 20;
		if (pos < 0) pos = 0;
		if (level >= 80) pos += 10;
		if (pos >= sizeof(y_neck)) return;
		item->add("cp", y_neck[pos]);
		item->add("pp", y_neck[pos + 1]);
		item->add("ap", y_neck[pos + 2]);
		ran = random(10000);
		less = 10000;
		j = 0;
		for (i = 3; i < 10; i++)
		{
			if (y_neck[pos + i] != 0)
			{
				value = y_neck[pos + i] * point * ran / 100000;
				less -= ran;
				j++;
				if (j >= 2)
					ran = less;
				else
					ran = random(less);
				switch (i)
				{
				case 3: item->add("ap", value); break;
				case 4: item->add("cp", value); break;
				case 5: item->add("hp", value); break;
				case 6: item->add("mp", value); break;
				case 7: item->add("dp", value); break;
				case 8: item->add("pp", value); break;
				case 9: item->add("sp", value); break;
				}
				if (less <= 0) break;
			}
		}
		break;
	}
	item->set_item_color(3);
	item->set_bind(1);
	"/sys/sys/count"->add_equip("T", 1);
}

//掉落装备属性生成 (大boss怪物掉装备专用)
void init_equip_prop_2(object item)
{
	int i, color;
	i = random(10000);
	color = item->get_item_color();
	if (color == 1 || color == 2 || color == 3) return;
	if (i < 9500) init_equip_prop_1(item);
	else
		init_equip_prop_3(item);
}

//掉落装备属性生成 (boss怪物掉装备专用)
void init_equip_prop_4(object item)
{
	int i, color;
	i = random(10000);
	color = item->get_item_color();
	if (color == 1 || color == 2 || color == 3) return;
	if (i < 8940) return;
	if (i < 9990) init_equip_prop_1(item);
	else
		init_equip_prop_3(item);
}
// -------------------------------------------------------------

// 函数：获取属性字串
string get_save_prop_string(object item)
{
	string prop, result;
	int point, mau1, mau2, mauvk, holeExp;

	result = "";

	if (point = item->get("hp")) result += sprintf("hp:%d,", point);
	if (point = item->get("hpp")) result += sprintf("hpp:%d,", point);
	if (point = item->get("hp2")) result += sprintf("hp2:%d,", point);
	if (point = item->get("hp3")) result += sprintf("hp3:%d,", point);
	if (point = item->get("hp4")) result += sprintf("hp4:%d,", point);
	if (point = item->get("hp%")) result += sprintf("hp%%:%d,", point);
	if (point = item->get("hp*")) result += sprintf("hp*:%d,", point);
	if (point = item->get("mp")) result += sprintf("mp:%d,", point);
	if (point = item->get("mpp")) result += sprintf("mpp:%d,", point);
	if (point = item->get("mp2")) result += sprintf("mp2:%d,", point);
	if (point = item->get("mp3")) result += sprintf("mp3:%d,", point);
	if (point = item->get("mp4")) result += sprintf("mp4:%d,", point);
	if (point = item->get("mp%")) result += sprintf("mp%%:%d,", point);
	if (point = item->get("mp*")) result += sprintf("mp*:%d,", point);
	if (point = item->get("ap")) result += sprintf("ap:%d,", point);
	if (point = item->get("app")) result += sprintf("app:%d,", point);
	if (point = item->get("ap2")) result += sprintf("ap2:%d,", point);
	if (point = item->get("ap3")) result += sprintf("ap3:%d,", point);
	if (point = item->get("ap4")) result += sprintf("ap4:%d,", point);
	if (point = item->get("double")) result += sprintf("double:%d,", point);
	if (point = item->get("double2")) result += sprintf("double2:%d,", point);
	if (point = item->get("ap%")) result += sprintf("ap%%:%d,", point);
	if (point = item->get("aps%")) result += sprintf("aps%%:%d,", point);
	if (point = item->get("dp")) result += sprintf("dp:%d,", point);
	if (point = item->get("dpp")) result += sprintf("dpp:%d,", point);
	if (point = item->get("dp2")) result += sprintf("dp2:%d,", point);
	if (point = item->get("dp3")) result += sprintf("dp3:%d,", point);
	if (point = item->get("dp4")) result += sprintf("dp4:%d,", point);
	if (point = item->get("cp")) result += sprintf("cp:%d,", point);
	if (point = item->get("cpp")) result += sprintf("cpp:%d,", point);
	if (point = item->get("cp2")) result += sprintf("cp2:%d,", point);
	if (point = item->get("cp3")) result += sprintf("cp3:%d,", point);
	if (point = item->get("cp4")) result += sprintf("cp4:%d,", point);
	if (point = item->get("cp%")) result += sprintf("cp%%:%d,", point);
	if (point = item->get("cps%")) result += sprintf("cps%%:%d,", point);
	if (point = item->get("pp")) result += sprintf("pp:%d,", point);
	if (point = item->get("ppp")) result += sprintf("ppp:%d,", point);
	if (point = item->get("pp2")) result += sprintf("pp2:%d,", point);
	if (point = item->get("pp3")) result += sprintf("pp3:%d,", point);
	if (point = item->get("pp4")) result += sprintf("pp4:%d,", point);
	if (point = item->get("sp")) result += sprintf("sp:%d,", point);
	if (point = item->get("sp2")) result += sprintf("sp2:%d,", point);
	if (point = item->get("sp3")) result += sprintf("sp3:%d,", point);
	if (point = item->get("sp4")) result += sprintf("sp4:%d,", point);
	if (point = item->get("!%")) result += sprintf("!%%:%d,", point);
	if (point = item->get("c!%")) result += sprintf("c!%%:%d,", point);
	if (point = item->get("t!%")) result += sprintf("t!%%:%d,", point);
	if (point = item->get("?%")) result += sprintf("?%%:%d,", point);
	if (point = item->get("c?%")) result += sprintf("c?%%:%d,", point);
	if (point = item->get("-*")) result += sprintf("-*:%d,", point);
	if (point = item->get("-*%")) result += sprintf("-*%%:%d,", point);
	if (point = item->get("-c*")) result += sprintf("-c*:%d", point);
	if (point = item->get("-c*%")) result += sprintf("-c*%%:%d,", point);
	//if( point = item->get_poison() ) result += sprintf(  "@:%d,", point );
	if (point = item->get("@%")) result += sprintf("@%%:%d,", point);
	if (point = item->get("X@%")) result += sprintf("X@%%:%d,", point);
	if (point = item->get("-@%")) result += sprintf("-@%%:%d,", point);
	if (point = item->get("/%")) result += sprintf("/%%:%d,", point);
	if (point = item->get("??%")) result += sprintf("??%%:%d,", point);
	if (point = item->get("#%")) result += sprintf("#%%:%d,", point);
	if (point = item->get("-1-"))  result += sprintf("-1-:%d,", point);
	if (point = item->get("hp+@"))  result += sprintf("hp+@:%d,", point);
	if (point = item->get("mp+@"))  result += sprintf("mp+@:%d,", point);
	if (point = item->get("-anti_hurt%"))  result += sprintf("-anti_hurt%%:%d,", point);

	if (point = item->get("stoneHP+"))  result += sprintf("stoneHP+:%d,", point);
	if (point = item->get("stoneAP+"))  result += sprintf("stoneAP+:%d,", point);
	if (point = item->get("stoneCP+"))  result += sprintf("stoneCP+:%d,", point);
	if (point = item->get("stoneDP+"))  result += sprintf("stoneDP+:%d,", point);
	if (point = item->get("stonePP+"))  result += sprintf("stonePP+:%d,", point);

	if (point = item->get("stoneHP++"))  result += sprintf("stoneHP++:%d,", point);
	if (point = item->get("stoneAP++"))  result += sprintf("stoneAP++:%d,", point);
	if (point = item->get("stoneCP++"))  result += sprintf("stoneCP++:%d,", point);
	if (point = item->get("stoneDP++"))  result += sprintf("stoneDP++:%d,", point);
	if (point = item->get("stonePP++"))  result += sprintf("stonePP++:%d,", point);

	if (point = item->get("stoneHP+++"))  result += sprintf("stoneHP+++:%d,", point);
	if (point = item->get("stoneAP+++"))  result += sprintf("stoneAP+++:%d,", point);
	if (point = item->get("stoneCP+++"))  result += sprintf("stoneCP+++:%d,", point);
	if (point = item->get("stoneDP+++"))  result += sprintf("stoneDP+++:%d,", point);
	if (point = item->get("stonePP+++"))  result += sprintf("stonePP+++:%d,", point);


	if (point = item->get("goldAP+"))  result += sprintf("goldAP+:%d,", point);
	if (point = item->get("goldCP+"))  result += sprintf("goldCP+:%d,", point);
	if (point = item->get("goldDP+"))  result += sprintf("goldDP+:%d,", point);
	if (point = item->get("goldPP+"))  result += sprintf("goldPP+:%d,", point);


	if (point = item->get("gold_time")) result += sprintf("gold_time:%d,", point);
	if (point = item->get_weapon_color()) result += sprintf("weaponColor:%d,", point);

	if (mau1 = item->get_back_color()) result += sprintf("mau1:%d,", mau1);
	if (mau2 = item->get_back2_color()) result += sprintf("mau2:%d,", mau2);
	if (mauvk = item->get("mauvk")) result += sprintf("mauvk:%d,", mauvk);

	if (holeExp = item->get("holeExp_0")) result += sprintf("holeExp_0:%d,", holeExp);
	if (holeExp = item->get("holeExp_1")) result += sprintf("holeExp_1:%d,", holeExp);
	if (holeExp = item->get("holeExp_2")) result += sprintf("holeExp_2:%d,", holeExp);

	if (point = item->get("itemExp")) result += sprintf("itemExp:%d,", point);
	if (point = item->get("itemLevel")) result += sprintf("itemLevel:%d,", point);
	if (point = item->get("itemLife")) result += sprintf("itemLife:%d,", point);


	//	if( point = item->get("mau+@" ) )  result += sprintf("mau+@:%d,", point );
	 //   if( point = item->get("mana+@" ) )  result += sprintf("mana+@:%d,", point );
	if (point = item->get("yuan+@"))  result += sprintf("yuan+@:%d,", point);
	if (point = item->get("cp+@"))  result += sprintf("cp+@:%d,", point);
	if (point = item->get("heal+@"))  result += sprintf("heal+@:%d,", point);
	if (prop = item->get_make_prop()) result += sprintf("ADD:%s,", prop);
	if (point = item->get_bind()) result += sprintf("bind:%d,", point);
	if ((point = item->get_hide()) && item->get_level() >= 30) result += sprintf("hide:%d,", point);
	result += sprintf("=:%d,", item->get_item_color());    // 禁止再有字串 "=:", 见 pawn
	result += sprintf("+:%d,", item->get_item_level());    // 禁止再有字串 "+:", 见 pawn
	result += sprintf("$:%d,", item->get_value());
	result += sprintf("B:%d,", item->get_nh());
	if (item->get("make") != 0 && item->get("make") != "") result += sprintf("make:%s,", item->get("make"));
	if (item->get("forge") != 0 && item->get("forge") != "") result += sprintf("forge:%s,", item->get("forge"));
	if (item->get("sao") != 0 && item->get("sao") != "") result += sprintf("sao:%s,", item->get("sao"));
	if (item->get("hole") != 0 && item->get("hole") != "") result += sprintf("hole:%s,", item->get("hole"));
	if (item->get_product_id() != 0 && item->get_product_id() != "") result += sprintf("product:%s,", item->get_product_id());
	return result;
}

// 函数：获取属性字串(当铺)
string get_save_prop_string_2(object item)
{
	string prop, result;
	int point;

	result = "";

	if (point = item->get("ap")) { result += sprintf("ap:%d,", point);    result += sprintf("|ap:%d,", to_int(point + item->get("ap+"))); }
	if (point = item->get("app")) { result += sprintf("app:%d,", point); }
	if (point = item->get("ap2")) { result += sprintf("ap2:%d,", point); }
	if (point = item->get("ap3")) { result += sprintf("ap3:%d,", point); }
	if (point = item->get("double")) { result += sprintf("double:%d,", point); }
	if (point = item->get("double2")) { result += sprintf("double2:%d,", point); }
	if (point = item->get("ap%")) { result += sprintf("ap%%:%d,", point);  result += sprintf("|ap%%:%d,", to_int(point + item->get("ap%+"))); }
	if (point = item->get("aps%")) { result += sprintf("aps%%:%d,", point);  result += sprintf("|aps%%:%d,", to_int(point)); }
	if (point = item->get("!%")) { result += sprintf("!%%:%d,", point);  result += sprintf("|!%%:%d,", to_int(point + item->get("!%+"))); }
	if (point = item->get("cp")) { result += sprintf("cp:%d,", point);    result += sprintf("|cp:%d,", to_int(point + item->get("cp+"))); }
	if (point = item->get("cpp")) { result += sprintf("cpp:%d,", point); }
	if (point = item->get("cp2")) { result += sprintf("cp2:%d,", point); }
	if (point = item->get("cp3")) { result += sprintf("cp3:%d,", point); }
	if (point = item->get("cp%")) { result += sprintf("cp%%:%d,", point);  result += sprintf("|cp%%:%d,", to_int(point + item->get("cp%+"))); }
	if (point = item->get("cps%")) { result += sprintf("cps%%:%d,", point);  result += sprintf("|cps%%:%d,", to_int(point)); }
	if (point = item->get("c!%")) { result += sprintf("c!%%:%d,", point);  result += sprintf("|c!%%:%d,", to_int(point + item->get("c!%+"))); }
	if (point = item->get("t!%")) { result += sprintf("t!%%:%d,", point);  result += sprintf("|t!%%:%d,", to_int(point + item->get("t!%+"))); }
	if (point = item->get("dp")) { result += sprintf("dp:%d,", point);    result += sprintf("|dp:%d,", to_int(point + item->get("dp+"))); }
	if (point = item->get("dpp")) { result += sprintf("dpp:%d,", point); }
	if (point = item->get("dp2")) { result += sprintf("dp2:%d,", point); }
	if (point = item->get("dp3")) { result += sprintf("dp3:%d,", point); }
	if (point = item->get("pp")) { result += sprintf("pp:%d,", point);    result += sprintf("|pp:%d,", to_int(point + item->get("pp+"))); }
	if (point = item->get("ppp")) { result += sprintf("ppp:%d,", point); }
	if (point = item->get("pp2")) { result += sprintf("pp2:%d,", point); }
	if (point = item->get("pp3")) { result += sprintf("pp3:%d,", point); }
	if (point = item->get("hp")) { result += sprintf("hp:%d,", point);    result += sprintf("|hp:%d,", to_int(point + item->get("hp+"))); }
	if (point = item->get("hpp")) { result += sprintf("hpp:%d,", point); }
	if (point = item->get("hp2")) { result += sprintf("hp2:%d,", point); }
	if (point = item->get("hp3")) { result += sprintf("hp3:%d,", point); }
	if (point = item->get("hp%")) { result += sprintf("hp%%:%d,", point);  result += sprintf("|hp%%:%d,", to_int(point + item->get("hp%+"))); }
	if (point = item->get("mp")) { result += sprintf("mp:%d,", point);    result += sprintf("|mp:%d,", to_int(point + item->get("mp+"))); }
	if (point = item->get("mpp")) { result += sprintf("mpp:%d,", point); }
	if (point = item->get("mp2")) { result += sprintf("mp2:%d,", point); }
	if (point = item->get("mp3")) { result += sprintf("mp3:%d,", point); }
	if (point = item->get("mp%")) { result += sprintf("mp%%:%d,", point);  result += sprintf("|mp%%:%d,", to_int(point + item->get("mp%+"))); }
	if (point = item->get("hp*")) { result += sprintf("hp*:%d,", point);   result += sprintf("|hp*:%d,", to_int(point + item->get("hp*+"))); }
	if (point = item->get("mp*")) { result += sprintf("mp*:%d,", point);   result += sprintf("|mp*:%d,", to_int(point + item->get("mp*+"))); }
	if (point = item->get("sp")) { result += sprintf("sp:%d,", point);    result += sprintf("|sp:%d,", to_int(point + item->get("sp+"))); }
	if (point = item->get("sp2")) { result += sprintf("sp2:%d,", point); }
	if (point = item->get("sp3")) { result += sprintf("sp3:%d,", point); }
	if (point = item->get("?%")) { result += sprintf("?%%:%d,", point);  result += sprintf("|?%%:%d,", to_int(point + item->get("?%+"))); }
	if (point = item->get("c?%")) { result += sprintf("c?%%:%d,", point);  result += sprintf("|c?%%:%d,", to_int(point + item->get("c?%+"))); }
	if (point = item->get("-*")) { result += sprintf("-*:%d,", point);    result += sprintf("|-*:%d,", to_int(point + item->get("-*+"))); }
	if (point = item->get("-*%")) { result += sprintf("-*%%:%d,", point);  result += sprintf("|-*%%:%d,", to_int(point + item->get("-*%+"))); }
	if (point = item->get("-c*")) { result += sprintf("-c*:%d", point);     result += sprintf("|-c*:%d", to_int(point + item->get("-c*+"))); }
	if (point = item->get("-c*%")) { result += sprintf("-c*%%:%d,", point);  result += sprintf("|-c*%%:%d,", to_int(point + item->get("-c*%+"))); }
	//if( point = item->get_poison() ) { result += sprintf(  "@:%d,", point );    result += sprintf(  "|@:%d,",   to_int( point + item->get_poison() ) ); }
	if (point = item->get("@%")) { result += sprintf("@%%:%d,", point);  result += sprintf("|@%%:%d,", to_int(point + item->get("@%+"))); }
	if (point = item->get("X@%")) { result += sprintf("X@%%:%d,", point);  result += sprintf("|X@%%:%d,", to_int(point + item->get("X@%+"))); }
	if (point = item->get("-@%")) { result += sprintf("-@%%:%d,", point);  result += sprintf("|-@%%:%d,", to_int(point + item->get("-@%+"))); }
	if (point = item->get("/%")) { result += sprintf("/%%:%d,", point);  result += sprintf("|/%%:%d,", to_int(point + item->get("/%+"))); }
	if (point = item->get("??%")) { result += sprintf("??%%:%d,", point);  result += sprintf("|??%%:%d,", to_int(point + item->get("??%+"))); }
	if (point = item->get("#%")) { result += sprintf("#%%:%d,", point);  result += sprintf("|#%%:%d,", to_int(point + item->get("#%+"))); }
	if (point = item->get("-1-"))   result += sprintf("-1-:%d,", point);
	if (point = item->get("hp+@"))  result += sprintf("hp+@:%d,", point);
	if (point = item->get("mp+@"))  result += sprintf("mp+@:%d,", point);


	if (point = item->get("-anti_hurt%")) { result += sprintf("-anti_hurt%%:%d,", point);  result += sprintf("|-anti_hurt%%:%d,", to_int(point)); }


	if (point = item->get("stoneHP+"))  result += sprintf("stoneHP+:%d,", point);
	if (point = item->get("stoneAP+"))  result += sprintf("stoneAP+:%d,", point);
	if (point = item->get("stoneCP+"))  result += sprintf("stoneCP+:%d,", point);
	if (point = item->get("stoneDP+"))  result += sprintf("stoneDP+:%d,", point);
	if (point = item->get("stonePP+"))  result += sprintf("stonePP+:%d,", point);

	if (point = item->get("stoneHP++"))  result += sprintf("stoneHP++:%d,", point);
	if (point = item->get("stoneAP++"))  result += sprintf("stoneAP++:%d,", point);
	if (point = item->get("stoneCP++"))  result += sprintf("stoneCP++:%d,", point);
	if (point = item->get("stoneDP++"))  result += sprintf("stoneDP++:%d,", point);
	if (point = item->get("stonePP++"))  result += sprintf("stonePP++:%d,", point);

	if (point = item->get("stoneHP+++"))  result += sprintf("stoneHP+++:%d,", point);
	if (point = item->get("stoneAP+++"))  result += sprintf("stoneAP+++:%d,", point);
	if (point = item->get("stoneCP+++"))  result += sprintf("stoneCP+++:%d,", point);
	if (point = item->get("stoneDP+++"))  result += sprintf("stoneDP+++:%d,", point);
	if (point = item->get("stonePP+++"))  result += sprintf("stonePP+++:%d,", point);

	if (point = item->get("goldAP+"))  result += sprintf("goldAP+:%d,", point);
	if (point = item->get("goldCP+"))  result += sprintf("goldCP+:%d,", point);
	if (point = item->get("goldDP+"))  result += sprintf("goldDP+:%d,", point);
	if (point = item->get("goldPP+"))  result += sprintf("goldPP+:%d,", point);

	if (point = item->get("holeExp_0")) result += sprintf("holeExp_0:%d,", point);
	if (point = item->get("holeExp_1")) result += sprintf("holeExp_1:%d,", point);
	if (point = item->get("holeExp_2")) result += sprintf("holeExp_2:%d,", point);

	if (point = item->get("itemExp")) result += sprintf("itemExp:%d,", point);
	if (point = item->get("itemLevel")) result += sprintf("itemLevel:%d,", point);
	if (point = item->get("itemLife")) result += sprintf("itemLife:%d,", point);


	//if( point = item->get("mau+@" ) )  result += sprintf("mau+@:%d,", point );
	//if( point = item->get("mana+@" ) )  result += sprintf("mana+@:%d,", point );
	if (point = item->get("yuan+@"))  result += sprintf("yuan+@:%d,", point);
	if (point = item->get("cp+@"))  result += sprintf("cp+@:%d,", point);
	if (point = item->get("heal+@"))  result += sprintf("heal+@:%d,", point);
	if (point = item->get_bind()) result += sprintf("bind:%d,", point);
	if (prop = item->get_make_prop()) result += sprintf("ADD:%s,", prop);
	if ((point = item->get_hide()) && item->get_level() >= 30) result += sprintf("hide:%d,", point);
	result += sprintf("=:%d,", item->get_item_color());    // 禁止再有字串 "=:", 见 pawn
	result += sprintf("+:%d,", item->get_item_level());    // 禁止再有字串 "+:", 见 pawn
	result += sprintf("$:%d,", item->get_value());
	result += sprintf("B:%d,", item->get_nh());
	if (item->get("make") != 0 && item->get("make") != "") result += sprintf("make:%s,", item->get("make"));
	if (item->get("forge") != 0 && item->get("forge") != "") result += sprintf("forge:%s,", item->get("forge"));
	if (item->get("hole") != 0 && item->get("hole") != "") result += sprintf("hole:%s,", item->get("hole"));
	if (item->get_product_id() != 0 && item->get_product_id() != "") result += sprintf("product:%s,", item->get_product_id());

	return result;
}

// 函数：根据字串Thiết lập 属性
void set_prop_baseon_string(object item, string prop)
{
	string* key, * key2, prop2;
	int point, i, j, size, size2;

	if (!prop || prop == "") return;
	item->set_hide(0);
	key = explode(prop, ",");
	for (i = 0, size = sizeof(key); i < size; i++)
	{
		if (sscanf(key[i], "ADD:%s", prop2))
		{
			if (!prop2 || prop2 == "") continue;
			item->set_make_prop(prop2);

			key2 = explode(prop2, "|");
			for (j = 0, size2 = sizeof(key2); j < size2; j++) switch (key2[j])
			{
			case "hp": item->add("hp+", 20);  break;
			case "hp%": item->add("hp%+", 1.5);  break;
			case "hp*": item->add("hp*+", 1);  break;
			case "mp": item->add("mp+", 20);  break;
			case "mp%": item->add("mp%+", 1);  break;
			case "mp*": item->add("mp*+", 1);  break;
			case "ap": item->add("ap+", 5);  break;
			case "ap%": item->add("ap%+", 1);  break;
			case "dp": item->add("dp+", 4);  break;
			case "cp": item->add("cp+", 5);  break;
			case "cp%": item->add("cp%+", 1);  break;
			case "pp": item->add("pp+", 4);  break;
			case "sp": item->add("sp+", 6);  break;
			case "!%": item->add("!%+", 1);  break;
			case "c!%": item->add("c!%+", 1);  break;
			case "t!%": item->add("t!%+", 1);  break;
			case "?%": item->add("?%+", 1);  break;
			case "c?%": item->add("c?%+", 1);  break;
			case "-*": item->add("-*+", 3);  break;
			case "-*%": item->add("-*%+", 1);  break;
			case "-c*": item->add("-c*+", 3);  break;
			case "-c*%": item->add("-c*%+", 1);  break;
			//case "@"  : item->add("@+",  1 );  break;
			case "@%": item->add("@%+", 1);  break;
			case "X@%": item->add("X@%+", 1);  break;
			case "-@%": item->add("-@%+", 1.5);  break;
			case "/%": item->add("/%+", 1.5);  break;
			case "??%": item->add("??%+", 2);  break;
			case "#%": item->add("#%+", 1);  break;
			}

			continue;
		}
		if (sscanf(key[i], "product:%s", prop2))
		{
			item->set_product_id(prop2);
			continue;
		}
		if (sscanf(key[i], "make:%s", prop2))
		{
			item->set("make", prop2);
			continue;
		}
		if (sscanf(key[i], "forge:%s", prop2))
		{
			item->set("forge", prop2);
			continue;
		}
		if (sscanf(key[i], "sao:%s", prop2))
		{
			item->set("sao", prop2);
			continue;
		}
		if (sscanf(key[i], "hole:%s", prop2))
		{
			item->set("hole", prop2);
			continue;
		}

		if (!sscanf(key[i], "%s:%d", prop, point)) continue;
		switch (prop)
		{
		case "hp": item->set("hp", point);  break;
		case "hpp": item->set("hpp", point);  break;
		case "hp2": item->set("hp2", point);  break;
		case "hp3": item->set("hp3", point);  break;
		case "hp4": item->set("hp4", point);  break;
		case "hp%": item->set("hp%", point);  break;
		case "hp*": item->set("hp*", point);  break;
		case "mp": item->set("mp", point);  break;
		case "mpp": item->set("mpp", point);  break;
		case "mp2": item->set("mp2", point);  break;
		case "mp3": item->set("mp3", point);  break;
		case "mp4": item->set("mp4", point);  break;
		case "mp%": item->set("mp%", point);  break;
		case "mp*": item->set("mp*", point);  break;
		case "ap": item->set("ap", point);  break;
		case "app": item->set("app", point);  break;
		case "ap2": item->set("ap2", point);  break;
		case "ap3": item->set("ap3", point);  break;
		case "ap4": item->set("ap4", point);  break;
		case "double": item->set("double", point);  break;
		case "double2": item->set("double2", point);  break;
		case "ap%": item->set("ap%", point);  break;
		case "aps%": item->set("aps%", point);  break;
		case "dp": item->set("dp", point);  break;
		case "dpp": item->set("dpp", point);  break;
		case "dp2": item->set("dp2", point);  break;
		case "dp3": item->set("dp3", point);  break;
		case "dp4": item->set("dp4", point);  break;
		case "cp": item->set("cp", point);  break;
		case "cpp": item->set("cpp", point);  break;
		case "cp2": item->set("cp2", point);  break;
		case "cp3": item->set("cp3", point);  break;
		case "cp4": item->set("cp4", point);  break;
		case "cp%": item->set("cp%", point);  break;
		case "cps%": item->set("cps%", point);  break;
		case "pp": item->set("pp", point);  break;
		case "ppp": item->set("ppp", point);  break;
		case "pp2": item->set("pp2", point);  break;
		case "pp3": item->set("pp3", point);  break;
		case "pp4": item->set("pp4", point);  break;
		case "sp": item->set("sp", point);  break;
		case "sp2": item->set("sp2", point);  break;
		case "sp3": item->set("sp3", point);  break;
		case "sp4": item->set("sp4", point);  break;
		case "!%": item->set("!%", point);  break;
		case "c!%": item->set("c!%", point);  break;
		case "t!%": item->set("t!%", point);  break;
		case "?%": item->set("?%", point);  break;
		case "c?%": item->set("c?%", point);  break;
		case "-*": item->set("-*", point);  break;
		case "-*%": item->set("-*%", point);  break;
		case "-c*": item->set("-c*", point);  break;
		case "-c*%": item->set("-c*%", point);  break;
		//case "@"  : item->set_poison(point);  break;
		case "@%": item->set("@%", point);  break;
		case "X@%": item->set("X@%", point);  break;
		case "-@%": item->set("-@%", point);  break;
		case "/%": item->set("/%", point);  break;
		case "??%": item->set("??%", point);  break;
		case "#%": item->set("#%", point);  break;
		case "-1-": item->set("-1-", point);  break;
		case "hp+@": item->set("hp+@", point);   break;
		case "mp+@": item->set("mp+@", point);   break;
		case "mau1": item->set_back_color(point); break;
		case "mau2": item->set_back2_color(point); break;
		case "mauvk": item->set("mauvk", point); break;

		case "weaponColor": item->set("weaponColor", point); break;

		case "holeExp_0": item->set("holeExp_0", point); break;
		case "holeExp_1": item->set("holeExp_1", point); break;
		case "holeExp_2": item->set("holeExp_2", point); break;

		case "itemExp": item->set("itemExp", point); break;
		case "itemLevel": item->set("itemLevel", point); break;
		case "itemLife": item->set("itemLife", point); break;
		//case "mau+@" : item->set("mau+@",point);   break;
		//case "mana+@" : item->set("mana+@",point);   break;
		case "yuan+@": item->set("yuan+@", point);   break;
		case "cp+@": item->set("cp+@", point);   break;
		case "heal+@": item->set("heal+@", point);   break;
		case "=": item->set_item_color(point);  break;
		case "+": item->set_item_level(point);  break;
		case "$": item->set_value(point);  break;
		case "B": item->set_nh(point);  break;
		case "hide": item->set_hide(point);   break;
		case "bind": item->set_bind(point);   break;

		case "-anti_hurt%": item->set("-anti_hurt%", point);  break;

		case "stoneHP+": item->set("stoneHP+", point); break;
		case "stoneAP+": item->set("stoneAP+", point); break;
		case "stoneCP+": item->set("stoneCP+", point); break;
		case "stoneDP+": item->set("stoneDP+", point); break;
		case "stonePP+": item->set("stonePP+", point); break;

		case "stoneHP++": item->set("stoneHP++", point); break;
		case "stoneAP++": item->set("stoneAP++", point); break;
		case "stoneCP++": item->set("stoneCP++", point); break;
		case "stoneDP++": item->set("stoneDP++", point); break;
		case "stonePP++": item->set("stonePP++", point); break;

		case "stoneHP+++": item->set("stoneHP+++", point); break;
		case "stoneAP+++": item->set("stoneAP+++", point); break;
		case "stoneCP+++": item->set("stoneCP+++", point); break;
		case "stoneDP+++": item->set("stoneDP+++", point); break;
		case "stonePP+++": item->set("stonePP+++", point); break;

		case "gold_time": item->set("gold_time", point); break;
		case "goldAP+": item->set("goldAP+", point); break;
		case "goldCP+": item->set("goldCP+", point); break;
		case "goldDP+": item->set("goldDP+", point); break;
		case "goldPP+": item->set("goldPP+", point); break;


		}
	}

	if (item->get_item_level() >= 10)
	{
		if (point = item->get("ap") + item->get("ap+") + item->get("app"))  item->add("ap+", point / 20);
		if (point = item->get("ap%") + item->get("ap%+")) item->add("ap%+", point / 20);
		if (point = item->get("!%") + item->get("!%+"))  item->add("!%+", point / 20);
		if (point = item->get("cp") + item->get("cp+") + item->get("cpp"))  item->add("cp+", point / 20);
		if (point = item->get("cp%") + item->get("cp%+")) item->add("cp%+", point / 20);
		if (point = item->get("c!%") + item->get("c!%+"))  item->add("c!%+", point / 20);
		if (point = item->get("t!%") + item->get("t!%+"))  item->add("t!%+", point / 20);
		if (point = item->get("dp") + item->get("dp+") + item->get("dpp"))  item->add("dp+", point / 20);
		if (point = item->get("pp") + item->get("pp+") + item->get("ppp"))  item->add("pp+", point / 20);
		if (point = item->get("hp") + item->get("hp+") + item->get("hpp"))  item->add("hp+", point / 20);
		if (point = item->get("hp%") + item->get("hp%+")) item->add("hp%+", point / 20);
		if (point = item->get("mp") + item->get("mp+") + item->get("mpp"))  item->add("mp+", point / 20);
		if (point = item->get("mp%") + item->get("mp%+")) item->add("mp%+", point / 20);
		if (point = item->get("hp*") + item->get("hp*+")) item->add("hp*+", point / 20);
		if (point = item->get("mp*") + item->get("mp*+")) item->add("mp*+", point / 20);
		if (point = item->get("sp") + item->get("sp+"))  item->add("sp+", point / 20);
		if (point = item->get("?%") + item->get("?%+"))  item->add("?%+", point / 20);
		if (point = item->get("c?%") + item->get("c?%+"))  item->add("c?%+", point / 20);
		if (point = item->get("-*") + item->get("-*+"))  item->add("-*+", point / 20);
		if (point = item->get("-*%") + item->get("-*%+")) item->add("-*%+", point / 20);
		if (point = item->get("-c*") + item->get("-c*+"))  item->add("-c*+", point / 20);
		if (point = item->get("-c*%") + item->get("-c*%+")) item->add("-c*%+", point / 20);
		//if( point = item->get_poison() ) item->get_poison();
		if (point = item->get("@%") + item->get("@%+")) item->add("@%+", point / 20);
		if (point = item->get("X@%") + item->get("X@%+")) item->add("X@%+", point / 20);
		if (point = item->get("-@%") + item->get("-@%+")) item->add("-@%+", point / 20);
		if (point = item->get("/%") + item->get("/%+")) item->add("/%+", point / 20);
		if (point = item->get("??%") + item->get("??%+")) item->add("??%+", point / 20);
		if (point = item->get("#%") + item->get("#%+")) item->add("#%+", point / 20);
	}
}

// 函数：根据字串刷新属性(装备合成)
void reset_make_prop_baseon_string(object item, string prop)
{
	string* key;
	int i, size;

	item->delete("hp+");
	item->delete("hp%+");
	item->delete("hp*+");
	item->delete("mp+");
	item->delete("mp%+");
	item->delete("mp*+");
	item->delete("ap+");
	item->delete("ap%+");
	item->delete("aps%");
	item->delete("dp+");
	item->delete("cp+");
	item->delete("cp%+");
	item->delete("cps%");
	item->delete("pp+");
	item->delete("sp+");
	item->delete("!%+");
	item->delete("c!%+");
	item->delete("t!%+");
	item->delete("?%+");
	item->delete("c?%+");
	item->delete("-*+");
	item->delete("-*%+");
	item->delete("-c*+");
	item->delete("-c*%+");
	//item->delete(  "@+"  );
	item->delete("@%+");
	item->delete("X@%+");
	item->delete("-@%+");
	item->delete("/%+");
	item->delete("??%+");
	item->delete("#%+");
	item->delete("-anti_hurt%");

	key = explode(prop, "|");
	for (i = 0, size = sizeof(key); i < size; i++) switch (key[i])
	{
	case "hp": item->add("hp+", 20);  break;
	case "hp%": item->add("hp%+", 1.5);  break;
	case "hp*": item->add("hp*+", 100);  break;
	case "mp": item->add("mp+", 20);  break;
	case "mp%": item->add("mp%+", 1);  break;
	case "mp*": item->add("mp*+", 100000);  break;
	case "ap": item->add("ap+", 5);  break;
	case "ap%": item->add("ap%+", 1);  break;
	case "dp": item->add("dp+", 4);  break;
	case "cp": item->add("cp+", 5);  break;
	case "cp%": item->add("cp%+", 1);  break;
	case "pp": item->add("pp+", 4);  break;
	case "sp": item->add("sp+", 6);  break;
	case "!%": item->add("!%+", 1);  break;
	case "c!%": item->add("c!%+", 1);  break;
	case "t!%": item->add("t!%+", 1);  break;
	case "?%": item->add("?%+", 1);  break;
	case "c?%": item->add("c?%+", 1);  break;
	case "-*": item->add("-*+", 3);  break;
	case "-*%": item->add("-*%+", 1);  break;
	case "-c*": item->add("-c*+", 3);  break;
	case "-c*%": item->add("-c*%+", 1);  break;
	//case "@"  : item->add(  "@+",  1 );  break;
	case "@%": item->add("@%+", 1);  break;
	case "X@%": item->add("X@%+", 1);  break;
	case "-@%": item->add("-@%+", 1.5);  break;
	case "/%": item->add("/%+", 1.5);  break;
	case "??%": item->add("??%+", 2);  break;
	case "#%": item->add("#%+", 1);  break;
	}
}

// 函数：获取属性说明(单个)
string get_chinese_prop_string(string file, string prop, int point)
{
	switch (prop)
	{
	case "ap": return sprintf(" %s Ngoại Công: %+d \n", !file->get("ap") ? HIY : point > file->get("ap") ? HIC : NOR, to_int(point));
	case "app": return sprintf(" %s Tăng cường Ngoại Công: %+d \n", HIC, to_int(point));
	case "ap2": return sprintf(" %s Rèn luyện Ngoại Công: %+d \n", HIC, to_int(point));
	case "double": return sprintf(" %s Tỷ lệ bạo kích: %.2f%% \n", HIC, to_float(point) / 100);
	case "double2": return sprintf(" %s Tỷ lệ bạo kích Khảm nạm: %.2f%% \n", HIC, to_float(point) / 100);
	case "ap%": return sprintf(" %s Ngoại Công: %+d %% \n", !file->get("ap%") ? HIY : point > file->get("ap%") ? HIC : NOR, to_int(point));
	case "aps%": return sprintf(" %s Cường hóa ngoại Công: %+d %% \n", !file->get("aps%") ? HIY : point > file->get("aps%") ? HIC : NOR, to_int(point));
	case "!%": return sprintf(" %s Chính xác: %.2f%% \n", !file->get("!%") ? HIY : point > file->get("!%") ? HIC : NOR, to_float(point) / 100);
	case "cp": return sprintf(" %s Nội Công: %+d \n", !file->get("cp") ? HIY : point > file->get("cp") ? HIC : NOR, to_int(point));
	case "cpp": return sprintf(" %s Tăng cường Nội Công : %+d \n", HIC, to_int(point));
	case "cp2": return sprintf(" %s Rèn luyện Nội Công: %+d \n", HIC, to_int(point));
	case "cp%": return sprintf(" %s Nội Công: %+d %% \n", !file->get("cp%") ? HIY : point > file->get("cp%") ? HIC : NOR, to_int(point));
	case "cps%": return sprintf(" %s Cường hóa nội Công: %+d %% \n", !file->get("cps%") ? HIY : point > file->get("cps%") ? HIC : NOR, to_int(point));
	case "c!%": return sprintf(" %s Trúng pháp thuật: %+d.%% \n", !file->get("c!%") ? HIY : point > file->get("c!%") ? HIC : NOR, to_int(point));
	case "t!%": return sprintf(" %s Trúng ám khí: %+d %% \n", !file->get("t!%") ? HIY : point > file->get("t!%") ? HIC : NOR, to_int(point));
	case "dp": return sprintf(" %s Ngoại Kháng: %+d \n", !file->get("dp") ? HIY : point > file->get("dp") ? HIC : NOR, to_int(point));
	case "dpp": return sprintf(" %s Tăng cường Ngoại Kháng: %+d \n", HIC, to_int(point));
	case "dp2": return sprintf(" %s Rèn luyện Ngoại Kháng: %+d \n", HIC, to_int(point));
	case "pp": return sprintf(" %s Nội Kháng: %+d \n", !file->get("pp") ? HIY : point > file->get("pp") ? HIC : NOR, to_int(point));
	case "ppp": return sprintf(" %s Tăng cường Nội Kháng: %+d \n", HIC, to_int(point));
	case "pp2": return sprintf(" %s Rèn luyện Nội Kháng: %+d \n", HIC, to_int(point));
	case "hp": return sprintf(" %s Khí huyết: %+d \n", !file->get("hp") ? HIY : point > file->get("hp") ? HIC : NOR, to_int(point));
	case "hpp": return sprintf(" %s Tăng cường khí huyết: %+d \n", HIC, to_int(point));
	case "hp2": return sprintf(" %s Rèn luyện khí huyết: %+d \n", HIC, to_int(point));
	case "hp%": return sprintf(" %s Khí huyết: %+d %% \n", !file->get("hp%") ? HIY : point > file->get("hp%") ? HIC : NOR, to_int(point));    // 小心 point 是 %f 的情况
	case "mp": return sprintf(" %s Ma Lực: %+d \n", !file->get("mp") ? HIY : point > file->get("mp") ? HIC : NOR, to_int(point));
	case "mpp": return sprintf(" %s Tăng cường Ma Lực: %+d \n", HIC, to_int(point));
	case "mp2": return sprintf(" %s Rèn luyện Ma Lực: %+d \n", HIC, to_int(point));
	case "mp%": return sprintf(" %s Ma Lực: %+d %% \n", !file->get("mp%") ? HIY : point > file->get("mp%") ? HIC : NOR, to_int(point));
	case "hp*": return sprintf(" %s Hấp thụ khí huyết: %+d %% \n", !file->get("hp*") ? HIY : point > file->get("hp*") ? HIC : NOR, to_int(point));
	case "mp*": return sprintf(" %s Hấp thụ pháp lực: %+d%%\n", !file->get("mp*") ? HIY : point > file->get("mp*") ? HIC : NOR, to_int(point));
	case "sp": return sprintf(" %s Thân thủ: %+d \n", !file->get("sp") ? HIY : point > file->get("sp") ? HIC : NOR, to_int(point));
	case "sp2": return sprintf(" %s Rèn Thân thủ: %+d \n", HIC, to_int(point));
	case "?%": return sprintf(" %s Tỷ lệ Thân thủ: %.2f%% \n", !file->get("?%") ? HIY : point > file->get("?%") ? HIC : NOR, to_float(point) / 100);
	case "c?%": return sprintf(" %s Pháp thuật lẫn tránh: %+.2f%% \n", !file->get("c?%") ? HIY : point > file->get("c?%") ? HIC : NOR, to_float(point) / 100);
	case "-*": return sprintf(" %s Giảm sát thương Ngoại: %+d \n", !file->get("-*") ? HIY : point > file->get("-*") ? HIC : NOR, to_int(point));
	case "-*%": return sprintf(" %s Giảm sát thương Ngoại: %+d%% \n", !file->get("-*%") ? HIY : point > file->get("-*%") ? HIC : NOR, to_int(point));
	case "-c*": return sprintf(" %s Giảm sát thương Nội: %+d \n", !file->get("-c*") ? HIY : point > file->get("-c*") ? HIC : NOR, to_int(point));
	case "-c*%": return sprintf(" %s Giảm sát thương Nội: %+d%% \n", !file->get("-c*%") ? HIY : point > file->get("-c*%") ? HIC : NOR, to_int(point));
	case "@": return sprintf(HIG "Độc tính: %+d \n", to_int(point));
	case "@%": return sprintf(" %s Độc tính: %+d%% \n", !file->get("@%") ? HIY : point > file->get("@%") ? HIC : NOR, to_int(point));
	case "X@%": return sprintf(" %s Miễn dịch chất độc: %+d %% \n", !file->get("X@%") ? HIY : point > file->get("X@%") ? HIC : NOR, to_int(point));
	case "-@%": return sprintf(" %s Kháng độc tính: %+d%% \n", !file->get("-@%") ? HIY : point > file->get("-@%") ? HIC : NOR, to_int(point));
	case "/%": return sprintf(" %s Miễn dịch dị thường: %+d%% \n", !file->get("/%") ? HIY : point > file->get("/%") ? HIC : NOR, to_int(point));
	case "??%": return sprintf(" %s May Mắn: %+d%% \n", !file->get("??%") ? HIY : point > file->get("??%") ? HIC : NOR, to_int(point));
	case "#%": return sprintf(" %s Khả năng trang bị: %+d%% \n", !file->get("#%") ? HIY : point > file->get("#%") ? HIC : NOR, to_int(point));
	case "-anti_hurt%": return sprintf(" %s Cường hóa phòng thủ: %+d%% \n", !file->get("#%") ? HIY : point > file->get("#%") ? HIC : NOR, to_int(point));

	
	default: return "";
	}
}

// 函数：获取属性说明(单个)
string get_chinese_prop_string_2(string color, string prop, int point)    // 专用于法宝
{
	switch (prop)
	{
	case "ap": return sprintf(" %s Ngoại Công: %+d \n", color, point);
	case "app": return sprintf(" %s Tăng cường Ngoại Công: %+d \n", HIC, point);
	case "ap2": return sprintf(" %s Rèn luyện Ngoại Công: %+d \n", HIC, point);
	//case "double"  : return sprintf( " %s Tỷ lệ bạo kích: %+d%%%% \n", HIC, point );
	case "double": return sprintf(" %s Tỷ lệ bạo kích: %.2f%% \n", HIC, to_float(point) / 100);
	case "double2": return sprintf(" %s Tỷ lệ bạo kích Khảm nạm: %.2f%% \n", HIC, to_float(point) / 100);
	case "ap%": return sprintf(" %s Ngoại Công: %+d %% \n", color, point);
	case "aps%": return sprintf(" %s Cường hóa ngoại Công: %+d %% \n", color, point);
	case "!%": return sprintf(" %s Chính xác: %.2f%% \n", color, to_float(point) / 100);
	case "cp": return sprintf(" %s Nội Công: %+d \n", color, point);
	case "cpp": return sprintf(" %s Tăng cường Nội Công : %+d \n", HIC, point);
	case "cp2": return sprintf(" %s Rèn luyện Nội Công: %+d \n", HIC, point);
	case "cp%": return sprintf(" %s Nội Công: %+d %% \n", color, point);
	case "cps%": return sprintf(" %s Cường hóa nội Công: %+d %% \n", color, point);
	case "c!%": return sprintf(" %s Trúng pháp thuật: %+d %% \n", color, point);
	case "t!%": return sprintf(" %s Trúng ám khí: %+d %% \n", color, point);
	case "dp": return sprintf(" %s Ngoại Kháng: %+d \n", color, point);
	case "dpp": return sprintf(" %s Tăng cường Ngoại Kháng: %+d \n", HIC, point);
	case "dp2": return sprintf(" %s Rèn luyện Ngoại Kháng: %+d \n", HIC, point);
	case "pp": return sprintf(" %s Nội Kháng: %+d \n", color, point);
	case "ppp": return sprintf(" %s Tăng cường Nội Kháng: %+d \n", HIC, point);
	case "pp2": return sprintf(" %s Rèn luyện Nội Kháng: %+d \n", HIC, point);
	case "hp": return sprintf(" %s Khí huyết: %+d \n", color, point);
	case "hpp": return sprintf(" %s Tăng cường khí huyết: %+d \n", HIC, point);
	case "hp2": return sprintf(" %s Rèn luyện khí huyết: %+d \n", HIC, point);
	case "hp%": return sprintf(" %s Khí huyết: %+d %% \n", color, point);
	case "mp": return sprintf(" %s Ma Lực: %+d \n", color, point);
	case "mpp": return sprintf(" %s Tăng cường Ma Lực: %+d \n", HIC, point);
	case "mp2": return sprintf(" %s Rèn luyện Ma Lực: %+d \n", HIC, point);
	case "mp%": return sprintf(" %s Ma Lực: %+d %% \n", color, point);
	case "hp*": return sprintf(" %s Hấp thụ khí huyết: %+d %% \n", color, point);
	case "mp*": return sprintf(" %s Hấp thụ pháp lực: %+d%% \n", color, point);
	case "sp": return sprintf(" %s Thân thủ: %+d \n", color, point);
	case "sp2": return sprintf(" %s Rèn Thân thủ: %+d \n", HIC, point);
	case "?%": return sprintf(" %s Tỷ lệ Thân thủ: %.2f%% \n", color, to_float(point) / 100);
	case "c?%": return sprintf(" %s Pháp thuật lẫn tránh: %+.2f%% \n", color, to_float(point) / 100);
	case "-*": return sprintf(" %s Giảm sát thương Ngoại: %+d \n", color, point);
	case "-*%": return sprintf(" %s Giảm sát thương Ngoại: %+d%% \n", color, point);
	case "-c*": return sprintf(" %s Giảm sát thương Nội: %+d \n", color, point);
	case "-c*%": return sprintf(" %s Giảm sát thương Nội: %+d%% \n", color, point);
	//  case "@"  : return sprintf( " %s Độc tính: %+d \n", color, point );
	case "@%": return sprintf(" %s Độc tính: %+d%% \n", color, point);
	case "X@%": return sprintf(" %s Miễn dịch chất độc: %+d %% \n", color, point);
	case "-@%": return sprintf(" %s Kháng độc tính: %+d%% \n", color, point);
	case "/%": return sprintf(" %s Miễn dịch dị thường: %+d%% \n", color, point);
	case "??%": return sprintf(" %s May Mắn: %+d%% \n", color, point);
	case "#%": return sprintf(" %s Khả năng trang bị: %+d%% \n", color, point);
	case "-anti_hurt%": return sprintf(" %s Cường hóa phòng thủ: %+d%% \n", color, point);
	case "stoneHP+": return sprintf(" %s Ngọc Lục Bảo Cấp %d - Khí Huyết %+d \n", PPM, point == 200 ? 1 : point == 400 ? 2 : 3, point);
	case "stoneAP+": return sprintf(" %s Hồng Ngọc Cấp %d - Ngoại Công %+d \n", PPM, point == 100? 1 : point == 150? 2 : 3, point);
	case "stoneCP+": return sprintf(" %s Ngọc Bích Cấp %d - Nội Công %+d \n", PPM, point == 100 ? 1 : point == 150 ? 2 : 3, point);
	case "stoneDP+": return sprintf(" %s Hoàng Ngọc Cấp %d - Ngoại Kháng %+d \n", PPM, point == 130 ? 1 : point == 190 ? 2 : 3, point);
	case "stonePP+": return sprintf(" %s Lam Ngọc Cấp %d - Nội Kháng %+d \n", PPM, point == 130 ? 1 : point == 190 ? 2 : 3, point);
	default: return "";
	}
}

// 函数：获取属性说明，根据物品是蓝还是金来决定显示颜色
string get_chinese_prop_string_3(string file, string prop, int point, string color)
{
	switch (prop)
	{
	case "ap": return sprintf(" %s Ngoại Công: %+d \n", !file->get("ap") ? color : point > file->get("ap") ? color : NOR, to_int(point));
	case "app": return sprintf(" %s Tăng cường Ngoại Công: %+d \n", HIC, to_int(point));
	case "ap2": return sprintf(" %s Rèn luyện Ngoại Công: %+d \n", HIC, to_int(point));
	//case "double"  : return sprintf( " %s Tỷ lệ bạo kích: %+d%%%% \n", HIC, to_int(point) );
	case "double": return sprintf(" %s Tỷ lệ bạo kích: %.2f%% \n", HIC, to_float(point) / 100);
	case "double2": return sprintf(" %s Tỷ lệ bạo kích Khảm nạm: %.2f%% \n", HIC, to_float(point) / 100);
	case "ap%": return sprintf(" %s Ngoại Công: %+d %% \n", !file->get("ap%") ? color : point > file->get("ap%") ? color : NOR, to_int(point));

	case "aps%": return sprintf(" %s Cường hóa ngoại Công: %+d %% \n", HIC, to_int(point));

	case "!%": return sprintf(" %s Chính xác: %.2f%% \n", !file->get("!%") ? color : point > file->get("!%") ? color : NOR, to_float(point) / 100);
	case "cp": return sprintf(" %s Nội Công: %+d \n", !file->get("cp") ? color : point > file->get("cp") ? color : NOR, to_int(point));
	case "cpp": return sprintf(" %s Tăng cường Nội Công : %+d \n", HIC, to_int(point));

	case "cp2": return sprintf(" %s Rèn luyện Nội Công: %+d \n", HIC, to_int(point));
	case "cps%": return sprintf(" %s Cường hóa nội Công: %+d %% \n", HIC, to_int(point));

	case "cp%": return sprintf(" %s Nội Công: %+d %% \n", !file->get("cp%") ? color : point > file->get("cp%") ? color : NOR, to_int(point));
	case "c!%": return sprintf(" %s Trúng pháp thuật: %+d %% \n", !file->get("c!%") ? color : point > file->get("c!%") ? color : NOR, to_int(point));
	case "t!%": return sprintf(" %s Trúng ám khí: %+d %% \n", !file->get("t!%") ? color : point > file->get("t!%") ? color : NOR, to_int(point));
	case "dp": return sprintf(" %s Ngoại Kháng: %+d \n", !file->get("dp") ? color : point > file->get("dp") ? color : NOR, to_int(point));
	case "dpp": return sprintf(" %s Tăng cường Ngoại Kháng: %+d \n", HIC, to_int(point));
	case "dp2": return sprintf(" %s Rèn luyện Ngoại Kháng: %+d \n", HIC, to_int(point));
	case "pp": return sprintf(" %s Nội Kháng: %+d \n", !file->get("pp") ? color : point > file->get("pp") ? color : NOR, to_int(point));
	case "ppp": return sprintf(" %s Tăng cường Nội Kháng: %+d \n", HIC, to_int(point));
	case "pp2": return sprintf(" %s Rèn luyện Nội Kháng: %+d \n", HIC, to_int(point));
	case "hp": return sprintf(" %s Khí huyết: %+d \n", !file->get("hp") ? color : point > file->get("hp") ? color : NOR, to_int(point));
	case "hpp": return sprintf(" %s Tăng cường khí huyết: %+d \n", HIC, to_int(point));
	case "hp2": return sprintf(" %s Rèn luyện khí huyết: %+d \n", HIC, to_int(point));
	case "hp%": return sprintf(" %s Khí huyết: %+d %% \n", !file->get("hp%") ? color : point > file->get("hp%") ? color : NOR, to_int(point));    // 小心 point 是 %f 的情况
	case "mp": return sprintf(" %s Ma Lực: %+d \n", !file->get("mp") ? color : point > file->get("mp") ? color : NOR, to_int(point));
	case "mpp": return sprintf(" %s Tăng cường Ma Lực: %+d \n", HIC, to_int(point));
	case "mp2": return sprintf(" %s Rèn luyện Ma Lực: %+d \n", HIC, to_int(point));
	case "mp%": return sprintf(" %s Ma Lực: %+d %% \n", !file->get("mp%") ? color : point > file->get("mp%") ? color : NOR, to_int(point));
	case "hp*": return sprintf(" %s Hấp thụ khí huyết: %+d %% \n", !file->get("hp*") ? color : point > file->get("hp*") ? color : NOR, to_int(point));
	case "mp*": return sprintf(" %s Hấp thụ pháp lực: %+d%% \n", !file->get("mp*") ? color : point > file->get("mp*") ? color : NOR, to_int(point));
	case "sp": return sprintf(" %s Thân thủ: %+d \n", !file->get("sp") ? color : point > file->get("sp") ? color : NOR, to_int(point));
	case "sp2": return sprintf(" %s Rèn Thân thủ: %+d \n", HIC, to_int(point));
	case "?%": return sprintf(" %s Tỷ lệ Thân thủ: %.2f%% \n", !file->get("?%") ? color : point > file->get("?%") ? color : NOR, to_float(point) / 100);
	case "c?%": return sprintf(" %s Pháp thuật lẫn tránh: %+.2f%% \n", !file->get("c?%") ? color : point > file->get("c?%") ? color : NOR, to_float(point) / 100);
	case "-*": return sprintf(" %s Giảm sát thương Ngoại: %+d \n", !file->get("-*") ? color : point > file->get("-*") ? color : NOR, to_int(point));
	case "-*%": return sprintf(" %s Giảm sát thương Ngoại: %+d%%\n", !file->get("-*%") ? color : point > file->get("-*%") ? color : NOR, to_int(point));
	case "-c*": return sprintf(" %s Giảm sát thương Nội: %+d \n", !file->get("-c*") ? color : point > file->get("-c*") ? color : NOR, to_int(point));
	case "-c*%": return sprintf(" %s Giảm sát thương Nội: %+d%% \n", !file->get("-c*%") ? color : point > file->get("-c*%") ? color : NOR, to_int(point));

	case "-anti_hurt%": return sprintf(HIC "Cường hóa phòng thủ: %+d %% \n", to_int(point));

	case "@": return sprintf(HIG "Độc tính: %+d \n", to_int(point));
	case "@%": return sprintf(" %s Độc tính: %+d%% \n", !file->get("@%") ? color : point > file->get("@%") ? color : NOR, to_int(point));
	case "X@%": return sprintf(" %s Miễn dịch chất độc: %+d %% \n", !file->get("X@%") ? color : point > file->get("X@%") ? color : NOR, to_int(point));
	case "-@%": return sprintf(" %s Kháng độc tính: %+d%% \n", !file->get("-@%") ? color : point > file->get("-@%") ? color : NOR, to_int(point));
	case "/%": return sprintf(" %s Miễn dịch dị thường: %+d%% \n", !file->get("/%") ? color : point > file->get("/%") ? color : NOR, to_int(point));
	case "??%": return sprintf(" %s May Mắn: %+d%% \n", !file->get("??%") ? color : point > file->get("??%") ? color : NOR, to_int(point));
	case "#%": return sprintf(" %s Khả năng trang bị: %+d%% \n", !file->get("#%") ? color : point > file->get("#%") ? color : NOR, to_int(point));

	case "stoneHP+": return sprintf(" %s%s - Khí Huyết %+d \n", HIG, HOLE_D->get_stone_name_by_type(prop), point);
	case "stoneAP+": return sprintf(" %s%s - Ngoại Công %+d \n", HIG, HOLE_D->get_stone_name_by_type(prop), point);
	case "stoneCP+": return sprintf(" %s%s - Nội Công %+d \n", HIG, HOLE_D->get_stone_name_by_type(prop), point);
	case "stoneDP+": return sprintf(" %s%s - Ngoại Kháng %+d \n", HIG, HOLE_D->get_stone_name_by_type(prop), point);
	case "stonePP+": return sprintf(" %s%s - Nội Kháng %+d \n", HIG, HOLE_D->get_stone_name_by_type(prop), point);

	case "stoneHP++": return sprintf(" %s%s - Khí Huyết %+d \n", HIC, HOLE_D->get_stone_name_by_type(prop), point);
	case "stoneAP++": return sprintf(" %s%s - Ngoại Công %+d \n", HIC, HOLE_D->get_stone_name_by_type(prop), point);
	case "stoneCP++": return sprintf(" %s%s - Nội Công %+d \n", HIC, HOLE_D->get_stone_name_by_type(prop), point);
	case "stoneDP++": return sprintf(" %s%s - Ngoại Kháng %+d \n", HIC, HOLE_D->get_stone_name_by_type(prop), point);
	case "stonePP++": return sprintf(" %s%s - Nội Kháng %+d \n", HIC, HOLE_D->get_stone_name_by_type(prop), point);

	case "stoneHP+++": return sprintf(" %s%s - Khí Huyết %+d \n", PPM, HOLE_D->get_stone_name_by_type(prop), point);
	case "stoneAP+++": return sprintf(" %s%s - Ngoại Công %+d \n", PPM, HOLE_D->get_stone_name_by_type(prop), point);
	case "stoneCP+++": return sprintf(" %s%s - Nội Công %+d \n", PPM, HOLE_D->get_stone_name_by_type(prop), point);
	case "stoneDP+++": return sprintf(" %s%s - Ngoại Kháng %+d \n", PPM, HOLE_D->get_stone_name_by_type(prop), point);
	case "stonePP+++": return sprintf(" %s%s - Nội Kháng %+d \n", PPM, HOLE_D->get_stone_name_by_type(prop), point);

	case "goldAP+": return sprintf(HIY "GOLD - Ngoại công: %+d \n", to_int(point));
	case "goldCP+": return sprintf(HIY "GOLD - Nội công: %+d \n", to_int(point));
	case "goldDP+": return sprintf(HIY "GOLD - Ngoại kháng: %+d \n", to_int(point));
	case "goldPP+": return sprintf(HIY "GOLD - Nội kháng: %+d \n", to_int(point));

	default: return "";
	}
}

string get_tuchat_string(string file, string prop, int point, string color)
{
	switch (prop)
	{
	case "ap3": return sprintf("%s →Ngoại công + %d← \n", color, to_int(point));
	case "cp3": return sprintf("%s →Nội công + %d← \n", color, to_int(point));
	case "dp3": return sprintf("%s →Ngoại Kháng + %d← \n", color, to_int(point));
	case "pp3": return sprintf("%s →Nội Kháng + %d← \n", color, to_int(point));
	case "hp3": return sprintf("%s →Khí Huyết + %d← \n", color, to_int(point));
	case "mp3": return sprintf("%s →Ma Lực + %d← \n", color, to_int(point));
	case "sp3": return sprintf("%s →Thân Thủ + %d← \n", color, to_int(point));
	}
}

void init_equip_prop_5(object item)
{
	int pos, family, level, ran, i, less, value, point, begin, end;
	string forge;
	if (!clonep(item)) return;    // 只对复制物品！
	forge = item->get("forge");
	if (forge == 0) level = 0;
	else level = strlen(forge);
	begin = 100; end = 100;
	for (i = 4; i < level; i++)
	{
		begin = begin * 6 / 5;
	}
	switch (item->get_equip_type())
	{
	case WEAPON_TYPE:
		switch (level)
		{
		case 0:
			item->add("ap2", 20);
			item->add("cp2", 20);

			item->add("aps%", 1);
			item->add("cps%", 1);
			break;
		case 1:
			item->add("ap2", 25);
			item->add("cp2", 25);

			item->add("aps%", 1);
			item->add("cps%", 1);
			break;
		case 2:
			item->add("ap2", 45);
			item->add("cp2", 45);

			item->add("aps%", 2);
			item->add("cps%", 2);
			break;
		case 3:
			item->add("ap2", 50);
			item->add("cp2", 50);

			item->add("aps%", 2);
			item->add("cps%", 2);
			break;
		default:
			item->add("ap2", (80 + item->get_level() / 2) * begin / end);
			item->add("cp2", (80 + item->get_level() / 2) * begin / end);

			item->add("aps%", (level + level / 2));
			item->add("cps%", (level + level / 2));
			

			break;
		}
		break;
	case ARMOR_TYPE:
		switch (level)
		{
		case 0:
			item->add("dp2", 10);
			item->add("pp2", 10);
			item->add("hp2", 30);

			item->add("-anti_hurt%",1);
			break;
		case 1:
			item->add("dp2", 13);
			item->add("pp2", 13);
			item->add("hp2", 40);

			item->add("-anti_hurt%",1);
			break;
		case 2:
			item->add("dp2", 23);
			item->add("pp2", 23);
			item->add("hp2", 70);

			item->add("-anti_hurt%", 1);

			break;
		case 3:
			item->add("dp2", 30);
			item->add("pp2", 30);
			item->add("hp2", 100);

			item->add("-anti_hurt%", 1);

			break;
		default:
			item->add("dp2", (45 + item->get_level() / 5) * begin / end);
			item->add("pp2", (45 + item->get_level() / 5) * begin / end);
			item->add("hp2", (180 + item->get_level()) * begin / end);

			item->add("-anti_hurt%", 1);
			break;
		}
		break;
	case HEAD_TYPE:
		switch (level)
		{
		case 0:
			item->add("dp2", 10);
			item->add("pp2", 10);
			break;
		case 1:
			item->add("dp2", 13);
			item->add("pp2", 13);
			break;
		case 2:
			item->add("dp2", 23);
			item->add("pp2", 23);
			break;
		case 3:
			item->add("dp2", 30);
			item->add("pp2", 30);
			break;
		default:
			item->add("dp2", (45 + item->get_level() / 5) * begin / end);
			item->add("pp2", (45 + item->get_level() / 5) * begin / end);
			break;
		}
		break;
	case BOOTS_TYPE:
		switch (level)
		{
		case 0:
			item->add("dp2", 10);
			item->add("pp2", 10);
			item->add("sp2", 10);
			break;
		case 1:
			item->add("dp2", 13);
			item->add("pp2", 13);
			item->add("sp2", 15);
			break;
		case 2:
			item->add("dp2", 23);
			item->add("pp2", 23);
			item->add("sp2", 25);
			break;
		case 3:
			item->add("dp2", 30);
			item->add("pp2", 30);
			item->add("sp2", 35);
			break;
		default:
			item->add("dp2", (45 + item->get_level() / 5) * begin / end);
			item->add("pp2", (45 + item->get_level() / 5) * begin / end);
			item->add("sp2", (60 + item->get_level() / 5) * begin / end);
			break;
		}
		break;
	case WAIST_TYPE:
		switch (level)
		{
		case 0:
			item->add("dp2", 5);
			item->add("pp2", 5);
			item->add("hp2", 50);
			item->add("mp2", 70);
			break;
		case 1:
			item->add("dp2", 8);
			item->add("pp2", 8);
			item->add("hp2", 60);
			item->add("mp2", 80);
			break;
		case 2:
			item->add("dp2", 13);
			item->add("pp2", 13);
			item->add("hp2", 110);
			item->add("mp2", 150);
			break;
		case 3:
			item->add("dp2", 18);
			item->add("pp2", 18);
			item->add("hp2", 150);
			item->add("mp2", 200);
			break;
		default:
			item->add("dp2", (30 + item->get_level() / 5) * begin / end);
			item->add("pp2", (30 + item->get_level() / 5) * begin / end);
			item->add("hp2", (270 + item->get_level()) * begin / end);
			item->add("mp2", (360 + item->get_level()) * begin / end);
			break;
		}
		break;
	case NECK_TYPE:
		switch (level)
		{
		case 0:
			item->add("ap2", 10);
			item->add("cp2", 10);
			break;
		case 1:
			item->add("ap2", 15);
			item->add("cp2", 15);
			break;
		case 2:
			item->add("ap2", 25);
			item->add("cp2", 25);
			break;
		case 3:
			item->add("ap2", 30);
			item->add("cp2", 30);
			break;
		default:
			item->add("ap2", (50 + item->get_level() / 2) * begin / end);
			item->add("cp2", (50 + item->get_level() / 2) * begin / end);
			break;
		}
		break;
	}
}

void tuchat(object item, int saovl)
{
	item->add("ap", (item->get("ap") + item->get("ap+")) * saovl / 10);
	item->add("cp", (item->get("cp") + item->get("cp+")) * saovl / 10);
	item->add("dp", (item->get("dp") + item->get("dp+")) * saovl / 10);
	item->add("pp", (item->get("pp") + item->get("pp+")) * saovl / 10);
	item->add("hp", (item->get("hp") + item->get("hp+")) * saovl / 10);
	item->add("mp", (item->get("mp") + item->get("mp+")) * saovl / 10);
	item->add("sp", (item->get("sp") + item->get("sp+")) * saovl / 10);
}

void reset_tuchat(object item) {}

void reset_equip_prop(object item)
{
	item->set("ap2", 0);
	item->set("cp2", 0);
	item->set("hp2", 0);
	item->set("mp2", 0);
	item->set("dp2", 0);
	item->set("pp2", 0);
	item->set("sp2", 0);

	item->set("aps%", 0);
	item->set("cps%", 0);
	item->set("-anti_hurt%", 0);
}


// 函数：用被结附的锻造石失败装备属性下调一星
void reduce_equip_prop(object item)
{
	int pos, family, level, ran, i, less, value, point, begin, end;
	string forge, key1, key2, key3, key4;
	if (!clonep(item)) return;    // 只对复制物品！
	forge = item->get("forge");
	if (forge == 0) level = 0;
	else level = strlen(forge);
	if (level < 4) return;
	begin = 100; end = 100;
	for (i = 5; i < level; i++)
	{
		begin = begin * 6 / 5;
	}
	forge = forge[0.. < 2];
	item->set("forge", forge);
	switch (item->get_equip_type())
	{
	case WEAPON_TYPE:
		switch (level)
		{
		case 4:
			item->add("ap2", -50);
			item->add("cp2", -50);
			break;
		default:
			item->add("ap2", -(80 + item->get_level() / 2) * begin / end);
			item->add("cp2", -(80 + item->get_level() / 2) * begin / end);
			break;
		}
		break;
	case ARMOR_TYPE:
		switch (level)
		{
		case 4:
			item->add("dp2", -30);
			item->add("pp2", -30);
			item->add("hp2", -100);
			break;
		default:
			item->add("dp2", -(45 + item->get_level() / 5) * begin / end);
			item->add("pp2", -(45 + item->get_level() / 5) * begin / end);
			item->add("hp2", -(180 + item->get_level()) * begin / end);
			break;
		}
		break;
	case HEAD_TYPE:
		switch (level)
		{
		case 4:
			item->add("dp2", -30);
			item->add("pp2", -30);
			break;
		default:
			item->add("dp2", -(45 + item->get_level() / 5) * begin / end);
			item->add("pp2", -(45 + item->get_level() / 5) * begin / end);
			break;
		}
		break;
	case BOOTS_TYPE:
		switch (level)
		{
		case 4:
			item->add("dp2", -30);
			item->add("pp2", -30);
			item->add("sp2", -35);
			break;
		default:
			item->add("dp2", -(45 + item->get_level() / 5) * begin / end);
			item->add("pp2", -(45 + item->get_level() / 5) * begin / end);
			item->add("sp2", -(60 + item->get_level() / 5) * begin / end);
			break;
		}
		break;
	case WAIST_TYPE:
		switch (level)
		{
		case 4:
			item->add("dp2", -18);
			item->add("pp2", -18);
			item->add("hp2", -150);
			item->add("mp2", -200);
			break;
		default:
			item->add("dp2", -(30 + item->get_level() / 5) * begin / end);
			item->add("pp2", -(30 + item->get_level() / 5) * begin / end);
			item->add("hp2", -(270 + item->get_level()) * begin / end);
			item->add("mp2", -(360 + item->get_level()) * begin / end);
			break;
		}
		break;
	case NECK_TYPE:
		switch (level)
		{
		case 4:
			item->add("ap2", -30);
			item->add("cp2", -30);
			break;
		default:
			item->add("ap2", -(50 + item->get_level() / 2) * begin / end);
			item->add("cp2", -(50 + item->get_level() / 2) * begin / end);
			break;
		}
		break;
	}
}
// 函数：用被结附的锻造石失败装备属性下调一星
void reduce_equip_prop_123(object item)
{
	int pos, family, level, ran, i, less, value, point, begin, end;
	string forge, key1, key2, key3, key4;
	if (!clonep(item)) return;    // 只对复制物品！
	forge = item->get("forge");
	if (forge == 0) level = 0;
	else level = strlen(forge);
	if (level < 16) return;
	begin = 100; end = 100;
	for (i = 5; i < level; i++)
	{
		begin = begin * 6 / 5;
	}
	forge = forge[0.. < 2];
	item->set("forge", forge);
	switch (item->get_equip_type())
	{
	case WEAPON_TYPE:
		switch (level)
		{
		case 4:
			item->add("ap2", -50);
			item->add("cp2", -50);
			break;
		default:
			item->add("ap2", -(80 + item->get_level() / 2) * begin / end);
			item->add("cp2", -(80 + item->get_level() / 2) * begin / end);
			break;
		}
		break;
	case ARMOR_TYPE:
		switch (level)
		{
		case 4:
			item->add("dp2", -30);
			item->add("pp2", -30);
			item->add("hp2", -100);
			break;
		default:
			item->add("dp2", -(45 + item->get_level() / 5) * begin / end);
			item->add("pp2", -(45 + item->get_level() / 5) * begin / end);
			item->add("hp2", -(180 + item->get_level()) * begin / end);
			break;
		}
		break;
	case HEAD_TYPE:
		switch (level)
		{
		case 4:
			item->add("dp2", -30);
			item->add("pp2", -30);
			break;
		default:
			item->add("dp2", -(45 + item->get_level() / 5) * begin / end);
			item->add("pp2", -(45 + item->get_level() / 5) * begin / end);
			break;
		}
		break;
	case BOOTS_TYPE:
		switch (level)
		{
		case 4:
			item->add("dp2", -30);
			item->add("pp2", -30);
			item->add("sp2", -35);
			break;
		default:
			item->add("dp2", -(45 + item->get_level() / 5) * begin / end);
			item->add("pp2", -(45 + item->get_level() / 5) * begin / end);
			item->add("sp2", -(60 + item->get_level() / 5) * begin / end);
			break;
		}
		break;
	case WAIST_TYPE:
		switch (level)
		{
		case 4:
			item->add("dp2", -18);
			item->add("pp2", -18);
			item->add("hp2", -150);
			item->add("mp2", -200);
			break;
		default:
			item->add("dp2", -(30 + item->get_level() / 5) * begin / end);
			item->add("pp2", -(30 + item->get_level() / 5) * begin / end);
			item->add("hp2", -(270 + item->get_level()) * begin / end);
			item->add("mp2", -(360 + item->get_level()) * begin / end);
			break;
		}
		break;
	case NECK_TYPE:
		switch (level)
		{
		case 4:
			item->add("ap2", -30);
			item->add("cp2", -30);
			break;
		default:
			item->add("ap2", -(50 + item->get_level() / 2) * begin / end);
			item->add("cp2", -(50 + item->get_level() / 2) * begin / end);
			break;
		}
		break;
	}
}
//根据索引取得宝石的名称

string get_hole_diamond_name(int idx) { return mpHole[idx]; }

void counting_hole_value(object item, int stoneCode) {
	switch (item->get_equip_type())
	{
	case NECK_TYPE:
	case WEAPON_TYPE:
		switch (stoneCode)
		{
			case 101:
				item->add("stoneAP+", 100);
				break;
			case 201:
				item->add("stoneAP++", 150);
				break;
			case 301:
				item->add("stoneAP+++", 250);
				break;
			
			case 103:
				item->add("stoneCP+", 100);
				break;
			case 203:
				item->add("stoneCP++", 150);
				break;
			case 303:
				item->add("stoneCP+++", 250);
				break;
		}
		break;
	case ARMOR_TYPE:
	case HEAD_TYPE:
	case BOOTS_TYPE:
	case WAIST_TYPE:
		switch (stoneCode)
		{
		case 102:
			item->add("stoneDP+", 130);
			break;
		case 202:
			item->add("stoneDP++", 190);
			break;
		case 302:
			item->add("stoneDP+++", 260);
			break;

		case 104:
			item->add("stonePP+", 130);
			break;
		case 204:
			item->add("stonePP++", 190);
			break;
		case 304:
			item->add("stonePP+++", 260);
			break;

		case 105:
			item->add("stoneHP+", 200);
			break;
		case 205:
			item->add("stoneHP++", 400);
			break;
		case 305:
			item->add("stoneHP+++", 800);
			break;
		}
		break;

	}

}

//GOLD
void reset_equip_gold(object item)
{
	item->set("goldAP+", 0);
	item->set("goldCP+", 0);
	item->set("goldDP+", 0);
	item->set("goldPP+", 0);
}



void init_equip_prop_hole(object item)
{
	int pos, level, i, stoneCode;
	string sHole, *sHoles, *listHole, *hole;

	if (!clonep(item)) return;

	sHole = item->get("hole");
	if (!sHole) {
		return;
	}

	sHoles = explode(sHole, "|");

	if (sizeof(sHoles) < 2) {
		return;
	}

	listHole = explode(sHoles[1], ":");

	for (i = 0; i < sizeof(listHole); i++) {
		hole = explode(listHole[i], "&");
		stoneCode = to_int(hole[0]);
		counting_hole_value(item, stoneCode);
	}

}

void reset_equip_prop_hole(object item)
{
	item->set("stoneHP+", 0);
	item->set("stoneAP+", 0);
	item->set("stoneCP+", 0);
	item->set("stoneDP+", 0);
	item->set("stonePP+", 0);

	item->set("stoneHP++", 0);
	item->set("stoneAP++", 0);
	item->set("stoneCP++", 0);
	item->set("stoneDP++", 0);
	item->set("stonePP++", 0);

	item->set("stoneHP+++", 0);
	item->set("stoneAP+++", 0);
	item->set("stoneCP+++", 0);
	item->set("stoneDP+++", 0);
	item->set("stonePP+++", 0);
}


int get_hole_amount(object item)
{
	int num;
	string cHole, * nTmp;

	if (item->get_item_type() != ITEM_TYPE_EQUIP)
		return 0;
	cHole = item->get("hole");
	if (!stringp(cHole))
		return 0;
	nTmp = explode(cHole, "|");
	if (!sizeof(nTmp))
		return 0;
	num = to_int(nTmp[0]);
	return num;
}

int get_hole_used_amount(object item)
{
	int num, n, i;
	string cHole, * nTmp, * nTmp1, *holes;

	if (item->get_item_type() != ITEM_TYPE_EQUIP)
		return 0;
	cHole = item->get("hole");
	if (!stringp(cHole))
		return 0;
	nTmp = explode(cHole, "|");
	if ((sizeof(nTmp)) < 2)
		return 0;
	nTmp1 = explode(nTmp[1], ":");
	n = sizeof(nTmp1);

	num = 0;
	for (i = 0; i < n; i++) {
		holes = explode(nTmp1[i], "&");
		if (to_int(holes[0]) != 0) {
			num++;
		}
	}

	return num;
}

int add_hole(object item, int maxHole) {
	int holeNumber;
	string cHole, * nTmp, * nTmp0;

	if (item->get_item_type() != ITEM_TYPE_EQUIP)
		return 0;

	holeNumber = get_hole_amount(item);

	if (holeNumber >= maxHole) {
		return 0;
	}

	cHole = item->get("hole");

	if (!stringp(cHole)) {
		item->set("hole", "1|0&1");
		return 1;
	}

	nTmp = explode(cHole, "|");
	if ((sizeof(nTmp)) < 2)
		return 0;

	holeNumber = to_int(nTmp[0]);
	holeNumber++;

	item->set("hole", sprintf("%d|%s%s", holeNumber, nTmp[1], ":0&1"));

	return 1;
}

int up_hole(object me, object item, int pos) {
	int holeNumber, maxHole, level, i;
	string cHole, * nTmp, * nTmp0, * sHoleLevels, * newHoleLevels, stringHoles;

	if (item->get_item_type() != ITEM_TYPE_EQUIP)
		return 0;

	cHole = item->get("hole");
	holeNumber = 1;

	if (!stringp(cHole) && pos == 1) {
		item->set("hole", "1|0&1");
		return 1;
	}

	nTmp = explode(cHole, "|");
	if ((sizeof(nTmp)) < 2)
		return 0;

	holeNumber = to_int(nTmp[0]);

	sHoleLevels = explode(nTmp[1], ":");

	if (sizeof(sHoleLevels) < pos) {
		return 0;
	}

	nTmp0 = explode(sHoleLevels[pos], "&");

	if (to_int(nTmp0[1]) >= 3) {
		return 0;
	}

	sHoleLevels[pos] = sprintf("0&%d", to_int(nTmp0[1]) + 1);

	stringHoles = implode(sHoleLevels, ":");

	item->set("hole", sprintf("%d|%s", holeNumber, stringHoles));

	return 1;
}

int get_hole_level(object me, object item, int pos) {
	int holeNumber, maxHole, level, i;
	string cHole, * nTmp, * nTmp0, * sHoleLevels, * newHoleLevels, stringHoles;

	if (item->get_item_type() != ITEM_TYPE_EQUIP)
		return 0;

	cHole = item->get("hole");
	holeNumber = 1;

	if (!stringp(cHole) && pos == 1) {
		item->set("hole", "1|0&1");
		return 1;
	}

	nTmp = explode(cHole, "|");
	if ((sizeof(nTmp)) < 2)
		return 0;

	holeNumber = to_int(nTmp[0]);

	sHoleLevels = explode(nTmp[1], ":");

	if (sizeof(sHoleLevels) < pos) {
		return 0;
	}

	nTmp0 = explode(sHoleLevels[pos], "&");

	if (to_int(nTmp0[1]) >= 3) {
		return 0;
	}

	return to_int(nTmp0[1]);
}

string get_hole_string(object item) {
	int i;
	string cHole, * nTmp, * nTmp0, * sStoneLevels, *str, result = "→ ";

	if (item->get_item_type() != ITEM_TYPE_EQUIP)
		return 0;
	

	cHole = item->get("hole");

	nTmp = explode(cHole, "|");

	if ((sizeof(nTmp)) < 2)
		return "ERROR";

	sStoneLevels = explode(nTmp[1], ":");

	result = "";
	for (i = 0; i < sizeof(sStoneLevels); i++) {
		str = explode(sStoneLevels[i], "&");
		result += sprintf("%s【cấp %s】 "WHT"", to_int(str[0])/100 == 1 ? HIG : to_int(str[0]) / 100 == 2? HIC: to_int(str[0]) / 100 == 3?PPM : WHT, str[1]);
	}

	return result;
}

int mix_diamond_to_hole(object who, object item, object diamond, int pos)
{
	int i, size, * nTmp, idx, num, total, used, levelOfDiamond;
	string cName, cHole, * nTmp1, * nTmp2, cTmp, *array_total_holes, sHole, *sStoneLevels, *sStone, stoneCode, sToneLevel;

	if (item->get_item_type() != ITEM_TYPE_EQUIP || diamond->get_item_type() != ITEM_TYPE_DIAMOND_HOLE)
		return 0;

	if ((total = get_hole_amount(item)) == 0)
	{
		tell_user(who, ECHO"Thiết bị này không có lỗ, không phù hợp cho khảm！");
		return 0;
	}

	used = get_hole_used_amount(item);

	if (used >= total) {
		tell_user(who, ECHO"Trang bị này không thể khảm thêm nữa！");
		return 0;
	}

	cName = diamond->get_name();
	stoneCode = diamond->get_code();
	levelOfDiamond = HOLE_D->get_stone_level_by_code(stoneCode);
	cHole = item->get("hole");

	array_total_holes = explode(cHole, "|");

	if (sizeof(array_total_holes) < 2) {
		sHole = "";
		return 0;
	}
	else
		sHole = array_total_holes[1];
	
	sStoneLevels = explode(sHole, ":");

	if (sStoneLevels[pos] != "") {
		sStone =  explode(sStoneLevels[pos], "&");

		if (to_int(sStone[1]) != levelOfDiamond ) {
			return 0;
		}

		cTmp = sprintf("%d&%d", stoneCode, levelOfDiamond);
	}

	nTmp2 = ({});

	for (i = 0; i < sizeof(sStoneLevels); i++) {
		if (i == pos) {
			nTmp2 += ({ sprintf("%s",cTmp) });
		}
		else {
			nTmp2 += ({ sprintf("%s",sStoneLevels[i]) });
		}
	}

	nTmp1 = implode(nTmp2, ":");

	array_total_holes = ({ sprintf("%s",array_total_holes[0]), nTmp1 });

	cHole = implode(array_total_holes, "|");
	item->set("hole", cHole);

	return 1;
}