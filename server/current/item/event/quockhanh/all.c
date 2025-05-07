#include <ansi.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;

int get_item_value() { return 35; }
int get_item_value_2() { return 35; }
int get_item_color() { return 2; }

void create()
{
        set_name("Túi Quốc Khánh");
        set_picid_1(3105);
        set_picid_2(3105);
        set_value(50);
        set_amount(1);
}

string get_desc() 
{
	return "Vật phẩm sự kiện, thu thập đủ bộ chữ có thể nhận được nhiều phần quà giá trị\n(Nhấn chuột phải để sử dụng)";    	
}


int get_use_effect(object me)
{
    return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object me, object gift)
{
	int khanh, chu29, p, rate, rate2, i, j;
	object item, item1, item2;

    if (USER_INVENTORY_D->get_free_count(me) < 3)
    {
        notify("Hành trang không đủ 3 chỗ trống");
        return 0;
    }

    gift->add_amount(-1);

    item = new("item/event/quockhanh/quoc");
    item1 = new("item/event/quockhanh/khanh");
    item2 = new("item/event/quockhanh/2_9");

    p = item->move2(me);
    item->add_to_user(p);

    i = item1->move2(me);
    item1->add_to_user(i);

    j = item2->move2(me);
    item2->add_to_user(j);

	return 1;
}

