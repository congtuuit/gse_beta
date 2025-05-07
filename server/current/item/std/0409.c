#include <ansi.h>
#include <map.h>
#include <effect.h>
#include <skill.h>

#include <item.h>
#include <cmd.h>
#include <task.h>
#include <music.h>

#define PF_START       "0409"

inherit ITEM;
inherit COMBINED;
inherit USABLE;

#define ITEM_USE_TYPE 	"add_hp"
#define ITEM_USE_TIME	90
int get_item_type_2() { return ITEM_TYPE_2_ADD_HP; }

// 函数：构造处理
void create()
{
	set_name("Phi Hành Phù");
	set_picid_1(0409);
	set_picid_2(0409);
	set_unit("张");
	set_value(800);
	set_amount(1);
}

// 函数：获取描述
string get_desc()
{
	return "Đưa đến theo vị trí cảnh trước mặt";
}

// 函数：使用效果
int get_use_effect(object me) { return __FILE__->get_use_effect_callout(me); }

// 函数：使用效果(在线更新)
int get_use_effect_callout(object me)    // 同步更改“驱神令”
{
	int type;
	object map, npc;
	int z, x, y, p;
	int time = 0, delayTime;
	if (me->is_store_open())
	{
		send_user(me, "%c%s", '!', "Không thể sử dụng biểu tượng bay khi thiết lập gian hàng。");
		return 0;
	}
	if (me->get_save_2("51cuanye.time"))
	{
		send_user(me, "%c%s", '!', "Không thể sử dụng biểu tượng bay sau khi chấp nhận nhiệm vụ vượt cực。");
		return 0;
	}
	if (objectp(map = get_map_object(get_z(me))) && map->get_map_type() == BATTLE_MAP)
	{
		send_user(me, "%c%s", '!', "Bay nhân vật không thể được sử dụng trên chiến trường。");
		return 0;
	}
	
	if (objectp(npc = me->get_quest("escort.robber#")) && npc->is_escort_robber())    // 寻找蒙面人
	{
		send_user(me, "%c%s", '!', "Người đàn ông đeo mặt nạ xuất hiện, hành động của bạn bị ảnh hưởng。");
		return 0;
	}

	if (get_effect(me, type))
	{
		send_user(me, "%c%s", '!', sprintf("Thời gian đóng băng của vật phẩm còn %d giây", get_effect(me, type)));
		return 0;
	}

	if (me->get_quest("escort.gold") > 0) {
		send_user(me, "%c%s", '!', sprintf("Bạn không thể sử dụng Phi Hành Phù lúc này", get_effect(me, type)));
		return 0;
	}

	if (!objectp(map = get_map_object(get_z(me))))
		return 0;

	if (map->is_changping())
	{
		send_user(me, "%c%s", '!', "Ở trong này không thể sử dụng。");
		return 0;
	}

	time = time();
	/*write_user(me, ECHO "time %d current", time);
	write_user(me, ECHO "time %d saved", me->get_save("0409"));
	write_user(me, ECHO "time %d delay", time - me->get_save("0409"));*/
	delayTime = time - me->get_save("0409");
	if (time - me->get_save("0409") < 90) {
		notify("Tái sử dụng sau %d giây.", 90 - delayTime);
		return 0;
	}

	write_user(me, ECHO "Bạn đã dùng một tấm Phi Hành Phù……");

	set_effect(me, type, ITEM_USE_TIME);
	send_user(me, "%c%c%c%w", 0x30, get_item_type_2(), 0, ITEM_USE_TIME);

	me->set_save("0409", time);

	if ((z = get_z(me))
		&& (p = get_xy_point(z, IS_CHAR_BLOCK)))
	{
		x = p / 1000;  y = p % 1000;

		if ((npc = me->get_quest("escort.npc"))
			&& npc->get_owner() == me
			&& inside_screen_2(me, npc))
			npc->add_to_scene(z, x, y, get_d(me), 40991, 40992, 40991, 40992);
		if ((npc = me->get_2("orgtask2.npc"))
			&& npc->get_owner() == me
			&& inside_screen_2(me, npc))
			npc->add_to_scene(z, x, y, get_d(me));
		if (p = get_valid_xy(z, x + random(3) - 1, y + random(3) - 1, IS_CHAR_BLOCK))
		{
			me->add_to_scene(z, p / 1000, p % 1000, get_d(me), 40991, 40992, 40991, 40992);
		}

		
		return 1;
	}
	else
	{
		write_user(me, ECHO "……Không có tác dụng。");
		return 0;
	}
}
