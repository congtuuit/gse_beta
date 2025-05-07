
// 自动生成：/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <ansi.h>
#include <task.h>
#include <effect.h>
inherit BADMAN;

// 函数：远程攻击的怪
// int is_caster() { return 1; }

// 函数：是否允许移动
// int is_moveable() { return 0; }    // 禁止使用 go 命令

// 函数：跟随对手(心跳之中调用)
// void follow_user() { }    // 禁止跟随敌人

// 函数：获取人物造型
int get_char_picid() { return 3011; }

// 函数：构造处理
void create()
{
        set_name(HIY"Thiên Long");

        set_char_type(FIGHTER_TYPE);    // init_level 要用到
        
        //set_head_color(0x69a9);
        set_head_color(0x0000D7FF);

        //NPC_ENERGY_D->init_level( this_object(), 100 + random(3) );    // 
        set_max_hp(30000);
        set_ap(8000);
        set_dp(3000);
        set_pp(3000);
        set_max_seek(2);
        set_walk_speed(4);
        set("no_sk04211", 1);
        set("anti_sleep", 1);
        set("anti_no_move", 1);

	    call_out("do_fight", 2);
        setup();
        //set_effect(me, EFFECT_CHAR_BUSY, 2);
        set_char_type(FIGHTER_TYPE);
        
}

void do_fight()
{
    object me = this_object();
    set_effect(me, EFFECT_CHAR_BUSY, 0);
    me->add_to_scene(get_z(me), get_x(me), get_y(me));
}

// 函数：获取装备代码
int get_weapon_code() { return UNARMED; }

// 函数：特技攻击对手
int perform_action( object who ) { return 0; }    // XXXXX->perform_action_npc( this_object(), who ); }

// 函数：自动战斗(遇玩家时调用)
// void auto_fight( object who ) { }

// 函数：任务处理(有任务时调用)
void check_legend_task( object who )
{
	
}
void drop_items( object who ) { __FILE__ ->drop_items_callout( this_object(), who ); }

// 函数：掉宝奖励(在线更新)
void drop_items_callout( object me, object who )
{
        object item, leader;
        string file, owner, id;
        int p, rate, i, size, gold, equip, total, total2 ;
        int z, x, y;

        z = get_z(me);  x = get_x(me);  y = get_y(me);
        id = who->get_leader();
        if (!id) owner = who->get_id();
        else
        {
        	if ( leader = find_player(id ) )
        	{
        		owner = leader->get_id();
		}      
		else
			owner = who->get_id();  		
	}

        p = random(100);  size = ( p > 2 ) ? 1 : ( p > 0 ) ? 2 : 8;  total = 2;  total2 = 3;

        rate = me->correct_drop_rate( me->get_level() - who->get_level() ) * who->get_online_rate() / 100;


}
