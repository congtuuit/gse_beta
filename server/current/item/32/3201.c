
// 自动生成：/make/item/make32a

inherit ITEM;
    inherit COMBINED;

// 函数：叠加上限
//  int get_max_combined() { return 30; }

// 函数：原料类型
int get_stuff_type() { return 142; }

// 函数：构造处理
void create()
{
        set_name("Cơm");
        set_picid_1(3201);
        set_picid_2(3201);
        set_unit("根");
        set_value(20);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "农产品的一种"; 
}
