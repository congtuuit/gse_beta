#include <ansi.h>
#include <effect.h>
#include <skill.h>

inherit ITEM;
inherit USABLE;

// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

// 函数：构造处理
void create()
{
        set_name("Hoa Hồng Trắng");
        set_picid_1(0051);
        set_picid_2(0051);
        set_unit("枝");
        set_value(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return ("Tươi như hoa：Tinh khiết và ngây thơ\nSau khi sử dụng tăng phòng thủ ma thuật 30%，Kéo dài 60 phút\n"HIR"Yêu cầu sử dụng Nữ");
}

// 函数：使用效果
int get_use_effect( object me ) {return __FILE__ ->get_use_effect_callout(me,this_object());}

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me , object item )
{
	if(me->get_gender()==1)
	{
		send_user(me,"%c%s",';',"Xin lỗi, anh không thể dùng nó");
		return 0;
	}
	write_user(me,ECHO"Bạn nhận được "+item->get_user_id()+"Cầu nguyện tình yêu đích thực, câu thần chú phòng thủ tăng lên 30％");
	send_user( me, "%c%w%w%c", 0x81, 0426, 3600, EFFECT_GOOD );
        set_effect(me, EFFECT_ITEM_9165, 3600);
	me->set_save( "9165#", 30 );
        USER_ENERGY_D->count_pp(me);
        return 1;
}

void effect_done(object me)
{
        send_user( me, "%c%w%w%c", 0x81, 0426, 0, EFFECT_GOOD );
}

// 函数：获取描述(持续)
string get_loop_desc( object me )
{
        return "Tăng thần chú phòng thủ trong một giờ. 30％。\n";
}