
#include <equip.h>
#include <effect.h>
#include <ansi.h>
inherit TALISMAN;

// 函数：法宝识别
int get_talisman_type() { return 13; }

int get_item_color() { return 2; }

int get_gender() { return 1; }

// 函数：构造处理
void create()
{
        set_name( "Tình Bỉ Kim Giới" );
        set_picid_1(0908);
        set_picid_2(0908);
        set_unit( "个" );

        set_level(1);
        set_value(1998);
        set_max_lasting(17099);
        set("ap", 30);  
        set("cp", 30);  
        set("hp", 120);  
        set("sp", 30);  
        set_no_give(1);
//        set_no_drop(1);
        set_no_sell(1);  
	set_bind(4);
        setup();
}

// 函数：获取描述
string get_desc() 
{ 
        return sprintf("Gia tăng nhân vật thuộc tính \n"HIC" do Ngưu lang Chức nữ tặng, chiếc nhẫn có năng lực thần kỳ \n Trang bị yêu cầu :"HIR" phái Nam \n"HIB" hoạt động kỷ niệm");
}


