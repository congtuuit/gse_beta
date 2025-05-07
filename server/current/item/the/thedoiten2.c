#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 100000 ;}
int get_item_value_2() {return 100000;}
int get_item_color() { return 3; }

// 函数：构造处理
void create()
{
        set_name("Thẻ Đổi Tên Đặc Biệt");
        set_picid_1(3812);
        set_picid_2(3812);
        set_value(30);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Sử dụng để thay đổi tên nhân vật"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object me,object gift) 
{	
    object* user, who, obj, * inv, map, item, zom, * zombie, ben;
    mapping org;
    int time, time2, i, size, level, cash, saving, size2, p, x, y, z, x1, y1, n;
    string id, order, filePath, newName;


    send_user(me, "%c%c%d%s", '?', 16, 12, "Nhập tên mới：\n" ESC"changename2 @ %s " + me->get_number() + "\n");
	return 0;
}