
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
			who->set_save_2("mastertask.time", 9);
			who->add_task("robber#", value);
			tell_user(who, "Bạn đã nạp thành công %d nhiệm vụ sư gia", value);	
			tell_user(who, "Bạn đã nạp thành công %d nhiệm vụ sư môn", value);	
			tell_user(me, "%s đã nạp thành công %d nhiệm vụ sư gia",who->get_name(), value);	
			tell_user(me, "%s đã nạp thành công %d nhiệm vụ sư môn",who->get_name(), value);	
		}
    }
	
    return 1;
}