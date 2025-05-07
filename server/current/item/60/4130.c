
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 4; }

// 函数：构造处理
void create()
{
        set_name("Toàn Phong Phi Phong");
        set_picid_1(6078);
        set_picid_2(6078);

        set_level(130);
        set_value(10000);
        set_max_lasting(16099);
        set("dp", 218);
        set("pp", 179);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "Toàn Phong Phi Phong";
}
