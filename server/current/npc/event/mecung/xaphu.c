#include <npc.h>
#include <ansi.h>
#include <cmd.h>
#include <public.h>

#include <task.h>
#include <equip.h>
#include <time.h>
#include <effect.h>

inherit OFFICER;
#define SESSION_TOWER  "sys/party/mecung"

int is_seller() { return 7005; }
int is_self_look() { return 1; }
void do_welcome(string arg);
int get_char_picid()
{
	return 5205;
}

void create()
{
	set_name("Mê Cung Truyền Tống");
	set_real_name(HIR"Ẩn Sĩ");

	set_2("good", ([
		"01" : "/item/common/stone/101",
		"02" : "/item/common/stone/102",
		"03" : "/item/common/stone/103",
		"04" : "/item/common/stone/104",
		"05" : "/item/common/stone/105",
		"06" : "/item/common/stone/tinhthach",
		"07" : "/item/common/stone/duclo",
	]));

	set_2("talk", (["welcome":(:do_welcome:)]));

	setup();
}

void do_look(object who)
{
	SESSION_TOWER->do_look(who,this_object());
}

void do_welcome(string arg)
{
	object me=this_object();
	__FILE__->do_welcome2(me,arg);
}

void do_welcome2(object me, string arg)
{
	SESSION_TOWER->do_welcome(me,this_player(),arg);
}
