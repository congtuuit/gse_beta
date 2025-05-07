
inherit ITEM;
inherit COMBINED;

int get_max_combined() { return 999; }

void create()
{
    set_name("Chiến Quốc Điểm Phiếu");
    set_picid_1(3858);
    set_picid_2(3858);
    set_value(10);
    set_amount(1);
}

string get_desc()
{
    return "Sau khi thu thập được số lượng nhất định Chiến Quốc Điểm Phiếu có thể đổi phần thưởng với Chiến Quốc Tổng Quản";
}
