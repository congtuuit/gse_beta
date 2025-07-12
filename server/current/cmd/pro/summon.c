#include <ansi.h>

#define SUMMON_LOG      "gm/summon.txt"         // File nhật ký triệu hồi

// 函数：命令处理 → Hàm: Xử lý lệnh
int main1( object me, string arg )
{
	object who;
        int z, x, y, x0, y0, p;

        if( is_player(me) ) 
        {
                notify( "Bạn không có quyền sử dụng lệnh này." );
		return 1;
        }

	if( !arg ) 
        {
                send_user( me, "%c%c%d%s", '?', 16, 10, sprintf( "Mời người chơi tới vị trí của bạn。\n\nVui lòng nhập ID số của người cần mời：\n"
                        ESC "summon %%s\n" ) );
                return 1;
        }

	if( !( who = find_any_char(arg) ) )
        {
                notify( "Không thể tìm thấy người này。" );
		return 1;
        }
        else if( !clonep(who) )
        {
                notify( "Không thể triệu hồi nhân vật này。" );
		return 1;
        }
        else if( who == me )
        {
                notify( "Bạn không thể tự triệu hồi chính mình。" );
		return 1;
        }

        z = get_z(me);  x0 = get_x(me);  y0 = get_y(me);

        if( p = get_valid_xy(z, x0, y0, IS_CHAR_BLOCK) )
        {
                x = p / 1000;  y = p % 1000;
                who->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0), 40971, 0, 40971, 0 );
                tell_user( me, HIY "Bạn đã mời %s tới vị trí của bạn。", who->get_name() );
                write_user( who, HIY "%s đã mời bạn đến vị trí của họ。", me->get_name() );

                if( userp(who) ) log_file( "gm/gm3.dat", sprintf( "%s %s đã mời %s(%s) đến %d (%d,%d)。\n", 
                        short_time(), me->get_id(), who->get_name(), who->get_id(), z, x, y ) );

		return 1;
        }
        else 
        {
                notify( who->get_name() + " không thể đến vị trí của bạn。" );
		return 1;
        }

        return 1;
}

int main( object me, string arg )
{
	int i,size;
	string *player;
	
        if( is_player(me) ) 
        {
                notify( "Bạn không có quyền sử dụng lệnh này。" );
		return 1;
        }
        player = explode(arg,",");
        if ( (size=sizeof(player)) == 0 )
        {
        	main1(me,arg);	
        	return 1;
        }
        for(i=0;i<size;i++)
        {
        	main1(me,player[i]);
        }
        return 1;
}
