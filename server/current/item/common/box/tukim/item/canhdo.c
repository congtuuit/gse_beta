#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1500 ;}
int get_item_value_2() {return 1500 ;}

int is_back_item () {return 1;}
int level () {return 0;}
string get_code_item() {return "canhdo";}

void create()
{
        set_name("Huyết Long Chi Dực");
        set_picid_1(3029);
        set_picid_2(3029);

        set_level(1);
		set_bind(1);
        set_value(1500);
        set_max_lasting(21599);
        set("cp+", 400);
        set("dp+", 350);
        set("pp+", 50);
        set("hp+", 900);
		set("mp+", 900);
		set("sp+", 150);
		set("double", 500);

        setup();

        set_back_type(7);
		set_back2_type(7);
        set_back_color(0x7000);
        set_back2_color(0x7000);
}

// 函数：获取描述
string get_desc()
{
        return "Thánh vật của sứ giả Quang Minh, dùng để ngăn cản lực lượng tà ác uy hiếp.";
}
