#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>

int main(object me, string arg)
{

	int skill = to_int(arg), p;
	string result;
	object item, item1, backItem, fashion;

	if (!objectp(item1 = present("Thuốc Chuyển Giới", me, 1, MAX_CARRY * 4)))
	{
		write_user(me, ECHO "Bạn không có Thuốc Chuyển Giới !");
		return 1;
	}

	if (me->get_level() < 20)
	{
		write_user(me, ECHO "Đẳng cấp không đủ 20, không thể chuyển giới!");
		return 1;
	}

	if (USER_INVENTORY_D->get_free_count(me) < 4)
	{
		write_user(me, ECHO "Hành trang của bạn không đủ 4 chỗ trống!");
		return 1;
	}

	if (sizeof_inventory(me, 4, MAX_CARRY) >= MAX_CARRY)
	{
		send_user(me, "%c%s", '!', "Hành trang trên người ngươi không đủ");
		return 0;
	}

	if (me->get_save_2("marry"))
	{
		write_user(me, ECHO "Bạn đã kết hôn rồi, không thể chuyển giới!");
		return 1;
	}
	if (me->get_save_2("marry_fashion"))
	{
		write_user(me, ECHO "Bạn đang mặc áo cưới, không thể chuyển giới!");
		return 1;
	}

	if (arg == 0)
	{
		result = sprintf("Bạn đang sử dụng Thuốc Chuyển Giới, xin hãy xác nhận :\n");
		result += ESC HIY"Ta thật sự muốn chuyển giới ! \ndoigt xacnhan\n";
		result += ESC "Ta vẫn còn lo lắng.\n";
		send_user(me, "%c%s", ':', result);
		return 1;
	}
	if (arg == "xacnhan")
	{
		if (me->get_gender() == 1)
		{
			me->set_gender(2);
			me->set_photo(1005);

			if (backItem = me->get_equip(BACK_TYPE)) {
				switch (backItem->get_code_item())
				{
				case "vgpp":
					if (backItem->level() > 0) {
						item = new(sprintf("item/ppvacanh/xnpp/xnpp_%d", backItem->level()));
					}
					else {
						item = new("item/ppvacanh/xnpp/xnpp");
					}
					break;
				case "xnpp":
					if (backItem->level() > 0) {
						item = new(sprintf("item/ppvacanh/vgpp/vgpp_%d", backItem->level()));
					}
					else {
						item = new("item/ppvacanh/vgpp/vgpp");
					}

					break;

				case "canhnam":
					if (backItem->level() > 0) {
						item = new(sprintf("item/ppvacanh/canhnu/canhnu_%d", backItem->level()));
					}
					else {
						item = new("item/ppvacanh/canhnu/canhnu");
					}
					break;
				case "canhnu":
					if (backItem->level() > 0) {
						item = new(sprintf("item/ppvacanh/canhnam/canhnam_%d", backItem->level()));
					}
					else {
						item = new("item/ppvacanh/canhnam/canhnam");
					}
					break;
				}

				if (item) {

					backItem->remove_from_user();
					destruct(backItem);

					item->set_hide(0);
					ITEM_EQUIP_D->init_equip_prop_3(item);
					p = item->move2(me, -1);
					item->add_to_user(p);
					me->use_equip(item);
				}
			}

			if (fashion = me->get_equip(FASHION_TYPE)) {
				me->remove_equip(FASHION_TYPE);
			}

			"/sys/user/energy"->count_all_prop(me);
			item1->add_amount(-1);
			send_user(get_scene_object_2(me, USER_TYPE), "%c%d%d%w%w%w%w%w", 0x23, getoid(me),
				me->get_armor_code(), me->get_armor_color_1(), me->get_back(), me->get_back_color(), me->get_back2(), me->get_back2_color());
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
			send_user(me, "%c%s", ';', HIY"Bạn đã Chuyển Giới thành công !!!");
		}
		else
		{
			me->set_gender(1);
			me->set_photo(5);
			
			if (backItem = me->get_equip(BACK_TYPE)) {

				switch (backItem->get_code_item())
				{
				case "vgpp":
					if (backItem->level() > 0) {
						item = new(sprintf("item/ppvacanh/xnpp/xnpp_%d", backItem->level()));
					}
					else {
						item = new("item/ppvacanh/xnpp/xnpp");
					}

					break;
				case "xnpp":
					if (backItem->level() > 0) {
						item = new(sprintf("item/ppvacanh/vgpp/vgpp_%d", backItem->level()));
					}
					else {
						item = new("item/ppvacanh/vgpp/vgpp");
					}

					break;

				case "canhnam":
					if (backItem->level() > 0) {
						item = new(sprintf("item/ppvacanh/canhnu/canhnu_%d", backItem->level()));
					}
					else {
						item = new("item/ppvacanh/canhnu/canhnu");
					}
					break;
				case "canhnu":
					if (backItem->level() > 0) {
						item = new(sprintf("item/ppvacanh/canhnam/canhnam_%d", backItem->level()));
					}
					else {
						item = new("item/ppvacanh/canhnam/canhnam");
					}
					break;
				}

				if (item) {

					backItem->remove_from_user();
					destruct(backItem);

					item->set_hide(0);
					ITEM_EQUIP_D->init_equip_prop_3(item);
					p = item->move2(me, -1);
					item->add_to_user(p);
					me->use_equip(item);
				}
			}

			if (fashion = me->get_equip(FASHION_TYPE)) {
				me->remove_equip(FASHION_TYPE);
			}

			"/sys/user/energy"->count_all_prop(me);
			item1->add_amount(-1);
			send_user(get_scene_object_2(me, USER_TYPE), "%c%d%d%w%w%w%w%w", 0x23, getoid(me),
				me->get_armor_code(), me->get_armor_color_1(), me->get_back(), me->get_back_color(), me->get_back2(), me->get_back2_color());
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
			send_user(me, "%c%s", ';', HIY"Bạn đã Chuyển Giới thành công !!!");
		}

		return 1;
	}
	return 1;
}