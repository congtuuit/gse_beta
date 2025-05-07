
#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}

void create()
{
        set_name("Càn Khôn Hoàng Kim Dực");
        set_picid_1(3030);
        set_picid_2(3030);

        set_level(0);
		set_bind(0);
        set_value(1000);
        set_max_lasting(21599);
        set("ap+", 150);
		set("cp+", 150);
        set("hp+", 500);
		set("mp+", 500);
		set("sp+", 300);
		set("double", 500);

		set_hide(0);
        setup();

        //set_gender(1);
        set_back_type(7);
		set_back2_type(7);

		//set_back_color(0x00FFFFE0);
		set_back2_color(0x008B8B00);
		set_back_color(0x008B8B00);
}

string get_desc()
{
        return "";
}
