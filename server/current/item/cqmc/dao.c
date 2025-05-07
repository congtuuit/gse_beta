#include <ansi.h>
#include <equip.h>
#include <level.h>

inherit WEAPON;

int get_family() { return 2; }
int get_item_color() { return 2; }
int is_item_cqmc() { return 1; }

void create()
{
        set_name("Bích Vân Đao");
        set_picid_1(6811);
        set_picid_2(6811);

        set_level(100);
        set_value(10000);
        set_max_lasting(13599);
        set("ap", 450);
        set("hp", 100);
        set("cp", 10);
        set("pp", 50);
        set_item_color(2);
        setup();

        set_weapon_type(BLADE);
}

int get_weapon_level() { return 100; }

string get_desc()
{
        return "Trang bị “Đao Pháp”";
}
