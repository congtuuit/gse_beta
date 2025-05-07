#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;


int is_christmas() { return 1;}

void reset()
{
        if( gone_time( get_drop_time() ) > 7200 )    // 2小时
        {
                remove_from_scene();
                destruct( this_object() );
        }
}
// 函数：构造处理
void create()
{
        set_name("Vớ dài");
        set_picid_1(9983);
        set_picid_2(9983);
        set_unit("条");
        set_value(50);
        set_amount(1);
}

string get_desc() 
{
	return "Vớ dài được sử dụng với những món quà vào dịp Noel。\nÔng già Noel món quà được mua lại。";
}

