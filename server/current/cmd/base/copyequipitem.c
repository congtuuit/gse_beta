#include <equip.h>
// 函数：命令处理
int main(object me, string arg)
{
	object item, item_dropped, item2;
	int x, y, z, p, itemid, type_item;

	if (!(item = find_any_object(arg)))
	{
		return 1;
	}

	if (item == me)
	{
		return 1;
	}

	if (item->get_equip_type() == 0)
	{
		return 1;
	}

	/*tell_user(me, "user id2: %s", item->get_user_id());
	tell_user(me, "item %s", item->get_name());*/

	type_item = item->get_equip_type();

	if (!item->is_equip() ||
		(type_item != WEAPON_TYPE && type_item != ARMOR_TYPE && type_item != HEAD_TYPE &&
			type_item != BOOTS_TYPE && type_item != WAIST_TYPE && type_item != NECK_TYPE && type_item != BACK_TYPE)) return 0;

	z = get_z(me), x = get_x(me), y = get_y(me);

	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		item_dropped = new(get_file_name(item));
		item_dropped->set_item_color(item->get_item_color());
		
		if (item->get("ap") > 0) {
			item_dropped->set("ap", item->get("ap"));
		}
		if (item->get("cp") > 0) {
			item_dropped->set("cp", item->get("cp"));
		}
		if (item->get("hp") > 0) {
			item_dropped->set("hp", item->get("hp"));
		}
		if (item->get("mp") > 0) {
			item_dropped->set("mp", item->get("mp"));
		}
		if (item->get("dp") > 0) {
			item_dropped->set("dp", item->get("dp"));
		}
		if (item->get("pp") > 0) {
			item_dropped->set("pp", item->get("pp"));
		}
		if (item->get("sp") > 0) {
			item_dropped->set("sp", item->get("sp"));
		}

		if (item->get("make")) {
			item_dropped->set("make", item->get("make"));
		}

		if (item->get("forge")) {
			item_dropped->set("forge", item->get("forge"));
			"/sys/item/equip"->init_equip_prop_5(item_dropped);
		}

		item_dropped->set_lasting(item->get_lasting());
		item_dropped->set_value(item->get_value());
		item_dropped->set_hide(0);

		item_dropped->set_bind(5);
		item_dropped->set_owner(me);

		item->remove_from_user();
		send_user(me, "%c%d", 0x2d, getoid(item));
		item_dropped->add_to_scene(z, p / 1000, p % 1000);

		tell_user(me, sprintf("Vật phẩm rơi: %s gia %d %d %d", item_dropped->get_name(), item_dropped->get_value(), item->get("ap"),item->get("cp")));
	}

	//send_user(me, "%c%d%c", 0x31, getoid(item), 0);

	return 1;
}

int drop_out(object me, object item)
{
	object item_dropped, item2;
	int x, y, z, p, itemid, type_item;

	if (item == me)
	{
		return 1;
	}

	if (item->get_equip_type() == 0)
	{
		return 1;
	}

	/*tell_user(me, "user id2: %s", item->get_user_id());
	tell_user(me, "item %s", item->get_name());*/

	type_item = item->get_equip_type();

	if (!item->is_equip() ||
		(type_item != WEAPON_TYPE && type_item != ARMOR_TYPE && type_item != HEAD_TYPE &&
			type_item != BOOTS_TYPE && type_item != WAIST_TYPE && type_item != NECK_TYPE && type_item != BACK_TYPE)) return 0;

	z = get_z(me), x = get_x(me), y = get_y(me);

	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		item_dropped = new(get_file_name(item));
		item_dropped->set_item_color(item->get_item_color());

		if (item->get("ap") > 0) {
			item_dropped->set("ap", item->get("ap"));
		}
		if (item->get("cp") > 0) {
			item_dropped->set("cp", item->get("cp"));
		}
		if (item->get("hp") > 0) {
			item_dropped->set("hp", item->get("hp"));
		}
		if (item->get("mp") > 0) {
			item_dropped->set("mp", item->get("mp"));
		}
		if (item->get("dp") > 0) {
			item_dropped->set("dp", item->get("dp"));
		}
		if (item->get("pp") > 0) {
			item_dropped->set("pp", item->get("pp"));
		}
		if (item->get("sp") > 0) {
			item_dropped->set("sp", item->get("sp"));
		}

		if (item->get("make")) {
			item_dropped->set("make", item->get("make"));
		}

		if (item->get("forge")) {
			item_dropped->set("forge", item->get("forge"));
			"/sys/item/equip"->init_equip_prop_5(item_dropped);
		}

		item_dropped->set_lasting(item->get_lasting());
		item_dropped->set_value(item->get_value());
		item_dropped->set_hide(0);

		item_dropped->set_bind(5);
		item_dropped->set_owner(me);

		item->remove_from_user();
		send_user(me, "%c%d", 0x2d, getoid(item));
		item_dropped->add_to_scene(z, p / 1000, p % 1000);

		//tell_user(me, sprintf("Vật phẩm rơi: %s gia %d %d %d", item_dropped->get_name(), item_dropped->get_value(), item->get("ap"), item->get("cp")));
	}

	//send_user(me, "%c%d%c", 0x31, getoid(item), 0);

	return 1;
}
