#include <ansi.h>
#include <effect.h>
#include <skill.h>
#include <city.h>

inherit COMBINED;
inherit ITEM;

int get_item_value() {return 999 ;}
int get_item_value_2() {return 888 ;}
int get_item_number() {return 10001021 ;}
int get_item_color() {return 1 ;}


// 函数：构造处理
void create()
{
        set_name("Định Bang Thần Châm");
        set_picid_1(3562);
        set_picid_2(3562);
        set_value(150000);
        set_amount(1);
        set_record(1);
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Sau khi sử dụng giúp tăng độ Ổn Định của bang phái thêm 1000 điểm。Tái sử dụng sau 2 giây。"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object item) 
{
	if ( !sizeof(who->get_org_name()) )
	{
		send_user(who,"%c%s",'!',"你没有帮派！");
		return 0;	
	}
	if( who->get_org_position() < 1 ) 
	{
		send_user(who,"%c%s",'!',"定帮神针只能是帮派成员使用。");
		return 0;	
	}
	send_user( who, "%c%c%w%s", ':', 3, 0,sprintf("使用该道具后帮派的安定度会增加1000点，你确定要使用吗？\n"ESC"Đồng ý.\nuse ! %x#\n"ESC"Thoát.",getoid(item))); 
	return 0;
}

string get_loop_desc(object me)
{
	return "使用后能使帮派的安定度增加1000。";
}
// 函数：使用效果
int confirm_use( object me ) { return __FILE__ ->confirm_use_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int confirm_use_callout( object who, object item )
{
	object org;

	if( who->get_org_position() < 1 ) 
	{
		send_user(who,"%c%s",'!',"Bạn không thể sử dụng。");
		return 0;	
	}
	if ( gone_time(who->get("use0026")) <= 2 )
	{
		send_user(who,"%c%s",'!',"Xin đừng dùng thường xuyên！");
		return 0;	
	}
	who->set("use0026",time());
	org = CITY_ZHOU->get_2( sprintf( "org.%s", who->get_org_name() ) );
	if ( !org )
		return 0;

	if (org->get_stable() == 10000)
	{
		send_user(who, "%c%s", '!', "Độ Ổn Định đã đến giới hạn rồi !");
		return 0;
	}

	org->add_stable(1000);
	org->save();
	return 1;
}