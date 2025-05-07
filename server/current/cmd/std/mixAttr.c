#include <item.h>
#include <ansi.h>
#include <equip.h>

int check_match(object equip, object diamond);
int mix1(object me, object* item);

void emty_attribute(object item) {
	int flag = 0;
	if (
		item->get("-*") || 
		item->get("-*%") || 
		item->get("-c*") || 
		item->get("-c*%") || 
		item->get("X@%") || 
		item->get("-@%") || 
		item->get("/%")
		) {

		flag = 1;
	}

	if (flag == 1) {
		item->delete("-*");
		item->delete("-*%");
		item->delete("-c*");
		item->delete("-c*%");
		item->delete("X@%");
		item->delete("-@%");
		item->delete("/%");
	}

}


string get_random_attribute() {
	int rate = 100;
	string result = "";
	rate = random100();

	if (rate < 14) {
		result = "-*";
	}
	else if (rate < 28) {
		result = "-*%";

	}
	else if (rate < 42) {
		result = "-c*";

	}
	else if (rate < 56) {
		result = "-c*%";
	}
	else if (rate < 70) {
		result = "X@%";

	}
	else if (rate < 84) {
		result = "-@%";
	}
	else  {
		result = "/%";
	}

	//cong
	//chinh xac
	//result = "!%";
	//result = "c!%";
	//result = "t!%";

	//result = "?%";
	//result = "c?%";

	//doc tinh
	//result = "@%";


	//THU
	//ngoai cong
	//result = "-*";
	//result = "-*%";
	//result = "-c*";
	//giam noi
	//result = "-c*%";

	//Mien dich doc
	//result = "X@%";

	//khang doc
	//result = "-@%";

	//miendich
	//result = "/%";

	//result = "??%";
	//result = "#%";

	return result;
}


int main(object me, string arg)
{
	object* item, who;
	string name, make, result, forge, index;
	int* id;
	int i, flag, level, rate, point;
	string attr = "";
	if (!arg) return 1;

	item = ({ 0, 0, });  id = ({ 0, 0, });

	if (sscanf(arg, "? %s %x# %x#", name, id[0], id[1]) == 3) flag = 1;
	else if (sscanf(arg, "%s %x# %x#", name,
		id[0], id[1]) == 3) flag = 2;
	else
	{
		notify("Bạn muốn tinh luyện đồ vật gì?");
		return 1;
	}

	if (flag == 1)
	{
		
		return 1;
	}
	else
	{
		for (i = 0; i < 2; i++)
		{
			if (!objectp(item[i] = present(sprintf("%x#", id[i]), me, 1, MAX_CARRY * 4)))    // 物品是否存在？
			{
				return 1;
			}
		}
		if (item[1]->get_item_type() != ITEM_TYPE_SPECIAL)
		{
			notify("Tinh chỉnh đá");
			return 1;
		}
		
		rate = item[1]->get_rate();

		if (me->get_vip() && !me->get_save_2("vip_package.trial"))
			rate += 5;


		if (random100() < rate)
		{
			//if (objectp(item[i] = present(sprintf("%x#", id[i]), me, 1, MAX_CARRY * 4)))    // 物品是否存在？
			{
				attr = get_random_attribute();
				point = random100();
				if (point < 20) {
					point = random(3) + 1;
				}
				else if (point < 40) {
					point = random(2) + 1;
				}
				else {
					point = 1;
				}

				emty_attribute(item[0]);

				item[0]->set(sprintf("%s", attr), point);
			}

			item[1]->remove_from_user();
			destruct(item[1]);
			send_user(me, "%c%d%c", 0x31, getoid(item[0]), 0);
			write_user(me, HIG " %s tinh luyện thành công!", item[0]->get_name());
		
		}
		else
		{
			item[1]->remove_from_user();
			destruct(item[1]);
			emty_attribute(item[0]);
			send_user(me, "%c%d%c", 0x31, getoid(item[0]), 0);
			write_user(me, HIR "%s tinh luyện không thành công！", item[0]->get_name());
		}
		return 1;
	}

	return 1;
}

int check_match(object equip, object diamond)
{
	string type = diamond->get_diamond_type();
	switch (equip->get_equip_type())
	{
	case HEAD_TYPE:
	case ARMOR_TYPE:
		if (type == "hp") return 1;
		if (type == "mp") return 1;
		if (type == "dp") return 1;
		if (type == "pp") return 1;
		break;
	case NECK_TYPE:
		if (type != "double" && type != "double2") return 1;
		break;
	case WEAPON_TYPE:
		if (type == "ap") return 1;
		if (type == "cp") return 1;
		if (type == "!%") return 1;
		if (type == "double") return 1;
		if (type == "double2") return 1;
		break;
	case WAIST_TYPE:
		if (type != "ap" && type != "cp" && type != "double" && type != "double2") return 1;
		break;
	case BOOTS_TYPE:
		if (type != "ap" && type != "cp" && type != "!%" && type != "double" && type != "double2") return 1;
		break;
	}
}
int mix1(object me, object* item)
{
	int level, rate, rate1, i, color, bind;
	string forge, result, index;
	if (!(i = item[0]->get_equip_type())
		|| (i != WEAPON_TYPE && i != ARMOR_TYPE && i != HEAD_TYPE && i != BOOTS_TYPE && i != WAIST_TYPE && i != NECK_TYPE))
		return 0;
	forge = item[0]->get("forge");
	index = item[1]->get_forge_index();
	if (index < "1" || index >"4") return 0;
	if (forge == 0) forge = "";
	level = strlen(forge);
	if (item[1]->get_level() != 1)
	{
		notify("Đá rèn cho các lớp học đầu vào công cộng trên một phân hủy.");
		return 1;
	}
	if (index == "1")
	{
		if (level > 1)
		{
			notify("Rèn đá chính chỉ rèn thiết bị trong ít hơn 2 sao.");
			return 1;
		}
	}
	if (index == "2")
	{
		if (level > 3)
		{
			notify("Trung cấp rèn đá chỉ rèn thiết bị trong vòng 4 sao.");
			return 1;
		}
	}
	bind = item[0]->get_bind();
	if (me->get_level() / 10 < level + 1)
	{
		notify("Số sao trang bị chỉ rèn được × 10 cấp.");
		return 0;
	}
	color = item[0]->get_item_color();
	rate = 10000;
	for (i = 4; i <= level; i++)
		rate = rate * 3 / 5;
	rate = 100;
	//	rate = rate / 100;
	if (me->get_vip() && !me->get_save_2("vip_package.trial"))
		rate += 5;
	rate1 = random100();
	if (is_god(me))
	{
		if (me->get("lb")) rate1 = me->get("lb");
		tell_user(me, "Bây giờ xác xuất thành công %d là %d", rate, rate1);
	}
	if (rate1 < rate)
	{
		forge += item[1]->get_forge_index();
		if (item[1]->is_record())
		{
			result = sprintf("Tinh chế thành công biến mất %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item[1]->get_name(), "/sys/item/item"->get_pawn_save_string(item[1]), 1, item[1]->get_user_id(), get_z(me), get_x(me), get_y(me));
			"/sys/user/cmd"->log_item(result);
		}

		ITEM_EQUIP_D->init_equip_prop_5(item[0]);
		if (color != 0) "/sys/sys/count"->add_equip("blue", -1);
		item[0]->set("forge", forge);
		item[1]->remove_from_user();
		destruct(item[1]);
		send_user(me, "%c%d%c", 0x31, getoid(item[0]), 0);
		level = strlen(forge);
		write_user(me, ECHO "Chúc mừng bạn thành công rèn ra %d tinh cấp trang bị!", level);
		if (level >= 9)
		{
			result = HIY + sprintf("Chúc mừng %s thành công rèn ra %d tinh cấp trang bị!", me->get_name(), level);
			CHAT_D->sys_channel(0, result);
		}
	}
	else
	{
		if (item[1]->is_record())
		{
			result = sprintf("Giả mạo không thành công biến mất %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item[1]->get_name(), "/sys/item/item"->get_pawn_save_string(item[1]), 1, item[1]->get_user_id(), get_z(me), get_x(me), get_y(me));
			"/sys/user/cmd"->log_item(result);
		}
		if (item[1]->get_forge_index() == "4")
		{
			ITEM_EQUIP_D->reduce_equip_prop_123(item[0]);
			write_user(me, ECHO "Thật không may, rèn thất bại, nhưng đừng buồn. %s của bạn vẫn còn y nguyên !", item[0]->get_name());
		}
		else
		{
			item[0]->delete("forge");
			ITEM_EQUIP_D->reset_equip_prop(item[0]);
			write_user(me, ECHO "Thật không may, rèn thất bại. %s của bạn mất hết ngôi sao", item[0]->get_name());
		}
		send_user(me, "%c%d%c", 0x31, getoid(item[0]), 0);
		item[1]->remove_from_user();
		destruct(item[1]);
	}
	return 1;


}
