/*****************************
	**TET NGUYEN DAN**
*****************************/

#include <time.h>
#include <ansi.h>
#include <cmd.h>
#include <music.h>
#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

#define BOSS "npc/boss/BossTet"

int* change54 = ({ 0010,0011,0050,0051,0052,0053,0100,0101,0102,0150,0151,0152,0200,0201,0202,0250,0251,0252,0300,0301,0302,0303,0304,0350,0351,0352,0400,0401,0402,0450,0500,0502,0550,0551,0552,8010,8011, });
int* nScene = ({ 1,10,20,30,40,50,60,70,80 });


int* nSceneBoss = ({ 10,20,30,40,50,60,70, });
string* cityname = ({ "Tề Quốc", "Hàn Quốc", "Triệu Quốc", "Ngụy Quốc", "Tần Quốc", "Sở Quốc", "Yên Quốc", });

int iStart, iStart2, iFinish, iFinish2, close_val, open_val;

mapping mpFuww = ([
	/*1:({ ({179,154,3}),({146,102,3}),({146,153,3}),({100,123,3}), }),
		10 : ({ ({130,114,8}),({114,129,8}),({ 64,168,8}), }),
		20 : ({ ({151,109,4}),({239, 67,3}),({175, 93,3}), }),
		30 : ({ ({174, 96,3}),({223, 61,3}),({249,111,2}), }),
		40 : ({ ({265,118,4}),({282,132,3}),({319,125,8}), }),
		50 : ({ ({133,119,2}),({118,134,3}),({ 51,138,2}), }),
		60 : ({ ({202,269,2}),({146,209,3}),({133,189,4}), }),
		70 : ({ ({149,189,6}),({255,192,2}),({171,213,2}),({194,265,2}), }),*/

		80 : ({ ({318,135,4}), }),

		/*80 : ({ ({328,124,3}),({318,135,4}),({338,153,3}),({290,149,3}),({283,179,3}),({338,215,3}),({159, 75,8}),({214,118,4}), }),
		54 : ({ ({132,116,2}),({106,133,4}), }),
		165 : ({ ({106,32,3}), }),
		269 : ({ ({258,177,4}),({267,187,4}), }),
		273 : ({ ({208,162,4}), }),
		289 : ({ ({107, 75,3}), }),
		324 : ({ ({ 81,122,2}), }),*/
]);

mapping mpFuhh = ([
	/*1:({ ({178,154,3}),({145,102,3}),({145,153,3}),({94,123,3}), }),
		10 : ({ ({134,117,4}),({121,134,4}),({ 69,172,4}), }),
		20 : ({ ({145,105,8}),({236, 65,3}),({228, 94,2}), }),
		30 : ({ ({229, 97,3}),({224, 62,3}),({254,107,6}), }),
		40 : ({ ({270,115,4}),({290,174,4}),({316,127,8}), }),
		50 : ({ ({128,115,2}),({121,171,4}),({ 57,142,2}), }),
		60 : ({ ({196,264,2}),({232,186,4}),({137,185,4}), }),
		70 : ({ ({145,192,2}),({251,189,2}),({227,220,4}),({197,267,2}), }),*/

		80 : ({ ({314,138,4}), }),

		/*80 : ({ ({327,124,3}),({314,138,4}),({339,153,3}),({291,149,3}),({260,149,3}),({288,175,3}),({333,219,3}),({187, 66,4}),({209,122,4}), }),
		54 : ({ ({135,119,2}),({114,139,8}), }),
		165 : ({ ({105,32,3}), }),
		269 : ({ ({261,175,4}),({271,184,4}), }),
		273 : ({ ({185,148,3}),({312,159,4}), }),
		289 : ({ ({ 77, 73,3}),({ 47, 57,7}), }),
		324 : ({ ({111,107,3}),({ 86,125,2}), }),*/
]);

object* NianShou, * BaoZhu, * FuWawa;
mapping mpNianshou;

void generate_phaohoa();
void destroy_phaohoa();
void generate_nienthu();
void destroy_nienthu();
void generate_npc_trangtri();
void destroy_npc_trangtri();
void check_time();
void call_boss();
void send_gift_to_user(object npc, object player);


void SAVE_BINARY() { }

void create()
{

	int year = 0;
	mixed* mixTime;
	mixTime = localtime(time());
	year = mixTime[TIME_YEAR];

	iStart = mktime(2021, 2, 7, 0, 0, 0);
	iFinish = mktime(2021, 2, 21, 23, 59, 59);

	iStart2 = mktime(2021, 2, 12, 0, 0, 0);
	iFinish2 = mktime(2021, 2, 14, 23, 0, 0);


	NianShou = ({});
	BaoZhu = ({});
	mpNianshou = ([]);
	FuWawa = ({});

	if (time() > iStart) {
		destroy_npc_trangtri();
		generate_npc_trangtri();
	}
	else {
		destroy_npc_trangtri();
	}

	call_out("check_time", 3);
}

int set_newyear(int open, int close)
{
	open_val = open;
	close_val = close;
	check_time();
	return 1;
}

void check_time()
{
	int iHour, p, iTime, i;
	string str;
	mixed* mixTime;
	remove_call_out("check_time");

	iTime = time();
	mixTime = localtime(time());

	if (iTime > iFinish)
	{
		destroy_phaohoa();
		destroy_nienthu();
		return;
	}

	if (iTime < iStart)
	{
		destroy_phaohoa();
		destroy_nienthu();
		call_out("check_time", iStart - iTime);
		return;
	}

	
	i = 60 * (60 - mixTime[TIME_MIN]);

	iHour = mixTime[TIME_HOUR];

	if (iTime > iStart2 && iTime < iFinish2) {
		if (iHour > 5 && iHour % 1 == 0) {
			str = sprintf("Chúc mọi người Năm Mới Vui Vẻ - HAPPY NEW YEAR 2021");
			send_user(CHAT_D->get_chat(), "%c%s", 0xA3, HIY + str);
			str = sprintf("Sự kiện mừng năm mới, đón Tết Nguyên Đán kéo dài đến hết ngày 21-02-2021. Theo dõi thông tin tại Fanpage "HIR"https://facebook.com/ChienQuoc.NguHoTuong"HIY"");
			send_user(CHAT_D->get_chat(), "%c%s", 0xA3, HIY + str);
		}
	}


	if (mixTime[TIME_HOUR] <= 5) {
		call_out("check_time", i);
	}
	else {

		if (mixTime[TIME_MIN] >= 30)
		{
			call_out("check_time", i);
		}
		else {

			if (mixTime[TIME_HOUR] == 20) {
				call_boss();
			}

			if (mixTime[TIME_HOUR] % 2 == 0)
			{
				generate_nienthu();
			}
			else {
				generate_phaohoa();
			}

			call_out("check_time", i + 3600);
		}
		
	}

}

void generate_npc_trangtri()
{
	int i, size, z, p, x, y, j, count, * nZ, * nXy;
	object* nObj, fw;
	mixed* nPoint;
	nObj = ({});

	nZ = keys(mpFuww);
	for (j = 0, count = sizeof(nZ); j < count; j++)
	{
		z = nZ[j];
		nPoint = mpFuww[z];
		for (i = 0, size = sizeof(nPoint); i < size; i++)
		{
			fw = new("npc/party/fuww");
			if (!objectp(fw))
				continue;
			nXy = nPoint[i];
			fw->add_to_scene(z, nXy[0], nXy[1], nXy[2]);
			FuWawa += ({ fw });
		}
	}

	nZ = keys(mpFuhh);
	for (j = 0, count = sizeof(nZ); j < count; j++)
	{
		z = nZ[j];
		nPoint = mpFuhh[z];
		for (i = 0, size = sizeof(nPoint); i < size; i++)
		{
			fw = new("npc/party/fuhh");
			if (!objectp(fw))
				continue;
			nXy = nPoint[i];
			fw->add_to_scene(z, nXy[0], nXy[1], nXy[2]);
			FuWawa += ({ fw });
		}
	}

}

void destroy_npc_trangtri()
{
	int i, size;
	int z, x, y, j, count, * nZ, * nXy;
	mixed* nPoint;
	object * item;


	for (i = 0, size = sizeof(FuWawa); i < size; i++)
	{
		if (!objectp(FuWawa[i]))
			continue;
		FuWawa[i]->remove_from_scene();
		destruct(FuWawa[i]);
	}

	nZ = keys(mpFuww);
	for (j = 0, count = sizeof(nZ); j < count; j++)
	{
		z = nZ[j];
		nPoint = mpFuww[z];

		for (i = 0, size = sizeof(nPoint); i < size; i++)
		{
			nXy = nPoint[i];
			x = nXy[0];
			y = nXy[1];

			if (have_scene_object(z, x, y, CHAR_TYPE, 1))
			{
				item = get_scene_object(z, x, y, CHAR_TYPE, 1);
				if (item[0]) {
					item[0]->remove_from_scene();
					destruct(item[0]);
				}
			}
		}
	}

	nZ = keys(mpFuhh);
	for (j = 0, count = sizeof(nZ); j < count; j++)
	{
		z = nZ[j];
		nPoint = mpFuhh[z];

		for (i = 0, size = sizeof(nPoint); i < size; i++)
		{
			nXy = nPoint[i];
			x = nXy[0];
			y = nXy[1];

			if (have_scene_object(z, x, y, CHAR_TYPE, 1))
			{
				item = get_scene_object(z, x, y, CHAR_TYPE, 1);
				if (item[0]) {
					item[0]->remove_from_scene();
					destruct(item[0]);
				}
			}
		}
	}


}

//Phao hoa
void generate_phaohoa()
{
	int i, size, z, p, x, y, j, count;
	object item;

	destroy_phaohoa();
	for (j = 0, count = sizeof(nScene); j < count; j++)
	{
		z = nScene[j];
		for (i = 0; i < 100; i++)
		{
			if (!(p = efun::get_xy_point(z, IS_CHAR_BLOCK)))
				continue;
			x = (p % 1000000) / 1000;  y = p % 1000;
			//item = new("/item/04/baozhu");
			item = new("/item/event/tet/phaonho");
			item->set_amount(2);
			if (!objectp(item))
				continue;
			item->add_to_scene(z, x, y);
			BaoZhu += ({ item });
		}
	}

}

void destroy_phaohoa()
{
	int i, size;

	for (i = 0, size = sizeof(BaoZhu); i < size; i++)
	{
		if (!objectp(BaoZhu[i]))
			continue;
		BaoZhu[i]->remove_from_scene();
		destruct(BaoZhu[i]);
	}
}

void generate_nienthu()
{
	int i, size, z, p, x, y, j, count, amount;
	object* nObj, npc;

	int iTime;
	mixed* mixTime;

	iTime = get_party_time();
	mixTime = localtime(iTime);

	nObj = ({});
	destroy_nienthu();

	for (j = 0, count = sizeof(nScene); j < count; j++)
	{
		for (i = 0; i < 20; i++)
		{
			if (!(p = efun::get_xy_point(z, IS_CHAR_BLOCK)))
				continue;
			x = (p % 1000000) / 1000;  y = p % 1000;
			npc = new("/npc/party/nianshou");
			if (!objectp(npc))
				continue;
			npc->add_to_scene(z, x, y);
			nObj += ({ npc });
		}
	}

	log_file("NienThu.txt", sprintf("%d tháng %d ngày %d :%d Nien thu\n", mixTime[TIME_MON] + 1, mixTime[TIME_MDAY], mixTime[TIME_HOUR], mixTime[TIME_MIN]));

	CHAT_D->sys_channel(0, HIR "<!!!> Ngoài thành của các quốc gia lại xuất hiện 1 đám Niên Thú, Các vị anh hùng hãy nhanh nhanh lấy Pháo đuổi chúng đi !");
	CHAT_D->sys_channel(0, HIR "<!!!> Ngoài thành của các quốc gia lại xuất hiện 1 đám Niên Thú, Các vị anh hùng hãy nhanh nhanh lấy Pháo đuổi chúng đi !");
	CHAT_D->sys_channel(0, HIR "<!!!> Ngoài thành của các quốc gia lại xuất hiện 1 đám Niên Thú, Các vị anh hùng hãy nhanh nhanh lấy Pháo đuổi chúng đi !");
}

void destroy_nienthu()
{
	int i, size;
	for (i = 0, size = sizeof(NianShou); i < size; i++)
	{
		if (!objectp(NianShou[i]))
			continue;
		NianShou[i]->remove_from_scene();
		destruct(NianShou[i]);
	}
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

	if (i < 10)    // Thẻ Biến Thân
	{
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = new (sprintf("/item/54/%04d", change54[random(sizeof(change54))]));
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
		}
	}
	else if (i < 18)
	{
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = new("/item/std/0001");
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->set_value(50000);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
			gold++;
		}
	}
	
	if (i < 25)
	{
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = new("/item/test2/TanNienLeBao");
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
		}
	}

	if (i > 40 && i < 50)
	{
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = new("/item/event/tet/phaohoa");
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
		}
	}

	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		item = new("/item/04/0435");
		TEAM_D->drop_item(item, who);
		item->set_user_id(owner);
		item->add_to_scene(z, p / 1000, p % 1000);
		item->set("winner", who);
		item->set("time", time());
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

	CHAT_D->sys_channel(0, HIY"Nghe nói Niên Thú đã bị " + who->get_name() + " tiêu diệt.");

	drop_items(me, who);

	if ((leader = who->get_leader()) && arrayp(team = who->get_team()) && sizeof(team) > 1)
	{
		team = me->correct_bonus_team(team);
		size = sizeof(team);
	}
	else    size = 1;

	exp = 500;

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

void drop_items_training (object me, object who)
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

	if (i < 10)
	{
		
	}
	else if (i < 18)
	{
		
	}
	else if (i < 25)
	{
		
	}

	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		item = new(file);
		TEAM_D->drop_item(item, who);
		item->set_user_id(owner);
		item->add_to_scene(z, p / 1000, p % 1000);
		item->set("winner", who);
		item->set("time", time());
	}

}

void call_boss() {
	int i, size, z, p, x, y, j, count;
	object* nObj, npc;

	j = random(sizeof(nSceneBoss));
	z = nSceneBoss[j];

	if (!(p = efun::get_xy_point(z, IS_CHAR_BLOCK)))
		return;

	x = (p % 1000000) / 1000;
	y = p % 1000;

	npc = new(BOSS);
	if (!objectp(npc))
		return;
	npc->add_to_scene(z, x, y);
	

	CHAT_D->sys_channel(0, HIR "<!> Ngưu Tinh "HIY" nghe nói lại xuất hiện ở "HIC"" + cityname[j] + " (" + x + "," + y + ") " + ""HIY" các anh hùng mau mau tiêu diệt để mùa Noel được an lành...");
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

		send_user(player, "%c%s", ';', "Chúc mừng bạn nhận được "+ HIR""+ name_s);
		send_user(player, "%c%w", 0x0d, MUSIC_TASK);
	}
}

void send_gift_of_task(object npc, object me) {

	if (sizeof_inventory(me, 3, MAX_CARRY) >= MAX_CARRY)
	{
		send_user(me, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n	Rất xin lỗi, muốn nhận được phần thưởng , vui lòng để trống hành trang. Nếu như kinh nghiệm cùng tiềm năng đạt tới giới hạn, cũng không thể nhận được." + ESC"Xác nhận\n");
		return;
	}

	if (me->get_save_2("task.TetStatus") == 2) {
		give_to_user(me, 1, "/item/event/tet/baolixi");
		give_to_user(me, 1, "/item/04/baozhu");

		me->delete_save_2("task.TetStatus");
		me->delete_save_2("task.TetPoint");

		send_user(me, "%c%w", 0x0d, MUSIC_TASK);

		return;
	}

}

void send_quest_to_user(object npc, object me) {

	tell_user(me, "%d", me->get_save_2("task.TetStatus"));
	if (me->get_save_2("task.TetStatus") == 0) {
		send_user(me, "%c%c%w%s", ':', 3, 6008,
			sprintf(" %s :\n Ngoài kia hàng loạt lũ yêu tinh đang quấy rối. Ngươi hãy giúp ta tiêu diệt "HIR"50 con yêu tinh"NOR", để giúp mọi người có một mùa Tết yên bình. Sau khi hoàn thành nhiệm vụ hãy quay lại đây nhận thưởng  !\n"
				ESC HIY"Nhận nhiệm vụ\ntalk %x# welcome.2122\n"
				ESC "Ta hiểu rồi\nCLOSE\n", npc->get_name(), getoid(npc)));

		return;
	}

	if (me->get_save_2("task.TetStatus") == 1) {
		send_user(me, "%c%c%w%s", ':', 3, 6008,
			sprintf(" %s :\n Hãy mau mau hoàn thành nhiệm vụ và quay lại đây nhận thưởng !\n"
				ESC "Ta hiểu rồi\nCLOSE\n", npc->get_name()));

		return;
	}

	if (me->get_save_2("task.TetStatus") == 2) {
		send_user(me, "%c%c%w%s", ':', 3, 6008,
			sprintf(" %s :\n Ngươi làm tốt lắm, ta có phần thưởng cho ngươi...!\n"
				ESC HIY"Hoàn thành nhiệm vụ\ntalk %x# welcome.2221\n"
				ESC "Ta hiểu rồi\nCLOSE\n", npc->get_name(), getoid(npc)));

		return;
	}
	
}

void send_gift_to_user(object npc, object player) {

	int day, p, iTime;
	string str;
	mixed* mixTime;
	remove_call_out("check_time");
	iTime = time();

	mixTime = localtime(time());
	day = mixTime[TIME_MDAY];

	if (sizeof_inventory(player, 3, MAX_CARRY) >= MAX_CARRY)
	{
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n	Rất xin lỗi, muốn nhận được phần thưởng , vui lòng để trống hành trang. Nếu như kinh nghiệm cùng tiềm năng đạt tới giới hạn, cũng không thể nhận được." + ESC"Xác nhận\n");
		return;
	}

	switch (day)
	{
	case 12:
		if (player->get_save_2("tet.qua") == 12) {
			send_user(player, "%c%c%w%s", ':', 3, 6008,
				sprintf(" %s :\n Bạn đã nhận quà hôm nay rồi!\n"
					ESC "Huỷ bỏ\nCLOSE\n", npc->get_name()));

			return;
		}

		give_to_user(player, 1, "/item/event/tet/phaohoa");
		give_to_user(player, 1, "/item/event/tet/baolixi");
		give_to_user(player, 5, "/item/event/tet/phao");
		player->set_save_2("tet.qua", 12);

		send_user(player, "%c%c%w%s", ':', 3, 6008,
			sprintf(" %s :\n Ta đã gửi phần quà cho ngươi rồi. Chúc mừng năm mới!\n"
				ESC "Huỷ bỏ\nCLOSE\n", npc->get_name()));

		break;
	case 13:
		if (player->get_save_2("tet.qua") == 13) {

			send_user(player, "%c%c%w%s", ':', 3, 6008,
				sprintf(" %s :\n Bạn đã nhận quà hôm nay rồi!\n"
					ESC "Huỷ bỏ\nCLOSE\n", npc->get_name()));
			return;
		}
		give_to_user(player, 5, "/item/event/tet/phao");
		give_to_user(player, 1, "/item/event/tet/phaohoa");
		player->set_save_2("tet.qua", 13);
		send_user(player, "%c%c%w%s", ':', 3, 6008,
			sprintf(" %s :\n Ta đã gửi phần quà cho ngươi rồi. Chúc mừng năm mới!\n"
				ESC "Huỷ bỏ\nCLOSE\n", npc->get_name()));
		break;
	case 14:
		if (player->get_save_2("tet.qua") == 14) {
			send_user(player, "%c%c%w%s", ':', 3, 6008,
				sprintf(" %s :\n Bạn đã nhận quà hôm nay rồi!\n"
					ESC "Huỷ bỏ\nCLOSE\n", npc->get_name()));
			return;
		}

		give_to_user(player, 5, "/item/event/tet/phao");
		give_to_user(player, 1, "/item/event/tet/phaohoa");
		player->set_save_2("tet.qua", 14);
		send_user(player, "%c%c%w%s", ':', 3, 6008,
			sprintf(" %s :\n Ta đã gửi phần quà cho ngươi rồi. Chúc mừng năm mới!\n"
				ESC "Huỷ bỏ\nCLOSE\n", npc->get_name()));
		break;
	}
	
}


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


void send_gift_nienthu(object npc, object player) {
	if (give_event_item(player, "Sừng Niên Thú", 1) == 0)
	{
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s:\n   Xin lỗi, bạn không có đủ "HIR"1 Sừng Niên Thú\n"ESC"Xác nhận", npc->get_name()));
		return;
	}

	give_to_user(player, 1, "/item/event/tet/quatet");
}