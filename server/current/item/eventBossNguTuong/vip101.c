
#include <equip.h>
#include <level.h>
#include <item.h>

inherit "/inh/equip/fashion";;

int get_item_value() {return 550 ;}
int get_item_value_2() {return 550 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Sát Thần Hoả Lân Trang");
        set_picid_1(10058);
        set_picid_2(10058);

        set_level(1);
		set_bind(0);
        set_value(100);
        set_max_lasting(35099);

//		set("time_item", 1);

		set("dp+", 500);
        set("pp+", 500);
        set("hp+", 1200);
		set("hp%+", 20);
		set("mp+", 1200);
		set("mp%+", 20);
		set("!%+", 1000);
		set("?%+", 500);
		set("double", 200);

        setup();

        set_gender(1);

		set_fashion_code(58);
}

// 函数：获取描述
string get_desc()
{
        return "★★★★★★★★★";
}


