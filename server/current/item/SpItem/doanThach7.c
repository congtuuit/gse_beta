#include <item.h>
#include <ansi.h>
#include <equip.h>

inherit ITEM;
inherit "/inh/item/diamond";

int is_diamond_2() { return 1; }

int confirm_sell_item() { return 1; }

int get_item_color() {return 3 ;}

string get_diamond_type() { return "forge"; }

string get_forge_index() {return "1";}

int is_specal_move() {return 1;}

void create()
{
        set_name("Đoạn Thạch 7 Sao");
        set_real_name("Đoạn Thạch");
        set_picid_1(4273);
        set_picid_2(4273);
        set_unit("块");
        set_value(500);
        set_level(1);
}

string get_desc() 
{
	return "Tinh luyện trang bị đạt 7 sao, có thể tăng cường thuộc tính của trang bị.\nTrang bị sẽ ngày càng cao theo số lần luyện, tỷ lệ thành công sẽ ngày càng thấp.";
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
	if( equip->is_equip()==0 && equip->get_real_name()!="Đoạn Thạch" )  return 0;
	if( equip->is_equip())
	{
		i=equip->get_equip_type();
		if ( i!=WEAPON_TYPE&&i!=ARMOR_TYPE&&i!=HEAD_TYPE&&i!=BOOTS_TYPE&&i!=WAIST_TYPE&&i!=NECK_TYPE)
			return 0;
	}
	if (equip->get_real_name()=="Đoạn Thạch" )
	{
		if (item->get_forge_index()!=equip->get_forge_index())
			notify( "Cấp bậc không phù hợp, không thể hợp thành." );
		else
			notify( "Cao Cấp Đoạn Thạch không cần hợp thành." );
		return 1;
	}
	forge = equip->get("forge");
	if (forge==0) level = 0;
	else level = strlen(forge);
	
	if (level < 6) {
		notify("Trang bị chưa thể tinh luyện lúc này.");
		return 1;
	}

	if (level > 6) {
		notify("Đá tinh luyện không thể sử dụng cho trang bị này.");
		return 1;
	}

	if (type==1)
	{
		result = sprintf("Ngươi xác định phải rèn %s không?\n"
			ESC "Chấp nhận\nren7 %x# 7\n"
			ESC "Hủy bỏ",
			equip->get_name(), getoid(equip), getoid(item) );
		send_user(me, "%c%c%w%s", ':', 3, 0, result);			       			
		return 1;
	}		
	return 1;
}