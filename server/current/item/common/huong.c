
#include <ansi.h>
#include <item.h>
#include <time.h>
#include <public.h>

inherit ITEM;
inherit USABLE;
inherit COMBINED;

private int Z, X, Y;

int get_item_value() { return 10; }
int get_item_value_2() { return 10; }

int get_item_color() { return 2; }

int get_item_type() { return ITEM_TYPE_TREASURE; }

int get_map_z() { return Z; }

int set_map_z(int z) { return Z = z; }

int get_map_x() { return X; }

int set_map_x(int x) { return X = x; }

int get_map_y() { return Y; }

int set_map_y(int y) { return Y = y; }

void create()
{
	set_name("Nén Hương");
	set_picid_1(301);
	set_picid_2(301);
	set_unit("张");
	set_value(100);

	set_amount(1);
	set_no_give(1);
	set_no_sell(1);
}

string get_desc()
{
	object map;
	int p;
	if (!clonep()) return "Thắp một nén hương, lòng tưởng niệm. Nhớ mang theo Bánh Chưng và Rượu gạo lên Phong Thần Đài thắp hương.";
	if (!(map = get_map_object(Z)))
	{
		//    if( p = XY_D->get_city_point(-1, IS_ITEM_BLOCK) )
		 //   {
		set_map_z(395);
		set_map_x(250);
		set_map_y(230);
		// }
	}
	return "Thắp một nén hương, lòng tưởng niệm.";
}

int get_use_effect(object me) { return __FILE__->get_use_effect_callout(me, this_object()); }


int get_use_effect_callout(object me, object item)
{
	object map, * monster, npc, item1;
	string name, file, result = "";
	int level, level2, pic, gold, p, i, size, u, rate, tien, knb, exp, iTime, iDay;
	int z0, x0, y0, z, x, y;
	mixed* mxTime;
	iTime = time();
	mxTime = localtime(iTime);
	iDay = mxTime[TIME_YDAY];

	if (get_z(me) != item->get_map_z()
		|| abs(get_x(me) - item->get_map_x()) > 8
		|| abs(get_y(me) - item->get_map_y()) > 8)
	{
		send_user(me, "%c%s", '!', "Vị trí không đúng");
		return 0;
	}
	if (USER_INVENTORY_D->get_free_count(me) < 1)
	{
		notify("Hành trang không đủ 1 chỗ trống");
		return 0;
	}


	if (!objectp(item = present("Bánh Chưng", me, 1, MAX_CARRY)))
	{
		notify("Bạn chưa có Bánh Chưng");
		return 0;
	}

	if (!objectp(item = present("Rượu gạo", me, 1, MAX_CARRY)))
	{
		notify("Bạn chưa có Rượu gạo");
		return 0;
	}

	TASK_LEGEND_D->check_task_item1(me, "Bánh Chưng", 1);
	TASK_LEGEND_D->check_task_item1(me, "Rượu gạo", 1);

	item->add_amount(-1);
	"sys/task/worker"->begin_thaphuong(me);

	return 1;
}
