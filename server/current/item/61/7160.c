
// 自动生成：/make/equip/60b

#include <equip.h>
#include <level.h>
#include <item.h>
#include <effect.h>
#include <skill.h>

inherit ARMOR;

int get_family() { return 7; }
// 函数：构造处理
void create()
{
        set_name("Càn Khôn Chiến Bào");
        set_picid_1(6182);        set_picid_2(6182);

        set_level(150);        set_value(78500);
        set_max_lasting(50099);
        set("dp+", 450);
        set("pp+", 450);
		set("hp+", 700);
		set("hp%+", 10);
		set("mp%+", 10);
		set("mp+", 700);
		set("-*%", 10);
		set("sp+", 300);
		//set_item_color(2);

        setup();

        set_gender(2);
        set_armor_code(F_BEIZI);
}

// 函数：获取描述
string get_desc()
{
        return "Bá Vương Chiến Bào";
}