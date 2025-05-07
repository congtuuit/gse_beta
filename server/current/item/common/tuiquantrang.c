#include <ansi.h>
#include <effect.h>
#include <time.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 1; }
int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}

// 函数：构造处理
void create()
{
        set_name( "Quân Trang Lễ Bao" );
        set_picid_1(3107);
        set_picid_2(3107);
        set_value(5);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Túi quà nhận được từ Sự kiện quân trang, sau khi sử dụng nhận được vật phẩm giá trị.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who, object gift ) 
{
	int p,rate, exp, money;
	object item;
	string *nTalisman = ({"9512","9522","9532","9542","9552","9562"});
	string file;

	int iTime;
	mixed* mxTime;
	iTime = time();
	mxTime = localtime(iTime);

	rate = random(100);

	/*cql
				"04" : "/item/test2/TuiThuCuoi",
	*/
	//create item
	if (rate < 3)
	{
		item = new("/item/eventquantrang/hoathach");

	}
	else if (rate < 6)
	{
		item = new("/item/eventquantrang/manhngoc");
	}
	else if (rate < 12)
	{
		item = new("/item/eventquantrang/tuithucuoi");
		
	}
	else if (rate < 20)
	{
		item = new("/item/eventquantrang/sotriduoc");
	}
	else if (rate < 28)
	{
		item = new("/item/eventquantrang/sophucduoc");
	}
	else if (rate < 35)
	{
		item = new("/item/eventquantrang/daihuyetthach");
	}
	else if (rate < 40)
	{
		item = new("/item/eventquantrang/daiphapluc");
	}
	else if (rate < 48)
	{
		item = new("/item/diemdanh/cql2");
	}
	else if (rate < 53)
	{
		item = new("/item/eventquantrang/tuiquavosong");
	}
	else if (rate < 58)
	{
		item = new("/item/eventquantrang/tuiphapbao");
	}
	else if (rate < 68)
	{
		item = new("/item/huynhde/0032");
		item = new ("/item/common/dacuonghoa");
	}
	else if (rate < 78)
	{
		item = new("/item/huynhde/1032");
		item = new ("/item/common/dacuonghoa");
	}
	else if (rate < 83)
	{
		item = new("/item/eventquantrang/hoathach");
	}
	else if (rate < 90)
	{
		money = 300000 + who->get_level() * random(10000);
	}
	else {
		exp = 10000 * who->get_level() + random(200000);
	}

	gift->remove_from_user();
	destruct(gift);

	if (money > 0) {

		who->add_cash(money);
		tell_user(who, ECHO"Bạn sử dụng lễ bao quân trang nhận được %d ngân lượng", money);
		CHAT_D->sys_channel(0, sprintf(who->get_name() + " sử dụng Quân Trang Lễ Bao nhận được "HIR"" + money + " lượng."));

		file = sprintf("/item/quantrang%d%02d%02d.dat", mxTime[TIME_YEAR], mxTime[TIME_MON] + 1, mxTime[TIME_MDAY]);
		log_file(file, sprintf("%s %s (%d) mở quà QUÂN TRANG nhận %d money\n", short_time(), who->get_id(), who->get_number(), money));
		return 0;
	}

	if (exp > 0) {

		who->add_exp(exp);
		tell_user(who, ECHO"Bạn sử dụng lễ bao quân trang nhận được %d kinh nghiệm", exp);

		CHAT_D->sys_channel(0, sprintf(who->get_name() + " sử dụng Quân Trang Lễ Bao nhận được "HIR"" + exp + " điểm Kinh Nghiệm."));

		file = sprintf("/item/quantrang%d%02d%02d.dat", mxTime[TIME_YEAR], mxTime[TIME_MON] + 1, mxTime[TIME_MDAY]);
		log_file(file, sprintf("%s %s (%d) mở quà QUÂN TRANG nhận %d exp\n", short_time(), who->get_id(), who->get_number(), exp));
		return 0;
	}

	p = item->move(who,-1);
	item->add_to_user(p);
	CHAT_D->sys_channel( 0, sprintf(who->get_name()+" sử dụng Quân Trang Lễ Bao nhận được "HIY""+item->get_name()+""));

	file = sprintf("/item/quantrang%d%02d%02d.dat", mxTime[TIME_YEAR], mxTime[TIME_MON] + 1, mxTime[TIME_MDAY]);
	log_file(file, sprintf("%s %s (%d) mở quà QUÂN TRANG nhận %s \n", short_time(), who->get_id(), who->get_number(), item->get_name()));
	return 0;
}