
// 自动生成：/make/item/make89a

#include <item.h>

inherit ITEM;
inherit "/inh/item/diamond";

// 函数：宝石识别
int is_diamond_2() { return 1; }

int get_item_value() {return 18 ;}
int get_item_value_2() {return 18 ;}
int get_item_number() {return 10001039 ;}

// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

int get_item_color() {return 1 ;}

// 函数：宝石识别
int get_item_type() { return ITEM_TYPE_DIAMOND_3; }

// 函数：宝石属性
string get_diamond_type() { return "cp"; }

// 宝石打造的辩别标志
string get_diamond_index() {return "5";}

// 函数：构造处理
void create()
{
        set_name("Hoả Tinh Thạch");
        set_real_name("Hoả Tinh Thạch");
        set_picid_1(8984);
        set_picid_2(8984);
        set_unit("块");
        set_value(600);
        set_level(1);
}

int get_diamond_add()
{
	int value, level;
	object me = this_object();
	level = me->get_level();
	switch(level)
	{
	default:
		value = 17;
		break;	
	case 2:
		value = 22;
		break;	
	case 3:
		value = 27;
		break;	
	case 4:
		value = 32;
		break;					
	case 5:
		value = 37;
		break;
	case 6:
		value = 42;
		break;
	case 7:
		value = 47;
		break;				
	case 8:
		value = 52;
		break;				
	case 9:
		value = 57;
		break;				
	case 10:
		value = 62;
		break;	
	}
	return value;	
}

// 函数：获取描述
string get_desc() 
{ 
	object me = this_object();
	if (!clonep(me)) return "Dùng để tăng cường vật liệu đặc biệt của trang bị, thuộc tính tăng thêm chịu ảnh hưởng đặc biệt từ Tinh Thạch.\nLinh thạch cùng loại cùng cấp cũng có thể kết hợp với những tinh thạch hoặc những Tinh Thạch cùng loại cùng cấp khác để thăng cấp.\n［Tinh Luyện］ Nội Công\n［Thích hợp với những trang bị］ vũ khí, hạng liên";
        return sprintf("Dùng để tăng cường vật liệu đặc biệt của trang bị, thuộc tính tăng thêm chịu ảnh hưởng đặc biệt từ Tinh Thạch.\nLinh thạch cùng loại cùng cấp cũng có thể kết hợp với những tinh thạch hoặc những Tinh Thạch cùng loại cùng cấp khác để thăng cấp.\n［Tinh Luyện］ Nội Công %+d\n［Thích hợp với những trang bị］ vũ khí, hạng liên", me->get_diamond_add()); 
}

string get_name()
{
	object me = this_object();
	if (!clonep(me)) return "Hoả Tinh Thạch";
	return sprintf("Hoả Tinh Thạch cấp %d ", me->get_level());
}