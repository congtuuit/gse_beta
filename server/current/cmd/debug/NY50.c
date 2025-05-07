
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
		"sys/sys/test_db"->add_yuanbao(who,500);	
	tell_user(me, sprintf("%s (%d) đã nhận được 50 Kim Nguyên Bảo", who->get_name(), who->get_number()));
//	tell_user(who, sprintf("%s (%d) đã nạp thành công 50 Kim Nguyên Bảo", who->get_name(), who->get_number()));
	tell_user(who, "Bạn đã nạp thành công 50 Kim Nguyên Bảo");	
        return 1;
}
