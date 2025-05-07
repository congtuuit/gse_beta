#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() { return 50; }
int get_item_value_2() { return 50; }
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
	set_name("Túi Quà Cổ Mộ");
	set_picid_1(4980);
	set_picid_2(4980);
	set_value(5);
	set_amount(1);
}

int is_usable() { return 1; }
string get_desc()
{
	return "Vật phẩm rơi ra từ Cổ Mộ Thạch Dũng";
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
    object item, leader;
    string file, owner, id;
    int p, rate, i, j, size, gold, equip, total, total2;
    int z, x, y;

	if (USER_INVENTORY_D->get_free_count(who) < 1)
	{
		notify("Hành trang không đủ 1 chỗ trống");
		return 0;
	}

	rate = random(100);
    p = random(10000);

   if (p < 4600 * rate / 100)
    {
       
       file = "/item/08/0016";

        if (load_object(file))
        {
            item = new(file);
        }
    }
    else if (p < 5100 * rate / 100) 
    {
        file = "item/std/8000";
        if (load_object(file))
        {
            item = new(file);
        }
    }
    else if (p < 5280 * rate / 100)
    {
        switch (random(1))
        {
        case 0: file = "/item/91/9167";  break;
        default: file = "/item/91/9167";  break;
        }
        if (load_object(file))
        {
            item = new(file);
        }
    }
    else
    {
       file = "/item/40/40" + sprintf("%d", 11 + random(72));
        if (load_object(file))
        {
            item = new(file);
        }
    }

    gift->add_amount(-1);
    if (item)
    {
        send_user(who, "%c%s", '!', "Bạn nhận được " + item->get_name());
        p = item->move2(who);
        item->add_to_user(p);
    }
	
	return 0;
}

