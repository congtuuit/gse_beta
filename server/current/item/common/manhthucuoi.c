
inherit ITEM;
inherit COMBINED;

int get_max_combined() { return 500; }
int get_item_color() {return 2 ;}
void create()
{
        set_name( "Mảnh Ghép Trứng Thú Cưỡi" );
        set_picid_1(10);
        set_picid_2(10);
        set_value(10);
        set_amount(1);
}

string get_desc() 
{ 
        return "Vật phẩm có thể sử dụng để đổi lấy trứng thú cưỡi tại sứ giả.";
}
