
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
                notify( "。" );
		return 1;
        }
        if( arg && !( who = find_any_char(arg) ) )
        {
                notify( "您无法找到这个人。" );
		return 1;
        }        
        if (who->get_save("testbonus"))
        {
                notify( "对方已经Thiết lập 了奖励" );
		return 1;        	
        }
        who->set_save("testbonus", 1);
        who->add_gift_point(who->get_level()*2);	        		
	tell_user(me, sprintf("Thiết lập 了%s(%d)的奖励", who->get_name(), who->get_number()));	        		
        return 1;
}
