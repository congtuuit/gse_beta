#include <npc.h>
#include <ansi.h>
#include <cmd.h>
#include <public.h>

#define SESSION_TOWER  "sys/party/thapchiton"

inherit OFFICER;

int get_char_picid()
{
	return 5205;
}

void do_welcome(string arg);
void create()
{
	set_name("Tháp Truyền Tống");
	set_real_name(HIR"Mục Phu");
	set_2("talk",(["welcome":(:do_welcome:)]));
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
