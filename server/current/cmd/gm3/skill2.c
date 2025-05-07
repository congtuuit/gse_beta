#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#include <equip.h>

int main( object me, string arg )
{
	object who;
    int i, size, a1, a2, a3, a4, rate;
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

			rate = me->get_double_rate();
			me->set_double_rate(10000);

			//effect
			//send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 3685, 1, OVER_BODY, PF_ONCE);

			CHAR_FIGHT_D->throwing_done(me, who, HIT_NONE, 100);
			/*if (who && !who->is_die())
				CHAR_FIGHT_D->set_enmity(me, who, 120);*/

			me->set_double_rate(rate);

		}
    }
	
    return 1;
}