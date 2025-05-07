
#include <ansi.h>
#include <task.h>
#include <effect.h>
#include <skill.h>

// 函数：命令处理
int main(object me, string arg)
{
	object who, map;
	string data, str1, str2;
	int level;
	object mapNew, * team;
	int size;

	if (arg && sscanf(arg, "%s %s", arg, data) == 2) switch (arg)
	{
	case "lock": me->set_enemy_2(0);    // 取消攻击目标(暗器，法术，医术，施毒锁定)，指令：set lock 0
		break;

	case "?": if (data == "attack")
	{
		switch (me->get_attack_mode())
		{
		case 0: data = "Tấn công tự do";  break;
		case 2: data = "Bảo vệ phục kích";  break;
		default: data = "An toàn";  break;
		}
		send_user(me, "%c%c%w%s", ':', 3, 0, "Chế độ tấn công của bạn là“" + data + "”，Bạn muốn thay đổi：(Phím tắt: Ctrl+H)\n"
			ESC "An toàn，Chỉ tấn công ＮＰＣ。\nset attack 1\n"
			//                                        ESC "伏击保护，以攻击红名玩家。但你也将处于自由攻击状态。\nset attack 2\n"
			ESC "Tấn công tự do，Người chơi trong cùng một Bang có thể tấn công nhau。\nset attack 0\n"
			ESC "Không thay đổi。\nCLOSE\n");
	}
			break;
	case "attack":
		if (me->get_level() < 30)
		{
			me->set_attack_mode(1);
			write_user(me, ECHO "Dưới 30 không thể PK !");
			break;
		}
		switch (data)
		{
		case "1":
			if (me->get_pk() >= 5) break;
			if (get_effect(me, EFFECT_USER_PK)) break;
			send_user(me, "%c%c%w%s", ':', 3, 0, "Bạn sẽ được bảo vệ và bạn sẽ không bị tấn công bởi bất kỳ người chơi nào。\n"
				ESC "Chấp nhận\nset !attack 1\n"
				ESC "Hủy bỏ\nCLOSE\n");
			break;
		default:
			send_user(me, "%c%c%w%s", ':', 3, 0, "Bạn sẽ ở trong một trạng thái tấn công không hạn chế, và bạn có thể tấn công lẫn nhau với người chơi trong cùng một nhà nước\n"
				ESC "Chấp nhận\nset !attack 0\n"
				ESC "Hủy bỏ\nCLOSE\n");
			break;
		}
		break;
	case "!attack":
		//debug tan cong
		//tell_user(me, "loại tấn công: %s", data);

		switch (data)
		{
		case "3":
			if (get_effect(me, EFFECT_USER_PK))
			{
				me->set_attack_mode(me->get_attack_mode());
				break;
			}

			me->set_attack_mode(0);
			set_effect(me, EFFECT_USER_PK, 1);
			me->set_pk(me->get_pk());
			write_user(me, ECHO"Hình thức tấn công: Tấn công Tự Do !");
			break;

		case "2":
			me->set_attack_mode(3);
			set_effect(me, EFFECT_USER_PK, 1);
			me->set_pk(me->get_pk());
			send_user(me, "%c%w%w%c", 0x81, 2214, 0, EFFECT_GOOD);
			write_user(me, ECHO "Hình thức tấn công của bạn: Tấn công theo Bang!");
			break;

		case "1":
			//check pt
			team = me->get_team();
			size = sizeof(team);
			if (size < 1)
			{
				notify("Nhóm của bạn đâu?");
				return;
			}

			me->set_attack_mode(2);
			set_effect(me, EFFECT_USER_PK, 1);
			me->set_pk(me->get_pk());
			send_user(me, "%c%w%w%c", 0x81, 2214, 0, EFFECT_GOOD);
			write_user(me, ECHO "Hình thức tấn công của bạn: Tấn công theo Đội Nhóm!");
			break;

		default:
			if (MAIN_D->get_host_type() == 6012)
			{
				send_user(me, "%c%%s", ':', "PK系统尚未开放！");
				break;
			}

			me->set_attack_mode(1);
			set_effect(me, EFFECT_USER_PK, 0);
			me->set_pk(me->get_pk());
			write_user(me, "Hình thức tấn công: Hoà Bình !");
			break;
		}
		break;
	case "give": me->set_no_give(data == "0");
		break;
	case "fly": me->set_no_fly(data == "0");
		break;
	case "trans": me->set_no_trans(data == "0");
		break;
	case "trade": me->set_no_trade(data == "0");
		break;
	case "team": me->set_no_team(data == "0");
		break;
	case "friend": me->set_no_friend(data == "0");
		break;
	case "tell": me->set_no_tell(data == "0");
		break;
	case "chat": if (data == "1")
	{
		me->set_chat_open(1);  CHAT_D->add_chat(me);
	}
			   else { me->set_chat_open(0);  CHAT_D->sub_chat(me); }
			   break;
	case "rumor": if (data == "1")
	{
		me->set_rumor_open(1);  CHAT_D->add_rumor(me);
	}
				else { me->set_rumor_open(0);  CHAT_D->sub_rumor(me); }
				break;
	case "ct": if (data == "1")
	{
		me->set_city_open(1);  FAMILY_D->add_city(me);
	}
			 else { me->set_city_open(0);  FAMILY_D->sub_city(me); }
			 break;
	case "ot": if (data == "1")
	{
		me->set_org_open(1);  FAMILY_D->add_org(me);
	}
			 else { me->set_org_open(0);  FAMILY_D->sub_org(me); }
			 break;
	case "ft": if (data == "1")
	{
		me->set_family_open(1);  FAMILY_D->add_family(me);
	}
			 else { me->set_family_open(0);  FAMILY_D->sub_family(me); }
			 break;
	case "say": me->set_say_open(data == "1");
		break;
	case "tt": me->set_team_open(data == "1");
		break;
	case "et": me->set_trade_open(data == "1");
		break;
	case "channel": if (data == "1")
	{
		me->set_chat_open(1);  CHAT_D->add_chat(me);
		me->set_rumor_open(1);  CHAT_D->add_rumor(me);
		me->set_city_open(1);  FAMILY_D->add_city(me);
		me->set_org_open(1);  FAMILY_D->add_org(me);
		me->set_family_open(1);  FAMILY_D->add_family(me);
		me->set_say_open(1);
		me->set_team_open(1);
		me->set_trade_open(1);
	}
	else
	{
		me->set_chat_open(0);  CHAT_D->sub_chat(me);
		me->set_rumor_open(0);  CHAT_D->sub_rumor(me);
		me->set_city_open(0);  FAMILY_D->sub_city(me);
		me->set_org_open(0);  FAMILY_D->sub_org(me);
		me->set_family_open(0);  FAMILY_D->sub_family(me);
		me->set_say_open(0);
		me->set_team_open(0);
		me->set_trade_open(0);
	}
				  break;
	case "protect": if (strlen(data) > 10) data = data[0..9];
		me->set_id_protect(data);
		break;
	case "locked": me->set_id_locked(data == "1");
		break;
	case "mode":   
		me->set_mode(data == "1");
		break;
	case "mouse":   me->set_mouse(data == "1");
		break;
	}
	else if (!is_player(me))
	{
		if (!arg) who = me;
		else if (!objectp(who = find_player(arg)))
		{
			notify("您找不到这位玩家。");
			return 1;
		}

		tell_user(me, "%s(%d)Môi trường thiết lập：\n", who->get_name(), who->get_number());
		tell_user(me, "Chế độ tấn công: %-4d Cấm bay: %d", who->get_attack_mode(), who->get_no_fly());
		tell_user(me, "Cấm tặng: %-4d Cấm giao hàng: %d", who->get_no_give(), who->get_no_trans());
		tell_user(me, "Cấm hẹn hò: %-4d Không lập PT: %d", who->get_no_friend(), who->get_no_team());
		tell_user(me, "Cấm trò chuyện riêng tư: %d", who->get_no_tell());
		tell_user(me, "Cấm giao dịch: %d", who->get_no_trade());

		tell_user(me, "公众: %-4d谣言: %-4d国家: %-4d帮派: %-4d门派: %-4d本地: %-4d队伍: %-4dGiao dịch: %-4d",
			who->get_chat_open(), who->get_rumor_open(), who->get_city_open(), who->get_org_open(),
			who->get_family_open(), who->get_say_open(), who->get_team_open(), who->get_trade_open());

		tell_user(me, "Mật khẩu bảo vệ: %-4s Khóa người dùng: %d", who->get_id_protect(), who->get_id_locked());
	}

	return 1;
}

// 函数：获取描述(持续)
string get_loop_desc(object me)
{
	return HIR "Công kích Tự Do";
}