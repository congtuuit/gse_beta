#include <item.h>
#include <ansi.h>
#include <equip.h>

#define EQUIP "sys/item/equip"

int check_match(object equip, object diamond);
int mix1(object me, object* item);

int get_cash_upgrade() {
	return 2000000;
}

int get_max_exp(int currentLevel) {
	int result;
	switch (currentLevel)
	{
	case 0:
		result = 100;
		break;
	case 1:
		result = 300;
		break;
	case 2:
		result = 600;
		break;
	}

	return result;
}

string get_stone_name_by_type(string type) {
	string name;
	switch (type)
	{
	case "stoneHP+":
		name = "Ngọc Lục Bảo Cấp 1";
		break;
	case "stoneAP+":
		name = "Hồng Ngọc Cấp 1";
		break;
	case "stoneCP+":
		name = "Ngọc Bích Cấp 1";
		break;
	case "stoneDP+":
		name = "Hoàng Ngọc Cấp 1";
		break;
	case "stonePP+":
		name = "Lam Ngọc Cấp 1";
		break;

	case "stoneHP++":
		name = "Ngọc Lục Bảo Cấp 2";
		break;
	case "stoneAP++":
		name = "Hồng Ngọc Cấp 2";
		break;
	case "stoneCP++":
		name = "Ngọc Bích Cấp 2";
		break;
	case "stoneDP++":
		name = "Hoàng Ngọc Cấp 2";
		break;
	case "stonePP++":
		name = "Lam Ngọc Cấp 2";
		break;

	case "stoneHP+++":
		name = "Ngọc Lục Bảo Cấp 3";
		break;
	case "stoneAP+++":
		name = "Hồng Ngọc Cấp 3";
		break;
	case "stoneCP+++":
		name = "Ngọc Bích Cấp 3";
		break;
	case "stoneDP+++":
		name = "Hoàng Ngọc Cấp 3";
		break;
	case "stonePP+++":
		name = "Lam Ngọc Cấp 3";
		break;
	}

	return name;
}

string get_stone_type_by_type(string type) {
	string name;
	switch (type)
	{
	case "stoneHP+":
		name = "Khí Huyết";
		break;
	case "stoneAP+":
		name = "Ngoại Công";
		break;
	case "stoneCP+":
		name = "Nội Công";
		break;
	case "stoneDP+":
		name = "Ngoại Kháng";
		break;
	case "stonePP+":
		name = "Nội Kháng";
		break;
	}

	return name;
}

string get_stone_name_by_code(int stoneCode) {
	string name;
	switch (stoneCode)
	{
		case 101: name = "Hồng Ngọc Cấp 1"; break;
		case 102 : name = "Hoàng Ngọc Cấp 1"; break;
		case 103 : name = "Ngọc Bích Cấp 1"; break;
		case 104 : name = "Lam Ngọc Cấp 1"; break;
		case 105 : name = "Ngọc Lục Bảo Cấp 1"; break;
		case 201 : name = "Hồng Ngọc Cấp 2"; break;
		case 202 : name = "Hoàng Ngọc Cấp 2"; break;
		case 203 : name = "Ngọc Bích Cấp 2"; break;
		case 204 : name = "Lam Ngọc Cấp 2"; break;
		case 205 : name = "Ngọc Lục Bảo Cấp 2"; break;
		case 301 : name = "Hồng Ngọc Cấp 3"; break;
		case 302 : name = "Hoàng Ngọc Cấp 3"; break;
		case 303 : name = "Ngọc Bích Cấp 3"; break;
		case 304 : name = "Lam Ngọc Cấp 3"; break;
		case 305 : name = "Ngọc Lục Bảo Cấp 3"; break;
	}

	return name;
}

int valid_stone(int stoneCode, object equip) {
	int result = 0;
	switch (stoneCode)
	{
		case 101:
		case 201:
		case 301:
		case 103:
		case 203:
		case 303:
			switch (equip->get_equip_type())
			{
			case WEAPON_TYPE:
			case NECK_TYPE:
				result = 1;
				break;
			}
			break;
		case 102:
		case 202:
		case 302:
		case 104:
		case 204:
		case 304:
		case 105:
		case 205:
		case 305:
			switch (equip->get_equip_type())
			{
			case ARMOR_TYPE:
			case HEAD_TYPE:
			case BOOTS_TYPE:
			case WAIST_TYPE:
				result = 1;
				break;
			}
			break;
	}

	return result;
}

int get_value_by_code(int stoneCode) {
	int value;
	switch (stoneCode)
	{
	case 101: value = 100; break;
	case 102: value = 130; break;
	case 103: value = 100; break;
	case 104: value = 130; break;
	case 105: value = 200; break;

	case 201: value = 150; break;
	case 202: value = 190; break;
	case 203: value = 150; break;
	case 204: value = 190; break;
	case 205: value = 400; break;

	case 301: value = 250; break;
	case 302: value = 260; break;
	case 303: value = 250; break;
	case 304: value = 260; break;
	case 305: value = 800; break;
	}

	return value;
}

int get_value_by_type(string type) {
	int name;
	switch (type)
	{
	case "stoneHP+":
		name = 200;
		break;
	case "stoneAP+":
		name = 100;
		break;
	case "stoneCP+":
		name = 100;
		break;
	case "stoneDP+":
		name = 130;
		break;
	case "stonePP+":
		name = 130;
		break;

	case "stoneHP++":
		name = 150;
		break;
	case "stoneAP++":
		name = 150;
		break;
	case "stoneCP++":
		name = 190;
		break;
	case "stoneDP++":
		name = 190;
		break;
	case "stonePP++":
		name = 190;
		break;

	case "stoneHP+++":
		name = 800;
		break;
	case "stoneAP+++":
		name = 250;
		break;
	case "stoneCP+++":
		name = 250;
		break;
	case "stoneDP+++":
		name = 260;
		break;
	case "stonePP+++":
		name = 260;
		break;
	}

	return name;
}

int get_pos_to_mix(object equip) {

	int used, total, result = -1;

	total = EQUIP->get_hole_amount(equip);
	used = EQUIP->get_hole_used_amount(equip);

	if (total > 0 && used < total) {
		result = used;
	}

	return result;
}

int get_stone_level_by_code(int stoneCode) {
	int result = 0;
	result = stoneCode / 100;
	return result;
}

int main(object me, string arg)
{
	object item, stone;
	int pos;
	if (!arg) return 0;
	if (sscanf(arg, "%s %s %d", arg, stone, pos) != 3) return 1;
	if (!objectp(item = present(arg, me, 0, 0))) return 1;
	if (!objectp(stone = present(stone, me, 0, 0))) return 1;

	if (EQUIP->mix_diamond_to_hole(me, item, stone, pos) == 0) {
		write_user(me, ECHO "%s khảm thất bại!", item->get_name());
		return 0;
	}

	stone->remove_from_user();
	destruct(stone);

	write_user(me, ECHO "%s "ECHO"khảm thành công!", item->get_name());

	EQUIP->reset_equip_prop_hole(item);
	EQUIP->init_equip_prop_hole(item);

	USER_ENERGY_D->count_all_prop(me);

	send_user(me, "%c%d%c", 0x31, getoid(item), 0);

	return 1;
}
