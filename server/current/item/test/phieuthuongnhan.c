
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 10000; }
int get_item_color() { return 2; }
int get_item_value() {return 10 ;}
int get_item_value_2() {return 10 ;}

// 函数：构造处理
void create()
{
        set_name( "Phiếu Nhiệm Vụ" );
        set_picid_1(0008);
        set_picid_2(0008);
        set_value(10);
        set_amount(1);
		
}

// 函数：获取描述
string get_desc() 
{ 
        return "Phiếu chuyên dùng để làm nhiệm vụ ở Sứ Giả Nhiệm Vụ";
}
