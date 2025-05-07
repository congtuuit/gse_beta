
// 函数：命令处理
int main( object me, string arg )
{
        object who = me;
        int time;

        if( is_player(me) ) 
        {
                notify( "。" );
		return 1;
        }

        if( arg && !( who = find_any_char(arg) ) ) 
        {
                notify( "您无法找到这个人。" );
		return 1;
        }

        //send_user(who, "%c%w", 0x0d, 001);

        tell_user( me, "Tọa độ: %d (%d, %d) %d - user (%s) %s >----< name", 
                get_z(who), get_x(who), get_y(who), get_d(who) , who->get_id(), who->get_name());
	time = time() + 8 * 3600;
	tell_user( me, "time=%d /3600=%d mode 24=%d second=%d", time, time/3600, (time/3600) % 24, time % 3600);
        return 1;
}
