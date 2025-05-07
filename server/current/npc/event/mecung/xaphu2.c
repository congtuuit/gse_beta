#include <npc.h>
#include <ansi.h>
#include <cmd.h>
#include <public.h>

#define SESSION_TOWER "sys/party/mecung"

inherit OFFICER;

// int get_char_action() { return 1; }

// string get_short()
// {
// 	return this_object()->get_name();
// }

// int get_char_type() { return 160; }

int get_char_picid()
{
	return 5205;
}

void do_welcome(string arg);
void create()
{
	set_name("Mê Cung Truyền Tống");
	set_2("talk", (["welcome":( : do_welcome:)]));
	setup();
}

void do_look(object who)
{
	SESSION_TOWER->do_look2(who, this_object());
}

void do_welcome(string arg)
{
	object me = this_object();
	__FILE__->do_welcome2(me, arg);
}

void do_welcome2(object me, string arg)
{
	SESSION_TOWER->do_welcome(me, this_player(), arg);
}
