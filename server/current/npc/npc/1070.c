
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
int get_char_picid() { return 1051; }

// 函数：构造处理
void create()
{
        set_name("Địa Sát Môn Thủ");

        set_char_type(FIGHTER_TYPE);    // init_level 要用到
        
        set_head_color(0x0);

        NPC_ENERGY_D->init_level( this_object(), 106+ random(4) );    // 
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
	int p,i,iRate;
	object item;

	if( who->get_legend(TASK_39, 20) && !who->get_legend(TASK_39, 21) && who->get_save("qgswdisamzs") < 3 )
	{
		if ( (i=who->add_save("qgswdisamzs",1)) >= 3 && who->get_save("qgswtaijimzs") >= 6 )
		{
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,58,"Điểm mấu chốt（3）(Hoàn thành)" );
			who->set_legend(TASK_39, 21);
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,58);
		send_user(who,"%c%s",'!',sprintf(HIY"Địa Sát Môn Thủ %d /3",i));		
	}
	if( who->get_legend(TASK_41, 28) && !who->get_legend(TASK_41, 29) && who->get_save("zgbxdsmzs") < 30 )
	{
		if ( (i=who->add_save("zgbxdsmzs",1)) >= 30 && who->get_save("zgbxshouztb") >= 30 )
		{
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,76,"Đột nhập vào Thiên Quân(Hoàn thành)" );
			who->set_legend(TASK_41, 29);
		}
		USER_TASK_D->send_task_intro(who,2,TID_ZHAOGUO,76);
		send_user(who,"%c%s",'!',sprintf(HIY"Địa Sát Môn Thủ %d /30",i));		
	}
	if( who->get_legend(TASK_43, 17) && !who->get_legend(TASK_43, 18) && random(100) < 23)
	{
		if ( objectp( item = present("救急丹", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 5 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0212");
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
		if ( (i=who->add_save("qgswjiujd",1)) >= 5 )
		{
			who->set_legend(TASK_43, 18);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,59,"Sự giúp đỡ của bạn bè(Hoàn thành)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,59);
		send_user(who,"%c%s",'!',sprintf(HIY"救急丹 %d/5",i));		
	}
	if( who->get_legend(TASK_44, 1) && !who->get_legend(TASK_44, 2) && who->get_save("ygswdismzs") < 9 )
	{
		if ( (i=who->add_save("ygswdismzs",1)) >= 9 && who->get_save("ygswtaijmzs") >= 11 )
		{
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,51,"Bóng tối bao trùm chúng ta(Hoàn thành)" );
			who->set_legend(TASK_44, 2);
		}
		USER_TASK_D->send_task_intro(who,2,TID_YANGUO,51);
		send_user(who,"%c%s",'!',sprintf(HIY"Địa Sát Môn Thủ %d /9",i));		
	}
	if( who->get_legend(TASK_44, 4) && !who->get_legend(TASK_44, 5) && random(100) < 38)
	{
		if ( objectp( item = present("做床的木头", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 30 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0217");
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
		if ( (i=who->add_save("wggjmutou",1)) >= 30 )
		{
			who->set_legend(TASK_44, 5);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,62,"Giường đẹp（1）(Hoàn thành)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_WEIGUO,62);
		send_user(who,"%c%s",'!',sprintf(HIY"做床的木头 %d/30",i));		
	}
	if( who->get_legend(TASK_44, 21) && !who->get_legend(TASK_44, 22) && who->get_save("qzgdismzs") < 8 )
	{
		if ( (i=who->add_save("qzgdismzs",1)) >= 8 && who->get_save("qzgtaijmzs") >= 8 && who->get_save("qzgjinj") >= 10 && who->get_save("qzgdaohun") >= 4 )
		{
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,62,"Tư vấn nhiệt tình（4）(Hoàn thành)" );
			who->set_legend(TASK_44, 22);
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,62);
		send_user(who,"%c%s",'!',sprintf(HIY"Địa Sát Môn Thủ %d /8",i));		
	}
	if( who->get_legend(TASK_45, 10) && !who->get_legend(TASK_45, 11) && random(100) < 32)
	{
		if ( objectp( item = present("Măng tây", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 20 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0223");
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
		if ( (i=who->add_save("qwwenzhu",1)) >= 20 )
		{
			who->set_legend(TASK_45, 11);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,70,"Vinh quang tối cao（2）(Hoàn thành)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_QIGUO,70);
		send_user(who,"%c%s",'!',sprintf(HIY"Măng tây %d/20",i));		
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

                if( p < 8626 * rate / 100 ) ;    // NONE

                else if( p < 9326 * rate / 100 )    // Ngân lượng
                {
                        if( gold >= total ) continue;

                        if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                        {
                                item = new( "/item/std/0001" );
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->set_value( 800 + random(380) );
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                                gold ++;
                        }
                }         
/*              else if( p < 9326 * rate / 100 )    // 武器(基本)
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
/*              else if( p < 9326 * rate / 100 )    // 防具(基本)
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
                else if( p < 9338 * rate / 100 )    // 武器(门派)
                {
                        if( equip >= total2 ) continue;

                        switch( random(3) )
                        {
                       case 0 : file = WEAPON_FILE->get_weapon_file_2(80);  break;
                       case 1 : file = WEAPON_FILE->get_weapon_file_2(90);  break;
                       case 2 : file = WEAPON_FILE->get_weapon_file_2(100);  break;

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
                else if( p < 9350 * rate / 100 )    // 防具(门派)
                {
                        if( equip >= total2 ) continue;

                        switch( random(3) )
                        {
                       case 0 : file = ARMOR_FILE->get_armor_file_2(80);  break;
                       case 1 : file = ARMOR_FILE->get_armor_file_2(90);  break;
                       case 2 : file = ARMOR_FILE->get_armor_file_2(100);  break;

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
/*              else if( p < 9350 * rate / 100 )    // 杂物１
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
                else if( p < 9850 * rate / 100 )    // 杂物２
                {
                        switch( random(5) )
                        {
                       case 0 : file = "/item/stuff/0146";  break;
                       case 1 : file = "/item/91/9145";  break;
                       case 2 : file = "/item/stuff/0053";  break;
                       case 3 : file = "/item/91/9135";  break;
                       case 4 : file = "/item/stuff/0187";  break;

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
                       case 0 : file = "/item/41/4109";  break;
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
/*              else if( p < 1070000 * rate / 100 )    // 杂物５
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
