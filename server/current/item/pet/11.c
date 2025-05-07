#include <item.h>
#include <ansi.h>
#include <effect.h>
#include <skill.h>
#include <npc.h>
#include <equip.h>
#include <task.h>
inherit ITEM;
inherit USABLE;

#define RIDE_ID	18 

#define PICID	9031
#define PET_SETTING	"cmd/user/superpet"
inherit "/inh/equip/equip";
int get_item_value() { return 100; }
int get_item_value_2() { return 100; }
int get_item_color() { return 3; };
int is_superpet() { return 1; }



void create()
{
	set_name("Huyễn Thú - Hắc Hỏa Sư");

	set_picid_1(101);
	set_picid_2(101);
	set_bind(6);
	set_value(444);

	set_no_sell(1);
	set_no_drop(1);
	set_no_get(1);
	set_no_give(1);

	set("itemLevel", 1);
	set_save_2("khobau.score", 999);

	setup();
}

string get_desc()
{
	return sprintf("\nYêu cầu sử dụng cấp 0\n %s", PET_SETTING->get_desc_black(this_object()));
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object me, object item)
{
	object* obj, zombie, npc;
	int size, index, p, z, x, y, itemLevel;

	if (item->get_bind() == 1)
	{
		item->set_bind(2);
	}

	obj = me->get("zombie");
	size = sizeof(obj);
	if (size)
	{
		for (index = 0; index < size; index++)
		{
			zombie = obj[index];
			if (!objectp(zombie)) continue;
			send_user(get_scene_object_2(zombie, USER_TYPE), "%c%w%w%w%c%c%c", 0x4f, get_x(zombie), get_y(zombie), 9414, 1, OVER_BODY, PF_ONCE);
			send_user(me, "%c%c%d", 0x2c, 0, getoid(zombie));
			zombie->remove_from_scene();
			destruct(zombie);
		}

		item->set_no_drop(0);
		item->set_no_get(0);
		item->set_no_give(0);
		
		PET_SETTING->reset_buff_pet(me, item);

		return 0;
	}

	if (item->get("itemLevel") < 1) {
		item->set("itemLevel", 1);
		item->set("itemExp", 0);
		item->set("itemLife", 100);
	}

	if (item->get("itemLife") < 1) {
		item->set("itemLife", 100);
	}

	if (item->get("itemLife") < 10 && item->get("itemLife") > 0) {
		notify("Thú cưỡi thọ mệnh sắp hết, không thể triệu hồi.");
		return 0;
	}

	item->set_no_drop(1);
	item->set_no_get(1);
	item->set_no_give(1);

	npc = new ("/npc/std/jiguan");
	npc->set_name(get_name());
	npc->set_char_picid(PICID);

	//vag
	//npc->set_head_color(0x0000D7FF);
	//npc->set_head_color(0x0060A4F4);

	//hong
	//npc->set_head_color(0x001E69D2);

	//xanh duong
	//npc->set_head_color(0x00FF00FF);
	//npc->set_head_color(0x00F000FF);

	npc->set_head_color(0x001);
	npc->upgrade_level(1);
	npc->set_owner(me);
	npc->set_action_mode(2);

	z = get_z(me); x = get_x(me); y = get_y(me);
	p = get_valid_xy(z, x + random(3) - 1, y + random(3) - 1, IS_CHAR_BLOCK);
	x = p / 1000;  y = p % 1000;
	npc->add_to_scene(z, x, y, 3);
	me->add("zombie", ({ npc }));

	me->set("12pet_item", item);

	PET_SETTING->init_buff_pet_black(me, item);

	if (item->get("itemLevel") > 4) {

		/*if (me->get_ride())
		{
			me->set_ride(0);
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
			return 0;
		}*/

		/*me->set_ride(RIDE_ID);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));*/
	}

	send_user(me, "%c%d%c", 0x31, getoid(item), 0);

	return 0;
}

string get_tail_desc()
{
	object item = this_object();
	string desc;
	int itemLevel, itemExp;

	if (item->get("itemLevel") < 1) {
		desc = sprintf("\n"HIG"(Chưa kích hoạt)");
	}
	else {
		desc = PET_SETTING->get_string_pet_red(item);
	}


	return desc;
}