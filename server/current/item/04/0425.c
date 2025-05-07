inherit ITEM;

void create()
{
        set_name("Đậu Socola");
        set_picid_1(9971);
        set_picid_2(9971);
        set_unit("粒");
        set_value(10);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1); 
}

// 函数：获取描述
string get_desc() 
{ 
        return "Đậu Socola tốt, bạn có thể sử dụng sô cô la";
}
