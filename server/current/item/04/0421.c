inherit ITEM;

// 函数：构造处理
void create()
{
        set_name("Hạt giống bí ẩn");
        set_picid_1(3234);
        set_picid_2(3234);
        set_unit("只");
        set_value(10);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1); 
}

// 函数：获取描述
string get_desc() 
{ 
        return "Phát ra một mùi thơm mờ nhạt，Có vẻ như để ăn。";
}
