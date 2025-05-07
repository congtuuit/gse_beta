
inherit ITEM;
inherit COMBINED;

// 函数：nh9h物品叠加上限
int get_max_combined() { return 999; }
int get_item_color() { return 1; }
// 函数：nh9h构造处理
void create()
{
        set_name( "Nhẫn Huyền Băng" );
        set_picid_1(908);
        set_picid_2(908);
        set_unit( "Nhẫn" );
        set_value(10);
        set_amount(1);
		
}

// 函数：nh9h获取描述
string get_desc() 
{ 
        return "Vật phẩm của bọn tù vượt ngục hay đeo. Có thể đổi được nhiều quà hấp dẫn.";
}
