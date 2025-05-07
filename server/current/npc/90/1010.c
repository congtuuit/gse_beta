
#include <npc.h>
#include <ansi.h>

inherit OFFICER;

void do_goto( string arg );

int get_char_picid() { return 5802; }

string get_fam_name() { return "Đào Hoa Nguyên"; }

int get_fam_order() { return 6; }


void create()
{
        set_name("Ngư Phu");
        set_real_name("Xa Phu");

        set_2( "talk", ([
                "go"   : (: do_goto :),
        ]));

        setup();
}

void do_look( object who )
{
	"/sys/task/travel"->do_look2(this_object(), who);        
}

void do_goto( string  arg )
{
	"/sys/task/travel"->do_goto2(this_object(), this_player(), arg);     
}