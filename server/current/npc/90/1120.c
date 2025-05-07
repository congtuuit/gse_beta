
#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <cmd.h>
#include <ansi.h>
#include <task.h>
inherit OFFICER;

// 函数：师父识别
int is_master() { return 1; }

// 函数：获取门派名称
string get_fam_name() { return "Đào Hoa Nguyên"; }

// 函数：获取升级顺序
int get_fam_order() { return 2; }

// 函数：获取人物造型
int get_char_picid() { return 9112; }

// 函数：小贩识别
int is_seller() { return 1; }

// 有自己的do_look函数
int is_self_look() { return 1; }

int get_level() { return 120; }

void do_skill();
void do_quest();
void do_giveup();
void do_giveup2();
void do_apprentice(string arg);
void accept_quest();
void task_info();
void valentine(string arg);
void valentine2();
// 函数：构造处理
void create()
{
	set_name("Vong Tình Bà Bà");

	set_skill(0211, 120);
	set_skill(0371, 120);
	set_skill(0212, 120);
	set_skill(0372, 120);
	set_skill(0316, 120);
	set_skill(0373, 120);
	set_skill(0317, 120);
	set_skill(0374, 120);
	set_skill(0319, 120);
	set_skill(0375, 120);
	set_2("talk", ([
		"skills":(: do_skill:),
			"quest" : (: do_quest:),
			"giveup" : (: do_giveup:),
			"giveup2" : (: do_giveup2:),
			"apprentice" : (: do_apprentice:),
			"accept_quest" : (: accept_quest:),
			"task_info" : (: task_info:),
			"valentine" : (: valentine:),
			"valentine2" : (: valentine2:),
	]));
	set_2("good", ([
		"01":"/item/70/0010",
			"02" : "/item/70/1020",
			"03" : "/item/60/0010",
			"04" : "/item/60/1020",
			"05" : "/item/61/0010",
			"06" : "/item/61/1020",
			"07" : "/item/65/0010",
			"08" : "/item/65/1020",
			"09" : "/item/66/0010",
			"10" : "/item/66/1020",
			"11" : "/item/88/0010",
			"12" : "/item/88/1020",
			"13" : "/item/87/1010",
			"14" : "/item/87/1020",
	]));
	setup();
}

void do_look(object who)
{
	object npc, me = this_object();
	int i, id = getoid(me);
	object item;
	string cmd, tmp = "";
	string cmds = "：\nTôi có thể làm gì cho bà già này?Thưa bà, tôi rất bận, nếu bà có việc gì quan trọng, xin hãy tìm hai người học việc của tôi trước.\n";
	if (who->get_quest("valentine.flag") == 5)
	{
		cmd = sprintf("talk %x# valentine.1\n", id);
		tmp = ESC "Truyền thuyết về Valentine's Day\n" + cmd;
		send_user(who, "%c%s", ':', get_name() + cmds +
			tmp +
			ESC "Rời khỏi\nCLOSE\n");
	}
	else if (who->get_quest("valentine.flag") == 6 && who->get_quest("valentine.type") != 1)
	{
		cmd = sprintf("talk %x# valentine.3\n", id);
		tmp = ESC "Thiên thần yêu sắc\n" + cmd;
		send_user(who, "%c%s", ':', get_name() + cmds +
			tmp +
			ESC "Rời khỏi\nCLOSE\n");
	}
	else if (who->get_quest("valentine.flag") == 6 && who->get_quest("valentine.bonus") == 1 && objectp(item = present("Son đỏ", who, 1, MAX_CARRY)) && objectp(item = present("Cái lược", who, 1, MAX_CARRY)) && objectp(item = present("Cây trâm", who, 1, MAX_CARRY)))
	{
		cmd = sprintf("talk %x# valentine.4\n", id);
		tmp = ESC "Thiên thần yêu sắc\n" + cmd;
		send_user(who, "%c%s", ':', get_name() + cmds +
			tmp +
			ESC "Rời khỏi\nCLOSE\n");
	}
	else if (who->get_quest("valentine.flag") == 7 && !objectp(item = present("Đậu Socola", who, 1, MAX_CARRY)))
	{
		cmd = sprintf("talk %x# valentine.6\n", id);
		tmp = ESC "Đậu Socola\n" + cmd;
		send_user(who, "%c%s", ':', get_name() + cmds +
			tmp +
			ESC "Rời khỏi\nCLOSE\n");
	}

	else
		TASK_MASTER_D->do_look(who, this_object());
}

void do_skill() { LEARN_CMD->learn_menu(this_player(), this_object()); }

void do_quest() { TASK_MASTER_D->do_quest(this_player(), this_object()); }

void do_giveup() { TASK_MASTER_D->do_giveup(this_player(), this_object()); }

void do_giveup2() { TASK_MASTER_D->do_giveup2(this_player(), this_object()); }

void do_apprentice(string arg) { TASK_APPRENTICE_D->do_apprentice(this_player(), this_object(), arg); }
//Nhận nhiệm vụ
void accept_quest() { TASK_MASTER_D->accept_quest(this_player(), this_object()); }
void task_info() { TASK_MASTER_D->task_info(this_player(), this_object()); }

int accept_object(object player, object obj)
{
	object who = this_object();
	return TASK_MASTER_D->accept_object(who, player, obj);
}

void delete_family_skill(object who)
{
	mapping skls;
	object file;
	string* name, result;
	int skill, level, i, size;

	skls = get_skill_dbase();
	name = keys(skls);
	size = sizeof(name);
	result = sprintf("Anh quyết định đi“%s”Bên dưới cánh cửa!：", get_fam_name());
	for (i = 0; i < size; i++)
	{
		skill = to_int(name[i]);
		if (level = who->get_skill(skill))
		{
			if (file = load_object(SKILL->get_skill_file(skill)))
				result = sprintf("%s%s(%d) ", result, file->get_name(), level);
			else    result = sprintf("%s%s(%d) ", result, name[i], level);
		}
		who->delete_skill(skill);
	}

	who->log_legend(result);
}


void valentine(string arg)
{
	object me = this_object();
	__FILE__->do_valentine(me, arg);
}

void do_valentine(object me, string arg)
{
	int flag, p, i, x, y, z, id;
	object who, item, map, item214_1, item214_2, item214_3;
	string cmd, cWord, tmp = "";
	who = this_player();
	flag = to_int(arg);
	who->set_time("talk", 0);
	switch (flag)
	{
	case 1:
		if (who->get_quest("valentine.flag") == 5)
		{
			cWord = sprintf(me->get_name() + "：\n   Cô bé dễ thương, đến hỏi mẹ vợ về ngày Valentine？\n    Trời ơi, tôi cũng là một cô gái thiên thần. Tôi cũng muốn mặc đồ vào. Cô có loại mỹ phẩm nào hay cho tôi không？\n");
			send_user(who, "%c%s", ':', cWord + "\n" +
				ESC + sprintf("Hoàn thành nhiệm vụ。\ntalk %x# valentine.2\n", getoid(me)) +
				ESC "Rời khỏi。\nCLOSE\n");
		}
		break;
	case 2:
		if (who->get_quest("valentine.flag") == 5)
		{
			if (who->get_quest("valentine.flag") == 5)
			{
				who->add_exp(500);
				who->set_quest("valentine.flag", 6);
				who->set_quest("valentine.type", 0);
				send_user(who, "%c%c%c%w%w%w%s", 0x51, 1, 4, TID_VALENTINE, 5, 0, "");
				send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 5, "");
				send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "");
				who->add_potential(2000);
				tell_user(who, ECHO"Hoàn thành nhiệm vụ - tiềm năng: +2000");
			}
		}
		break;
	case 3:
		if (who->get_quest("valentine.flag") == 6 && who->get_quest("valentine.type") != 1)
		{
			z = ({ 10,20,30,40,50,60,70 })[random(7)];
			if (!(p = efun::get_xy_point(z, IS_CHAR_BLOCK))) return;
			x = (p % 1000000) / 1000;  y = p % 1000;
			if (!objectp(map = get_map_object(z)) || !map->is_scene()) return;
			who->set_quest("valentine.name", "Valentine's Day hooligans");
			who->set("valentine.x", x);
			who->set("valentine.y", y);
			who->set("valentine.z", z);
			cWord = sprintf(me->get_name() + "：\n    Trời ơi, tôi cũng là một cô gái thiên thần. Tôi cũng muốn mặc đồ vào. Cô có loại mỹ phẩm nào hay cho tôi không？\n    如果没有的话，不如去一趟%s国的（%d，%d）吧，去城外找找那些流氓，他们身上或许就带着用来讨好女孩子的胭脂、梳子和头钗呢！\n", map->get_name(), x, y);
			send_user(who, "%c%s", ':', cWord + "\n" +
				ESC + sprintf("Nhận nhiệm vụ。\ntalk %x# valentine2\n", getoid(me)) +
				ESC "Rời khỏi。\nCLOSE\n");
		}
		break;
	case 4:
		if (who->get_quest("valentine.flag") == 6 && who->get_quest("valentine.bonus") == 1 && objectp(item = present("Son đỏ", who, 1, MAX_CARRY)) && objectp(item = present("Cái lược", who, 1, MAX_CARRY)) && objectp(item = present("Cây trâm", who, 1, MAX_CARRY)))
		{
			cWord = sprintf(me->get_name() + "：\n    Phải, đây là những thứ tôi phải mặc đồ, cô có thể quay lại với tôi sau, tôi sẽ chỉ cô cách làm lấy Sô-cô-la。\n");
			send_user(who, "%c%s", ':', cWord + "\n" +
				ESC + sprintf("Hoàn thành nhiệm vụ。\ntalk %x# valentine.5\n", getoid(me)) +
				ESC "Rời khỏi。\nCLOSE\n");
		}
		break;
	case 5:
		if (who->get_quest("valentine.flag") == 6 && who->get_quest("valentine.bonus") == 1 && objectp(item = present("Son đỏ", who, 1, MAX_CARRY)) && objectp(item = present("Cái lược", who, 1, MAX_CARRY)) && objectp(item = present("Cây trâm", who, 1, MAX_CARRY)))
		{
			if (!objectp(item214_1 = present("Son đỏ", who, 1, MAX_CARRY)))
			{
				send_user(who, "%c%s", '!', "Con không có Son đỏ");
				return;
			}
			if (!objectp(item214_1 = present("Cái lược", who, 1, MAX_CARRY)))
			{
				send_user(who, "%c%s", '!', "Con không có Cái lược");
				return;
			}
			if (!objectp(item214_1 = present("Cây trâm", who, 1, MAX_CARRY)))
			{
				send_user(who, "%c%s", '!', "Con không có chiếc trâm mẹ chồng con muốn");
				return;
			}
			if (objectp(item214_1 = present("Son đỏ", who, 1, MAX_CARRY)))
			{
				item214_1->remove_from_user();
				destruct(item214_1);
			}
			if (objectp(item214_1 = present("Cái lược", who, 1, MAX_CARRY)))
			{
				item214_1->remove_from_user();
				destruct(item214_1);
			}
			if (objectp(item214_1 = present("Cây trâm", who, 1, MAX_CARRY)))
			{
				item214_1->remove_from_user();
				destruct(item214_1);
			}
			who->add_exp(500);
			who->add_potential(2000);
			tell_user(who, ECHO"Hoàn thành nhiệm vụ - tiềm năng: +2000");
			who->set_quest("valentine.flag", 7);
			send_user(who, "%c%c%c%w%w%w%s", 0x51, 1, 4, TID_VALENTINE, 6, 0, "");
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 6, "");
			send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "");
		}
		break;
	case 6:
		if (who->get_quest("valentine.flag") == 7 && !objectp(item = present("Đậu Socola", who, 1, MAX_CARRY)))
		{
			cWord = sprintf(me->get_name() + "：\n    Cảm ơn cô bé!Về lễ tình nhân, điều quan trọng nhất là các chàng trai tặng Son đỏ cho các cô gái cho các chàng trai s ô-cô-la!ỒAnh mua sô-cô-la ở đâu?Tôi không biết, nhưng t ôi có chút bối rối ở đây Đậu Socola，Ta nghĩ Hồng Nương biết cách tạo Đậu Socola Nó làm bằng chocolate。\n");
			send_user(who, "%c%s", ':', cWord + "\n" +
				ESC + sprintf("Nhận nhiệm vụ。\ntalk %x# valentine.7\n", getoid(me)) +
				ESC "Rời khỏi。\nCLOSE\n");
		}
		break;
	case 7:
		if (who->get_quest("valentine.flag") == 7 && !objectp(item = present("Đậu Socola", who, 1, MAX_CARRY)))
		{
			item214_1 = new ("item/04/0425");    //Đậu Socola
			if (item214_1)
			{
				if (USER_INVENTORY_D->can_carry(who, item214_1) >= 1)
				{
					p = item214_1->move(who, -1);
					item214_1->add_to_user(p);
					send_user(who, "%c%s", '!', "Lấy "HIR"Đậu Socola"NOR"một ít");
					send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_VALENTINE, "Valentine Day");
					send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_VALENTINE, 7, "Đậu Socola");
					send_user(who, "%c%s", '!', "Bạn đã nhận được Valentine Day————Đậu Socola！");
				}
				else
				{
					destruct(item214_1);
					send_user(who, "%c%s", '!', "Hành trang không đủ chỗ trống！");
				}
			}
		}
		break;
	}
}

void valentine2() { "/sys/party/valentine"->do_valentine5_call(this_player(), this_object()); }

