
#include <equip.h>

inherit NECK;

int get_family() { return 1; }
int get_item_color() { return 2; }
int is_item_cqmc() { return 1; }

void create()
{
        set_name("Bích Vân Hạng Liên");
        set_picid_1(8611);
        set_picid_2(8611);

        set_level(100);
        set_value(24000);
        set_max_lasting(7399);
        set("cp", 0);
        set("pp", 40);
        setup();
}

string get_desc()
{
        return "Bích Vân Hạng Liên";
}
