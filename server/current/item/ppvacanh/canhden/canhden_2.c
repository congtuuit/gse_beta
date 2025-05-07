#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1500 ;}
int get_item_value_2() {return 1500 ;}

int is_back_item () {return 1;}
int level () {return 3;}
string get_code_item() {return "canhden";}

void create()
{
        set_name("Hắc Long Chi Dực +2");
        set_picid_1(3036);
        set_picid_2(3036);

        set_level(1);
		set_bind(1);
        set_value(1500);
        set_max_lasting(21599);
        set("ap+", 800);
        set("dp+", 250);
        set("pp+", 650);
        set("hp+", 1650);
        set("mp+", 1650);
        set("sp+", 250);
        set("double", 1000);

        setup();

        //set_gender(2);
        set_back_type(7);
		set_back2_type(7);
        set_back_color(0x880800);
        set_back2_color(0x880800);
}

// 函数：获取描述
string get_desc()
{
    return "Thánh vật của sứ giả Quang Minh, dùng để ngăn cản lực lượng tà ác uy hiếp.";
}
