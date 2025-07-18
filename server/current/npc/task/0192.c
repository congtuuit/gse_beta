
// 自动生成：/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
inherit LEGEND_NPC;

// 函数：获取人物造型
int get_char_picid() { return 0252; }

// 函数：构造处理
void create()
{
        set_name("龙九");

        set_level(114);
	set_max_hp(2700);
	set_ap(720);
	set_dp(620);
	set_cp(100);
	set_pp(380);
	set_sp(280);
	set_walk_speed(3);
	set_attack_speed(13);
        set_max_seek(4);
        
        setup();
        set_char_type(FIGHTER_TYPE_2);  
}

void check_legend_task( object who )
{
        if ( objectp(who) && who->get_legend(TASK_43, 9) && !who->get_legend(TASK_43, 10) )
        {
		who->set_legend(TASK_43, 10);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,90,"Xóa bỏ mối đe dọa(Hoàn thành)" );
		send_user(who, "%c%s",'!', "龙九 1/1");
	}
}
