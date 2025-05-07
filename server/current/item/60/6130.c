
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 6; }

// 函数：构造处理
void create()
{
        set_name("Phi Thiên Vũ Y");
        set_picid_1(6125);
        set_picid_2(6125);

        set_level(130);
        set_value(10000);
        set_max_lasting(16099);
        set("dp", 167);
        set("pp", 319);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "Phi Thiên Vũ Y";
}
