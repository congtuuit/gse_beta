
#include <equip.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 1; }

// 函数：构造处理
void create()
{
        set_name("Trùng Thiên Quyền");
        set_picid_1(7004);
        set_picid_2(7004);
        set_unit("双");

        set_level(150);
        set_value(57000);
        set_max_lasting(77599);
        set("ap", 325);
        set("dp", 46);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(UNARMED);
}

// 函数：获取武器级别
int get_weapon_level() { return 23; }

// 函数：获取描述
string get_desc()
{
        return "Trang bị “Quyền Pháp”";
}
