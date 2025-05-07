
// 自动生成：/make/item/make30

inherit ITEM;
inherit COMBINED;

// 函数：获取装备颜色：灰色
int get_item_color() { return 2; }
int get_max_combined() { return 999; }

// 函数：构造处理
void create()
{
        set_name("Lông Vũ Đặc Biệt");
        set_picid_1(4001);
        set_picid_2(4001);
        set_value(100);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Loại lông nhẹ nhiều màu sắc, vật phẩm đặc biệt dùng để đổi lấy Phi Phong và Cánh."; 
}
