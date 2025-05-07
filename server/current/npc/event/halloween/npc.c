#include <npc.h>
#include <ansi.h>
#include <public.h>

#define ZHONGQIU "sys/party/halloween"
inherit OFFICER;

int get_char_picid() { return 4144; }
void do_welcome(string arg);
int is_seller() { return 1; }
int is_self_look() { return 1; }


void create()
{
    set_name("Sứ giả Hallowen");
    set_2("good", ([
        "01":"/item/event/halloween/buahangma",
    ]));

    set_2("talk", ([
        "welcome":(: do_welcome:),
    ]));

    setup();
}

void do_look(object who)
{
    ZHONGQIU->do_look(this_object(), who);
}

void do_welcome(string arg)
{
    object me = this_object();
    ZHONGQIU->do_welcome(me, arg);
}
