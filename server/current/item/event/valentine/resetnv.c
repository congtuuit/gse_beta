#include <ansi.h>
#include <effect.h>
#include <skill.h>

inherit ITEM;
inherit USABLE;

int get_item_value() { return 100; }
int get_item_value_2() { return 100; }
int get_item_color() { return 2; }

int confirm_sell_item() { return 1; }

void create()
{
        set_name("Valentine Card");
        set_picid_1(3811);
        set_picid_2(3811);
        set_unit("块");
        set_value(1);
}

string get_desc() 
{ 
        return ("Thẻ reset nhiệm vụ Valentine\nLoại thẻ đặc biệt, sau khi sử dụng nhận thêm 1 lượt nhận chuỗi nhiệm vụ Valentine tại Nguyệt Lão hoặc Hồng Nương Tỉ Tỉ\n"HIR"Lưu ý: Thẻ không cộng dồn");
}

int get_use_effect( object me ) {return __FILE__ ->get_use_effect_callout(me,this_object());}

int get_use_effect_callout( object me , object item )
{

    me->set_quest("valentine.flag", 0);
    me->set_quest("valentine.type", 0);

    send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 37201, 1, OVER_BODY, PF_ONCE);
	write_user(me,ECHO"Bây giờ bạn có thể nhận chuỗi nhiệm vụ tại Nguyệt Lão hoặc Hồng Nương.");
    return 1;
}

