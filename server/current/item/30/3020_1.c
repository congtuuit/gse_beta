#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}

// 函数：构造处理
void create()
{
        set_name("Vương Giả Phi Phong +1");
        set_picid_1(3020);
        set_picid_2(3020);

        set_level(1);
		set_bind(0);
        set_value(1000);
        set_max_lasting(21599);
        set("ap+", 500);
        set("pp+", 500);
        set("hp+", 1200);
		set("mp+", 1200);
		set("sp+", 200);
		set("double", 1000);
		set_hide(0);
        setup();

        set_gender(1);
		set_back_type(1);
}

// 函数：获取描述
string get_desc()
{
        return "★Một chiếc áo choàng thần bí kiêu hùng, mặc áo choàng này lên, sẽ hiện lên phong cách của Vương Giả.";
}
