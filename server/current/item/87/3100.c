
// 自动生成：/make/equip/60b

#include <equip.h>

inherit WAIST;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("Càn Khôn Yêu Đới");
        set_picid_1(8710);
        set_picid_2(8710);

        set_level(100);
        set_value(22500);
        set_max_lasting(13899);
        set("dp", 98);
        set("pp", 85);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "Bá Vương Yêu Đới";
}
