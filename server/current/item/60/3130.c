
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("Cuồng Chiến Chiến Giáp");
        set_picid_1(6042);
        set_picid_2(6042);

        set_level(130);
        set_value(10000);
        set_max_lasting(16099);
        set("dp", 302);
        set("pp", 184);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "Cuồng Chiến Chiến Giáp";
}
