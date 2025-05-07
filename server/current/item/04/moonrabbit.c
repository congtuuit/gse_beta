inherit ITEM;
inherit COMBINED;   

int is_zhongqiu() { return 1; }
int get_item_color() {return 2 ;}
// 函数：构造处理
void create()
{
        set_name("Thỏ Ngọc");
        set_picid_1(3569);
        set_picid_2(3569);
        set_unit("只");
        set_value(100);
        set_amount(1);      
        set_no_give(0);//
        set_no_drop(0);//可丢弃。
        set_no_sell(0);//可Giao dịch，可存当铺，可摆摊。
          
}

// 函数：获取描述
string get_desc() 
{
	return "Những chú Thỏ thất lạc của Hằng Nga, hãy bắt càng nhiều để được càng nhiều phần thưởng.";    	
}
