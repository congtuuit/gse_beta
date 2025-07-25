
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 8; }

// 函数：构造处理
void create()
{
        set_name("Đoản Đao");
        set_picid_1(7225);
        set_picid_2(7225);

        set_level(15);
        set_value(1200);
        set_max_lasting(6599);
        set("ap", 48);
        set("dp", 0);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(BLADE);
}

// 函数：获取武器级别
int get_weapon_level() { return LEVEL_02; }

// 函数：获取描述
string get_desc()
{
        return "Trang bị “Đao Pháp”";
}
