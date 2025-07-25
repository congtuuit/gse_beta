
// 自动生成：/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <ansi.h>
#include <task.h>
inherit BADMAN;

// 函数：远程攻击的怪
   int is_caster() { return 1; }

// 函数：是否允许移动
// int is_moveable() { return 0; }    // 禁止使用 go 命令

// 函数：跟随对手(心跳之中调用)
// void follow_user() { }    // 禁止跟随敌人

// 函数：获取人物造型
int get_char_picid() { return 0901; }

// 函数：构造处理
void create()
{
        set_name("Võng Lượng");

        set_char_type(FIGHTER_TYPE);    // init_level 要用到
        
        set_head_color(0x1001);

        NPC_ENERGY_D->init_level( this_object(), 51+ random(3) );    // 
        set_max_seek(6);

        setup();

        set_char_type(FIGHTER_TYPE);    // 重设类型
}

// 函数：获取装备代码
int get_weapon_code() { return UNARMED; }

// 函数：特技攻击对手
int perform_action( object who ) { return PF_FILE_04232->perform_action_npc( this_object(), who ); }

// 函数：自动战斗(遇玩家时调用)
// void auto_fight( object who ) { }

// 函数：任务处理(有任务时调用)
void check_legend_task( object who )
{
	int p,i;
	object item;
	if( who->get_legend(TASK_11, 16) && !who->get_legend(TASK_11, 17) && random(100) < 30)
	{
		if ( objectp( item = present("石炭", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 10 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0046");
			if ( !item  )
				return ;
			p = item->move(who,-1);
			if ( !p )
			{
				destruct(item);
				return;
			}
			item->add_to_user(p);
		}
		if ( (i=who->add_save_2("wtjshitan",1)) >= 10 )
		{
			who->set_save_2("wtjshitan",10);
			who->set_legend(TASK_11, 17);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,1,"无奈的求助（2）(Hoàn thành)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_ZHAOGUO,1);
		send_user(who,"%c%s",'!',sprintf(HIY"石炭 %d/10",i));		
	}	
	if( who->get_legend(TASK_11, 27) && !who->get_legend(TASK_11, 28) && random(100) < 27)
	{
		if ( objectp( item = present("发光的石头", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 5 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0048");
			if ( !item  )
				return ;
			p = item->move(who,-1);
			if ( !p )
			{
				destruct(item);
				return;
			}
			item->add_to_user(p);
		}
		if ( (i=who->add_save_2("yanjiushitou",1)) >= 5 )
		{
			who->set_save_2("yanjiushitou",5);
			who->set_legend(TASK_11, 28);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,19,"Viên đá(Hoàn thành)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_YANGUO,19);
		send_user(who,"%c%s",'!',sprintf(HIY"发光的石头 %d/5",i));		
	}	
	if( who->get_legend(TASK_13, 25) && !who->get_legend(TASK_13, 26) && random(100) < 27)
	{
		if ( objectp( item = present("棋子", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 20 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0056");
			if ( !item  )
				return ;
			p = item->move(who,-1);
			if ( !p )
			{
				destruct(item);
				return;
			}
			item->add_to_user(p);
		}
		if ( (i=who->add_save_2("swqizhi",1)) >= 20 )
		{
			who->set_save_2("swqizhi",20);
			who->set_legend(TASK_13, 26);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,21,"棋子(Hoàn thành)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_YANGUO,21);
		send_user(who,"%c%s",'!',sprintf(HIY"棋子 %d/20",i));		
	}
	if( who->get_legend(TASK_14, 15) && !who->get_legend(TASK_14, 16) && random(100) < 15)
	{
		item = new("item/98/0060");
		if ( !item  )
			return ;
		p = item->move(who,-1);
		if ( !p )
		{
			destruct(item);
			return;
		}
		item->add_to_user(p);
		who->set_legend(TASK_14, 16);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,28,"Đàn nhị(Hoàn thành)" );
		USER_TASK_D->send_task_intro(who,2,TID_YANGUO,28);
		send_user(who,"%c%s",'!',sprintf(HIY"Đàn nhị %d/1",1));		
	}
	if( who->get_legend(TASK_15, 12) && !who->get_legend(TASK_15, 13) && random(100) < 20)
	{
		if ( objectp( item = present("Hoàng liên", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 5 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0064");
			if ( !item  )
				return ;
			p = item->move(who,-1);
			if ( !p )
			{
				destruct(item);
				return;
			}
			item->add_to_user(p);
		}
		if ( (i=who->add_save_2("frhuanglian",1)) >= 5 )
		{
			who->set_save_2("frhuanglian",5);
			who->set_legend(TASK_15, 13);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,32,"Căn bệnh của Phu Nhân（3）(Hoàn thành)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_YANGUO,32);
		send_user(who,"%c%s",'!',sprintf(HIY"Hoàng liên %d/5",i));		
	}
	if( who->get_legend(TASK_24, 12) && !who->get_legend(TASK_24, 13) && random(100) < 18)
	{
		item = new("item/98/0114");
		if ( !item  )
			return ;
		p = item->move(who,-1);
		if ( !p )
		{
			destruct(item);
			return;
		}
		item->add_to_user(p);
		who->set_legend(TASK_24, 13);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,30,"Trà Jasmine（3）(Hoàn thành)" );
		USER_TASK_D->send_task_intro(who,2,TID_CHUGUO,30);
		send_user(who,"%c%s",'!',sprintf(HIY"雪水 %d/1",1));		
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

                if( p < 5030 * rate / 100 ) ;    // NONE

/*              else if( p < 5030 * rate / 100 )    // Ngân lượng
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
/*              else if( p < 5030 * rate / 100 )    // 武器(基本)
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
                }       */
/*              else if( p < 5030 * rate / 100 )    // 防具(基本)
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
                }       */
/*              else if( p < 5030 * rate / 100 )    // 武器(门派)
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
                else if( p < 5167 * rate / 100 )    // 防具(门派)
                {
                        if( equip >= total2 ) continue;

                        switch( random(3) )
                        {
                       case 0 : file = ARMOR_FILE->get_armor_file_2(30);  break;
                       case 1 : file = ARMOR_FILE->get_armor_file_2(40);  break;
                       case 2 : file = ARMOR_FILE->get_armor_file_2(50);  break;

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
                }         
                else if( p < 9350 * rate / 100 )    // 杂物１
                {
                        switch( random(2) )
                        {
                       case 0 : file = "/item/40/4034";  break;
                       case 1 : file = "/item/40/4051";  break;

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
                else if( p < 9850 * rate / 100 )    // 杂物２
                {
                        switch( random(3) )
                        {
                       case 0 : file = "/item/91/9111";  break;
                       case 1 : file = "/item/stuff/0047";  break;
                       case 2 : file = "/item/stuff/0049";  break;

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
                else if( p < 9950 * rate / 100 )    // 杂物３
                {
                        switch( random(2) )
                        {
                       case 0 : file = "/item/stuff/0312";  break;
                       case 1 : file = "/item/stuff/0032";  break;

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
                else if( p < 10000 * rate / 100 )    // 杂物４
                {
                        switch( random(1) )
                        {
                       case 0 : file = "/item/stuff/0311";  break;

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
/*              else if( p < 580000 * rate / 100 )    // 杂物５
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
