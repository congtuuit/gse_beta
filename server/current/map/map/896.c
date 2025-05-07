#include <map.h>
inherit SCENE;

int get_id() { return 896; }

int get_client_id() { return 896; }

string get_name() { return "Phá Thiên Tháp"; }

int get_map_type() { return CAVE_MAP; }

void create()
{
    object me = this_object();

    set_client_id(896);
    set_name("Phá Thiên Tháp");

    if (!clonep(me)) return;

    set_heart_timer(me, set_heart_timer_2(me, getoid(me) % 10));
    set_heart_loop(me, 600);
    me->heart_beat();
    set_heart_beat(1);
}

void reset() 
{
        int time = add_reset_time(1);

        remove_call_out( "reset" );

        if( !( time % 10 ) ) MAP_D->reset_npc( get_id() );
        if( time % get_clean_time() ) return;
        MAP_D->reset_item_callout( get_id() );
}

void before_jumpout( object me )
{
        object soldier, *zombie;
        int i, size;

        if( objectp( soldier = me->get("soldier") ) )    // 停止召唤兽攻击
        {
                soldier->set_enemy(0);
        }
        if( arrayp( zombie = me->get("zombie") ) )
        {
                for( i = 0, size = sizeof(zombie); i < size; i ++ ) 
                        if( objectp( zombie[i] ) ) zombie[i]->set_enemy(0);
        }
        me->set_enemy(0);
}
