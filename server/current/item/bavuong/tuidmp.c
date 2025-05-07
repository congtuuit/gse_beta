#include <ansi.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;

int get_item_value() {return 30 ;}
int get_item_value_2() {return 30 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Túi Điểm Môn Phái");
        set_picid_1(9995);
        set_picid_2(9995);
        set_value(10);
	//	set_save("knb",30);
		set_amount(1);
        
}
//int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Mở ra Điểm Môn Phái!1!"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p;
	object item1;
	
	if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return 0;
		}
	gift->add_amount(-1);
	rate = random(100);
		if( objectp( item1 = present("Điểm Môn Phái", who, 1, MAX_CARRY*4) ) && item1->get_amount() < 9999 )
		{
			item1->add_amount(rate);	
			send_user(who, "%c%s", '!', "Bạn nhận được "+rate+" Điểm Môn Phái");	
		}
		else
		{
				item1 = new("item/trangbi110/dmp");
				item1->set_amount(rate);
				p = item1->move2(who,-1);
				item1->add_to_user(p);
				send_user(who, "%c%s", '!', "Bạn nhận được "+rate+" Điểm Môn Phái");
		}
}	