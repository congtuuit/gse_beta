
#include <item.h>
inherit ITEM;

int get_product_sort() { return 5; }
int get_item_type_2() { return ITEM_TYPE_2_PRODUCT; }
int is_thanbinhpho() { return 1; }
int get_item_color() { return 3; }

int proc_level() {
    return 55;
}
string proc_code() {
    return "555";
}

void create()
{
        set_name("Bá Vương Phổ - Côn");
        set_picid_1(9807);
        set_picid_2(9807);
        set_value(200);
}

string get_desc()
{
        return "Ghi ghép lại cách chế tạo thần binh tuyệt thế";
}

string get_product()
{
    return sprintf("/item/bavuong/vukhi/%d/%s", proc_level(), proc_code());
}

int get_use_effect(object me) { return "/sys/item/product"->get_use_effect(me, this_object()); }
