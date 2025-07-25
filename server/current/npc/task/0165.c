
// 自动生成：/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
inherit LEGEND_NPC;

// 函数：获取人物造型
int get_char_picid() { return 1051; }

// 函数：构造处理
void create()
{
        set_name("马宁");

        set_level(76);
	set_max_hp(1900);
	set_ap(490);
	set_dp(513);
	set_cp(552);
	set_pp(274);
	set_sp(203);
	set_walk_speed(4);
	set_attack_speed(13);
        set_max_seek(4);

        setup();
        set_char_type(FIGHTER_TYPE_2);  
}

void check_legend_task( object who )
{
        if ( objectp(who) && who->get_legend(TASK_23, 14) && !who->get_legend(TASK_23, 15) )
        {
		who->set_legend(TASK_23, 15);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_MAOSHAN,4,"游魂（5）(Hoàn thành)" );
		send_user(who, "%c%s",'!', "马宁 1/1");
	}
}
   