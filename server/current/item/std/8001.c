
#include <ansi.h>

inherit ITEM;
inherit USABLE;

int get_item_color() { return 1; }
// 函数：构造处理
void create()
{
        set_name( "Góc trên trái của bản đồ" );
        set_picid_1(8001);
        set_picid_2(8001);
        set_unit( "张" );
        set_value(100);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Bản đồ kho báu"; 
}

// 函数：使用效果
int get_use_effect( object me )
{
        object obj, obj2, obj3, obj4;
        int p;

        if(     !( obj2 = present("Góc phải trên của bản đồ", me, 1, MAX_CARRY) )
        ||      !( obj3 = present("Góc trái dưới của bản đồ", me, 1, MAX_CARRY) )
        ||      !( obj4 = present("Góc phải dưới của bản đồ", me, 1, MAX_CARRY) ) )
        {
                send_user(me, "%c%s", '!', "Bản đồ kho báu của ngươi chưa đủ，Không thể ghép。");
                return 0;
        }

        obj2->remove_from_user();
        destruct(obj2);
        obj3->remove_from_user();
        destruct(obj3);
        obj4->remove_from_user();
        destruct(obj4);

        obj = new( "/item/std/8005" );
        if( p = obj->move(me, -1) ) obj->add_to_user(p);
        else destruct(obj);

        if( obj ) write_user(me, ECHO "Bạn có thể ghép bốn mảnh bản đồ kho báu thành một bản đồ kho báu cũ");

        return 1;
}
