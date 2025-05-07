#include <ansi.h>
#include <equip.h>
#include <effect.h>

inherit ITEM;
inherit USABLE;
inherit COMBINED;

int get_item_value() { return 200; }
int get_item_value_2() { return 200; }
int get_item_number() { return 30; }
int get_item_color() { return 1; }


void create()
{
	set_name("Cẩm nang nhiệm vụ");
	set_picid_1(3453);
	set_picid_2(3453);
	set_value(50);
	set_amount(1);
	set_record(1);
	set_no_give(1);
	set_no_sell(1);
}

string get_desc()
{
	return "Cẩm nang nhiệm vụ ẩn (Chuột phải để sử dụng)";
}

void show_quest(object me, int type) {

}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object me, object item)
{
	int i, iWeek, typeQuest, type;
	string result = "", cmd = "";
	typeQuest = me->get_save("qcamnang");
	type = random(3) + 1;
	//type = 1;
	if (typeQuest == 0) {
		"cmd/user/quest"->do_quest_camnang(me, type);
		me->set_save("qcamnang", type);

	}
	else {
		"cmd/user/quest"->do_quest_camnang(me, typeQuest);
	}


	return 0;
}

