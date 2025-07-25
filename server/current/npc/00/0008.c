
#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <time.h>

#define TREASURE        "/item/std/8000"
#define EVENT_TET        "/sys/party/tet"

#define LT_SEC          0
#define LT_MIN          1
#define LT_HOUR         2
#define LT_MDAY         3
#define LT_MON          4
#define LT_YEAR         5
#define LT_WDAY         6
#define LT_YDAY         7
#define LT_GMTOFF       8
#define LT_ZONE         9

inherit OFFICER;

int iStart2, iFinish2, close_val, open_val, BatDau, KetThuc;
void do_look(object who);
void do_welcome(string arg);
int is_holiday();

int get_char_picid() { return 6008; }

void create()
{

	int year = 0;
	mixed* mixTime;
	mixTime = localtime(time());
	year = mixTime[TIME_YEAR];

	set_name("Thần Tiên Gia Gia");

	set_2("talk", ([
		"welcome":(: do_welcome:),
	]));
	//	set("mpLegend",([0:({32*48+1}),10:({11,}),30:({9,13})]));
	//	set("mpLegend2",([0:({24,2}),]));
	setup();
	set("mpLegend", ([0:({ 32 }), ]));


	iStart2 = mktime(year, 2, 16, 0, 0, 0);
	iFinish2 = mktime(year, 2, 21, 0, 0, 0);

	BatDau = mktime(year, 2, 7, 0, 0, 0);
	KetThuc = mktime(year, 2, 21, 23, 59, 59);

}

void do_look(object who)
{
	int x;
	x = (time() - 4 * 24 * 3600 + 8 * 3600) / (7 * 24 * 3600);
	if (who->get_save_2("double_time.week") != x)
	{
		who->set_save_2("double_time.week", x);
		who->set_save_2("double_time.time", 0);		//双
		who->set_save_2("double_time.time1", 0);	//战国令
		who->set_save_2("double_time.time2", 0);	//战国号角
		who->set_save_2("double_time.time3", 0);	//额外换取的3小时双倍时间
		who->set_save_2("double_time.freeze", 0);	//冻结的双倍时间
	}

	do_welcome("99");
}

void do_welcome(string arg)
{
	object me = this_object();
	__FILE__->do_welcome2(me, arg);
}

void do_welcome2(object me, string arg)
{
	int flag, date, status, p, z, x, y, i;
	object who, obj, item, item2;
	object itemValentine;

	string cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, cmd7, cmd8, result, ben;
	mixed mxTime;
	int iVipTime, iTime;

	who = this_player();
	flag = to_int(arg);
	who->set_time("talk", 0);
	p = 0;
	z = get_z(me);
	x = (time() - 4 * 24 * 3600 + 8 * 3600) / (7 * 24 * 3600);
	if (who->get_save_2("double_time.week") != x)
	{
		who->set_save_2("double_time.week", x);
		who->set_save_2("double_time.time", 0);		//双
		who->set_save_2("double_time.time1", 0);	//战国令
		who->set_save_2("double_time.time2", 0);	//战国号角
		who->set_save_2("double_time.time3", 0);	//额外领双
		who->set_save_2("double_time.freeze", 0);	//冻结的双倍时间
	}
	switch (flag)
	{
	case 1:
		if (who->get_legend(TASK_NEWBIE_00, 1) && !who->get_legend(TASK_NEWBIE_00, 2))
		{
			cmd1 = sprintf("talk %x# welcome.2\n", getoid(me));
			result = sprintf(" %s :\n Ha ha ! Nhìn thấy các dũng sĩ lần lượt đến, ta cảm thấy rất vui. Mạo hiểm của ngươi chỉ mới bắt đầu, ngươi có thể đến Tân Thủ Thôn trước để tìm hiểu tất cả các chức năng, nếu có chỗ nào không hiểu, ngươi có thể tìm Chỉ Dẫn Tiên tử Mà hỏi.\n"
				ESC "Nhiệm vụ hoàn thành\n" + cmd1 +
				ESC "Đóng lại\nCLOSE\n", get_name());
			send_user(who, "%c%c%w%s", ':', 3, 6008, result);
		}
		break;
	case 2:
		if (who->get_legend(TASK_NEWBIE_00, 1) && !who->get_legend(TASK_NEWBIE_00, 2))
		{
			if (who->get_save_2("double_time.freeze") > 0)
			{
				send_user(who, "%c%c%w%s", ':', 3, 6008,
					sprintf("%s:\n     Của bạn "HIR "Nhân đôi kinh nghiệm đã đóng băng"NOR "， hãy giải trừ đóng băng rồi mới nhân đôi kinh nghiệm !\n"
						ESC "Đóng\nCLOSE\n", me->get_name()));
				return;
			}
			// 收去百合仙子的信件
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_NEWBIE_00, 2);
			who->add_exp(20);
			who->add_cash(500);
			who->add_potential(20);
			"/quest/help"->send_help_tips(who, 2);

			mxTime = localtime(time());
			if (who->get_save("dbtime_s") == mxTime[TIME_YDAY])
			{
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n    Bạn đã nhận nhân đôi kinh nghiệm rồi !");
				return;
			}
			i = gone_time(who->get_login_time());

			who->set_save("dbtime_s", mxTime[TIME_YDAY]);
			if (i + who->get_game_time() < who->get_double_time())
				who->set_double_time(who->get_double_time() + 1800);
			else
				who->set_double_time(i + who->get_game_time() + 1800);
			who->delete("tasklist");
			send_user(who, "%c%c%c%w%s", 0x51, 1, 1, 0001, "Viện Trợ trò chơi");
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "Thời Gian Nhân Đôi");
			"/sys/task/task"->send_task_intro(who, 1, 1, 1);
			"/quest/help"->send_help_tips(who, 3);
			result = "Ngươi đã nhận được phần thưởng của Thần Tiên Gia Gia là 20 điểm Kinh nghiệm, 20 điểm Tiềm năng, 500 lượng và nửa giờ kinh nghiệp gấp đôi";
			send_user(who, "%c%s", ';', result);
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n    Ta tặng ngươi 30 phút nhân đôi kinh nghiệm, hãy biết tận dụng !");

			send_user(who, "%c%c%c%w%c", 0x51, 2, 1, TID_NEWBIE_00, 0);
			send_user(who, "%c%c%c%w%w%c", 0x51, 2, 2, TID_NEWBIE_00, 1, 0);
			"/sys/sys/count"->add_task("Sứ Mệnh Đưa Thư", 1);
			if (who->get_legend(TASK_48, 1))  return;
			cmd1 = sprintf("talk %x# welcome.21\n", getoid(me));
			result = sprintf(" %s :\n Ở ngoài Tân Thủ Thôn này, phân bố 1 số động vật rất kì quái, bọn chúng không giống như gà, thỏ và Bù Nhìn thân thiện thông thường, chúng biết tấn công người, tiêu trừ lũ quái vật này là công việc chúng ta luôn phải làm, nếu anh có thể giúp ta tiêu diệt lũ quái vật này thì tốt biết mấy!\n Chủ Tiệm Vũ Khí rất vui vẽ tặng anh một số đồ, sau khi tiêu diệt xong bọn chúng anh đi tìm ông ấy nhé.\n"

				ESC "Nhận lãnh nhiệm vụ\n" + cmd1 +
				ESC "Đóng lại\nCLOSE\n", get_name());
			send_user(who, "%c%c%w%s", ':', 3, 6008, result);

		}
		else
			send_user(who, "%c%s", '!', "Anh không có người đưa tin trên người.");
		break;
	case 3:
		if (who->get_legend(TASK_NEWBIE_00, 3))  return;
		cmd1 = sprintf("talk %x# welcome.4\n", getoid(me));
		result = get_name() + ":\n    Bạn vừa mới tới ngôi làng này, và bạn có thể không quen với môi trường ở đây. bạn đi lên con đường màu xanh xanh bên cạnh tôi. bạn có thể tìm chủ tiệm cầm đồ và hỏi ông ta một thanh kiếm gỗ cho tôi. ông sẽ đưa nó cho bạn rất nhanh！\n"
			ESC "Nhận nhiệm vụ\n" + cmd1 +
			ESC "Đóng\nCLOSE\n";
		send_user(who, "%c%c%w%s", ':', 3, 6008, result);
		break;
	case 4:
		if (!who->get_legend(TASK_NEWBIE_00, 3)) who->set_legend(TASK_NEWBIE_00, 3);
		send_user(who, "%c%s", '!', "Bạn đã nhận được Nhiệm vụ của Thần Tiên Gia Gia！");
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Làng Tân Sinh");
		send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 1, "Thiên Chúa của các vị thần");
		break;
	case 5:
		if (!who->get_legend(TASK_NEWBIE_00, 4))
		{
			result = get_name() + ":\n    Sao?Người chủ cửa hàng vũ khí không cho à?Nếu không, sao anh không mang theo?Tôi không nghĩ vậy！\n"
				ESC "Rời khỏi\nCLOSE\n";
			send_user(who, "%c%c%w%s", ':', 3, 6008, result);
			return;
		}
		if (who->get_legend(TASK_NEWBIE_00, 5))  return;
		cmd1 = sprintf("talk %x# welcome.6\n", getoid(me));
		result = get_name() + ":\n    武器店老板痛快吧！呵呵，说过了，他是个痛快人.我就喜欢和这样的人打交道.这柄木剑虽然不值什么钱，但是对我用途大着呢，具体有什么用，我可不告诉你，嘿嘿.这是俺老头儿的一点秘密！\n"
			ESC "Hoàn thành nhiệm vụ\n" + cmd1;
		send_user(who, "%c%c%w%s", ':', 3, 6008, result);
		break;
	case 6:
		cmd1 = sprintf("talk %x# welcome.7\n", getoid(me));
		cmd2 = sprintf("talk %x# welcome.8\n", getoid(me));
		cmd3 = sprintf("talk %x# welcome.9\n", getoid(me));
		result = get_name() + ":\n    Xin hãy chọn một món thưởng:\n"
			ESC "Dao gỗ cho người mới\n" + cmd1 +
			ESC "Cây gỗ dài\n" + cmd2 +
			ESC "Mâu\n" + cmd3;
		send_user(who, "%c%c%w%s", ':', 3, 6008, result);
		break;
	case 7:
	case 8:
	case 9:
		if (who->get_legend(TASK_NEWBIE_00, 4) && !who->get_legend(TASK_NEWBIE_00, 5))
		{
			// 收去Kiếm gỗ của ông bất tử
			if (!objectp(item = present("Kiếm gỗ của ông bất tử", who, 1, MAX_CARRY)))
			{
				send_user(who, "%c%s", '!', "Anh không có nó Kiếm gỗ của ông bất tử");
				return;
			}
			item->remove_from_user();
			destruct(item);
			switch (flag)
			{
			case 7:
				item = new ("item/01/7200");
				break;
			case 8:
				item = new ("item/01/7500");
				break;
			case 9:
				item = new ("item/01/7400");
				break;
			}
			result = "Cậu được 30 点经验";
			if (item)
			{
				if (USER_INVENTORY_D->can_carry(who, item) >= 1)
				{
					p = item->move(who, -1);
					item->add_to_user(p);
					result += sprintf("và %s", item->get_name());
				}
				else
					destruct(item);
			}
			result += ".";
			send_user(who, "%c%s", ';', result);
			who->add_exp(30);
			who->set_legend(TASK_NEWBIE_00, 5);
			send_user(who, "%c%c%c%w%c", 0x51, 2, 1, TID_NEWBIE_01, 0);
			send_user(who, "%c%c%c%w%w%c", 0x51, 2, 2, TID_NEWBIE_01, 1, 0);
			"/sys/sys/count"->add_task("Lời dạy của ông nội bất tử", 1);

		}
		break;
	case 20:
		if (who->get_legend(TASK_48, 1))  return;
		cmd1 = sprintf("talk %x# welcome.21\n", getoid(me));
		result = get_name() + ":\n    Bên ngoài ngôi làng này, có vài con thú lạ, chúng không thân thiện như những con gà, thỏ và bù nhìn tầm thường. Chúng sẽ tấn công con người. Loại bỏ những con quái vật này là những gì chúng ta đang làm！\n    Người chủ tiệm vũ khí sẽ rất vui lòng cho anh thứ gì đó.\n"

			ESC "Nhận nhiệm vụ\n" + cmd1 +
			ESC "Đóng\nCLOSE\n";
		send_user(who, "%c%c%w%s", ':', 3, 6008, result);
		break;
	case 21:
		if (who->get_legend(TASK_48, 1))  return;
		if (who->get_save_2("task.story") >= 20)
		{
			send_user(who, "%c%s", '!', "Bạn đã nhận 20 nhiệm vụ, không thể nhận thêm được nữa！");
			return;
		}
		if (!who->get_legend(TASK_48, 1)) who->set_legend(TASK_48, 1);
		who->delete_save("new_sj");
		send_user(who, "%c%s", '!', "Ngươi đã nhận được nhiệm vụ của Thủ Thuật Nhỏ!");
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Tân Thủ Thôn");
		send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 101, "Thủ Thuật Nhỏ");
		who->add_save_2("task.story", 1);
		break;
	case 26:
		cmd1 = sprintf("talk %x# welcome.27\n", getoid(me));
		cmd2 = sprintf("talk %x# welcome.28\n", getoid(me));
		result = get_name() + ":\n    Xin hãy chọn một món thưởng:\n"
			ESC "Quần áo đàn ông\n" + cmd1 +
			ESC "uần áo vải nữ\n" + cmd2;
		send_user(who, "%c%c%w%s", ':', 3, 6008, result);
		break;
	case 27:
	case 28:
		if (who->get_legend(TASK_NEWBIE_00, 6) && who->get_legend(TASK_NEWBIE_00, 7) && !who->get_legend(TASK_NEWBIE_00, 8))
		{
			if (flag == 27)
				item = new ("/item/01/6000");    // 男布衣
			else
				item = new ("/item/01/6100");    // 女布衣
			result = "Bạn nhận được 80 kinh nghiệm";
			if (item)
			{
				if (USER_INVENTORY_D->can_carry(who, item) >= 2)
				{
					p = item->move(who, -1);
					item->add_to_user(p);
					result += sprintf("、%s", item->get_name());
				}
				else
				{
					destruct(item);
					send_user(who, "%c%s", '!', "Hành trang không đủ chỗ！");
					return;
				}
			}
			item = new ("/item/32/3282");    // Trái quýt
			if (item)
			{
				item->set_amount(6);
				if (USER_INVENTORY_D->can_carry(who, item) >= 1)
				{
					p = item->move(who, -1);
					item->add_to_user(p);
					result += sprintf("、%s", item->get_name());
				}
				else
					destruct(item);
			}
			result += ".";
			send_user(who, "%c%s", ';', result);
			who->add_exp(80);
			who->set_legend(TASK_NEWBIE_00, 8);
			send_user(who, "%c%c%c%w%c", 0x51, 2, 1, TID_NEWBIE_01, 0);
			send_user(who, "%c%c%c%w%w%c", 0x51, 2, 2, TID_NEWBIE_01, 2, 0);
			"/sys/sys/count"->add_task("Thủ Thuật Nhỏ", 1);
		}
		break;
	case 30:
		if (get_z(who) != 80)
			return;
		if (who->get_level() >= 30 && !who->get_legend(TASK_NEWBIE_00, 9))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Một số người nói rằng ông ta tham nhũng và hối lộ, nhưng một số khác nói rằng ông ta là một quan chức tốt và đã làm rất nhiều việc cải thiện. ông ta không bao giờ giải thích những tin đồn này cho chính mình. người ta nói rằng có rất nhiều bọn cướp gần đây. Chủ nhân đang tìm sự giúp đỡ khắp nơi. Đi và nhìn đi! Sau cây cầu đằng sau tôi, đi thẳng về phía trước và bạn sẽ tìm thấy người Giáo.\n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.31\n"ESC"Rời khỏi", me->get_name(), getoid(me)));
		else if (!who->get_legend(TASK_NEWBIE_00, 10))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Bạn đã đi thăm Sư Phụ? Bạn không cảm thấy không may sao? Không phải bạn không tò mò? Cùng một huyền thoại, bạn có muốn gặp anh ấy không?\n"ESC"Rời khỏi", me->get_name()));
		break;
	case 31:
		if (get_z(who) != 80)
			return;
		if (who->get_level() >= 30 && !who->get_legend(TASK_NEWBIE_00, 9))
		{
			who->set_legend(TASK_NEWBIE_00, 9);
			send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_ZHOUGUO, "Chu Quốc");
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_ZHOUGUO, 3, "Thăm chủ nhân");
			send_user(who, "%c%s", '!', "Nhận nhiệm vụ  "HIY"Thăm chủ nhân");
		}
		break;
	case 32:
		if (get_z(who) != 80)
			return;
		if (!who->get_legend(TASK_NEWBIE_00, 11))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Cảnh sát Vương (Vương Bộ Đầu) vừa mới nhận được một loạt việc vặt, và không có đủ người, nói rằng các t ù nhân đã trốn thoát. và có rất nhiều phần thưởng. cháu có thể tìm kiếm rất nhiều phần thưởng. cháu không cần phải nói cho cháu sự thật. đồn thư ở thành phố Châu Đại Yên, Hầu Viên Vương, rất gần. cháu có thể tìm kiếm nó！\n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.33\n"ESC"Rời khỏi", me->get_name(), getoid(me)));
		else if (!who->get_legend(TASK_NEWBIE_00, 12))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Eh, tại sao cậu không đến gặp Cảnh sát Vương?Khi thời điểm đến, người khác s ẽ làm mọi việc lặt vặt anh sẽ không mất cơ hội kiếm tiền đâu?\n"ESC"Rời khỏi", me->get_name()));
		break;
	case 33:
		if (get_z(who) != 80)
			return;
		if (who->get_level() >= 10 && !who->get_legend(TASK_NEWBIE_00, 11))
		{
			who->set_legend(TASK_NEWBIE_00, 11);
			send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_ZHOUGUO, "Chu Quốc");
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_ZHOUGUO, 1, "Công việc tốt của Vương Bộ Đầu");
		}
		break;
	case 34:
		if (get_z(who) != 80)
			return;
		if (!who->get_legend(TASK_NEWBIE_00, 13))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Vị lãnh đạo hộ tống cũ của weichi là nỗi kinh hoàng của bọn cướp. tôi nghe nói công việc của ông ta quá tốt và không có đủ người. đi và xem xem liệu các bạn có thể giúp được gì không. mà còn nhớ là đại lý hộ tống của ông ta đang ở vùng Tây Bắc của quốc gia tôi. không có đủ người. đi tìm xem xem các bạn có thể giúp được gì không. nhớ không, cơ quan hộ tống là Trịnh wei.\n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.35\n"ESC"Rời khỏi", me->get_name(), getoid(me)));
		else if (!who->get_legend(TASK_NEWBIE_00, 14))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Được.Vị thủ lĩnh phi tiêu của Lão Chí có vẻ như là anh hùng.Cô vẫn chưa gặp anh ta à?Hỡi các chàng trai trẻ, chúng t a phải có sức mạnh trong việc làm nhiều việc, cũng là câu nói của vệ sĩ cũ Ngụy Chi！\n"ESC"Rời khỏi", me->get_name()));
		break;
	case 35:
		if (get_z(who) != 80)
			return;
		if (who->get_level() >= 30 && !who->get_legend(TASK_NEWBIE_00, 13))
		{
			who->set_legend(TASK_NEWBIE_00, 13);
			send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_ZHOUGUO, "Chu Quốc");
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_ZHOUGUO, 2, "Đi mà nói chuyện với nước Ngụy");
		}

		break;
	case 36:
		if (get_z(who) != 80)
			return;
		if (who->get_legend(TASK_NEWBIE_01, 23) && !who->get_legend(TASK_NEWBIE_01, 24) && get_z(who) == 80)
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Tôi chỉ muốn huấn luyện các bạn. Chu Qu đâu đâu đâu đâu đâu? Chu Qu đâu? 789C có một thế giới rộng hơn cả làng người mới. C ác bạn nên quan sát xa hơn. Ví dụ, sư phụ Chu Quốc, 7889C, lãnh đạo của weichi phi tiêu và nhà Vương lãnh đạo đều là những người lớn！\n"ESC"Hoàn thành nhiệm vụ\ntalk %x# welcome.37\n"ESC"Rời khỏi", me->get_name(), getoid(me)));
		break;
	case 37:
		if (get_z(who) != 80)
			return;
		if (who->get_legend(TASK_NEWBIE_01, 23) && !who->get_legend(TASK_NEWBIE_01, 24) && get_z(who) == 80)
		{
			who->set_legend(TASK_NEWBIE_01, 24);
			who->add_exp(250);
			who->add_potential(30);
			who->add_cash(5000);
			send_user(who, "%c%s", ';', "Phần thưởng kinh nghiệm 250 tiềm năng 30 Ngân lượng 5000 ");
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 13, "");
		}
		break;
	case 40:
		x = (time() - 4 * 24 * 3600 + 8 * 3600) / (7 * 24 * 3600);
		if (who->get_save_2("double_time.week") != x)
		{
			who->set_save_2("double_time.week", x);
			who->set_save_2("double_time.time", 0);		//双
			who->set_save_2("double_time.time1", 0);	//战国令
			who->set_save_2("double_time.time2", 0);	//战国号角
			who->set_save_2("double_time.time3", 0);
			who->set_save_2("double_time.freeze", 0);	//冻结的双倍时间
		}
		if (who->get_save_2("double_time.time") >= 8)
		{
			y = 7 * 24 * 3600 - ((time() - 4 * 24 * 3600 + 8 * 3600) % (7 * 24 * 3600));
			if (y < 24 * 3600)
			{
				send_user(who, "%c%c%w%s", ':', 3, 6008,
					sprintf("%s:\n     Bạn đã tích luỹ thời gian nhân đôi vượt quá 4 giờ, hãy chờ %d giờ sau lại đến nhận. \n"
						ESC "Đóng\nCLOSE\n", me->get_name(), y / 3600));
			}
			else
			{
				send_user(who, "%c%c%w%s", ':', 3, 6008,
					sprintf("%s:\n     Bạn đã tích luỹ thời gian nhân đôi vượt quá 4 giờ, hãy chờ %d ngày sau lại đến nhận. \n"
						ESC "Đóng\nCLOSE\n", me->get_name(), y / (24 * 3600)));
			}
			return;
		}
		cmd1 = sprintf("talk %x# welcome.41\n", getoid(me));
		cmd2 = sprintf("talk %x# welcome.42\n", getoid(me));
		cmd3 = sprintf("talk %x# welcome.43\n", getoid(me));
		result = sprintf(" %s :\n Ta có thể dùng tiên thuật nhanh chóng nâng cao đẳng cấp, sau khi ngươi tiêu diệt yêu quái trong thời gian nhất định Kinh nghiệm và Tiềm năng đạt được đều đước thưởng gấp đôi .Ngươi còn có thể nhận lãnh " + sprintf("%d", (8 - who->get_save_2("double_time.time")) * 30) + " Phút Thời Gian Nhân Đôi.Vậy thì ngay từ bây giờ ngươi hãy chọn 1 thời gian luyện cấp thích hợp với mình.\n"
			ESC "1 giờ\n" + cmd1 +
			ESC "2 giờ\n" + cmd2 +
			ESC "4 giờ\n" + cmd3 +
			ESC "Đóng lại\nCLOSE\n", get_name());
		send_user(who, "%c%s", ':', result);
		break;
	case 43:
		p += 4;
	case 42:
		p += 2;
	case 41:
		p += 2;
		i = gone_time(who->get_login_time());
		x = (time() - 4 * 24 * 3600 + 8 * 3600) / (7 * 24 * 3600);
		if (who->get_save_2("double_time.week") != x)
		{
			who->set_save_2("double_time.week", x);
			who->set_save_2("double_time.time", 0);		//双
			who->set_save_2("double_time.time1", 0);	//战国令
			who->set_save_2("double_time.time2", 0);	//战国号角
			who->set_save_2("double_time.time3", 0);
			who->set_save_2("double_time.freeze", 0);	//冻结的双倍时间
		}
		if (who->get_save_2("double_time.freeze") > 0)
		{
			send_user(who, "%c%c%w%s", ':', 3, 6008,
				sprintf("%s:\n     Của bạn "HIR "Nhân đôi kinh nghiệm đã đóng băng"NOR "， hãy giải trừ rồi lại nhân đôi kinh nghiệm\n"
					ESC "Đóng\nCLOSE\n", me->get_name()));
			return;
		}
		if (who->get_save_2("double_time.time") >= 8)
		{
			y = 7 * 24 * 3600 - ((time() - 4 * 24 * 3600 + 8 * 3600) % (7 * 24 * 3600));
			if (y < 24 * 3600)
			{
				send_user(who, "%c%c%w%s", ':', 3, 6008,
					sprintf("%s:\n     Bạn đã tích luỹ thời gian nhân đôi vượt quá 4 giờ, hãy chờ %d giờ sau lại đến nhận. \n"
						ESC "Đóng\nCLOSE\n", me->get_name(), y / 3600));
			}
			else
			{
				send_user(who, "%c%c%w%s", ':', 3, 6008,
					sprintf("%s:\n     Bạn đã tích luỹ thời gian nhân đôi vượt quá 4 giờ, hãy chờ %d ngày sau lại đến nhận. \n"
						ESC "Đóng\nCLOSE\n", me->get_name(), y / (24 * 3600)));
			}
			return;
		}
		if (who->get_online_rate() == 50)
		{
			send_user(who, "%c%s", '!', "Không có kinh nghiệm chơi mệt mỏ.");
			return;
		}
		else if (who->get_online_rate() == 0)
		{
			send_user(who, "%c%s", '!', "Không có kinh nghiệm kép trong thời gian trò chơi không lành.");
			return;
		}
		if (who->get_save_2("double_time.time") + p > 8)
		{
			p = 8 - who->get_save_2("double_time.time");
		}
		send_user(who, "%c%c%w%s", ':', 3, 6008,
			sprintf("%s:\n     Bạn nhận được %d phút nhân đôi kinh nghiệm, hãy tận dụng\n"
				ESC "Đóng\nCLOSE\n", me->get_name(), p * 30));
		who->add_save_2("double_time.time", p);
		p *= 1800;
		if (i + who->get_game_time() < who->get_double_time())
			who->set_double_time(who->get_double_time() + p);
		else
			who->set_double_time(i + who->get_game_time() + p);
		send_user(who, "%c%c%w%s", ':', 3, 6008,
			sprintf(" %s :\n Ngươi đã lũy kế nhận lãnh rồi %d Giải thưởng thời gian Kinh nghiệm gấp đôi, cố gắng giữ.\n"
				ESC "Đóng\nCLOSE\n", me->get_name(), (who->get_double_time() - i - who->get_game_time()) / 60));
		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, 0001, "Viện Trợ trò chơi");
		send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "Thời Gian Nhân Đôi");
		"/sys/task/task"->send_task_intro(who, 1, 1, 1);
		"/quest/help"->send_help_tips(who, 3);
		"/sys/task/task"->send_task_intro(who, 1, 1, 1);
		break;
	case 50:
		if (MAIN_D->get_host_type() == 6012)
		{
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Máy chủ đang bận.", me->get_name()));
			return;
		}
		if (who->get_level() >= 40 && !who->get_legend(TASK_40, 5))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(),
				sprintf(" %s :\n Kiến Bang cần Tù Và Đế Vương, Nói về Tù Và, cơ hồ chỉ là truyền thuyết……\n "
					NOR "Mấy chục năm về trước, có người họ Lý , họ sở hữu một thủ nghệ đã thất truyền trên giang hồ từ lâu ——chế tạo Tù và. Giặc giã triền miên, sự việc thay đổi, con cháu nhà Họ lý đều khôn lớn, không thích cuộc sống giang hồ, chọn Ngoại thế đào nguyên là 1 nơi có hoa có cỏ có thác nước chảy định cư, từ đó về sau không màn đến chuyện giang hồ.\n Ta nghĩ, thế lực dân gian không dễ dàng bỏ qua đâu, nếu như ngươi muốn kiến bang, ngươi hãy đi tìm Lý Ẩn Sĩ đi, dùng tấm lòng thành của ngươi để ông ấy cảm động, nói với ông ấy làm cho ngươi 1 cái Tù và, đương nhiên cái Tù và này còn phải cần thợ mộc gia công sau đó mới có thể trở thành Tù Và Đế Vương, ngươi đi đến đỉnh Đông Thái gần bờ biển mà tìm ông ấy nhé .\n"
					ESC"Tiếp nhận nhiệm vụ\ntalk %x# welcome.51\n"
					ESC"Rời khỏi", me->get_name(), getoid(me)));
		break;
	case 51:
		if (MAIN_D->get_host_type() == 6012)
		{
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Máy chủ đang bận.", me->get_name()));
			return;
		}
		if (who->get_level() >= 40 && !who->get_legend(TASK_40, 5))
		{
			who->set_legend(TASK_40, 5);
			send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_ZHOUGUO, "Chu Quốc");
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_ZHOUGUO, 10, "Tù Và Lập Bang");
			send_user(who, "%c%s", '!', "Nhận nhiệm vụ "HIY"Tù Và Lập Bang");
		}
		break;


	case 60:
		i = time();
		if (!close_val && ((i > iStart2 && i < iFinish2) || open_val))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(),
				sprintf("%s:\n    唉，Ban đầu năm mới là một ngày tiệc tùng phổ thông, nhưng con thú năm mới, bị niêm phong hàng trăm năm trước, thoát khỏi rắc rối và gây rắc rối khắp các thành phố và làng tập s ự trên cả nước. Đã đến lúc các chiến binh của các bạn nhặt pháo và trục xuất con quái thú năm mới một cách dũng cảm! Giờ thì những người đốt pháo ở khắp cả nước. Đi tìm những người đốt pháo hoa này và dùng chúng để trục xuất con quái thú năm mới, và cho chúng ta một phong bì đỏ hạnh phúc.Xuân Thu！\n"
					ESC "Năm mới có sừng niên thú\ntalk %x# welcome.61\n"
					ESC "Rời khỏi", me->get_name(), getoid(me)));
		break;
	case 61:
		i = time();
		if (!close_val && ((i > iStart2 && i < iFinish2) || open_val))
		{
			if (!objectp(item = present("年兽的角", who, 1, MAX_CARRY)))
			{
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(),
					sprintf("%s:\n    你身上没有年兽的角呀！现在各国到处都是年兽，你赶快去找爆竹驱赶年兽，然后拿年兽身上的角回来给我吧！\n"
						ESC "Rời khỏi", me->get_name(), getoid(me)));
			}
			else
			{
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(),
					sprintf("%s:\n    哈哈，看来年兽又一次被我们赶走了！你想要红包吗?现在是新春佳节，想要红包的话你要跟我说什么话呀?呵呵~~\n"
						ESC "恭喜发财\ntalk %x# welcome.62\n"
						ESC "福如东海\ntalk %x# welcome.62\n"
						ESC "万事如意\ntalk %x# welcome.62\n"
						ESC "圣诞快乐\ntalk %x# welcome.63\n", me->get_name(), getoid(me), getoid(me), getoid(me), getoid(me)));
			}
		}
		break;
	case 62:
		i = time();
		if (!close_val && ((i > iStart2 && i < iFinish2) || open_val))
		{


			if (!objectp(item = present("年兽的角", who, 1, MAX_CARRY)))
			{
				send_user(who, "%c%s", '!', "您身上没有年兽的角");
				return;
			}
			item2 = new ("/item/04/0434");    // 给红包
			if (item2)
			{
				if (USER_INVENTORY_D->can_carry(who, item2) >= 1)
				{
					p = item2->move(who, -1);
					item2->add_to_user(p);
				}
				else
				{
					destruct(item2);
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(),
						sprintf("%s:\n    你身上现在连红包都放不下了，想领红包的话快去腾个空位出来吧！\n"
							ESC "确定", me->get_name(), getoid(me)));
					return;
				}
			}
			// 收去年兽的角一只
			item->add_amount(-1);
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(),
				sprintf("%s:\n    哈哈哈，来来来，我给你红包.我神仙爷爷也祝愿你在新的一年可以万事如意.\n"
					ESC "确定", me->get_name(), getoid(me)));
			send_user(who, "%c%s", '!', "获得红包");
		}
		break;
	case 63:
		i = time();
		if (!close_val && ((i > iStart2 && i < iFinish2) || open_val))
		{


			if (!objectp(item = present("年兽的角", who, 1, MAX_CARRY)))
			{
				send_user(who, "%c%s", '!', "您身上没有年兽的角");
				return;
			}
			item2 = new ("/item/04/0434");    // 给红包
			if (item2)
			{
				if (USER_INVENTORY_D->can_carry(who, item2) >= 1)
				{
					p = item2->move(who, -1);
					item2->add_to_user(p);
				}
				else
				{
					destruct(item2);
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(),
						sprintf("%s:\n    你身上现在连红包都放不下了，想领红包的话快去腾个空位出来吧！\n"
							ESC "确定", me->get_name(), getoid(me)));
					return;
				}
			}
			// 收去年兽的角一只
			item->add_amount(-1);
			//item->remove_from_user();
			//destruct(item);
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(),
				sprintf("%s:\n    现在可不是圣诞节哦，新年说错话本来是没有红包的.但是我希望新年大家都开开心心，这次也把红包给你吧！\n"
					ESC "确定", me->get_name(), getoid(me)));
			send_user(who, "%c%s", '!', "获得红包");
		}
		break;
	case 70:
		cmd1 = sprintf("talk %x# welcome.71\n", getoid(me));
		cmd2 = sprintf("talk %x# welcome.72\n", getoid(me));
		result = get_name() + ":\n    Bạn có thể lợi dụng "HIR "điểm Công Đức hoặc Cống hiến Môn phái"NOR " để lấy thêm thời gian nhân đôi.Nhưng "HIR " mỗi lần nhiều nhất chỉ có thể đổi 3 thứ"NOR ". Đừng bỏ qua cơ hội này nha !\n";
		result += ESC "3 điểm Công đức đổi 1 giờ nhân đôi kinh nghiệm\n" + cmd1;
		result += ESC "3 điểm cống hiến Môn phái đổi 1 giờ nhân đôi kinh nghiệm\n" + cmd2;
		result += ESC "Rời khỏi\nCLOSE\n";
		send_user(who, "%c%c%w%s", ':', 3, 6008, result);
		break;
	case 71:
	case 72:
		i = gone_time(who->get_login_time());
		if (who->get_save_2("double_time.freeze") > 0)
		{
			send_user(who, "%c%c%w%s", ':', 3, 6008,
				sprintf("%s:\n     Của bạn "HIR "Nhân đôi kinh nghiệm đã đóng băng"NOR "， hãy giải trừ rồi lại nhân đôi kinh nghiệm\n"
					ESC "Đóng\nCLOSE\n", me->get_name()));
			return;
		}
		if (who->get_online_rate() == 50)
		{
			send_user(who, "%c%s", '!', "疲劳游戏时间禁止领取双倍经验.");
			return;
		}
		else if (who->get_online_rate() == 0)
		{
			send_user(who, "%c%s", '!', "不健康游戏时间禁止领取双倍经验.");
			return;
		}
		if (who->get_save_2("double_time.time3") >= 3)
		{
			send_user(who, "%c%c%w%s", ':', 3, 6008,
				sprintf("%s:\n     Bạn không còn thừa thời gian nhân đôi, lần sau lại đến !\n"
					ESC "Đóng\nCLOSE\n", me->get_name()));
			return;
		}
		if (flag == 71)
		{
			if (who->get_bonus() / 10 < 3)
			{
				send_user(who, "%c%c%w%s", ':', 3, 6008,
					sprintf("%s:\n     điểm Công đức của ngươi không đủ 3 điểm !\n"
						ESC "Đóng\nCLOSE\n", me->get_name()));
				return;
			}
			who->add_bonus(-30);
		}
		else
		{
			if (who->get_fam_contribute() < 3)
			{
				send_user(who, "%c%c%w%s", ':', 3, 6008,
					sprintf("%s:\n     điểm Cống hiến Môn Phái của ngươi không đủ 3 điểm\n"
						ESC "Đóng\nCLOSE\n", me->get_name()));
				return;
			}
			who->set_fam_contribute(who->get_fam_contribute() - 3);
		}
		who->add_save_2("double_time.time3", 1);
		p = 3600;
		if (i + who->get_game_time() < who->get_double_time())
			who->set_double_time(who->get_double_time() + p);
		else
			who->set_double_time(i + who->get_game_time() + p);
		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, 0001, "Viện Trợ trò chơi");
		send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "Thời Gian Nhân Đôi");
		"/sys/task/task"->send_task_intro(who, 1, 1, 1);
		"/quest/help"->send_help_tips(who, 3);
		"/sys/task/task"->send_task_intro(who, 1, 1, 1);
		p = who->get_save_2("double_time.time3");
		if (p < 3)
			result = sprintf(get_name() + ":\n    Bạn đã đổi thành công 1 giờ nhân đôi kinh nghiệm, bạn còn thừa "HIR "%d giờ"NOR " hãy tận dụng đi !\n", 3 - p);
		else
			result = get_name() + ":\n    Bạn đã đổi thành công 1 giờ nhân đôi kinh nghiệm, hãy tận dụng đi !\n";
		result += ESC "Rời khỏi\nCLOSE\n";
		send_user(who, "%c%c%w%s", ':', 3, 6008, result);
		break;
	case 80:
		send_user(who, "%c%c%w%s", ':', 3, 6008,
			sprintf(" %s :\n VIP, viết tắt trong tiếng Anh là Very Important Person, có nghĩa là người rất quan trọng, thường gọi là “người quan trọng”.Đừng hỏi ta sao lại biết tiếng Anh, ta là thần tiên mà, trên biết thiên văn, dưới biết địa lý, biết cả thời xưa thời nay biết trong lẫn ngoài, biết được quá khứ và tương lai.Trong thời đại chiến quốc phân tranh này, ngươi có phải là VIP tôn quý nhất không?\n"
				ESC "VIP có ích lợi gì?\ntalk %x# welcome.81\n"
				ESC "Ta làm thế nào để trở thành VIP?\ntalk %x# welcome.82\n"
				ESC "Hỏi ta thời hạn VIP\ntalk %x# welcome.83\n"
				ESC "Đóng\nCLOSE\n", me->get_name(), getoid(me), getoid(me), getoid(me)));

		break;
	case 100:
		if (who->get_online_rate() == 50)
		{
			send_user(who, "%c%s", '!', "Thời gian ngừng trò chơi cấm phát ra giá lạnh kinh nghiệm kép.");
			return;
		}
		else if (who->get_online_rate() == 0)
		{
			send_user(who, "%c%s", '!', "Không lành mạnh thời gian trò chơi cấm xóa giá lạnh kinh nghiệm đôi.");
			return;
		}
		result = sprintf(" %s :\n Ngươi có chắc chắn muốn giải trừ 2 lần Kinh nghiệm đóng băng không?Đương nhiên, ngươi muốn đóng băng 2 lần kinh ngiệm có thể đến gặp ta bất cứ lúc nào.\n", get_name());
		result += ESC "Xin giúp ta giải trừ Thời gian nhân đôi Kinh nghiệm đang đóng băng\n" + sprintf("talk %x# welcome.101\n", getoid(me));
		result += ESC "Rời khỏi\nCLOSE\n";
		send_user(who, "%c%c%w%s", ':', 3, 6008, result);
		break;
	case 101:
		if (who->get_online_rate() == 50)
		{
			send_user(who, "%c%s", '!', "Thời gian ngừng trò chơi cấm phát ra giá lạnh kinh nghiệm kép.");
			return;
		}
		else if (who->get_online_rate() == 0)
		{
			send_user(who, "%c%s", '!', "Không lành mạnh thời gian trò chơi cấm xóa giá lạnh kinh nghiệm đôi.");
			return;
		}

		if (who->get_save_2("double_time.freeze") > 0)
		{
			//
			i = gone_time( who->get_login_time() );
			if (i + who->get_game_time() < who->get_double_time())
				who->set_double_time(who->get_double_time() + who->get_save_2("double_time.freeze"));
			else
				who->set_double_time(i + who->get_game_time() + who->get_save_2("double_time.freeze"));
			//

			who->set_save_2("double_time.freeze", 0);
			result = get_name() + sprintf(" :\n Ngươi đã thành công thời gian giải trừ 2 lần Kinh nghiệm đóng băng, ngươi hiện tại đã nhận được thời gian 2 lần Kinh nghiệm "HIR " %d giây "NOR " , nếu ngươi muốn đóng băng 2 lần kinh nghiệm có thể đến gặp ta bất cứ lúc nào.\n", who->get_double_time() - i - who->get_game_time());
			result += ESC "Rời khỏi\nCLOSE\n";
			send_user(who, "%c%c%w%s", ':', 3, 6008, result);
			send_user(who, "%c%c%c%w%s", 0x51, 1, 1, 0001, "Viện Trợ trò chơi");
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "Thời Gian Nhân Đôi");
			"/sys/task/task"->send_task_intro(who, 1, 1, 1);
		}
		break;
	case 102:	//	战国宝典的领取操作
		if (objectp(item = "/quest/zg_dict"->want_an_zgdict(me, who))) {
			p = item->move(who, -1);
			item->add_to_user(p);
			send_user(who, "%c%s", '!', "Ngươi đã giành được kho báu của thời kỳ của hiệp ước.");
		}
		break;
	case 90:
		result = sprintf(" %s :\n    Ngươi có muốn đóng băng thời gian 2 lần Kinh nghiệm của ngươi không?Một khi thời gian 2 lần Kinh nghiệm của ngươi bị đóng băng, như vậy ngươi sẽ không cách nào để nhận được thời gian 2 lần Kinh nghiệm mới.Sau khi thời gian 2 lần Kinh nghiệm bị đóng băng, nếu cần, ngươi có thể đến chỗ ta để giải trừ 2 lần Kinh nghiệm đóng băng bất cứ lúc nào. Nhưng ngươi phải nhớ, sau khi thời gian 2 lần Kinh nghiệm đóng băng, ta chỉ có thể giúp ngươi "HIR "lưu giữ ngày Chủ nhật mỗi tuần thời gian là 23:59 "HIR "phút, một khi vượt quá thời gian này, thời gian đóng băng sẽ hoàn "HIR "toàn bị xóa sạch.\n", get_name());
		result += ESC "Xin giúp ta đóng băng thời gian 2 lần Kinh nghiệm\n" + sprintf("talk %x# welcome.91\n", getoid(me));
		result += ESC "Rời khỏi\nCLOSE\n";
		send_user(who, "%c%c%w%s", ':', 3, 6008, result);
		break;
	case 91:
		i = gone_time(who->get_login_time());
		if (i + who->get_game_time() < who->get_double_time())
		{
			who->set_save_2("double_time.freeze", who->get_double_time() - i - who->get_game_time());
			result = get_name() + sprintf(" :\n Ngươi đã thành công trong việc đóng băng thời gian 2 lần Kinh nghiệm "HIR " %d giây "NOR ", nếu cần giải trừ 2 lần Kinh nghiệm đóng băng thì cứ đến tìm ta bất cứ lúc nào.\n", who->get_double_time() - i - who->get_game_time());
			result += ESC "Rời khỏi\nCLOSE\n";
			send_user(who, "%c%c%w%s", ':', 3, 6008, result);

			who->set_double_time(0);
			//who->set_save_2("double_time.time", 0);
			who->set_save_2("double_time.time1", 0);

			send_user(who, "%c%c%c%w%s", 0x51, 1, 1, 0001, "Viện Trợ trò chơi");
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "Thời Gian Nhân Đôi");
			"/sys/task/task"->send_task_intro(who, 1, 1, 1);
		}
		break;
	case 81:
		send_user(who, "%c%c%w%s", ':', 3, 6008,
			sprintf(" %s :\n VIP mà, phải đặc biệt chứ.\n Đầu tiên, trong suốt thời gian trở thành VIP có thể trò chuyện trên kênh của VIP để mọi người thấy được lời nói của mình quan trọng thế nào.\n Kế tiếp, còn được nhận Nhân Đôi Kinh Nghiệm trong thời gian này; gia tăng cả sức Tấn Công và Phòng Thủ; giảm thời gian tái sử dụng của dược phẩm. Đã vậy còn được Miễn Phí 3 lần hồi sinh, sau khi sống lại sẽ hoàn toàn khỏe mạnh ngay.\n "
				NOR "Còn nữa nhé, có thể làm Nhiệm Vụ Sư Môn đến 20 lần mỗi ngày; điểm thưởng Tiềm năng từ nhiệm vụ Diệt Phạm của Sư Gia cũng tăng lên. Ở đâu có VIP là ở đó quan trọng, trong Nhóm có VIP sẽ tăng thêm kinh nghiệm tối đa cho mọi người.\n Ngoài ra, khi VIP sử dụng kỹ năng nghề nghiệp hay khảm nạm Tinh Thạch, Đoạn Thạch thì tỉ lệ thành công cũng rất cao!\n Ái chà, ta nói mệt rồi, để ta nghỉ ngơi chút đã…Lợi ích cụ thể hơn nữa thì ngươi tự đi mà hỏi lấy đi.\n"
				ESC "Phải làm thế nào để trở thành VIP?\ntalk %x# welcome.82\n"
				ESC "Rời khỏi\nCLOSE\n", me->get_name(), getoid(me)));

		break;
	case 82:
		send_user(who, "%c%c%w%s", ':', 3, 6008,
			sprintf(" %s :\n Muốn trở thành VIP à? Ngươi có thể đến mạng lưới quan phủ mua đĩnh vàng.Trong danh mục gói phục vụ VIP châu báu chiến quốc chọn mua gói VIP, thì ID và vai trò của ngươi sẽ được gắn liền với nhau.\n Nhưng cần chú ý, đĩnh vàng có trong tài khoản , nhưng VIP gắn liền với ID vai trò mua hàng, nhưng không được gắn kết sai chỗ.\n"
				ESC "Dò hỏi thời gian gắn liền VIP của ta\ntalk %x# welcome.83\n"
				ESC "Đóng\nCLOSE\n", me->get_name(), getoid(me)));

		break;
	case 83:
		if (!who->get_vip())
		{
			send_user(who, "%c%s", ':', sprintf(" %s \n Ngươi hình như không phải là hội viên VIP.\n"ESC"Rời khỏi", me->get_name()));
			return;
		}
		iVipTime = who->get_save_2("vip_package.time");
		mxTime = localtime(iVipTime);
		send_user(who, "%c%c%w%s", ':', 3, 6008,
			sprintf("%s:\n     Hoan nghênh, bạn là VIP hiệu quả đến %d-%02d-%02d %02d:%02d:%02d， có cần ta giúp gì không ?\n"
				ESC "Lấy VIP nhận nhân đôi kinh nghiệm\ntalk %x# welcome.84\n"
				ESC "Đóng\nCLOSE\n", me->get_name(), mxTime[TIME_YEAR], mxTime[TIME_MON] + 1, mxTime[TIME_MDAY], mxTime[TIME_HOUR], mxTime[TIME_MIN], mxTime[TIME_SEC], getoid(me)));

		break;
	case 84:
		if (!who->get_vip())
		{
			send_user(who, "%c%s", ':', sprintf(" %s \n Ngươi hình như không phải là hội viên VIP.\n"ESC"Rời khỏi", me->get_name()));
			return;
		}
		x = who->get_save_2("vip_package.doubles");
		y = x / 2;
		z = x % 2;
		if (z)
			cmd1 = sprintf("%s:\n     Bạn có thể nhận nhân đôi kinh nghiệm còn "HIR "%d giờ 30 phút"NOR ".Muốn nhận nhân đôi kinh nghiệm không ?\n", me->get_name(), y);
		else
			cmd1 = sprintf("%s:\n     Bạn có thể nhận nhân đôi kinh nghiệm còn "HIR "%d giờ"NOR ".Muốn nhận nhân đôi kinh nghiệm không ?\n", me->get_name(), y);

		send_user(who, "%c%c%w%s", ':', 3, 6008,
			sprintf(cmd1 +
				ESC "Nhận 30 phút VIP nhân đôi kinh nghiệm\ntalk %x# welcome.85\n"
				ESC "Nhận 1 giờ VIP nhân đôi kinh nghiệm\ntalk %x# welcome.86\n"
				ESC "Nhận 2 giờ VIP nhân đôi kinh nghiệm\ntalk %x# welcome.87\n"
				ESC "Đóng\nCLOSE\n", getoid(me), getoid(me), getoid(me)));
		break;
	case 87:
		p += 2;
	case 86:
		p += 1;
	case 85:
		p += 1;
		if (!who->get_vip())
		{
			send_user(who, "%c%s", ':', sprintf(" %s \n Ngươi hình như không phải là hội viên VIP.\n"ESC"Rời khỏi", me->get_name()));
			return;
		}
		if (who->get_save_2("vip_package.doubles") < p)
		{
			send_user(who, "%c%s", ':', sprintf("%s\n    Thời gian nhân đôi kinh nghiệm VIP đã dùng rồi\n"ESC"Rời khỏi", me->get_name()));
			return;
		}
		i = gone_time(who->get_login_time());
		x = (time() - 4 * 24 * 3600 + 8 * 3600) / (7 * 24 * 3600);
		if (who->get_save_2("double_time.week") != x)
		{
			who->set_save_2("double_time.week", x);
			who->set_save_2("double_time.time", 0);		//双
			who->set_save_2("double_time.time1", 0);	//战国令
			who->set_save_2("double_time.time2", 0);	//战国号角
			who->set_save_2("double_time.time3", 0);
		}
		who->add_save_2("vip_package.doubles", -p);
		send_user(who, "%c%c%w%s", ':', 3, 6008,
			sprintf("%s:\n     Bạn nhận %d phút nhân đôi kinh nghiệm VIP, hãy tận dụng !\n"
				ESC "Đóng\nCLOSE\n", me->get_name(), p * 30));

		p *= 1800;
		if (i + who->get_game_time() < who->get_double_time())
			who->set_double_time(who->get_double_time() + p);
		else
			who->set_double_time(i + who->get_game_time() + p);
		send_user(who, "%c%c%c%w%c", 0x51, 1, 1, 0001, 0);
		send_user(who, "%c%c%c%w%w%c", 0x51, 1, 2, 0001, 1, 0);
		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, 0001, "Viện Trợ trò chơi");
		send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "Thời Gian Nhân Đôi");
		"/quest/help"->send_help_tips(who, 3);
		"/sys/task/task"->send_task_intro(who, 1, 1, 1);
		break;
	case 88:
		send_user(who, "%c%c%w%s", ':', 3, 6008,
			sprintf(" %s :\n Để đáp lễ người chơi cũ và giúp đỡ người chơi mới của Chiến Quốc Loạn Thế Anh Hùng, tiên nhân ta đặc biệt tổ chức gói dùng thử VIP "HIR "Tặng"NOR ". Người chơi chỉ cần có đẳng cấp đủ 30 cấp hoặc hơn, đều có thể nhận được gói dùng thử "HIR "VIP "NOR ".Đương nhiên, vì đây là gói dùng thử, nên sẽ có sự khác biệt với gói VIP chính hiệu.\n 1, thời gian sử dụng gói dùng thử chỉ có "HIR "3 ngày(tính từ lúc nhận được).\n 2, trong thời gian 3 ngày sử dụng gói dùng thử có tác dụng, ngươi có thể tích luỹ thời gian 2 lần kinh nghiệm ngoài hạn định là 4 giờ "HIR ".\n 3, Khi chế tạo kỹ năng cuộc sống thành phẩm, trang bị tinh luyện và rèn trang bị, "HIR "Tỉ suất thành công không thể tăng quá 5％.\n"
				ESC HIY"Nhận được gói dùng thử VIP\ntalk %x# welcome.89\n"
				ESC "Đóng\nCLOSE\n", me->get_name(), getoid(me)));
		break;
	case 89:
		"item/sell/0061"->give_trial_vip(me, who);
		break;
	case 99:
		iTime = time();
		cmd1 = sprintf("talk %x# welcome.1\n", getoid(me));
		cmd2 = sprintf("talk %x# welcome.3\n", getoid(me));
		cmd3 = sprintf("talk %x# welcome.20\n", getoid(me));
		cmd4 = sprintf("talk %x# welcome.30\n", getoid(me));
		cmd5 = sprintf("talk %x# welcome.40\n", getoid(me));
		cmd6 = sprintf("talk %x# welcome.70\n", getoid(me));
		cmd7 = sprintf("talk %x# welcome.100\n", getoid(me));
		cmd8 = sprintf("talk %x# welcome.90\n", getoid(me));
		if (get_z(who) == 80)
			result = sprintf(" %s :\n Đây là Chu Quốc, ngươi đã từng đến chưa?Chỗ của ta là nơi trung tâm của Chu Quốc, thông suốt 4 bên, đi đâu đếu phải đi ngang đây.Ngươi hỏi ta nơi đây tên gì?Thiên đàn, có biết không?Đây là tên gọi rất thích hợp!\n", get_name());
		else
			result = sprintf(" %s :\n Để đi đến Tân Thủ Thôn của người chơi mới đều phải đi qua chỗ của ta, eh, ngươi mới đến chỗ chúng ta, chắc là sẽ không biết gì rồi, có cần ta giới thiệu không?\n", get_name());
		if (z == 1 || z == 4 || z == 7)
		{
			if (who->get_legend(TASK_NEWBIE_00, 1) && !who->get_legend(TASK_NEWBIE_00, 2))
				result = result + ESC + HIY + "Sứ Mệnh Đưa Thư\n" + cmd1;
			if (who->get_legend(TASK_NEWBIE_00, 3) && !who->get_legend(TASK_NEWBIE_00, 5))
				result = result + ESC "交出木剑\n" + sprintf("talk %x# welcome.5\n", getoid(me));
			if (!who->get_legend(TASK_48, 1))
				result = result + ESC + HIY + "Thủ Thuật Nhỏ\n" + cmd3;
		}
		else
		{
			//			if (who->get_level()>=30&&(!who->get_legend(TASK_NEWBIE_00, 9)||!who->get_legend(TASK_NEWBIE_00, 10))&& get_z(who) == 80 )
			//				result = result + ESC +HIY+ "拜访师爷\n" + sprintf("talk %x# welcome.30\n", getoid( me ));
			//			if (who->get_level()>=10&&(!who->get_legend(TASK_NEWBIE_00, 11)||!who->get_legend(TASK_NEWBIE_00, 12)) && get_z(who) == 80)
			//				result = result + ESC +HIY+ "王捕头的美差\n" + sprintf("talk %x# welcome.32\n", getoid( me ));
			//			if (who->get_level()>=30&&(!who->get_legend(TASK_NEWBIE_00, 13)||!who->get_legend(TASK_NEWBIE_00, 14))&& get_z(who) == 80 )
			//				result = result + ESC +HIY+ "找尉迟老镖头谈谈\n" + sprintf("talk %x# welcome.34\n", getoid( me ));
			if (who->get_legend(TASK_NEWBIE_01, 23) && !who->get_legend(TASK_NEWBIE_01, 24) && get_z(who) == 80)
				result = result + ESC + HIY + "锻炼的机会\n" + sprintf("talk %x# welcome.36\n", getoid(me));
			if (who->get_level() >= 40 && !who->get_legend(TASK_40, 5))
				result = result + ESC + HIY + "Truyền thuyết của Kiến Bang\n" + sprintf("talk %x# welcome.50\n", getoid(me));
		}
		if (is_holiday()) result += sprintf(ESC "我想领取礼物\n%s\n", cmd4);
		result += ESC "Nhận được thời gian gấp bội\n" + cmd5;
		//                result += ESC "换取额外的双倍时间\n" + cmd6 ;
		i = gone_time(who->get_login_time());
		if (who->get_save_2("double_time.freeze") > 0)
			result += ESC + HIY + "Xin giải trừ đóng băng thời gian gấp bội của ta\n" + cmd7;
		else
			if (i + who->get_game_time() < who->get_double_time())
				result += ESC HIY"Đóng băng thời gian Kinh nghiệm gấp bội\n" + cmd8;
		i = time();
		if (!close_val && ((i > iStart2 && i < iFinish2) || open_val))
			result += sprintf(ESC "Tết Âm Lịch của Thần Tiên Gia Gia\ntalk %x# welcome.60\n", getoid(me));
		result += sprintf(ESC HIG"VIP là gì?\ntalk %x# welcome.80\n", getoid(me));
		result += sprintf(ESC HIG"Nhận được thời gian gấp bội VIP\ntalk %x# welcome.84\n", getoid(me));
		result += sprintf(ESC HIY"Gói dùng thử VIP\ntalk %x# welcome.88\n", getoid(me));
		result += sprintf(ESC HIC"Nhập Gift Code nhận quà\ntalk %x# welcome.12021\n", getoid(me));

		if (iTime > BatDau && iTime < KetThuc)
		{
			result += sprintf(ESC HIC"Nhận Quà Tết Nguyên Đán\ntalk %x# welcome.2021\n", getoid(me));
			result += sprintf(ESC HIY"Nhiệm vụ tiêu diệt quái vật\ntalk %x# welcome.2121\n", getoid(me));
			result += sprintf(ESC HIY"Đổi Sừng Niên Thú lấy quà\ntalk %x# welcome.2321\n", getoid(me));
		}

		if (iTime < KetThuc && who->get_save("distanceTime") >= 400000)
		{
			result += sprintf(ESC HIY"Nhận Quà Trở Về\ntalk %x# welcome.3000\n", getoid(me));
		}

		//result += sprintf(ESC HIC"Nhập Code Tân Thủ Chiến Quốc\ntalk %x# welcome.1000\n", getoid(me));
		//                result += sprintf(ESC "Nhận lãnh Chiến Quốc Bảo Điển\ntalk %x# welcome.102\n",getoid(me));
		result += ESC "Rời khỏi\nCLOSE\n";

		send_user(who, "%c%s", ':', result);
		break;
	case 1000:
		iTime = time();
		if (iTime > BatDau && iTime < KetThuc)
		{
			if (who->get_fam_name() != "" && who->get_level() <= 40)
			{
				send_user(who, "%c%c%w%s", ':', 3, 6008,
					sprintf(" %s :\n Chỉ cần đẳng cấp của ngươi dưới 40 và Đã gia nhập Môn phái thì ta có thể hỗ trợ cho ngươi ! Nào, muốn nhập Code Tân Thủ không ?\n"
						ESC HIY"Nhập code Tân Thủ\ntalk %x# welcome.1001\n"
						ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me)));
				return;
			}
			else if (who->get_fam_name() == "")
			{
				send_user(who, "%c%c%w%s", ':', 3, 6008,
					sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code Tân Thủ !\n"
						ESC HIY"Ta hiểu rồi\ntalk %x# welcome.1002\n"
						ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me)));
				return;
			}
			else if (who->get_level() > 40)
			{
				send_user(who, "%c%c%w%s", ':', 3, 6008,
					sprintf(" %s :\n Trên cấp 40 không thể nhập Code Tân Thủ !\n"
						ESC HIY"Ta hiểu rồi\ntalk %x# welcome.1002\n"
						ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me)));
				return;
			}
		}
		else if (iTime < BatDau || iTime > KetThuc)
		{
			send_user(who, "%c%c%w%s", ':', 3, 6008,
				sprintf(" %s :\n Bây giờ không phải thời gian nhập Code Tân Thủ !\n"
					ESC HIY"Ta hiểu rồi\ntalk %x# welcome.1002\n"
					ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me)));
			return;
		}
		break;
	case 1001:
		iTime = time();
		if (iTime > BatDau && iTime < KetThuc)
		{
			if (who->get_fam_name() != "" && who->get_level() <= 40)
			{
				send_user(who, "%c%c%d%s", '?', 16, 15, "Xin nhập mã Code Tân Thủ    (Tối đa 15 ký tự):\n" ESC "codetanthu + %s\n");
				return;
			}
			else if (who->get_fam_name() == "")
			{
				send_user(who, "%c%c%w%s", ':', 3, 6008,
					sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code Tân Thủ !\n"
						ESC HIY"Ta hiểu rồi\ntalk %x# welcome.1002\n"
						ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me)));
				return;
			}
			else if (who->get_level() > 40)
			{
				send_user(who, "%c%c%w%s", ':', 3, 6008,
					sprintf(" %s :\n Trên cấp 40 không thể nhập Code Tân Thủ !\n"
						ESC HIY"Ta hiểu rồi\ntalk %x# welcome.1002\n"
						ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me)));
				return;
			}
		}
		else if (iTime < BatDau || iTime > KetThuc)
		{
			send_user(who, "%c%c%w%s", ':', 3, 6008,
				sprintf(" %s :\n Bây giờ không phải thời gian nhập Code Tân Thủ !\n"
					ESC HIY"Ta hiểu rồi\ntalk %x# welcome.1002\n"
					ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me)));
			return;
		}
		break;

	case 1002:
		break;

	case 2021:
		iTime = time();
		if (iTime > BatDau && iTime < KetThuc)
		{
			EVENT_TET->send_gift_to_user(me, who);
		}
		else if (iTime < BatDau || iTime > KetThuc)
		{
			send_user(who, "%c%c%w%s", ':', 3, 6008,
				sprintf(" %s :\n Bây giờ không phải thời gian nhận quà !\n"
					ESC HIY"Ta hiểu rồi\ntalk %x# welcome.1002\n"
					ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me)));
			return;
		}
		break;
	case 2121:
		iTime = time();
		if (iTime > BatDau && iTime < KetThuc)
		{
			EVENT_TET->send_quest_to_user(me, who);
		}
		else if (iTime < BatDau || iTime > KetThuc)
		{
			send_user(who, "%c%c%w%s", ':', 3, 6008,
				sprintf(" %s :\n Thời gian sự kiện đã kết thúc !\n"
					ESC HIY"Ta hiểu rồi\ntalk %x# welcome.1002\n"
					ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me)));
			return;
		}
		break;

	case 2221:
		iTime = time();
		if (iTime > BatDau && iTime < KetThuc)
		{
			EVENT_TET->send_gift_of_task(me, who);
		}
		else if (iTime < BatDau || iTime > KetThuc)
		{
			send_user(who, "%c%c%w%s", ':', 3, 6008,
				sprintf(" %s :\n Thời gian sự kiện đã kết thúc !\n"
					ESC HIY"Ta hiểu rồi\ntalk %x# welcome.1002\n"
					ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me)));
			return;
		}
		break;

	case 2321:
		iTime = time();
		if (iTime > BatDau && iTime < KetThuc)
		{
			EVENT_TET->send_gift_nienthu(me, who);
		}

		else if (iTime < BatDau || iTime > KetThuc)
		{
			send_user(who, "%c%c%w%s", ':', 3, 6008,
				sprintf(" %s :\n Thời gian sự kiện đã kết thúc !\n"
					ESC HIY"Ta hiểu rồi\ntalk %x# welcome.1002\n"
					ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me)));
			return;
		}
		break;

	case 12021:
		send_user(who, "%c%c%d%s", '?', 16, 15, "Nhập mã code để nhận thưởng：\n" ESC"nhanthuongts @ %s " + who->get_number() + "\n");

		break;

	case 2122:
		iTime = time();
		if (iTime > BatDau && iTime < KetThuc)
		{
			who->set_save_2("task.TetStatus", 1);
			notify(HIY"Tiêu diệt 50 quái vật");

		}
		else if (iTime < BatDau || iTime > KetThuc)
		{
			send_user(who, "%c%c%w%s", ':', 3, 6008,
				sprintf(" %s :\n Thời gian sự kiện đã kết thúc !\n"
					ESC HIY"Ta hiểu rồi\ntalk %x# welcome.1002\n"
					ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me)));
			return;
		}
		break;
	case 3000:

		if (who->get_save("distanceTime") >= 400000)
		{
			if (USER_INVENTORY_D->get_free_count(who) < 2)
			{
				notify("Hành trang không đủ 2 chỗ trống");
				return;
			}

			if (sizeof_inventory(who, 2, MAX_CARRY) >= MAX_CARRY)
			{
				send_user(who, "%c%s", '!', "Hành trang trên người ngươi không đủ 2 chỗ, lần sau nhận thưởng phải chú ý");
				return;
			}


			item = new("/item/tuiquatanthu/comeback");
			item->set_no_give(1);
			item->set_no_sell(1);

			p = item->move(who, -1);
			item->add_to_user(p);

			who->delete_save("distanceTime");
		}
		
		break;

	}
}


int is_holiday()
{
	return 0;
}

int set_newyear(int open, int close)
{
	open_val = open;
	close_val = close;
	return 1;
}
