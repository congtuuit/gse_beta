inherit ITEM;

// 函数：构造处理
void create()
{
        set_name("Cây trâm");
        set_picid_1(3562);
        set_picid_2(3562);
        set_unit("支");
        set_value(10);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1); 
}

// 函数：获取描述
string get_desc() 
{ 
        return "Có thể cắm vào tóc để trang trí";
}
