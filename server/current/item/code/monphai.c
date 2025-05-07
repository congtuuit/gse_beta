#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <skill.h>

inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() { return 100; }
int get_item_value_2() { return 100; }

int get_level_support() { return 60; }

void create()
{
	set_name("Gói hỗ trợ môn phái");
	set_picid_1(4980);
	set_picid_2(4981);
	set_value(1000);

	set_no_give(1);
	set_no_sell(1);
	set_no_drop(1);
}

string get_desc(object me)
{
	return "[Có thể sử dụng] Túi Qùa Tân Thủ.\n Sau khi sử dụng nhận được vật phẩm hỗ trợ.\n";
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object me, object gift)
{
	int gender, type, i, k, l, m;
	int family, level, level2, weapon, armor, skill, size;

	object * inv, item, item1, item2, item3, equip;
	string cTmp, cFile, cFile1, cFile2, cFile3, p, file, * name;
	mapping skls;

	if (USER_INVENTORY_D->get_free_count(me) < 5)
	{
		notify("Hành trang không đủ 5 chỗ trống");
		return 0;
	}

	if (sizeof_inventory(me, 5, MAX_CARRY) >= MAX_CARRY)
	{
		send_user(me, "%c%s", '!', "Hành trang trên người ngươi không đủ 5 chỗ, lần sau nhận thưởng phải chú ý");
		return 0;
	}

	family = 0;
	file = me->get_fam_name();

	switch (file)
	{
	case "Đào Hoa Nguyên":
		family = 1;
		break;
	case "Thục Sơn":
		family = 2;
		break;
	case "Cấm Vệ Quân":
		family = 3;
		break;
	case "Đường Môn":
		family = 4;
		break;
	case "Mao Sơn":
		family = 5;
		break;
	case "Côn Luân":
		family = 6;
		break;
	case "Vân Mộng Cốc":
		family = 7;
		break;
	default:
		family = 0;
		break;
	}

	if (family == 0) {
		notify("Bạn chưa gia nhập phái.");
		return 0;
	}

	gift->remove_from_user();
	destruct(gift);

	
	if (mapp(skls = me->get_skill_dbase()) && sizeof(skls))
	{
		name = keys(skls);
		for (i = 0, size = sizeof(name); i < size; i++)
		{
			skill = to_int(name[i]);
			if (skill < 610) me->delete_skill(skill);
		}
	}

	level = get_level_support();
	weapon = -1;

	me->set_upgrade_exp(0);
	if (level == 0) me->set_exp(0, 0);
	else
		me->set_exp(USER_EXP_D->get_level_exp_low(me->get_reincarnation(), level - 1),
			USER_EXP_D->get_level_exp_high(me->get_reincarnation(), level - 1));

	NPC_ENERGY_2_D->init_family(me, family, level, weapon);

	/*inv = me->get_all_equip();
	for (i = 0, size = sizeof(inv); i < size; i++) if (inv[i])
	{
		inv[i]->remove_from_user();
		destruct(inv[i]);
	}*/

	equip = me->get_equip(HEAD_TYPE);
	if (equip) {
		equip->remove_from_user();
		destruct(equip);
	}

	equip = me->get_equip(NECK_TYPE);
	if (equip) {
		equip->remove_from_user();
		destruct(equip);
	}


	equip = me->get_equip(ARMOR_TYPE);
	if (equip) {
		equip->remove_from_user();
		destruct(equip);
	}

	equip = me->get_equip(WAIST_TYPE);
	if (equip) {
		equip->remove_from_user();
		destruct(equip);
	}

	equip = me->get_equip(BOOTS_TYPE);
	if (equip) {
		equip->remove_from_user();
		destruct(equip);
	}

	equip = me->get_equip(WEAPON_TYPE);
	equip->set("gold_time", time() + 15 * 24 * 3600);
	equip->set("goldAP+", 300);
	equip->set("goldCP+", 300);
	equip->set("goldDP+", 100);
	equip->set("goldPP+", 100);


	USER_ENERGY_D->count_all_prop(me);
	USER_ENERGY_D->count_max_yuan(me);
	me->set_max_level(me->get_level());

	me->set_hp(me->get_max_hp());
	me->set_mp(me->get_max_mp());

	me->add_exp(13887800);

	send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(me),
		9043, 1, OVER_BODY, 9044, 1, OVER_BODY, PF_ONCE);

	tell_user(me, ECHO"Bạn đã sử dụng gói quà hỗ trợ môn phái.");

	return 1;

}