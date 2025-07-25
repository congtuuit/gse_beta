
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 1; }

// 函数：成品编号
int get_fin_type() { return 1136; }

// 函数：构造处理
void create()
{
        set_name("Tử Thần Lung Thủ");
        set_picid_1(7022);
        set_picid_2(7022);

        set_level(85);
        set_value(8500);
        set_max_lasting(13599);
        set("ap", 195);
        set("dp", 70);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(UNARMED);
}

// 函数：获取武器级别
int get_weapon_level() { return LEVEL_09; }

// 函数：获取描述
string get_desc()
{
        return "Trang bị “Quyền Pháp”";
}
