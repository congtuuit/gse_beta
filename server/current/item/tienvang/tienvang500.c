
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 999; }
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name( "Tiền Vàng Năm Trăm Xu" );
        set_picid_1(0002);
        set_picid_2(0002);
        set_value(10);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Có Tiền Vàng bạn có thể đến Cửa Hàng Tiền Vàng đổi lấy điểm để mua vật phẩm";
}
