#include <ansi.h>
#include <equip.h>
inherit ITEM;
inherit COMBINED;

int get_item_color() { return 2; }


void create()
{
        set_name("Túi Tôn Sư Trọng Đạo");
        set_picid_1(9995);
        set_picid_2(9995);
        set_amount(1);
        set_value(5000);
}

int is_usable() {return 1;}


int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc()
{ 
        return "Túi quà tôn sư trọng đạo, tham gia event có được. Bên trong có nhiều vật phẩm quí."; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,level,exp,cash;
	object item;
       	string *nTmp,tmp,cTmp,chat;
	string *nFamily = ({"Đào Hoa Nguyên", "Thục Sơn", "Cấm Vệ Quân", "Đường Môn", "Mao Sơn", "Côn Luân", "Vân Mộng Cốc", });
	int *bian=({1267,1238,1225,1201,1200});
	if(USER_INVENTORY_D->get_free_count(who) < 1 )
	{
	        send_user(who,"%c%s",';',"Hành trang của bạn đã đầy, xin vui lòng dọn sạch rồi hãy sử dụng");
    		return 0;
	}
	rate = random(36);
	if (rate<2) 
		item = new ("/item/event/huyenbangnhan");
	else if (rate<3)
		item = new ("/item/doanthach/0032");
	else if (rate<4)
		item = new ("/item/doanthach/1032");
	else if (rate<5)
		item = new ("/item/doanthach/2032");
	else if (rate<6)
		item = new ("/item/doanthach/3032");
	else if (rate<7) {
		item = new ("/item/04/0472");
		item->set_amount(1+random(10));
		}
	else if (rate<8)
		item = new ("/Pretkuzl/daocu/vsdp");
	else if (rate<9)
		item = new ("/item/event/tuihivong");
	else if (rate<10)
		item = new ("/Pretkuzl/nganphieu/nganphieu20");
	else if (rate<11)
		item = new ("/Pretkuzl/nganphieu/nganphieu50");
	else if (rate<12) 
		item = new ("/item/test/chenbac");
	else if (rate<16) {
		item = new ("/item/04/0443");
		item->set_amount(2+random(14));
		}
	else if (rate<17)
		who->add_cash(50000);
	else if (rate<18)
		who->add_cash(5000);
	else if (rate<19)
		who->add_cash(3000);
	else if (rate<20)
		who->add_cash(2000);
	else if (rate<21)
		who->add_cash(1000);
	else if (rate<22)
		who->add_cash(60000);
	else if (rate<23)
		who->add_cash(100000);
	else if (rate<24)
		who->add_cash(59000);
	else if (rate<25)
		who->add_cash(49000);
	else if (rate<26)
		who->add_cash(9999);
	else if (rate<27)
		who->add_cash(50000);
	else if (rate<28)
		who->add_exp(5200);
	else if (rate<29)
		who->add_exp(90030);
	else if (rate<30)
		who->add_exp(51000);
	else if (rate<31)
		who->add_exp(50020);
	else if (rate<32)
		who->add_exp(50000);
	else if (rate<33)
		who->add_exp(9000);
	else if (rate<34)
		who->add_exp(500);
	else if (rate<35)
		who->add_exp(50100);
	else if (rate<36)
		who->add_exp(50200);

	
	if ( item )
	{
	//	CHAT_D->sys_channel(0,sprintf(HIY"%s"HIG" mở túi hi vọng ,đạt được "HIY"%s"HIG"！",who->get_name(),item->get_name()));
		p = item->move2(who);
		item->add_to_user(p);	
	}
	else if (who->add_cash(5000))
	{
		send_user(who,"%c%s",'!',sprintf("Bạn nhận được 5000 vàng",cash));
	}		
	else if (who->add_exp(50000))
	{
		send_user(who,"%c%s",'!',sprintf("Bạn nhận được 50000 kinh nghiệm",exp));
//		CHAT_D->sys_channel(0,sprintf(HIY"%s"HIR"打开神秘法宝包，获得"HIY"经验%d"HIR"的奖励！",who->get_name(),exp));
	}
	gift->add_amount(-1);
	return 0;
}