#include <map.h>
inherit SCENE;

int get_id() { return 893; }

int get_client_id() { return 893; }

string get_name() { return "Minh Chủ Đài"; }

int get_map_type() { return CAVE_MAP; }

void create() 
{
        object map = this_object();

        set_map_object( map, get_id() );
        //MAP_D->load_npc_file( map, "/map/npc/885.npc" );

        set_heart_timer( map, set_heart_timer_2( map, ( RESET_TIME - time() % RESET_TIME ) * 10 ) );
        set_heart_loop(map, 60);
        map->heart_beat();
        set_heart_beat(1);

        call_out("reset", 1);
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
