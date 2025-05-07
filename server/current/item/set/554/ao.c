#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Túi Tử Kim 4*(Áo) cấp 55");
        set_picid_1(3107);
        set_picid_2(3107);
        set_value(2);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Sau khi mở ra sẽ nhận được trang bị [Áo] \ncấp 55-4* Tử Kim.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who, object gift ) 
{
	int i,p,gender,level;
	object item;
	string *nTmp,cFile,forge="";


	if (who->get_fam_name()==""||!who->get_fam_name())
	{
		send_user(who, "%c%s", '!', "Phải gia nhập Phái mới sử dụng được。");
		return 0;
	}
	gift->remove_from_user();
	destruct(gift);
	item = new(sprintf("item/%d/%d055",56,who->get_fam_type()));
	"/sys/item/equip"->init_equip_prop_3(item);
		for (i = 0; i< 4; i++)
		{
			"/sys/item/equip"->init_equip_prop_5(item);
			forge += "1";
			item->set("forge", forge);
		}
	item->set_item_color(3);
	item->set_hide(0);
	item->set_bind(1);
	p = item->move(who,-1);
	item->add_to_user(p);
	return 0;
}