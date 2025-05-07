#include <ansi.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;

int is_usable() { return 1; }

int get_item_color() { return 2; }
int get_item_value() {return 100 ;}
int get_item_value_2() {return 100 ;}

void create()
{
        set_name( "Túi Tinh Thạch cấp 1" );
        set_picid_1(7106);
        set_picid_2(7106);
        set_value(50);
		set_amount(1);
}

string get_desc() 
{ 
        return "Sau khi sử dụng có thể nhận được một Tinh Thạch cấp 1";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int p;
	object item;
	if (USER_INVENTORY_D->get_free_count(who) < 1)
	{
		notify("Hành trang không đủ 1 chỗ trống");
		return 0;
	}

	if (sizeof_inventory(who, 1, MAX_CARRY) >= MAX_CARRY)
	{
		send_user(who, "%c%s", '!', "Hành trang trên người ngươi không đủ, lần sau nhận thưởng phải chú ý");
		return 0;
	}

	/*gift->remove_from_user();
	destruct(gift);*/

	gift->add_amount(-1);

	item = new(sprintf("/item/sell/%d", 9301+random(10)));
	item->set_level(1);
	p = item->move(who,-1);
	item->add_to_user(p);
	CHAT_D->sys_channel( 0, sprintf(who->get_name()+" đã mở Túi Tinh Thạch cấp 1 và nhận được %s ",item->get_name()));
	return 0;
}