#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <music.h>

inherit OFFICER;
int get_char_picid() { return 2702; }
void do_welcome(string arg);
void create()
{
        set_name("");
        setup();
}

void do_look(object who)
{
}

