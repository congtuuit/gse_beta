
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// 函数：小贩识别
int is_item_seller() { return 1; }

// 函数：获取人物造型
int get_char_picid() { return 5402; }

// 函数：构造处理
void create()
{
        set_name("Cửa Tiệm Hỗ Trợ");
        set_city_name("Chu Quốc");

        set_2( "good", ([
				"01" : "/item/test/dacankhon",
				"02" : "/item/test/datuonguyen",
				"03" : "/item/sell/0033",
				"04" : "/item/sell/0032",
				"05" : "/item/sell/1032",
				"06" : "/item/sell/2032",
				"07" : "/item/73/1075",
				"08" : "/item/71/1075",
				"09" : "/item/74/1075",
				"10" : "/item/75/1075",
				"11" : "/item/72/1075",
				"12" : "/item/70/1075",
        ]) );
        setup();
}
