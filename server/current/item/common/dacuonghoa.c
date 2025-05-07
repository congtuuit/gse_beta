#include <item.h>
#include <ansi.h>
#include <equip.h>
inherit ITEM;
inherit COMBINED;

int get_item_color() { return 2; }
int get_max_combined() { return 999; }

void create()
{
    set_name("Đá Cường Hóa");
    set_picid_1(12018);
    set_picid_2(12018);
    set_value(10);
    set_amount(1);
}

string get_desc()
{
    return "Viên đá sức mạnh kỳ bí.\nNghe nói nó được dùng để cường hóa trang bị tại NPC Can Tương.";
}
