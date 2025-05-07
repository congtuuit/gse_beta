#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <music.h>

inherit ITEM;
inherit USABLE;

int get_item_color() { return 3; }
int get_item_value() { return 100; }
int get_item_value_2() { return 100; }

void create()
{
	set_name("Túi vũ khí");
	set_picid_1(6814);
	set_picid_2(6814);
	set_value(500);
}

string get_desc(object me)
{
	return "Sau khi sử dụng sẽ nhận được 1 loại "HIY "Thần Khí"NOR "";
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
	int p, gender, family, type, rate, indexItem;
	object item, weapon, armor, head, neck, waist, boots;
	string cTmp, cFile;
	
	if (USER_INVENTORY_D->get_free_count(who) < 1)
	{
		send_user(who, "%c%s", '!', "Hành trang không đủ 1 chỗ.");
		return 0;
	}

	if (sizeof_inventory(who, 1, MAX_CARRY) >= MAX_CARRY)
	{
		send_user(who, "%c%s", '!', "Hành trang không đủ 1 chỗ.");
		return 0;
	}

	gift->remove_from_user();
	destruct(gift);

	rate = random(100);
	if (rate > 7) {
		indexItem = random(6) + 1;
		item = new(sprintf("item/trangbi110/thankhi/%d001", indexItem));
	}
	else {
		indexItem = random(6) + 1;
		item = new(sprintf("item/trangbi110/thankhi/%d002", indexItem));
	}
	
	if (item) {
		p = item->move2(who, -1);
		item->add_to_user(p);
		send_user(who, "%c%w", 0x0d, MUSIC_EXCHANGE);
		return 1;

	}
	else {
		return 0;
	}
	
	return 0;

}