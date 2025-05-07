#include <item.h>
#include <effect.h>
#include <skill.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>
#include <music.h>

inherit ITEM;
inherit USABLE;
inherit COMBINED;

#define CONFIG_THUCUOI      "custom/player/thucuoiexp"

#define ITEM_USE_TYPE 	"add_hp"
#define ITEM_USE_TIME	2

int get_item_value() { return 50; }
int get_item_value_2() { return 50; }

int get_item_number() { return 999; }
int get_item_type_2() { return ITEM_TYPE_2_ADD_HP; }

// 函数：获取装备颜色：灰色
int get_item_color() { return 3; }

//lv2
int Hoa_Dai_Hung = 29;
int Hoa_Ho_Ly = 27;
int Than_Voi_Dia = 31;
int Thuy_Long_Quy = 33;
int Tuan_Loc_Do = 38;

//lv1
int Dai_Hung = 28;
int Ho_Ly = 26;
int Than_Voi = 30;
int Long_Quy = 32;
int Tuan_Loc = 39;

void create()
{
	set_name("Reset diem thu cuoi");
	set_picid_1(4052);
	set_picid_2(4052);
	set_value(1);
	set_amount(1);
}

// 函数：获取描述
string get_desc()
{
}

// 函数：使用效果
int get_use_effect(object me) { return __FILE__->get_use_effect_callout(me, this_object()); }

// 函数：使用效果(在线更新)
int get_use_effect_callout(object me, object item)
{
	int type;
	object who, npc;
	int i, size, x, y, z, p, thucuoi, exp, maxexp;
	int exitsItem;

	if (get_item_type_2() == ITEM_TYPE_2_ADD_HP) type = EFFECT_USE_ITEM_1;

	exitsItem = TASK_LEGEND_D->check_task_item_amount(me, item->get_name());

	if (exitsItem <= 0) {
		return 0;
	}

	if (get_effect(me, type))
	{
		send_user(me, "%c%s", '!', sprintf("Thời gian đóng băng của vật phẩm còn %d giây", get_effect(me, type)));
		return 0;
	}

	thucuoi = me->get_ride();

	//check than thu
	me->delete_save(sprintf("thucuoi.%d.level", thucuoi));
	me->delete_save(sprintf("thucuoi.%d.exp", thucuoi));
	me->delete_save(sprintf("thucuoi.%d.maxexp", thucuoi));

	tell_user(me, sprintf(ECHO"Mức độ luyện hóa Thần Thú đạt: %d / %d", me->get_save(sprintf("thucuoi.%d.exp", thucuoi)), me->get_save(sprintf("thucuoi.%d.maxexp", thucuoi))));

	item->remove_from_user();
	destruct(item);

	return 0;
}

