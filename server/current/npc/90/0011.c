#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <effect.h>
inherit OFFICER;
inherit "/inh/std/invite";

// 函数：获取人物造型
//int get_char_picid() { return 5316; }
int get_armor_code() { return 20100; }
string get_fam_name() { return "Đào Hoa Nguyên"; }

// 函数：构造处理
void create()
{	
	object me = this_object();
        set_name("Môn Phái Chiêu Sinh");
		set_real_name("Đào Hoa Nguyên");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));   
        setup();
}

