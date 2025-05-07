#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() {return 100 ;}
int get_item_value_2() {return 100 ;}

// 函数：构造处理
void create()
{
        set_name("Túi Quà Tân Thủ");
        set_picid_1(4980);
        set_picid_2(4981);
		set_level(30);
        set_value(10000);
		        set_no_give(1);		
        set_no_sell(1);
				set_no_drop(1);

}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Túi quà Tân Thủ Cấp 30.\n Vật phẩm nhận được sau khi mở :\n_________________\n " HIC"Nhận được món phi phong hoặc cánh bất kỳ\n " HIC"Túi quà tân thủ cấp 50\n"HIC"Phiếu Thương Nhân x1 (Khóa)\n"HIC" Kinh Nghiệm : + 50000" NOR " \n_________________\n"HIG "(Lưu ý : Túi tân thủ Không thể bán, vứt bỏ hay giao dịch)"NOR "" ;
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int gender,family,type,i,k,l;
	object item,item1,item2;
	string cTmp,cFile,p,q;
	if ( TASK_LEGEND_D->check_task_item_amount(who,"Túi Quà Tân Thủ") < 1 )
			{
				notify( "Ở hành trang 1 thì tui quà mới có thể sử dụng" );
				return ;	
			}
		if ( who->get_level() < 30 )
		{
		send_user(who,"%c%s",'!',"Cấp 30 mới có thể sử dụng.");
		    		return 0;

		}
	if(USER_INVENTORY_D->get_free_count(who) < 3 )
	{
	        send_user(who,"%c%s",'!',"Không đủ 2 chỗ trống");
    		return 0;
	}
	
	TASK_LEGEND_D->check_task_item1(who,"Túi Quà Tân Thủ",1);
	cFile = "item/tuiquatanthu/lv50";
		item = new(cFile);
			i = item->move2(who,-1);
			item->add_to_user(i);
		q = "item/mtg/phieuthuongnhan";
		item2 = new(q);
			l = item2->move2(who,-1);
			item2->add_to_user(l);
			switch(random(8))	
	{
				case 1:item1 = new ("item/tuiquatanthu/lv30/1");break;
				case 2:item1 = new ("item/tuiquatanthu/lv30/2");break;
				case 3:item1 = new ("item/tuiquatanthu/lv30/3");break;
				case 4:item1 = new ("item/tuiquatanthu/lv30/4");break;
				case 5:item1 = new ("item/tuiquatanthu/lv30/8");break;
				case 6:item1 = new ("item/tuiquatanthu/lv30/3026");break;
				case 7:item1 = new ("item/tuiquatanthu/lv30/3027");break;
				default :item1 = new ("item/tuiquatanthu/lv30/a");break;
	}

	k = item1->move2(who,-1);
	item1->add_to_user(k);
}