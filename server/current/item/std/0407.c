#include <ansi.h>
#include <item.h>
#include <map.h>
#include <effect.h>

inherit ITEM;
inherit COMBINED;
inherit USABLE;

int get_item_type() { return ITEM_TYPE_FLY_SEAL; }
int get_max_combined() { return 30; }

void create()
{
	set_name("Hồi Thành Phù");
	set_picid_1(0407);
	set_picid_2(0407);
	set_unit("张");
	set_value(1500);
	set_amount(1);
}

string get_desc()
{
	return "Gửi tới thành mà đã đi qua gần đây";
}

int get_use_effect(object me) { return __FILE__->get_use_effect_callout(me); }

int get_use_effect_callout(object me)
{
	object map, npc;
	int z, x, y, p, x1, y1;

	if (me->get_level() < 10)
	{
		send_user(me, "%c%s", '!', "trình độ của bạn quá thấp, không phù hợp với con đường gập ghềnh。");
		return 0;
	}
	if (me->get_save_2("51cuanye.time"))
	{
		send_user(me, "%c%s", '!', "Bạn không thể sử dụng trở lại thành phố sau giờ nghỉ qua các giới hạn được chấp nhận trong những nhiệm vụ。");
		return 0;
	}
	if (objectp(map = get_map_object(get_z(me)))
		&& map->get_map_type() == BATTLE_MAP && !map->is_changping())
	{
		send_user(me, "%c%s", '!', "Trong Chiến Trường không thể sử dụng Hồi Thành Phù");
		return 0;
	}
	if (present("钱票", me, 1, MAX_CARRY))
	{
		send_user(me, "%c%s", '!', "Bạn không thể sử dụng vé với sự trở lại tiền cho biểu tượng thành phố。");
		return 0;
	}
	if (present("Vật phẩm quý giá", me, 1, MAX_CARRY * 4))
	{
		send_user(me, "%c%s", '!', "không thể được sử dụng với các vật có giá trị sao cho biểu tượng thành phố。");
		return 0;
	}
	if (objectp(npc = me->get_quest("escort.robber#")) && npc->is_escort_robber())
	{
		send_user(me, "%c%s", '!', "người đàn ông đeo mặt nạ xuất hiện, hành động của bạn bị ảnh hưởng。");
		return 0;
	}

	write_user(me, ECHO "Bạn đã sử dụng Hồi Thành Phù……");
	p = me->get_latest_city();
	if (p == 0) p = 110;
	z = p / 100;  p = get_jumpin(z, p % 100);

	if (p)
	{
		x = p / 1000;
		y = p % 1000;
		if (z == 80) {
			p -= 3002;
		}

		send_user(me, "%c%c%w%s", 0x5a, 0, 2, "Hồi Thành Phù……");
		me->set_2("travel.z", z);
		me->set_2("travel.p", p);
		me->set_2("travel.money", 0);
		set_effect(me, EFFECT_TRAVEL, 3);

		//if (z == 80 && p = get_valid_xy(z, x1, y1, IS_CHAR_BLOCK)) {
		//	send_user(me, "%c%c%w%s", 0x5a, 0, 2, "Hồi Thành Phù……");
		//	me->set_2("travel.z", z);
		//	me->set_2("travel.p", p);
		//	me->set_2("travel.money", 0);
		//	set_effect(me, EFFECT_TRAVEL, 3);
		//}
		//else {
		//	send_user(me, "%c%c%w%s", 0x5a, 0, 2, "Hồi Thành Phù……");
		//	me->set_2("travel.z", z);
		//	me->set_2("travel.p", p);
		//	me->set_2("travel.money", 0);
		//	set_effect(me, EFFECT_TRAVEL, 3);
		//}
		
		
		return 1;
	}
	else
	{
		write_user(me, ECHO "……Nhưng không có tác dụng。");
		return 0;
	}
}
