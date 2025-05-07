
#include <npc.h>
#include <effect.h>

void into_effect( object me )
{
// inh/char/cmd
        if( me->get_login_flag() < 3 )    
        {
                me->set_login_flag(3);
//              me->set_char_type(PLAYER_TYPE_2);
                me->add_pk(0);
                if( !get_effect(me, EFFECT_CHAR_INVISIBLE) ) set_invisible(me, 0);
                if( gone_time( me->get_login_time() ) < 25 ) USER_TASK_D->auto_give_task(me);
        }
}
