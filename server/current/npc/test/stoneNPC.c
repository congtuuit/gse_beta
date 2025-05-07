#include <npc.h>
#include <item.h>
#include <ansi.h>
#include <task.h>
#include <music.h>
#include <equip.h>

#include <public.h>
#include <action.h>

inherit OFFICER;

int get_char_picid() { return 5407; }
void do_welcome(string arg);
void do_accept(string arg);

int duclo_item(object me, object who, object item);
int nang_cap_lo(object me, object who, object item, int pos);

void create()
{
	set_name("Bảo Thạch Công Tượng");
	set_real_name(HIR"Chu Đằng");

	set_2("talk", ([
		"welcome":(: do_welcome:),
			"giaotrangbi" : (: do_accept:),
	]));
	setup();

}

void do_welcome(string arg)
{
	__FILE__->do_welcome2(this_object(), arg);
}
void do_welcome2(object npc, string arg)
{
	int flag;
	object player = this_player();
	flag = to_int(arg);
	switch (flag)
	{
	case 1:
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + "Công tượng có thể giúp ngươi đục lỗ trang bị, chỉ cần bạn đưa ông ta trang bị hoặc vũ khí và thêm một ít ngân lượng là được.\n"
			ESC "ALT+G  để giao trang bị\nCLOSE\n"
			ESC "Thoát ra\nCLOSE\n");
		break;
	}
}
void do_look(object player)
{
	object npc = this_object();

	send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf(" %s :\n" + " Công tượng có thể giúp ngươi đục lỗ trang bị, chỉ cần bạn đưa ông ta trang bị hoặc vũ khí và thêm một ít ngân lượng là được.\n"
		ESC "Ta muốn đục lỗ trang bị\ntalk %x# welcome.1\n"
		ESC "Ta muốn nâng cấp lỗ khảm cho trang bị\ntalk %x# welcome.1\n"
		ESC "Rời khỏi\nCLOSE\n", npc->get_name(), getoid(npc), getoid(npc)));
}

int accept_object(object who, object item) { return __FILE__->accept_object_callout(this_object(), who, item); }

int accept_object_callout(object me, object who, object item)
{
	int random, exp, number, i, level = 1;

	me->to_front_eachother(who);
	if (!item->is_equip()) return 0;

	if (item->is_equip())
	{
		i = item->get_equip_type();
		if (i != WEAPON_TYPE && i != ARMOR_TYPE && i != HEAD_TYPE && i != BOOTS_TYPE && i != WAIST_TYPE && i != NECK_TYPE) {
			notify("Ta không nhận trang bị này");
			return -99;
		}
	}

	if (item->get_hide() > 0) {
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nHãy giám định %s trước đã!!!\n"ESC"Xác nhận",me->get_name(), item->get_name()));
		return -99;
	}

	send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nNgươi cần ta giúp gì?\n"
		ESC"Đục thêm lỗ khảm cho trang bị\ntalk %x# giaotrangbi.%x# 1\n"
		ESC"Nâng cấp lỗ khảm cho trang bị\ntalk %x# giaotrangbi.%x# 3\n"
		ESC"Huỷ bỏ", me->get_name(), getoid(me), getoid(item), getoid(me), getoid(item)));

	return -99;
}

void do_accept(string arg) { return __FILE__->do_accept_callout(this_object(), this_player(), arg); }

void do_accept_callout(object me, object who, string arg)
{
	object item;
	int number, currentHole, random, exp, total, cash, level, type, hole_number,i;
	string itemId, itemInputId, cmd="";
	string *input;

	input = explode(arg, " ");
	if (sizeof(input) < 1) {
		return 0;
	}

	itemInputId = input[0];
	type = to_int(input[1]);

	if (!objectp(item = present(itemInputId, who, 1, MAX_CARRY * 4)))
		return 0;

	switch (type)
	{
	case 1:
		number = TASK_LEGEND_D->check_task_item_amount(who, "Lạc Thanh Chi Tiễn");
		currentHole = ITEM_EQUIP_D->get_hole_amount(item);
		if (number < 1) {
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nNgươi không có đủ %d "HIR"%s \n"ESC"Thoát", me->get_name(), 1 ,"Lạc Thanh Chi Tiễn"));
			return;
		}

		cash = (currentHole + 1) * 500000;
		if (who->get_cash() < cash) {
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nNgươi không có đủ %d lượng \n"ESC"Thoát", me->get_name(), cash));
			return;
		}

		if (currentHole > 2) {
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nTrang bị này không thể đục thêm lỗ \n"ESC"Thoát", me->get_name()));
			return;
		}

		if (number < 1) {
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nBạn không có đủ %d "HIR"Lạc Thanh Chi Tiễn"NOR" ?\n"ESC"Thoát", me->get_name(), 1));
			return;
		}

		if (total < HOLE_D->get_max_exp(currentHole)) {
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nTrang bị "HIR"%s"NOR" đục lỗ sẽ tiêu hao "HIR"%d "NOR"cái "HIR"Lạc Thanh Chi Tiễn"NOR" và "HIR"%d "NOR"lượng.\n"
				ESC"Đồng ý\ntalk %x# giaotrangbi.%x# 2\n"
				ESC"Thoát", me->get_name(), item->get_name(), 1,cash, getoid(me), getoid(item)));
		}

		break;
	case 2:
		duclo_item(me, who, item);
		break;

	case 3:
		hole_number = ITEM_EQUIP_D->get_hole_amount(item);
		if (hole_number < 1) {
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s: \nTrang bị "HIR"%s chưa có lỗ khảm nào!! \n"ESC"Rời khỏi\nnCLOSE\n", me->get_name(), item->get_name()));
			return;
		}

		/*if (HOLE_D->get_pos_to_mix(item) == -1) {
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s: \nTrang bị "HIR"%s không thể nâng cấp lỗ khảm!! \n"ESC"Rời khỏi\nnCLOSE\n", me->get_name(), item->get_name()));
			return;
		}*/

		for (i = 0; i < hole_number; i++) {
			cmd += sprintf(ESC"Nâng cấp lỗ khảm %d\ntalk %x# giaotrangbi.%x# %d\n", i + 1,getoid(me), getoid(item), 101 + i);
		}

		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s: "NOR"Ngươi muốn nâng cấp lỗ khảm?\n%s"ESC"Rời khỏi\nCLOSE\n", me->get_name(), cmd));
		
		break;
	case 4:
		cash = HOLE_D->get_cash_upgrade();
		if (who->get_cash() < cash) {
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nNgươi không có đủ %d lượng \n"ESC"Thoát", me->get_name(), cash));
			return;
		}

		number = TASK_LEGEND_D->check_task_item_amount(who, "Tinh Thạch");
		if (number < 1) {
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nNgươi không có đủ %d viên "HIR"Tinh Thạch"NOR" \n"ESC"Thoát", me->get_name(), cash));
			return;
		}

		hole_number = ITEM_EQUIP_D->get_hole_amount(item);
		for (i = 0; i < hole_number; i++) {
			cmd += sprintf(ESC"Nâng cấp lỗ khảm %d\nhole %x# %d\n", i + 1, getoid(item), i);
		}

		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s: "NOR"Bạn muốn nâng cấp lỗ khảm?\n%s\n"ESC"Rời khỏi\nCLOSE\n", me->get_name(), cmd));
		break;
	case 101:
		nang_cap_lo(me, who, item, 0);
		break;
	case 102:
		nang_cap_lo(me, who, item, 1);
		break;
	case 103:
		nang_cap_lo(me, who, item, 2);
		break;
	}

	return 0;
}

int duclo_item(object me, object who, object item) {

	int number, currentHole, rate, exp, total, cash, level, type, color, itemRate;
	string itemId, keyItemSaved;
	number = TASK_LEGEND_D->check_task_item_amount(who, "Lạc Thanh Chi Tiễn");
	currentHole = ITEM_EQUIP_D->get_hole_amount(item);

	color = item->get_item_color();

	if (color != 2 && color != 3 && color != 5) {
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nTrang bị này không thể đục lỗ\n"ESC"Thoát", me->get_name()));
		return 0;
	}

	if ((color == 2 || color == 3) && currentHole > 1) {
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nTrang bị này không thể đục thêm.\n"ESC"Thoát", me->get_name()));
		return 0;
	}

	if (number < 1) {
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nVật phẩm không đủ \n"ESC"Thoát", me->get_name()));
		return 0;
	}

	cash = (currentHole + 1) * 500000;

	if (who->get_cash() < cash) {
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nNgân lượng không đủ \n"ESC"Thoát", me->get_name()));
		return 0;
	}

	if (currentHole > 2) {
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nTrang bị này không thể đục thêm lỗ \n"ESC"Thoát", me->get_name()));
		return 0;
	}

	if (number < 1) {
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nBạn không có đủ %d "HIR"Lạc Thanh Chi Tiễn"NOR" ?\n"ESC"Thoát", me->get_name(), 1));
		return 0;
	}

	TASK_LEGEND_D->check_task_item1(who, "Lạc Thanh Chi Tiễn", 1);
	who->add_cash(-cash);

	rate = 15 + random(11) - (currentHole + 1) * 5;

	if (who->get_vip() && !who->get_save_2("vip_package.trial"))
	{
		rate += 5;
	}

	itemId = item->get_user_id();
	keyItemSaved = sprintf("ratingHole.%s", itemId);
	if (who->get_save_2(keyItemSaved) < 1) {
		who->set_save_2(keyItemSaved, 1);
	}
	else {
		who->add_save_2(keyItemSaved, 1);
	}

	itemRate = 100 - who->get_save_2(keyItemSaved) + currentHole + 1;

	if (is_god(who)) {
		tell_user(who, ECHO"Tỉ lệ hiện tại %d - rateUp %d", itemRate, rate);
	}

	if (currentHole == 0) {
		if (ITEM_EQUIP_D->add_hole(item, 3) == 1) {
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nChúc mừng, trang bị "HIG"%s"NOR" hiện tại có "HIR"%d"NOR" lỗ khảm nạm \n"
				ESC"Thoát", me->get_name(), item->get_name(), ITEM_EQUIP_D->get_hole_amount(item)));
			send_user(who, "%c%d%c", 0x31, getoid(item), 0);
		}
		else {
			write_user(who, ECHO "%s đục lỗ trang bị thất bại！", item->get_name());
		}

		return;
	}

	if (who->get_save_2(keyItemSaved) < ((currentHole + 2) * 10 + (currentHole * 10))) {
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nĐục lỗ thất bại, tỉ lệ thành công tăng dần theo số lần đục.\n"
			ESC"Tiếp tục đục lỗ\ntalk %x# giaotrangbi.%x# 2\n"
			ESC"Thoát", me->get_name(), getoid(me), getoid(item)));
	} else 
	if (itemRate > rate) {
		who->add_save_2(keyItemSaved, random(7) - currentHole + 1);
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nĐục lỗ thất bại, tỉ lệ thành công tăng dần theo số lần đục.\n"
			ESC"Tiếp tục đục lỗ\ntalk %x# giaotrangbi.%x# 2\n"
			ESC"Thoát", me->get_name(), getoid(me), getoid(item)));
	}
	else {
		who->delete_save_2(keyItemSaved);
		if (ITEM_EQUIP_D->add_hole(item, 3) == 1) {
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nChúc mừng, trang bị "HIG"%s"NOR" hiện tại có "HIR"%d"NOR" lỗ khảm nạm \n"
				ESC"Thoát", me->get_name(), item->get_name(), ITEM_EQUIP_D->get_hole_amount(item)));
			send_user(who, "%c%d%c", 0x31, getoid(item), 0);
		}
		else {
			write_user(who, ECHO "%s đục lỗ trang bị thất bại！", item->get_name());
		}

	}
}

int nang_cap_lo(object me, object who, object item, int pos) {
	int number, currentHole, random, exp, total, cash, level, type, holeTotal, holeLevel;
	string saveCode;

	number = TASK_LEGEND_D->check_task_item_amount(who, "Tinh Thạch");
	holeTotal = ITEM_EQUIP_D->get_hole_amount(item);

	if (holeTotal < 1) {
		return 0;
	}
	
	currentHole = pos;

	if (number < pos + 1) {
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nNgươi không có đủ "HIR"%d Tinh Thạch"NOR" \n"ESC"Thoát", me->get_name(), pos + 1));
		return 0;
	}

	cash = (currentHole + 1) * 500000;

	if (who->get_cash() < cash) {
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nNgươi không có đủ %d lượng\n"ESC"Thoát", me->get_name(), cash));
		return 0;
	}

	if (number < currentHole + 1) {
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nBạn không có đủ %d "HIR"Tinh Thạch"NOR" ?\n"ESC"Thoát", me->get_name(), currentHole + 1));
		return 0;
	}

	TASK_LEGEND_D->check_task_item1(who, "Tinh Thạch", currentHole + 1);
	who->add_cash(-cash);

	exp = random(5) + currentHole + 1;

	saveCode = sprintf("holeExp_%d", pos);
	total = to_int(item->get(saveCode));
	item->set(saveCode, total + exp);

	holeLevel = ITEM_EQUIP_D->get_hole_level(me, item, pos);

	if (total + exp < HOLE_D->get_max_exp(holeLevel - 1)) {
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nChúc mừng trang bị "HIG"%s"NOR" lỗ khảm nạm tích lũy thêm "HIR"%d"NOR" điểm EXP, hiện có "HIR"%d/%d"NOR"\n"
			ESC"Tiếp tục\ntalk %x# giaotrangbi.%x# %d\n"
			ESC"Thoát", me->get_name(), item->get_name(), exp, total + exp, HOLE_D->get_max_exp(holeLevel - 1), getoid(me), getoid(item), 101+pos));
	}
	else {
		item->delete(saveCode);
		if (ITEM_EQUIP_D->up_hole(me,item, pos) == 1) {
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\nChúc mừng, trang bị "HIG"%s"NOR" nâng cấp lỗ khảm số "HIR"%d"NOR" thành công.\n"
				ESC"Thoát", me->get_name(), item->get_name(), pos + 1));
			send_user(who, "%c%d%c", 0x31, getoid(item), 0);

		}
		else {
			write_user(who, ECHO "%s không thể nâng cấp lỗ khảm！", item->get_name());
		}

	}

}