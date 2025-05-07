// 怪物攻城升级规模
#include <ansi.h>
#include <map.h>
#include <city.h>
#include <skill.h>
#include <equip.h>

inherit "/inh/std/virtual";

private static int War;
private static int Level;


private static object* dbComrade = ({ });
private static object* dbPlayer = ({ });

private static int Damage;

private static string City;

int is_copy_scene() { return 1; }

int get_real_z() { return 8860; }

void create()
{
	object me = this_object();

	if (!clonep(me)) return;

	set_heart_timer(me, set_heart_timer_2(me, getoid(me) % 10));
	set_heart_loop(me, 5);
	me->heart_beat();
	set_heart_beat(1);
	War = WAR_READY;
}

int get_war() { return War; }

int set_war(int flag) { return War = flag; }

string get_city() { return City; }

string set_city(string flag) { return City = flag; }

int get_level() { return Level; }

int set_level(int i, int j)
{
	string* cityname = ({ "Tề Quốc", "Hàn Quốc", "Triệu Quốc", "Ngụy Quốc", "Tần Quốc", "Sở Quốc", "Yên Quốc", });
	string* warname = ({ "Huyền Vũ Môn", "Chu Tước Môn", "Thanh Long Môn", "Bạch Hổ Môn", });
	if (j > 0 && j < 8) set_city(cityname[j - 1]);
	if (i < 4) set_name(warname[i]);
	return Level = i;
}

int get_damage() { return Damage; }

int set_damage(int flag) { return Damage = flag; }

void heart_beat() { }

private static int HeartSec = 0;

int get_heart_sec() { return HeartSec; }

int set_heart_sec(int point) { return HeartSec = point; }

int add_heart_sec(int point) { return set_heart_sec(HeartSec + point); }

object* get_comrade_dbase() { dbComrade -= ({ 0 });  return copy(dbComrade); }

int sizeof_comrade_dbase() { dbComrade -= ({ 0 });  return sizeof(dbComrade); }

void add_comrade(object npc) { dbComrade = dbComrade + ({ npc }) - ({ 0 }); }

void sub_comrade(object npc) { dbComrade -= ({ npc, 0 }); }

object* get_player_dbase() { dbPlayer -= ({ 0 });  return copy(dbPlayer); }

int sizeof_player_dbase() { dbPlayer -= ({ 0 });  return sizeof(dbPlayer); }

void add_player(object player) { dbPlayer = dbPlayer + ({ player }) - ({ 0 }); }

void sub_player(object player) { dbPlayer -= ({ player, 0 }); }

void heart_beat_loop(int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8) { __FILE__->heart_beat_loop_callout(this_object(), effect1, effect2, effect3, effect4, effect5, effect6, effect7, effect8); }

void heart_beat_loop_callout(object map, int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8)    // 每2秒处理
{
	int sec = map->add_heart_sec(2);
	int time, count, value, i, j, p, x, y, z, color, value2;
	string name, * attrib, * attrib2;
	object npc, * player;
	if (sec < 600) return;
	if (map->get_war() == 2) return;
	player = map->get_player_dbase();

	tell_user(player, "%d", sec);

	if (sec == 600)
	{
		send_user(player, "%c%c%d%s", 0x43, 6, 0, CHAT + HIY + "Thành phố đang bị quái vật tấn công! đợt tấn công đầu tiên của quái vật sẽ tấn công trong một chút nữa！");
		return;
	}

	if (map->sizeof_comrade_dbase() >= 250)
	{
		send_user(player, "%c%c%d%s", 0x43, 6, 0, CHAT + HIY + "Bởi vì lũ quái vật tấn công đã vượt quá giới hạn mà thành phố có thể chịu đựng chỉ 250，Nhiệm vụ sẽ thất bại。");
		send_user(player, "%c%c%d%s", 0x43, 6, 0, CHAT + HIY + "Mặc dù chúng tôi cố hết sức để chiến đấu，Nhưng chúng ta đã thất bại trong cuộc chiến này。Tôi mong đợi nỗ lực của anh lần tới，Hiệu quả tốt hơn！");
		send_user(player, "%c%c%d%s", 0x43, 6, 0, CHAT + HIY + "Anh có thể dùng "HIR"Tín Vật"NOR"Đợi các thiết bị truyền tin Rời khỏi Chiến trường này。");
		CHAT_D->sys_channel(0, HIY + map->get_city() + "的" + map->get_name() + "Bởi quái vật Phá hoại，Sức mạnh quốc gia đã bị đánh rất mạnh。");
		map->before_destruct();
		//  destruct(map);
		return;
	}

	if (map->get_damage() >= 100)
	{
		send_user(player, "%c%c%d%s", 0x43, 6, 0, CHAT + HIY + "Bởi vì thiệt hại của thành phố vượt quá giới hạn 100，Nhiệm vụ hoàn toàn thất bạ。");
		send_user(player, "%c%c%d%s", 0x43, 6, 0, CHAT + HIY + "虽然大家竭尽全力征战，但本战我们还是失败了。期待大家下次再接再厉，发挥更出色的表现！");
		send_user(player, "%c%c%d%s", 0x43, 6, 0, CHAT + HIY + "Anh có thể dùng "HIR"Tín Vật"NOR"Đợi các thiết bị truyền tin Rời khỏi Chiến trường này。");
		CHAT_D->sys_channel(0, HIY + map->get_city() + "的" + map->get_name() + "Bởi quái vật Phá hoại，Sức mạnh quốc gia đã bị đánh rất mạnh。");
		map->before_destruct();
		return;
	}
	if (sec < 660) return;
	map->set_war(1);
	sec -= 660;
	if (sec <= 90 * 40 + 32)
	{
		time = sec / 90;
		count = (sec % 90) / 2;
		time++;
		attrib = "/quest/defence"->get_npc_attrib(map->get_level(), sprintf("%d", time));
		if (attrib == 0) return;
		value = to_int(attrib[6]);
		value2 = value;
		if (value < 16)
		{
			if (count > 0) return;
		}
		else
		{
			if (count >= value / 6) return;
			value = value / 16;
		}
		if (count == 0)
		{
			send_user(player, "%c%c%d%s", 0x43, 6, 0, HIR "Thành phố đang bị quái vật ác độc tấn công！");
			send_user(player, "%c%c%d%s", 0x43, 6, 0, sprintf(HIR "第%d Con quái vật của Bo bắt đầu tấn công！", time));
			send_user(player, "%c%c%d%s", 0x43, 6, 0, sprintf(HIR "đã có %d Chỉ có quái vật mới tấn công！", map->sizeof_comrade_dbase()));
		}

		value = value / 3;
		z = map->get_id();
		for (i = 0; i < 3; i++)
		{
			p = get_jumpin(z, i + 2);
			x = (p % 1000000) / 1000;
			y = p % 1000;
			for (j = 0; j < value; j++)
			{
				p = get_valid_xy(z, x + random(5), y + random(5), IS_CHAR_BLOCK);
				if (p)
				{
					x = (p % 1000000) / 1000;
					y = p % 1000;
				}
				if (value2 == 6)
				{
					if (time < 40) npc = new ("/npc/war/1101");
					else npc = new ("/npc/war/1102");
				}
				else
					npc = new ("/npc/war/1100");
				switch (attrib[5])
				{
				case "空手":
				case "武器":
					npc->set_weapon_code(UNARMED);
					npc->set_caster(0);
					break;
				case "暗器":
					npc->set_weapon_code(THROWING);
					npc->set_caster(1);
					break;
				default:
					npc->set_weapon_code(UNARMED);
					npc->set_caster(1);
					break;
				}

				npc->set_level(to_int(attrib[4]));
				npc->set_char_picid(to_int(attrib[0]));
				if (attrib[1] == "－") color = 0;
				else sscanf(attrib[1], "%x", color);
				npc->set_head_color(color);
				attrib2 = ({ attrib[2], attrib[3], attrib[5] });
				"/sys/npc/energy"->init_npc(npc, npc->get_level(), attrib2);
				if (value == 2)
				{
					if (time < 40)
					{
						npc->set_max_hp(npc->get_max_hp() * 10);
						npc->set_hp(npc->get_max_hp());
						npc->set_cp(npc->get_cp() * 105 / 100);
						npc->set_ap(npc->get_ap() * 105 / 100);
					}
					else
					{
						npc->set_max_hp(npc->get_max_hp() * 40);
						npc->set_hp(npc->get_max_hp());
						npc->set_cp(npc->get_cp() * 110 / 100);
						npc->set_ap(npc->get_ap() * 110 / 100);
					}
				}

				npc->add_to_scene(z, x, y, 6);
				map->add_comrade(npc);
			}
		}
	}
	else
	{
		if (map->sizeof_comrade_dbase() == 0)
		{
			CHAT_D->sys_channel(0, HIY"với nỗ lực đồng nhất của các chiến binh，Cuộc tấn công cuối cùng cũng từ chối" + map->get_city() + map->get_name() + "Một đội quân quái vật，Cảm ơn đã giúp đỡ！");
			send_user(player, "%c%c%d%s", 0x43, 6, 0, HIY"với nỗ lực đồng nhất của các chiến binh，Cuộc tấn công cuối cùng cũng từ chối" + map->get_city() + map->get_name() + "Một đội quân quái vật，Cảm ơn đã giúp đỡ！");
			send_user(player, "%c%c%d%s", 0x43, 6, 0, CHAT + HIY + "你们可以使用"HIR"门派信物"NOR"等传送道具Rời khỏi.这个战场。");
			map->before_destruct();
		}
	}
}

void before_destruct()
{
	object map, * char, npc;
	int i, size;

	map = this_object();

	if (arrayp(char = map->get_comrade_dbase()))
	{
		for (i = 0, size = sizeof(char); i < size; i++) if (objectp(npc = char[i]))
		{
			npc->remove_from_scene();
			destruct(npc);
		}
	}

	"/sys/party/defence"->add_end_count(1);
	map->set_war(2);
}

void init_place(object map)
{
	object npc, * all;
	int i, z;
	int* locate = ({ 87, 123 , 95, 129 , 95, 117 , 107, 126, 121, 111, 110, 102, 86, 140, 77, 134, });
	z = map->get_id();
	for (i = 0; i < 8; i++)
	{
		npc = new ("/npc/war/1017");
		npc->set_level(map->get_level() / 2);
		npc->add_to_scene(z, locate[2 * i], locate[2 * i + 1], 2);
		set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
	}
}