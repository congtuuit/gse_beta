
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 1; }

// 函数：成品编号
int get_fin_type() { return 1112; }

// 函数：构造处理
void create()
{
        set_name("Bạch Hổ Quyền Sáo");
        set_picid_1(7010);
        set_picid_2(7010);

        set_level(45);
        set_value(4500);
        set_max_lasting(6099);
        set("ap", 115);
        set("dp", 30);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(UNARMED);
}

// 函数：获取武器级别
int get_weapon_level() { return LEVEL_05; }

// 函数：获取描述
string get_desc()
{
        return "Trang bị “Quyền Pháp”";
}
