// general 将军

#include <ansi.h>
#include <city.h>
#include <cmd.h>
#include <skill.h>

// 函数：对话处理
void do_look(object who, object me)
{
	string name1, name2;
	string cmd1, cmd2, cmd3, cmd4, cmd5;

	name1 = who->get_city_name();
	name2 = me->get_city_name();

	if (stringp(name1) && stringp(name2) && name1 == name2)
	{
		if (who->is_soldier())
		{
			cmd1 = sprintf("talk %x# patrol\n", getoid(me));
			cmd2 = sprintf("talk %x# soldier\n", getoid(me));
			cmd3 = sprintf("talk %x# armor\n", getoid(me));
			cmd4 = sprintf("talk %x# taofa\n", getoid(me));
			cmd5 = sprintf("talk %x# baowei\n", getoid(me));
			send_user(who, "%c%s", ':', me->get_name() + "：\n    " + "/quest/word"->get_country_word(me) + "\n    " + who->get_name() + "，尔等找我有何事情？\n"
				ESC "Tham gia tuần tra\n" + cmd1 +
				ESC "Gia nhập quân ngũ\n" + cmd2 +
				ESC "Nhận nhiệm vụ tham chiến\n" + cmd3 +
				ESC "Chống lại kẻ thù\n" + cmd4 +
				ESC "Bảo vệ quốc gia\n" + cmd5 +
				ESC "Rời đi。\nCLOSE\n");
		}
		else
		{
			send_user(who, "%c%s", ':', me->get_name() + "：\n    " + "/quest/word"->get_country_word(me));
		}
	}
	else
	{
		send_user(who, "%c%s", ':', me->get_name() + "：\n    " + "/quest/word"->get_country_word(me));
	}
}

// 函数：城内巡逻
void do_patrol(object who, object me, string arg)
{
	object city;
	string name1, name2;

	name1 = who->get_city_name();
	name2 = me->get_city_name();

	if (stringp(name1) && stringp(name2) && name1 == name2
		&& who->is_soldier()
		&& (city = CITY_D->get_city_object(who)))
	{
		if (who->get_2("train.patrol"))
		{
			send_user(who, "%c%s", ':', me->get_name() + "：\nCác người tuần tra để xem ai phạm lệnh giới nghiêm.\n");
			return;
		}
		if (who->get_strength() < 1)
		{
			send_user(who, "%c%s", '!', "Anh không đủ sức đâu");
			return;
		}

		who->set_2("train.patrol", 1);
		send_user(who, "%c%s", ':', me->get_name() + "：\nVài giờ giới nghiêm đang gây rắc rối trong thành phố.\n");
	}
}

void do_soldier(object who, object me, string arg)
{
	object city;
	string name1, name2;

	name1 = who->get_city_name();
	name2 = me->get_city_name();

	if (stringp(name1) && stringp(name2) && name1 == name2
		&& who->is_soldier()
		&& (city = CITY_D->get_city_object(who)))
	{
		if (city->is_soldier_enough())
		{
			send_user(who, "%c%s", ':', me->get_name() + "：\nTrong thành phố này có đủ lính rồi, không cần phải tuyển mộ nữa đâu.\n");
			return;
		}
		if (who->get_2("train.soldier"))
		{
			send_user(who, "%c%s", ':', me->get_name() + "：\nNgài di chuyển khắp thành phố để xem ai sẵn sàng gia nhập quân đội.\n");
			return;
		}
		if (who->get_strength() < 1)
		{
			send_user(who, "%c%s", '!', "Anh không đủ sức đâu.");
			return;
		}

		who->set_2("train.soldier", 1);
		send_user(who, "%c%s", ':', me->get_name() + "：\nNgài có thể huy động khắp thành phố để xem ai muốn gia nhập quân đội\n");
	}
}

void do_armor(object who, object me, string arg)
{
	object city;
	string name1, name2;

	name1 = who->get_city_name();
	name2 = me->get_city_name();

	if (stringp(name1) && stringp(name2) && name1 == name2
		&& who->is_soldier()
		&& (city = CITY_D->get_city_object(who)))
	{
		if (city->get_armor() >= city->get_soldier())
		{
			send_user(who, "%c%s", ':', me->get_name() + "：\nCó đủ thiết bị trong thành phố, không cần mua nữa.\n");
			return;
		}
		if (who->get_2("train.armor"))
		{
			send_user(who, "%c%s", ':', me->get_name() + "：\nBạn đến các quốc gia khác nhau để điều tra và xem bạn có thể mua thiết bị ở đâu？\n");
			return;
		}
		if (who->get_strength() < 1)
		{
			send_user(who, "%c%s", '!', "Anh không đủ sức đâu");
			return;
		}

		who->set_2("train.armor", 1);
		send_user(who, "%c%s", ':', me->get_name() + "：\nBạn đến các quốc gia khác nhau để điều tra và xem bạn có thể mua thiết bị ở đâu？\n");
	}
}
