
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
int get_char_picid() { return 0852; }

// 函数：构造处理
void create()
{
        set_name("Thương Dũng");

        set_char_type(FIGHTER_TYPE);    // init_level 要用到
        
        set_head_color(0x0);

        NPC_ENERGY_D->init_level( this_object(), 85+ random(4) );    // 
        set_max_seek(4);

        setup();

        set_char_type(FIGHTER_TYPE);    // 重设类型
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
	int p,i;
	object item;

	if( who->get_legend(TASK_29, 10) && !who->get_legend(TASK_29, 11) && random(100) < 25 )
	{
		if ( objectp( item = present("玉雕", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 20 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0141");
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
		if ( (i=who->add_save("wgbxyudiao",1)) >= 20 )
		{
			who->set_save("wgbxyudiao",20);
			who->set_legend(TASK_29, 11);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,33,"Điều kiện của bọn bắt cóc(Hoàn thành)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_WEIGUO,33);
		send_user(who,"%c%s",'!',sprintf(HIY"玉雕 %d/20",i));		
	}
	if( who->get_legend(TASK_29, 28) && !who->get_legend(TASK_29, 29) && who->get_save("qgbxqianyong") < 30 )
	{
		if ( (i=who->add_save("qgbxqianyong",1)) >= 30 && who->get_save("qgbxdaoyong") >= 30)
		{
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,33,"Tự kiểm tra(Hoàn thành)" );
			who->set_legend(TASK_29, 29);
		}
		USER_TASK_D->send_task_intro(who,2,TID_QIGUO,33);
		send_user(who,"%c%s",'!',sprintf(HIY"Thương Dũng %d/30",i));		
	}
	if( who->get_legend(TASK_30, 12) && !who->get_legend(TASK_30, 13) && who->get_save("lbtqianyong") < 30 )
	{
		if ( (i=who->add_save("lbtqianyong",1)) >= 30 && who->get_save("lbtgongjsy") >= 30)
		{
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,37,"Xác định đối thủ(Hoàn thành)" );
			who->set_legend(TASK_30, 13);
		}
		USER_TASK_D->send_task_intro(who,2,TID_QIGUO,37);
		send_user(who,"%c%s",'!',sprintf(HIY"Thương Dũng %d/30",i));		
	}
	if( who->get_legend(TASK_31, 3) && !who->get_legend(TASK_31, 4) && who->get_save("qxfqianyong") < 30 )
	{
		if ( (i=who->add_save("qxfqianyong",1)) >= 30 && who->get_save("qxfgongjsy") >= 30)
		{
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,46,"Nghi ngờ(Hoàn thành)" );
			who->set_legend(TASK_31, 4);
		}
		USER_TASK_D->send_task_intro(who,2,TID_QIGUO,46);
		send_user(who,"%c%s",'!',sprintf(HIY"Thương Dũng %d/30",i));		
	}
	if( who->get_legend(TASK_31, 13) && !who->get_legend(TASK_31, 14) && who->get_save("wwqianyong") < 9 )
	{
		if ( (i=who->add_save("wwqianyong",1)) >= 9 && who->get_save("wwjianyong") >= 12)
		{
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,35,"Truy nã(Hoàn thành)" );
			who->set_legend(TASK_31, 14);
		}
		USER_TASK_D->send_task_intro(who,2,TID_WEIGUO,35);
		send_user(who,"%c%s",'!',sprintf(HIY"Thương Dũng %d/9",i));		
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

                if( p < 6544 * rate / 100 ) ;    // NONE

/*              else if( p < 6544 * rate / 100 )    // Ngân lượng
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
/*              else if( p < 6544 * rate / 100 )    // 武器(基本)
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
/*              else if( p < 6544 * rate / 100 )    // 防具(基本)
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
                else if( p < 6564 * rate / 100 )    // 武器(门派)
                {
                        if( equip >= total2 ) continue;

                        switch( random(3) )
                        {
                       case 0 : file = WEAPON_FILE->get_weapon_file_2(60);  break;
                       case 1 : file = WEAPON_FILE->get_weapon_file_2(70);  break;
                       case 2 : file = WEAPON_FILE->get_weapon_file_2(80);  break;

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
                else if( p < 6584 * rate / 100 )    // 防具(门派)
                {
                        if( equip >= total2 ) continue;

                        switch( random(3) )
                        {
                       case 0 : file = ARMOR_FILE->get_armor_file_2(60);  break;
                       case 1 : file = ARMOR_FILE->get_armor_file_2(70);  break;
                       case 2 : file = ARMOR_FILE->get_armor_file_2(80);  break;

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
                       case 0 : file = "/item/40/4070";  break;
                       case 1 : file = "/item/40/4069";  break;

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
                        switch( random(5) )
                        {
                       case 0 : file = "/item/stuff/0146";  break;
                       case 1 : file = "/item/stuff/0130";  break;
                       case 2 : file = "/item/stuff/0148";  break;
                       case 3 : file = "/item/stuff/0191";  break;
                       case 4 : file = "/item/stuff/0053";  break;

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
/*              else if( p < 900000 * rate / 100 )    // 杂物５
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
