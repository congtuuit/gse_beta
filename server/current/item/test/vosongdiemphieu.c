
inherit ITEM;
inherit COMBINED;

int get_max_combined() { return 10000; }

void create()
{
        set_name( "Vô Song Điểm Phiếu" );
        set_picid_1(3856);
        set_picid_2(3856);
        set_value(10);
        set_amount(1);
}

string get_desc() 
{ 
        return "Sau khi thu thập được số lượng nhất định Vô Song Điểm Phiếu có thể đổi phần thưởng với Quân sư Vô Song Thành";
}
