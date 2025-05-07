#include <ansi.h>

inherit ITEM;
inherit COMBINED;

int get_max_combined() { return 500; }
int get_item_color() {return 2 ;}
void create()
{
        set_name( "Mảnh Ghép Trứng Thú Cưỡi" );
        set_picid_1(3461);
        set_picid_2(3461);
        set_value(10);
        set_amount(1);
        set_save_2("cqtq.score", 30);

}

string get_desc() 
{ 
        return "Vật phẩm có thể sử dụng để đổi lấy trứng thú cưỡi tại sứ giả.";
}
