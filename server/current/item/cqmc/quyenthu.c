#include <ansi.h>
#include <equip.h>
#include <level.h>

inherit WEAPON;

int get_family() { return 1; }
int get_item_color() { return 2; }
int is_item_cqmc() { return 1; }

void create()
{
        set_name("Bích Vân Quyền Thủ");
        set_picid_1(6827);
        set_picid_2(6827);

        set_level(100);
        set_value(10000);
        set_max_lasting(36099);
        set("ap", 370);
        set("hp", 100);
        set("!%+", 100);
        set_item_color(2);
        setup();

        set_weapon_type(UNARMED);
}

int get_weapon_level() { return 100; }

string get_desc()
{
        return "Trang bị “Quyền Pháp”";
}
