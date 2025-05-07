#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

int main(object me, string arg)
{
	object item;
	int num, type, cash, number,p;
	if (!arg) return 0;

	if (USER_INVENTORY_D->get_free_count(me) < 1)
	{
		notify("Hành trang không đủ 1 chỗ trống");
		return 0;
	}

	number = TASK_LEGEND_D->check_task_item_amount(me, "Tinh Thạch");
	if (number < 5) {
		return 0;
	}

	if (me->get_cash() < 100000) {
		tell_user(me, ECHO"Bạn không đủ 100.000 lượng!");
		return 0;
	}

	if (me->get_strength() < 1) {
		tell_user(me, ECHO"Bạn không đủ thể lực!");
		return 0;
	}

	num = random(4) + 2;

	item = new("item/common/stone/nangcap");
	if (!item)
		return 0;

	TASK_LEGEND_D->check_task_item1(me, "Tinh Thạch", num);
	tell_user(me, ECHO"Hợp thành biến mất %d Tinh Thạch!", num);
	me->add_cash(-100000);
	me->add_strength(-1);

	if (item && random(100) < 5) {
		p = item->move2(me);
		item->add_to_user(p);
		tell_user(me, ECHO"Hợp thành thành công!");
		send_user(me, "%c%s", ';', sprintf("Chúc mừng, bạn hợp thành nhận được "HIY"%s", item->get_name()));
	}
	else {
		tell_user(me, ECHO"Hợp thành thất bại!");
	}

	send_user(me, "%c%c%s", ':', 3, sprintf("   Hợp thành Tinh Thạch:\n Tỉ lệ thành công "HIR"5%%"NOR", ngươi muốn hợp thành "HIR"Kết Tinh Thạch"NOR" không? Dù thành công hay thất bại sẽ "HIR"tiêu hao ngẫu nhiên 2-5 viên Tinh Thạch"NOR", "HIR"100.000"NOR" lượng và "HIR"1"NOR" điểm thể lực\n"
		ESC"Tiếp tục hợp thành\ntaotinhthach 1\n"
		ESC"Thoát\nCLOSE\n"));

	return 1;
}

