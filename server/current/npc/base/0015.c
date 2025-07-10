
// 自动生成：/make/npc/make0015

#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <equip.h>

inherit OFFICER;

// 函数：小贩识别
int is_seller() { return 1; }

// 有自己的do_look函数
int is_self_look() { return 1; }

void do_info();

// 函数：获取人物造型
int get_char_picid() { return 7415; }
void do_exchange(string sArg);
void do_inputx(string sArg);
void do_welcome(string arg);

// 函数：构造处理
void create()
{
	set_name("Chủ Tửu Lâu");

	set_2("talk", (["info":( : do_info:),
					  "do_exchange":( : do_exchange:),
						   "inputx":( : do_inputx:),
						  "welcome":( : do_welcome:),
	]));
	set_2("good", (["01":"/item/31/3150",
					  "02":"/item/31/3151",
					  "03":"/item/31/3152",
					  "04":"/item/32/3280",
					  "05":"/item/32/3281",
					  "06":"/item/32/3282",
					  "07":"/item/32/3283",
					  "08":"/item/32/3284",
					  "09":"/item/32/3285",
					  "10":"/item/stuff/0219",
					  "11":"/item/stuff/0220",
					  "12":"/item/stuff/0221",
					  "13":"/item/stuff/0222",
					  "14":"/item/stuff/0223",
					  "15":"/item/stuff/0224",
					  "16":"/item/stuff/0159",
					  "17":"/item/32/3204",
	]));

	//        set("level",5);
	//        set("legend",({32*2+12,32*40+22}));
	set("mpLegend", ([5:({32 * 2 + 18, 32 * 40 + 22}),
						0:({
							  32 * 49 + 18,
						  })]));
	set("mpLegend2", ([5:({
							 32 * 2 + 20,
						 }),
						 0:({
							   32 * 49 + 20,
						   })]));
	setup();
}

// 函数：对话处理
void do_look(object who)
{
	object item;
	object me = this_object(), map;
	int id = getoid(me);
	string tmp;
	"/quest/help"->send_help_tips(who, 53);
	tmp = "";

	if (who->get_legend(TASK_49, 8) && !who->get_legend(TASK_49, 9))
		tmp += sprintf(ESC + HIY + "Vòng tay bị mất\ntalk %x# welcome.1\n", id);
	if (who->get_level() >= 5 && !who->get_legend(TASK_NEWBIE_02, 18))
		tmp += sprintf(ESC + HIY + "Nguyên liệu thô để làm rượu\ntalk %x# welcome.3\n", id);
	if (who->get_legend(TASK_NEWBIE_02, 19) && !who->get_legend(TASK_NEWBIE_02, 20))
		tmp += sprintf(ESC + HIY + "Nguyên liệu thô để làm rượu\ntalk %x# welcome.3\n", id);
	if (who->get_level() >= 5 && !who->get_legend(TASK_40, 22))
		tmp += sprintf(ESC + HIY + "Nguồn thực phẩm\ntalk %x# welcome.6\n", id);
	if (!who->get_legend(TASK_49, 18))
		tmp += sprintf(ESC + HIY + "Một con thỏ nhỏ\ntalk %x# welcome.8\n", id);
	if (who->get_legend(TASK_49, 19) && !who->get_legend(TASK_49, 20))
		tmp += sprintf(ESC + HIY + "Một con thỏ nhỏ\ntalk %x# welcome.8\n", id);

	tmp += sprintf(ESC "Mua Thực phẩm\nlist %x#\n", id);
	tmp += sprintf(ESC "Tin đồn cửa hàng ở phố\ntalk %x# info\n", id);
	tmp += ESC "Rời khỏi\nCLOSE\n";
	send_user(who, "%c%s", ':', " " + get_name() + " :\n " + "/quest/word"->get_normal_word(this_object()) + "\n Khách quan, cần đổi gì không?\n" + tmp);
}

// 函数：住宿处理
void do_info()
{
	object me, who;
	string result, info;
	me = this_object();
	who = this_player();
	TASK_MASTER_D->do_info(me, who);
}

void do_exchange(string sArg)
{
	TASK_COLLECT_D->do_exchange(sArg, 0015);
}

void do_inputx(string sArg)
{
	object me, who;
	me = this_object();
	who = this_player();
	TASK_COLLECT_D->do_inputx(me, who, sArg, 0015);
}

void do_welcome(string arg)
{
	object me = this_object();
	__FILE__->do_welcome2(me, arg);
}

void do_welcome2(object me, string arg)
{
	int flag, date, status, p, z, x, y, i;
	object who, obj, item;
	string cmd1, cmd2, cmd3, cmd4, cmd5, result;
	who = this_player();
	flag = to_int(arg);
	who->set_time("talk", 0);
	switch (flag)
	{
	case 1:
		if (who->get_legend(TASK_49, 8) && !who->get_legend(TASK_49, 9))
			send_user(who, "%c%s", ':', sprintf("%s\n    Thất quốc phân tranh, quần hùng tranh bá. Năm xưa trong lúc chạy trốn chiến loạn, cha mẹ tôi không may qua đời, mẹ tôi trước khi mất đã trao cho tôi một chiếc vòng tay, nhưng tôi đã làm mất nó, nghĩ lại thật đau lòng!\n    Bạn có sẵn lòng giúp tôi tìm lại Vòng tay bị mất không? Tôi nghe nói có người nhìn thấy nó ở khu vực tây bắc U Cốc. Nếu bạn có thể mang chiếc vòng tay nguyên vẹn trở về, tôi nhất định sẽ hậu tạ bạn. Sau khi tìm được vòng tay, hãy đưa nó cho Hướng dẫn viên môn phái trước, nghe nói họ có một kỹ năng khử trùng tuyệt diệu, chiếc vòng đã lưu lạc bên ngoài lâu như vậy, nên nhờ họ làm sạch một chút.\n" ESC "Chấp nhận\ntalk %x# welcome.2\n" ESC "Rời khỏi.", me->get_name(), getoid(me)));
		break;
	case 2:
		if (who->get_legend(TASK_49, 8) && !who->get_legend(TASK_49, 9))
		{
			if (TASK_LEGEND_D->can_task_add(who) != 1)
				return;
			who->delete_save_2("dssouzuo");
			who->delete_save_2("dssouzuo1");
			who->set_legend(TASK_49, 9);
			send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Tân Thủ Thôn");
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 117, "Vòng tay bị mất");
			send_user(who, "%c%s", '!', "Bạn đã chấp nhận nhiệm vụ " HIY "Vòng tay bị mất" NOR);
		}
		break;
	case 3:
		if (who->get_level() >= 5 && !who->get_legend(TASK_NEWBIE_02, 18))
			send_user(who, "%c%s", ':', sprintf("%s\n    Tôi từng nghe nói gần U Cốc và Thanh Khê có một loại ếch đốm, chúng sở hữu một thứ gọi là lúa mì, là nguyên liệu thượng hạng để酿 rượu. Tôi rất muốn dùng loại lúa mì này để酿 ra thứ rượu tuyệt hảo, giúp việc kinh doanh quán rượu nhỏ của tôi tốt hơn.\n    Nếu bạn có thể mang về cho tôi 3 cây lúa mì, tôi chắc chắn sẽ không để bạn thiệt thòi.\n" ESC "Chấp nhận\ntalk %x# welcome.4\n" ESC "Rời khỏi.", me->get_name(), getoid(me)));
		else if (who->get_legend(TASK_NEWBIE_02, 19) && !who->get_legend(TASK_NEWBIE_02, 20))
			send_user(who, "%c%s", ':', sprintf("%s\n    Không tệ! Không tệ! Quả nhiên bạn là người giữ chữ tín, nói là làm.\n" ESC "Hoàn thành nhiệm vụ\ntalk %x# welcome.5\n" ESC "Rời khỏi.", me->get_name(), getoid(me)));
		break;
	case 4:
		if (who->get_level() >= 5 && !who->get_legend(TASK_NEWBIE_02, 18))
		{
			if (TASK_LEGEND_D->can_task_add(who) != 1)
				return;
			who->set_legend(TASK_NEWBIE_02, 18);
			who->delete_save_2("baqiu_xiaomai");
			send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Tân Thủ Thôn");
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 44, "Nguyên liệu thô để làm rượu");
			send_user(who, "%c%s", '!', "Nhận nhiệm vụ " HIY "Nguyên liệu thô để làm rượu");
		}
		break;
	case 5:
		if (who->get_legend(TASK_NEWBIE_02, 19) && !who->get_legend(TASK_NEWBIE_02, 20))
		{
			if (TASK_LEGEND_D->check_task_item(who, "Lúa mì", 3) != 1)
				return;
			TASK_LEGEND_D->task_finish(who);
			who->delete_save_2("baqiu_xiaomai");
			who->add_exp(220);
			who->add_potential(10);
			who->set_legend(TASK_NEWBIE_02, 20);
			send_user(who, "%c%s", ';', "Nguyên liệu thô để làm rượu Kinh nghiệm 220 Tiềm năng 10");
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 44, "");
		}
		break;
	case 6:
		if (who->get_level() >= 5 && !who->get_legend(TASK_40, 22))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Thực phẩm trong khách sạn của tôi đều là sản vật địa phương, từ những thứ bay trên trời đến chạy dưới đất, tất cả đều do thợ săn mang đến, đảm bảo tuyệt đối tươi ngon.\n    Gần đây, khách thích ăn cá đột nhiên tăng nhiều, người ngư dân cung cấp cá tươi trước đây có vẻ không đủ sức đáp ứng. Tôi nghe nói ông Mạnh ở ngoại ô có kỹ thuật bắt cá rất tốt, hay là bạn giúp tôi đến hỏi xem ông ấy có sẵn lòng bắt cá để bán cho tôi không, để giải quyết khó khăn trước mắt của tôi.\n" ESC "Chấp nhận nhiệm vụ\ntalk %x# welcome.7\n" ESC "Rời khỏi.", me->get_name(), getoid(me)));
		break;
	case 7:
		if (who->get_level() >= 5 && !who->get_legend(TASK_40, 22))
		{
			if (TASK_LEGEND_D->can_task_add(who) != 1)
				return;
			who->set_legend(TASK_40, 22);
			send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Tân Thủ Thôn");
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 35, "Nguồn gốc thực phẩm");
			send_user(who, "%c%s", '!', "Nhận nhiệm vụ " HIY "Nguồn gốc thực phẩm");
		}
		break;
	case 8:
		if (!who->get_legend(TASK_49, 18))
			send_user(who, "%c%s", ':', sprintf("%s\n    Quán của tôi tuy nhỏ, nhưng rượu ngon thì nổi tiếng khắp nơi, nhiều khách từ xa đến thưởng thức, việc kinh doanh rất phát đạt. Tôi có một xưởng nhỏ ở Thanh Khê, rượu trong quán đều được酿 ở đó. Không ngờ vài ngày trước, một đàn thỏ rừng chạy vào xưởng ăn trộm, làm xưởng của tôi tan hoang. Bạn giúp tôi dạy cho lũ thỏ này một bài học, chúng thường xuất hiện ở ngoài Tân Thủ Thôn và Thanh Khê.\n" ESC "Chấp nhận\ntalk %x# welcome.9\n" ESC "Rời khỏi.", me->get_name(), getoid(me)));
		else if (who->get_legend(TASK_49, 19) && !who->get_legend(TASK_49, 20))
			send_user(who, "%c%s", ':', sprintf("%s\n    Cảm ơn bạn đã giúp tôi dạy dỗ chúng, hy vọng sau này chúng sẽ không quấy rối xưởng của tôi nữa. Đây là vài bình Rượu gạo của quán tôi, bạn cầm lấy nếm thử, nhưng cẩn thận đừng uống quá nhiều.\n" ESC "Hoàn thành nhiệm vụ\ntalk %x# welcome.10\n" ESC "Rời khỏi.", me->get_name(), getoid(me)));
		break;
	case 9:
		if (!who->get_legend(TASK_49, 18))
		{
			if (TASK_LEGEND_D->can_task_add(who) != 1)
				return;
			who->set_legend(TASK_49, 18);
			who->delete_save("jiudian_yetu");
			send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Tân Thủ Thôn");
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 46, "Một con thỏ nhỏ");
			send_user(who, "%c%s", '!', "Nhận nhiệm vụ " HIY "Một con thỏ nhỏ");
		}
		break;
	case 10:
		if (who->get_legend(TASK_49, 19) && !who->get_legend(TASK_49, 20))
		{
			if (TASK_LEGEND_D->can_carry_amount(who, 1) != 1)
				return;
			TASK_LEGEND_D->give_item(who, "item/stuff/0230", 5);
			TASK_LEGEND_D->task_finish(who);
			who->delete_save("jiudian_yetu");
			who->add_exp(150);
			who->add_potential(20);
			who->add_cash(500);
			who->set_legend(TASK_49, 20);
			send_user(who, "%c%s", ';', "Một con thỏ nhỏ kinh nghiệm 150 tiềm năng 20 Ngân lượng 500 Rượu gạo 5");
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 46, "");
		}
		break;
	case 99:
		TASK_COLLECT_D->do_talk_exchange(who, me, 0015);
		break;
	}
}
