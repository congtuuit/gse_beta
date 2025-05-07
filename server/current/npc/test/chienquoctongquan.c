#include <item.h>
#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>
#include <effect.h>
#include <music.h>

#include <time.h>
#include <city.h>
#include <public.h>
#include <equip.h>
#include <time.h>

inherit OFFICER;

#define YUANBAO "sys/sys/test_db"

int get_char_picid() { return 9955; }

int is_seller() { return 12021; }

int is_self_look() { return 1; }
void do_welcome(string arg);
void do_accept(string arg);
void create()
{
	set_name(HIR"Chiến Quốc Đại Tổng Quản");
	set_real_name("Chu Tịch");

	set_2("talk", ([
		"welcome":(: do_welcome:),
		"giaotrangbi" : (: do_accept:),

	]));

	set_2("good", ([
			"01":"/item/diemdanh/cql",
			"02" : "/item/diemdanh/tuidacuonghoa5",
			"03" : "/item/diemdanh/ve/ve5sao",
			"04" : "/item/ppvacanh/canhnamblock/canhnamblock",
			"05" : "/item/ppvacanh/canhnublock/canhnublock",
			"06" : "/item/ppvacanh/vgppblock/vgppblock",
			"07" : "/item/ppvacanh/xnppblock/xnppblock",
			"08" : "/item/diemdanh/cql2",
	]));

	setup();

}

void do_look(object player)
{
	object npc = this_object();

	send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s :\n" + "Tham gia điểm danh đổi nhiều phần quà hấp dẫn...!!!\n"
		ESC HIC"Tham gia điểm danh\ntalk %x# welcome.1\n"
		ESC HIC"Quà điểm danh\nlist2 %x#\n"
		//ESC HIG"Quyên góp quân trang \ntalk %x# welcome.3\n"
		//ESC HIY"Top quyên góp quân trang \ntalk %x# welcome.4\n"
		ESC "Rời khỏi\nCLOSE\n", npc->get_name(), getoid(npc), getoid(npc), getoid(npc), getoid(npc)));
}

void do_welcome(string arg)
{
	__FILE__->do_welcome2(this_object(), arg);
}

void do_welcome2(object npc, string arg)
{
	int flag,size, i, p, gender, rate, point, thieunhi_item, k, j, iTime, user_id, huan_chuong_number, cql_number, amount;
	object player = this_player(), item, item1, item2;
	string* nTmp, cFile;
	mixed* mixTime;
	string *data_quan_trang, *data_content;

	string result = "";

	flag = to_int(arg);
	user_id = player->get_number();

	iTime = time();
	mixTime = localtime(iTime);

	switch (flag)
	{
	case 1:

		if (player->get_save_2("diem_danh.ngay") == (mixTime[TIME_WDAY] +1) && player->get_save_2("diem_danh.ngay") != 0) {
			send_user(player, "%c%c%w%s", ':', 3, get_char_picid(), sprintf(" %s :\n Hôm nay ngươi đã điểm danh rồi, hôm sau quay lại sao nhé!!\n"
				ESC"Thoát", npc->get_name()));
			return;
		}

		if (player->get_save_2("diem_danh.today") - iTime > 0) {
			send_user(player, "%c%c%w%s", ':', 3, get_char_picid(), sprintf(" %s :\n Bạn đã đăng ký điểm danh, sau %d giây nữa quay lại nhận thưởng nhé!!\n"
				ESC"Thoát", npc->get_name(), player->get_save_2("diem_danh.today") - iTime));
			return;
		}

		if (player->get_save_2("diem_danh.today") > 0 && time() - player->get_save_2("diem_danh.today") >= 0) {
			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s :\n" + "Tham gia điểm danh đổi nhiều phần quà hấp dẫn...!!!\n"
				ESC HIY"Nhận thưởng điểm danh\ntalk %x# welcome.11\n"
				ESC "Rời khỏi\nCLOSE\n", npc->get_name(), getoid(npc), getoid(npc), getoid(npc)));
			return;
		}

		player->set_save_2("diem_danh.today", time() + 3600);
		send_user(player, "%c%c%w%s", ':', 3, get_char_picid(), sprintf(" %s :\n Bạn đã đăng ký điểm danh thành công, 1h sau bạn quay lại nhận thưởng nhé!\n"
			ESC"Thoát", npc->get_name()));

		break;
	case 2:
		
		//send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s :\n" + "Tham gia điểm danh đổi nhiều phần quà hấp dẫn...!!!\n"
		//	ESC HIC"5 Huân Chương lấy 1 Chiến quốc lệnh\ntalk %x# welcome.26\n"
		//	/*ESC "5 Huân Chương lấy 1 Sơ Cấp Đoạn Thạch"NOR"\ntalk %x# welcome.21\n"
		//	ESC "10 Huân Chương lấy 1 Trung Cấp Đoạn Thạch"NOR"\ntalk %x# welcome.22\n"
		//	ESC "15 Huân Chương lấy 1 Cao Cấp Đoạn Thạch"NOR"\ntalk %x# welcome.23\n"*/
		//	//ESC HIY"30 Huân Chương lấy Cánh (7 ngày)\ntalk %x# welcome.24\n"
		//	//ESC HIY"30 Huân Chương lấy Phi Phong (7 ngày)\ntalk %x# welcome.25\n"
		//	ESC "Rời khỏi\nCLOSE\n", npc->get_name(), getoid(npc), getoid(npc), getoid(npc), getoid(npc), getoid(npc), getoid(npc), getoid(npc)));

		break;

	case 3:

		/*if ((mixTime[TIME_MON] + 1) == 7 && mixTime[TIME_MDAY] > 14) {
			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s :\n" + "Sự kiện đã kết thúc.\n"
				ESC "Rời khỏi\nCLOSE\n", npc->get_name(), getoid(npc)));
			return;
		}*/

		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s :\n" + "Sự kiện sẽ kết thúc vào lúc "HIR"23h59 14/07/2020"NOR". Điểm cống hiến cho quân đội của bạn: "HIR"%d"NOR". Bạn có thể sử dụng điểm để đổi thưởng.\n"
			ESC "Giao trang bị ALT+G\ntalk %x# welcome.31\n"
			//ESC "Quyên góp ngân lượng\ntalk %x# welcome.33\n"
			//ESC HIY"Quyên góp KNB\ntalk %x# welcome.34\n"
			//ESC HIC"Đổi thưởng (Sử dụng 150 điểm)\ntalk %x# welcome.32\n"
			ESC "Rời khỏi\nCLOSE\n", npc->get_name(), player->get_save_2("quantrang.core"), getoid(npc), getoid(npc), getoid(npc), getoid(npc), getoid(npc)));
		return;
		break;
	case 4:
		"sys/party/quantrang"->check_mingren_downline(player);
		result = "sys/party/quantrang"->get_top_data(player, "point_player", "point");
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf(""NOR"%s : Sự kiện sẽ kết thúc vào lúc "HIR"23h59 14/07/2020"NOR"\n" +
			"%s"
			ESC "Rời khỏi\nCLOSE\n", npc->get_name(), result));

		break;
	
	case 11:
		if (player->get_save_2("diem_danh.ngay") == (mixTime[TIME_WDAY] + 1) && player->get_save_2("diem_danh.ngay") != 0) {
			send_user(player, "%c%c%w%s", ':', 3, get_char_picid(), sprintf(" %s :\n Hôm nay ngươi đã điểm danh rồi, hôm sau quay lại sao nhé!!\n"
				ESC"Thoát", npc->get_name()));
			return;
		}

		if (USER_INVENTORY_D->get_free_count(player) < 1)
		{
			notify("Hành trang không đủ 1 chỗ trống");
			return;
		}

		item = new ("/item/diemdanh/0438");
		k = item->move2(player, -1);
		item->add_to_user(k);
		send_user(player, "%c%s", ';', sprintf("Bạn nhận được "HIC"%s"NOR" từ sự kiện điểm danh!", item->get_name()));

		player->set_save_2("diem_danh.ngay", mixTime[TIME_WDAY] + 1);

		log_file("DiemDanh.txt", sprintf("%s %s (%d) %s hoàn tất điểm danh\n", short_time(), player->get_name(), player->get_number(), player->get_id()));

		break;

	/*case 21:

		if (USER_INVENTORY_D->get_free_count(player) < 1)
		{
			notify("Hành trang không đủ 1 chỗ trống");
			return;
		}

		huan_chuong_number = TASK_LEGEND_D->check_task_item_amount(player, "Huân Chương Điểm Danh");
		if (huan_chuong_number < 5) {
			notify("Vật phẩm không đủ");
			return;
		}

		TASK_LEGEND_D->check_task_item1(player, "Huân Chương Điểm Danh", 5);

		item = new ("/item/diemdanh/0032");
		k = item->move(player, -1);
		item->add_to_user(k);

		send_user(player, "%c%s", ';', "Chúc mừng bạn đã nhận được "HIY"" + item->get_name());
		log_file("item/chienquoctongquan.dat", sprintf("%s %s (%d) đổi quà điểm danh nhận %s\n", short_time(), player->get_id(), player->get_number(), item->get_name()));

		break;
	case 22:
		if (USER_INVENTORY_D->get_free_count(player) < 1)
		{
			notify("Hành trang không đủ 1 chỗ trống");
			return;
		}

		huan_chuong_number = TASK_LEGEND_D->check_task_item_amount(player, "Huân Chương Điểm Danh");
		if (huan_chuong_number < 10) {
			notify("Vật phẩm không đủ");
			return;
		}

		TASK_LEGEND_D->check_task_item1(player, "Huân Chương Điểm Danh", 10);

		item = new ("/item/diemdanh/1032");
		k = item->move(player, -1);
		item->add_to_user(k);

		send_user(player, "%c%s", ';', "Chúc mừng bạn đã nhận được "HIY"" + item->get_name());

		log_file("item/chienquoctongquan.dat", sprintf("%s %s (%d) đổi quà điểm danh nhận %s\n", short_time(), player->get_id(), player->get_number(), item->get_name()));


		break;
	case 23:
		if (USER_INVENTORY_D->get_free_count(player) < 1)
		{
			notify("Hành trang không đủ 1 chỗ trống");
			return;
		}

		huan_chuong_number = TASK_LEGEND_D->check_task_item_amount(player, "Huân Chương Điểm Danh");
		if (huan_chuong_number < 15) {
			notify("Vật phẩm không đủ");
			return;
		}

		TASK_LEGEND_D->check_task_item1(player, "Huân Chương Điểm Danh", 15);

		item = new ("/item/diemdanh/2032");
		k = item->move(player, -1);
		item->add_to_user(k);

		send_user(player, "%c%s", ';', "Chúc mừng bạn đã nhận được "HIY"" + item->get_name());

		log_file("item/chienquoctongquan.dat", sprintf("%s %s (%d) đổi quà điểm danh nhận %s\n", short_time(), player->get_id(), player->get_number(), item->get_name()));


		break;
	case 24:
		if (USER_INVENTORY_D->get_free_count(player) < 1)
		{
			notify("Hành trang không đủ 1 chỗ trống");
			return;
		}

		huan_chuong_number = TASK_LEGEND_D->check_task_item_amount(player, "Huân Chương Điểm Danh");
		if (huan_chuong_number < 30) {
			notify("Vật phẩm không đủ");
			return;
		}

		gender = player->get_gender();

		if (gender == 0) {
			notify("Lỗi không xác định");
			return;
		}

		TASK_LEGEND_D->check_task_item1(player, "Huân Chương Điểm Danh", 30);

		if (gender == 1) {
			item = new ("/item/diemdanh/canhnam");

		}
		else {
			item = new ("/item/diemdanh/canhnu");
		}

		k = item->move(player, -1);
		item->add_to_user(k);

		send_user(player, "%c%s", ';', "Chúc mừng bạn đã nhận được "HIY"" + item->get_name());
		log_file("item/chienquoctongquan.dat", sprintf("%s %s (%d) đổi quà điểm danh nhận %s\n", short_time(), player->get_id(), player->get_number(), item->get_name()));

		break;
	case 25:
		if (USER_INVENTORY_D->get_free_count(player) < 1)
		{
			notify("Hành trang không đủ 1 chỗ trống");
			return;
		}

		huan_chuong_number = TASK_LEGEND_D->check_task_item_amount(player, "Huân Chương Điểm Danh");
		if (huan_chuong_number < 30) {
			notify("Vật phẩm không đủ");
			return;
		}

		gender = player->get_gender();

		if (gender == 0) {
			notify("Lỗi không xác định");
			return;
		}

		TASK_LEGEND_D->check_task_item1(player, "Huân Chương Điểm Danh", 30);

		if (gender == 1) {
			item = new ("/item/diemdanh/vgpp");

		}
		else {
			item = new ("/item/diemdanh/xnpp");
		}

		k = item->move(player, -1);
		item->add_to_user(k);

		send_user(player, "%c%s", ';', "Chúc mừng bạn đã nhận được "HIY"" + item->get_name());

		log_file("item/chienquoctongquan.dat", sprintf("%s %s (%d) đổi quà điểm danh nhận %s\n", short_time(), player->get_id(), player->get_number(), item->get_name()));

		break;
	case 26:
		if (USER_INVENTORY_D->get_free_count(player) < 1)
		{
			notify("Hành trang không đủ 1 chỗ trống");
			return;
		}

		huan_chuong_number = TASK_LEGEND_D->check_task_item_amount(player, "Huân Chương Điểm Danh");
		cql_number = TASK_LEGEND_D->check_task_item_amount(player, "Chiến Quốc Lệnh");

		if (huan_chuong_number < 5 || cql_number < 2) {
			notify("Vật phẩm không đủ");
			return;
		}

		TASK_LEGEND_D->check_task_item1(player, "Huân Chương Điểm Danh", 5);
		TASK_LEGEND_D->check_task_item1(player, "Chiến Quốc Lệnh", 2);

		item = new ("/item/diemdanh/cql2");
		k = item->move(player, -1);
		item->add_to_user(k);

		send_user(player, "%c%s", ';', "Chúc mừng bạn đã nhận được "HIY"" + item->get_name());

		log_file("item/chienquoctongquan.dat", sprintf("%s %s (%d) đổi quà điểm danh nhận %s\n", short_time(), player->get_id(), player->get_number(), item->get_name()));

		break;*/

	case 31:
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + "Sử dụng ALT + G để đưa trang bị cho tôi !\n"
			ESC "Ta hiểu rồi\nCLOSE\n"
			ESC "Thoát ra\nCLOSE\n");
		break;

	case 32:
		return;
		/*if ((mixTime[TIME_MON] + 1) == 7 && mixTime[TIME_MDAY] > 14) {
			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s :\n" + "Sự kiện đã kết thúc.\n"
				ESC "Rời khỏi\nCLOSE\n", npc->get_name(), getoid(npc)));
			return;
		}*/

		if (USER_INVENTORY_D->get_free_count(player) < 1)
		{
			notify("Hành trang không đủ 1 chỗ trống");
			return;
		}

		if (player->get_save_2("quantrang.core") < 150) {
			notify("Tích lũy ít nhất 150 điểm mới có thể đổi thưởng");
			return;
		}

		item = new("/item/eventquantrang/tuiquantrang");
		k = item->move(player, -1);
		item->add_to_user(k);
		tell_user(player, ECHO"Bạn đã sử dụng 150 điểm tích lũy, còn lại: %d", player->get_save_2("quantrang.core"));
		send_user(player, "%c%s", ';', "Chúc mừng bạn đã nhận được "HIY"" + item->get_name());
		log_file("item/chienquoctongquan.dat", sprintf("%s %s (%d) đổi quà QUÂN TRANG nhận %s\n", short_time(), player->get_id(), player->get_number(), item->get_name()));

		player->add_save_2("quantrang.core", -150);
		CHAT_D->sys_channel(0, sprintf(player->get_name() + " nhận "HIR"Quân Trang Lễ Bao"NOR" từ "HIG"Chiến Quốc Đại Tổng Quản."));

		break;

	case 33:
		return;
		if ((mixTime[TIME_MON] + 1) == 7 && mixTime[TIME_MDAY] > 14) {
			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s :\n" + "Sự kiện đã kết thúc.\n"
				ESC "Rời khỏi\nCLOSE\n", npc->get_name(), getoid(npc)));
			return;
		}

		//ngan lương
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s :\n" + "Bạn muốn sử dụng ngân lượng để quyên góp không?\n"
			ESC "100.000 ngân lượng (8 điểm tích lũy)\ntalk %x# welcome.41\n"
			ESC "1.000.000 ngân lượng (88 điểm tích lũy)\ntalk %x# welcome.42\n"
			ESC "5.000.000 ngân lượng (444 điểm tích lũy)\ntalk %x# welcome.43\n"
			ESC "Rời khỏi\nCLOSE\n", npc->get_name(), getoid(npc), getoid(npc), getoid(npc), getoid(npc)));

		break;
	case 34:
		return;
		if ((mixTime[TIME_MON] + 1) == 7 && mixTime[TIME_MDAY] > 14) {
			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s :\n" + "Sự kiện đã kết thúc.\n"
				ESC "Rời khỏi\nCLOSE\n", npc->get_name(), getoid(npc)));
			return;
		}

		//KNB
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s :\n" + "Bạn muốn sử Kim Bảo để quyên góp không?\n"
			ESC "50 KNB (100 điểm tích lũy)\ntalk %x# welcome.44\n"
			ESC "100 KNB (200 điểm tích lũy)\ntalk %x# welcome.45\n"
			ESC "Rời khỏi\nCLOSE\n", npc->get_name(), getoid(npc), getoid(npc), getoid(npc), getoid(npc)));
		break;


	case 41:
		return;
		amount = 100000;
		point = 8;
		
		if(player->get_cash() < amount){
			notify("Số dư bạn không đủ");
			return;
		}
		
		player->add_cash(-amount);
		player->add_save_2("quantrang.core", point);
		send_user(player, "%c%s", ';', "Bạn góp 100.000 lượng. Bạn nhận được "HIR + point + " điểm.");
		log_file("item/quyengop_quantrang.dat", sprintf("%s %s (%d) góp QUÂN TRANG %d ngân lượng nhận %d điểm\n", short_time(), player->get_id(), player->get_number(), amount, point));

		break;

	
	case 42:
		return;
		amount = 1000000;
		point = 88;
		
		if(player->get_cash() < amount){
			notify("Số dư bạn không đủ");
			return;
		}
		
		player->add_cash(-amount);
		player->add_save_2("quantrang.core", point);
		send_user(player, "%c%s", ';', "Bạn góp 1.000.000 lượng. Bạn nhận được "HIR + point + " điểm.");
		log_file("item/quyengop_quantrang.dat", sprintf("%s %s (%d) góp QUÂN TRANG %d ngân lượng nhận %d điểm\n", short_time(), player->get_id(), player->get_number(), amount, point));

		break;
	case 43:
		amount = 5000000;
		point = 444;
		
		if(player->get_cash() < amount){
			notify("Số dư bạn không đủ");
			return;
		}
		
		player->add_cash(-amount);
		player->add_save_2("quantrang.core", point);
		send_user(player, "%c%s", ';', "Bạn góp 5.000.000 lượng. Bạn nhận được "HIR + point + " điểm.");
		log_file("item/quyengop_quantrang.dat", sprintf("%s %s (%d) góp QUÂN TRANG %d ngân lượng nhận %d điểm\n", short_time(), player->get_id(), player->get_number(), amount, point));

		break;
	case 44:
		return;
		amount = 500;
		point = 100;
		
		if(YUANBAO->get_yuanbao(player) < amount){
			notify("KNB bạn không đủ");
			return;
		}
		
		YUANBAO->add_yuanbao(player, -amount);
		player->add_save_2("quantrang.core", point);
		send_user(player, "%c%s", ';', "Bạn góp 50 KNB. Bạn nhận được "HIR + point + " điểm.");
		log_file("item/quyengop_quantrang.dat", sprintf("%s %s (%d) góp QUÂN TRANG %d KNB nhận %d điểm\n", short_time(), player->get_id(), player->get_number(), amount, point));

		break;
	case 45:
		return;
		amount = 1000;
		point = 200;
		
		if(YUANBAO->get_yuanbao(player) < amount){
			notify("KNB bạn không đủ");
			return;
		}
		
		YUANBAO->add_yuanbao(player, -amount);
		player->add_save_2("quantrang.core", point);
		send_user(player, "%c%s", ';', "Bạn góp 100 KNB. Bạn nhận được "HIR + point + " điểm.");
		log_file("item/quyengop_quantrang.dat", sprintf("%s %s (%d) góp QUÂN TRANG %d KNB nhận %d điểm\n", short_time(), player->get_id(), player->get_number(), amount, point));

		break;

	case 99:

		break;

	}

}



int accept_object(object who, object item) { return __FILE__->accept_object_callout(this_object(), who, item); }

int accept_object_callout(object me, object who, object item)
{
	int level, p, i, t1, t2, t3, t4, mau, cap, cap1, cap2, point, price, price2;
	object item2;
	string sao, ngoc;

	int iTime;
	mixed* mixTime;
	iTime = time();
	mixTime = localtime(iTime);

	me->to_front_eachother(who);

	if ((mixTime[TIME_MON] + 1) == 7 && mixTime[TIME_MDAY] > 14) {
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s :\n" + "Sự kiện đã kết thúc.\n"
			ESC "Rời khỏi\nCLOSE\n", me->get_name(), getoid(me)));
		return;
	}

	if (!item->is_equip()) return 0;
	if (item->is_equip())
	{
		i = item->get_equip_type();
		if (i != ARMOR_TYPE && i != HEAD_TYPE && i != BOOTS_TYPE && i != WAIST_TYPE && i != NECK_TYPE) {
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), "Đại Tổng Quản:\nNgươi đưa cho ta trang bị không đúng !\n"ESC"Xác nhận\nCLOSE\n"ESC"Rời khỏi");
			return -99;
		}
	}

	cap2 = item->get_level();
	mau = item->get_item_color();

	point = cap2 / 10;

	if (mau == 2) {
		point = point + 2;
	}

	price2 = who->get_level() * 100;
	price = item->get_value() / 2;

	if (price < price2 || mau < 1 || mau == 3) {
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), "Đại Tổng Quản:\nTrang bị này không có giá trị, người còn trang bị nào không?\n"ESC"Xác nhận");
		return 0;
	}

	send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("Đại Tổng Quản:\nTrang bị này sẽ đổi được %d điểm tích lũy\n"
		ESC"Xác nhận\ntalk %x# giaotrangbi.%x#\n"
		ESC"Huỷ bỏ", point, getoid(me), getoid(item)));

	return -99;
}

void do_accept(string arg) { return __FILE__->do_accept_callout(this_object(), this_player(), arg); }

void do_accept_callout(object me, object who, string arg)
{
	int level, p, i, t1, t2, t3, t4, mau, cap, cap1, cap2, itemid, ben, point, price, price2;
	object item, item1;
	string sao, ngoc, forge = "";

	if (!objectp(item = present(arg, who, 1, MAX_CARRY * 4)))
		return 0;
	if (!item->is_equip()) return 0;
	if (item->is_equip())
	{
		i = item->get_equip_type();
		if (i != WEAPON_TYPE && i != ARMOR_TYPE && i != HEAD_TYPE && i != BOOTS_TYPE && i != WAIST_TYPE && i != NECK_TYPE) {
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), "Đại Tổng Quản:\nNgươi giao cho ta không phải là trang bị hoặc vũ khí !!!\n"ESC"Xác nhận");
			return 0;
		}
	}

	cap2 = item->get_level();
	mau = item->get_item_color();

	price2 = who->get_level() * 100;
	price = item->get_value() / 2;

	if (price < price2 || mau < 1 || mau == 3) {
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), "Đại Tổng Quản:\nTrang bị này không có giá trị, người còn trang bị nào không?\n"ESC"Xác nhận");
		return 0;
	}

	if (who->get_save_2("quantrang.core") < 1) {
		who->set_save_2("quantrang.core", 0);
	}

	point = cap2 / 10;
	if (mau == 2) point = point + 2;
	who->add_save_2("quantrang.core", point);

	item->remove_from_user();
	destruct(item);

	send_user(who, "%c%s", ';', "Bạn nhận được "HIR + point + " điểm.");
	return 0;
}