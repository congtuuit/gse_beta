
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define YUANBAO "sys/sys/test_db"

int main( object me, string arg )
{
	object who;
    int i, size, a1, a2, a3, a4;
    int amount, value;
    string chars;
    if( is_player(me) ) 
    {
        notify( "Ngươi không đủ quyền hạn" );
	    return 1;
    }
    if(sscanf( arg, "%s %d", chars, value) != 3){
		if(!( who = find_any_char(chars) ))
	    {
	        notify( "Không tìm thấy người này" );
			return 1;
	    }
	    
	    if(value > 0){

			who->add_exp(value);
			tell_user(me, sprintf("%s (%d) đã nhận được %d ngân lượng", who->get_name(), who->get_number(), value));
			//tell_user(who, "Bạn đã nạp thành công %d ngân lượng", value);	
		}
    }
	
    return 1;
}