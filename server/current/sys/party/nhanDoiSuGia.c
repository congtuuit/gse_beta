#include <time.h>
#include <ansi.h>
#include <cmd.h>

#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

void SAVE_BINARY() { }

void create()
{
	call_out("check_time", 1);
}

void check_time()
{
	int iTime, rate, level, z, p, x, y;
	int i, * nScene, size;
	mixed* mixTime;
	object robber;

	remove_call_out("check_time");
	iTime = time();
	mixTime = localtime(iTime);
	i = 60 * (60 - mixTime[TIME_MIN]);

	if (
		mixTime[TIME_WDAY] == 2 ||
		mixTime[TIME_WDAY] == 4 ||
		mixTime[TIME_WDAY] == 6 ||
		mixTime[TIME_WDAY] == 0
		)
	{
		if (mixTime[TIME_HOUR] == 9 || mixTime[TIME_HOUR] == 20) {
			if (mixTime[TIME_MIN] <= 30) {
				CHAT_D->sys_channel(0, HIY "Thời gian nhân đôi tiềm năng nhiệm vụ sư gia bắt đầu từ: 9:00 đến 10:00 và 20:00 đến 21:00");

				call_out("check_time", 3600);
				return;
			}
			else {
				call_out("check_time", 3600);
				return;
			}
		}
		else {
			call_out("check_time", 3600);
		}
	}

}
