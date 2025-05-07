/************************************************************************************
PVP
*************************************************************************************/

#include <time.h>
#include <ansi.h>
#include <cmd.h>
#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

inherit DBASE_F;
inherit SAVE_F;

#define FILE_MAP    "map/copy/893"
#define PVP_NPC "npc/00/8085"
#define MAP_ID 893


void SAVE_BINARY() { }
string get_save_file() { return "data/PVPdata"SAVE_EXTENSION; }


string* array_rank_name = ({ "Đồng", "Bạc", "Vàng", "Bạch Kim", "Lục Bảo", "Kim Cương", "Cao Thủ", "Tuyệt Đại Cao Thủ" });
int pointToUp = 5;

void check_time();
void initPVP(object p1, object p2);
void update_record(object me);
int check_valid_user(object me);
int registerPVP(object me);
void find_match();
int indexByRankedName(string rankName);
int index(object me, int point);
void update_rank(object me, int point);
void remove_user_from_waiting(object p1);

void create()
{
	restore();
	call_out("check_time", 1);
}


int new_copy_scene(object who, object me)
{
	int z, d, tid, i, size, size2;
	object map, npc, * team, * team2;
	d = MAP_ID;
	tid = who->get_team_id();
	if (!tid)return 0;
	team = who->get_team();
	team2 = me->get_team();
	size = sizeof(team);
	size2 = sizeof(team2);
	z = COPY_CTROL->new_scene(d, FILE_MAP, "Đấu Trường PVP");
	if (!z) return 0;
	if (!objectp(map = get_map_object(z)) || !map->is_virtual_scene())
		return 0;

	TEAM_D->add_copy_scene(tid, COPY_GUMU, map);

	map->set("copy_id", 111);
	map->set("gumu_map", 111);

	for (i = 0; i < size; i++)
	{
		team[i]->set("team_id", tid);
		team2[i]->set("team_id", tid);
		map->set_owner(team[i]);
	}

	return z;
}


void initBuff(object who) {
	int i, size, a1, a2, a3, a4, arg_tmp, z;
	int amount, value;
	int level;
	int time, pos, time2;
	string chars;

	int* all = ({
			EFFECT_CHAR_POWERUP3,
			EFFECT_CHAR_KING_2,
			EFFECT_1811,
			EFFECT_2123_ARMORFALL,
			EFFECT_03484,
			EFFECT_CHAR_ARMORFALL,
			EFFECT_CHAR_HALFGOD2,
			EFFECT_02614,
			EFFECT_02614,
			EFFECT_USER_MP,
			EFFECT_USER_EXCHANGE_HP,
			EFFECT_CHAR_KING,
			EFFECT_USER_HP,
			EFFECT_USER_PP,
			EFFECT_USER_EXCHANGE_CP,
			EFFECT_USER_CP,
			EFFECT_USER_AP,
			EFFECT_CHAR_ADD_DP,
			EFFECT_EXCITE,
			EFFECT_REBOUND,
			EFFECT_USER_DP,
			EFFECT_USER_SP,
			EFFECT_DODGE,
			EFFECT_03484,
			EFFECT_CHAR_MOVE,
			EFFECT_CHAR_HALFGOD2,
			EFFECT_CHAR_POWERUP,
			EFFECT_CHAR_POWERUP2,
			EFFECT_CHAR_BLOOD,
			EFFECT_USER_BURN,
			EFFECT_CHAR_LAZY,
			EFFECT_CHAR_NO_MOVE,
			EFFECT_CHAR_CHAOS,
			EFFECT_CHAR_BLIND,
			EFFECT_02614,
			EFFECT_02616,
			EFFECT_CHAR_POWERFALL,
			EFFECT_CHAR_FALL,
			EFFECT_XUESHI_HP,
			EFFECT_MP_FALL, });


	send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 32531, 1, OVER_BODY, PF_ONCE);
	size = sizeof(all);

	for (z = 0; z < 15; z++) {
		time = 0; pos = -1;
		time2 = 0;
		for (i = 0; i < size; i++) {

			if (who->get_effect(all[i]) ||
				who->get_effect_2(all[i]) ||
				who->get_effect_3(all[i])
				)

			{
				who->set_effect(who, all[i], 0);
				who->set_effect_2(who, all[i], 0);
				who->set_effect_3(who, all[i], 0);
			}

			if (time < get_effect(who, all[i]))
			{
				time = get_effect(who, all[i]);
				time2 = get_effect_3(who, all[i]);

				pos = i;

				who->delete_perform(all[i]);
			}
		}


		for (i = 0; i < size; i++) {
			if (who->get_perform(PF_FLAG_03172))
			{
				if (time() - who->get_perform(PF_FLAG_03172) > time)
				{
					who->delete_perform(PF_FLAG_03172);
					pos = -1;
					CHAR_CHAR_D->init_loop_perform(who);
					send_user(who, "%c%w%w%c", 0x81, 3172, 0, EFFECT_GOOD);
					send_user(get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 3172, 0, EFFECT_GOOD);
				}

				if (time() - who->get_perform(PF_FLAG_03172) > time2)
				{
					who->delete_perform(PF_FLAG_03172);
					pos = -1;
					CHAR_CHAR_D->init_loop_perform(who);
					send_user(who, "%c%w%w%c", 0x81, 3172, 0, EFFECT_GOOD);
					send_user(get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 3172, 0, EFFECT_GOOD);
				}
			}



			if (pos != -1)
			{
				if (all[pos] < 96) set_effect(who, all[pos], 1);
				else set_effect_2(who, all[pos], 1, 1);
			}
		}
	}

	who->set_hp(who->get_max_hp());
	who->set_mp(who->get_max_mp());
	who->set_yuan(who->get_max_yuan());

	send_user(who, "%c%w%c%w", 0x50, 03253, 0xff, 0);
	send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 32531, 1, OVER_BODY, PF_ONCE);

}

void startNotify(object p1, object p2) {
	tell_user(p1, HIY"%s  vs  %s", p1->get_name(), p2->get_name());
	tell_user(p2, HIY"%s  vs  %s", p1->get_name(), p2->get_name());

	send_user(p1, "%c%s", ';', "Trận đấu giữ "HIY"" + p1->get_name() + "  vs  " + p2->get_name()  + HIR"  Bắt đầu!");
	send_user(p2, "%c%s", ';', "Trận đấu giữ "HIY"" + p1->get_name() + "  vs  " + p2->get_name()  + HIR"  Bắt đầu!");

}

void initPVP(object p1, object p2) {

	int z, tid, p, x,y , x1,y1, pos;
	object map, npc, * team;

	z = new_copy_scene(p1, p2);
	if (!z) return 0;
	if (!objectp(map = get_map_object(z)) || !map->is_virtual_scene())
		return 0;

	tid = p1->get("team_id");

	map = TEAM_D->get_copy_scene(tid, COPY_GUMU);

	if (map)
	{
		map->set_name("Đấu Trường PVP");
		z = map->get_id();
		x = 26; y = 31;

		if (!p = get_valid_xy(z, x, y, IS_CHAR_BLOCK)) return;
		x = (p % 1000000) / 1000;  y = p % 1000;

		p1->set("me_die", 1);
		send_user(p1, "%c%c%w%s", 0x5a, 0, 1, "Đang di chuyển……");
		p1->set_2("travel.z", z);
		p1->set_2("travel.p", p);
		p1->set("map", map);
		set_effect(p1, EFFECT_TRAVEL, 1);


		x1 = 52; y1 = 28;
		if (!pos = get_valid_xy(z, x1, y1, IS_CHAR_BLOCK)) return;
		x1 = (pos % 1000000) / 1000;  y1 = pos % 1000;

		p2->set("me_die", 1);
		send_user(p2, "%c%c%w%s", 0x5a, 0, 1, "Đang di chuyển……");
		p2->set_2("travel.z", z);
		p2->set_2("travel.p", pos);
		p2->set("map", map);
		set_effect(p2, EFFECT_TRAVEL, 1);

		
		call_out("initBuff", 2, p1);
		call_out("initBuff", 2, p2);

		call_out("startNotify", 2, p1, p2);
		
	}


}

void check_time()
{
	int iTime, rate, level;
	mixed* mixTime;

	remove_call_out("check_time");

	iTime = time();
	mixTime = localtime(iTime);

	call_out("find_match", 5);

}

void update_record(object player)
{
	int size, index, pos, oldid, id1, rankedPoint, i, ranked;
	int id = player->get_number();
	string name = player->get_name();

	rankedPoint = player->get_save_2("ranked.point");
	ranked = player->get_save_2("ranked.name");

	if (get_save_2(sprintf("player.%d", id)))
	{
		if (get_save_2(sprintf("player.%d.name", id)) == name)
		{
			set_save_2(sprintf("player.%d.point", id), rankedPoint);
			set_save_2(sprintf("player.%d.ranked", id), ranked);
			pos = get_save_2(sprintf("player.%d.pos", id));
		}
	}
	else if ((size = get_save_2(sprintf("record.size"))) < 50)
	{
		pos = size + 1;
		set_save_2("record.size", pos);
		set_save_2(sprintf("record.%d", pos), id);
		set_save_2(sprintf("player.%d.name", id), name);
		set_save_2(sprintf("player.%d.pos", id), pos);
		set_save_2(sprintf("player.%d.point", id), rankedPoint);
		set_save_2(sprintf("player.%d.ranked", id), ranked);

	}
	else
	{
		oldid = get_save_2(sprintf("record.%d", size));
		if (get_save_2(sprintf("player.%d.point", oldid)) < rankedPoint)
		{
			pos = size;
			delete_save_2(sprintf("player.%d", oldid));
			set_save_2(sprintf("record.%d", pos), id);
			set_save_2(sprintf("player.%d.name", id), name);
			set_save_2(sprintf("player.%d.pos", id), pos);
			set_save_2(sprintf("player.%d.point", id), rankedPoint);
			set_save_2(sprintf("player.%d.ranked", id), ranked);
			set_save_2("record.size", pos);
		}
	}

	if (pos)
	{
		for (index = pos; index > 1; index--)
		{
			id = get_save_2(sprintf("record.%d", index));
			id1 = get_save_2(sprintf("record.%d", index - 1));
			if (get_save_2(sprintf("player.%d.point", id1)) >= get_save_2(sprintf("player.%d.point", id)))
			{
				break;
			}
			set_save_2(sprintf("record.%d", index), id1);
			set_save_2(sprintf("player.%d.pos", id1), index);
			set_save_2(sprintf("record.%d", index - 1), id);
			set_save_2(sprintf("player.%d.pos", id), index - 1);
		}
		save();
	}

	//tell_user(player, "... %d", get_save_2("player.1426.pos"));
}

void remove_user_from_waiting(object me) {
	int id = me->get_number(), size, i;
	int* nMemId, *newMemId;
	int* nRankIndex, *newRandIndex;

	newMemId = ({});
	newRandIndex = ({});

	nMemId = get("memIds");
	nRankIndex = get("rankIndexs");

	if (!arrayp(nMemId)) {
		nMemId = ({});
	}

	if (!arrayp(nRankIndex)) {
		nRankIndex = ({});
	}

	for (i = 0, size = sizeof(nMemId); i < size; i++) {
		if (nMemId[i] == id) {
			continue;
		}

		newMemId += ({ nMemId[i] });
		newRandIndex += ({ nRankIndex[i] });
	}

	set("memIds", newMemId);
	set("rankIndexs", newRandIndex);

}

int check_valid_user(object me) {
	int id;
	int* nMemId;

	id = me->get_number();
	nMemId = PVP_NPC->get("memIds");

	if (!sizeof(nMemId))
		return 0;

	if (member_array(id, nMemId) == -1)
		return 0;
	return 1;
}


int registerPVP(object me) {
	int* nMemId;
	int* nRankIndex;
	int id, index;

	if (check_valid_user(me)) {
		return 0;
	}

	nMemId = get("memIds");
	nRankIndex = get("rankIndexs");
	if (!arrayp(nMemId))
		nMemId = ({});
	if (!arrayp(nRankIndex))
		nRankIndex = ({});

	id = me->get_number();
	index = indexByRankedName(me->get_save_2("ranked.name"));

	

	if (member_array(id, nMemId) == 0) {
		tell_user(me, ECHO"Bạn đang trong hàng chờ...");
		return 0;
	}

	nMemId += ({ id });
	nRankIndex += ({ index });

	tell_user(me, ECHO"Đang có %d người trong hàng chờ.", sizeof(nMemId));
	set("memIds", nMemId);
	set("rankIndexs", nRankIndex);


	return 1;
}

void waiting_mems(object me) {
	int* nMemId, i, size;
	nMemId = get("memIds");
	if (!arrayp(nMemId))
		nMemId = ({});

	for (i = 0, size = sizeof(nMemId); i < size; i++)
	{
		if (nMemId[i]) {
			tell_user(me, "%d waiting", nMemId[i]);
		}
	}
}

int isSameRankAndLevel(object p1, object p2) {
	int range;
	if (p1->get_save_2("ranked.point") && p2->get_save_2("ranked.point")) {
		range = abs(p1->get_save_2("ranked.point") - p2->get_save_2("ranked.point"));
		if (range <= 11) {
			return 1;
		}
	}
	else {
		range = abs(p1->get_save_2("ranked.point") - p2->get_save_2("ranked.point"));
		if (range <= 11) {
			return 1;
		}
	}

	return 0;
}

//dang ky vao file, tim tran truy xet tren file
void find_match() {
	int* nMemId;
	int* nRankIndex;
	object p1, p2, admin;
	int randomP1, randomP2;

	remove_call_out("check_time");

	nMemId = get("memIds");
	nRankIndex = get("rankIndexs");

	if (!arrayp(nMemId)) {
		nMemId = ({});
		call_out("find_match", 10);
		return;
	}

	if (!arrayp(nRankIndex)) {
		nRankIndex = ({});
		call_out("find_match", 10);
		return;
	}

	if (sizeof(nMemId) < 1) {
		call_out("find_match", 10);
		return;
	}

	randomP1 = random(sizeof(nMemId));
	randomP2 = random(sizeof(nMemId));

	if (!nMemId[randomP1]) {
		call_out("find_match", 10);
		return;
	}

	if (!(p1 = find_any_char(sprintf("%d", nMemId[randomP1]))) )
	{
		nMemId -= ({ nMemId[randomP1] });
		nRankIndex -= ({ nRankIndex[randomP1] });
		call_out("find_match", 10);
		return;
	}

	if (!(p2 = find_any_char(sprintf("%d", nMemId[randomP2]))))
	{
		nMemId -= ({ nMemId[randomP2] });
		nRankIndex -= ({ nRankIndex[randomP2] });
		call_out("find_match", 10);
		return;
	}

	if (p1 == p2) {
		call_out("find_match", 10);
		return;
	}

	if (!isSameRankAndLevel(p1, p2)) {
		call_out("find_match", 10);
		return;
	}

	initPVP(p1, p2);

	/*send_user(p1, "%c%s", ':', " Tìm thấy trận, bắt đầu thi đấu?\n"
		ESC "Đồng ý.\n" +
		ESC "Hủy bỏ.\nCLOSE\n");

	send_user(p2, "%c%s", ':', " Tìm thấy trận, bắt đầu thi đấu?\n"
		ESC "Đồng ý.\n" +
		ESC "Hủy bỏ.\nCLOSE\n");*/

	//nMemId -= ({ nMemId[randomP1] });
	//nRankIndex -= ({ nRankIndex[randomP1] });

	remove_user_from_waiting(p1);
	remove_user_from_waiting(p2);

	//set("memIds", nMemId);
	//set("rankIndexs", nRankIndex);

	call_out("find_match", 10);

}

int indexByRankedName(string rankName) {
	for (int i = 0; i < sizeof(array_rank_name); i++) {
		if (rankName == array_rank_name[i]) {
			return i;
		}
	}
}

int index(object me, int point) {
	return point / pointToUp;
}

void update_rank(object me, int point) {
	int totalPoint, index_rank, month;
	mixed* mxTime;
	mxTime = localtime(time());
	month = mxTime[TIME_MON];

	if (me->get_save_2("ranked.point") <= 0) {
		if (point < 0) {
			me->set_save_2("ranked.point", 0);
		}
		else {
			me->set_save_2("ranked.point", point);
		}

		me->set_save_2("ranked.name", array_rank_name[0]);
		me->set_save_2("ranked.month", month);

		if (me->get_save_2("ranked.point") > 0) {
			me->add_save_2("ranked.point", point);
		}

	}
	else {
		if (me->get_save_2("ranked.point") > 0) {
			me->add_save_2("ranked.point", point);
		}
	}

	totalPoint = 0;
	totalPoint = me->get_save_2("ranked.point");
	index_rank = index(me, totalPoint);
	me->set_save_2("ranked.name", array_rank_name[index_rank]);
	me->set_save_2("ranked.month", month);
}


void finished_match_p1win(object p1, object p2) {
	update_rank(p1, 1);
	update_rank(p2, -1);

	update_record(p1);
	update_record(p2);
}



void paihangbang(object player)
{
	int index, pos, name_size, id, max_blank, i;
	string tmp = "", cmd = "", playername, blank = "";

	for (index = 1; index <= 10; index++)
	{
		id = get_save_2(sprintf("record.%d", index));
		if (!id)
		{
			tmp = sprintf(" ""%2d.%s%s%s", index, " ", "", "Chưa cập nhật");
			tmp += "\n";
		}
		else
		{
			playername = get_save_2(sprintf("player.%d.name", id));
			name_size = strlen(playername);
			if (name_size <= 12)
			{
				playername += repeat_string(" ", 10 - name_size);
			}
			switch (index)
			{
			case 1:
				tmp = sprintf(" ""R""%2d. %2s%s %s (%3d điểm)"NOR, 1, playername, ": ", get_save_2(sprintf("player.%d.ranked", id)), get_save_2(sprintf("player.%d.point", id)));
				max_blank = get_save_2(sprintf("player.%d.point", id));
				break;
			case 2:
				tmp = sprintf(" ""M""%2d. %2s%s %s (%3d điểm)"NOR, 2, playername, ": ", get_save_2(sprintf("player.%d.ranked", id)), get_save_2(sprintf("player.%d.point", id)));
				break;
			case 3:
				tmp = sprintf(" ""B""%2d.%2s%s %s (%3d điểm)"NOR, 3, playername, ": ", get_save_2(sprintf("player.%d.ranked", id)), get_save_2(sprintf("player.%d.point", id)));
				break;
			default:
				tmp = sprintf(" ""%2d. %2s%s %s (%3d điểm)", index, playername, ": ", get_save_2(sprintf("player.%d.ranked", id)), get_save_2(sprintf("player.%d.point", id)));
				break;
			}
			
			tmp += "\n";
		}
		cmd += tmp;

	}

	send_user(player, "%c%c%w%s", ':', 3, 3000, sprintf("Bảng xếp hạng Đấu Trường PVP \n%s \n\n", cmd + ESC "Xác nhận\n"));
}

void view_board(object who) {
	paihangbang(who);
}