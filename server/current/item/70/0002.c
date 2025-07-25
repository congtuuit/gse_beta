
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 8; }

// 函数：构造处理
void create()
{
        set_name("Thô Ma Thủ");
        set_picid_1(7000);
        set_picid_2(7000);

        set_level(0);
        set_value(450);
        set_max_lasting(6099);
        set("ap", 35);
        set("dp", 3);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(UNARMED);
}

// 函数：获取武器级别
int get_weapon_level() { return LEVEL_00; }

// 函数：获取描述
string get_desc()
{
        return "Trang bị “Quyền Pháp”";
}
