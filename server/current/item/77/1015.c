
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 5; }

// 函数：构造处理
void create()
{
        set_name("Phong Mộc Kiếm");
        set_picid_1(7613);
        set_picid_2(7613);

        set_level(15);
        set_value(3000);
        set_max_lasting(4799);
        set("ap", 30);
        set("dp", 0);
        set("cp", 55);
        set("sp", 0);

        setup();

        set_weapon_type(SWORD);
}

// 函数：获取武器级别
int get_weapon_level() { return LEVEL_02; }

// 函数：获取描述
string get_desc()
{
        return "Trang bị “Kiếm Pháp”";
}
