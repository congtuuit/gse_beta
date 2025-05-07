
#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>

string* donatePoints = ({
		"500",
		"1200",
		"2000",
		"5000",
		"5500",
		"6000",
		"6500",
		"10000",
		"15000",
		"20000",
		"25000",
		"30000",
		"35000",
		"45000",
		"50000",
	});


mapping donatePoints_Gift = ([
		"500":"/item/common/box/tukim/item/tuidacuonghoa5",
		"1200" : "/item/ride/hoasulenh",
		"2000" : "/item/common/box/tukim/item/tuidacuonghoa10",
		"5000" : "/item/common/box/tukim/item/tuidacuonghoa20",
		"5500" : "/item/mocnap/item/tui5tr",
		"6000" : "/item/common/tui500vsdp",
		"6500" : "/item/common/tui500vsdp",
		"10000" : "/item/common/box/tukim/item/ve5sao",
		"15000" : "/item/mocnap/item/tuicqdp",
		"20000" : "/item/mocnap/item/tuihonhuyenthu",
		"25000" : "/item/common/box/tukim/item/ve7sao",
		"30000" : "/item/ppvacanh/canhdo/canhdo",
		"35000" : "/item/common/box/tukim/item/ve7sao",
		"45000" : "/item/ppvacanh/canhdo/canhdo",
		"50000" : "/item/ppvacanh/canhtrangden/canhtrangden_1",
]);


string get_string_donates() {
	string result = "", name;
	object item;


	for (int i = 0; i < sizeof(donatePoints); i++) {
		item = new (donatePoints_Gift[donatePoints[i]]);
		if (item) {
			name = item->get_name();
			result += sprintf("%s điểm cống hiến - %s\n", donatePoints[i], name);
		}

	}

	result += sprintf(HIY"Tỉ lệ qui đổi:\n"HIY" 100.000 VNĐ = 600 xu = 750 Kim Bảo = 750 điểm cống hiến\n");
	return result;
}



void get_gift_bonus(object me) {
	int donate_total = 0, point, p;
	int pre_got = 0, name;
	object item;

	donate_total = to_int(me->get_save_2("donate.total"));
	pre_got = to_int(me->get_save_2("donate.got"));

	if (USER_INVENTORY_D->count_empty_carry(me) < 1)
	{
		send_user(me, "%c%s", '!', "Hành trang của bạn không đủ 1 chỗ");
		return;
	}


	if (pre_got == 0) {
		for (int i = 0; i < sizeof(donatePoints); i++) {

			point = to_int(donatePoints[i]);
			if (donate_total > 0 && point > 0 && point > pre_got && point <= donate_total) {
				item = new (donatePoints_Gift[donatePoints[i]]);
				if (item) {
					name = item->get_name();
					p = item->move(me, -1);
					item->add_to_user(p);
					me->set_save_2("donate.got", point);

					MAILBOX->sys_mail(me->get_id(), me->get_number(), sprintf("Bạn nhận được "HIR"%s .", name));

					break;
				}
			}
		}

	}
	else {
		for (int i = 0; i < sizeof(donatePoints); i++) {
			point = to_int(donatePoints[i]);
			if (donate_total > 0 && point > 0 && point > pre_got && point <= donate_total) {
				item = new (donatePoints_Gift[donatePoints[i]]);
				if (item) {
					name = item->get_name();
					p = item->move(me, -1);
					item->add_to_user(p);
					me->set_save_2("donate.got", point);

					MAILBOX->sys_mail(me->get_id(), me->get_number(), sprintf("Bạn nhận được "HIR"%s .", name));

					break;
				}

				
			}
		}

	}
}


int main(object me, string arg)
{
	string mocnap = "", pre_got = "";
	int donate_total = 0, point;
	
	if (arg == "" || arg == "0" || arg == 0) {
		mocnap = get_string_donates();
		tell_user(me, "%s", mocnap);

		point = me->get_save_2("donate.got");
		donate_total = me->get_save_2("donate.total");
		if (point == 0) {
			tell_user(me, "Cống hiến %d - Mốc đã nhận (Chưa có)", donate_total, point);

		}
		else {
			tell_user(me, "Cống hiến %d - Mốc đã nhận: %d", donate_total, point);
		}

	} else
	if (arg == "resetall") {
		point = me->get_save_2("donate.got");
		donate_total = me->get_save_2("donate.total");

		me->set_save_2("donate.total", donate_total - point);
		me->set_save_2("donate.got", 0);

		point = me->get_save_2("donate.got");
		donate_total = me->get_save_2("donate.total");

		if (point == 0) {
			tell_user(me, "Cống hiến %d - Mốc đã nhận (Chưa có)", donate_total, point);

		}
		else {
			tell_user(me, "Cống hiến %d - Mốc đã nhận: %d", donate_total, point);
		}
	}

	else if (arg == "@"){
		get_gift_bonus(me);
	}

	return 1;
}