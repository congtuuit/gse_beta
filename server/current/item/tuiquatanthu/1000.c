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
		set_level(0);
        set_value(5000);
		set_no_give(1);		
        set_no_sell(1);
		set_no_drop(1);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Túi Quà hỗ trợ Tân Thủ\nSau khi sử dụng sẽ nhận được : \nTân Thủ Kĩ Năng.........\nNgoại trang (14 ngày)....\nPhục Dược và Trị Dược x60 \nNgân Lượng + 1.000.000 \nThăng lên cấp 10..... \n";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int p,gender,family,type;
	object item;
	string cTmp,cFile;
	gender = who->get_gender() == 1 ? 1 : 2;
	if(USER_INVENTORY_D->get_free_count(who) < 4 )
	{
	        send_user(who,"%c%s",'!',"Hành trang không đủ 4 chỗ.");
    		return 0;
	}

	if(who->get_fam_name() == "Đào Hoa Nguyên") family = 1;
	else if(who->get_fam_name() == "Thục Sơn") family = 2;
	else if(who->get_fam_name() == "Cấm Vệ Quân") family = 3;
	else if(who->get_fam_name() == "Đường Môn") family = 4;
	else if(who->get_fam_name() == "Mao Sơn") family = 5;
	else if(who->get_fam_name() == "Côn Luân") family = 6;
	else if(who->get_fam_name() == "Vân Mộng Cốc") family = 7;

	gift->remove_from_user();
	destruct(gift);
	
	if ( who->get_level() < 10 )
{	
	item = new(sprintf("item/tuiquatanthuhieu/TanThuKiNang"));	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/test/tuihoangkimtanthucap20"));	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/ngoai_trang/ngoaitrang%d",gender));
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new("item/tuiquatanthuhieu/0008");
	item->set_amount(60);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new("item/tuiquatanthuhieu/0010");
	item->set_amount(60);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	
//	who->set_level(who->get_level()+10);
	who->set_level(10);
	who->add_cash(1000000);	
	send_user(who,"%c%s",';',"Bạn đã sử dụng \"Túi Qùa Tân Thủ\"");	
	return 0;
}
	else
{
	item = new(sprintf("item/tuiquatanthuhieu/TanThuKiNang"));	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/test/tuihoangkimtanthucap20"));	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/ngoai_trang/ngoaitrang%d",gender));
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new("item/tuiquatanthuhieu/0008");
	item->set_amount(60);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new("item/tuiquatanthuhieu/0010");
	item->set_amount(60);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	
//	who->set_level(who->get_level()+10);
	who->add_cash(1000000);	
	send_user(who,"%c%s",';',"Bạn đã sử dụng \"Túi Qùa Tân Thủ\"");	
	return 0;
}	
}