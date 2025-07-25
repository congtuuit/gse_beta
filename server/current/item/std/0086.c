
#include <item.h>

inherit ITEM;
inherit USABLE;

private int Potential;                  // tiềm năng

// 函数：混沌天书
// int is_potential_item() { return 1; }

// 函数：混沌天书
int get_item_type() { return ITEM_TYPE_POTENTIAL; }

// 函数：获取tiềm năng属性
int get_potential() { return Potential; }

// 函数：Thiết lập tiềm năng属性
int set_potential( int point ) { return Potential = point; }

// 函数：构造处理
void create()
{
        set_name( "九转丹" );
        set_picid_1(9171);
        set_picid_2(9171);
        set_unit( "粒" );
        set_value(1000);
}

// 函数：获取描述
string get_desc() 
{ 
        return "能储存 1000 tiềm năng";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
        if( item->get_potential() < 1 )
        {
                if( me->get_potential() < 1000 )
                {
                        send_user(me, "%c%s", '!', "您得一次充满 1000 tiềm năng。");
                        return 0;
                }
                me->add_potential( -1000 );
                item->set_potential(1000);
                write_user(me, "你将 1000 tiềm năng充入%s。", item->get_name() );
                send_user( me, "%c%d%c", 0x31, getoid(item), 0 );

                return 0;    // 不能删除
        }
        else
        {
                me->add_potential(1000);
                return 1;
        }

        return 0;
}
