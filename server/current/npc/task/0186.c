
// 自动生成：/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
inherit LEGEND_NPC;

// 函数：获取人物造型
int get_char_picid() { return 0301; }

// 函数：构造处理
void create()
{
        set_name("蜘蛛精");

        set_level(107);
	set_max_hp(3908);
	set_ap(655);
	set_dp(606);
	set_cp(778);
	set_pp(347);
	set_sp(255);
	set_walk_speed(4);
	set_attack_speed(13);
        set_max_seek(4);
        
        setup();
        set_char_type(FIGHTER_TYPE_2);  
}

void check_legend_task( object who )
{
        if ( objectp(who) && who->get_legend(TASK_37, 4) && !who->get_legend(TASK_37, 5) )
        {
		who->set_legend(TASK_37, 5);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,60,"Tiểu Đồ（1）(Hoàn thành)" );
		send_user(who, "%c%s",'!', "蜘蛛精 1/1");
		USER_TASK_D->send_task_intro(who,2,TID_QIGUO,60);
	}
}
