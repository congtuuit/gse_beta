#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1500 ;}
int get_item_value_2() {return 1500 ;}

int is_back_item () {return 1;}
int level () {return 0;}
string get_code_item() {return "canhnu";}

// 函数：构造处理
void create()
{
        set_name("Thánh Linh Chi Dực·Trắng Thuần");
        set_picid_1(3028);
        set_picid_2(3028);

        set_level(1);
		set_bind(1);
        set_value(1500);
        set_max_lasting(21599);
        set("cp+", 300);
        set("dp+", 300);
        set("hp+", 800);
		set("mp+", 800);
		set("sp+", 100);
		set("double", 500);

        setup();

        set_gender(2);
        set_back_type(7);
		set_back2_type(7);
		set_back_color(0xffff);
		set_back2_color(0xffff);
}

// 函数：获取描述
string get_desc()
{
        return "Thánh vật của sứ giả Quang Minh, dùng để ngăn cản lực lượng tà ác uy hiếp.";
}
