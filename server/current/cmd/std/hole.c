#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

#define EQUIP "/sys/item/equip"
#define UP_HOLE 1
#define MIX_HOLE 2

int up_hole(object me, object equip, int pos) {
	return EQUIP->up_hole(me, equip, pos);
}

int main(object me, string arg)
{
	object item;
	int num, type, cash, number;
	if (!arg) return 0;
	if (sscanf(arg, "%s %d %d", arg, num) != 2) return 1;
	if (!objectp(item = present(arg, me, 0, 0))) return 1;

	cash = HOLE_D->get_cash_upgrade();
	if (me->get_cash() < cash) {
		notify("Ngươi không có đủ ngân lượng");
		return 0;
	}

	number = TASK_LEGEND_D->check_task_item_amount(me, "Kết Tinh Thạch");
	if (number < 1) {
		notify("Ngươi không có đủ vật phẩm");
		return 0;
	}

	if (up_hole(me, item, num) == 1) {
		me->add_cash(-cash);
		TASK_LEGEND_D->check_task_item1(me, "Kết Tinh Thạch", 1);

		tell_user(me, ECHO"Nâng cấp lỗ khảm thành công!");
		send_user(me, "%c%s", ';', sprintf("Chúc mừng bạn đã nâng cấp thành công lỗ khảm số "HIG"%d cho trang bị "HIY"%s",num+1, item->get_name()));
		send_user(me, "%c%d%c", 0x31, getoid(item), 0);
	}
	else {
		tell_user(me, ECHO"Nâng cấp lỗ khảm thất bại!");
	}

	return 1;
}

