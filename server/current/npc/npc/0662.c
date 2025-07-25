
// 自动生成：/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;

// 函数：远程攻击的怪
   int is_caster() { return 0; }

// 函数：是否允许移动
// int is_moveable() { return 0; }    // 禁止使用 go 命令

// 函数：跟随对手(心跳之中调用)
// void follow_user() { }    // 禁止跟随敌人

// 函数：获取人物造型
int get_char_picid() { return 0652; }

// 函数：构造处理
void create()
{
        set_name("Tần Quốc Cung Binh");

        set_char_type(FIGHTER_TYPE);    // init_level 要用到
        
        set_head_color(0x0);

        NPC_ENERGY_D->init_level( this_object(), 66+ random(3) );    // 
        set_max_seek(6);

        setup();

        set_char_type(FIGHTER_TYPE);    // 重设类型
}

// 函数：获取装备代码
int get_weapon_code() { return UNARMED; }

// 函数：特技攻击对手
//int perform_action( object who ) { return PF_FILE_04232->perform_action_npc( this_object(), who ); }
int perform_action( object who ) { return 0; }

// 函数：自动战斗(遇玩家时调用)
// void auto_fight( object who ) { }

// 函数：任务处理(有任务时调用)
void check_legend_task( object who )
{
	int p,i;
	object item;
	if( who->get_legend(TASK_18, 16) && !who->get_legend(TASK_18, 17) && random(100) < 35)
	{
		if ( objectp( item = present("剑", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 20 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0080");
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
		if ( (i=who->add_save_2("qgdjjjian",1)) >= 20 )
		{
			who->set_save_2("qgdjjjian",20);
			who->set_legend(TASK_18, 17);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,11,"大展神威（1）(Hoàn thành)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,11);
		send_user(who,"%c%s",'!',sprintf(HIY"剑 %d/20",i));		
	}
	if( who->get_legend(TASK_18, 22) && !who->get_legend(TASK_18, 23) && random(100) < 35)
	{
		if ( objectp( item = present("锄头", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 20 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0081");
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
		if ( (i=who->add_save_2("qgdjjchutou",1)) >= 20 )
		{
			who->set_save_2("qgdjjchutou",20);
			who->set_legend(TASK_18, 23);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,14,"大展神威（4）(Hoàn thành)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,14);
		send_user(who,"%c%s",'!',sprintf(HIY"锄头 %d/20",i));		
	}
	if( who->get_legend(TASK_19, 7) && !who->get_legend(TASK_19, 8) && random(100) < 35)
	{
		if ( objectp( item = present("特殊泥土", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 20 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0085");
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
		if ( (i=who->add_save_2("teshunitu",1)) >= 20 )
		{
			who->set_save_2("teshunitu",20);
			who->set_legend(TASK_19, 8);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,18,"大葫芦（4）(Hoàn thành)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,18);
		send_user(who,"%c%s",'!',sprintf(HIY"特殊泥土 %d/20",i));		
	}
	if( who->get_legend(TASK_19, 19) && !who->get_legend(TASK_19, 20) )
	{
		if ( (i=who->add_save_2("qgtaofan",1)) >= 20 )
		{
			who->set_legend(TASK_19, 20);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,21,"追捕逃犯(Hoàn thành)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,21);
		send_user(who,"%c%s",'!',sprintf(HIY"Tần Quốc Cung Binh %d/20",i));		
	}
	if( who->get_legend(TASK_20, 10) && !who->get_legend(TASK_20, 11) && random(100) < 10)
	{
		if ( objectp( item = present("纸钱", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 5 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0091");
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
		if ( (i=who->add_save_2("qgbxzhiqian",1)) >= 5 )
		{
			who->set_save_2("qgbxzhiqian",5);
			who->set_legend(TASK_20, 11);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,50,"重阳节（1）(Hoàn thành)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,50);
		send_user(who,"%c%s",'!',sprintf(HIY"纸钱 %d/5",i));		
	}
	if( who->get_legend(TASK_22, 13) && !who->get_legend(TASK_22, 14) && who->get_save_2("qzggongbing",1) < 10)
	{
		if ( (i=who->add_save_2("qzggongbing",1)) >= 10 && who->get_save_2("qzgdaodunbing",1) >= 10 && who->get_save_2("qzgqiangbing",1) >= 10 )
		{
			who->set_legend(TASK_22, 14);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,45,"Hàm ý tội ác(Hoàn thành)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,45);
		send_user(who,"%c%s",'!',sprintf(HIY"Tần Quốc Cung Binh %d/10",i));		
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

                if( p < 5553 * rate / 100 ) ;    // NONE

                else if( p < 5803 * rate / 100 )    // Ngân lượng
                {
                        if( gold >= total ) continue;

                        if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                        {
                                item = new( "/item/std/0001" );
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->set_value( 460 + random(60) );
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                                gold ++;
                        }
                }         
/*              else if( p < 5803 * rate / 100 )    // 武器(基本)
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
/*              else if( p < 5803 * rate / 100 )    // 防具(基本)
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
                else if( p < 5864 * rate / 100 )    // 武器(门派)
                {
                        if( equip >= total2 ) continue;

                        switch( random(3) )
                        {
                       case 0 : file = WEAPON_FILE->get_weapon_file_2(40);  break;
                       case 1 : file = WEAPON_FILE->get_weapon_file_2(50);  break;
                       case 2 : file = WEAPON_FILE->get_weapon_file_2(60);  break;

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
                else if( p < 5911 * rate / 100 )    // 防具(门派)
                {
                        if( equip >= total2 ) continue;

                        switch( random(3) )
                        {
                       case 0 : file = ARMOR_FILE->get_armor_file_2(40);  break;
                       case 1 : file = ARMOR_FILE->get_armor_file_2(50);  break;
                       case 2 : file = ARMOR_FILE->get_armor_file_2(60);  break;

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
                        switch( random(1) )
                        {
                       case 0 : file = "/item/40/4055";  break;

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
                       case 0 : file = "/item/stuff/0192";  break;
                       case 1 : file = "/item/stuff/0051";  break;
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
                       case 0 : file = "/item/41/4110";  break;
                       case 1 : file = "/item/stuff/0310";  break;

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
                       case 0 : file = "/item/stuff/0309";  break;

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
/*              else if( p < 690000 * rate / 100 )    // 杂物５
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
