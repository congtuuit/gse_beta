
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 500; }
int get_item_color() {return 2 ;}
// 函数：构造处理
void create()
{
        set_name( "Mảnh Ghép Thú Cưỡi" );
        set_picid_1(10);
        set_picid_2(10);
        set_value(10);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Sau khi thu thập đủ 30 mảnh ghép có thể đến \nSứ Giả Hoạt Động để hợp thành Hoả Kì Lân.";
}
