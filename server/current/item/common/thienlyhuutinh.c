#include <item.h>
#include <ansi.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;

int get_item_value() {return 15 ;}
int get_item_value_2() {return 15;}
int get_item_number() {return 30 ;}
int get_item_color() {return 1 ;}

// 函数：构造处理
void create()
{
        set_name( "Thiên Lý Hữu Tình" );
        set_picid_1(3857);
        set_picid_2(3857);
	    set_record(1);
        set_value(20);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Hữu duyên thiên lý năng tương ngộ, sử dụng có khả năng gọi đồng đội về bên cạnh mình, tái sử dụng sau 2 giây";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me )
{
        object map, *team, npc;
        string str1, str2;
	if( !objectp( map = get_map_object( get_z(me) ) ) )
		return 0;
	if( map->is_copy_scene() )
        {
                send_user(me, "%c%s", '!', "Trong phó bản không thể sử dụng。");
                return 0;
        }
        if( map->is_changping() )
        {
                send_user(me, "%c%s", '!', "Ở trong này không thể sử dụng。");
                return 0;
        }
	send_user( me, "%c%c%d%d%s", '?', 3, 0, me->get_save("fly"), "Ngươi muốn gọi bằng hữu？Hãy điền số ID người ngươi muốn gọi về !\n"
                        ESC "goto2byThienLy ?.%s\n" );	                        
	return 0;	                        
} 