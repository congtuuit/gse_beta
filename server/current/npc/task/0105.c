
// 自动生成：/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
inherit LEGEND_NPC;
object boss1;

// 函数：获取人物造型
int get_char_picid() { return 0651; }

// 函数：构造处理
void create()
{
        set_name("Thọ Căn Quân");

        set_level(18);
	set_max_hp(200);
	set_ap(112);
	set_dp(100);
	set_pp(120);
	set_sp(60);
	set_walk_speed(4);
	set_attack_speed(20);
        set_max_seek(4);

        setup();
        set_char_type(FIGHTER_TYPE_2);
}

void check_legend_task( object who )
{
	object me=this_object();
        if ( objectp(who) && who->get_legend(TASK_NEWBIE_03, 26)&&!who->get_legend(TASK_NEWBIE_03, 27) && who->get_save_2("zxkillnpc")==me->get_name() )
        {
		who->set_legend(TASK_NEWBIE_03, 27);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_DONGTINGHU,2,"亡羊补牢(3)(Hoàn thành)" );
		USER_TASK_D->send_task_intro(who,2,TID_DONGTINGHU,2);
		send_user(who, "%c%s",'!', who->get_save_2("zxkillnpc")+ " 1/1");
	}	
}