#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>
#include <time.h>

#define PVP "sys/party/pvp"

int main(object me, string arg)
{
	int tid, teamSize;
	object* team;

	if (!arg) return 1;
	if (arg == 0) return 1;

	switch (arg)
	{
	case "run":
		
		tid = me->get_team_id();
		if (!tid) {
			notify("Vui lòng lập tổ đội");
			return 0;
		}

		team = me->get_team();
		teamSize = sizeof(team);

		if (teamSize > 1) {
			notify("Chỉ có thể tham gia đơn lẻ");
			return 0;
		}

		PVP->registerPVP(me);
		PVP->find_match(me);
		//tell_user(me, "Tim tran");
		break;

	case "register":
		PVP->registerPVP(me);
		//tell_user(me, "Dang ky");
		break;
	case "check":
		PVP->update_rank(me, 0);
		PVP->update_record(me);
		PVP->waiting_mems(me);

		tell_user(me, ECHO"Rank %s (%d điểm)", me->get_save_2("ranked.name"), me->get_save_2("ranked.point"));
		break;
	}

	return 1;

}