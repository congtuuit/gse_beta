
// 自动生成：/make/item/make33

inherit ITEM;
    inherit COMBINED;

// 函数：叠加上限
//  int get_max_combined() { return 30; }

// 函数：小吃识别
int is_snack() { return 1; }

// 函数：构造处理
void create()
{
        set_name("Đậu phộng chiên");
        set_picid_1(3324);
        set_picid_2(3324);
        set_unit("盘");
        set_value(20);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Một loại món ăn"; 
}
