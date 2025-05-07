
#include <ansi.h>
#include <public.h>

inherit ITEM;
//inherit USABLE;
inherit COMBINED;

int get_item_value() { return 35; }
int get_item_value_2() { return 35; }
int get_item_color() { return 1; }

void create()
{
	set_name("Tinh Thạch");
	set_picid_1(8962);
	set_picid_2(8962);
	set_value(50);
	set_amount(1);
	set_save_2("mecung.point", 2);

}

//int is_usable() { return 1; }


string get_desc()
{
	return "Tinh thạch quý hiếm, nguyên liệu sử dụng để nâng cấp lỗ khảm cho trang bị.";
}
//
//int get_use_effect(object me)
//{
//	return __FILE__->get_use_effect_callout(me, this_object());
//}
//
//int get_use_effect_callout(object me, object gift)
//{
//	int tinhthach, chu29, p, rate, rate2;
//	object item;
//
//	tinhthach = TASK_LEGEND_D->check_task_item_amount(me, "Tinh Thạch");
//
//
//	if (tinhthach < 5) {
//		notify("Ngươi không có đủ 5 Tinh Thạch để hợp thành");
//		return 0;
//	}
//
//	if (USER_INVENTORY_D->get_free_count(me) < 1)
//	{
//		notify("Hành trang không đủ 1 chỗ trống");
//		return 0;
//	}
//
//	send_user(me, "%c%c%s", ':', 3, sprintf("   Hợp thành Tinh Thạch:\n Tỉ lệ thành công "HIR"5%%"NOR", ngươi muốn hợp thành "HIR"Kết Tinh Thạch"NOR" không? Dù thành công hay thất bại sẽ "HIR"tiêu hao ngẫu nhiên 2-5 viên Tinh Thạch"NOR", "HIR"100.000"NOR" lượng và "HIR"1"NOR" điểm thể lực\n"
//		ESC"Đồng ý, ta muốn hợp thành\ntaotinhthach 1\n"
//		ESC"Thoát\nCLOSE\n", getoid(gift)));
//
//	return 0;
//}
//
