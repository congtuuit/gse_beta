
#include <ansi.h>

int main( object me, string arg )
{   
        int id;

        id = to_int(arg);

        if( me->get_save_2("Newbie.Login") )
                QUEST_TIPS->send_newbie_tips( me, sprintf("%d", id) );
        else if( id >= 200 )
                QUEST_TIPS->send_common_tips( me, sprintf("%d", id) );
        else    QUEST_TIPS->send_map_tips( me, sprintf("%d", id) );

        return 1;
}
