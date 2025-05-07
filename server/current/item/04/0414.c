#include <item.h>
#include <ansi.h>
#include <effect.h>
#include <skill.h>
#include <equip.h>
#include <time.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;
#define SANTACLAUS	"npc/party/santaclaus"


int get_item_value() { return 50; }
int get_item_value_2() { return 50; }

int is_christmas() { return 1; }

void reset()
{
	if (gone_time(get_drop_time()) > 10)
	{
		remove_from_scene();
		destruct(this_object());
	}
}

void create()
{
	set_name("Hạt Giống Cây Noel");
	set_picid_1(3234);
	set_picid_2(3234);
	set_unit("只");
	set_value(50);
	set_amount(1);
}

string get_desc()
{
	return "Nhấp chuột phải sau khi sử dụng có thể trở thành một cây thông Noel đẹp，Admin chúc bạn Giáng sinh vui vẻ！";
}

int get_use_effect(object who) { return __FILE__->get_use_effect_callout(who, this_object()); }

int get_use_effect_callout(object who, object item)
{
	int x, y, z, x0, y0, p;
	object obj, * nObj, map;

	z = get_z(who);  x0 = get_x(who);  y0 = get_y(who);

	map = get_map_object(z);
	if (!map) return 0;

	if (MAP_D->is_inside_city(get_z(who), get_x(who), get_y(who)))
	{
		send_user(who, "%c%s", ';', "Không thể sử dụng trong \"Thành\" !!!");
		return;
	}

	p = get_valid_xy(z, x0, y0, IS_CHAR_BLOCK);
	if (!p)
		return 0;
	x = p / 1000;  y = p % 1000;
	obj = new("item/event/giangsinh/thong_1");
	if (!obj)
		return 0;
	obj->set("birth", time());
	obj->add_to_scene(z, x, y);
	nObj = SANTACLAUS->get("plant");
	if (!arrayp(nObj))
		nObj = ({});
	nObj += ({ obj });
	SANTACLAUS->set("plant", nObj);
	send_user(who, "%c%s", '!', "Bạn có một cây Giáng sinh xung quanh bạn.");
	return 1;
}