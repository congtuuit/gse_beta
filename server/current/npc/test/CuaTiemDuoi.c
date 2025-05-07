
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// 函数：小贩识别
int is_item_seller() { return 1; }
int is_seller() { return 1; }
int is_self_look() { return 1; }

// 函数：获取人物造型
int get_char_picid() { return 5402; }

// 函数：构造处理
void create()
{
        set_name("Cửa Tiệm Đuôi");
        set_city_name("Chu Quốc");

        set_2( "good", ([
				"01" : "/item/Duoi/10",
				"02" : "/item/Duoi/11",
				"03" : "/item/Duoi/12",
				"04" : "/item/Duoi/13",
				"05" : "/item/Duoi/14",
				"06" : "/item/Duoi/15",
				"07" : "/item/Duoi/16",
				"08" : "/item/Duoi/17",
				"09" : "/item/Duoi/18",
				"10" : "/item/Duoi/19",
				"11" : "/item/Duoi/20",
				"12" : "/item/Duoi/21",
				"13" : "/item/Duoi/22",
				"14" : "/item/Duoi/23",
				"15" : "/item/Duoi/24",
				"16" : "/item/Duoi/25",
				"17" : "/item/Duoi/26",
				"18" : "/item/Duoi/27",
				"19" : "/item/Duoi/28",
				"20" : "/item/Duoi/29",
				"21" : "/item/Duoi/30",
				"22" : "/item/Duoi/31",
				
        ]) );
        setup();
}
