#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;

int get_item_value() {return 30 ;}
int get_item_value_2() {return 30 ;}
int get_item_color() { return 2; }
// 函数：构造处理
void create()
{
        set_name("Rương Vũ Khí Môn Phái");
        set_picid_1(9995);
        set_picid_2(9995);
        set_value(10);
		set_save("DMP",50);
		set_amount(1);
}
//int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Mở ra Vũ Khí Môn Phái!"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,lv,i;
	object item1;
	string phai, phai1 ="",forge="";
	
	if (who->get_fam_name()==""||!who->get_fam_name())
	{
		send_user(who, "%c%s", '!', "Hãy gia nhập môn phái");
		return 0;
	}
	
	if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return 0;
		}

	phai = who->get_fam_name();
		switch(phai)
	{
	case "Đào Hoa Nguyên":
		phai1 = "item/70/9130";
		break;
	case "Thục Sơn":
		phai1 = "item/73/9130";
		break;
	case "Cấm Vệ Quân":
		phai1 = "item/domonphai/9130";
		break;
	case "Đường Môn":
		phai1 = "item/71/9130";
		break;
	case "Mao Sơn":
		phai1 = "item/73/9130";
		break;
	case "Côn Luân":
		phai1 = "item/73/9130";
		break;
	case "Vân Mộng Cốc":
		phai1 = "item/73/9130";
		break;
	}
	gift->add_amount(-1);
	item1 = new(sprintf("%s",phai1));
	rate = 7;
	for(i=0;i<rate;i++)
	{
		"/sys/item/equip"->init_equip_prop_5(item1);
		forge += "1";
		item1->set("forge", forge);
	}
	rate = 5;
	forge = "";
	for(i=0;i<rate;i++) forge +="1";
	item1->set("sao", forge);
	"/sys/item/equip"->reset_tuchat(item1);
	"/sys/item/equip"->tuchat(item1, rate+1);
	item1->set_hide(0);
	notify(sprintf("Bạn mở được %s", item1->get_name()));
	p = item1->move2(who,-1);
	item1->add_to_user(p);
}

