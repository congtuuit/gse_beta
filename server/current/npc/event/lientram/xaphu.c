#include <npc.h>
#include <ansi.h>
#include <cmd.h>
#include <public.h>

//#define FILE_SENDER "npc/party/0042"
#define SESSION_TOWER  "sys/party/lientram"

inherit OFFICER;

int get_char_picid()
{
	return 8206;
}

void do_welcome(string arg);
void create()
{
	set_name("Phó bản Liên Trảm");
	set_real_name(HIR"Truyền Tống");
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
