#include <ansi.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;

int get_item_value() {return 30 ;}
int get_item_value_2() {return 30 ;}
int get_item_color() { return 2; }

void create()
{
        set_name("Túi Quà Vô Song");
        set_picid_1(9995);
        set_picid_2(9995);
        set_value(3);
		set_amount(1);
        
}

string get_desc() 
{ 
        return "Túi quà do Vô Song Thành sản xuất, có thể mở ra Vô Song Điểm Phiếu hoặc một số bảo vật khác. \nNghe nói Quân Sư Vô Song Thành biết cách sử dụng"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash,sl1,sl2,sl3,sl4,sl5,sl6, rate2;
	object item,item1,item2,item3,item4,item5,item6;
	
	if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return 0;
		}
	rate = random(100);
	
	if ( rate < 5 )		//战国令
	{
		sl1 = 20;
	}
	else if ( rate < 15 )
	{
		sl1 = 15;
	}
	else if ( rate < 30 )	//百宝囊
	{
		sl2 = 1;
	}
	else if ( rate < 35 )	//百宝囊
	{
		sl4 = 1;
	}
	else if ( rate < 45 )	//百宝囊
	{
		sl1 = 10;
	}
	else if ( rate < 50 )	//百宝囊
	{
		sl3 = 1;
	}
	else if ( rate < 60 )	//百宝囊
	{
		sl5 = 1;
	}
	else if (rate < 65)	//百宝囊
	{
		sl1 = 3;
	}
	else if ( rate < 70 )	//百宝囊
	{
		sl4 = 1;
	}
	else if ( rate < 85 )	//百宝囊
	{
		sl6 = 1;
	}
	else 			//乾坤袋
	{
		sl1 = 5;
	}

	gift->add_amount(-1);
	if ( item )
	{
		//send_user(who,"%c%s",'!',"Bạn nhận được "+item->get_name());
		p = item->move2(who);
		item->add_to_user(p);
		USER_D->user_channel(sprintf("Bằng hữu "HIR "%s" NOR " mở Túi Quà Vô Song nhận được "HIR "%s "NOR " . ", who->get_name(),item->get_name() ));	
	}
	else if ( sl1 )
	{
		if( objectp( item1 = present("Vô Song Điểm Phiếu", who, 1, MAX_CARRY*4) ) && item1->get_amount() < 10000 )
		{
			item1->add_amount(sl1);	
			USER_D->user_channel(sprintf("Bằng hữu "HIR "%s" NOR " mở Túi Quà Vô Song nhận được "HIR "%s "NOR " . ", who->get_name(), item1->get_name()));
		}
		else
		{
				item1 = new("item/test/vosongdiemphieu");
				item1->set_amount(sl1);
				p = item1->move2(who,-1);
				item1->add_to_user(p);
				USER_D->user_channel(sprintf("Bằng hữu "HIR "%s" NOR " mở Túi Quà Vô Song nhận được "HIR "%s "NOR " . ", who->get_name(), item1->get_name()));
		}
	}
	else if ( sl2 )
	{
		if( objectp( item2 = present("Đại Huyết Thạch", who, 1, MAX_CARRY*4) ) && item2->get_amount() < 10000 )
		{
			item2->add_amount(sl2);	
			USER_D->user_channel(sprintf("Bằng hữu "HIR "%s" NOR " mở Túi Quà Vô Song nhận được "HIR "%s "NOR " . ", who->get_name(), item2->get_name()));

		}
		else
		{
				item2 = new("item/sell/0002");
				item2->set_amount(sl2);
				p = item2->move2(who,-1);
				item2->add_to_user(p);
				USER_D->user_channel(sprintf("Bằng hữu "HIR "%s" NOR " mở Túi Quà Vô Song nhận được "HIR "%s "NOR " . ", who->get_name(), item2->get_name()));

		}
	}
	else if ( sl3 )
	{
		if( objectp( item3 = present("Đại Pháp Lực Thạch", who, 1, MAX_CARRY*4) ) && item3->get_amount() < 10000 )
		{
			item3->add_amount(sl3);	
			USER_D->user_channel(sprintf("Bằng hữu "HIR "%s" NOR " mở Túi Quà Vô Song nhận được "HIR "%s "NOR " . ", who->get_name(), item3->get_name()));

		}
		else
		{
				item3 = new("item/sell/0004");
				item3->set_amount(sl3);
				p = item3->move2(who,-1);
				item3->add_to_user(p);
				USER_D->user_channel(sprintf("Bằng hữu "HIR "%s" NOR " mở Túi Quà Vô Song nhận được "HIR "%s "NOR " . ", who->get_name(), item3->get_name()));

		}
	}
	else if ( sl4 )
	{
		if( objectp( item4 = present("Đá Tương Uyên", who, 1, MAX_CARRY*4) ) && item4->get_amount() < 10000 )
		{
			item4->add_amount(sl4);	
			USER_D->user_channel(sprintf("Bằng hữu "HIR "%s" NOR " mở Túi Quà Vô Song nhận được "HIR "%s "NOR " . ", who->get_name(), item4->get_name()));

		}
		else
		{
				item4 = new("item/08/0016");
				item4->set_amount(sl4);
				p = item4->move2(who,-1);
				item4->add_to_user(p);
				USER_D->user_channel(sprintf("Bằng hữu "HIR "%s" NOR " mở Túi Quà Vô Song nhận được "HIR "%s "NOR " . ", who->get_name(), item4->get_name()));

		}
	}
	else if ( sl5 )
	{
		if( objectp( item5 = present("Đá Càn Khôn", who, 1, MAX_CARRY*4) ) && item5->get_amount() < 10000 )
		{
			item5->add_amount(sl5);	
			USER_D->user_channel(sprintf("Bằng hữu "HIR "%s" NOR " mở Túi Quà Vô Song nhận được "HIR "%s "NOR " . ", who->get_name(), item5->get_name()));

		}
		else
		{
				item5 = new("item/08/0017");
				item5->set_amount(sl5);
				p = item5->move2(who,-1);
				item5->add_to_user(p);
				USER_D->user_channel(sprintf("Bằng hữu "HIR "%s" NOR " mở Túi Quà Vô Song nhận được "HIR "%s "NOR " . ", who->get_name(), item5->get_name()));

		}
	}
	else if (  sl6 )
	{
		rate2 = random(100);

		if (rate2 >= 40) {
			//nu
			item = new(sprintf("item/100/11051"));
		}
		else {
			//nam
			item = new(sprintf("item/100/10051"));
		}

		p = item->move2(who);
		item->add_to_user(p);
		send_user(who,"%c%s",'!',"Bạn nhận được "+item->get_name());
		USER_D->user_channel(sprintf("Bằng hữu "HIR "%s" NOR " mở Túi Quà Vô Song nhận được "HIR "%s "NOR " . ", who->get_name(), item->get_name()));

	}

	return 0;
}

