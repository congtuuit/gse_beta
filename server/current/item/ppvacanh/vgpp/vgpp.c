#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1500 ;}
int get_item_value_2() {return 1500 ;}

int is_back_item () {return 1;}
int level () {return 0;}
string get_code_item() {return "vgpp";}

// 函数：构造处理
void create()
{
        set_name("Vương Giả Phi Phong");
        set_picid_1(3020);
        set_picid_2(3020);

        set_level(1);
		set_bind(1);
        set_value(1500);
        set_max_lasting(21599);
        set("ap+", 300);
        set("pp+", 300);
        set("hp+", 800);
		set("mp+", 800);
		//set("sp+", 100);
		set("double", 500);

		set_hide(0);
        setup();

        set_gender(1);
		set_back_type(1);
}

// 函数：获取描述
string get_desc()
{
        return "Một chiếc áo choàng thần bí kiêu hùng, mặc áo choàng này lên, sẽ hiện lên phong cách của Vương Giả.";
}
