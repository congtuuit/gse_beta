
// 自动生成：/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;

// 函数：远程攻击的怪
// int is_caster() { return 1; }

// 函数：是否允许移动
// int is_moveable() { return 0; }    // 禁止使用 go 命令

// 函数：跟随对手(心跳之中调用)
// void follow_user() { }    // 禁止跟随敌人

// 函数：获取人物造型
int get_char_picid() { return 0304; }

// 函数：构造处理
void create()
{
        set_name("Ếch Tử Mẫu");

        set_char_type(FIGHTER_TYPE);    // init_level 要用到
        
        set_head_color(0x29c6);

        NPC_ENERGY_D->init_level( this_object(), 7+ random(2) );    // 
        set_max_seek(4);

        setup();

        set_char_type(FIGHTER_TYPE);    // 重设类型
}

// 函数：获取装备代码
int get_weapon_code() { return UNARMED; }

// 函数：特技攻击对手
int perform_action( object who ) { return 0; }    // XXXXX->perform_action_npc( this_object(), who ); }

// 函数：自动战斗(遇玩家时调用)
 void auto_fight( object who ) { }

// 函数：任务处理(有任务时调用)
void check_legend_task( object who ) 
{
	int p,i;
	object item; 

	if ( who->get_legend(TASK_49, 24) && !who->get_legend(TASK_49, 25) && who->get_save("xiuli_zimuwa")==0 )
	{
		i = who->set_save("xiuli_zimuwa",1);
		if ( i && who->get_save("xiuli_cscr") && who->get_save("xiuli_chy") )
		{
			who->set_legend(TASK_49, 25);
	                send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,48,"Khó khăn(Hoàn thành)" );
		}
		send_user(who,"%c%s",'!',sprintf("Ếch Tử Mẫu %d/1",i));
		USER_TASK_D->send_task_intro(who,2,TID_NEWBIE_01,48);	
	}
	//掉Hỏa Thạch
	if ( who->get_legend(TASK_49,6) && !who->get_legend(TASK_49,7) && random(100)<65 )
	{
		if ( objectp( item = present("Hỏa Thạch", who, 1, MAX_CARRY) ) && item->is_huoyanshi() == 1 ) 
		{
			if ( item->get_amount() < 5 )
				item->add_amount(1);
			p = 1;
		}
		else
		{
			item = new("item/98/9886");
			if ( item  )
			{
				p = item->move(who,-1);
				if ( !p )
				{
					destruct(item);
				}
				else
					item->add_to_user(p);
			}
		}
		if ( p )
		{		
			if ( (i=who->add_save_2("huoyanshi",1)) >= 5 )
			{
				who->set_legend(TASK_49,7);
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,116,"Giao dịch(已经Hoàn thành)" );
				send_user(who,"%c%s",';',"Hỏa Thạch已经收集好,请找新手村的门派向导Hoàn thành任务");
			}
			send_user(who,"%c%s",'!',sprintf(HIY"Hỏa Thạch %d/5",i));
			USER_TASK_D->send_task_intro(who,2,TID_NEWBIE_01,116);
		}			
	}
	//掉Hoa huệ
	if ( who->get_legend(TASK_48, 28) && !who->get_legend(TASK_48, 29) && random(100) < 50 )
	{
		if ( objectp( item = present("Hoa huệ", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 3 )
				item->add_amount(1);
			p = 1;
		}
		else
		{
			item = new("item/98/0202");
			if ( item  )
			{
				p = item->move(who,-1);
				if ( !p )
				{
					destruct(item);
				}
				else
					item->add_to_user(p);
			}
		}
		if ( p )
		{		
			if ( (i=who->add_save("wdzbaihh",1)) >= 3 )
			{
				who->set_legend(TASK_48,29);
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,112,"Trang trí nhà cửa(Hoàn thành)" );
			}
			send_user(who,"%c%s",'!',sprintf(HIY"Hoa huệ %d/3",i));
			USER_TASK_D->send_task_intro(who,2,TID_NEWBIE_01,112);
		}			
	}

}

// 函数：掉宝奖励
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
//      p = random(100);  size = ( p > 40 ) ? 3 : 10;  total = 2;  total2 = 3;

        rate = me->correct_drop_rate( me->get_level() - who->get_level() ) * who->get_online_rate() / 100;

        for( i = 0; i < size; i ++ )
        {
                p = random(10000);

                if( p < 4412 * rate / 100 ) ;    // NONE

/*              else if( p < 4412 * rate / 100 )    // Ngân lượng
                {
                        if( gold >= total ) continue;

                        if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                        {
                                item = new( "/item/std/0001" );
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->set_value( 0 + random(0) );
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                                gold ++;
                        }
                }       */
                else if( p < 4538 * rate / 100 )    // 武器(基本)
                {
                        if( equip >= total2 ) continue;

                        file = WEAPON_FILE->get_weapon_file_0(0);
                        if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                        {
                                item = new(file);
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                ITEM_EQUIP_D->init_equip_prop(item);
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                                equip ++;
                        }
                }         
                else if( p < 4844 * rate / 100 )    // 防具(基本)
                {
                        if( equip >= total2 ) continue;

                        file = ARMOR_FILE->get_armor_file_0(0);
                        if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                        {
                                item = new(file);
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                ITEM_EQUIP_D->init_equip_prop(item);
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                                equip ++;
                        }
                }         
/*              else if( p < 4844 * rate / 100 )    // 武器(门派)
                {
                        if( equip >= total2 ) continue;

                        switch( random(0) )
                        {

                      default : break;
                        }
                        if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                        {
                                item = new(file);
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                ITEM_EQUIP_D->init_equip_prop(item);
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                                equip ++;
                        }
                }       */
/*              else if( p < 4844 * rate / 100 )    // 防具(门派)
                {
                        if( equip >= total2 ) continue;

                        switch( random(0) )
                        {

                      default : break;
                        }
                        if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                        {
                                item = new(file);
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                ITEM_EQUIP_D->init_equip_prop(item);
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                                equip ++;
                        }
                }       */
                else if( p < 9900 * rate / 100 )    // 杂物１
                {
                        switch( random(3) )
                        {
                       case 0 : file = "/item/40/4004";  break;
                       case 1 : file = "/item/40/4008";  break;
                       case 2 : file = "/item/40/4007";  break;

                      default : break;
                        }
                        if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                        {
                                item = new(file);
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                        }
                }         
/*              else if( p < 9900 * rate / 100 )    // 杂物２
                {
                        switch( random(0) )
                        {

                      default : break;
                        }
                        if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                        {
                                item = new(file);
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                        }
                }       */
                else if( p < 10000 * rate / 100 )    // 杂物３
                {
                        switch( random(1) )
                        {
                       case 0 : file = "/item/41/4111";  break;

                      default : break;
                        }
                        if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                        {
                                item = new(file);
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                        }
                }         
/*              else if( p < 10000 * rate / 100 )    // 杂物４
                {
                        switch( random(0) )
                        {

                      default : break;
                        }
                        if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                        {
                                item = new(file);
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                        }
                }       */
/*              else if( p < 90000 * rate / 100 )    // 杂物５
                {
                        switch( random(0) )
                        {

                      default : break;
                        }
                        if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                        {
                                item = new(file);
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                        }
                }       */

        }       
}
