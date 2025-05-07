/*******************************
	**Code By Nguyễn Hiếu 2014**
*******************************/
#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <public.h>
#include <time.h>
#include <action.h>
#include <skill.h>
inherit DBASE_F;
inherit SAVE_F;
#define DEBUG_STR(player,str) {tell_user(player,"str=%s",str);}

#define YUEBING	"item/04/mooncake"
#define BOSS "npc/event/trungthu/boss_1"
#define BOSS_2 "npc/event/trungthu/boss_2"
//#define YUTU	"npc/party/yutu"
#define YUTU	"npc/party/0008"

//Vat pham top
#define YUEHUAN "item/04/0454"
//Tui qua Top
#define ITEM_TOP "item/event/trungthu/topbattho"
#define ITEM_TOP_1 "item/event/trungthu/topbattho_1"
#define ITEM_TOP_2 "item/event/trungthu/topbattho_2"
#define ITEM_TOP_3 "item/event/trungthu/topbattho_3"

#define GIFT_FROM_ADMIN	"item/event/trungthu/tuitrungthu_2"
#define GIFT_EVENT	"item/event/trungthu/tuitrungthu"
#define GIFT_EVENT_THO	"item/event/trungthu/tuitrungthu_tho"


int iStart, iFinish, iFinish_a, kkkk, close, iStart_2;
//object* nObjs= ({});
object change;
string* nWord = ({
	"Chúc mừng Trung thu người yêu nhất và ngoan hiền dịu ngọt nhất của tôi. Cuộc sống buồn tẻ biết bao nếu vắng em.",
	"Chúc Trung thu thật vui và hạnh phúc.",
	"Chúc cho em có những ngày tháng tám luôn tràn đầy ánh trăng thu.",
	"Gửi trọn toàn bộ tình yêu, thân xác (trừ những chỗ cấm) này đến anh/em nhân ngày Trung thu.",
	"Anh yêu quý, mong anh một Tết Trung thu yêu em nhiều hơn, nhiều hơn nữa nha anh và giữ mãi tình yêu mà anh dành cho em. Tháng sau em đi lấy chồng đó, hi hi. ",
	"Chúc tình yêu của em một ngày tràn ngập những quà tặng, những lời chúc, nhưng nụ hôn thì chỉ nhận được một cái thôi nhé. Và đó là của em. Chụt chụt.",
	"Nhân ngày Tết Trung thu anh xin tặng em món quà quý giá nhất của anh, đó chính là... cuộc đời anh. Mong em hãy nhận nó với niềm vui, hạnh phúc.",
	"Chiến quốc Hùng Bá, xin gửi lời chúc đến các bạn với những ước mơ sớm thành hiện thực. kekeke..",
	"Trung thu này tuy em không ở bên anh nhưng đêm qua em đã bí mật nhét trái tim vào trong lồng ngực anh rồi, anh có thấy tim mình hôm nay đập mạnh hơn không? hihi.. ",
	"Ngày Trung thu em, anh chúc em luôn khỏe mạnh, tươi trẻ và gặp được chị hằng tươi xinh nhé.",
	"Gửi đến em những lời chúc tốt đẹp nhất, ngọt ngào như những bông hoa này, vì em đã cùng anh đi đến tận cùng thế giới. Chúc em một ngày Tết Trung thu hạnh phúc.",
	"Chúc cho đại gia đình Chiến Quốc Trung thu ngập tràn tiếng cười, niềm vui",
	});

void get_chang();
void destruct_chang();
void generate_yutu();
void destroy_yutu();
void destroy_yuebing();
void generate_yuebing();
int yuetu_bonus(object player, object npc);
void update_record(object player);
void check_time2();
void paihangbang(object player, object npc);
void paihangbang_bonus(int top, int vip, int potential, int cash, object player, object npc);
int check_yuebing(object who, int count, string name);
int give_yuebing(object who, string name, int count);
int exchange(object player, object npc, int amount, string type);
int get_close();
void move_to_user(object player, int amount_s, string name);

void SAVE_BINARY() { }
string get_save_file() { return "data/Trungthu"SAVE_EXTENSION; }

void create()
{
	restore();

	int year = 0;
	mixed* mixTime;
	mixTime = localtime(time());
	year = mixTime[TIME_YEAR];

	iStart_2 = mktime(year, 9, 30, 17, 0, 0);

	iStart = mktime(year, 9, 26, 8, 0, 0);
	iFinish = mktime(year, 10, 14, 22, 0, 0);
	iFinish_a = mktime(year, 10, 16, 22, 0, 0);
	call_out("check_time", 1);
}

void check_time()
{
	int iTime;
	mixed* mixTime;

	iTime = get_party_time();
	remove_call_out("check_time");

	if (iTime < iStart)
	{
		call_out("check_time", iStart - iTime);
		return;
	}
	if (iTime > iFinish_a)
	{
		destroy_yuebing();
		destroy_yutu();
		destruct_chang();
		return;
	}
	if (iTime > iFinish)
	{
		destroy_yuebing();
		destroy_yutu();
		get_chang();
		call_out("destruct_chang", iFinish_a - iTime);
		return;
	}
	mixTime = localtime(iTime);
	if (mixTime[TIME_HOUR] >= 22)
	{
		destroy_yuebing();
		destroy_yutu();
		call_out("check_time", 3600 * 24 - mixTime[TIME_HOUR] * 3600 - mixTime[TIME_MIN] * 60);
		return;
	}

	/*	delete_save_2("record");
		delete_save_2("player");
		save();
		YUTU->delete_2("player");
		*/

	if (mixTime[TIME_HOUR] < 8)
	{
		call_out("check_time", 3600 * 8 - mixTime[TIME_HOUR] * 3600 - mixTime[TIME_MIN] * 60);
		return;
	}
	check_time2();
}

void check_time2()
{
	int iTime, iHour, random;
	mixed* mixTime, *mixTime_2;
	object npc;

	//	iTime = time();

	iHour = time();
	mixTime_2 = localtime(iTime);

	iTime = get_party_time();
	mixTime = localtime(iTime);
	get_chang();
	CHAT_D->sys_channel(0, "Tết Trung Thu sắp tới, để ăn mừng Trung Thu đoàn viên giai tiết , Chiến quốc đặc biệt mở event Trung thu tới làm bạn cùng các Mem. Mọi người hãy nhanh đến "HIR " Chu Quốc "NOR " tìm ——"HIR " Hằng Nga "NOR " đi , nàng đang ở gần Thần Tiên Gia Gia.");
	log_file("TRUNGTHU.txt", sprintf("%d tháng %d ngày %d :%d Sự kiện Trung Thu bắt đầu.\n", mixTime[TIME_MON] + 1, mixTime[TIME_MDAY], mixTime[TIME_HOUR], mixTime[TIME_MIN]));
	if (mixTime[TIME_MIN] < 30)
	{
		kkkk = -1;
		generate_yutu();
		CHAT_D->rumor_channel(0, CHAT + HIC "Nghe nói Thỏ Ngọc xuất hiện ở bên ngoài thành Thất Quốc, không biết có thật hay không ???");
		log_file("TRUNGTHU.txt", sprintf("%d tháng %d ngày %d :%d giao nộp Thỏ Ngọc\n", mixTime[TIME_MON] + 1, mixTime[TIME_MDAY], mixTime[TIME_HOUR], mixTime[TIME_MIN]));
		call_out("check_time3", 60 * (30 - mixTime[TIME_MIN]));
	}
	else
	{
		kkkk = 1;
		generate_yuebing();
		CHAT_D->rumor_channel(0, CHAT + HIC "Nghe nói Thất quốc bên ngoài thành khắp nơi có rất nhiều Bánh Trung Thu , không biết có thật hay không ???");
		log_file("TRUNGTHU.txt", sprintf("%d tháng %d ngày %d :%d giao nộp Bánh Trung Thu\n", mixTime[TIME_MON] + 1, mixTime[TIME_MDAY], mixTime[TIME_HOUR], mixTime[TIME_MIN]));
		
		if ((mixTime_2[TIME_WDAY] == 0 || mixTime_2[TIME_WDAY] == 1 || mixTime_2[TIME_WDAY] == 5) && mixTime_2[TIME_HOUR] == 20) {
			
			random = random(100);

			if (random <= 50) {
				npc = new(BOSS);
			}
			else {
				npc = new(BOSS_2);
			}

			if (random % 2 == 0) {
				npc->add_to_scene(80, 101, 176);
			}
			else if (random % 3 == 0) {
				npc->add_to_scene(80, 90, 146);
			}
			else {
				npc->add_to_scene(80, 151, 104);
			}

			log_file("TRUNGTHU.txt", sprintf("%d tháng %d ngày %d :%d Boss trung thu\n", mixTime[TIME_MON] + 1, mixTime[TIME_MDAY], mixTime[TIME_HOUR], mixTime[TIME_MIN]));

		}
		

		call_out("check_time3", 60 * (60 - mixTime[TIME_MIN]));
	}
}

void check_time3()
{
	int iTime, rate, level, z, p, x, y, random;
	int i, * nScene, size;
	mixed* mixTime;
	object robber;
	object npc;

	remove_call_out("check_time3");
	//	iTime = time();
	iTime = get_party_time();
	mixTime = localtime(iTime);
	if (get_close()) return;
	if (iTime > iFinish_a)
	{
		destroy_yuebing();
		destroy_yutu();
		destruct_chang();
		return;
	}
	if (iTime > iFinish)
	{
		destroy_yuebing();
		destroy_yutu();
		USER_D->user_channel("Các bạn thân mến, Event Trung Thu đã kết thúc, trong khoảng thời gian này cảm ơn các bạn đã tham gia, làm cho cả Chiến quốc có được không khí vui tươi, cảm tạ mọi người. Xin mời những bạn có tên trong Top lại Hằng Nga nhận thưởng, thời gian tới 22:00 ngày 28 tháng 8 năm 2014.");
		log_file("TRUNGTHU.txt", sprintf("%d tháng %d ngày %d :%d Tết Trung thu hoạt động kết thúc.\n", mixTime[TIME_MON] + 1, mixTime[TIME_MDAY], mixTime[TIME_HOUR], mixTime[TIME_MIN]));
		call_out("destruct_chang", iFinish_a - iTime);
		return;
	}
	if (mixTime[TIME_HOUR] >= 22)
	{
		destroy_yuebing();
		destroy_yutu();
		USER_D->user_channel("Hôm nay hoạt động đến đây kết thúc, ngày mai mời mọi người trở lại tham gia, chúc mọi người Trung thu vui vẻ .");
		call_out("check_time3", 3600 * 24 - mixTime[TIME_HOUR] * 3600 - mixTime[TIME_MIN] * 60);
		log_file("TRUNGTHU.txt", sprintf("%d tháng %d ngày %d :%d Tết Trung Thu cuối ngày.\n", mixTime[TIME_MON] + 1, mixTime[TIME_MDAY], mixTime[TIME_HOUR], mixTime[TIME_MIN]));
		return;
	}

	if (mixTime[TIME_HOUR] < 8)
	{
		call_out("check_time3", 3600 * 8 - mixTime[TIME_HOUR] * 3600 - mixTime[TIME_MIN] * 60);
		return;
	}
	if (mixTime[TIME_HOUR] == 8 && mixTime[TIME_MIN] < 30)
		CHAT_D->sys_channel(0, "Tết Trung Thu sắp tới, để ăn mừng Trung Thu đoàn viên giai tiết, Chiến quốc đặc biệt mở event Trung thu tới làm bạn cùng các Mem. Mọi người hãy nhanh đến "HIR " Chu Quốc "NOR " tìm ——"HIR " Hằng Nga "NOR " đi, nàng đang ở gần Thần Tiên Gia Gia.");
	else
		CHAT_D->sys_channel(0, "Chiến quốc Trung Thu hoạt động đang tiến hành, muốn tham dự hãy tìm hoạt động viên ——"HIR " Hằng Nga "NOR " đi, nàng đang ở "HIR " Chu Quốc "NOR " chờ ngươi.");
	if (kkkk == 1)
	{
		generate_yutu();
		log_file("TRUNGTHU.txt", sprintf("%d tháng %d ngày %d :%d giao nộp Thỏ Ngọc\n", mixTime[TIME_MON] + 1, mixTime[TIME_MDAY], mixTime[TIME_HOUR], mixTime[TIME_MIN]));
	}
	if (kkkk == -1)
	{
		generate_yuebing();
		CHAT_D->rumor_channel(0, CHAT + HIC "Nghe nói Thất quốc bên ngoài thành khắp nơi có rất nhiều Bánh Trung Thu , không biết có thật hay không ???");
		log_file("TRUNGTHU.txt", sprintf("%d tháng %d ngày %d :%d giao nộp Bánh Trung Thu\n", mixTime[TIME_MON] + 1, mixTime[TIME_MDAY], mixTime[TIME_HOUR], mixTime[TIME_MIN]));
	
		if ((mixTime[TIME_WDAY] == 0 || mixTime[TIME_WDAY] == 1 || mixTime[TIME_WDAY] == 5) && mixTime[TIME_HOUR] == 20) {

			random = random(100);

			if (random <= 50) {
				npc = new(BOSS);
			}
			else {
				npc = new(BOSS_2);
			}

			if (random % 2 == 0) {
				npc->add_to_scene(80, 101, 176);
			}
			else if (random % 3 == 0) {
				npc->add_to_scene(80, 90, 146);
			}
			else {
				npc->add_to_scene(80, 151, 104);
			}

			log_file("TRUNGTHU.txt", sprintf("%d tháng %d ngày %d :%d Boss trung thu\n", mixTime[TIME_MON] + 1, mixTime[TIME_MDAY], mixTime[TIME_HOUR], mixTime[TIME_MIN]));

		}

	}
	kkkk = -kkkk;
	call_out("check_time3", 1800);
}

void get_chang()
{
	if (!objectp(change))
	{
		change = new("npc/party/0008");
		change->add_to_scene(80, 283, 179, 4);
	}
}

void destruct_chang()
{
	if (objectp(change))
	{
		change->remove_from_scene();
		destruct(change);
	}
}

void generate_yutu()
{
	int i, z, p, x, y;
	object* nObj, npc;
	destroy_yutu();
	nObj = ({});
	for (z = 10; z <= 80; z += 10)
	{
		for (i = 0; i < 30; i++)
		{
			if (!(p = efun::get_xy_point(z, IS_CHAR_BLOCK)))
				continue;
			x = (p % 1000000) / 1000;  y = p % 1000;
			npc = new("npc/party/yutu");
			if (!objectp(npc))
				continue;
			npc->add_to_scene(z, x, y);
			nObj += ({ npc });
		}
	}
	YUTU->set("npc", nObj);
}

void destroy_yutu()
{
	int i, size;
	object* nObj;
	nObj = YUTU->get("npc");
	for (i = 0, size = sizeof(nObj); i < size; i++)
	{
		if (!objectp(nObj[i]))
			continue;
		nObj[i]->remove_from_scene();
		destruct(nObj[i]);
	}
	YUTU->delete("npc");
}

void generate_yuebing()
{
	int i, z, p, x, y;
	object* nObj, item;
	destroy_yuebing();
	nObj = ({});
	for (z = 10; z <= 80; z += 10)
	{
		for (i = 0; i < 30; i++)
		{
			if (!(p = efun::get_xy_point(z, IS_CHAR_BLOCK)))
				continue;
			x = (p % 1000000) / 1000;  y = p % 1000;
			item = new(YUEBING);
			if (!objectp(item))
				continue;
			item->add_to_scene(z, x, y);
			nObj += ({ item });
		}
	}

	YUTU->set("item", nObj);
}

void destroy_yuebing()
{
	int i, size;
	object* nObj;
	nObj = YUTU->get("item");
	for (i = 0, size = sizeof(nObj); i < size; i++)
	{
		if (!objectp(nObj[i]))
			continue;
		if (get_d(nObj[i]))
			continue;
		nObj[i]->remove_from_scene();
		destruct(nObj[i]);
	}
	YUTU->delete("item");
}

int set_open(object who, string arg)
{
	int year, mon, day, hour, min;
	string cTmp1, cTmp2;
	if (sscanf(arg, "%s-%s", cTmp1, cTmp2) != 2)
	{
		send_user(who, "%c%s", '!', "Sai cách thức !");
		return 0;
	}
	year = to_int(cTmp1[0..3]);
	mon = to_int(cTmp1[4..5]);
	day = to_int(cTmp1[6..7]);
	hour = to_int(cTmp1[8..9]);
	min = to_int(cTmp1[10..11]);
	iStart = mktime(year, mon, day, hour, min, 0);

	year = to_int(cTmp2[0..3]);
	mon = to_int(cTmp2[4..5]);
	day = to_int(cTmp2[6..7]);
	hour = to_int(cTmp2[8..9]);
	min = to_int(cTmp2[10..11]);
	iFinish = mktime(year, mon, day, hour, min, 0);

	if (!iStart || !iFinish)
	{
		send_user(who, "%c%s", '!', "Sai thời gian !");
		return 0;
	}
	if (iStart > iFinish || iFinish < time())
	{
		send_user(who, "%c%s", '!', "Sai thời gian !");
		return 0;
	}
	tell_user(who, "Tết Trung thu hoạt động mở : %s !", arg);
	send_user(who, "%c%s", '!', "Tết Trung thu hoạt động mở!");
	save();
	call_out("check_time", 3);
	return 1;
}

/*int set_close(object who)
{
	remove_call_out("check_time");
	iStart = 0;
	iFinish = 0;
	send_user(who,"%c%s",'!',"中秋节活动关闭！");
	save();
	return 1;
}*/
//获取中秋节活动状态。
/*int is_open()
{
	mixed* mixTime;
	int iHour,iDay,iTime;
	mixTime = localtime(get_party_time());
	iHour = mixTime[TIME_HOUR];
	iDay = mixTime[TIME_MDAY];
	iTime = get_party_time();
	if(!iStart || !iFinish)//Thiết lập 活动开始和结束时间无效。
	{
		return 0;
	}
	if(iTime < iStart || iTime > iFinish)//还没有到时间以及已经活动过期。
	{
		return 0;
	}
	if(iDay == 24 || iDay == 25 || iDay == 26)//9月24 25 26 20:00-21:00
	{
		if(iHour == 20)
		{
			return 1;
		}
	}
	return 0;
}*/

void do_look(object npc, object player)
{
	int index;
	string dailogue = "";
	string* choices1 = ({ HIY"Giao nộp 5 Thỏ Ngọc","Bảng xếp hạng bắt Thỏ",HIY"Đổi Bánh Trung Thu","Quy tắc hoạt động","Thời gian hoạt động", HIC"Nhận quà Trung Thu" });
	string* choices2 = ({ HIY"Đổi Bánh Trung Thu",HIY"Giao nộp 5 Thỏ Ngọc","Bảng xếp hạng bắt Thỏ","Nhận giải thưởng", });
	int iTime;
	mixed* mixTime;
	iTime = get_party_time();
	mixTime = localtime(iTime);
	if (iTime < iFinish)
		//	if(is_open())
	{
		dailogue += "    Trung Thu vui vẻ, hôm nay là Trung Thu giai tiết, ta mang theo Thỏ Ngọc tới Chiến quốc cùng mọi người ăn mừng ngày lễ, nhưng là ta vừa tới nơi đây, lại phát hiện Thỏ Ngọc không thấy, có thể nó lại không nghe lời, ngươi có thể giúp ta bắt nó về không ?\n";
		for (index = 0; index < 6; index++)
		{
			dailogue += sprintf(ESC"%s\ntalk %x# welcome.%d\n", choices1[index], getoid(npc), index + 2);
		}
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + dailogue + ESC"Rời khỏi\n");
	}
	else
	{
		dailogue += "    Ngươi cần ta giúp một tay không ?\n";
		for (index = 0; index < 4; index++)
		{
			dailogue += sprintf(ESC"%s\ntalk %x# welcome.%d\n", choices2[index], getoid(npc), index + 8);
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

	//player->set_2("rabbit.day",localtime(get_party_time())[TIME_MDAY]);//记录与嫦娥交互的时间。	
	switch (flag)
	{
	case 1:
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + "    Ở Chu Quốc, Hàn Quốc, Triệu Quốc, Ngụy Quốc, Tần Quốc, Sở Quốc, Yên Quốc, Tề Quốc sẽ xuất hiện Thỏ, dùng Dây Bắt Thỏ bắt được giao cho ta , là sẽ đạt được phần thưởng. Hơn nữa số lượng bắt càng nhiều sẽ lọt vào TOP, nếu như tên của ngươi xuất hiện ở Bảng xếp hạng, ta sẽ cho ngươi một phần Trung Thu đại lễ.\n" + ESC"Xác nhận\n");
		break;
	case 2: // Doi tho ngoc
		if (get_party_time() > iFinish) return;
		if (check_yuebing(player, 1, "Thỏ Ngọc") != 1)
		{
			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + "    Xin lỗi bạn không có con Thỏ nào\n" + ESC"Xác nhận\n");
			return;
		}

		if (yuetu_bonus(player, npc)) {
			player->add_save("tuzi", 5);
			update_record(player);
		}
		
		break;
	case 3://Bảng xếp hạng bắt Thỏ
		paihangbang(player, npc);
		break;
	case 4://Đổi Bánh Trung Thu
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s:\n    Trung thu hoạt động thời gian đã qua, bất quá ta còn là sẽ giúp ngươi đổi thưởng đích.\n"
			ESC"Giao 5 Bánh Trung Thu đổi lấy túi quà Trung Thu\ntalk %x# welcome.1139157\n"
			ESC HIY"Giao 15 Bánh Trung Thu đổi lấy 2 Dây Bắt Thỏ\ntalk %x# welcome.1139160\n"
			ESC"Rời khỏi", npc->get_name(), id, id, id));
		break;
	case 5://Quy tắc hoạt động
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s:\n    Ở Chu Quốc, Hàn Quốc, Triệu Quốc, Ngụy Quốc, Tần Quốc, Sở Quốc, Yên Quốc, Tề Quốc sẽ xuất hiện Thỏ, dùng "HIR "Dây Bắt Thỏ"NOR "bắt được giao cho ta sẽ được phần thưởng, ta còn sẽ ghi chép số lượng, nếu như ngươi có thể ở "HIR "Bảng xếp hạng bắt Thỏ"NOR "sẽ đạt được Trung thu đặc biệt lễ vật một phần, 3 người chơi Top đầu sẽ đạt được phần thưởng VIP... muốn đạt được phải cố gắng bắt nhiều Thỏ.\n    Ngoài ra, bên ngoài thành các nước sẽ còn có Bánh Trung Thu, chỉ cần giao Bánh Trung Thu cũng có thể ở chỗ này của ta đổi phần thưởng nhất định.\n"ESC"Xác nhận\n", npc->get_name()));
		break;
	case 6://Thời gian hoạt động
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s:\n    Thời gian hoạt động từ ngày 26 tháng 9 (10/8 âm lịch) đến ngày 15 tháng 10 (29/8 âm lịch) là event kết thúc, đến hết ngày 30/8 âm lịch chị Hằng sẽ bay về trời. Event bắt đầu lúc 08:00 đến 22:00 hàng ngày.\n"ESC"Xác nhận", npc->get_name()));
		break;

	case 7://Qua Trung Thu

		if (iTime < iStart_2) {
			notify(HIY"17h ngày 30/09 hãy quay lại nhận thưởng nhé!");
			return;
		}

		if ((mixTime[TIME_HOUR] < 17 || mixTime[TIME_HOUR] > 20) && (mixTime[TIME_WDAY] != 30 && mixTime[TIME_WDAY] != 1)) {
			notify(HIY"Không thể nhận quà lúc này, quay lại sau nhé");
			return;
		}

		if (player->get_save("trungthu2020")) {
			notify("Ngươi đã nhận qua phần thưởng này rồi!");
			return;
		}

		move_to_user(player, 1, GIFT_FROM_ADMIN);
		player->set_save("trungthu2020", 1);

		break;
	//2 ngay trao thuong
	case 8://Giao banh
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s:\n    Trung thu hoạt động thời gian đã qua, bất quá ta còn là sẽ giúp ngươi đổi thưởng đích.\n"
			ESC"Giao 5 Bánh Trung Thu đổi lễ vật\ntalk %x# welcome.1139157\n"ESC"Rời khỏi", npc->get_name(), id, id));
		break;
	case 9: // thong bao giao tho 
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + "    Thời gian sự kiện đã hết, ngươi muốn giao nộp Thỏ Ngọc sao ??\n" + 
			sprintf(ESC"Xác nhận\ntalk %x# welcome.12\n", getoid(npc)) + ESC"Rời khỏi\n");
		break;
	case 12: //giao tho
		if (check_yuebing(player, 1, "Thỏ Ngọc") != 1)
		{
			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + "    Xin lỗi bạn không có con Thỏ nào\n" + ESC"Xác nhận\n");
			return;
		}

		yuetu_bonus(player, npc);
		break;

	case 1139157: // Banh Trung Thu doi qua
		if (check_yuebing(player, 5, "Bánh Trung Thu") == 0)
		{
			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s:\n    Bánh Trung Thu trên người ngươi không đủ\n"ESC"Xác nhận", npc->get_name()));
			return;
		}
		exchange(player, npc, 5, "Túi Quà Trung Thu");
		break;
	case 1139160: // Banh Trung Thu doi day bat tho
		if (check_yuebing(player, 15, "Bánh Trung Thu") == 0)
		{
			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s:\n    Bánh Trung Thu trên người ngươi không đủ\n"ESC"Xác nhận", npc->get_name()));
			return;
		}
		exchange(player, npc, 15, "Dây Bắt Thỏ");
		break;

		//Tang banh trung thu
	case 1139158:
		if (check_yuebing(player, 5, "Bánh Trung Thu") == 0)
		{
			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s:\n    Bánh Trung Thu trên người ngươi không đủ\n"ESC"Xác nhận", npc->get_name()));
			return;
		}
		send_user(player, "%c%c%d%s", '?', 16, 30, "Vui lòng nhập ID :\n" + sprintf(ESC"talk %x# welcome.1139159", getoid(npc)) + ".%s\n");
		break;

	case 1139159:
		if (!sizeof(id1))
			return;
		cTmp = nWord[random(sizeof(nWord))];
		if (id1 == "0")
			name = "Tất cả mọi người";
		else
		{
			i = to_int(id1);
			if (!i)
				return;
			obj = find_char(id1);
			if (!objectp(obj))
			{
				if (!(player->get_friend_id(i)))
				{
					send_user(player, "%c%s", '!', "Người chơi không tồn tại");
					return;
				}
				else
				{
					name = player->get_friend_name(i);
				}
			}
			else
				name = obj->get_name();
			if (name == player->get_name())
			{
				send_user(player, "%c%s", '!', "Không thể gửi cho chính mình");
				return;
			}
		}
		if (give_yuebing(player, "Bánh Trung Thu", 5) == 0)
		{
			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s:\n    Bánh Trung Thu trên người ngươi không đủ\n"ESC"Xác nhận", npc->get_name()));
			return;
		}

		cTmp = sprintf(HIY"%s"HIR " nói với"HIY" %s"HIR " : %s", player->get_name(), name, cTmp);
		if (objectp(obj)) MAILBOX->sys_mail(obj->get_id(), obj->get_number(), cTmp);
		CHAT_D->sys_channel(0, HIR + cTmp);
		break;

	case 10://Bảng xếp hạng bắt Thỏ,
		paihangbang(player, npc);
		break;
	case 11:
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
		//		if(player->get_2("rabbit.day")== localtime(get_party_time())[TIME_MDAY])
		{
			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s:\n    Ngươi rất lợi hại, đây là phần thưởng của ngươi, xin mời nhận lấy đi.\n" + sprintf(ESC"Nhận giải thưởng.\ntalk %x# welcome.16\n", getoid(npc)), npc->get_name()));
		}
		break;
	case 16:


		if (iTime <= iFinish) {
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
			paihangbang_bonus(pos,1, 900, 500000, player, npc);
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
			paihangbang_bonus(pos,0, 500, 50000, player, npc);
			break;
		case 7:
			paihangbang_bonus(pos,0, 400, 40000, player, npc);
			break;
		case 8:
			paihangbang_bonus(pos,0, 300, 30000, player, npc);
			break;
		case 9:
			paihangbang_bonus(pos,0, 200, 20000, player, npc);
			break;
		default:
			paihangbang_bonus(pos,0, 100, 10000, player, npc);
		}
		break;
	}
}

//Doi banh trung thu
void move_to_user(object player, int amount_s, string name)
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

		USER_D->user_channel("Xin chúc mừng "HIY + player->get_name() + NOR" trong dịp Tết Trung Thu đạt được " + HIR + name_s + ".\n");
	}
}

// Thông báo nhận thưởng đổi Thỏ
void move_to_hieu(object player, int amount_s, string name, object npc)
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

		USER_D->user_channel("Xin chúc mừng "HIY + player->get_name() + NOR" trong dịp Tết Trung Thu đổi Thỏ Ngọc đạt được " + HIR + name_s + ".\n");
	}
}

//Thuong Top Trung thu
void paihangbang_bonus(int top, int vip, int potential, int cash, object player, object npc)
{
	int flag = 0, iVipTime, iVip, iTime;
	int id = player->get_number();
	mixed* mixTime;

	iTime = get_party_time();

	if (iTime <= iFinish) {
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n	Rất xin lỗi, chưa tới lúc để nhận thưởng" + ESC"Xác nhận\n");
		return;
	}


	if (sizeof_inventory(player, 2, MAX_CARRY) >= MAX_CARRY)
	{
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n	Rất xin lỗi, muốn nhận được phần thưởng , vui lòng để trống hành trang. Nếu như kinh nghiệm cùng tiềm năng đạt tới giới hạn, cũng không thể nhận được." + ESC"Xác nhận\n");
		return;
	}

	//move_to_user(player, 1, YUEHUAN);
	
	switch (top)
	{
	case 1:
		move_to_user(player, 1, ITEM_TOP_1);
		break;
	case 2:
		move_to_user(player, 1, ITEM_TOP_2);
		break;
	case 3:
		move_to_user(player, 1, ITEM_TOP_3);
		break;
	default:
		move_to_user(player, 1, ITEM_TOP);
		break;
	}

	if (vip)
	{
		iVip = player->get_vip();
		if (iVip != 0 && iVip != 1)
			return 0;
		iVipTime = player->get_save_2("vip_package.time");
		if (iVipTime == 0)
			iVipTime = time() + 3600 * 24 * 31;
		else
			iVipTime += 3600 * 24 * 31;
		if (iVip == 0)
			player->delete_save_2("vip_package");
		player->delete_save_2("vip_package.trial");
		player->set_vip(1);
		player->add_save_2("vip_package.doubles", 4);
		player->set_save_2("vip_package.time", iVipTime);
		player->add_title("V001");
		send_user(player, "%c%w%w%c", 0x81, 7401, 999, EFFECT_GOOD);
		USER_ENERGY_D->count_cp(player);
		USER_ENERGY_D->count_pp(player);
		USER_ENERGY_D->count_ap(player);
		USER_ENERGY_D->count_dp(player);
		mixTime = localtime(iVipTime);
		send_user(player, "%c%s", ';', sprintf("VIP của bạn là %d - %02d - %02d %02d : %02d : %02d. VIP mô tả các ảnh hưởng của thời gian có thể học được. Bạn cũng có thể tìm thấy thời gian VIP hết hạn.", mixTime[TIME_YEAR], mixTime[TIME_MON] + 1, mixTime[TIME_MDAY], mixTime[TIME_HOUR], mixTime[TIME_MIN], mixTime[TIME_SEC]));
		send_user(player, "%c%w%s", 0x82, 7401, "item/sell/0061"->get_loop_desc(player));
		send_user(player, "%c%c%c", 0xA2, 4, 1);
		send_user(player, "%c%c%c", 0xA2, 3, 3 - player->get_save_2("vip_package.revive.count"));
		"item/sell/0061"->send_vip_to_friend(player, 1);
		USER_D->user_channel("Xin chúc mừng "HIY + player->get_name() + NOR" trong dịp event Trung Thu đạt được " + HIR + " Gói VIP " + ".\n");
	}

	player->add_potential(potential);
	player->add_cash(cash);
	set_save_2(sprintf("player.%d.bonus", id), 1);
	save();
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
	//	log_file("zhongqiu.txt",short_time() + "\n"+cmd );
	send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("Bảng xếp hạng bắt Thỏ, bây giờ đã nộp "HIR"%d"NOR" Thỏ Ngọc \n", player->get_save("tuzi")) + cmd
		+ ESC "Xác nhận\n");
}

//Doi banh trung thu
int exchange(object player, object npc, int amount, string type)
{
	int rand, p, cash, exp, pot;
	if (sizeof_inventory(player, 1, MAX_CARRY) >= MAX_CARRY)
	{
		send_user(player, "%c%s", '!', "Hành trang trên người ngươi không đủ, lần sau nhận thưởng phải chú ý");
		return;
	}
	if (give_yuebing(player, "Bánh Trung Thu", amount) == 0)
	{
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s:\n    Bánh Trung Thu trên người ngươi không đủ\n"ESC"Xác nhận", npc->get_name()));
		return;
	}

	if (type == "Dây Bắt Thỏ") {
		move_to_user(player, 2, "/item/event/trungthu/daybattho");
		return 1;
	}
	else {
		move_to_user(player, 1, GIFT_EVENT);
	}

	send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s:\n    Chúc ngươi Trung Thu vui vẻ , "HIB"Chiến Quốc Ngũ Hổ Tướng.\n", npc->get_name()));
	return 1;
}

int check_yuebing(object who, int count, string name)
{
	int i, size, amount;
	object* inv, item;
	inv = all_inventory(who, 1, MAX_CARRY * 4);
	if (!inv)
	{
		return 0;
	}
	if (!(objectp(item = present(name, who, 1, MAX_CARRY * 4))) || (item->is_zhongqiu() != 1))
	{
		return 0;
	}
	for (i = 0, size = sizeof(inv); i < size; i++)
	{
		if (!objectp(inv[i]))
			continue;
		if (inv[i]->get_name() != name || inv[i]->is_zhongqiu() != 1)
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
int give_yuebing(object who, string name, int count)
{
	int i, size, amount;
	object* inv, item;
	if (check_yuebing(who, count, name) != 1)
		return 0;
	inv = all_inventory(who, 1, MAX_CARRY * 4);
	for (i = 0, size = sizeof(inv); i < size; i++)
	{
		if (!objectp(inv[i]))
			continue;
		if (inv[i]->get_name() != name || inv[i]->is_zhongqiu() != 1)
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

void update_record(object player)
{
	int size, index, pos, oldid, id1, amount, i;
	int id = player->get_number();
	string name = player->get_name();
	amount = player->get_save("tuzi");
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

//Doi tho ngoc
int yuetu_bonus(object player, object npc)
{
	int rand, id, move, level;
	int* decoration = ({ HEAD_TYPE,NECK_TYPE,ARMOR_TYPE,WAIST_TYPE,BOOTS_TYPE });
	string* nFamily = ({ "Đào Hoa Nguyên", "Thục Sơn", "Cấm Vệ Quân", "Đường Môn", "Mao Sơn", "Côn Luân", "Vân Mộng Cốc", "Minh Giáo", });
	string* nTmp;
	object item;

	id = player->get_number();

	if (sizeof_inventory(player, 1, MAX_CARRY) >= MAX_CARRY)
	{
		send_user(player, "%c%s", '!', "Hành trang trên người ngươi không đủ, lần sau nhận thưởng phải chú ý");
		return 0;
	}

	if (give_yuebing(player, "Thỏ Ngọc", 5) == 0)
	{
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s:\n   Xin lỗi, bạn không có đủ 5 Thỏ Ngọc.\n"ESC"Xác nhận", npc->get_name()));
		return 0;
	}

	move_to_hieu(player, 2, GIFT_EVENT_THO, npc);

	return 1;
}

void before_destruct()
{
	if (objectp(change))
	{
		change->remove_from_scene();
		destruct(change);
	}
}

/*void equipment(string*schoolname, int*gender,int*decoration,object player)
{
	int level,move;
	object present;
	string* gold_equip = ({});
	level = player->get_level();
	level = level+random(10)+1;
	if(level > 120)
	{
		level = 120;
	}
	gold_equip = WEAPON_FILE->get_family_equip(schoolname[random(sizeof(schoolname))],gender[random(sizeof(gender))],level,decoration[random(sizeof(decoration))]);
	if(sizeof(gold_equip)> 0)
	{
		present = new(gold_equip[random(sizeof(gold_equip))]);
		if(!present)
		{
			return;
		}
		ITEM_EQUIP_D->init_equip_prop_3(present);
		if( move = present->move(player, -1) )
			{
					present->add_to_user(move);
					USER_D->user_channel("Xin chúc mừng"+player->get_name()+"trong dịp Tết Trung Thu đạt được"+HIR+present->get_name()+".\n");
			}
			else
			{
				destruct(present);
			}
	}
}*/

int get_close()
{
	return close;
}

void set_close()
{
	close = 1;
	destruct_chang();
	destroy_yutu();
	destroy_yuebing();
}