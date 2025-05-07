
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

int is_item_seller() { return 1; }
int is_seller() { return 1; }
int is_self_look() { return 1; }

int get_char_picid() { return 4984; }

void create()
{
	set_name("Người bán hàng rong");
	set_real_name("Thương gia bí ẩn");

	set_2("good", ([
		"01":"/item/common/attribute",
	]));

	setup();
}

void do_look(object who)
{
	int id = getoid(this_object());
	send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), sprintf(" %s :\n Bạn muốn mua vật phẩm không ? \n\n"
		ESC HIY"Mua vật phẩm\nlist %x#\n"
		ESC"Rời khỏi", get_name(), id));
}