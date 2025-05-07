#include <ansi.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;

int get_item_value() { return 35; }
int get_item_value_2() { return 35; }
int get_item_color() { return 1; }

void create()
{
	set_name("Quốc");
	set_picid_1(3859);
	set_picid_2(3859);
	set_value(50);
	set_amount(1);
}

string get_desc()
{
	return "Vật phẩm sự kiện, thu thập đủ bộ chữ có thể nhận được nhiều phần quà giá trị\n(Nhấn chuột phải để sử dụng)";
}

//int is_usable() { return 1; }

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object me, object gift)
{
	int khanh, chu29, p, rate, rate2;
	object item;

	khanh = TASK_LEGEND_D->check_task_item_amount(me, "Khánh");
	chu29 = TASK_LEGEND_D->check_task_item_amount(me, "2-9");

	if (!khanh) {
		notify("Bạn không đủ vật phẩm");
		return 0;
	}

	if (USER_INVENTORY_D->get_free_count(me) < 1)
	{
		notify("Hành trang không đủ 1 chỗ trống");
		return 0;
	}

	rate = random(100);

	if (khanh && chu29) {
		

		if (rate < 5)	//Bao de phu
		{
			item = new("item/sell/0034");
			if (!item)
				return 0;
		}
		else if (rate < 10)//Cao Cấp
		{
			item = new(sprintf("item/sell/2032"));
			if (!item)
				return 0;
		}
		else if (rate < 20)//Trung Cấp
		{
			item = new(sprintf("item/sell/1032"));
			if (!item)
				return 0;
		}
		else if (rate < 30)//Sơ Cấp
		{
			item = new("item/sell/0032");
			if (!item)
				return 0;
		}
		else if (rate < 45)//Túi Linh Thạch 1-3
		{
			item = new("item/TuiLinhThach/NgauNhien/1_3");

			if (!item)
				return 0;
		}
		else if (rate < 55)// Nhật Nguyệt Tinh Thần
		{
			item = new(sprintf("item/mop/9988"));
			if (!item)
				return 0;
		}
		else if (rate < 65)// Túi pháp bảo
		{
			item = new(sprintf("item/test2/TuiPhapBao"));
			if (!item)
				return 0;
		}
		else if (rate < 75)
		{
			item = new(sprintf("item/ride/newRide/hoasulenh"));
			if (!item)
				return 0;
		}
		else if (rate < 85)//Ngân lượng = level*1000
		{
			item = new(sprintf("item/common/tuinganluongrandom"));
			if (!item)
				return 0;
		}
		else if (rate < 95) {
			item = new("/item/eventquantrang/hoathach");
			if (!item)
				return 0;
		} else
		{
			item = new("item/mop/9552");

			if (!item)
				return 0;
		}

		p = item->move2(me);
		item->add_to_user(p);
		TASK_LEGEND_D->check_task_item1(me, "Khánh", 1);
		TASK_LEGEND_D->check_task_item1(me, "2-9", 1);
	}
	else if (khanh) {
		if (rate < 20)//Trung Cấp
		{
			item = new(sprintf("item/sell/1032"));
			if (!item)
				return 0;
		}
		else if (rate < 30)//Sơ Cấp
		{
			item = new("item/sell/0032");
			if (!item)
				return 0;
		}
		else if (rate < 35)//Túi Linh Thạch 1-3
		{
			item = new("item/TuiLinhThach/NgauNhien/1_3");
			if (!item)
				return 0;
		}
		else if (rate < 45)// Nhật Nguyệt Tinh Thần
		{
			item = new(sprintf("item/mop/9988"));
			if (!item)
				return 0;
		}
		else if (rate < 60)// Túi pháp bảo
		{
			item = new(sprintf("item/test2/TuiPhapBao"));
			if (!item)
				return 0;
		}
		else if (rate < 65)
		{
			item = new(sprintf("item/ride/newRide/hoasulenh"));
			if (!item)
				return 0;
		}
		else if (rate < 90)//Ngân lượng
		{
			item = new(sprintf("item/common/tuinganluongrandom"));
			if (!item)
				return 0;
		}
		else
		{
			item = new("/item/eventquantrang/hoathach");
			if (!item)
				return 0;
		}

		p = item->move2(me);
		item->add_to_user(p);
		TASK_LEGEND_D->check_task_item1(me, "Khánh", 1);
	}
	else {
		notify("Bạn không đủ vật phẩm");
		return 0;
	}

	if (item) {

		send_user(me, "%c%s", ';', "Bạn nhận được "HIY + item->get_name());
		CHAT_D->sys_channel(0, sprintf(HIY"Chúc mừng "HIG "%s"HIY" từ sự kiện Quốc Khánh 2/9 nhận được "HIR"%s", me->get_name(), item->get_name()));
		log_file("quockhanh.txt", sprintf("%s %s (%d) QUOC KHANH nhận được %s\n", short_time(), me->get_name(), me->get_number(), item->get_name()));
	}

	return 1;
}

