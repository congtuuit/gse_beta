
inherit ITEM;
inherit COMBINED;

int get_item_color() { return 2; }
// 函数：物品叠加上限
int get_max_combined() { return 10000; }

// 函数：构造处理
void create()
{
        set_name( "Phiếu Chuyển Sinh Cao Cấp lần năm" );
        set_picid_1(3856);
        set_picid_2(3856);
        set_value(10);
        set_amount(1);
		set_no_give(1);		
        set_no_sell(1);
		set_no_drop(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Có phiếu này có thể nhận phần thưởng Chuyển Sinh Cao Cấp lần 5 \n Phiếu này chỉ có khi nhận thưởng chuyển sinh lần 10.";
}
