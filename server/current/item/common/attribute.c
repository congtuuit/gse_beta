#include <item.h>
#include <ansi.h>
#include <equip.h>

inherit ITEM;
inherit "/inh/item/diamond";

int is_diamond_2() { return 1; }

int confirm_sell_item() { return 1; }

int get_item_color() {return 3 ;}

int get_item_type() { return ITEM_TYPE_SPECIAL; }

int is_specal_move() {return 1;}

int get_forge_index() { return 7; }

int get_rate() { return 60; }

void create()
{
        set_name("Đá Tinh Luyện Phòng Cụ");
        set_real_name("ATTRIBUTE");
        set_picid_1(8921);
        set_picid_2(8921);
        set_unit("块");
        set_value(300000);
        set_level(1);
}

string get_desc() 
{
	return "Loại đá huyền bí mang sức mạnh tiềm ẩn, nghe nói có thể dùng làm nguyên liệu đúc lại phòng cụ, bổ sung thêm thuộc tính cho phòng cụ.";
}

int move_item(object me, object item, object equip)
{
	return __FILE__->move_item_callout(me, item, equip, 1 );
}

int move_item2(object me, object item, object equip)
{
	return __FILE__->move_item_callout(me, item, equip, 2 );
}

int move_item_callout(object me, object item, object equip, int type)
{
	string result, forge;
	object item2;
	int i, p, level, rate;	
	if( equip->is_equip()==0 && equip->get_real_name()!="ATTRIBUTE" )  return 0;
	if( equip->is_equip())
	{
		i=equip->get_equip_type();
		if ( i!=ARMOR_TYPE && i!=HEAD_TYPE && i!=BOOTS_TYPE)
			return 0;
	}

	if (equip->get_real_name()=="ATTRIBUTE" )
	{
		if (item->get_forge_index() < equip->get_forge_index())
		return 1;
	}

	forge = equip->get("forge");
	if (forge==0) level = 0;
	else level = strlen(forge);
	if (level < equip->get_forge_index())
	{
		notify( "Trang bị 7 sao trở lên mới có thể rèn thuộc tính." );
		return 1;
	}	

	rate = 10000;		
	for (i=4;i<=level;i++)
	{
		rate = rate * 3 / 5; 
	}

	rate = get_rate();

	if ( me->get_vip() && !me->get_save_2("vip_package.trial") )
		rate += 5;

	if (rate > 100) rate = 100;	

	if (type==1)
	{
		result = sprintf("Trang bị nếu rèn thuộc tính thất bị sẽ mất đi chỉ số hiện tại. Tỷ lệ thành công là"HIR " %d％"NOR "，\nBạn có chắc chắn muốn rèn thuộc tính cho "HIR"%s"NOR" không?\n"
			ESC "Chấp nhận\nmixAttr 0# %x# %x#\n"
			ESC "Hủy bỏ",
			rate, equip->get_name(), getoid(equip), getoid(item) );
		send_user(me, "%c%c%w%s", ':', 3, 0, result);			       			
		return 1;
	}	
	return 1;
}