
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

// 函数：命令处理
int main( object me, string arg )
{
	object who;
        int i, size, a1, a2, a3, a4;
        if( is_player(me) ) 
        {
                notify( "Ngươi không đủ quyền hạn" );
		return 1;
        }
        if( arg && !( who = find_any_char(arg) ) )
        {
                notify( "Không tìm thấy người này" );
		return 1;
        }        
		who->set_level(150);	
	tell_user(me, sprintf("%s (%d) đã thăng lên cấp 150", who->get_name(), who->get_number()));
//	tell_user(who, sprintf("%s (%d) đã thăng lên cấp 150", who->get_name(), who->get_number()));
	tell_user(who, "Bạn đã thăng lên cấp 150");
        return 1;
}
