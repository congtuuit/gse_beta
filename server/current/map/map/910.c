
// 自动生成：/make/std/makemap

#include <map.h>
#include <time.h>

inherit SCENE;
object daozhang;
int dzTime,dzStart;
void clone_npc();

// 函数：获取标识
int get_id() { return 910; }

// 函数：获取标识(客户端)
int get_client_id() { return 910; }

// 函数：获取名字
string get_name() { return "Ngũ Hổ Tướng Chiến Trận"; }

// 函数：复位顺序
int get_reset_order() { return 108; }

// 函数：获取地型类别
int get_map_type() { return FIELD_MAP; }

// 函数：获取投掷类数
int get_caster_amount() { return 1; }

// 函数：构造处理
void create() 
{
        object map = this_object();
		mixed *mxTmp;

        set_map_object( map, get_id() );
        //MAP_D->load_npc_file( map, "/map/npc/804.npc" );

        //set_sizeof_xy( sizeof_xy_point( get_id() ) );

        //set_heart_timer( map, set_heart_timer_2( map, ( time() % RESET_TIME ) * 10 ) );
        //set_heart_loop(map, 60);   
        //map->heart_beat();
        //set_heart_beat(1);
	
	    mxTmp = localtime(time());
	   /* dzStart = mktime(mxTmp[TIME_YEAR],mxTmp[TIME_MON]+1,mxTmp[TIME_MDAY],20,30,0);
        call_out("reset", 1); */
}

// 函数：心跳处理
void heart_beat() { }

// 函数：心跳处理(循环)
void heart_beat_loop( int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 )    // 每１分处理
{
}

// 函数：复位处理
void reset() 
{

}

// 函数：复位处理
void reset_call_out()
{
        /*remove_call_out( "reset_call_out" );

        MAP_D->reset_item( get_id() );

        if( sizeof_fighter_file() > 0 ) 
        { 
                set_add_amount(-1);  clone_npc(); 
        }*/
}

// 函数：载入怪物
void clone_npc()
{
       /* remove_call_out( "clone_npc" );

        MAP_D->clone_npc( this_object() );

        if( get_add_amount() ) call_out( "clone_npc", 2 );*/
}
