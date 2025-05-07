
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

//int is_item_seller() { return 1; }
int is_seller() { return 70021; }
int is_self_look() { return 1; }

//int get_char_picid() { return 4984; }
int get_char_picid() { return 9512; }

void create()
{
	set_name("Đổi Thú Cưỡi");
	//set_real_name("Người bán hàng rong");

	set_2("good", ([
		"01":"/item/thucuoi/001",
			"02" : "/item/thucuoi/002",
			"03" : "/item/thucuoi/003",
			"04" : "/item/thucuoi/004",
			"05" : "/item/thucuoi/005",
			"06" : "/item/thucuoi/006",
			"07" : "/item/thucuoi/007",
			"08" : "/item/thucuoi/008",
			"09" : "/item/thucuoi/009",
			"10" : "/item/thucuoi/010",
			"11" : "/item/thucuoi/011",
			"12" : "/item/thucuoi/012",
	]));

	setup();
}

void do_look(object who)
{
	int id = getoid(this_object());
	send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), sprintf(" %s :\n Bạn muốn mua vật phẩm không ? \n\n"
		ESC HIY"Đổi vật phẩm\nlist2 %x#\n"
		ESC"Rời khỏi", get_name(), id));
}