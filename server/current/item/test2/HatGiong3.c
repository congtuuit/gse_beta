#include <item.h>
#include <ansi.h>
#include <effect.h>
#include <skill.h>
#include <equip.h>
#include <time.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;

int get_item_value() { return 200; }
int get_item_value_2() { return 200; }
int get_item_color() { return 2; };
// 函数：构造处理
void create()
{
	set_name("Hạt Giống Võ Lâm Bại Hoại Hoàng Kim");
	set_picid_1(3234);
	set_picid_2(3234);
	set_unit("只");
	set_value(50);
	set_amount(1);
}

// 函数：获取描述
string get_desc()
{
	return "Sử dụng sẽ gọi ra một NPC Võ Lâm Bại Hoại Hoàng Kim \nKhi tiến vào bên trong sẽ xuất hiện 50 NPC Võ Lâm Bại Hoại Hoàng Kim và \nkhi giết một NPC Võ Lâm Bại Hoại Hoàng Kim sẽ có tỉ lệ rơi túi Linh Thạch 1 \nLưu ý : không được sử dụng bên trong Thành hoặc Tân Thủ Thôn.";
}

int get_use_effect(object who) { return __FILE__->get_use_effect_callout(who, this_object()); }

int get_use_effect_callout(object who, object item)
{
	int x, y, z, x0, y0, p, iTime, iDay, iGio, z1;
	object obj, * nObj, map;
	mixed* mxTime;
	iTime = time();
	mxTime = localtime(iTime);
	iDay = mxTime[TIME_YDAY];
	iGio = mxTime[TIME_HOUR];

	z1 = get_z(who);
	map = get_map_object(z1);
	if (!map) return 0;
	if (MAP_D->is_inside_city(get_z(who), get_x(who), get_y(who)))
	{
		send_user(who, "%c%s", ';', "Không thể sử dụng trong \"Thành\" !!!");
		return ;
	}
	if (map->get_client_id() == 001)
	{
		send_user(who, "%c%s", ';', "Không thể sử dụng ở \"Tân Thủ Thôn\" !!!");
		return ;
	}

	if (iGio % 2 == 1)
	{
		send_user(who, "%c%s", ';', "Chỉ có thể sử dụng trong khung giờ chẵn!!");
		return;
	}

	if (who->get_level() < 70) {
		send_user(who, "%c%s", ';', "Cấp 70 trở lên mới có thể gọi Võ Lâm Bại Hoại Hoàng Kim");
		return;
	}

	if (who->get_save_2("gio1.tieng") == iGio)
	{
		send_user(who, "%c%s", ';', "Đã gọi đủ \"1\" NPC Võ Lâm Bại Hoại Hoàng Kim, hãy đợi tới khung giờ kế tiếp !!!");
		return;
	}

	z = get_z(who);  x0 = get_x(who);  y0 = get_y(who);
	p = get_valid_xy(z, x0, y0, IS_CHAR_BLOCK);
	if (!p)
		return 0;
	x = p / 1000;  y = p % 1000;
	obj = new("npc/party/scum4");
	if (!obj)
		return 0;
	obj->set("birth", time());
	obj->add_to_scene(z, x, y);
	who->add_save("hatgiongvlbhhk.diem", 1);
	send_user(who, "%c%s", ';', sprintf("Đã gọi ra \"%d\" NPC Võ Lâm Bại Hoại Hoàng Kim", who->get_save("hatgiongvlbhhk.diem")));
	if (who->get_save("hatgiongvlbhhk.diem") > 0)
	{
		who->set_save_2("gio1.tieng", iGio);
		who->set_save("hatgiongvlbhhk.diem", 0);
		send_user(who, "%c%s", ';', "Đã gọi đủ \"1\" NPC Võ Lâm Bại Hoại Hoàng Kim, hãy đợi tới khung giờ kế tiếp !!!");
	}
	return 1;
}