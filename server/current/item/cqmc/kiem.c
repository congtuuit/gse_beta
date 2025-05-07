#include <ansi.h>
#include <equip.h>
#include <level.h>

inherit WEAPON;

int get_family() { return 9; }
int get_item_color() { return 2; }
int is_item_cqmc() { return 1; }

void create()
{
        set_name("Bích Vân Kiếm");
        set_picid_1(7303);
        set_picid_2(7303);

        set_level(100);
        set_value(10000);
        set_max_lasting(13599);
        set("ap", 150);
        set("dp", 50);
        set("cp", 425);
        set("pp", 50);
        set_item_color(2);
        setup();

        set_weapon_type(SWORD);
}

int get_weapon_level() { return 100; }

string get_desc()
{
        return "Trang bị “Kiếm Pháp”";
}
