
// 自动生成：/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
inherit LEGEND_NPC;

// 函数：获取人物造型
int get_char_picid() { return 0900; }

// 函数：构造处理
void create()
{
        set_name("迷魂精灵");

        set_level(37);
	set_max_hp(700);
	set_ap(280);
	set_dp(300);
	set_cp(100);
	set_pp(180);
	set_sp(120);
	set_walk_speed(4);
	set_attack_speed(13);
        set_max_seek(4);

        setup();
        set_char_type(FIGHTER_TYPE_2);  
}

void check_legend_task( object who )
{
        if ( objectp(who) && who->get_legend(TASK_08, 22) && !who->get_legend(TASK_08, 23) )
        {
		who->set_legend(TASK_08, 23);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,20,"Câu thần chú của Đường Cangwu(Hoàn thành)" );
		send_user(who, "%c%s",'!', "迷魂精灵 1/1");
	}
        
}
