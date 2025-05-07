
#include <ansi.h>

string status_color( int num, int max );

// 函数：命令处理
int main( object me, string arg )
{
        object who;
        string arg2;
        int time, i;

        if( is_player(me) )
        {
                notify( "。" );
		return 1;
        }
	if (sscanf(arg, "%s %d", arg2, time)!=2) return 1;
	if (time<0) return 1;
        if( !( who = find_player(arg2) ) )
        {
                notify( "您无法找到这个玩家。" );
		return 1;
        }
	i = gone_time( who->get_login_time() );
	if ( who->get_double_time()< i + who->get_game_time())
	{
		who->set_double_time(i+who->get_game_time()+time*3600);
	}
	else
		who->set_double_time(who->get_double_time()+time*3600);
	send_user( who, "%c%c%c%w%c", 0x51, 1, 1,0001, 0 );
	send_user( who, "%c%c%c%w%w%c", 0x51, 1, 2, 0001, 1, 0 );
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"Viện Trợ trò chơi" );
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "Thời Gian Nhân Đôi" );
	"/sys/task/task"->send_task_intro(who, 1, 1, 1);
	if (me==who) tell_user(me, "Bạn đã thêm vào bản thân mình %d Thời gian gấp đôi của các giờ。", time);
	else
	{
		tell_user(me, "Cung cấp cho bạn %s Tăng %d Thời gian gấp đôi của các giờ。", who->get_name(), time);
		tell_user(who, "%s Thêm vào, bạn %d Thời gian gấp đôi của các giờ。", me->get_name(), time);
	}
        return 1;
}

