
inherit ITEM;
inherit LEGEND_ITEM;

// 函数：构造处理
void create()
{
        set_name("Tín Phiếu");
        set_picid_1(3855);
        set_picid_2(3855);
        set_unit("封");
        set_value(10);
        set_no_give(1);
        set_no_sell(1); 
}

// 函数：获取描述
string get_desc() 
{ 
        return "百合仙子的介绍信，请把它交给新手村的神仙爷爷";
}
