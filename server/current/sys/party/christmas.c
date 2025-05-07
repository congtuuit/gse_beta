/*****************************
	**giáng sinh**
*****************************/

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <public.h>
#include <time.h>
#include <action.h>
#include <skill.h>
#include <effect.h>
#include <task.h>
#include <cmd.h>
#include <music.h>

inherit DBASE_F;
inherit SAVE_F;

#define SANTACLAUS	"npc/party/santaclaus"
#define TURKEY		"item/04/0413"
#define SANTANBADMAN		"npc/party/0012"
#define BOSS		"npc/party/bossnoel"

//Tui qua Top
#define ITEM_TOP_1 "item/event/giangsinh/top1"
#define ITEM_TOP_2 "item/event/giangsinh/top2"
#define ITEM_TOP_3 "item/event/giangsinh/top3"
#define ITEM_TOP_10 "item/event/giangsinh/top10"

void SAVE_BINARY() { }
string get_save_file() { return "data/Christmas"SAVE_EXTENSION; }

int* nScene = ({ 1,10,20,30,40,50,60,70,});
int* nSceneBoss = ({ 10,20,30,40,50,60,70,});
string* cityname = ({ "Tề Quốc", "Hàn Quốc", "Triệu Quốc", "Ngụy Quốc", "Tần Quốc", "Sở Quốc", "Yên Quốc", });

int iStart, iFinish, iFinish2;
object SantaClaus, SantaBear, SantaGuan, SantaFeizei;
mapping mpTree1 = ([
	1:({ ({53,144}), ({149,138}),}),
		80 : ({ ({292,183}), }),
		//886:({  ({93,127}),  }),
]);
mapping mpTree2 = ([
	1:({ ({193,148}),({146,153}),({182,153}),({160,148}), }),
		10 : ({ ({130,113}), ({135,117}) , ({139,198}),({143,195}) }),
		20 : ({ ({228,84}),({167,87}),({172,93}),({230,93}), }),
		30 : ({ ({191,80}),({173,94}),({229,96}),({202,78}), }),
		40 : ({ ({270,113}),({265,117}),({258,191}),({264,196}), }),
		50 : ({ ({128,114}),({134,118}),({118,172}), }),
		60 : ({ ({242,169}),({247,173}),({138,184}),({133,188}), }),
		70 : ({ ({181,219}),({251,187}),({217,245}),({232,217}), }),
		80 : ({ ({220,49}),({189,70}),({161,75}),({214,117}),({209,121}),({324,132}),({311,140}), }),
		289 : ({ ({49,59}), ({66,62}) }),
		165 : ({ ({90,30}), ({110,30}) }),
		269 : ({ ({253,166}), ({265,188}) }),
		273 : ({ ({185,140}),({197,155}),({216,170}), }),
		54 : ({ ({140,115}),({127,126}),({114,138}), }),
		324 : ({ ({99,115}), ({119,156}) }),
		886 : ({ ({112,92}), ({136,110}) }),
]);

int SantaClausGift(object me, object who, int type);
int check_turkey(object who, int count);
int give_turkey(object who, int count);
void generate_turkey();
void generate_badman();
void destroy_badman();
void generate_tree();

void update_record(object player);
void paihangbang(object player, object npc);
void paihangbang_bonus(int top, object player, object npc);

void move_item_to_user(object who, int amount_s, string name);
void call_boss();

void destroy_tree();

void create()
{
	//	iStart = mktime(2006,12,23,10,0,0);	
	//	iFinish = mktime(2006,12,28,0,0,0);	
	//	call_out("check_time",3);
	//	generate_tree();
	//> 8h start

	int year = 0;
	mixed* mixTime;
	mixTime = localtime(time());
	year = mixTime[TIME_YEAR];

	iStart = mktime(year, 12, 12, 9, 0, 0);
	iFinish = mktime(year, 12, 30, 23, 0, 0);
	iFinish2 = mktime(year, 1, 3, 0, 0, 0);

	destroy_tree();
	generate_tree();

	call_out("check_time", 3);
}

void check_time()
{
	int iHour, p;
	mixed* mixTime;

	remove_call_out("check_time");
	iHour = time();

	destroy_badman();

	//test
	/*generate_turkey();
	generate_badman();
	call_boss();
	generate_tree();*/
	//end test

	if (iHour > iFinish) {
		destroy_tree();
		return;
	}

	if (iHour < iStart)
	{
		destroy_tree();
		call_out("check_time", iStart - iHour);
		return;
	}

	if (!objectp(SantaClaus))
	{
		SantaClaus = new(SANTACLAUS);
		SantaClaus->add_to_scene(80, 280, 176, 4);
	}
	if (!objectp(SantaBear))
	{
		SantaBear = new("npc/party/santabear");
		SantaBear->add_to_scene(80, 282, 178, 4);
	}
	if (!objectp(SantaGuan))
	{
		SantaGuan = new("npc/party/santaguan");
		SantaGuan->add_to_scene(80, 283, 177, 4);
	}
	if (!objectp(SantaFeizei))
	{
		SantaFeizei = new("npc/party/santafeizei");
		SantaFeizei->add_to_scene(80, 281, 179, 4);
	}

	mixTime = localtime(time());
	iHour = mixTime[TIME_HOUR];

	if (mixTime[TIME_MIN] > 40) {
		call_out("check_time", 60 * (60 - mixTime[TIME_MIN]));
		return;
	}
	else {
		call_out("check_time", 60 * (60 - mixTime[TIME_MIN]));
	}

	if (iHour == 9 || 
		iHour == 11 ||
		iHour == 13 ||
		iHour == 15 ||
		iHour == 17 ||
		iHour == 19 ||
		iHour == 21
		)
	{
		/*if (SANTACLAUS->get("turkey") != time() / 1800)
		{
			SANTACLAUS->set("turkey", time() / 1800);
			generate_turkey();
		}*/

		generate_turkey();
	}

	if (iHour == 20) {
		call_boss();
	}

	if (iHour == 10 ||
		iHour == 12 ||
		iHour == 14 ||
		iHour == 16 ||
		iHour == 18 ||
		iHour == 20 ||
		iHour == 22
		)
	{
		if (SANTACLAUS->get("banman") != iHour)
		{
			generate_badman();
			SANTACLAUS->set("banman", iHour);
		}
	}

	else if (iHour == 6 || iHour == 0)
	{
		destroy_badman();
	}

}

void before_destruct()
{
	int i, size;
	object* nObj;
	if (objectp(SantaClaus))
	{
		SantaClaus->remove_from_scene();
		destruct(SantaClaus);
	}
	if (objectp(SantaBear))
	{
		SantaBear->remove_from_scene();
		destruct(SantaBear);
	}
	if (objectp(SantaGuan))
	{
		SantaGuan->remove_from_scene();
		destruct(SantaGuan);
	}
	if (objectp(SantaFeizei))
	{
		SantaFeizei->remove_from_scene();
		destruct(SantaFeizei);
	}
	nObj = SANTACLAUS->get("tree");
	for (i = 0, size = sizeof(nObj); i < size; i++)
	{
		if (!objectp(nObj[i]))continue;
		nObj[i]->remove_from_scene();
		destruct(nObj[i]);
	}

}

void do_look(object me, object who)
{
	int id = getoid(me), i;
	i = time();
	if (i > iStart && i <= iFinish)
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n  Sự kiện Giáng Sinh hàng năm lại đến, tôi - ông già Noel đã chuẩn bị rất nhiều quà tặng cho các bạn.\nNếu bạn có Vớ hoặc Gà Tây có thể giao cho tôi để nhận phần quà Noel trong đêm Giáng Sinh ấm áp!\n"
			ESC HIY"Giao nộp vớ\ntalk %x# welcome.1\n"
			ESC HIY"Giao nộp gà tây\ntalk %x# welcome.2\n"
			ESC"Bảng xếp hạng Trang Trí Thông Noel\ntalk %x# welcome.5\n"
			ESC HIC"Dùng 75.000 lượng mua Linh Thủy\ntalk %x# welcome.7\n"
			ESC"Rời khỏi", me->get_name(), id, id, id, id));

	else if (i > iFinish && i <= iFinish2) {
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n  Sự kiện Giáng Sinh hàng năm lại đến, tôi - ông già Noel đã chuẩn bị rất nhiều quà tặng cho các bạn.\nNếu bạn có Vớ hoặc Gà Tây có thể giao cho tôi để nhận phần quà Noel trong đêm Giáng Sinh ấm áp!\n"
			ESC HIY"Giao nộp vớ\ntalk %x# welcome.1\n"
			ESC HIY"Giao nộp gà tây\ntalk %x# welcome.2\n"
			ESC"Nhận thưởng xếp hạng\ntalk %x# welcome.24122020\n"
			ESC"Rời khỏi", me->get_name(), id, id, id));
	}

}

void do_welcome(object me, string arg)
{
	int flag, i, rate, exp, money, pot, pos;
	int id = getoid(me);
	object who, item, player, gift;
	string name, cTmp, id1;
	mixed* mixTime;
	who = this_player();
	i = time();

	if (sscanf(arg, "%d.%s", flag, id1) != 2)
		flag = to_int(arg);
	who->set_time("talk", 0);

	if (i > iFinish2) {
		return;
	}

	switch (flag)
	{
	case 1:
		if (!objectp(item = present("Vớ dài", who, 1, MAX_CARRY)) || item->is_christmas() != 1)
		{
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n Vớ noel của bạn đâu, ta chưa thấy !\n"ESC"Rời khỏi", me->get_name()));
			return;
		}
		item->add_amount(-1);
		if (SantaClausGift(me, who, 1) != 1)
			item->add_amount(1);
		break;
	case 2:
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n Bạn có Gà tây Noel, có thể giao cho tôi để đổi phần quà giáng sinh !\n"ESC"Giao nộp 5 Gà tây Noel đổi quà\ntalk %x# welcome.3\n"ESC"Rời khỏi", me->get_name(), getoid(me)));
		break;
	case 3:
		if (check_turkey(who, 5) != 1)
		{
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n Bạn không có đủ 5 Gà tây Noel !\n"ESC"Rời khỏi", me->get_name()));
			return;
		}
		if (TASK_LEGEND_D->can_carry_amount(who, 1) != 1)
			return;
		give_turkey(who, 5);
		SantaClausGift(me, who, 2);
		break;
	case 5:
		update_record(who);
		paihangbang(who, me);
		break;
	case 24122020:
		if (is_god(who)) {
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n" + "    debug.\n" + ESC"Xác nhận\n");
			return;
		}

		if (i > iFinish && i < iFinish2)
		{
			if (get_save_2(sprintf("player.%d.bonus", who->get_number())))
			{
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n" + "    Bạn đã nhận giải thưởng rồi, không thể nhận tiếp.\n" + ESC"Xác nhận\n");
				return;
			}

			pos = get_save_2(sprintf("player.%d.pos", who->get_number()));

			if (pos < 1 || pos > 10)
			{
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n" + "    Xin lỗi tên của bạn không có trên bảng xếp hạng\n" + ESC"Xác nhận\n");
				return;
			}
			
			paihangbang_bonus(pos, who, me);

		}

		break;
	case 7:
		if (sizeof_inventory(who, 1, MAX_CARRY) >= MAX_CARRY)
		{
			send_user(who, "%c%s", '!', "Hành trang trên người ngươi không đủ 1 chỗ");
			return 0;
		}

		if (who->get_cash() < 75000) {
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n Ngân lượng không đủ!\n"ESC"Rời khỏi", me->get_name()));
		}
		else {
			who->add_cash(-75000);
			move_item_to_user(who, 1, "item/event/giangsinh/linhthuy");
		}
		break;
	}
}

int check_turkey(object who, int count)
{
	int i, size, amount;
	object* inv, item;
	string name = "Gà Tây Noel";
	inv = all_inventory(who, 1, MAX_CARRY);

	if (!objectp(item = present(name, who, 1, MAX_CARRY)) || item->is_christmas() != 1)
	{
		return 0;
	}
	for (i = 0, size = sizeof(inv); i < size; i++)
	{
		if (!objectp(inv[i]))
			continue;
		if (inv[i]->get_name() != name || inv[i]->is_christmas() != 1)
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

int give_turkey(object who, int count)
{
	int i, size, amount;
	object* inv, item;
	string name = "Gà Tây Noel";
	if (check_turkey(who, count) != 1)
		return 0;
	inv = all_inventory(who, 1, MAX_CARRY);
	for (i = 0, size = sizeof(inv); i < size; i++)
	{
		if (!objectp(inv[i]))
			continue;
		if (inv[i]->get_name() != name || inv[i]->is_christmas() != 1)
			continue;
		amount = inv[i]->get_amount();
		if (count >= amount)
		{
			inv[i]->remove_from_user();
			destruct(inv[i]);
			count -= amount;
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

int SantaClausGift(object me, object who, int type)
{
	int rate, p, exp, pot, money;
	object gift;
	string name;
	if (type == 1) {
		gift = new("item/event/giangsinh/gift");
	}
	else {
		gift = new("item/event/giangsinh/gift2");
	}
	
	if (gift)
	{
		p = gift->move(who, -1);
		if (!p)
		{
			destruct(gift);
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n Hành trang của bạn không đủ ô trống !\n"ESC"Rời khỏi", me->get_name()));
			return 0;
		}
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n Bạn đã nhận được phần quà "HIR "%s"NOR ", chúc bạn giáng sinh ấm áp\n"ESC"Rời khỏi", me->get_name(), gift->get_name()));
		gift->add_to_user(p);
		if (name)
			CHAT_D->sys_channel(0, sprintf(HIR "Xin chúc mừng %s trong mùa Giáng Sinh đạt được %s !", who->get_name(), gift->get_name()));
	}
	return 1;
}

void destroy_turkey()
{
	int i, size;
	object* nObj;
	nObj = SANTACLAUS->get("item");
	for (i = 0, size = sizeof(nObj); i < size; i++)
	{
		if (!objectp(nObj[i]))
			continue;
		if (get_d(nObj[i]))
			continue;
		nObj[i]->remove_from_scene();
		destruct(nObj[i]);
	}
	SANTACLAUS->delete("item");
}

void destroy_tree()
{
	int i, size;
	object* nObj;
	nObj = SANTACLAUS->get("tree");
	for (i = 0, size = sizeof(nObj); i < size; i++)
	{
		if (!objectp(nObj[i]))
			continue;
		if (get_d(nObj[i]))
			continue;
		nObj[i]->remove_from_scene();
		destruct(nObj[i]);
	}
	SANTACLAUS->delete("tree");
}


void call_boss() {
	int i, size, z, p, x, y, j, count;
	object* nObj, npc;

	j = random(sizeof(nSceneBoss));
	z = nSceneBoss[j];

	if (!(p = efun::get_xy_point(z, IS_CHAR_BLOCK)))
		return;

	nObj = SANTACLAUS->get("npc");
	if (!arrayp(nObj))
		nObj = ({});

	x = (p % 1000000) / 1000;
	y = p % 1000;
	
	npc = new(BOSS);
	if (!objectp(npc))
		return;
	npc->add_to_scene(z, x, y);
	nObj += ({ npc });

	CHAT_D->sys_channel(0, HIR "Santa Claus Hiểm Họa "HIY" đã xuất hiện ở "HIC"" + cityname[j] + " (" + x +","+ y +") " +""HIY" các anh hùng mau mau tiêu diệt để mùa Noel được an lành...");
}

void generate_turkey()
{
	int i, size, z, p, x, y, j, count;
	object* nObj, item;

	destroy_turkey();
	nObj = ({});
	for (j = 0, count = sizeof(nScene); j < count; j++)
	{
		z = nScene[j];
		for (i = 0; i < 50; i++)
		{
			if (!(p = efun::get_xy_point(z, IS_CHAR_BLOCK)))
				continue;
			x = (p % 1000000) / 1000;  y = p % 1000;
			item = new(TURKEY);
			if (!objectp(item))
				continue;
			item->add_to_scene(z, x, y);
			nObj += ({ item });
		}
	}

	log_file("christmas.txt", short_time() + " hoạt động Noel bắt đầu\n");
	SANTACLAUS->set("item", nObj);
	CHAT_D->sys_channel(0, HIR "Gà tây Noel đã xuất hiện ở các nước và Tân Thủ Thôn, hãy nhanh chóng tìm nó để cùng ông già Noel có một giáng sinh ấm áp !.");
	CHAT_D->sys_channel(0, HIG "Gà tây Noel đã xuất hiện ở các nước và Tân Thủ Thôn, hãy nhanh chóng tìm nó để cùng ông già Noel có một giáng sinh ấm áp !.");
	CHAT_D->sys_channel(0, HIY "Gà tây Noel đã xuất hiện ở các nước và Tân Thủ Thôn, hãy nhanh chóng tìm nó để cùng ông già Noel có một giáng sinh ấm áp !.");
}

void generate_badman()
{
	int i, size, z, p, x, y;
	object* nObj, npc;

	nObj = ({});
	for (z = 10; z <= 70; z += 10)
	{
		for (i = 0; i < 15; i++)
		{
			if (!(p = efun::get_xy_point(z, IS_CHAR_BLOCK)))
				continue;
			x = (p % 1000000) / 1000;  y = p % 1000;
			npc = new(SANTANBADMAN);
			if (!objectp(npc))
				continue;
			switch (random(3))
			{
			default:
				npc->set_name("Gấu Ngốc Noel");
				npc->set_char_picid(1289);
				npc->set_max_hp(1);
				npc->set_ap(1);
				npc->set_dp(1);
				npc->set_cp(1);
				npc->set_pp(1);
				npc->set_sp(1);
				npc->set_walk_speed(4);
				npc->set_attack_speed(3);
				break;
			case 1:
				npc->set_name("Quán Yêu Noel");
				npc->set_char_picid(1291);
				npc->set_max_hp(1);
				npc->set_ap(1);
				npc->set_dp(1);
				npc->set_cp(1);
				npc->set_pp(1);
				npc->set_sp(1);
				npc->set_walk_speed(2);
				npc->set_attack_speed(3);
				break;
			case 2:
				npc->set_name("Phi Tặc Noel");
				npc->set_char_picid(1290);
				npc->set_max_hp(1);
				npc->set_ap(1);
				npc->set_dp(1);
				npc->set_cp(1);
				npc->set_pp(1);
				npc->set_sp(1);
				npc->set_walk_speed(2);
				npc->set_attack_speed(1);
				break;
			}
			npc->add_to_scene(z, x, y);
			nObj += ({ npc });
		}
	}
	log_file("christmas.txt", short_time() + " quái vật noel xuất hiện\n");
	SANTACLAUS->set("npc", nObj);
	CHAT_D->sys_channel(0, HIR "Một đám quái vật Noel đã cướp túi quà giáng sinh của ông già Noel, nghe nói chúng xuất hiện ở ngoài thành 7 nước !.");
}

void destroy_badman()
{
	int i, size, z, p, x, y;
	object* nObj, npc;

	nObj = SANTACLAUS->get("npc");
	for (i = 0, size = sizeof(nObj); i < size; i++)
	{
		if (!objectp(nObj[i]))
			continue;
		nObj[i]->remove_from_scene();
		destruct(nObj[i]);
	}
	SANTACLAUS->delete("npc");
}

void away_user(object me, object who)
{
	int x, y, z, x0, y0, z0, p, d;
	string cmd;

	z = get_z(who);  x = get_x(who);  y = get_y(who);
	z0 = get_z(me); x0 = get_x(me);  y0 = get_y(me);
	d = distance_between(me, who);

	if (x0 > x)
	{
		if (y0 > y)
		{
			if (p = get_valid_path(z, x0, y0, (x + (d + 1 + random(3))), y + (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, x, y + (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, (x + (d + 1 + random(3))), y));
			else if (p = get_valid_path(z, x0, y0, (x - (d + 1 + random(3))), y + (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, (x + (d + 1 + random(3))), y - (d + 1 + random(3))));
		}
		else if (y0 == y)
		{
			if (p = get_valid_path(z, x0, y0, (x + (d + 1 + random(3))), y));
			else if (p = get_valid_path(z, x0, y0, (x + (d + 1 + random(3))), y + (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, (x + (d + 1 + random(3))), y - (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, x, y + (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, x, y - (d + 1 + random(3))));
		}
		else
		{
			if (p = get_valid_path(z, x0, y0, (x + (d + 1 + random(3))), y - (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, (x + (d + 1 + random(3))), y));
			else if (p = get_valid_path(z, x0, y0, x, y - (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, (x + (d + 1 + random(3))), y + (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, (x - (d + 1 + random(3))), y - (d + 1 + random(3))));
		}
	}
	else if (x0 == x)
	{
		if (y0 > y)
		{
			if (p = get_valid_path(z, x0, y0, x, y + (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, (x - (d + 1 + random(3))), y + (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, (x + (d + 1 + random(3))), y + (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, (x - (d + 1 + random(3))), y));
			else if (p = get_valid_path(z, x0, y0, (x + (d + 1 + random(3))), y));
		}
		else if (y0 == y);
		else
		{
			if (p = get_valid_path(z, x0, y0, x, y - (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, (x + (d + 1 + random(3))), y - (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, (x - (d + 1 + random(3))), y - (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, (x + (d + 1 + random(3))), y));
			else if (p = get_valid_path(z, x0, y0, (x - (d + 1 + random(3))), y));
		}
	}
	else
	{
		if (y0 > y)
		{
			if (p = get_valid_path(z, x0, y0, (x - (d + 1 + random(3))), y + (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, (x - (d + 1 + random(3))), y));
			else if (p = get_valid_path(z, x0, y0, x, y + (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, (x - (d + 1 + random(3))), y - (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, (x + (d + 1 + random(3))), y + (d + 1 + random(3))));
		}
		else if (y0 == y)
		{
			if (p = get_valid_path(z, x0, y0, (x - (d + 1 + random(3))), y));
			else if (p = get_valid_path(z, x0, y0, (x - (d + 1 + random(3))), y - (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, (x - (d + 1 + random(3))), y + (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, x, y - (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, x, y + (d + 1 + random(3))));
		}
		else
		{
			if (p = get_valid_path(z, x0, y0, (x - (d + 1 + random(3))), y - (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, x, y - (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, (x - (d + 1 + random(3))), y));
			else if (p = get_valid_path(z, x0, y0, (x + (d + 1 + random(3))), y - (d + 1 + random(3))));
			else if (p = get_valid_path(z, x0, y0, (x - (d + 1 + random(3))), y + (d + 1 + random(3))));
		}
	}

	if (p)
	{
		cmd = sprintf("%d", p);

		switch (me->get_walk_step())
		{
		case 0:
		case 1: if (strlen(cmd) > 1) cmd = cmd[0..0];  break;
		case 2: if (strlen(cmd) > 2) cmd = cmd[0..1];  break;
		default: break;
		}

		GO_CMD->main_npc(me, cmd);
	}
}

void generate_tree()
{
	int i, size, z, p, x, y, j, count, * nZ, * nXy;
	object* nObj, tree;
	mixed* nPoint;
	nObj = ({});

	nZ = keys(mpTree1);
	for (j = 0, count = sizeof(nZ); j < count; j++)
	{
		z = nZ[j];
		nPoint = mpTree1[z];
		for (i = 0, size = sizeof(nPoint); i < size; i++)
		{
			tree = new("npc/party/santatree1");
			if (!objectp(tree))
				continue;
			nXy = nPoint[i];
			tree->add_to_scene(z, nXy[0], nXy[1]);
			nObj += ({ tree });
		}
	}

	nZ = keys(mpTree2);
	for (j = 0, count = sizeof(nZ); j < count; j++)
	{
		z = nZ[j];
		nPoint = mpTree2[z];
		for (i = 0, size = sizeof(nPoint); i < size; i++)
		{
			tree = new("npc/party/santatree2");
			if (!objectp(tree))
				continue;
			nXy = nPoint[i];
			tree->add_to_scene(z, nXy[0], nXy[1]);
			nObj += ({ tree });
		}
	}

	SANTACLAUS->set("tree", nObj);
}

void update_record(object player)
{
	int size, index, pos, oldid, id1, amount, i;
	int id = player->get_number();
	string name = player->get_name();
	amount = player->get_save("ChristmasPoint");
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

	send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("Bảng xếp hạng, bây giờ đã trang trí "HIR"%d"NOR" Cây Thông Noel \n", player->get_save("ChristmasPoint")) + cmd
		+ ESC "Xác nhận\n");
}

void move_item_to_user(object who, int amount_s, string name)
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
			amount = USER_INVENTORY_D->carry_combined_item(who, item, total);
			if (amount > 0 && item->set_amount(amount))
			{
				if (p = item->move(who, -1))
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
			if (p = item->move(who, -1))
			{
				item->add_to_user(p);
			}
		}
	}
}


void paihangbang_bonus(int top, object player, object npc) {
	int flag = 0, iVipTime, iVip, iTime;
	int id = player->get_number();
	mixed* mixTime;

	iTime = time();

	if (iTime <= iFinish) {
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n	Rất xin lỗi, chưa tới lúc để nhận thưởng" + ESC"Xác nhận\n");
		return;
	}

	if (sizeof_inventory(player, 2, MAX_CARRY) >= MAX_CARRY)
	{
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n	Rất xin lỗi, muốn nhận được phần thưởng , vui lòng để trống hành trang." + ESC"Xác nhận\n");
		return;
	}

	switch (top)
	{
	case 1:
		move_item_to_user(player, 1, ITEM_TOP_1);
		break;
	case 2:
		move_item_to_user(player, 1, ITEM_TOP_2);
		break;
	case 3:
		move_item_to_user(player, 1, ITEM_TOP_3);
		break;
	default:
		if (top < 10) {
			move_item_to_user(player, 1, ITEM_TOP_10);
		}
		break;
	}

	set_save_2(sprintf("player.%d.bonus", id), 1);
	save();
}