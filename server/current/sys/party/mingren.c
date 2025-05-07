#include <npc.h>
#include <cmd.h>
#include <time.h>
#include <ansi.h>

#define FILE_SAVE "data/mingren" SAVE_EXTENSION
#define FILE_SHOUXI "sys/school/shouxi"
#define FILE_TITLE "sys/sys/title"
#define FILE_ENERGY "sys/user/energy"
#define FILE_UPDATE "mingren_update.txt"
#define DEBUG(arg) ;

inherit DBASE_F;
inherit SAVE_F;

static string *SchoolName = ({
	"Đào Hoa Nguyên",
	"Cấm Vệ Quân",
	"Thục Sơn",
	"Côn Luân",
	"Mao Sơn",
	"Vân Mộng Cốc",
	"Đường Môn",
});
mapping Exp_players, Cash_players, Teacher_players, Gongde_players, Dizi_players;
mapping Enable_id = ([]);

int xy_get_fam_id(string name);
void delete_mingren_title(object who, string titlecode);
int get_sum_skills_level(object who);
int get_mingren_power(object who);
void send_mingren_data(object who, mapping players, string type);

void SAVE_BINARY() {}

string get_save_file() { return FILE_SAVE; }

void create()
{
	restore();
}
void do_look(object who)
{
	int i, size, level, point, xy_family;
	string name, family;
	if (!mapp(Exp_players) && !mapp(Cash_players) && !mapp(Teacher_players) && !mapp(Gongde_players) && !mapp(Dizi_players))
	{
		// notify( HIY"Danh nhân đường trước mắt không thay đổi");
		return;
	}
	send_user(who, "%c%c", 0xA9, 0);
	send_mingren_data(who, Exp_players, "power");
	send_mingren_data(who, Cash_players, "cash");
	send_mingren_data(who, Teacher_players, "teacher");
	send_mingren_data(who, Gongde_players, "gongde");
	if (mapp(Dizi_players))
	{
		size = sizeof(SchoolName);
		DEBUG(sprintf("测试-->Dizi_players size=%d", size));
		for (i = 0; i < size; i++)
		{
			if (!mapp(Dizi_players[SchoolName[i]]))
				continue;
			family = Dizi_players[SchoolName[i]]["family"];
			xy_family = xy_get_fam_id(family);
			name = Dizi_players[SchoolName[i]]["name"];
			DEBUG(sprintf("测试-->Dizi_players name=%s", name));
			level = Dizi_players[SchoolName[i]]["level"];
			point = Dizi_players[SchoolName[i]]["point"];
			send_user(who, "%c%c%c%c%d%s", 0xA9, 5, xy_family, level, point, name);
		}
	}
	DEBUG(sprintf("测试-->do_look "));
}
void do_look1(object who)
{
	int i, size, level, point, xy_family;
	string name, family;
	if (!mapp(Exp_players))
	{
		//	notify( HIY"Bảng xếp hạng Thực Lực trước mắt không thay đổi");
		return;
	}
	send_user(who, "%c%c", 0xA9, 0);
	send_mingren_data(who, Exp_players, "power");
	DEBUG(sprintf("测试-->do_look1 "));
}
void do_look2(object who)
{
	int i, size, level, point, xy_family;
	string name, family;
	if (!mapp(Cash_players))
	{
		//	notify( HIY"Bảng xếp hạng Phú hộ trước mắt không thay đổi");
		return;
	}
	send_user(who, "%c%c", 0xA9, 0);
	send_mingren_data(who, Cash_players, "cash");
	DEBUG(sprintf("测试-->do_look2 "));
}
void do_look3(object who)
{
	int i, size, level, point, xy_family;
	string name, family;
	if (!mapp(Teacher_players))
	{
		//	notify( HIY"Bảng xếp hạng Danh Sư trước mắt không thay đổi");
		return;
	}
	send_user(who, "%c%c", 0xA9, 0);
	send_mingren_data(who, Teacher_players, "teacher");
	DEBUG(sprintf("测试-->do_look3 "));
}

// Bang Công đức
void do_look4(object who)
{
	int i, size, level, point, xy_family;
	string name, family;
	if (!mapp(Gongde_players))
	{
		//	notify( HIY"Bảng xếp hạng Công Đức trước mắt không thay đổi");
		return;
	}
	send_user(who, "%c%c", 0xA9, 0);
	send_mingren_data(who, Gongde_players, "gongde");
	DEBUG(sprintf("测试-->do_look4 "));
}
void do_look5(object who)
{
	int i, size, level, point, xy_family;
	string name, family;
	if (!mapp(Dizi_players))
	{
		//	notify( HIY"Bảng xếp hạng Đại Đệ Tử Môn Phái trước mắt không thay đổi");
		return;
	}
	send_user(who, "%c%c", 0xA9, 0);
	send_mingren_data(who, Dizi_players, "winners");
	if (mapp(Dizi_players)) // 首席大弟子
	{
		size = sizeof(SchoolName);
		DEBUG(sprintf("测试-->Dizi_players size=%d", size));
		for (i = 0; i < size; i++)
		{
			if (!mapp(Dizi_players[SchoolName[i]]))
				continue;
			family = Dizi_players[SchoolName[i]]["family"];
			xy_family = xy_get_fam_id(family);
			name = Dizi_players[SchoolName[i]]["name"];
			DEBUG(sprintf("测试-->Dizi_players name=%s", name));
			level = Dizi_players[SchoolName[i]]["level"];
			point = Dizi_players[SchoolName[i]]["point"];
			send_user(who, "%c%c%c%c%d%s", 0xA9, 5, xy_family, level, point, name);
		}
	}
	DEBUG(sprintf("测试-->do_look5 "));
}

void check_time()
{
	int i, size;
	object *user;
	mixed mixtime;

	mixtime = localtime(get_party_time());
	DEBUG(sprintf("check_time, Giờ chơi hiện tại %s", short_time(get_party_time())));

	if (!arrayp(user = USER_D->get_user()))
		return;

	size = sizeof(user);
	for (i = 0; i < size; i++)
	{
		DEBUG("Test-->Cập nhật thứ hạng cho tất cả người chơi trực tuyến lần cuối trước khi phát hành");
		DEBUG(sprintf("Kiểm tra->Danh mục số lượng người chơi trực tuyến hiện tại %d", size));
		if (user[i]->is_user())
		{
			__FILE__->check_mingren_downline(user[i]);
		}
	}

	__FILE__->create_mingren_board();
}

void create_mingren_board()
{
	int i, j, size1, size2, id, iTime;
	mapping expTmp, cashTmp, teacherTmp, gongdeTmp, diziTmp;
	string *key, *xy_delete_id = ({});
	string *titlecode = ({"A020", "A021", "A022", "A023"});
	object who;

	xy_delete_id = keys(Enable_id);
	size1 = sizeof(xy_delete_id);
	size2 = sizeof(titlecode);
	DEBUG(sprintf("size=%d ", size1));
	if (size1)
	{
		for (i = 0; i < size1; i++)
		{
			if (objectp(who = find_char(xy_delete_id[i])))
			{
				for (j = 0; j < size2; j++)
				{
					delete_mingren_title(who, titlecode[j]);
				}
			}
		}
	}

	Enable_id = ([]);
	if (mapp(expTmp = get_save_2("exp_player")))
	{
		Exp_players = copy(expTmp);
		__FILE__->add_mingren_title(expTmp, "A020");
	}
	if (mapp(cashTmp = get_save_2("cash_player")))
	{
		Cash_players = copy(cashTmp);
		__FILE__->add_mingren_title(cashTmp, "A021");
	}
	if (mapp(gongdeTmp = get_save_2("gongde_player")))
	{
		Gongde_players = copy(gongdeTmp);
		__FILE__->add_mingren_title(gongdeTmp, "A022");
	}
	if (mapp(teacherTmp = get_save_2("teacher_player")))
	{
		Teacher_players = copy(teacherTmp);
		__FILE__->add_mingren_title(teacherTmp, "A023");
	}

	if (mapp(diziTmp = FILE_SHOUXI->get_save_2("winners")))
		Dizi_players = copy(diziTmp);

	log_file(FILE_UPDATE, sprintf("%s Danh nhân đường đổi mới\n", short_time(get_party_time())));
	save();
}

void add_mingren_title(mapping players, string title)
{
	int iTime, id, *arr_id = ({});
	int ap, cp;
	object who;

	mixed *mixTime;

	iTime = time();
	mixTime = localtime(iTime);

	if (mapp(players))
	{
		id = players["pos"][sprintf("%d", 1)];
		if (!(arr_id = Enable_id[sprintf("%d", id)]))
		{
			arr_id = ({title});
		}
		else
		{
			arr_id += ({title});
		}
		if (objectp(who = find_char(sprintf("%d", id))))
		{
			//
			/*if (mixTime[TIME_MDAY] >= 21 && mixTime[TIME_WDAY] == 0) {
				who->set_save_2("Bonus.Title", title);
				who->set_save_2("Bonus.Point", 1);
			}*/

			who->add_title(title);
			who->show_title(title);
		};
		Enable_id[sprintf("%d", id)] = arr_id;
		save();
	}
}

void check_mingren_downline(object who)
{
	int i, size, id, id1, pos;
	mapping power = ([]);
	power["tudi"] = sizeof(who->get_apprentice());
	__FILE__->sort_mingren_power(who, "exp_player");
	__FILE__->sort_board(who, "cash_player", "cash");
	__FILE__->sort_board(who, "gongde_player", "gongde");
	if (power["tudi"] > 0)
	{
		__FILE__->sort_board(who, "teacher_player", "tudi");
	}
}

void check_mingren_upline(object who)
{
	int i, size;
	string *xy_titlecode = ({"A020", "A021", "A022", "A023"});
	string *dizi_titlecode = ({
		"F001",
		"F002",
		"F003",
		"F004",
		"F005",
		"F006",
		"F007",
	});
	size = sizeof(xy_titlecode);
	for (i = 0; i < size; i++)
	{
		if (who->is_user())
		{
			__FILE__->check_mingren_upline_title(who, xy_titlecode[i]);
		}
	}

	size = sizeof(dizi_titlecode);
	for (i = 0; i < size; i++)
	{
		if (who->have_title(dizi_titlecode[i]))
			__FILE__->show_msg(who, dizi_titlecode[i]);
	}
}

void check_mingren_upline_title(object who, string titlecode)
{
	int i, size, id, ap, cp;
	string *xy_id_table, *xy_titlecode_table;
	if (!who)
	{
		return;
	}

	id = who->get_number();
	xy_id_table = keys(Enable_id);
	xy_titlecode_table = Enable_id[sprintf("%d", id)];
	DEBUG(sprintf("测试-->xy_check_upline_title() id=%d sizeof(xy_id_table)=%d titlecode=%s", id, sizeof(xy_id_table), titlecode));
	if (who->have_title(titlecode))
	{
		if ((member_array(sprintf("%d", id), xy_id_table) != -1) && (member_array(titlecode, xy_titlecode_table) != -1))
		{
			__FILE__->show_msg(who, titlecode);
			return;
		}
		else
		{
			__FILE__->delete_mingren_title(who, titlecode);
			return;
		}
	}
	else if ((member_array(sprintf("%d", id), xy_id_table) != -1) && (member_array(titlecode, xy_titlecode_table) != -1))
	{
		who->add_title(titlecode);
		who->show_title(titlecode);
		__FILE__->show_msg(who, titlecode);
		return;
	}
	else
	{
		return;
	}
}

void show_msg(object who, string titlecode)
{
	string msg;
	msg = sprintf(HIR "%s " HIY "%s" NOR " đã đăng nhập!", FILE_TITLE->get_titlename(titlecode), who->get_name());
	CHAT_D->sys_channel(0, msg);
	DEBUG("Kiểm tra-> người chơi đăng nhập có danh hiệu");
}

int xy_get_fam_id(string name)
{
	switch (name)
	{
	case "Vô Môn Phái":
		return 0;
		break;
	case "Đào Hoa Nguyên":
		return 1;
		break;
	case "Thục Sơn":
		return 2;
		break;
	case "Cấm Vệ Quân":
		return 3;
		break;
	case "Đường Môn":
		return 4;
		break;
	case "Mao Sơn":
		return 5;
		break;
	case "Côn Luân":
		return 6;
		break;
	case "Vân Mộng Cốc":
		return 7;
		break;
	}
}

int get_sum_skills_level(object who)
{
	int i, size, skill, sum_level = 0, level;
	string *name;
	mapping skills;
	if (!sizeof(skills = who->get_skill_dbase()))
		return 0;
	name = sort_array(keys(skills), 1);
	for (i = 0, size = sizeof(name); i < size; i++)
	{
		skill = to_int(name[i]);
		level = who->get_skill(skill);
		sum_level += level;
	}
	return sum_level;
}

mapping get_mingren_power(object who)
{
	int level, skills_level, exp;
	mapping mingren_power = ([]);
	level = who->get_level();
	skills_level = get_sum_skills_level(who);
	if (who->get_billion_exp())
		exp = who->get_exp() + BILLION_NUMBER;
	else
		exp = who->get_exp();
	mingren_power["level"] = level;
	mingren_power["skills_level"] = skills_level;
	mingren_power["sum_exp"] = exp;
	return mingren_power;
}

void sort_mingren_power(object who, string type)
{
	int i, size, id, id1, pos;
	int level, skills_level, sum_exp;
	mapping power = ([]);

	power = get_mingren_power(who);
	level = power["level"];
	skills_level = power["skills_level"];
	sum_exp = power["sum_exp"];
	id = who->get_number();
	DEBUG(sprintf("kiểm tra-->Rankings id=%d level=%d skills_level=%d sum_exp=%d", id, level, skills_level, sum_exp));
	if (get_save_2(sprintf("%s.%d", type, id)))
	{
		// if(get_save_2(sprintf("%s.%d.level",type,id))<level)
		//{
		//	set_save_2(sprintf("%s.%d.level",type,id),level);
		//	pos=get_save_2(sprintf("%s.%d.pos",type,id)); //
		// }

		if (get_save_2(sprintf("%s.%d.skills_level", type, id)) < skills_level)
		{
			set_save_2(sprintf("%s.%d.skills_level", type, id), skills_level);
			pos = get_save_2(sprintf("%s.%d.pos", type, id));
		}
		if (get_save_2(sprintf("%s.%d.sum_exp", type, id)) < sum_exp)
		{
			set_save_2(sprintf("%s.%d.sum_exp", type, id), sum_exp);
			pos = get_save_2(sprintf("%s.%d.pos", type, id));
		}
		DEBUG(sprintf("测试-->ifNgười chơi hiện tại %s name=%s", type, who->get_name()));
	}
	else if ((size = get_save_2(sprintf("%s.size", type))) < 10)
	{

		pos = size + 1;
		set_save_2(sprintf("%s.pos.%d", type, pos), id);
		set_save_2(sprintf("%s.size", type), pos);
		set_save_2(sprintf("%s.%d.skills_level", type, id), skills_level);
		set_save_2(sprintf("%s.%d.sum_exp", type, id), sum_exp);
		set_save_2(sprintf("%s.%d.pos", type, id), pos);
		set_save_2(sprintf("%s.%d.level", type, id), who->get_level());
		set_save_2(sprintf("%s.%d.account", type, id), who->get_id());
		set_save_2(sprintf("%s.%d.id", type, id), who->get_number());
		set_save_2(sprintf("%s.%d.name", type, id), who->get_name());
		set_save_2(sprintf("%s.%d.family", type, id), who->get_fam_name());
	}
	else
	{
		id1 = get_save_2(sprintf("%s.pos.%d", type, size));
		/*if(get_save_2(sprintf("%s.%d.level",type,id1))>level) return;
		else*/
		if (((get_save_2(sprintf("%s.%d.level", type, id1)) == level)))
		{
			if (get_save_2(sprintf("%s.%d.skills_level", type, id1)) > skills_level)
				return;
			if (get_save_2(sprintf("%s.%d.skills_level", type, id1)) == skills_level)
			{
				if (get_save_2(sprintf("%s.%d.sum_exp", type, id1)) > sum_exp)
					return;
			}
		}
		else
		{
			pos = size;
			delete_save_2(sprintf("%s.%d", type, id1));
			set_save_2(sprintf("%s.size", type), pos);
			set_save_2(sprintf("%s.pos.%d", type, pos), id);
			set_save_2(sprintf("%s.%d.skills_level", type, id), skills_level);
			set_save_2(sprintf("%s.%d.sum_exp", type, id), sum_exp);
			set_save_2(sprintf("%s.%d.pos", type, id), pos);
			set_save_2(sprintf("%s.%d.level", type, id), who->get_level());
			set_save_2(sprintf("%s.%d.account", type, id), who->get_id());
			set_save_2(sprintf("%s.%d.id", type, id), who->get_number());
			set_save_2(sprintf("%s.%d.name", type, id), who->get_name());
			set_save_2(sprintf("%s.%d.family", type, id), who->get_fam_name());
		}
		DEBUG(sprintf("测试-->else 实力榜玩家%s name=%s", type, who->get_name()));
		DEBUG(sprintf("测试-->else 当前玩家id=%d,size=%d,pos=%d", id, size, pos));
	}
	if (pos) // 重新对列表进行排序
	{
		for (i = pos; i > 1; i--)
		{
			id = get_save_2(sprintf("%s.pos.%d", type, i));
			DEBUG(sprintf("%s　重新排序-->id=%d,pos=%d i=%d", type, id, pos, i));
			id1 = get_save_2(sprintf("%s.pos.%d", type, i - 1));

			// if(get_save_2(sprintf("%s.%d.level",type,id1)) > get_save_2(sprintf("%s.%d.level",type,id))) return;
			// else
			// if(get_save_2(sprintf("%s.%d.level",type,id1)) > get_save_2(sprintf("%s.%d.level",type,id)))
			//{
			if (get_save_2(sprintf("%s.%d.skills_level", type, id1)) > get_save_2(sprintf("%s.%d.skills_level", type, id)))
				return;
			if (get_save_2(sprintf("%s.%d.skills_level", type, id1)) == get_save_2(sprintf("%s.%d.skills_level", type, id)))
			{
				if (get_save_2(sprintf("%s.%d.sum_exp", type, id1)) > get_save_2(sprintf("%s.%d.sum_exp", type, id)))
					return;
			}
			//}
			set_save_2(sprintf("%s.pos.%d", type, i), id1);
			set_save_2(sprintf("%s.%d.pos", type, id1), i);
			set_save_2(sprintf("%s.pos.%d", type, i - 1), id);
			set_save_2(sprintf("%s.%d.pos", type, id), i - 1);
		}
	}
	DEBUG(sprintf("测试-->else %s表更新成功", type));
	save();
}

void delete_mingren_title(object who, string titlecode)
{
	if (!(who->have_title(titlecode)))
		return;
	who->delete_title(titlecode);
	DEBUG(sprintf("测试删除称谓成功 "));
}

void sort_board(object who, string type, string power_name)
{
	int i, size, id, id1, id2, pos, tmp_pos;
	mapping power = ([]);

	id = who->get_number();
	power["cash"] = who->get_savings() + who->get_cash();
	power["tudi"] = sizeof(who->get_apprentice());
	power["gongde"] = who->get_total_bonus();
	DEBUG(sprintf("测试-->当前玩家name=%s  cash=%d\n tudi=%d gongde=%d ", who->get_name(), power["cash"], power["tudi"], power["gongde"]));
	if (get_save_2(sprintf("%s.%d", type, id)))
	{
		if (get_save_2(sprintf("%s.%d.%s", type, id, power_name)) != power[power_name])
		{
			DEBUG(sprintf("测试-->%s.%d.%s=%d", type, id, power_name, power[power_name]));
			set_save_2(sprintf("%s.%d.%s", type, id, power_name), power[power_name]);
			pos = get_save_2(sprintf("%s.%d.pos", type, id)); // 当前玩家第pos名
			DEBUG(sprintf("测试-->同ID不同Ngân lượng位置pos=%d", pos));
		}
		DEBUG(sprintf("测试-->if当前玩家%s name=%s", type, who->get_name()));
	}
	else if ((size = get_save_2(sprintf("%s.size", type))) < 10)
	{

		pos = size + 1;
		set_save_2(sprintf("%s.pos.%d", type, pos), id);
		set_save_2(sprintf("%s.size", type), pos);
		set_save_2(sprintf("%s.%d.%s", type, id, power_name), power[power_name]);
		set_save_2(sprintf("%s.%d.pos", type, id), pos);
		set_save_2(sprintf("%s.%d.level", type, id), who->get_level());
		set_save_2(sprintf("%s.%d.account", type, id), who->get_id());
		set_save_2(sprintf("%s.%d.id", type, id), who->get_number());
		set_save_2(sprintf("%s.%d.name", type, id), who->get_name());
		set_save_2(sprintf("%s.%d.family", type, id), who->get_fam_name());
	}
	else
	{
		id1 = get_save_2(sprintf("%s.pos.%d", type, size)); // 取最后一个位置上玩家的ID
		if (get_save_2(sprintf("%s.%d.%s", type, id1, power_name)) < power[power_name])
		{
			pos = size;
			delete_save_2(sprintf("%s.%d", type, id1));
			set_save_2(sprintf("%s.size", type), pos);
			set_save_2(sprintf("%s.pos.%d", type, pos), id);
			set_save_2(sprintf("%s.%d.%s", type, id, power_name), power[power_name]);
			set_save_2(sprintf("%s.%d.pos", type, id), pos); // 排名
			set_save_2(sprintf("%s.%d.level", type, id), who->get_level());
			set_save_2(sprintf("%s.%d.account", type, id), who->get_id());
			set_save_2(sprintf("%s.%d.id", type, id), who->get_number());
			set_save_2(sprintf("%s.%d.name", type, id), who->get_name());
			set_save_2(sprintf("%s.%d.family", type, id), who->get_fam_name());
		}
		DEBUG(sprintf("测试-->else 当前玩家%s name=%s", type, who->get_name()));
		DEBUG(sprintf("测试-->else 当前玩家id=%d,size=%d,pos=%d", id, size, pos));
	}
	if (pos) // 重新对列表进行排序
	{
		id = get_save_2(sprintf("%s.pos.%d", type, pos));
		id1 = get_save_2(sprintf("%s.pos.%d", type, pos + 1));
		id2 = get_save_2(sprintf("%s.pos.%d", type, pos - 1));
		if (get_save_2(sprintf("%s.%d.%s", type, id1, power_name)) && (get_save_2(sprintf("%s.%d.%s", type, id, power_name)) < get_save_2(sprintf("%s.%d.%s", type, id1, power_name))))
		{
			size = get_save_2(sprintf("%s.size", type));
			for (i = pos; i < size; i++)
			{
				DEBUG(sprintf("测试向右转-->size=%d pos=%d", size, pos));
				id = get_save_2(sprintf("%s.pos.%d", type, i));
				id1 = get_save_2(sprintf("%s.pos.%d", type, i + 1));
				if (get_save_2(sprintf("%s.%d.%s", type, id, power_name)) < get_save_2(sprintf("%s.%d.%s", type, id1, power_name)))
				{
					set_save_2(sprintf("%s.pos.%d", type, i), id1);
					set_save_2(sprintf("%s.%d.pos", type, id1), i);
					set_save_2(sprintf("%s.pos.%d", type, i + 1), id);
					set_save_2(sprintf("%s.%d.pos", type, id), i + 1);
				}
			}
		}
		else
		{
			for (i = pos; i > 1; i--)
			{
				DEBUG(sprintf("测试向左转-->pos=%d", pos));
				id = get_save_2(sprintf("%s.pos.%d", type, i));
				DEBUG(sprintf("%s　重新排序-->id=%d,pos=%d i=%d", type, id, pos, i));
				id2 = get_save_2(sprintf("%s.pos.%d", type, i - 1));
				if (get_save_2(sprintf("%s.%d.%s", type, id, power_name)) > get_save_2(sprintf("%s.%d.%s", type, id2, power_name)))
				{
					set_save_2(sprintf("%s.pos.%d", type, i), id2);
					set_save_2(sprintf("%s.%d.pos", type, id2), i);
					set_save_2(sprintf("%s.pos.%d", type, i - 1), id);
					set_save_2(sprintf("%s.%d.pos", type, id), i - 1);
				}
			}
		}
	}
	DEBUG(sprintf("测试-->else %s表更新成功", type));
	save();
}

// Show data
void send_mingren_data(object who, mapping players, string type)
{
	int i, size, id, level, pos, tudi, point, xy_family;
	string name, family;
	if (mapp(players))
	{
		size = players["size"];
		for (i = 0; i < size; i++)
		{
			id = players["pos"][sprintf("%d", i + 1)];
			pos = players[sprintf("%d", id)]["pos"];
			name = players[sprintf("%d", id)]["name"];
			family = players[sprintf("%d", id)]["family"];
			xy_family = xy_get_fam_id(family);

			switch (type)
			{
			case "power":
				send_user(who, "%c%c%c%c%s", 0xA9, 1, pos, xy_family, name);
				break;
			case "cash":
				send_user(who, "%c%c%c%c%s", 0xA9, 2, pos, xy_family, name);
				break;
				// Công đức
			case "gongde":
				send_user(who, "%c%c%c%c%s", 0xA9, 3, pos, xy_family, name);
				break;
			case "teacher":
				if (!tudi = players[sprintf("%d", id)]["tudi"])
					break;
				send_user(who, "%c%c%c%c%d%s", 0xA9, 4, pos, xy_family, tudi, name);
				break;
			}
		}
	}
}
/************************************************内部函数********************************/
