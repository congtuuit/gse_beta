
// 自动生成：/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>

inherit BADMAN;

// 函数：远程攻击的怪
int is_caster() { return 1; }

// 函数：是否允许移动
// int is_moveable() { return 0; }    // 禁止使用 go 命令

// 函数：跟随对手(心跳之中调用)
// void follow_user() { }    // 禁止跟随敌人

// 函数：获取人物造型
//int get_char_picid() { return 9961; }
int get_char_picid() { return 8250; }

// 函数：构造处理
void create()
{
    set_name("Tiểu Miu Tinh");

    set_char_type(FIGHTER_TYPE);    // init_level 要用到

    set_head_color(0x0);

    NPC_ENERGY_D->init_level(this_object(), 120 + random(5));    // 
    set_max_seek(6);

    setup();
    add_cp(400 + random(300));
    set_char_type(FIGHTER_TYPE);    // 重设类型
}

// 函数：获取装备代码
int get_weapon_code() { return UNARMED; }

// 函数：特技攻击对手
int perform_action(object who) { return PF_FILE_04232->perform_action_npc(this_object(), who); }

// 函数：自动战斗(遇玩家时调用)
// void auto_fight( object who ) { }

// 函数：任务处理(有任务时调用)
// void check_legend_task( object who ) { USER_TASK_D->kill_legend_npc( who, this_object() ); }

// 函数：掉宝奖励
void drop_items(object who) { __FILE__->drop_items_callout(this_object(), who); }

// 函数：掉宝奖励(在线更新)
void drop_items_callout(object me, object who)
{
    object item, leader;
    string file, owner, id;
    int p, rate, i, size, gold, equip, total, total2;
    int z, x, y;

    z = get_z(me);  x = get_x(me);  y = get_y(me);
    id = who->get_leader();
    /*if(who->get_save_2("kiemtradanhanchua.score") == 3)
    {
                    if(who->add_save_2("soquaicandiet2.score")>=4)
                    {
                                    send_user(who,"%c%s",'!',sprintf("Nhiệm vụ thương nhân đã hoàn thành"));
                                    return 0;
                    }
                    who->add_save_2("soquaicandiet2.score",1);
                    send_user(who,"%c%s",'!',sprintf("Đã giết được %d/4",who->get_save_2("soquaicandiet2.score")));
    }*/
    if (!id) owner = who->get_id();
    else
    {
        if (leader = find_player(id))
        {
            owner = leader->get_id();
        }
        else
            owner = who->get_id();
    }

    p = random(100);  size = (p > 2) ? 1 : (p > 0) ? 2 : 8;  total = 2;  total2 = 3;
    //      p = random(100);  size = ( p > 40 ) ? 3 : 10;  total = 2;  total2 = 3;

    rate = me->correct_drop_rate(me->get_level() - who->get_level()) * who->get_online_rate() / 100;

    for (i = 0; i < size; i++)
    {
        p = random(10000);

        if (p < 8799 * rate / 100);    // NONE

        else if (p < 9049 * rate / 100)    // Ngân lượng
        {
            if (gold >= total) continue;

            if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
            {
                item = new("/item/std/0001");
                TEAM_D->drop_item(item, who);
                item->set_user_id(owner);
                item->set_value(760 + random(320));
                item->add_to_scene(z, p / 1000, p % 1000);
                item->set("winner", who);
                item->set("time", time());
                gold++;
            }
        }
        /*              else if( p < 9049 * rate / 100 )    // 武器(基本)
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
                        /*              else if( p < 9049 * rate / 100 )    // 防具(基本)
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
        else if (p < 9075 * rate / 100)    // 武器(门派)
        {
            if (equip >= total2) continue;

            switch (random(3))
            {
            case 0: file = WEAPON_FILE->get_weapon_file_2(70);  break;
            case 1: file = WEAPON_FILE->get_weapon_file_2(80);  break;
            case 2: file = WEAPON_FILE->get_weapon_file_2(90);  break;

            default: break;
            }
            if (load_object(file) && (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK)))
            {
                item = new(file);
                TEAM_D->drop_item(item, who);
                item->set_user_id(owner);
                ITEM_EQUIP_D->init_equip_prop(item);
                item->add_to_scene(z, p / 1000, p % 1000);
                item->set("winner", who);
                item->set("time", time());
                equip++;
            }
        }
        else if (p < 9101 * rate / 100)    // 防具(门派)
        {
            if (equip >= total2) continue;

            switch (random(3))
            {
            case 0: file = ARMOR_FILE->get_armor_file_2(70);  break;
            case 1: file = ARMOR_FILE->get_armor_file_2(80);  break;
            case 2: file = ARMOR_FILE->get_armor_file_2(90);  break;

            default: break;
            }
            if (load_object(file) && (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK)))
            {
                item = new(file);
                TEAM_D->drop_item(item, who);
                item->set_user_id(owner);
                ITEM_EQUIP_D->init_equip_prop(item);
                item->add_to_scene(z, p / 1000, p % 1000);
                item->set("winner", who);
                item->set("time", time());
                equip++;
            }
        }
        /*              else if( p < 9101 * rate / 100 )    // 杂物１
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
        else if (p < 9851 * rate / 100)    // 杂物２
        {
            switch (random(5))
            {
            case 0: file = "/item/91/9140";  break;
            case 1: file = "/item/stuff/0130";  break;
            case 2: file = "/item/stuff/0191";  break;
            case 3: file = "/item/stuff/0053";  break;
            case 4: file = "/item/stuff/0187";  break;

            default: break;
            }
            if (load_object(file) && (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK)))
            {
                item = new(file);
                TEAM_D->drop_item(item, who);
                item->set_user_id(owner);
                item->add_to_scene(z, p / 1000, p % 1000);
                item->set("winner", who);
                item->set("time", time());
            }
        }
        else if (p < 9951 * rate / 100)    // 杂物３
        {
            switch (random(2))
            {
            case 0: file = "/item/41/4109";  break;
            case 1: file = "/item/stuff/0310";  break;

            default: break;
            }
            if (load_object(file) && (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK)))
            {
                item = new(file);
                TEAM_D->drop_item(item, who);
                item->set_user_id(owner);
                item->add_to_scene(z, p / 1000, p % 1000);
                item->set("winner", who);
                item->set("time", time());
            }
        }
        else if (p < 10001 * rate / 100)    // 杂物４
        {
            switch (random(1))
            {
            case 0: file = "/item/stuff/0309";  break;

            default: break;
            }
            if (load_object(file) && (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK)))
            {
                item = new(file);
                TEAM_D->drop_item(item, who);
                item->set_user_id(owner);
                item->add_to_scene(z, p / 1000, p % 1000);
                item->set("winner", who);
                item->set("time", time());
            }
        }
        /*              else if( p < 220015 * rate / 100 )    // 杂物５
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
