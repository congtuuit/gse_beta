
#include <ansi.h>
#include <item.h>

#define MONSTER_BOSS    "/npc/task/8005"

inherit ITEM;
inherit USABLE;

private int Z, X, Y;

int get_item_value() { return 35; }
int get_item_value_2() { return 55; }
int get_item_color() { return 2; }

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
	set_name("Tàng Bảo Đô Cũ Nát");
	set_picid_1(8005);
	set_picid_2(8005);
	set_unit("张");
	set_value(100);
}

string get_desc()
{
	int p;

	if (clonep(this_object()) && !get_map_object(Z))
	{
		if (p = XY_D->get_city_point(-1, IS_ITEM_BLOCK))
		{
			set_map_z(p / 1000000);
			set_map_x((p % 1000000) / 1000);
			set_map_y(p % 1000);
		}
	}
	return "Bản đồ kho báu cũ nát, thông qua địa đồ có thể tìm thấy bảo tàng";
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
		send_user(me, "%c%s", '!', "Anh không ở vị trí thích hợp để đào kho báu");
		return 0;
	}

	/*if ( me->get_online_rate() == 50 )
	{
		send_user(me,"%c%s",'!',"疲劳游戏时间禁止使用藏宝图。");
		return 0;
	}
	else if ( me->get_online_rate() == 0 )
	{
		send_user(me,"%c%s",'!',"不健康游戏时间禁止使用藏宝图。");
		return 0;
	} */

	name = item->get_name();
	item->remove_from_user();
	destruct(item);

	/*if (MAIN_D->get_host_type() == 1 || MAIN_D->get_host_type() == 1000)
	{
		if (random100() < 3)
		{
			item = new("/item/sell/0021");
			if (p = item->move(me, -1))
			{
				item->add_to_user(p);
			}
			else    destruct(item);
			item = new("/item/sell/0021");
			if (p = item->move(me, -1))
			{
				item->add_to_user(p);
			}
			else    destruct(item);
		}
	}*/

	p = random(100);
	if (p < 20)
	{
		switch (level = 35 + random(8) * 10)
			// 35、45、55、65、75、85、95、105（随机）
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

		size = 2;
		for (i = 0; i < size; i++)
		{
			if (!(p = XY_D->get_city_point(level2, IS_CHAR_BLOCK))) continue;

			z = p / 1000000;  x = (p % 1000000) / 1000;  y = p % 1000;

			npc = new(MONSTER_BOSS);

			if (!objectp(map = get_map_object(z)) || !map->is_scene())
			{
				destruct(npc);  continue;
			}
			monster = map->get("monster");
			if (arrayp(monster))
			{
				monster -= ({ 0 });
				if (sizeof(monster) >= 100)
				{
					destruct(npc);  continue;
				}
			}
			else    monster = ({ });

			npc->set_name(result);
			npc->set_char_picid(pic);
			NPC_ENERGY_D->init_level(npc, level);
			npc->add_max_hp(npc->get_max_hp() * 75);
			npc->add_dp(level * 5);
			npc->add_pp(level * 4);
			npc->add_ap(level * 3);
			npc->set_walk_speed(2);
			npc->set_attack_speed(20);
			npc->add_to_scene(z, x, y, 3);
			npc->set("task", me->get_number());

			map->add_reset(npc);

			monster += ({ npc });  map->set("monster", monster);
		}
		if (map)
		{
			result = sprintf("Nghe nói "HIR"%s đã cướp lấy kho báu của %s，Bây giờ chúng ta đang chạy trốn sang "HIR"%s Quốc"NOR".", result, me->get_name(), map->get_name());
			USER_D->user_channel(result);
		}
	}
	else if (p < 26)
	{
		gold = me->get_level() * 500 + random(1001);
		me->add_cash(gold);  me->add_gold_log("task", gold);
		me->log_money("kho báu", gold);
		"/sys/sys/count"->add_income("item8005", gold);
		write_user(me, ECHO "Khai quật theo %s，nhận được %d lượng", name, gold);
	}
	else if (p < 31)
	{
		item = new("item/44/4404");
		if (p = item->move(me, -1))
		{
			item->add_to_user(p);
			write_user(me, ECHO "Khai quật theo %s，nhận được %s。", name, item->get_name());
		}
		else    destruct(item);
	}
	// else if (p < 61)
	// {
	// 	item = new("item/common/dacuonghoa");
	// 	if (p = item->move(me, -1))
	// 	{
	// 		item->set_amount(2);
	// 		item->add_to_user(p);
	// 		write_user(me, ECHO "Khai quật theo %s，nhận được %s。", name, item->get_name());
	// 	}
	// 	else    destruct(item);
	// }
	else if (p < 66)
	{
		if (random(2))
			file = ARMOR_FILE->get_armor_file_2(me->get_level());
		else    file = WEAPON_FILE->get_weapon_file_2(me->get_level());

		if (load_object(file))
		{
			item = new(file);
			ITEM_EQUIP_D->init_equip_prop_3(item);
			if (p = item->move(me, -1))
			{
				item->add_to_user(p);
				write_user(me, ECHO "Khai quật theo %s，nhận được %s。", name, item->get_name());
			}
			else    destruct(item);
		}
	}
	else if (p < 67)
	{
		if (load_object(file = STONE_FILE->get_diamond_file()))
		{
			item = new(file);
			level = random(5) + 2;
			item->set_level(level);
			if (p = item->move(me, -1))
			{
				item->add_to_user(p);
				write_user(me, ECHO "Khai quật theo %s，nhận được %s。", name, item->get_name());
			}
			else    destruct(item);
		}
	}
	else if (p < 85)
	{
		item = new("item/44/4488");
		p = "quest/pet"->get_drop_skill2();
		if (p)
			item->set("special", sprintf("%d", p));
		if (p = item->move(me, -1))
		{
			item->add_to_user(p);
			write_user(me, ECHO "Khai quật theo %s，nhận được %s。", name, item->get_name());
		}
		else    destruct(item);
	}
	else
	{
		if (load_object(file = "sys/item/product"->get_random_product()))
		{
			item = new(file);
			if (p = item->move(me, -1))
			{
				item->add_to_user(p);
				write_user(me, ECHO "Khai quật theo %s，nhận được  %s。", name, item->get_name());
			}
			else    destruct(item);
		}
	}
	
	return 1;
}
