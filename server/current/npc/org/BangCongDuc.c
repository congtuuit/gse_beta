#include <npc.h>
#include <ansi.h>
#include <city.h>
#include <effect.h>

inherit OFFICER;

int get_char_picid() { return 2005; }

void create()
{
        set_city_name("");
        set_name( "Bảng Công Đức" );
        setup();
}
void do_look(object who)
{
	return "sys/party/mingren"->do_look4(who);
}