
#include <equip.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Thiên Ma Đao");
        set_picid_1(7220);
        set_picid_2(7220);
        set_unit("口");

        set_level(150);
        set_value(57000);
        set_max_lasting(77599);
        set("ap", 311);
        set("dp", 0);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(BLADE);
}

// 函数：获取武器级别
int get_weapon_level() { return 23; }

// 函数：获取描述
string get_desc()
{
        return "Trang bị “Đao Pháp”";
}
