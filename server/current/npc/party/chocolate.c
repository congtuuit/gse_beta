
#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

void do_zzy();
void accept_zzy();
void give_bonus();

int get_char_picid() { return 0951; }

void create()
{
	set_name("Yêu tinh sô cô la");

	set_2("talk", ([
		"zzy":(: do_zzy:),
			"accept_zzy" : (: accept_zzy:),
			"bonus_zy" : (: give_bonus:),

	]));

	setup();

}

void do_look(object who)
{
	object npc, item, me = this_object();
	int id = getoid(me), i;
	string cmd = sprintf("talk %x# zzy\n", id);
	string tmp = "";
	if (who->get_quest("valentine.flag") == 8 && objectp(item = present("Đậu Socola", who, 1, MAX_CARRY)))
		tmp = ESC "Chocolate ngày Valentine。\n" + cmd;
	send_user(who, "%c%s", ':', get_name() + "：\n    Sôcôla khác nhau có ý nghĩa khác nhau, nhưng họ đã bày tỏ tình yêu sâu sắc của họ.。\n" +
		tmp +
		ESC "Rời khỏi.\nCLOSE\n");
}

void do_zzy()
{
	object who = this_player();
	object me = this_object();
	__FILE__->do_task_start(who, me);
}

void accept_zzy()
{
	object who = this_player();
	object me = this_object();
	__FILE__->accept_task(who, me);
}

void give_bonus() { object who = this_player(); __FILE__->give_bonus_2(who); }

void do_task_start(object who, object me)
{
	if (who->get_quest("valentine.flag") == 8)
	{
		string cWord = "";
		cWord = sprintf(me->get_name() + "：\n    Cô bé, bạn có muốn gửi một miếng sô cô la cho tình yêu của bạn không? Nhưng máy cơ học làm sô cô la đòi hỏi bạn phải trả rất nhiều mana để lái xe, bạn có sẵn sàng không?？");
		send_user(who, "%c%s", ':', cWord + "\n" +
			ESC + sprintf("Rất sẵn lòng.\ntalk %x# accept_zzy\n", getoid(me)) +
			ESC "Rời khỏi.\nCLOSE\n");
	}
}
void accept_task(object who, object me)
{
	object item, item1;
	string file, cWord = "";
	int p, i, k;
	if (who->get_quest("valentine.flag") == 8 && MAIN_D->get_host_type() != 4)
	{
		if (USER_INVENTORY_D->count_empty_carry(who) < 4)
		{
			send_user(who, "%c%s", ';', "Hành trang bạn không đủ 4 chỗ trống.");
			return;
		}
		if (objectp(item = present("Đậu Socola", who, 1, MAX_CARRY)))
		{
			item->remove_from_user();
			destruct(item);
		}
		switch (random(4))
		{
		case 0: file = "/item/04/0430";  break;
		case 1: file = "/item/04/0431";  break;
		case 2: file = "/item/04/0432";  break;
		case 3: file = "/item/04/0433";  break;
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

		who->set_mp(0);
		who->set_quest("valentine.flag", 9);
		who->add_exp(500);
		who->add_potential(2000);
		tell_user(who, ECHO"Hoàn thành nhiệm vụ - tiềm năng: +2000");

		item1 = new ("item/event/valentine/quanv");
		if (item1)
		{
			k = item1->move(who, -1);
			item1->add_to_user(k);
		}

		send_user(who, "%c%s", '!', "nhận được "HIR"Socola"NOR"");
		write_user(who, ECHO"Bởi vì sự chân thành và sự can đảm của bạn, tôi đã có ngày Valentine thật tuyệt vời cùng " + item->get_name());
		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "");
		send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 8, "");
	}

	if (who->get_quest("valentine.flag") == 8 && MAIN_D->get_host_type() == 4)
	{
		if (USER_INVENTORY_D->count_empty_carry(who) < 3)
		{
			send_user(who, "%c%s", ';', "Không có đủ không gian trên bạn! Tôi đề nghị bạn làm trống 3 ô để nhận món quà ngày Valentine.");
			return;
		}
		if (objectp(item = present("Đậu Socola", who, 1, MAX_CARRY)))
		{
			item->remove_from_user();
			destruct(item);
		}
		switch (random(4))
		{
		case 0: file = "/item/04/0430m";  break;
		case 1: file = "/item/04/0431m";  break;
		case 2: file = "/item/04/0432m";  break;
		case 3: file = "/item/04/0433m";  break;
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
		who->set_mp(0);
		who->set_quest("valentine.flag", 9);
		who->add_exp(500);
		who->add_potential(2000);
		tell_user(who, ECHO"Hoàn thành nhiệm vụ - tiềm năng: +2000");

		send_user(who, "%c%s", '!', "nhận được "HIR"Socola"NOR"");
		write_user(who, ECHO"Bởi vì sự chân thành và sự can đảm của bạn, tôi đã có ngày Valentine thật tuyệt vời cùng " + item->get_name());
		send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "");
		send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 8, "");
	}
}

