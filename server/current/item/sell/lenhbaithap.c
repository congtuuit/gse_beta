#include <ansi.h>
#include <cmd.h>
#include <effect.h>
#include <public.h>
#include <map.h>
#include <time.h>
#include <action.h>

inherit COMBINED;
inherit ITEM;

int get_item_value() { return 350; }
int get_item_value_2() { return 350; }
int get_item_number() { return 30; }
int get_item_color() { return 2; }

void create()
{
	set_name("Phá Thiên Lệnh");
	set_picid_1(9541);
	set_picid_2(9541);
	set_value(20);
	set_amount(1);
}

int is_usable() { return 1; }

string get_desc()
{
	return "Lệnh bài đặc biệt, sau khi sử dụng sẽ tích lũy thêm 1 lần đi Phá Thiên Tháp\n(Số tích lũy chỉ có hiệu lực trong ngày)";
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object me, object item)
{
	int iTime;
	mixed* mixTime;

	iTime = time();
	mixTime = localtime(iTime);
	mixTime[TIME_WDAY];

	if (me->get_save_2("tower_105.today") == mixTime[TIME_WDAY]) {
		me->add_save_2("tower_105.go", 1);
	}
	else {
		me->set_save_2("tower_105.today", mixTime[TIME_WDAY]);
		me->set_save_2("tower_105.go", 1);
	}
	
	tell_user(me, sprintf(ECHO"Bạn đang có %d lượt đi Phá Thiên Tháp.", me->get_save_2("tower_105.go")));
	return 1;
}
