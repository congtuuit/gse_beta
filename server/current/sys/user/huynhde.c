#include <ansi.h>
#include <cmd.h>
#include <task.h>
#include <equip.h>
static string* nTudi = ({
"huynhde.huynh",
"huynhde.huynh1",
"huynhde.huynh2",
"huynhde.huynh3",
"huynhde.huynh4",
"huynhde.huynh5",
"huynhde.huynh6",
"huynhde.huynh7",
"huynhde.huynh8",
"huynhde.huynh9",
"huynhde.huynh10",
"huynhde.huynh11",
"huynhde.huynh12",
"huynhde.huynh13",
"huynhde.huynh14"
	});


void giai_thoat(object me, object who, int id);
void baishi(object me, object who, object user);
object check_baishi(object me, object who);
object check_chushi(object me, object who);
void chushi(object me, object who, object user);
void dissolve1(object me, object who);
void dissolve2(object me, object who);
void query_shifu(object me, object who);
void dissolve1_list(object me, object who);
void dissolve2_list(object me, object who);
void dissolve1_tudi(object me, object who, int id);
void dissolve2_tudi(object me, object who, int id);
void dissolve1_shifu(object me, object who);
void dissolve2_shifu(object me, object who);
void query_tudi(object me, object who, int id);
void query_tudi_list_2(object me, object who);
void query_tudi_list(object me, object who);

#define DA_CUONG_HOA "/item/common/dacuonghoa"

void SAVE_BINARY() { }

int is_shifu(object who)
{
	int i, size;
	for (i = 0, size = sizeof(nTudi); i < size; i++)
	{
		if (mapp(who->get_save_2(nTudi[i])))
			return 1;
	}
	return 0;
}

int is_tudi(object who)
{
	return mapp(who->get_save_2("huynhde.de"));
}
void do_look(object who, object me)
{
	int id;
	string tmp = "";
	id = getoid(me);
	send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(),
		me->get_name() + ":\n  Ngươi có Huynh Đệ muốn kết nghĩa phải không? Chỉ cần đến chỗ ta đăng kí (người làm Huynh phải là đội trưởng), đồng thời từ nay về sau 2 người cùng nhau rèn luyện là có thể lấy giải thưởng của Mạc Gia.\n"
		+ sprintf(ESC"Điền thông tin kết nghĩa\ntalk %x# welcome.2\n", id)
		+ sprintf(ESC"Xem thông tin kết nghĩa\ntalk %x# welcome.4\n", id)
		+ sprintf(ESC"Tìm hiểu quy tắc kết nghĩa\ntalk %x# welcome.1\n", id)
		+ sprintf(ESC"Giải thoát huynh đệ kết nghĩa\ntalk %x# welcome.5\n", id)
		+ sprintf(ESC"Nhận giải thưởng\ntalk %x# welcome.19\n", id)
		+ ESC"Rời khỏi"
	);
}


void do_welcome(object me, object who, string arg)
{
	int flag, i, size, id, exp, pot, max, exp1, pot1, p;
	string* name, tmp, * nTmp, * nTmp2, username, cFile, forge = "";
	object user, item;
	object huynh, de;

	if (!arg)
		return;
	nTmp = explode(arg, ".");
	flag = to_int(nTmp[0]);
	who->set_time("talk", 0);
	id = getoid(me);
	switch (flag)
	{
	case 1:
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nMục đích của quy tắt giới thiệu là cùng những huynh đệ giúp đỡ lẫn nhau, cùng dốc sức quyết đấu tìm ra một vùng trời của riêng mình.\nCụ thể quy tắc giới thiệu như sau :\n1.Người được nhận làm tiểu Đệ phải có đẳng 30 trở xuống, người muốn làm Huynh phải có đẳng cấp cao hơn tiểu Đệ của mình.\n2.Hai bên đều đồng ý mới có thể kết thành huynh đệ.\n3.Chỉ có thể được kết nghĩa 1 lần.\n4.Thường xuyên kiểm tra giải thưởng tại NPC Mạc Địch.\n5.Một người chơi chỉ có một đại Huynh, nhưng có thể có đến 15 tiểu Đệ.\n"ESC"Rời khỏi", me->get_name()));
		break;
	case 2:
		if (!objectp(user = check_baishi(me, who)))
			return;
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			sprintf("%s\n Ngươi muốn nhận %s làm tiểu Đệ để cùng nhau rèn luyện xông pha giang hồ không ?\n", me->get_name(), user->get_name())
			+ sprintf(ESC"Xác nhận\ntalk %x# welcome.7\n"ESC"Rời khỏi", getoid(me)));
		who->set("huynhde.huynh", user);
		break;
	case 3:
		break;
	case 4:
		if (is_tudi(who) && is_shifu(who))
		{
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(),
				me->get_name() + sprintf(":\n Ngươi muốn tìm thông tin của tiểu Đệ hay đại Huynh ?\n")
				+ sprintf(ESC"Thông tin của tiểu Đệ\ntalk %x# welcome.8\n", getoid(me))
				+ sprintf(ESC"Thông tin của đại Huynh\ntalk %x# welcome.9\n", getoid(me))
				+ ESC"Rời khỏi");
		}
		else if (is_tudi(who))
			query_shifu(me, who);
		else if (is_shifu(who))
			query_tudi_list(me, who);
		else
		{
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nNgươi chưa kết nghĩa với ai hết.\n"ESC"Rời khỏi", me->get_name()));
		}
		break;
	case 5:
		if (is_shifu(who))
			query_tudi_list_2(me, who);
		else {
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nNgươi chưa kết nghĩa với ai hết.\n"ESC"Rời khỏi", me->get_name()));
		}
		break;
	case 6:
		break;
	case 7:
		if (!objectp(user = check_baishi(me, who)))
			return;
		send_user(user, "%c%c%w%s", ':', 3, me->get_char_picid(),
			sprintf("%s:\n Ngươi bằng lòng làm tiểu Đệ của %s không ?\n", me->get_name(), who->get_name())
			+ sprintf(ESC"Xác nhận\ntalk %x# welcome.13\n"ESC"Rời khỏi", getoid(me)));
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n Xin đợi đối phương xác nhận.");
		user->set("huynhde.de", who);
		break;
	case 8:
		query_tudi_list(me, who);
		break;
	case 9:
		query_shifu(me, who);
		break;
	case 13:
		user = who;
		who = user->get("huynhde.de");
		if (!objectp(who))
			return;
		if (user != who->get("huynhde.huynh"))
			return;
		who->delete("huynhde.huynh");
		user->delete("huynhde.de");
		if (!objectp(user = check_baishi(me, who)))
			return;
		baishi(me, who, user);
		break;
	case 14:
		break;
	case 15:		//发寻师信息
		break;
	case 16:
		break;
	case 17:
		//giai thoat huynh de
		//query_tudi(me, who, to_int(nTmp[1]));
		//huynh = who;
		//giai_thoat(me, huynh, to_int(nTmp[1]));
		giai_thoat(me, who, to_int(nTmp[1]));
		break;
	case 18:
		query_tudi(me, who, to_int(nTmp[1]));
		break;
	case 19:
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			me->get_name() + sprintf(":\n Ngươi có những giải thưởng Huynh Đệ của Mạc Gia dưới đây:\n")
			+ sprintf(ESC"Nhận phần thưởng thành tựu\ntalk %x# welcome.20\n", getoid(me))
			+ sprintf(ESC"Nhận phần thưởng kết nghĩa\ntalk %x# welcome.21\n", getoid(me))
			+ ESC"Rời khỏi");
		break;
	case 20:
		if (is_tudi(who))
		{
			if (who->get_level() < 35)
			{
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nNgươi không đủ điều kiện nhận thưởng.\n"ESC"Rời khỏi", me->get_name()));
				return;
			}

			if (!who->get_save_2("phanthuong.de") &&
				!who->get_save_2("phanthuong.de1") &&
				!who->get_save_2("phanthuong.de2") &&
				!who->get_save_2("phanthuong.de100") &&
				!who->get_save_2("phanthuong.de3") &&
				!who->get_save_2("phanthuong.de4") &&
				!who->get_save_2("phanthuong.de5"))
			{
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nNgươi không đủ điều kiện nhận thưởng.\n"ESC"Rời khỏi", me->get_name()));
				return;
			}

			if (who->get_save_2("phanthuong.de") >= 1)// 35
			{
				if (USER_INVENTORY_D->get_free_count(who) < 4)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 4 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}

				who->add_save_2("phanthuong.de", -1);
				who->add_exp(100000);

				item = new("/item/std/8000");
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/std/8000");
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/sell/ruongdutru");
				item->set_amount(1);
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/sell/ruongdutru");
				item->set_amount(1);
				p = item->move2(who, -1);
				item->add_to_user(p);

				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng thành tựu cấp 35.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng thành tựu cấp 35");
				return;
			}
			if (who->get_save_2("phanthuong.de1") >= 1)// 50
			{
				if (USER_INVENTORY_D->get_free_count(who) < 3)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 3 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.de1", -1);//10
				who->add_exp(150000);
				who->add_cash(20000);

				item = new("/item/test2/block/0007");
				item->set_amount(10);
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/test2/block/0009");
				item->set_amount(10);
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/TuiLinhThach/NgauNhien/1");
				item->set_level(1);
				p = item->move2(who, -1);
				item->add_to_user(p);

				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng thành tựu cấp 50.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng thành tựu cấp 50");
				return;
			}
			if (who->get_save_2("phanthuong.de2") >= 1)// 60
			{
				if (USER_INVENTORY_D->get_free_count(who) < 3)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 3 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.de2", -1);//30
				who->add_exp(200000);
				who->add_cash(50000);

				item = new("/item/test2/block/0007");
				item->set_amount(30);
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/test2/block/0009");
				item->set_amount(30);
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/huynhde/0032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/08/0800");
				p = item->move2(who, -1);
				item->add_to_user(p);

				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng thành tựu cấp 60.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng thành tựu cấp 60");
				return;
			}
			if (who->get_save_2("phanthuong.de100") >= 1)// 70
			{
				if (USER_INVENTORY_D->get_free_count(who) < 1)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 1 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.de100", -1);//30
				item = new("/item/huynhde/0032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng thành tựu cấp 70.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng thành tựu cấp 70");
				return;
			}
			if (who->get_save_2("phanthuong.de3") >= 1)// 80
			{
				if (USER_INVENTORY_D->get_free_count(who) < 1)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 1 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.de3", -1);//60
				item = new("/item/huynhde/0032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng thành tựu cấp 80.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng thành tựu cấp 80");
				return;
			}
			if (who->get_save_2("phanthuong.de4") >= 1)// 90
			{
				if (USER_INVENTORY_D->get_free_count(who) < 2)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 2 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}

				who->add_save_2("phanthuong.de4", -1);//120
				item = new("/item/huynhde/1032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/huynhde/0032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);

				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng thành tựu cấp 90.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng thành tựu cấp 90");
				return;
			}
			if (who->get_save_2("phanthuong.de5") >= 1)// 100
			{
				if (USER_INVENTORY_D->get_free_count(who) < 4)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 4 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.de5", -1);//240
				item = new("/item/08/0002");
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/08/0004");
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/08/cql2");
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/huynhde/1032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);

				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng thành tựu cấp 100.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng thành tựu cấp 100");
				return;
			}
		}
		else
		{
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nNgươi không đủ điều kiện nhận thưởng.\n"ESC"Rời khỏi", me->get_name()));
		}
		break;
	case 21:
		if (is_shifu(who))
		{
			if (who->get_level() < 35)
			{
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nNgươi không đủ điều kiện nhận thưởng.\n"ESC"Rời khỏi", me->get_name()));
				return;
			}
			if (!who->get_save_2("phanthuong.huynh1") &&
				!who->get_save_2("phanthuong.huynh2") &&
				!who->get_save_2("phanthuong.huynh3") &&
				!who->get_save_2("phanthuong.huynh100") &&
				!who->get_save_2("phanthuong.huynh4") &&
				!who->get_save_2("phanthuong.huynh5") &&
				!who->get_save_2("phanthuong.huynh6") &&
				!who->get_save_2("phanthuong.huynh7") &&
				!who->get_save_2("phanthuong.huynh8") &&
				!who->get_save_2("phanthuong.huynh9") &&
				!who->get_save_2("phanthuong.huynh10") &&
				!who->get_save_2("phanthuong.huynh11") &&
				!who->get_save_2("phanthuong.huynh12") &&
				!who->get_save_2("phanthuong.huynh13") &&
				!who->get_save_2("phanthuong.huynh14") &&
				!who->get_save_2("phanthuong.huynh15") &&
				!who->get_save_2("phanthuong.huynh16") &&
				!who->get_save_2("phanthuong.huynh17"))
			{
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nNgươi không đủ điều kiện nhận thưởng.\n"ESC"Rời khỏi", me->get_name()));
				return;
			}
			if (who->get_save_2("phanthuong.huynh1") >= 1)// 35
			{
				if (USER_INVENTORY_D->get_free_count(who) < 4)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 4 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.huynh1", -1);//1
				who->add_exp(100000);

				item = new("/item/std/8000");
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/std/8000");
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/sell/ruongdutru");
				item->set_no_give(1);
				item->set_no_sell(1);
				item->set_amount(1);
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/sell/ruongdutru");
				item->set_no_give(1);
				item->set_no_sell(1);
				item->set_amount(1);
				p = item->move2(who, -1);
				item->add_to_user(p);

				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng kết nghĩa cấp 35.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng kết nghĩa cấp 35");
				return;
			}
			if (who->get_save_2("phanthuong.huynh2") >= 1)// 50
			{
				if (USER_INVENTORY_D->get_free_count(who) < 3)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 3 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.huynh2", -1);//10
				who->add_exp(150000);
				who->add_cash(20000);

				item = new("/item/test2/block/0007");
				item->set_amount(10);
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/test2/block/0009");
				item->set_amount(10);
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/TuiLinhThach/NgauNhien/1");
				item->set_no_give(1);
				item->set_no_sell(1);
				item->set_level(1);
				p = item->move2(who, -1);
				item->add_to_user(p);

				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng kết nghĩa cấp 50.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng kết nghĩa cấp 50");
				return;
			}
			if (who->get_save_2("phanthuong.huynh3") >= 1)//60
			{
				if (USER_INVENTORY_D->get_free_count(who) < 4)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 4 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.huynh3", -1);//30
				who->add_exp(200000);
				who->add_cash(50000);

				item = new("/item/test2/block/0007");
				item->set_amount(30);
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/test2/block/0009");
				item->set_amount(30);
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/huynhde/0032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/08/0800");
				p = item->move2(who, -1);
				item->add_to_user(p);

				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng kết nghĩa cấp 60.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng kết nghĩa cấp 60");
				return;
			}
			if (who->get_save_2("phanthuong.huynh100") >= 1)// 70
			{
				if (USER_INVENTORY_D->get_free_count(who) < 1)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 1 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.huynh100", -1);//60
				
				who->add_exp(500000);
				who->add_cash(50000);

				item = new("/item/huynhde/1032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);

				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng kết nghĩa cấp 70.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng kết nghĩa cấp 70");
				return;
			}
			if (who->get_save_2("phanthuong.huynh4") >= 1)// 80
			{
				if (USER_INVENTORY_D->get_free_count(who) < 2)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 2 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.huynh4", -1);//60
				nTmp2 = WEAPON_FILE->get_family_equip(who->get_fam_name(), who->get_gender(), 80, NECK_TYPE);
				cFile = nTmp2[random(sizeof(nTmp2))];
				
				if (load_object(cFile))
				{
					item = new(cFile);
					ITEM_EQUIP_D->init_equip_prop_3(item);
					for (i = 0; i < 3; i++)
					{
						"/sys/item/equip"->init_equip_prop_5(item);
						forge += "1";
						item->set("forge", forge);
					}
					item->set_hide(0);
					item->set_bind(4);
					p = item->move2(who, -1);
					item->add_to_user(p);
				}

				item = new("/item/huynhde/2032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);

				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng kết nghĩa cấp 80.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng kết nghĩa cấp 80");
				return;
			}

			//up level 90 (part 2)
			if (who->get_save_2("phanthuong.huynh5") >= 1)// 90
			{
				if (USER_INVENTORY_D->get_free_count(who) < 2)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 2 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.huynh5", -1);//120
				nTmp2 = WEAPON_FILE->get_family_equip(who->get_fam_name(), who->get_gender(), 90, WEAPON_TYPE);
				cFile = nTmp2[random(sizeof(nTmp2))];
				if (load_object(cFile))
				{
					item = new(cFile);
					ITEM_EQUIP_D->init_equip_prop_3(item);
					for (i = 0; i < 3; i++)
					{
						"/sys/item/equip"->init_equip_prop_5(item);
						forge += "1";
						item->set("forge", forge);
					}
					item->set_hide(0);
					item->set_bind(4);
					p = item->move2(who, -1);
					item->add_to_user(p);
				}

				/*item = new(sprintf("/item/zzz/macdich/%d", 9301 + random(10)));
				item->set_level(3);*/

				/*item = new(STONE_FILE->get_diamond_file());
				item->set_level(3);*/
				item = new("/item/huynhde/2032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);

				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng kết nghĩa cấp 90.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng kết nghĩa cấp 90");
				return;
			}
			if (who->get_save_2("phanthuong.huynh6") >= 1)// 100
			{
				if (USER_INVENTORY_D->get_free_count(who) < 4)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 4 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.huynh6", -1);//240
				item = new("/item/huynhde/0032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/huynhde/0032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/huynhde/1032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/huynhde/1032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);

				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng kết nghĩa cấp 100.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng kết nghĩa cấp 100");
				return;
			}
			if (who->get_save_2("phanthuong.huynh7") >= 1)// 110
			{
				if (USER_INVENTORY_D->get_free_count(who) < 2)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 2 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.huynh7", -1);//480
				item = new("/item/huynhde/2032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);

				item = new("/item/huynhde/2032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);

				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng kết nghĩa cấp 110.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng kết nghĩa cấp 110");
				return;
			}
			if (who->get_save_2("phanthuong.huynh8") >= 1)// 111
			{
				if (USER_INVENTORY_D->get_free_count(who) < 1)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 1 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.huynh8", -1);//960
				item = new("/item/huynhde/2032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng kết nghĩa cấp 111.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng kết nghĩa cấp 111");
				return;
			}
			if (who->get_save_2("phanthuong.huynh9") >= 1)// 112
			{
				if (USER_INVENTORY_D->get_free_count(who) < 1)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 1 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.huynh9", -1);//1920
				item = new("/item/huynhde/2032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng kết nghĩa cấp 112.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng kết nghĩa cấp 112");
				return;
			}
			if (who->get_save_2("phanthuong.huynh10") >= 1)// 113
			{
				if (USER_INVENTORY_D->get_free_count(who) < 1)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 1 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.huynh10", -1);//3840
				item = new("/item/huynhde/2032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng kết nghĩa cấp 113.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng kết nghĩa cấp 113");
				return;
			}
			if (who->get_save_2("phanthuong.huynh11") >= 1)// 114
			{
				if (USER_INVENTORY_D->get_free_count(who) < 1)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 1 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.huynh11", -1);//7680
				item = new("/item/huynhde/2032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng kết nghĩa cấp 114.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng kết nghĩa cấp 114");
				return;
			}
			if (who->get_save_2("phanthuong.huynh12") >= 1)// 115
			{
				if (USER_INVENTORY_D->get_free_count(who) < 1)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 1 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.huynh12", -1);//15360
				item = new("/item/huynhde/2032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng kết nghĩa cấp 115.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng kết nghĩa cấp 115");
				return;
			}
			if (who->get_save_2("phanthuong.huynh13") >= 1)// 116
			{
				if (USER_INVENTORY_D->get_free_count(who) < 1)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 1 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.huynh13", -1);//30720
				item = new("/item/huynhde/2032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng kết nghĩa cấp 116.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng kết nghĩa cấp 116");
				return;
			}
			if (who->get_save_2("phanthuong.huynh14") >= 1)// 117
			{
				if (USER_INVENTORY_D->get_free_count(who) < 1)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 1 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.huynh14", -1);//61440
				item = new("/item/huynhde/2032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng kết nghĩa cấp 117.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng kết nghĩa cấp 117");
				return;
			}
			if (who->get_save_2("phanthuong.huynh15") >= 1)// 118
			{
				if (USER_INVENTORY_D->get_free_count(who) < 1)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 1 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.huynh15", -1);//122880
				item = new("/item/huynhde/2032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng kết nghĩa cấp 118.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng kết nghĩa cấp 118");
				return;
			}
			if (who->get_save_2("phanthuong.huynh16") >= 1)// 119
			{
				if (USER_INVENTORY_D->get_free_count(who) < 1)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 1 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.huynh16", -1);//245760
				item = new("/item/huynhde/2032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng kết nghĩa cấp 119.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng kết nghĩa cấp 119");
				return;
			}
			if (who->get_save_2("phanthuong.huynh17") >= 1)// 120
			{
				if (USER_INVENTORY_D->get_free_count(who) < 1)
				{
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nHành trang của ngươi không đủ 1 ô trống.\n"ESC"Rời khỏi", me->get_name()));
					return;
				}
				who->add_save_2("phanthuong.huynh17", -1);//491520
				item = new("/item/huynhde/2032");
				//item = new(DA_CUONG_HOA);
				p = item->move2(who, -1);
				item->add_to_user(p);
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi đã nhận được phần thưởng kết nghĩa cấp 120.\n"ESC"Xác nhận", me->get_name()));
				send_user(who, "%c%s", ';', "Bạn đã nhận được phần thưởng kết nghĩa cấp 120");
				return;
			}
		}
		else
		{
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\nNgươi không đủ điều kiện nhận thưởng.\n"ESC"Rời khỏi", me->get_name()));
		}
		break;
	}
}

object check_baishi(object me, object who)
{
	int i, size;
	object* team, user;
	string leader;

	if (who->get_level() < 50)
	{
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n Đẳng cấp của ngươi chưa đủ 50 cấp !");
		return 0;
	}
	for (i = 0, size = sizeof(nTudi); i < size; i++)
	{
		if (!mapp(who->get_save_2(nTudi[i])))
			break;
	}
	if (i >= size)
	{
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n Ngươi đã kết nghĩa tối đa 15 tiểu Đệ rồi !");
		return 0;
	}
	if (!arrayp(team = who->get_team()) || sizeof(team) == 1)
	{
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n Trong hai ngươi có người không đáp ứng đủ điều kiện, xin hãy xem lại quy tắc !");
		return 0;
	}
	if (sizeof(team) > 2)
	{
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n Tổ đội 2 người mới có thể kết nghĩa !");
		return;
	}
	if (!stringp(leader = who->get_leader()) || to_int(leader) != who->get_number())
	{
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n Kết nghĩa yêu cầu người làm Huynh phải là đội trưởng, tiểu Đệ và đại Huynh phải chung 1 nhóm !");
		return 0;
	}
	team -= ({ who });
	user = team[0];
	if (user->get_level() < 1)
	{
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n Đẳng cấp của đối phương chưa đủ 1 cấp !");
		return 0;
	}
	if (user->get_level() > 30)
	{
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n Đẳng cấp của đối phương đã trên 30 cấp !");
		return 0;
	}
	if (who->get_level() <= user->get_level())
	{
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n Đẳng cấp của ngươi không cao hơn đối phương, không thể kết nghĩa !");
		return 0;
	}
	/*	if ( is_shifu(user) )
		{
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Đối phương đã là đại Huynh của người khác rồi !");
			return 0;
		}*/
	if (user->get_save_2("huynhde.de"))
	{
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n Đối phương đã có đại Huynh rồi !");
		return 0;
	}
	if (!inside_screen_2(who, user))
	{
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n Hãy gọi tiểu Đệ của ngươi đến gặp ta !");
		return 0;
	}
	return user;
}

void baishi(object me, object who, object user)
{
	int i, size;
	string cTudi;
	int j;
	int notExits;
	for (i = 0, size = sizeof(nTudi); i < size; i++)
	{
		if (!mapp(who->get_save_2(nTudi[i]))) {
			j = i;
			notExits = who->get_save_2(nTudi[i] + ".id");
			if (notExits == 0) {
				break;
			}
			break;
		}
	}
	if (i >= size)
	{
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n Ngươi đã kết nghĩa tối đa 15 tiểu Đệ rồi !");
		return;
	}
	cTudi = nTudi[j];
	who->set_save_2(cTudi + ".name", user->get_name());
	who->set_save_2(cTudi + ".id", user->get_number());
	who->set_save_2(cTudi + ".account", user->get_id());
	who->set_save_2(cTudi + ".level", user->get_level());

	user->set_save_2("huynhde.de.name", who->get_name());
	user->set_save_2("huynhde.de.id", who->get_number());
	user->set_save_2("huynhde.de.account", who->get_id());
	user->set_save_2("huynhde.de.level", who->get_level());

	log_file("huynhde.txt", sprintf("%s %s(%d) %s(%d) kết nghĩa\n", short_time(), who->get_name(), who->get_number(), user->get_name(), user->get_number()));
	who->log_legend(sprintf("Ngươi nhận %s(%d) làm tiểu Đệ", user->get_name(), user->get_number()));
	user->log_legend(sprintf("Ngươi nhận %s(%d) làm đại Huynh", who->get_name(), who->get_number()));
	send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n Chúc mừng ngươi đã có thêm 1 tiểu Đệ !");
	send_user(user, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n Chúc mừng ngươi đã có một người Huynh kết nghĩa !");
}

void query_shifu(object me, object who)
{
	int iFlag, id, iTime, i, size;
	string tmp;
	string account, name;
	object user, user1;
	mapping mpTmp;

	if (gone_time(who->get("baishi.query")) < 3)
	{
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n    Trong chốc lát nữa lại đến kiểm tra !\n");
		return;
	}
	who->set("baishi.query", time());
	if (!(mpTmp = who->get_save_2("huynhde.de")))
	{
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n Ngươi muốn nói gì?");
		return;
	}
	id = mpTmp["id"];
	account = mpTmp["account"];
	name = mpTmp["name"];
	if (!objectp(user = find_player(sprintf("%d", id))) && user_exist(account))
	{
		user1 = new(USER);
		user1->set_id(account);
		user1->restore();
		user = user1;
	}
	else
		iFlag = 1;
	if (objectp(user))
	{
		for (i = 0, size = sizeof(nTudi); i < size; i++)
		{
			if (!mapp(user->get_save_2(nTudi[i])))
				continue;
			if (user->get_save_2(nTudi[i] + ".id") != who->get_number())
				continue;
			break;
		}
		if (i >= size)
			iFlag = -1;
	}
	else
		iFlag = -1;        //不存在
	//iTime = gone_time(user->get_quit_time());
	if (objectp(user1))
		destruct(user1);
	if (iFlag == -1)
		return;
	if (iFlag == 1)
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + sprintf(":\n đại Huynh %s của ngươi hiện tại đang trong trò chơi !", name));
	else
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + sprintf(":\n đại Huynh %s của ngươi hiện tại không có trong trò chơi !", name));//, iTime/(3600*24)+1));

}
void query_tudi_list(object me, object who)
{
	int i, size, id;
	string result;
	mapping mpTmp;

	id = getoid(me);
	result = sprintf("%s\n Tiểu đệ của ngươi gồm có :\n", me->get_name());
	for (i = 0, size = sizeof(nTudi); i < size; i++)
	{
		if (!mapp(mpTmp = who->get_save_2(nTudi[i])))
			continue;
		result += sprintf(ESC"%s\ntalk %x# welcome.18.%d\n", mpTmp["name"], id, mpTmp["id"]);
	}
	result += ESC"Rời khỏi";
	send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
}

void query_tudi_list_2(object me, object who)
{
	int i, size, id;
	string result;
	mapping mpTmp;

	id = getoid(me);
	result = sprintf("%s\n Ngươi muốn giải thoát cho đệ nào của ngươi:\n", me->get_name());
	for (i = 0, size = sizeof(nTudi); i < size; i++)
	{
		if (!mapp(mpTmp = who->get_save_2(nTudi[i])))
			continue;
		result += sprintf(ESC"%s\ntalk %x# welcome.17.%d\n", mpTmp["name"], id, mpTmp["id"]);
	}
	result += ESC"Rời khỏi";
	send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
}

void giai_thoat(object me, object who, int id) {
	int iFlag, iTime, i, size, j;
	string tmp;
	string account, name;
	object user, user1;
	mapping mpTmp;
	string cTudi;

	j = -1;
	for (i = 0, size = sizeof(nTudi); i < size; i++)
	{
		if (!mapp(who->get_save_2(nTudi[i])))
			continue;
		if (who->get_save_2(nTudi[i] + ".id") != id)
			continue;
		j = i;
	}
	if (j == -1)
	{
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n    Ngươi muốn nói gì?");
		return;
	}
	mpTmp = who->get_save_2(nTudi[j]);
	id = mpTmp["id"];
	account = mpTmp["account"];
	name = mpTmp["name"];
	if (!objectp(user = find_player(sprintf("%d", id))) && user_exist(account))
	{
		user1 = new(USER);
		user1->set_id(account);
		user1->restore();
		user = user1;
	}
	else
		iFlag = 1;
	if (!objectp(user))
		return;        //不存在
	iTime = gone_time(user->get_quit_time());
	if (objectp(user1))
		destruct(user1);
	if (iFlag == -1)
		return;

	cTudi = nTudi[j];
	if (iFlag == 1) {

		who->delete_save_2(cTudi + ".name");
		who->delete_save_2(cTudi + ".id");
		who->delete_save_2(cTudi + ".account");
		who->delete_save_2(cTudi + ".level");
		who->delete_save_2(cTudi);

		user->delete_save_2("huynhde.de.name");
		user->delete_save_2("huynhde.de.id");
		user->delete_save_2("huynhde.de.account");
		user->delete_save_2("huynhde.de.level");
		user->delete_save_2("huynhde.de");

		log_file("huynhde.txt", sprintf("%s %s(%d) %s(%d) HỦY kết nghĩa\n", short_time(), who->get_name(), who->get_number(), user->get_name(), user->get_number()));
		who->log_legend(sprintf("Ngươi giải thoát huynh đệ cho %s(%d)", user->get_name(), user->get_number()));
		user->log_legend(sprintf("Huynh ngươi %s(%d) đã giải thoát cho ngươi", who->get_name(), who->get_number()));
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n Giải thoát huynh đệ thành công !");
		send_user(user, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n Từ bây giờ ngươi và huynh ngươi mỗi người mỗi đường rồi !");

	}
	else {
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + sprintf(":\n    tiểu Đệ %s của ngươi hiện tại không có trong trò chơi !", name));//,iTime/(3600*24)+1));
	}
}

void query_tudi(object me, object who, int id)
{
	int iFlag, iTime, i, size, j;
	string tmp;
	string account, name;
	object user, user1;
	mapping mpTmp;

	if (gone_time(who->get("baishi.query")) < 3)
	{
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n    Trong chốc lát nữa lại đến kiểm tra !\n");
		return;
	}
	who->set("baishi.query", time());
	j = -1;
	for (i = 0, size = sizeof(nTudi); i < size; i++)
	{
		if (!mapp(who->get_save_2(nTudi[i])))
			continue;
		if (who->get_save_2(nTudi[i] + ".id") != id)
			continue;
		j = i;
	}
	if (j == -1)
	{
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + ":\n    Ngươi muốn nói gì?");
		return;
	}
	mpTmp = who->get_save_2(nTudi[j]);
	id = mpTmp["id"];
	account = mpTmp["account"];
	name = mpTmp["name"];
	if (!objectp(user = find_player(sprintf("%d", id))) && user_exist(account))
	{
		user1 = new(USER);
		user1->set_id(account);
		user1->restore();
		user = user1;
	}
	else
		iFlag = 1;
	if (!objectp(user))
		return;        //不存在
	iTime = gone_time(user->get_quit_time());
	if (objectp(user1))
		destruct(user1);
	if (iFlag == -1)
		return;
	if (iFlag == 1)
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + sprintf(":\n    tiểu Đệ %s của ngươi hiện đang trong trò chơi !", name));
	else
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name() + sprintf(":\n    tiểu Đệ %s của ngươi hiện tại không có trong trò chơi !", name));//,iTime/(3600*24)+1));

}
int add_phanthuong(object who, int exp)
{
	int id, max, exp1, pot, level, level1, flag, iSave;
	int e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e100;
	int pot1, pot2, pot3, pot4, pot5, pot100;
	string account, name;
	mapping mpTmp;
	object user, user1;

	if (mapp(mpTmp = who->get_save_2("huynhde.de")))
		flag = 1;
	else
		return 0;

	id = mpTmp["id"];
	account = mpTmp["account"];
	name = mpTmp["name"];

	if (!objectp(user = find_player(sprintf("%d", id))) && user_exist(account))
	{
		user1 = new(USER);
		user1->set_id(account);
		user1->restore();
		user = user1;
	}

	if (!user)
		return 0;

	tell_user(who, "Huynh của ngươi: %s", name);
	tell_user(who, "Level của ngươi: %d", level);

	if (flag == 1)
	{
		level = who->get_level();
		level1 = mpTmp["level"];;
		if (level == 35)
		{
			e1 = 1;
			pot = 1;
		}
		else if (level == 50)
		{
			e2 = 1;
			pot1 = 1;
		}
		else if (level == 60)
		{
			e3 = 1;
			pot2 = 1;
		}
		else if (level == 70)
		{
			e100 = 1;
			pot100 = 1;
		}
		else if (level == 80)
		{
			e4 = 1;
			pot3 = 1;
		}
		else if (level == 90)
		{
			e5 = 1;
			pot4 = 1;
		}
		else if (level == 100)
		{
			e6 = 1;
			pot5 = 1;
		}
		else if (level == 110)
		{
			e7 = 1;
		}
		else if (level == 111)
		{
			e8 = 1;
		}
		else if (level == 112)
		{
			e9 = 1;
		}
		else if (level == 113)
		{
			e10 = 1;
		}
		else if (level == 114)
		{
			e11 = 1;
		}
		else if (level == 115)
		{
			e12 = 1;
		}
		else if (level == 116)
		{
			e13 = 1;
		}
		else if (level == 117)
		{
			e14 = 1;
		}
		else if (level == 118)
		{
			e15 = 1;
		}
		else if (level == 119)
		{
			e16 = 1;
		}
		else if (level == 120)
		{
			e17 = 1;
		}

		tell_user(who, "Level của huynh ngươi: %d", level1);
		tell_user(who, "điểm e1: %d", e1);

		if (level1 && e1)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh1", e1);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 35 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e2)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh2", e2);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 50 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e3)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh3", e3);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 60 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e100)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh100", e100);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 70 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e4)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh4", e4);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 80 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e5)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh5", e5);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 90 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e6)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh6", e6);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 100 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e7)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh7", e7);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 110 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e8)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh8", e8);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 111 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e9)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh9", e9);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 112 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e10)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh10", e10);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 113 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e11)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh11", e11);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 114 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e12)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh12", e12);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 115 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e13)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh13", e13);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 116 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e14)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh14", e14);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 117 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e15)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh15", e15);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 118 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e16)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh16", e16);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 119 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e17)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh17", e17);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 120 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (pot)
		{
			who->add_save_2("phanthuong.de", pot);
			MAILBOX->sys_mail(who->get_id(), who->get_number(), "Bạn chăm chỉ rèn luyện, nay đã có thể nhận phường thưởng cấp 35 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !");
		}
		if (pot1)
		{
			who->add_save_2("phanthuong.de1", pot1);
			MAILBOX->sys_mail(who->get_id(), who->get_number(), "Bạn chăm chỉ rèn luyện, nay đã có thể nhận phường thưởng cấp 50 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !");
		}
		if (pot2)
		{
			who->add_save_2("phanthuong.de2", pot2);
			MAILBOX->sys_mail(who->get_id(), who->get_number(), "Bạn chăm chỉ rèn luyện, nay đã có thể nhận phường thưởng cấp 60 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !");
		}
		if (pot100)
		{
			who->add_save_2("phanthuong.de100", pot100);
			MAILBOX->sys_mail(who->get_id(), who->get_number(), "Bạn chăm chỉ rèn luyện, nay đã có thể nhận phường thưởng cấp 70 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !");
		}
		if (pot3)
		{
			who->add_save_2("phanthuong.de3", pot3);
			MAILBOX->sys_mail(who->get_id(), who->get_number(), "Bạn chăm chỉ rèn luyện, nay đã có thể nhận phường thưởng cấp 80 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !");
		}
		if (pot4)
		{
			who->add_save_2("phanthuong.de4", pot4);
			MAILBOX->sys_mail(who->get_id(), who->get_number(), "Bạn chăm chỉ rèn luyện, nay đã có thể nhận phường thưởng cấp 90 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !");
		}
		if (pot5)
		{
			who->add_save_2("phanthuong.de5", pot5);
			MAILBOX->sys_mail(who->get_id(), who->get_number(), "Bạn chăm chỉ rèn luyện, nay đã có thể nhận phường thưởng cấp 100 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !");
		}
	}
	if (user1)
	{
		if (iSave)
			user1->save();
		destruct(user1);
	}
	return exp;
}

void phanthuong_huynhde(object who)
{
	int id, max, exp1, pot, level, level1, flag, iSave;
	int e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e100;
	int pot1, pot2, pot3, pot4, pot5, pot100;
	string account, name;
	mapping mpTmp;
	object user, user1;

	if (mapp(mpTmp = who->get_save_2("huynhde.de")))
		flag = 1;
	else
		return ;

	id = mpTmp["id"];
	account = mpTmp["account"];
	name = mpTmp["name"];

	if (!objectp(user = find_player(sprintf("%d", id))) && user_exist(account))
	{
		user1 = new(USER);
		user1->set_id(account);
		user1->restore();
		user = user1;
	}

	if (!user)
		return ;

	//tell_user(who, "Huynh của ngươi: %s", name);
	//tell_user(who, "Level của ngươi: %d", level);

	if (flag == 1)
	{
		level = who->get_level();
		level1 = mpTmp["level"];;
		if (level == 35)
		{
			e1 = 1;
			pot = 1;
		}
		else if (level == 50)
		{
			e2 = 1;
			pot1 = 1;
		}
		else if (level == 60)
		{
			e3 = 1;
			pot2 = 1;
		}
		else if (level == 70)
		{
			e100 = 1;
			pot100 = 1;
		}
		else if (level == 80)
		{
			e4 = 1;
			pot3 = 1;
		}
		else if (level == 90)
		{
			e5 = 1;
			pot4 = 1;
		}
		else if (level == 100)
		{
			e6 = 1;
			pot5 = 1;
		}
		else if (level == 110)
		{
			e7 = 1;
		}
		else if (level == 111)
		{
			e8 = 1;
		}
		else if (level == 112)
		{
			e9 = 1;
		}
		else if (level == 113)
		{
			e10 = 1;
		}
		else if (level == 114)
		{
			e11 = 1;
		}
		else if (level == 115)
		{
			e12 = 1;
		}
		else if (level == 116)
		{
			e13 = 1;
		}
		else if (level == 117)
		{
			e14 = 1;
		}
		else if (level == 118)
		{
			e15 = 1;
		}
		else if (level == 119)
		{
			e16 = 1;
		}
		else if (level == 120)
		{
			e17 = 1;
		}

		//tell_user(who, "Level của huynh ngươi: %d", level1);
		//tell_user(who, "điểm e1: %d", e1);

		if (level1 && e1)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh1", e1);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 35 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e2)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh2", e2);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 50 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e3)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh3", e3);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 60 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e100)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh100", e100);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 70 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e4)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh4", e4);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 80 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e5)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh5", e5);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 90 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e6)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh6", e6);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 100 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e7)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh7", e7);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 110 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e8)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh8", e8);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 111 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e9)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh9", e9);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 112 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e10)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh10", e10);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 113 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e11)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh11", e11);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 114 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e12)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh12", e12);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 115 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e13)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh13", e13);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 116 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e14)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh14", e14);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 117 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e15)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh15", e15);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 118 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e16)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh16", e16);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 119 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (level1 && e17)
		{
			iSave = 1;
			user->add_save_2("phanthuong.huynh17", e17);
			MAILBOX->sys_mail(account, id, sprintf("Tiểu đệ %s của bạn Đẳng cấp có tiến bộ, bạn đã có thể nhận Phần thưởng cấp 120 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !", who->get_name()));
		}
		if (pot)
		{
			who->add_save_2("phanthuong.de", pot);
			MAILBOX->sys_mail(who->get_id(), who->get_number(), "Bạn chăm chỉ rèn luyện, nay đã có thể nhận phường thưởng cấp 35 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !");
		}
		if (pot1)
		{
			who->add_save_2("phanthuong.de1", pot1);
			MAILBOX->sys_mail(who->get_id(), who->get_number(), "Bạn chăm chỉ rèn luyện, nay đã có thể nhận phường thưởng cấp 50 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !");
		}
		if (pot2)
		{
			who->add_save_2("phanthuong.de2", pot2);
			MAILBOX->sys_mail(who->get_id(), who->get_number(), "Bạn chăm chỉ rèn luyện, nay đã có thể nhận phường thưởng cấp 60 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !");
		}
		if (pot100)
		{
			who->add_save_2("phanthuong.de100", pot100);
			MAILBOX->sys_mail(who->get_id(), who->get_number(), "Bạn chăm chỉ rèn luyện, nay đã có thể nhận phường thưởng cấp 70 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !");
		}
		if (pot3)
		{
			who->add_save_2("phanthuong.de3", pot3);
			MAILBOX->sys_mail(who->get_id(), who->get_number(), "Bạn chăm chỉ rèn luyện, nay đã có thể nhận phường thưởng cấp 80 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !");
		}
		if (pot4)
		{
			who->add_save_2("phanthuong.de4", pot4);
			MAILBOX->sys_mail(who->get_id(), who->get_number(), "Bạn chăm chỉ rèn luyện, nay đã có thể nhận phường thưởng cấp 90 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !");
		}
		if (pot5)
		{
			who->add_save_2("phanthuong.de5", pot5);
			MAILBOX->sys_mail(who->get_id(), who->get_number(), "Bạn chăm chỉ rèn luyện, nay đã có thể nhận phường thưởng cấp 100 tại Mạc Địch Huynh Đệ Tổng Quản, xin chúc mừng !");
		}
	}
	if (user1)
	{
		if (iSave)
			user1->save();
		destruct(user1);
	}
	//return ;
}