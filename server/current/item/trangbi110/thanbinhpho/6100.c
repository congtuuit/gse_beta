
#include <item.h>
inherit ITEM;

int get_item_value() {return 3000 ;}
int get_item_value_2() {return 3000 ;}
int get_product_sort() { return 5; }

int get_item_type_2() { return ITEM_TYPE_2_PRODUCT; }
int is_thanbinhpho() { return 1; }
int get_item_color() { return 3; }

void create()
{
        set_name("Thần Binh Phổ - Hoả Long Côn");
        set_picid_1(9807);
        set_picid_2(9807);
        set_value(200);
}

string get_desc()
{
        return "Ghi ghép lại cách chế tạo thần binh tuyệt thế Hoả Long Côn.";
}

string get_product()
{
    return "/item/trangbi110/vukhi/759130";
}

int get_use_effect( object me ) { return "/sys/item/product" ->get_use_effect(me, this_object()); }
