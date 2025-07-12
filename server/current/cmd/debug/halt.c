#include <ansi.h>

// 函数：命令处理 → Hàm: Xử lý lệnh
int main( object me, string arg )
{
        object *char, who = me;
        int i, size;

        if( is_player(me) ) 
        {
                notify( "Bạn không có quyền sử dụng lệnh này。" );
		return 1;
        }

        if( arg && !( who = find_any_char(arg) ) ) 
        {
                notify( "Không thể tìm thấy người này。" );
		return 1;
        }

        who->stop_fight();

        char = get_range_object_2(who, 5, CHAR_TYPE) + get_range_object_2(who, 5, USER_TYPE) - ({ who });
        for( i = 0, size = sizeof(char); i < size; i ++ )
                if( char[i] && char[i]->get_enemy() == who ) char[i]->stop_fight();

        if( who == me )
        {
                tell_user( me, HIY "Bạn đã cưỡng chế kết thúc tất cả trận chiến liên quan đến mình。" );
        }
        else
        {
                tell_user( me, HIY "Bạn đã cưỡng chế kết thúc tất cả trận chiến liên quan đến %s。", who->get_name() );
                write_user( who, HIY "%s đã cưỡng chế kết thúc tất cả trận chiến liên quan đến bạn。", me->get_name() );
        }

        return 1;
}
