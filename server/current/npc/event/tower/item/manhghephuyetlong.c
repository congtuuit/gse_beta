
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 100; }
int get_item_color() {return 2 ;}
// 函数：构造处理
void create()
{
    set_name( "Mảnh Ghép Huyết Long" );
    set_picid_1(6182);
    set_picid_2(6182);
    set_value(10);
    set_amount(1);
}

string get_desc() 
{ 
    return "Vật phẩm trao đổi\n Hãy đến Sứ Giả Hoạt Động để trao đổi Trang bị.";
}
