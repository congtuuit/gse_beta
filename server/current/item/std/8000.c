
#include <ansi.h>
#include <item.h>

#define MONSTER         "/npc/task/8001"
#define ZOMBIE          "/npc/task/8002"

inherit ITEM;
inherit USABLE;

private int Z, X, Y;

int get_item_value() { return 15; }
int get_item_value_2() { return 15; }
int get_item_color() { return 1; }

// int is_treasure() { return 1; }

int get_item_type() { return ITEM_TYPE_TREASURE; }

int get_map_z() { return Z; }

int set_map_z(int z) { return Z = z; }

int get_map_x() { return X; }

int set_map_x(int x) { return X = x; }

int get_map_y() { return Y; }

int set_map_y(int y) { return Y = y; }

void create()
{
	set_name("Tàng Bảo Đồ");
	set_picid_1(8000);
	set_picid_2(8000);
	set_unit("张");
	set_value(100);
}

string get_desc()
{
	object map;
	int p;
	if (!clonep()) return "Thông qua địa đồ có thể tìm thấy bảo tàng";
	if (!(map = get_map_object(Z)))
	{
		if (p = XY_D->get_city_point(-1, IS_ITEM_BLOCK))
		{
			set_map_z(p / 1000000);
			set_map_x((p % 1000000) / 1000);
			set_map_y(p % 1000);
		}
	}
	return "Thông qua địa đồ có thể tìm thấy bảo tàng";
}

int get_use_effect(object me) { return __FILE__->get_use_effect_callout(me, this_object()); }

int get_use_effect_callout(object me, object item)
{
	object map, * monster, npc;
	string name, file, result = "";
	int level, level2, pic, gold, p, i, size;
	int z0, x0, y0, z, x, y;

	if (get_z(me) != item->get_map_z()
		|| abs(get_x(me) - item->get_map_x()) > 2
		|| abs(get_y(me) - item->get_map_y()) > 2)
	{
		send_user(me, "%c%s", '!', "Bạn đào sai chỗ kho báu.");
		return 0;
	}
	//if ( me->get_online_rate() == 50 )
	//{
	//	send_user(me,"%c%s",'!',"疲劳游戏时间禁止使用bản đồ kho báu。");
	//	return 0;	
	//}
	//else if ( me->get_online_rate() == 0 )
	//{
	//	send_user(me,"%c%s",'!',"不健康游戏时间禁止使用bản đồ kho báu。");
	//	return 0;	
	//}

	name = item->get_name();
	item->remove_from_user();    // 空出位置
	destruct(item);

	/*if (MAIN_D->get_host_type()==1||MAIN_D->get_host_type()==1000)
	{
		if (random100()<2 )
		{
			item = new( "/item/sell/0021" );
			if( p = item->move(me, -1) )
			{
					item->add_to_user(p);
					write_user(me, ECHO "Truy theo %s，tìm thấy %s。", name, item->get_name() );
			}
			else    destruct(item);
		}
	}*/

	// nhận được额外的经验和tiềm năng奖励
	p = 500 + random(me->get_level() * 100);
	me->add_exp(p);
	me->add_potential(p / 500 + 1);
	p = random(100);
	if (p < 7)    // lượng钱
	{
		gold = me->get_level() * 20 + random(501);
		me->add_cash(gold);  me->add_gold_log("task", gold);
		me->log_money("bản đồ kho báu", gold);
		"/sys/sys/count"->add_income("item8000", gold);
		write_user(me, ECHO "Bạn đào được %d lượng。", gold);
	}
	else if (p < 9)    // 精元丹
	{
		item = new("item/44/4488");
		p = "quest/pet"->get_drop_skill1();
		if (p)
			item->set("special", sprintf("%d", p));
		if (p = item->move(me, -1))
		{
			item->add_to_user(p);
			write_user(me, ECHO "Bạn đào được %s。", item->get_name());
		}
		else    destruct(item);
	}
	else if (p < 10)    // 玉灵液
	{
		item = new("item/44/4404");
		if (p = item->move(me, -1))
		{
			item->add_to_user(p);
			write_user(me, ECHO "Bạn đào được %s。", item->get_name());
		}
		else    destruct(item);
	}
	else if (p < 30)    // 妖怪
	{
		switch (level = 35 + random(8) * 10)    // 35、45、55、65、75、85、95、105（随机）
		{
		default: result = "Đào phạm";  pic = 8010;  level2 = 6;  break;
		case 45: result = "Tướng cướp Sơn Tây";  pic = 0251;  level2 = 2;  break;
		case 55: result = "Mã Đại Hán";  pic = 8011;  level2 = 4;  break;
		case 65: result = "Lưu Manh";  pic = 0252;  level2 = 8;  break;
		case 75: result = "Đào Phạm Sơn Đông";  pic = 8012;  level2 = 1;  break;
		case 85: result = "Tên Trộm Ngựa";  pic = 8012;  level2 = 3;  break;
		case 95: result = "Tên Trộm Trường Bạch Sơn";  pic = 8011;  level2 = 7;  break;
		case 105: result = "Tên Trộm Ngựa";  pic = 8013;  level2 = 5;  break;
		}

		size = 5;
		for (i = 0; i < size; i++)
		{
			if (!(p = XY_D->get_city_point(level2, IS_CHAR_BLOCK))) continue;

			z = p / 1000000;  x = (p % 1000000) / 1000;  y = p % 1000;

			npc = new(MONSTER);

			if (!objectp(map = get_map_object(z)) || !map->is_scene())
			{
				destruct(npc);  continue;
			}
			monster = map->get("monster");
			if (arrayp(monster))
			{
				monster -= ({ 0 });
				if (sizeof(monster) >= 100)    // 同场景不能超过百只
				{
					destruct(npc);  continue;
				}
			}
			else    monster = ({ });

			npc->set_name(result);
			npc->set_char_picid(pic);
			NPC_ENERGY_D->init_level(npc, level);
			npc->add_max_hp(npc->get_max_hp() * 21);
			npc->add_dp(level * 15 / 10);
			npc->add_pp(level * 8 / 10);
			npc->add_ap(level * 2);
			npc->add_to_scene(z, x, y, 3);
			npc->set_walk_speed(4);
			npc->set_attack_speed(15);
			npc->set("task", me->get_number());

			map->add_reset(npc);    // 加入复位列表

			monster += ({ npc });  map->set("monster", monster);
		}
		if (map)
		{
			result = sprintf("Nghe nói "HIR"%s đã cướp lấy kho báu của %s，Bây giờ chúng ta đang chạy trốn sang "HIR"%s Quốc"NOR".", result, me->get_name(), map->get_name());
			USER_D->user_channel(result);
		}
	}
	else if (p < 38)
	{
		z0 = get_z(me);  x0 = get_x(me);  y0 = get_y(me);

		for (i = 0; i < 2; i++)
		{
			npc = new(ZOMBIE);
			if (!(p = get_valid_xy(z0, x0, y0, IS_CHAR_BLOCK)))
			{
				destruct(npc);  continue;
			}
			x = p / 1000;  y = p % 1000;

			level = me->get_level() - random(6);
			if (level < 0) level = 0;
			NPC_ENERGY_D->init_level(npc, level);
			npc->add_max_hp(750);
			npc->add_dp(level * 75 / 100);
			npc->add_pp(level * 180 / 100);
			npc->add_ap(level * 150 / 100);

			npc->add_to_scene(z0, x, y, get_front_xy(x, y, x0, y0));
			me->to_front_xy(x, y);

			npc->set("task", me);
			npc->start_fight(me);
		}
		write_user(me, ECHO "Bạn đào kho báu cảnh báo những kho tàng bảo vệ zombie！");
	}
	else if (p < 39)
	{
		if (load_object(file = STONE_FILE->get_diamond_file()))
		{
			item = new(file);
			item->set_level(2);
			if (p = item->move(me, -1))
			{
				item->add_to_user(p);
				write_user(me, ECHO "Truy theo %s，tìm thấy %s。", name, item->get_name());
			}
			else    destruct(item);
		}
	}
	else if (p < 45)    // 蓝色药品
	{
		switch (random(7))
		{
		case 0: item = new("/item/91/9160");  break;
		case 1: item = new("/item/91/9161");  break;
		case 2: item = new("/item/91/9162");  break;
		case 3: item = new("/item/91/9163");  break;
		case 4: item = new("/item/91/9164");  break;
		case 5: item = new("/item/91/9165");  break;
		case 6: item = new("/item/91/9167");  break;
		}

		if (p = item->move(me, -1))
		{
			item->add_to_user(p);
			write_user(me, ECHO "Truy theo %s, tìm thấy %s。", name, item->get_name());
		}
		else    destruct(item);
	}
	else if (p < 75)
	{
		if (random(2))
			file = ARMOR_FILE->get_armor_file_2(me->get_level());
		else    file = WEAPON_FILE->get_weapon_file_2(me->get_level());
		if (load_object(file))
		{
			item = new(file);
			if (p = item->move(me, -1))
			{
				item->add_to_user(p);
				write_user(me, ECHO "Truy theo %s，tìm thấy %s。", name, item->get_name());
			}
			else    destruct(item);
		}
	}
	else if (p < 76)
	{
		if (random(2))
			file = ARMOR_FILE->get_armor_file_2(me->get_level());
		else    file = WEAPON_FILE->get_weapon_file_2(me->get_level());
		if (load_object(file))
		{
			item = new(file);
			ITEM_EQUIP_D->init_equip_prop_1(item);
			if (p = item->move(me, -1))
			{
				item->add_to_user(p);
				write_user(me, ECHO "Truy theo %s，tìm thấy %s。", name, item->get_name());
			}
			else    destruct(item);
		}
	}
	else if (p < 88) 
	{
		if (load_object(file = "sys/item/product"->get_random_mid_product()))
		{
			item = new(file);
			if (p = item->move(me, -1))
			{
				item->add_to_user(p);
				write_user(me, ECHO "Truy theo %s，tìm thấy %s。", name, item->get_name());
			}
			else    destruct(item);
		}
	}
	else if (p < 89)
	{
		switch (random(4))
		{
		case 0: item = new("/item/std/8001");  break;
		case 1: item = new("/item/std/8002");  break;
		case 2: item = new("/item/std/8003");  break;
		case 3: item = new("/item/std/8004");  break;
		}
		if (p = item->move(me, -1))
		{
			item->add_to_user(p);
			write_user(me, ECHO "Truy theo %s，tìm thấy %s。", name, item->get_name());
		}
		else    destruct(item);
	}
	else if (p < 90)
	{
		gold = me->get_level() * 20 + random(501);
		me->add_cash(gold);  me->add_gold_log("task", gold);
		me->log_money("bản đồ kho báu", gold);
		"/sys/sys/count"->add_income("item8000", gold);
		write_user(me, ECHO "Truy theo %s，nhận được %d lượng。", name, gold);
	}
	
	else
	{
		gold = me->get_level() * 20 + random(501);
		me->add_cash(gold);  me->add_gold_log("task", gold);
		me->log_money("bản đồ kho báu", gold);
		"/sys/sys/count"->add_income("item8000", gold);
		write_user(me, ECHO "Truy theo %s，nhận được %d lượng。", name, gold);
	}
	

	return 0;
}
