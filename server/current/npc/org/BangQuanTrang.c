#include <npc.h>
#include <ansi.h>
#include <city.h>
#include <effect.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 2005; }

// 函数：构造处理
void create()
{
        set_city_name("");
        set_name( "Quyên Góp Quân Trang" );
        

        setup();
}
void do_look(object who)
{
	return "sys/party/quantrang"->do_look2(who);
}