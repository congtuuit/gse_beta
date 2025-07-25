
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 7; }

// 函数：构造处理
void create()
{
        set_name("Tuyết Kiếm");
        set_picid_1(7314);       set_picid_2(7314);

        set_level(150);
        set_value(57000);
        set_max_lasting(76599);
        set("ap", 245);
        set("dp", 0);
        set("cp", 395);
        set("sp", 0);

        setup();

        set_weapon_type(SWORD);
}

// 函数：获取武器级别
int get_weapon_level() { return LEVEL_14; }

// 函数：获取描述
string get_desc()
{
        return "“Kiếm Pháp” trang bị";
}
