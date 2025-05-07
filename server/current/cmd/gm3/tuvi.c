
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#include <time.h>

void check_time(object who) {
	"cmd/base/quit"->main(who, "");
}

int main( object me, string arg )
{
	object who;
    int i, size, a1, a2, a3, a4;
    int amount, value;
    string id, type;

	int iTime;
	mixed* mixTime;
	int tuvi, timestart, time, hour, levelUp, timeGame, previousTime;
	string showTimeStart, showTime;


    if( is_player(me) ) 
    {
        notify( "Ngươi không đủ quyền hạn" );
	    return 1;
    }
    if(sscanf( arg, "%s %s %d", id, type, value) != 4){
		if(!( who = find_any_char(id) ))
	    {
	        notify( "Không tìm thấy người này" );
			return 1;
	    }
	    
		switch (type)
		{
			case "get":
				tuvi = who->get_save_2("online_rank.level");
				timestart = who->get_save_2("online_rank.start");
				time = who->get_save_2("online_rank.time");

				mixTime = localtime(timestart);

				hour = who->get_game_time() / (900 * (who->get_save_2("online_rank.level") + 1) * 3);
				levelUp = USER_RANK_D->check_online_level(hour);

				showTimeStart = sprintf("%d_%d_%d %d:%d:%d",mixTime[TIME_YEAR], mixTime[TIME_MON] + 1, mixTime[TIME_MDAY], mixTime[TIME_HOUR], mixTime[TIME_MIN], mixTime[TIME_SEC]);
				tell_user(me, sprintf(HIG"Thông tin tu vị: %s (%d)\n"HIG"Level: %d\n"HIG"Time start: %s\n"HIG"Time online: %d", who->get_name(), who->get_number(), tuvi, showTimeStart, time));
				tell_user(me, sprintf(HIC"Time to up: %d\n"HIC"Next level: %d", hour, levelUp));
				
				break;
			case "set":
				timeGame = 8;
				previousTime = 8;

				for (i = 1; i < value; i++) {
					previousTime += 2;
					timeGame += previousTime;
				}

				USER_RANK_D->online_rank(who, 0);

				who->set_save_2("online_rank.start", time());
				who->set_save_2("online_rank.time", timeGame*3600);
				who->set_game_time(who->get_save_2("online_rank.time"));
				who->set_save_2("online_rank.level", value);

				tell_user(who,HIR"Hệ thống đã đặt lại cấp độ tu vị, thoát sau vài giây!");
				notify("Thành công!");

				call_out("check_time", 10, who, "");
				break;

			case "cal":
				USER_RANK_D->online_rank(who, 1);
			break;
		}

    }
    
    return 1;
}