/*****************************
	**情人节**
*****************************/

#include <ansi.h>
#include <music.h>
#include <task.h>
#include <time.h>
#include <cmd.h>

int* nScene = ({ 1,10,20,30,40,50,60,70,80 });
int iStart214, iFinish214, close_val, open_val = 0;
object ChocoLate;
object* TinhNhan;
object check_tn(object me, object who);
mapping mpTinhNhan;

void generate_tinhnhan();
void destroy_tinhnhan();

void get_chocolate();
void SAVE_BINARY() { }

void create()
{
	int year = 0;
	mixed* mixTime;
	mixTime = localtime(time());
	year = mixTime[TIME_YEAR];

	iStart214 = mktime(year, 2, 10, 0, 0, 0);
	iFinish214 = mktime(year, 2, 24, 23, 59, 59);

	TinhNhan = ({});
	mpTinhNhan = ([]);
	call_out("check_time", 5);

}

void check_time()
{
	int iHour, p;
	mixed* mixTime;
	remove_call_out("check_time");
	iHour = time();
	switch (open_val)
	{
	case 1:

		mixTime = localtime(time());
		iHour = mixTime[TIME_HOUR];
		if (mixTime[TIME_MIN] >= 30)
			call_out("check_time", 60 * (60 - mixTime[TIME_MIN]));
		else
			call_out("check_time", 60 * (30 - mixTime[TIME_MIN]));
		if (iHour == 0 || iHour == 1 || iHour == 2 || iHour == 3 || iHour == 4 || iHour == 5 || iHour == 6 || iHour == 7 || iHour == 8 || iHour == 9 || iHour == 10 || iHour == 11 || iHour == 12 || iHour == 13 || iHour == 14 || iHour == 15 || iHour == 16 || iHour == 17 || iHour == 18 || iHour == 19 || iHour == 20 || iHour == 21 || iHour == 22 || iHour == 23)	//放Pháo
		{
			generate_tinhnhan();
		}

		break;
	case 0:
		if (iHour > iFinish214) {
			destroy_tinhnhan();
			return;
		}

		if (iHour < iStart214)
		{
			call_out("check_time", iStart214 - iHour);
			return;
		}

		mixTime = localtime(time());
		iHour = mixTime[TIME_HOUR];
		if (mixTime[TIME_MIN] >= 30)
			call_out("check_time", 60 * (60 - mixTime[TIME_MIN]));
		else
			call_out("check_time", 60 * (30 - mixTime[TIME_MIN]));

		if (iHour % 2 != 0)
		{
			generate_tinhnhan();
		}

		break;
	}

	get_chocolate();

}

void get_chocolate()
{
	int z, x, y;
	object* item;

	z = 1;
	x = 156;
	y = 129;

	if (have_scene_object(z, x, y, CHAR_TYPE, 1))
	{
		item = get_scene_object(z, x, y, CHAR_TYPE, 1);
		if (item[0]) {
			item[0]->remove_from_scene();
			destruct(item[0]);
		}
	}

	if (!objectp(ChocoLate))
	{
		ChocoLate = new("/npc/party/chocolate");
		ChocoLate->add_to_scene(z, x, y, 8);
	}
}

void do_valentine4_call(object who, object me)
{
	object map, npc, item;
	string* member, name;
	int level, i, size;
	int z, x, y, p, iType, x1, y1;
	if (who->get_quest("valentine.flag") == 2 && who->get_quest("valentine.type") != 1)
	{
		x = who->get("valentine.x");
		y = who->get("valentine.y");
		z = who->get("valentine.z");
		name = who->get_quest("valentine.name");
		if (!stringp(name))	return;
		if (!objectp(map = get_map_object(z)) || !map->is_scene()) return;
		for (i = 0; i < 100; i++)
		{
			if (p = get_valid_xy(z, abs(x + random(10) - 5), abs(y + random(10) - 5), IS_CHAR_BLOCK))
			{
				x1 = p / 1000;  y1 = p % 1000;  break;
			}
		}
		npc = new("/npc/party/rosethief");
		npc->set_name(sprintf("Kẻ trộm hoa hồng(%d)", who->get_number()));
		npc->set_char_picid(0202);
		npc->set_max_hp(1);
		npc->set_ap(1);
		npc->set_dp(1);
		npc->set_cp(1);
		npc->set_pp(1);
		npc->set_sp(1);
		npc->set_walk_speed(4);
		npc->set_attack_speed(3);
		npc->add_to_scene(z, x, y, 3);
		member = ({ sprintf("%d", who->get_number()) });
		npc->set("user", member);
		map->add_reset(npc);
		who->set_quest("valentine.time", time());
		who->set_quest("valentine.thief", sprintf("%x#", getoid(npc)));
		who->set_quest("valentine.z", z);
		who->set_quest("valentine.x", x);
		who->set_quest("valentine.y", y);
		who->set_quest("valentine.type", 1);
		npc->set("task", who->get_number());

		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "Valentine Day");
		send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 2, "Kẻ trộm hoa hồng");
		send_user(who, "%c%s", '!', "Bạn đã nhận được Valentine Day————Kẻ trộm hoa hồng！");
	}
}

void do_valentine5_call(object who, object me)
{
	if (who->get_quest("valentine.flag") == 6 && who->get_quest("valentine.type") != 1)
	{
		object map, npc, item;
		string* member, name;
		int level, i, size;
		int z, x, y, p, iType, x1, y1;
		if (USER_INVENTORY_D->count_empty_carry(who) < 3)
		{
			send_user(who, "%c%s", ';', "Hành trang không đủ chỗ trống.");
			return;
		}
		x = who->get("valentine.x");
		y = who->get("valentine.y");
		z = who->get("valentine.z");
		name = who->get_quest("valentine.name");
		if (!stringp(name))	return;
		if (!objectp(map = get_map_object(z)) || !map->is_scene()) return;
		for (i = 0; i < 100; i++)
		{
			if (p = get_valid_xy(z, abs(x + random(10) - 5), abs(y + random(10) - 5), IS_CHAR_BLOCK))
			{
				x1 = p / 1000;  y1 = p % 1000;  break;
			}
		}
		npc = new("/npc/party/gangster");
		npc->set_name(sprintf("ngày lễ tình nhân (%d)", who->get_number()));
		npc->set_char_picid(0053);
		npc->set_max_hp(1);
		npc->set_ap(1);
		npc->set_dp(1);
		npc->set_cp(1);
		npc->set_pp(1);
		npc->set_sp(1);
		npc->set_walk_speed(4);
		npc->set_attack_speed(3);
		npc->add_to_scene(z, x, y, 3);
		member = ({ sprintf("%d", who->get_number()) });
		npc->set("user", member);
		map->add_reset(npc);
		who->set_quest("valentine.time", time());
		who->set_quest("valentine.thief", sprintf("%x#", getoid(npc)));
		who->set_quest("valentine.z", z);
		who->set_quest("valentine.x", x);
		who->set_quest("valentine.y", y);
		who->set_quest("valentine.type", 1);
		npc->set("task", who->get_number());

		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "Valentine Day");
		send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 6, "Thiên thần yêu sắc");
		send_user(who, "%c%s", '!', "Bạn đã nhận được Valentine Day————Thiên thần yêu sắc！");
	}
}

void generate_tinhnhan()
{
	int i, size, z, p, x, y, j, count, amount;
	object* nObj, npc;
	nObj = ({});
	destroy_tinhnhan();
	for (j = 0, count = sizeof(nScene); j < count; j++)
	{
		z = nScene[j];
		nObj = mpTinhNhan[z];
		if (!arrayp(nObj))
			nObj = ({});
		nObj -= ({ 0 });
		amount = 30 - sizeof(nObj);
		nObj = ({});
		for (i = 0; i < amount; i++)
		{
			if (!(p = efun::get_xy_point(z, IS_CHAR_BLOCK)))
				continue;
			x = (p % 1000000) / 1000;  y = p % 1000;
			npc = new("/npc/event/qvvlt");
			npc->add_to_scene(z, x, y);
			TinhNhan += ({ npc });
			nObj += ({ npc });
		}
		mpTinhNhan[z] = nObj;
	}
	CHAT_D->sys_channel(0, HIR "Quái vật Valentine đã xuất hiện ngoài thành các quốc gia, nghe nói tiêu diệt chúng sẽ đạt được Chocolate !");
}

void destroy_tinhnhan()
{
	int i, size;
	for (i = 0, size = sizeof(TinhNhan); i < size; i++)
	{
		if (!objectp(TinhNhan[i]))
			continue;
		TinhNhan[i]->remove_from_scene();
		destruct(TinhNhan[i]);
	}
}

void task_giveup(object who, int iKind)
{
	object map, * reset, npc, item;
	string thief, * member;
	int time, id, i, size;
	if (!who->get_quest("valentine.flag"))
	{
		return;
	}
	if (iKind != who->get_quest("valentine.flag"))
		return;
	switch (iKind)
	{
	default: break;
	case 1:
		who->set_quest("valentine.flag", 0);
		if (objectp(item = present("Một gói hàng từ Viện Hàn", who, 1, MAX_CARRY)))
		{
			item->remove_from_user();
			destruct(item);
		}
		break;
	case 2:
		who->delete_quest("valentine.bonus");
		if (stringp(thief = who->get_quest("valentine.thief"))
			&& (npc = find_char(thief)))
		{
			member = npc->get("user");
			thief = sprintf("%d", who->get_number());
			member -= ({ thief });
			if (sizeof(member) == 0)
			{
				npc->remove_from_scene();
				destruct(npc);
			}
		}
		if (objectp(item = present("Hạt giống bí ẩn", who, 1, MAX_CARRY)))
		{
			item->remove_from_user();
			destruct(item);
		}

		break;
	case 3:
	case 4:
		if (objectp(item = present("Hạt giống bí ẩn", who, 1, MAX_CARRY)))
		{
			item->remove_from_user();
			destruct(item);
		}
		break;
	case 5:
	case 6:
		who->set_quest("valentine.flag", 0);
		who->delete_quest("valentine.bonus");
		if (stringp(thief = who->get_quest("valentine.thief"))
			&& (npc = find_char(thief)))
		{
			member = npc->get("user");
			thief = sprintf("%d", who->get_number());
			member -= ({ thief });
			if (sizeof(member) == 0)
			{
				npc->remove_from_scene();
				destruct(npc);
			}
		}
		if (objectp(item = present("Son đỏ", who, 1, MAX_CARRY)))
		{
			item->remove_from_user();
			destruct(item);
		}
		if (objectp(item = present("Cái lược", who, 1, MAX_CARRY)))
		{
			item->remove_from_user();
			destruct(item);
		}
		if (objectp(item = present("Cây trâm", who, 1, MAX_CARRY)))
		{
			item->remove_from_user();
			destruct(item);
		}
		break;
	case 7:
	case 8:
		if (objectp(item = present("Đậu Socola", who, 1, MAX_CARRY)))
		{
			item->remove_from_user();
			destruct(item);
		}
		break;
	}

	send_user(who, "%c%c%c%w%w%w%s", 0x51, 1, 4, TID_VALENTINE, iKind, 0, "");
	send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, iKind, "");
	send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "");

	who->delete_quest("valentine.time");
	who->delete_quest("valentine.type");
	who->delete_quest("valentine.name");
	who->delete_quest("valentine.z");
	who->delete_quest("valentine.x");
	who->delete_quest("valentine.y");
	who->delete_quest("valentine.count");

}

void send_task_list(object who)
{
	int iFlag;
	string name, id;
	object npc;
	if (iFlag = who->get_quest("valentine.flag"))
	{

		switch (iFlag)
		{
		case 1: // 1. 
			send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "Valentine Day");
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 1, "Hạt giống bí ẩn");
			break;

		case 2: // 2. 
			if (who->get_quest("valentine.bonus") == 1)
			{
				send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "Valentine Day");
				send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 2, "Kẻ trộm hoa hồng(Hoàn thành)");
			}
			else if (stringp(id = who->get_quest("valentine.thief"))
				&& (npc = find_char(id)))
			{
				send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "Valentine Day");
				send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 2, "Kẻ trộm hoa hồng");
			}
			else
			{
				send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "Valentine Day");
				send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 2, "Kẻ trộm hoa hồng(Nhiệm vụ thất bại)");
			}
			break;

		case 3: // 3. 
			send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "Valentine Day");
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 3, "Tìm");
			break;

		case 4: // 4. 爱情之花
			send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "Valentine Day");
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 4, "Hoa của tình yêu");
			break;
		case 5: // 5. 情人节的传说
			send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "Valentine Day");
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 5, "Legend's Legend");
			break;

		case 6: // 6. 天使爱美丽
			if (who->get_quest("valentine.bonus") == 1)
			{
				send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "Valentine Day");
				send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 6, "Thiên thần yêu sắc(Hoàn thành)");
			}
			else if (stringp(id = who->get_quest("valentine.thief"))
				&& (npc = find_char(id)))    // 30 分钟
			{
				send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "Valentine Day");
				send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 6, "Thiên thần yêu sắc.");
			}
			else
			{
				send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "Valentine Day");
				send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 6, "Thiên thần yêu sắc.(任务失败)");
			}
			break;

		case 7: // 3. Đậu Socola
			send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "Valentine Day");
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 7, "Đậu Socola");
			break;

		case 8: // 4. Chocolate ngày Valentine
			send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "Valentine Day");
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 8, "Chocolate ngày Valentine");
			break;
		}
	}
}

void destruct_chocolate()
{
	if (objectp(ChocoLate))
	{
		ChocoLate->remove_from_scene();
		destruct(ChocoLate);
	}
}

int set_valentine(int open, int close)
{
	open_val = open;
	close_val = close;
	check_time();
	return 1;
}