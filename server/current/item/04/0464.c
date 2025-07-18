#include <ansi.h>
#include <equip.h>
inherit ITEM;
inherit COMBINED;

int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("重阳Túi quà lớn");
        set_picid_1(4981);
        set_picid_2(4981);
	set_amount(1);
        set_value(400);
}

int is_usable() {return 1;}

// 函数：获取描述
string get_desc() 
{ 
        return "重阳老人在重阳节赠送的贵重礼物"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash,level;
	object item;
       	string *nTmp,tmp,cTmp;
	string *nFamily = ({"Hoa đào源","蜀山","禁卫军","唐门","茅山","昆仑山","云梦泽"});
	if(USER_INVENTORY_D->get_free_count(who) < 1 )
	{
	        send_user(who,"%c%s",';',"你的道具栏空间不足够哦，请整理一下吧。");
    		return 0;
	}
	rate = random(100);
	if (rate<10) 
		item = 0;
	else if (rate<15)
	{
		item = new ("item/91/9102");//Tạo Hoá Đơn
		item->set_amount(5);
	}
	else if (rate<20)
	{
		item = new ("/item/01/0200");//红木宝箱
	}
	else if (rate<25)
	{
		item = new ("/item/01/0201");//青铜宝箱
	}
	else if (rate<30)
	{
		item = new ("/item/01/0202");//紫金宝箱
	}
	else if (rate<60)
		item = new ("item/44/4488");//宠物技能丹
	else if (rate<80)
	{
		cTmp = BOOK_FILE->get_book_file();
		item = new (cTmp);//随机门派技能进阶书
	}
	else if (rate<95)//蓝装
	{
		if ((level=who->get_level()+10)>120) level=120;
		nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,level,101+random(6));
		tmp = nTmp[random(sizeof(nTmp))];
		if ( !stringp(tmp) )
			return 0;
		item = new(tmp);
		ITEM_EQUIP_D->init_equip_prop_1(item);
	}
	else if (rate<99)//金装
	{
		level=who->get_level()+10;
		if (level>120) level=120;
		nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,level,103);
		tmp = nTmp[random(sizeof(nTmp))];
		if ( !stringp(tmp) )
			return 0;
		item = new(tmp);
		ITEM_EQUIP_D->init_equip_prop_2(item);
	}
	else if (rate<100)//随机一级法宝
		item = new(sprintf("/item/std/95%d1",random(8)+1));
	if ( item )
	{
		send_user(who,"%c%s",'!',"恭喜您！您打开重阳礼包得到了"+item->get_name());
		p = item->move2(who);
		item->add_to_user(p);	
	}
	else
	{
		who->add_cash(20000);
		send_user(who,"%c%s",'!',"恭喜您！您打开重阳礼包得到了20000金");
	}
	gift->add_amount(-1);
	return 0;
}

