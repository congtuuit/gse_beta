
#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <music.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 5403; }
void do_welcome(string arg);

void create()
{
	set_name("Trí Tuệ Lão Nhân");
	set_2("talk", ([
		"welcome":(: do_welcome:),
	]));
	setup();
}
void do_look(object who)
{
	string tmp = "";
	string tmp214 = "";
	object item;

	if ((who->get_legend(TASK_41, 4) && !who->get_legend(TASK_41, 5)) || (who->get_legend(TASK_41, 5) && !who->get_legend(TASK_41, 6)) || (who->get_legend(TASK_41, 7) && !who->get_legend(TASK_41, 8)) || (who->get_legend(TASK_41, 8) && !who->get_legend(TASK_41, 9)))
		tmp = sprintf(ESC"Rất nhiều bệnh khác nhau\ntalk %x# welcome.3\n", getoid(this_object()));

	if (objectp(item = present("Hạt giống bí ẩn", who, 1, MAX_CARRY)) && who->get_quest("valentine.flag") == 4)
		tmp = sprintf(ESC"Hoa của tình yêu\ntalk %x# welcome.214\n", getoid(this_object()));

	send_user(who, "%c%s", ':', sprintf("%s:\n    Anh biết không?\n    Vóc dáng quyết định giá trị cuộc sống tối đa của một cầu thủ. chừng nào người chơi có cơ thể tốt hơn, thì khả năng sinh hoạt tối đa của cầu thủ càng cao.\n    Linh hồn quyết định vận tốc tối đa của người chơi và tấn công và phòng thủ của câu thần chú. Yêu tinh càng cao, vận tốc tối đa của người chơi và s ức mạnh tấn công và phòng thủ của câu thần chú càng cao.\n    Sức bền quyết định phòng thủ thể chất của cầu thủ. nó là một trong các đặc trưng quan trọng của trường thể chất.\n"ESC"Tiếp tục\ntalk %x# welcome.1\n" +
		tmp + tmp214 +
		ESC"Rời khỏi", get_name(), getoid(this_object())));
}

void do_welcome(string arg)
{
	object me = this_object();
	__FILE__->do_welcome2(me, arg);
}

void do_welcome2(object me, string arg)
{
	int flag, p, i,k;
	object who, item, item1;
	string file, cWord = "";

	who = this_player();
	flag = to_int(arg);
	who->set_time("talk", 0);
	switch (flag)
	{
	case 1:
		if (who->get_legend(TASK_NEWBIE_02, 10) && !who->get_legend(TASK_NEWBIE_02, 11))
			send_user(who, "%c%s", ':', sprintf("%s:\n    Quyền lực quyết định s ức mạnh t ấn công vật lý của người chơi. Quyền lực của người chơi càng cao, sức mạnh tấn công thể chất của người chơi. Nó là một khả năng không thể bị bỏ qua bởi cầu thủ bảo vệ。\n    Kích động né được đòn tấn công của đối thủ, và ảnh hưởng đến tỷ lệ tấn công. Tốc độ nhanh chóng và nhanh chóng tấn công đối thủ, và dễ dàng hơn để tấn công đối phương, giảm khả năng thất bại \n"ESC"Hoàn thành nhiệm vụ\ntalk %x# welcome.2\n"ESC"Rời khỏi", me->get_name(), getoid(me)));
		else
			send_user(who, "%c%s", ':', sprintf("%s:\n    Quyền lực quyết định s ức mạnh t ấn công vật lý của người chơi. Sức mạnh tấn công vật lý của người chơi càng cao. Nó là một khả năng không thể bị lơ là của cầu thủ bảo vệ.\n   Tốc độ nhanh nhẹn càng cao, cơ hội tránh được cuộc tấn công của đối thủ càng cao, và tốc độ nhanh nhẹn cũng ảnh hưởng đến tỷ lệ tiêu chuẩn của mỗi cuộc tấn công.n"ESC"Rời khỏi", me->get_name(), getoid(me)));
		break;
	case 2:
		if (who->get_legend(TASK_NEWBIE_02, 10) && !who->get_legend(TASK_NEWBIE_02, 11))
		{
			who->set_legend(TASK_NEWBIE_02, 11);
			who->add_exp(280);
			who->add_cash(1500);
			send_user(who, "%c%s", ';', "Hãy nói chuyện với ông già thông thái. Kinh nghiệm 280 Ngân lượng 1500");
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 17, "");
		}
		break;
	case 3:
		if (who->get_legend(TASK_41, 4) && !who->get_legend(TASK_41, 5))
			send_user(who, "%c%s", ':', sprintf("%s:\n    Theo mô tả của anh, dân làng không hề bị bệnh, mà còn bị đầu độc. và rồi tới chỗ tôi.\n"ESC"Hoàn thành nhiệm vụ\ntalk %x# welcome.4\n"ESC"Rời khỏi", me->get_name(), getoid(me)));
		else if (who->get_legend(TASK_41, 5) && !who->get_legend(TASK_41, 6))
			send_user(who, "%c%s", ':', sprintf("%s:\n    Theo đánh giá của tôi, dân làng nên bị đầu độc bởi một loại chất độc gọi là thuốc độc, và nguồn gốc của chất độc là cái giếng phía sau làng. tất cả dân làng bị đầu độc đã uống nước trong giếng phía sau làng trước khi họ phát triển triệu chứng này。\n    Thuốc tẩy là cần thiết để cai nghiện, và nó phải được kết hợp với các loại thuốc khác để có hiệu ứng hóa. nó không chỉ cần bị dân làng lấy, mà còn cần phải được rắc trong giếng để cai nghiện.\n    Anh đi tìm thuốc súng thật trước. Tôi nghe nói tất cả chim trĩ trong vùng này đều có bột thực thụ.\n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.5\n"ESC"Rời khỏi", me->get_name(), getoid(me)));
		else if (who->get_legend(TASK_41, 7) && !who->get_legend(TASK_41, 8))
			send_user(who, "%c%s", ':', sprintf("%s:\n    Tôi vẫn cần chút thời gian để chuẩn bị thuốc hãy quay lại với tôi sau！\n"ESC"Hoàn thành nhiệm vụ\ntalk %x# welcome.6\n"ESC"Rời khỏi", me->get_name(), getoid(me)));
		else if (who->get_legend(TASK_41, 8) && !who->get_legend(TASK_41, 9))
			send_user(who, "%c%s", ':', sprintf("%s:\n    Bạn mang gói thuốc giải này đến cho người đứng đầu làng và nói với ông ấy nhớ nói với dân làng là không được tới cái giếng phía sau làng uống rượu trong hai ngày qua. Hãy nhớ mang thuốc giải đến làng dân làng và rắc thuốc giải vào giếng！\n    Còn một chuyện nữa, anh không được công khai. tôi nghi ngờ ai đó đã đầu độc cái giếng. và tôi cũng muốn nhờ thủ lĩnh làng tìm hiểu vấn đề và tìm ra kẻ đã đầu độc người độc\n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.7\n"ESC"Rời khỏi", me->get_name(), getoid(me)));

		break;
	case 4:
		if (who->get_legend(TASK_41, 4) && !who->get_legend(TASK_41, 5))
		{
			who->set_legend(TASK_41, 5);
			who->add_exp(150);
			who->add_potential(20);
			send_user(who, "%c%s", ';', "Khó khăn và nhiều bệnh khác nhau(1) kinh nghiệm 150 tiềm năng 20");
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 27, "");
			me->do_welcome(3);
		}
		break;
	case 5:
		if (who->get_legend(TASK_41, 5) && !who->get_legend(TASK_41, 6))
		{
			who->set_legend(TASK_41, 6);
			send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Làng Tân Sinh");
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 28, "Rất nhiều bệnh khác nhau（2）");
			send_user(who, "%c%s", '!', "Nhiệm vụ "HIY"Rất nhiều bệnh khác nhau（2）");
		}
		break;
	case 6:
		if (who->get_legend(TASK_41, 7) && !who->get_legend(TASK_41, 8))
		{
			if (TASK_LEGEND_D->check_task_item(who, "Bột Thạch Hoàng", 1) != 1)
				return;
			//				TASK_LEGEND_D->give_item(who,"item/91/9100",5);
			who->add_exp(300);
			who->add_potential(30);
			who->add_cash(1800);
			who->set_legend(TASK_41, 8);
			send_user(who, "%c%s", ';', "Khó khăn và nhiều bệnh khác nhau (2) kinh nghiệm 300, tiềm năng 30, money 1800");
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 28, "");
		}
		break;
	case 7:
		if (who->get_legend(TASK_41, 8) && !who->get_legend(TASK_41, 9))
		{
			if (TASK_LEGEND_D->can_carry_amount(who, 1) != 1)
				return;
			TASK_LEGEND_D->give_item(who, "item/98/0200", 1);
			who->set_legend(TASK_41, 9);
			send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Làng Tân Sinh");
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 29, "Rất nhiều bệnh khác nhau（3）");
			send_user(who, "%c%s", '!', "Nhận việc đi "HIY"Rất nhiều bệnh khác nhau（3）");
		}
		break;
	case 214:
		if (who->get_quest("valentine.flag") == 4)
		{

			send_user(who, "%c%s", ':', sprintf("%s:\n    Tôi hiểu anh muốn nói gì, anh bạn trẻ nhưng không dễ dàng gì để cho hạt giống bí ẩn này nảy sinh anh ta cần các nỗ lực chăm chỉ để tưới nước nó？\n"ESC"Sẵn sàng\ntalk %x# welcome.215\n"ESC"Để sau", me->get_name(), getoid(me)));

		}
		break;
	case 215:
		if (who->get_quest("valentine.flag") == 4)
		{
			if (USER_INVENTORY_D->count_empty_carry(who) < 4)
			{
				send_user(who, "%c%s", ';', "Cô không có đủ 4 chỗ, tôi đề nghị cô tạo ra ba chỗ cho quà tặng Valentine");
				return;
			}

			if (objectp(item = present("Hạt giống bí ẩn", who, 1, MAX_CARRY)))
			{
				item->remove_from_user();
				destruct(item);
			}
			switch (random(4))
			{
			case 0: file = "/item/04/0426";  break;
			case 1: file = "/item/04/0427";  break;
			case 2: file = "/item/04/0428";  break;
			case 3: file = "/item/04/0429";  break;
			default: break;
			}
			for (i = 0; i < 3; i++)
			{
				item = new (file);
				if (item)
				{
					p = item->move(who, -1);
					item->add_to_user(p);
				}
			}
			who->set_hp(1);
			who->set_quest("valentine.flag", 10);
			who->add_exp(500);
			who->add_potential(2000);
			tell_user(who, ECHO"Hoàn thành nhiệm vụ - tiềm năng: +2000");

			item1 = new ("item/event/valentine/quanv");
			if (item1)
			{
				k = item1->move(who, -1);
				item1->add_to_user(k);
			}


			send_user(who, "%c%s", '!', "Lấy 3 cành "HIR"Hoa");
			write_user(who, ECHO"Vì lòng thành của anh và lòng can đảm，Có quà Valentine " + item->get_name() + " đưa nó cho bà ấy càng sớm càng tốt.！");
			send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "");
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 4, "");
		}
		break;
	}
}