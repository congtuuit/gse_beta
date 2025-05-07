
inherit ITEM;
inherit COMBINED;

// 函数：nh9h物品叠加上限
int get_max_combined() { return 9999; }
int get_item_color() { return 5; }
// 函数：nh9h构造处理
void create()
{
        set_name( "Điểm Môn Phái" );
        set_picid_1(3856);
        set_picid_2(3856);
		set_unit("金");
        set_value(1);
        set_amount(1);
		
}

// 函数：nh9h获取描述
string get_desc() 
{ 
        return "Dùng để đổi trang bị môn phái.";
}
