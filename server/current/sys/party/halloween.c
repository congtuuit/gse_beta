/*******************************
	**Halloween**
*******************************/
#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <public.h>
#include <time.h>
#include <action.h>
#include <skill.h>
#include <effect.h>
#include <task.h>


inherit DBASE_F;
inherit SAVE_F;
#define DEBUG_STR(player,str) {tell_user(player,"str=%s",str);}

#define MAP_ID 894
#define FILE_MAP    "map/copy/894"

#define YEU_MA_BI_NGO	"npc/event/halloween/yeumabingo"
#define EVENT_NPC_MAIN	"npc/event/halloween/npc"

//Tui qua Top
#define ITEM_TOP_1 "item/event/halloween/top1"
#define ITEM_TOP_2 "item/event/halloween/top2"
#define ITEM_TOP_3 "item/event/halloween/top3"

#define GIFT_EVENT	"item/event/halloween/bingo"

int iStart, iFinish, iFinish_a, kkkk, close, iStart_2, iFinish_phoban;
//object* nObjs= ({});
object* Map;
object event_npc;
string* nWord = ({
	"Halloween là một lễ hội truyền thống được tổ chức vào ngày 31 tháng 10 hàng năm.Trọng tâm theo truyền thống của Halloween xoay quanh chủ đề sử dụng sự hài hước và chế giễu để đối đầu với quyền lực của cái chết.",
	"Cùng tham gia sự kiện để nhận nhiều phần quà hấp dẫn.",
	"Thu thập nhiều hồn ma yêu tinh để nhận lấy phần quà giá trị",
	"Hãy vào Phục Ma trận bắt Cương Thi về giao nộp cho ta nhé, ta có phần thưởng xứng đáng cho ngươi đấy!!",
	"Yêu Tinh Bí Ngô thỉnh thoảng xuất hiện ngoại thành, hãy tiêu diệt chúng!",
	});

void SAVE_BINARY() { }
string get_save_file() { return "data/Halloween"SAVE_EXTENSION; }

void do_look(object npc, object player);
void do_welcome(object npc, string arg);
void call_npc();
void destruct_npc();
void before_destruct();
void call_yeu_ma_bi_ngo();
void detrust_yeu_ma_bi_ngo();
void get_close();
void set_close();
void give_to_user(object player, int amount_s, string name);

void paihangbang(object player, object npc);
void update_record(object player);
void paihangbang_bonus(int top, int vip, int potential, int cash, object player, object npc);
int check_event_item(object who, int count, string name);
int give_event_item(object who, string name, int count);
int give_gift_100(object player, object npc);
void give_mission(object npc, object player);
void before_give_mission(object npc, object player);
void finished_mission(object npc, object player);

int add_point_top(object player, object npc);

void check_time();
void check_time2();
void check_time3();

void create_copy_npc(int next, int sec, int z, object who, int number);
void enter_phoban(object me, object who);
int new_copy_scene(object who, object me);

void create()
{
	Map = ({});

	restore();

	int year = 0;
	mixed* mixTime;
	mixTime = localtime(time());
	year = mixTime[TIME_YEAR];

	iStart = mktime(year, 10, 30, 19, 0, 0);
	iFinish = mktime(year, 11, 12, 23, 0, 0);

	iFinish_phoban = mktime(year, 11, 10, 23, 0, 0);

	call_out("check_time", 1);
}

void check_time()
{
	int iTime;
	mixed* mixTime;

	iTime = get_party_time();
	mixTime = localtime(iTime);
	remove_call_out("check_time");

	log_file("Halloween.txt", sprintf("%d tháng %d ngày %d :%d Checktime\n", mixTime[TIME_MON] + 1, mixTime[TIME_MDAY], mixTime[TIME_HOUR], mixTime[TIME_MIN]));
	
	detrust_yeu_ma_bi_ngo();

	if (iTime < iStart)
	{
		log_file("Halloween.txt", sprintf("%d tháng %d ngày %d :%d Checktime- Chưa tới\n", mixTime[TIME_MON] + 1, mixTime[TIME_MDAY], mixTime[TIME_HOUR], mixTime[TIME_MIN]));

		destruct_npc();
		detrust_yeu_ma_bi_ngo();
		call_out("check_time", iStart - iTime);
		return;
	}
	
	if (iTime > iFinish)
	{
		log_file("Halloween.txt", sprintf("%d tháng %d ngày %d :%d Checktime- Đã hết\n", mixTime[TIME_MON] + 1, mixTime[TIME_MDAY], mixTime[TIME_HOUR], mixTime[TIME_MIN]));

		destruct_npc();
		detrust_yeu_ma_bi_ngo();
		return;
	}

	call_npc();

	if (mixTime[TIME_HOUR] >= 22)
	{
		//destruct_npc();
		detrust_yeu_ma_bi_ngo();
		call_out("check_time", 3600 * 24 - mixTime[TIME_HOUR] * 3600 - mixTime[TIME_MIN] * 60);
		return;
	}

	if (mixTime[TIME_HOUR] < 8)
	{
		//destruct_npc();
		detrust_yeu_ma_bi_ngo();
		call_out("check_time", 3600 * 8 - mixTime[TIME_HOUR] * 3600 - mixTime[TIME_MIN] * 60);
		return;
	}

	log_file("Halloween.txt", sprintf("%d tháng %d ngày %d :%d Checktime2\n", mixTime[TIME_MON] + 1, mixTime[TIME_MDAY], mixTime[TIME_HOUR], mixTime[TIME_MIN]));

	check_time2();
}

void check_time2()
{
	int iTime, iHour, random;
	mixed* mixTime, * mixTime_2;
	object npc;

	iTime = get_party_time();
	mixTime = localtime(iTime);

	if (get_close()) return;

	if (iTime > iFinish)
	{
		destruct_npc();
		detrust_yeu_ma_bi_ngo();

		USER_D->user_channel("Hoạt động Halloween khép lại, hẹn gặp lại mọi người vào kỳ tới...");
		log_file("Halloween.txt", sprintf("%d tháng %d ngày %d :%d Halloween hoạt động kết thúc.\n", mixTime[TIME_MON] + 1, mixTime[TIME_MDAY], mixTime[TIME_HOUR], mixTime[TIME_MIN]));
		call_out("destruct_npc", iFinish - iTime);
		return;
	}


	if (mixTime[TIME_HOUR] >= 22)
	{
		//destruct_npc();
		detrust_yeu_ma_bi_ngo();

		//USER_D->user_channel("Hôm nay hoạt động đến đây kết thúc, ngày mai mời mọi người trở lại tham gia hoạt động .");
		call_out("check_time2", 3600 * 24 - mixTime[TIME_HOUR] * 3600 - mixTime[TIME_MIN] * 60);
		log_file("Halloween.txt", sprintf("%d tháng %d ngày %d :%d Halloween cuối ngày.\n", mixTime[TIME_MON] + 1, mixTime[TIME_MDAY], mixTime[TIME_HOUR], mixTime[TIME_MIN]));
		return;
	}

	if (mixTime[TIME_HOUR] < 8)
	{
		call_out("check_time2", 3600 * 8 - mixTime[TIME_HOUR] * 3600 - mixTime[TIME_MIN] * 60);
		return;
	}

	USER_D->user_channel("Hoạt động Halloween đang diễn ra, hãy tới "HIC"Sứ Giả Nhiệm Vụ"NOR" tại Tân Thủ Thôn (1) để tham gia...");
	//call_npc();

	if (mixTime[TIME_HOUR] >= 18 && mixTime[TIME_HOUR] <= 22) {
		call_yeu_ma_bi_ngo();
	}

	call_out("check_time2", 60 * (60 - mixTime[TIME_MIN]) + 3600);
	log_file("Halloween.txt", sprintf("%d tháng %d ngày %d :%d Sứ giả Hallowen\n", mixTime[TIME_MON] + 1, mixTime[TIME_MDAY], mixTime[TIME_HOUR], mixTime[TIME_MIN]));

}

/*View NPC*/
void do_look(object npc, object player)
{
	int index;
	string dailogue = "";
	string* choices1 = ({ HIY"Nhiệm vụ thu thập",HIC"Tiến vào phó bản Phục Ma","Giao nộp Mũ Cương Thi",HIC"Bảng xếp hạng Phục Ma","Thông tin sự kiện", });
	string* choices2 = ({ HIY"Nhiệm vụ thu thập","Bảng xếp hạng Phục Ma",HIY"Nhận giải thưởng", "Giao nộp Mũ Cương Thi" });

	int iTime;
	mixed* mixTime;
	iTime = get_party_time();
	mixTime = localtime(iTime);

	if (iTime < iFinish_phoban)
	{
		dailogue += sprintf("     %s\n", nWord[random(sizeof(nWord))]);
		for (index = 0; index < 4; index++)
		{
			dailogue += sprintf(ESC"%s\ntalk %x# welcome.%d\n", choices1[index], getoid(npc), index + 10);
		}
		//send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + dailogue + sprintf(ESC"Mua vật phẩm\nlist %x#\n", getoid(npc)) + ESC"Rời khỏi\n");
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + dailogue + ESC"Rời khỏi\n");
	}
	else
	{
		dailogue += "    Sự kiện Halloween sắp kết thúc, ngươi cần ta giúp gì ?\n";
		for (index = 0; index < 4; index++)
		{
			dailogue += sprintf(ESC"%s\ntalk %x# welcome.%d\n", choices2[index], getoid(npc), index + 20);
		}
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + dailogue + ESC"Rời khỏi\n");
	}
}

void do_welcome(object npc, string arg)
{
	int flag, i, size, index, move, pos, record, index2, name_size, iTime;
	int id = getoid(npc);
	object who, item, player, obj;
	string name, cTmp, id1, tmp = "", cmd = "", playername;
	mixed* mixTime;

	player = this_player();
	iTime = get_party_time();

	mixTime = localtime(iTime);

	if (sscanf(arg, "%d.%s", flag, id1) != 2)
	{
		flag = to_int(arg);
	}
	if (!flag)
	{
		return;
	}

	switch (flag)
	{
		//Nhiem vu
	case 10:
	case 20:
		if (get_party_time() > iFinish) return;
		before_give_mission(npc, player);

		break;
		//Pho ban phuc ma
	case 11:
		if (get_party_time() > iFinish_phoban) return;
		enter_phoban(npc, player);
		break;

		//Nop vat pham
	case 12:
		if (get_party_time() > iFinish_phoban) return;

		if (check_event_item(player, 1, "Mũ Cương Thi") != 1)
		{
			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + "    Xin lỗi bạn không có "HIR"Mũ Cương Thi"NOR" nào\n" + ESC"Xác nhận\n");
			return;
		}

		if (add_point_top(player, npc)) {
			player->add_save("tuziHalloween", 5);
			update_record(player);
		}
		break;

		//Bang xep hang
	case 13:
	case 21:
		paihangbang(player, npc);
		break;

		//Thong tin su kien
	case 13:
		if (get_party_time() > iFinish) return;
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s:\n    Thời gian hoạt động từ 17h00 ngày 30 tháng 10 đến 22h ngày 10 tháng 11 sự kiện sẽ kết thúc. Event bắt đầu lúc 08:00 đến 22h hàng ngày.\n"ESC"Xác nhận", npc->get_name()));
		break;

		//Nhan thuong top
	case 22:
		if (get_party_time() > iFinish) return;
		if (iTime <= iFinish_phoban) {
			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n	Rất xin lỗi, chưa tới lúc để nhận thưởng" + ESC"Xác nhận\n");
			return;
		}
		if (get_save_2(sprintf("player.%d.bonus", player->get_number())))
		{
			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + "    Bạn đã nhận giải thưởng rồi, không thể nhận tiếp.\n" + ESC"Xác nhận\n");
			return;
		}
		pos = get_save_2(sprintf("player.%d.pos", player->get_number()));
		if (pos < 1 || pos > 10)
		{
			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + "    Xin lỗi tên của bạn không có trên bảng xếp hạng\n" + ESC"Xác nhận\n");
			return;
		}
		//Qua top bat tho
		switch (pos)
		{
		case 1:
			paihangbang_bonus(pos, 1, 1000, 1000000, player, npc);
			break;
		case 2:
			paihangbang_bonus(pos, 1, 900, 500000, player, npc);
			break;
		case 3:
			paihangbang_bonus(pos, 1, 800, 100000, player, npc);
			break;
		case 4:
			paihangbang_bonus(pos, 0, 700, 70000, player, npc);
			break;
		case 5:
			paihangbang_bonus(pos, 0, 600, 60000, player, npc);
			break;
		case 6:
			paihangbang_bonus(pos, 0, 500, 50000, player, npc);
			break;
		case 7:
			paihangbang_bonus(pos, 0, 400, 40000, player, npc);
			break;
		case 8:
			paihangbang_bonus(pos, 0, 300, 30000, player, npc);
			break;
		case 9:
			paihangbang_bonus(pos, 0, 200, 20000, player, npc);
			break;
		default:
			paihangbang_bonus(pos, 0, 100, 10000, player, npc);
		}
		break;


	case 23:
		if (get_party_time() > iFinish) return;

		if (check_event_item(player, 1, "Mũ Cương Thi") != 1)
		{
			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + "    Xin lỗi bạn không có "HIR"Mũ Cương Thi"NOR" nào\n" + ESC"Xác nhận\n");
			return;
		}

		break;
		//Tiep nhan nhiem vu
	case 100:
		give_mission(npc, player);
		break;

	case 111:
		finished_mission(npc, player);
		break;
	}
}

/*Event NPC */
void call_npc()
{
	if (!objectp(event_npc))
	{
		event_npc = new(EVENT_NPC_MAIN);
		event_npc->add_to_scene(01, 148, 144, 4);
	}

	//USER_D->user_channel("Sự kiện Halloween đang diễn ra, hãy đến "HIM"Sứ giả Halloween"NOR" xem tham gia...");
}
void destruct_npc()
{
	if (objectp(event_npc))
	{
		event_npc->remove_from_scene();
		destruct(event_npc);
	}
}
void before_destruct()
{
	if (objectp(event_npc))
	{
		event_npc->remove_from_scene();
		destruct(event_npc);
	}
}

/*Hoat dong*/
void call_yeu_ma_bi_ngo()
{
	int i, z, p, x, y, iTime;
	object* nObj, item;
	mixed* mixTime;
	detrust_yeu_ma_bi_ngo();
	nObj = ({});

	iTime = get_party_time();

	if (iTime > iFinish) {
		return;
	}
	
	for (z = 10; z <= 80; z += 10)
	{
		for (i = 0; i < 15; i++)
		{
			if (!(p = efun::get_xy_point(z, IS_CHAR_BLOCK)))
				continue;
			x = (p % 1000000) / 1000;  y = p % 1000;
			item = new(YEU_MA_BI_NGO);
			if (!objectp(item))
				continue;
			item->add_to_scene(z, x, y);
			nObj += ({ item });
		}
	}

	EVENT_NPC_MAIN->set("item", nObj);
	USER_D->user_channel(HIC"Nghe nói "ECHO"Cương Thi"HIC" xuất hiện ở ngoại thành các nước, hãy nhanh dẫn chúng về giao nộp cho "HIM"Sứ giả Hallowen"HIC" để nhận thưởng #58");
}
void detrust_yeu_ma_bi_ngo()
{
	int i, size;
	object* nObj;
	nObj = EVENT_NPC_MAIN->get("item");
	for (i = 0, size = sizeof(nObj); i < size; i++)
	{
		if (!objectp(nObj[i]))
			continue;
		if (get_d(nObj[i]))
			continue;
		nObj[i]->remove_from_scene();
		destruct(nObj[i]);
	}

	EVENT_NPC_MAIN->delete("item");
}

/*Function*/
//Kiem tra trang thai hoat dong
int get_close()
{
	return close;
}
//Ket thuc hoat dong
void set_close()
{
	close = 1;
	destruct_npc();
	/*destroy_yutu();
	destroy_event_item();*/
}

void give_to_user(object player, int amount_s, string name)
{
	int p, total, amount;
	object item;
	string name_s;
	item = new(name);
	if (item)
	{
		name_s = item->get_name();
		if (item->get_max_combined() > 1)
		{
			total = amount_s;
			amount = USER_INVENTORY_D->carry_combined_item(player, item, total);
			if (amount > 0 && item->set_amount(amount))
			{
				if (p = item->move(player, -1))
				{
					item->add_to_user(p);
				}
			}
			else
			{
				item->add_amount(-total);
			}
		}
		else
		{
			if (p = item->move(player, -1))
			{
				item->add_to_user(p);
			}
		}

		USER_D->user_channel("Chúc mừng bằng hữu "HIY + player->get_name() + NOR" trong sự kiện Halloween nhận được " + HIR + name_s + ".\n");
	}
}

/*XEP HANG*/
void paihangbang(object player, object npc)
{
	int index, pos, name_size, id, max_blank, i;
	string tmp = "", cmd = "", playername, blank = "";
	blank = repeat_string(" ", 10);

	for (index = 1; index <= 5; index++)
	{
		id = get_save_2(sprintf("record.%d", index));
		if (!id)
		{
			tmp = sprintf(" ""%2d.%s%s%s", index, " ", "", "Chưa cập nhật");
			tmp += blank;
			tmp += sprintf(" ""%2d.%s%s%s", index + 5, " ", "", "Chưa cập nhật");
			tmp += "\n";
		}
		else
		{
			playername = get_save_2(sprintf("player.%d.name", id));
			name_size = strlen(playername);
			if (name_size <= 12)
			{
				playername += repeat_string(" ", 12 - name_size);
			}
			switch (index)
			{
			case 1:
				tmp = sprintf(" ""R""%2d.%12s%4s%3d"NOR, 1, playername, ":", get_save_2(sprintf("player.%d.count", id)));
				max_blank = get_save_2(sprintf("player.%d.count", id));
				break;
			case 2:
				tmp = sprintf(" ""M""%2d.%12s%4s%3d"NOR, 2, playername, ":", get_save_2(sprintf("player.%d.count", id)));
				break;
			case 3:
				tmp = sprintf(" ""B""%2d.%12s%4s%3d"NOR, 3, playername, ":", get_save_2(sprintf("player.%d.count", id)));
				break;
			case 4:
				tmp = sprintf(" ""%2d.%12s%4s%3d", 4, playername, ":", get_save_2(sprintf("player.%d.count", id)));	//+BLK+BLK
				break;
			case 5:
				tmp = sprintf(" ""%2d.%12s%4s%3d", 5, playername, ":", get_save_2(sprintf("player.%d.count", id)));	//+BLK+BLK
				break;
			}

			tmp += blank;
			for (i = 0; i < 4; i++) {
				tmp += " ";
			}

			id = get_save_2(sprintf("record.%d", index + 5));
			if (!id)
			{
				tmp += sprintf(" ""%d.%s%s%s", index + 5, "", "", "Chưa cập nhật");
			}
			else
			{
				playername = get_save_2(sprintf("player.%d.name", id));
				name_size = strlen(playername);
				if (name_size <= 12)
				{
					playername += repeat_string(" ", 12 - name_size);
				}
				tmp += sprintf("""%2d.%8s%4s%3d", index + 5, playername, ":", get_save_2(sprintf("player.%d.count", id)));
			}
			tmp += "\n";
		}
		cmd += tmp;

	}

	send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("Bảng xếp hạng Sự kiện Halloween, bây giờ đã nộp "HIR"%d"NOR" Mũ Cương Thi \n", player->get_save("tuziHalloween")) + cmd
		+ ESC "Xác nhận\n");
}
void update_record(object player)
{
	int size, index, pos, oldid, id1, amount, i;
	int id = player->get_number();
	string name = player->get_name();
	amount = player->get_save("tuziHalloween");
	if (get_save_2(sprintf("player.%d", id)))
	{
		if (get_save_2(sprintf("player.%d.name", id)) == name)
		{
			set_save_2(sprintf("player.%d.count", id), amount);
			pos = get_save_2(sprintf("player.%d.pos", id));
		}
	}
	else if ((size = get_save_2(sprintf("record.size"))) < 10)
	{
		pos = size + 1;
		set_save_2("record.size", pos);
		set_save_2(sprintf("record.%d", pos), id);
		set_save_2(sprintf("player.%d.name", id), name);
		set_save_2(sprintf("player.%d.pos", id), pos);
		set_save_2(sprintf("player.%d.count", id), amount);
	}
	else
	{
		oldid = get_save_2(sprintf("record.%d", size));
		if (get_save_2(sprintf("player.%d.count", oldid)) < amount)
		{
			pos = size;
			delete_save_2(sprintf("player.%d", oldid));
			set_save_2(sprintf("record.%d", pos), id);
			set_save_2(sprintf("player.%d.name", id), name);
			set_save_2(sprintf("player.%d.pos", id), pos);
			set_save_2(sprintf("player.%d.count", id), amount);
			set_save_2("record.size", pos);
		}
	}
	if (pos)
	{
		for (index = pos; index > 1; index--)
		{
			id = get_save_2(sprintf("record.%d", index));
			id1 = get_save_2(sprintf("record.%d", index - 1));
			if (get_save_2(sprintf("player.%d.count", id1)) >= get_save_2(sprintf("player.%d.count", id)))
			{
				break;
			}
			set_save_2(sprintf("record.%d", index), id1);
			set_save_2(sprintf("player.%d.pos", id1), index);
			set_save_2(sprintf("record.%d", index - 1), id);
			set_save_2(sprintf("player.%d.pos", id), index - 1);
		}
		save();
	}

}

//Thuong Top
void paihangbang_bonus(int top, int vip, int potential, int cash, object player, object npc)
{
	int flag = 0, iVipTime, iVip, iTime;
	int id = player->get_number();
	mixed* mixTime;

	iTime = get_party_time();

	if (iTime <= iFinish_phoban) {
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n	Rất xin lỗi, chưa tới lúc để nhận thưởng" + ESC"Xác nhận\n");
		return;
	}

	if (sizeof_inventory(player, 2, MAX_CARRY) >= MAX_CARRY)
	{
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n	Rất xin lỗi, muốn nhận được phần thưởng , vui lòng để trống hành trang. Nếu như kinh nghiệm cùng tiềm năng đạt tới giới hạn, cũng không thể nhận được." + ESC"Xác nhận\n");
		return;
	}

	switch (top)
	{
	case 1:
		give_to_user(player, 1, ITEM_TOP_1);
		break;
	case 2:
		give_to_user(player, 1, ITEM_TOP_2);
		break;
	case 3:
		give_to_user(player, 1, ITEM_TOP_3);
		break;
	default:
		break;
	}

	player->add_potential(potential);
	player->add_cash(cash);
	set_save_2(sprintf("player.%d.bonus", id), 1);
	save();
}

//Tich tiem
int add_point_top(object player, object npc)
{
	int rand, id, move, level;
	string* nTmp;
	object item;

	id = player->get_number();

	if (sizeof_inventory(player, 1, MAX_CARRY) >= MAX_CARRY)
	{
		send_user(player, "%c%s", '!', "Hành trang trên người ngươi không đủ, lần sau nhận thưởng phải chú ý");
		return 0;
	}

	if (give_event_item(player, "Mũ Cương Thi" , 5 ) == 0)
	{
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s:\n   Xin lỗi, bạn không có đủ "HIR"5 Mũ Cương Thi.\n"ESC"Xác nhận", npc->get_name()));
		return 0;
	}

	give_to_user(player, 1, GIFT_EVENT);

	return 1;
}


/*NHIEM VU*/
//Thu phuc yeu ma - GIFT

int check_event_item(object who, int count, string name)
{
	int i, size, amount;
	object* inv, item;
	inv = all_inventory(who, 1, MAX_CARRY * 4);
	if (!inv)
	{
		return 0;
	}
	
	if (!objectp(item = present(name, who, 1, MAX_CARRY * 4)))
	{
		return 0;
	}

	for (i = 0, size = sizeof(inv); i < size; i++)
	{
		if (!objectp(inv[i]))
			continue;
		if (inv[i]->get_name() != name)
			continue;
		if (inv[i]->is_combined())
			amount += inv[i]->get_amount();
		else
			amount++;
	}
	if (amount < count)
	{
		return 0;
	}

	return 1;
}

int give_event_item(object who, string name, int count)
{
	int i, size, amount;
	object* inv, item;
	if (check_event_item(who, count, name) != 1)
		return 0;
	inv = all_inventory(who, 1, MAX_CARRY * 4);
	for (i = 0, size = sizeof(inv); i < size; i++)
	{
		if (!objectp(inv[i]))
			continue;
		if (inv[i]->get_name() != name)
			continue;
		amount = inv[i]->get_amount();
		if (count >= amount)
		{
			count -= amount;
			inv[i]->remove_from_user();
			destruct(inv[i]);
		}
		else
		{
			inv[i]->add_amount(-count);
			count = 0;
		}
		if (count <= 0)
			break;
	}
	return 1;

}

//gift for mission
int give_gift_100(object player, object npc)
{
	int rand, id, move, level;
	object item;

	if (sizeof_inventory(player, 1, MAX_CARRY) >= MAX_CARRY)
	{
		send_user(player, "%c%s", '!', "Hành trang trên người ngươi không đủ, lần sau nhận thưởng phải chú ý");
		return 0;
	}

	player->delete_save_2("halloween", 0);
	give_to_user(player, 1, GIFT_EVENT);

	return 1;
}

/*Mission*/
void give_mission(object npc, object player) {
	string result = "";

	if (player->get_save_2("halloween.status") == 1) {
		result = "Hình như ngươi đã nhận nhiệm vụ rồi. Hãy hoàn thành rồi quay lại đây nhận thưởng nha!\n";
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + result + ESC"Rời khỏi\n");
		return;
	}

	send_user(player, "%c%c%c%w%s", 0x51, 2, 1, TID_EVENTS, "Nhiệm Vụ Sự Kiện");
	send_user(player, "%c%c%c%w%w%s", 0x51, 2, 2, TID_EVENTS, 1, "Thu thập hồn ma yêu tinh");
	
	result = "Hãy mau mau tiêu diệt 100 quái vật để thu thập linh hồn và mang về đây giúp ta nhé!\n";
	player->set_save_2("halloween.task", 0);
	player->set_save_2("halloween.status", 1);
	send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + result + ESC"Rời khỏi\n");
}
void before_give_mission(object npc, object player) {
	string result = "";
	
	if (player->get_level() < 20) {
		result = sprintf("Ngươi đạt cấp 20 trở lên rồi hãy quay lại đây nha!\n", getoid(npc));
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + result + ESC"Rời khỏi\n");
		return;
	}

	if (player->get_save_2("halloween.status") != 0) {
		result = sprintf("Ngươi đã xong nhiệm vụ chưa!\n\n" ESC"Hoàn thành nhiệm vụ\ntalk %x# welcome.111\n", getoid(npc));
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + result + ESC"Rời khỏi\n");
		return;
	}

	result = "Nhiệm vụ yêu cầu tiêu diệt 100 quái vật để thu thập linh hồn của bọn chúng. Sau khi thu thập đủ, quay lại đây để nhận thưởng\n";
	send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + result + sprintf(ESC"Tiếp nhận nhiệm vụ\ntalk %x# welcome.100\n", getoid(npc)) + ESC"Rời khỏi\n");
}
void finished_mission(object npc, object player) {
	string result = "";
	
	if (player->get_save_2("halloween.status") == 1) {
		result = "Hãy mau mau hoàn thành nhiệm vụ và quay trở lại nhận thưởng nha!\n\n";
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + result + ESC"Rời khỏi\n");
		return;
	}

	if (player->get_save_2("halloween.status") != 2) {
		result = sprintf("Hình như ngươi chưa hoàn thành nhiệm vụ này...\n", getoid(npc));
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + result + ESC"Rời khỏi\n");
		return;
	}

	send_user(player, "%c%c%c%w%w%s", 0x51, 2, 2, TID_EVENTS, 1, "");
	send_user(player, "%c%c%c%w%s", 0x51, 2, 1, TID_EVENTS, "");

	give_gift_100(player, npc);
}


void drop_items(object me, object who)
{
	object item, leader;
	string file, owner, id;
	int p, i, size, gold;
	int z, x, y;

	z = get_z(me);  x = get_x(me);  y = get_y(me);
	id = who->get_leader();
	if (!id) owner = who->get_id();
	else
	{
		if (leader = find_player(id))
		{
			owner = leader->get_id();
		}
		else
			owner = who->get_id();
	}

	i = random(100);

	if( i < 30 )    // Thẻ Biến Thân
	{
		if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
		{
			item = new ("/item/54/9001");
			TEAM_D->drop_item(item,who);
			item->set_user_id(owner);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set( "time", time() );
		}
	} 

	if (i < 30)
	{
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = new("/item/std/0001");
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->set_value(random(50000) + 50000);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
		}
	}
	
	if (i > 30 &&  i < 50)
	{
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = new(GIFT_EVENT);
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->set_value(random(100000) + 100000);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
		}
	}

	size = random(3) + 1;

	for (i = 0; i < size; i++) {
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = new("/item/event/halloween/buahangma");
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
		}
	}

}
void win_bonus_callout(object me, object who)
{
	object owner, * team;
	int exp, exp2;
	int i, size;
	string leader;

	if (!objectp(who = me->get_enemy_4())) return;
	if (owner = who->get_owner()) who = owner;
	if (who->is_npc()) return;

	CHAT_D->sys_channel(0, HIY"Nghe nói Yêu Tinh Bí Ngô đã bị " + who->get_name() + " tiêu diệt");

	drop_items(me, who);

	if ((leader = who->get_leader()) && arrayp(team = who->get_team()) && sizeof(team) > 1)
	{
		team = me->correct_bonus_team(team);
		size = sizeof(team);
	}
	else    size = 1;

	exp = 300;

	if (size > 1) 
	{
		for (i = 0; i < size; i++) if (team[i])
		{
			exp2 = exp * (10 + size - 1) / 10;
			team[i]->add_exp(exp2);
		}
	}
	else  
	{
		who->add_exp(exp);
	}

}

/*PHO BAN*/

void timeout(object who, object map) {

	if (!who) {
		return;
	}

	who->set_login_flag(2);
	set_invisible(who, 1);
	set_effect(who, EFFECT_USER_LOGIN, 4);
	who->add_to_scene(080, 293, 184);

	if (!map)
		return;

	COPY_MAP->destruct_virtual_map(map, map->get_id());

	return;
}

void create_copy_npc(int next, int sec, int z, object who, int number)
{
	int p, x, y, i, map_level, rate, type, old_level, size;
	object npc, map, * member;
	p = MAP_ID;

	if (!who && !get_z(who)) {
		return;
	}

	sec--;
	if (sec > 0) {
		if (next < 4) {
			call_out("create_copy_npc", 1, next, sec, z, who, 10);
			tell_user(who, sprintf(ECHO"Đợt %d xuất hiện sau %d giây...", next, sec));
		}
		else if(next > 3){
			call_out("create_copy_npc", 1, next, sec, z, who, 15);
			tell_user(who, sprintf(ECHO"Đợt %d xuất hiện sau %d giây...", next, sec));
		}
	}
	else {
		map = get_map_object(get_z(who));

		if (!map || !map->is_virtual_scene())
			return 0;

		for (i = 0; i < number; i++)
		{
			npc = new("npc/event/halloween/cuongthi");

			if (!(p = efun::get_xy_point(MAP_ID, IS_CHAR_BLOCK)))
				continue;

			x = (p % 1000000) / 1000;  y = p % 1000;
			npc->add_to_scene(z, x, y);

			map->add("copy_npc_amount", 1);
		}

		next++;
		if (next < 4) {
			call_out("create_copy_npc", 1, next, 15, z, who, 10);
		}
		else if (next > 3 && next < 6) {
			call_out("create_copy_npc", 1, next, 15, z, who, 15);
			call_out("timeout", 60, who, map);
		} else {
			notify(HIY"Rời phó bản sau 30 giây nữa...");
			tell_user(who, sprintf(HIR"Rời phó bản sau 1 phút nữa..."));
		}
		
	}
	
}

int new_copy_scene(object who, object me)
{
	int z, d, tid, i, size, iTime;
	object map, npc, * team;
	mixed* mixTime;

	iTime = time();
	mixTime = localtime(iTime);
	mixTime[TIME_WDAY];

	d = MAP_ID;
	tid = who->get_team_id();
	if (!tid)return 0;
	team = who->get_team();
	size = sizeof(team);
	z = COPY_CTROL->new_scene(d, FILE_MAP, "Phục Ma Trận");
	if (!z) return 0;
	if (!objectp(map = get_map_object(z)) || !map->is_virtual_scene())
		return 0;

	TEAM_D->add_copy_scene(tid, COPY_GUMU, map);

	map->set("copy_id", 1);
	map->set("gumu_map", 1);
	Map += ({ map });

	for (i = 0; i < size; i++)
	{
		team[i]->set("team_id", tid);
		team[i]->set_save("maphalloween.timeout", time() + 60*3);
		map->set_owner(team[i]);
		team[i]->set_save_2("maphalloween.today", (mixTime[TIME_WDAY] + 1));
	}

	return z;
}

int new_copy(object who, object me)
{
	int i, tid, size, z, iTime;
	int level = 0;
	object* team, map;
	mixed* mixTime;

	iTime = time();
	mixTime = localtime(iTime);
	mixTime[TIME_WDAY];

	tid = who->get_team_id();
	if (!tid) return 0;
	if (!team = who->get_team()) return 0;

	if (who->get_save_2("maphalloween.today") == (mixTime[TIME_WDAY] + 1)) {
		if (who->get_save_2("maphalloween.go") < 1) {
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Hôm nay bạn sử dụng hết lượt tham gia Phó Bản rồi\n"
				ESC"Thoát", me->get_name()));
			return;
		}
	}

	z = new_copy_scene(who, me);
	if (!z) return 0;
	if (!objectp(map = get_map_object(z)) || !map->is_virtual_scene())
		return 0;

	map->set("copy_npc_amount", 0);
	map->set("max_copy_npc_amount", 100);
	create_copy_npc(1, 5,z, who, 20);

	return 1;
}


void enter_phoban(object me, object who) {
	int i, flag, size, x, y, z, p, tid, map_grade, iTime, member;
	int level = 0;
	string result;
	object map, * team, old_map, item;
	mixed* mixTime;

	iTime = time();
	mixTime = localtime(iTime);
	mixTime[TIME_WDAY];

	team = who->get_team();
	size = sizeof(team);

	if (!who->is_leader())
	{
		result = sprintf(me->get_name() + ":\n    Hãy gọi đội trưởng tới gặp ta !\n");
		result += sprintf(ESC"Rời khỏi");
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
		return;
	}


	if (size > 1)
	{
		result = sprintf(me->get_name() + ":\n    Phó bản này chỉ cho phép đi đơn lẻ !\n");
		result += sprintf(ESC"Rời khỏi");
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
		return;
	}

	if (!new_copy(who, me) == 1) return;
	tid = who->get("team_id");
	map = TEAM_D->get_copy_scene(tid, COPY_GUMU);
	if (map)
	{
		z = map->get_id();
		x = 39; y = 30;
		if (!p = get_valid_xy(z, x, y, IS_CHAR_BLOCK)) return;
		x = (p % 1000000) / 1000;  y = p % 1000;
		
		/*if (who->get_save_2("maphalloween.today") == (mixTime[TIME_WDAY] + 1)) {
			if (who->get_save_2("maphalloween.go") < 1) {
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Hôm nay bạn sử dụng hết lượt tham gia Phó Bản rồi\n"
					ESC"Thoát", me->get_name()));
				return;
			}
		}*/

		who->set_save_2("maphalloween.today", (mixTime[TIME_WDAY] + 1));
		who->add_save_2("maphalloween.go", -1);

		who->set("me_die", 1);
		send_user(who, "%c%c%w%s", 0x5a, 0, 1, "Đang di chuyển……");
		who->set_2("travel.z", z);
		who->set_2("travel.p", p);
		who->set("map", map);

		set_effect(team[i], EFFECT_TRAVEL, 1);

	}
}