#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}

int is_back_item () {return 1;}
int level () {return 1;}
string get_code_item() {return "xnpp";}

// 函数：构造处理
void create()
{
        set_name("Xí Nhiệt Phi Phong +1");
        set_picid_1(3021);
        set_picid_2(3021);

        set_level(1);
		set_bind(1);
        set_value(1000);
        set_max_lasting(21599);

        set("ap+", 450);
        set("pp+", 450);
        set("hp+", 1200);
		set("mp+", 1200);
		//set("sp+", 300);
		set("double", 750);

        setup();

        set_gender(2);
        set_back_type(1);
		
		set_back_color(0xaaaaa);
}

// 函数：获取描述
string get_desc()
{
        return "Áo choàng nữ anh hùng không kém đấng mày râu, mặc áo choàng này lên, sẽ hiện rõ khí chất anh hùng.";
}
