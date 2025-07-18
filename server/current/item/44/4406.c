
// 自动生成：/make/item/make31c
#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;   

// 函数：叠加上限
//  int get_max_combined() { return 30; }

// 函数：可使用物品
int get_item_type_2() { return ITEM_TYPE_2_PET; }
//宠物物品
int is_pet_item() { return 1;}
// 函数：构造处理
void create()
{
        set_name("Cao Cấp Bảo Thú Thực Phẩm");
        set_picid_1(9974);
        set_picid_2(9974);
        set_unit("个");
        set_value(400);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{
	string desc;
	return desc = "Loại thức ăn làm tăng lòng trung thành của Bảo Thú, mỗi lần ăn độ trung thành tăng 20 điểm.";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__->get_use_effect_call(me, this_object()); }

int get_use_effect_call(object me,object item)
{
	object owner;
	if ( !me->is_pet() )
		return 0;
	owner = me->get_owner();
	if ( me->get_faith() >= 10000 )
	{
		send_user(owner,"%c%s",'!',"Mức độ trung thành của Bảo Thú "+me->get_name()+" đã vượt qua giới hạn 10000");
		return 0;	
	}
	tell_user(owner,"Trung thành của "+me->get_name()+" tăng 20 điểm");
	me->add_faith(20);
	return 1;	
}