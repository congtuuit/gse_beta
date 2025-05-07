
#include <item.h>
#include <ansi.h>

inherit ITEM;
inherit USABLE;

//private int KIMNGUYENBAO; 

int get_item_value() {return 5 ;}
int get_item_value_2() {return 5 ;}
int get_item_color() { return 2; }
int get_item_type() { return ITEM_TYPE_KIMNGUYENBAO; }

string desc = "Có thể chứa đựng 50 Kim Nguyên Bảo.";
string set_desc(string x) {return desc = x};

// 函数：构造处理
void create()
{
        set_name("Bí Kíp Kim Nguyên Bảo(50)");
        set_picid_1(0003);
        set_picid_2(0003);
        set_unit("本");
        set_value(10);
		set_desc(desc);
}

// 函数：获取描述
string get_desc() 
{ 
        return desc;
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
        if( "sys/sys/test_db"->get_yuanbao(item) < 1 )
        {
                return 0;    // 不能删除
        }
        else
        {
                "sys/sys/test_db"->add_yuanbao(me,500);
				send_user(me,"%c%s",';',"Bạn nhận được "HIY " 50 Kim Nguyên Bảo");
                return 1;
        }
		
        return 0;
}
