#include <item.h>
#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>
#include <effect.h>
#include <music.h>

#include <time.h>
#include <city.h>
#include <public.h>


inherit OFFICER;

#define CONFIG_THUCUOI      "/custom/player/thucuoiexp"

int is_seller() { return 5555; }
int is_self_look() { return 1; }
void do_goto(string arg);
void do_welcome(string arg);
void createThanThu(object me, int idRide);

int get_char_picid()
{
	return 5109;
}

//lv3 
int HoaKiLan = 18;

//lv2
int Hoa_Dai_Hung = 29;	// Hoả Đại Hùng (Cấp 2)
int Hoa_Ho_Ly = 27;		// Hoả Hồ Ly (Cấp 2)
int Than_Voi_Dia = 31;	// Thần Voi Địa (Cấp 2)
int Thuy_Long_Quy = 33;	// Thuỷ Long Quy (Cấp 2)
int Tuan_Loc_Do = 38;	// Tuần Lộc Đỏ (Cấp 2)

//lv1
int Dai_Hung = 28;	// Đại Hùng (Cấp 1)
int Ho_Ly = 26;		// Hồ Ly (Cấp 1)
int Than_Voi = 30;	// Voi Địa (Cấp 1)
int Long_Quy = 32;	// Thuỷ Long Quy (Cấp 1)
int Tuan_Loc = 39;	// Tuần Lộc (Cấp 1)

//构造初始化
void create()
{
	set_name("Chiến Trường Ngũ Tướng Truyền Tống");
	set_city_name("Chu Quốc");

	set_2("good", ([
		"01" : "/item/NgocBoi/0007",
		"02" : "/item/NgocBoi/0008",
		"03" : "/npc/event/PhoBan/item/thuhon",
		"04" : "/npc/event/PhoBan/item/hoathach",
		//"05" : "/npc/event/PhoBan/item/nguhanhthach",

	]));

	set_2("talk",(["welcome":(:do_welcome:)]));
	setup();
}

//对话处理
void do_look(object who)
{
	string result;
	object me=this_object();

	int id = getoid(this_object());

	send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), sprintf(" %s :\n Ngũ Hổ Tướng Chiến Trận mở sau "HIR"19h "NOR"vào ngày "HIR"Thứ 6 "NOR"và "HIR"Chủ Nhật"NOR". Các vị bằng hữu muốn vào chiến trường Ngũ Tướng để xem thực lực của mình đến đâu không!\n"
		ESC HIC"Có, ta muốn tham gia thử sức\ntalk %x# welcome.100\n"
		ESC HIY"Đổi vật phẩm \nlist %x#\n"
		ESC HIC"Kiểm tra quá trình luyện hóa Thần Thú \ntalk %x# welcome.101\n"
		ESC HIC"Giúp ta nâng cấp Thần Thú \ntalk %x# welcome.102\n"
		ESC HIY"Ta muốn nhận Thần Thú \ntalk %x# welcome.103\n"
		ESC"Rời khỏi", get_name(), id, id,id,id, id));
}

void do_welcome(string arg)
{
	object me=this_object();
	__FILE__->do_welcome2(me,arg);
}


void createThanThu (object me, int idRide) {

	int i, exitsItem;
	object newItem;
	string name, result;

	//string item_lv3 = "/npc/event/PhoBan/item/ThuCuoi/lv3/003";
	string gau3 = "/npc/event/PhoBan/item/ThuCuoi/lv3/001";
	string holy3 = "/npc/event/PhoBan/item/ThuCuoi/lv3/002";
	string voi3 = "/npc/event/PhoBan/item/ThuCuoi/lv3/004";
	string rua3 = "/npc/event/PhoBan/item/ThuCuoi/lv3/005";

	string daiHung = "/npc/event/PhoBan/item/ThuCuoi/001";
	string hoaDaiHung = "/npc/event/PhoBan/item/ThuCuoi/lv2/001";

	string hoLy = "/npc/event/PhoBan/item/ThuCuoi/002";
	string hoaHoLy = "/npc/event/PhoBan/item/ThuCuoi/lv2/002";

	string voiDia = "/npc/event/PhoBan/item/ThuCuoi/004";
	string thanVoiDia = "/npc/event/PhoBan/item/ThuCuoi/lv2/004";

	string tuanLoc = "/npc/event/PhoBan/item/ThuCuoi/006";
	string tuanLocDo = "/npc/event/PhoBan/item/ThuCuoi/lv2/006";

	string thuyLongQuy1 = "/npc/event/PhoBan/item/ThuCuoi/005";
	string thuyLongQuy2 = "/npc/event/PhoBan/item/ThuCuoi/lv2/005";

	if (me->get_save(sprintf("thucuoi.%d.level", idRide)) <= 1) {
		if (me->get_save(sprintf("thucuoi.%d.exp", idRide)) < 1) {
			me->set_save(sprintf("thucuoi.%d.level", idRide), CONFIG_THUCUOI->get_level_1());
			me->set_save(sprintf("thucuoi.%d.exp", idRide), 2);
			me->set_save(sprintf("thucuoi.%d.maxexp", idRide), CONFIG_THUCUOI->get_expmax());
		}
	}

	if (me->get_save(sprintf("thucuoi.%d.level", idRide)) == 1) {
		if (me->get_save(sprintf("thucuoi.%d.maxexp", idRide)) < CONFIG_THUCUOI->get_expmax()) {
			notify("Chưa thể nâng cấp lúc này!");
			return 0;
		}
	}

	if (me->get_save(sprintf("thucuoi.%d.level", idRide)) == 2) {
		if (me->get_save(sprintf("thucuoi.%d.maxexp", idRide)) < CONFIG_THUCUOI->get_expmaxlv2()) {
			notify("Chưa thể nâng cấp lúc này!");
			return 0;
		}
	}

	switch (idRide)
	{
		case 27:
			name = "Hoả Hồ Ly (Cấp 2)";
			exitsItem = TASK_LEGEND_D->check_task_item_amount(me, name);
			
			if (exitsItem > 0) {
				TASK_LEGEND_D->check_task_item1(me, "Hoả Hồ Ly (Cấp 2)", 1);
				newItem = new(holy3);
				i = newItem->move(me, -1);
				newItem->add_to_user(i);

				me->set_save(sprintf("thucuoi.%d.level", idRide), CONFIG_THUCUOI->get_level_2());
				me->set_save(sprintf("thucuoi.%d.exp", idRide), 0);
				me->set_save(sprintf("thucuoi.%d.maxexp", idRide), CONFIG_THUCUOI->get_expmax2());

				me->set_save(sprintf("thucuoi.%d.MAX.exp", idRide), 0);
				me->set_save(sprintf("thucuoi.%d.MAX.maxexp", idRide), 1000);
				me->set_save(sprintf("thucuoi.%d.level", idRide), 3);

				result = HIY + sprintf("Chúc mừng %s ( %d ) đã nâng cấp thần thú thành công và nhận được "HIR"%s.", me->get_name(), me->get_number(), newItem->get_name());
				CHAT_D->sys_channel(0, result);
				send_user(me, "%c%s", ';', "Chúc mừng bạn đã nhận được "HIY"" + newItem->get_name());
			}
			else {
				notify("Không tìm thấy thú cưỡi nào cần để nâng cấp");
			}

			break;
		case 29:
			name = "Hoả Đại Hùng (Cấp 2)";
			exitsItem = TASK_LEGEND_D->check_task_item_amount(me, name);

			if (exitsItem > 0) {
				TASK_LEGEND_D->check_task_item1(me, "Hoả Đại Hùng (Cấp 2)", 1);
				newItem = new(gau3);
				i = newItem->move(me, -1);
				newItem->add_to_user(i);

				me->set_save(sprintf("thucuoi.%d.level", idRide), CONFIG_THUCUOI->get_level_2());
				me->set_save(sprintf("thucuoi.%d.exp", idRide), 0);
				me->set_save(sprintf("thucuoi.%d.maxexp", idRide), CONFIG_THUCUOI->get_expmaxlv2());

				me->set_save(sprintf("thucuoi.%d.MAX.exp", idRide), 0);
				me->set_save(sprintf("thucuoi.%d.MAX.maxexp", idRide), 1000);
				me->set_save(sprintf("thucuoi.%d.level", idRide), 3);

				result = HIY + sprintf("Chúc mừng %s ( %d ) đã nâng cấp thần thú thành công và nhận được "HIR"%s.", me->get_name(), me->get_number(), newItem->get_name());
				CHAT_D->sys_channel(0, result);
				send_user(me, "%c%s", ';', "Chúc mừng bạn đã nhận được "HIY"" + newItem->get_name());
			}
			else {
				notify("Không tìm thấy thú cưỡi nào cần để nâng cấp");
			}
			break;
		case 31:
			name = "Thần Voi Địa (Cấp 2)";
			exitsItem = TASK_LEGEND_D->check_task_item_amount(me, name);

			if (exitsItem > 0) {
				TASK_LEGEND_D->check_task_item1(me, "Thần Voi Địa (Cấp 2)", 1);
				newItem = new(voi3);
				i = newItem->move(me, -1);
				newItem->add_to_user(i);

				me->set_save(sprintf("thucuoi.%d.level", idRide), CONFIG_THUCUOI->get_level_2());
				me->set_save(sprintf("thucuoi.%d.exp", idRide), 0);
				me->set_save(sprintf("thucuoi.%d.maxexp", idRide), CONFIG_THUCUOI->get_expmaxlv2());

				me->set_save(sprintf("thucuoi.%d.MAX.exp", idRide), 0);
				me->set_save(sprintf("thucuoi.%d.MAX.maxexp", idRide), 1000);
				me->set_save(sprintf("thucuoi.%d.level", idRide), 3);

				result = HIY + sprintf("Chúc mừng %s ( %d ) đã nâng cấp thần thú thành công và nhận được "HIR"%s.", me->get_name(), me->get_number(), newItem->get_name());
				CHAT_D->sys_channel(0, result);
				send_user(me, "%c%s", ';', "Chúc mừng bạn đã nhận được "HIY"" + newItem->get_name());
			}
			else {
				notify("Không tìm thấy thú cưỡi nào cần để nâng cấp");
			}
			break;
		case 33:
			name = "Thuỷ Long Quy (Cấp 2)";
			exitsItem = TASK_LEGEND_D->check_task_item_amount(me, name);

			if (exitsItem > 0) {
				TASK_LEGEND_D->check_task_item1(me, "Thuỷ Long Quy (Cấp 2)", 1);
				newItem = new(rua3);
				i = newItem->move(me, -1);
				newItem->add_to_user(i);

				me->set_save(sprintf("thucuoi.%d.level", idRide), CONFIG_THUCUOI->get_level_2());
				me->set_save(sprintf("thucuoi.%d.exp", idRide), 0);
				me->set_save(sprintf("thucuoi.%d.maxexp", idRide), CONFIG_THUCUOI->get_expmaxlv2());

				me->set_save(sprintf("thucuoi.%d.MAX.exp", idRide), 0);
				me->set_save(sprintf("thucuoi.%d.MAX.maxexp", idRide), 1000);
				me->set_save(sprintf("thucuoi.%d.level", idRide), 3);

				result = HIY + sprintf("Chúc mừng %s ( %d ) đã nâng cấp thần thú thành công và nhận được "HIR"%s.", me->get_name(), me->get_number(), newItem->get_name());
				CHAT_D->sys_channel(0, result);
				send_user(me, "%c%s", ';', "Chúc mừng bạn đã nhận được "HIY"" + newItem->get_name());
			}
			else {
				notify("Không tìm thấy thú cưỡi nào cần để nâng cấp");
			}
			break;
		/*case 38:
			name = "Tuần Lộc Đỏ (Cấp 2)";
			exitsItem = TASK_LEGEND_D->check_task_item_amount(me, name);

			if (exitsItem > 0) {
				TASK_LEGEND_D->check_task_item1(me, "Tuần Lộc Đỏ (Cấp 2)", 1);
				newItem = new(item_lv3);
				i = newItem->move(me, -1);
				newItem->add_to_user(i);

				me->set_save(sprintf("thucuoi.%d.level", idRide), CONFIG_THUCUOI->get_level_2());
				me->set_save(sprintf("thucuoi.%d.exp", idRide), 0);
				me->set_save(sprintf("thucuoi.%d.maxexp", idRide), CONFIG_THUCUOI->get_expmax2());

				me->set_save("thucuoi.MAX.exp", 0);
				me->set_save("thucuoi.MAX.maxexp", 1000);
				me->set_save("thucuoi.MAX.level", 3);

				result = HIY + sprintf("Chúc mừng %s ( %d ) đã nâng cấp thần thú thành công và nhận được "HIR"%s.", me->get_name(), me->get_number(), newItem->get_name());
				CHAT_D->sys_channel(0, result);
				send_user(me, "%c%s", ';', "Chúc mừng bạn đã nhận được "HIY"" + newItem->get_name());
			}
			else {
				notify("Không tìm thấy thú cưỡi nào cần để nâng cấp");
			}
			break;*/


		case 28:
			name = "Đại Hùng (Cấp 1)";
			exitsItem = TASK_LEGEND_D->check_task_item_amount(me, name);

			if (exitsItem > 0) {
				TASK_LEGEND_D->check_task_item1(me, "Đại Hùng (Cấp 1)", 1);
				newItem = new(hoaDaiHung);
				i = newItem->move(me, -1);
				newItem->add_to_user(i);

				me->set_save(sprintf("thucuoi.%d.level", idRide), CONFIG_THUCUOI->get_level_1());
				me->set_save(sprintf("thucuoi.%d.exp", idRide), 0);
				me->set_save(sprintf("thucuoi.%d.maxexp", idRide), CONFIG_THUCUOI->get_expmax());

				me->set_save(sprintf("thucuoi.%d.level", newItem->get_ride_id()), newItem->get_level());
				me->set_save(sprintf("thucuoi.%d.exp", newItem->get_ride_id()), 0);
				me->set_save(sprintf("thucuoi.%d.maxexp", newItem->get_ride_id()), CONFIG_THUCUOI->get_expmax2());

				result = HIY + sprintf("Chúc mừng %s ( %d ) đã nâng cấp thần thú thành công và nhận được "HIR"%s.", me->get_name(), me->get_number(), newItem->get_name());
				CHAT_D->sys_channel(0, result);
				send_user(me, "%c%s", ';', "Chúc mừng bạn đã nhận được "HIY"" + newItem->get_name());
			}
			else {
				notify("Không tìm thấy thú cưỡi nào cần để nâng cấp");
			}
			break;
		case 26:
			name = "Hồ Ly (Cấp 1)";
			exitsItem = TASK_LEGEND_D->check_task_item_amount(me, name);

			if (exitsItem > 0) {
				TASK_LEGEND_D->check_task_item1(me, "Hồ Ly (Cấp 1)", 1);
				newItem = new(hoaHoLy);
				i = newItem->move(me, -1);
				newItem->add_to_user(i);

				me->set_save(sprintf("thucuoi.%d.level", idRide), CONFIG_THUCUOI->get_level_1());
				me->set_save(sprintf("thucuoi.%d.exp", idRide), 0);
				me->set_save(sprintf("thucuoi.%d.maxexp", idRide), CONFIG_THUCUOI->get_expmax());

				me->set_save(sprintf("thucuoi.%d.level", newItem->get_ride_id()), newItem->get_level());
				me->set_save(sprintf("thucuoi.%d.exp", newItem->get_ride_id()), 0);
				me->set_save(sprintf("thucuoi.%d.maxexp", newItem->get_ride_id()), CONFIG_THUCUOI->get_expmax2());

				result = HIY + sprintf("Chúc mừng %s ( %d ) đã nâng cấp thần thú thành công và nhận được "HIR"%s.", me->get_name(), me->get_number(), newItem->get_name());
				CHAT_D->sys_channel(0, result);
				send_user(me, "%c%s", ';', "Chúc mừng bạn đã nhận được "HIY"" + newItem->get_name());
			}
			else {
				notify("Không tìm thấy thú cưỡi nào cần để nâng cấp");
			}
			break;
		case 30:
			name = "Voi Địa (Cấp 1)";
			exitsItem = TASK_LEGEND_D->check_task_item_amount(me, name);

			if (exitsItem > 0) {
				TASK_LEGEND_D->check_task_item1(me, "Voi Địa (Cấp 1)", 1);
				newItem = new(thanVoiDia);
				i = newItem->move(me, -1);
				newItem->add_to_user(i);

				me->set_save(sprintf("thucuoi.%d.level", idRide), CONFIG_THUCUOI->get_level_1());
				me->set_save(sprintf("thucuoi.%d.exp", idRide), 0);
				me->set_save(sprintf("thucuoi.%d.maxexp", idRide), CONFIG_THUCUOI->get_expmax());

				me->set_save(sprintf("thucuoi.%d.level", newItem->get_ride_id()), newItem->get_level());
				me->set_save(sprintf("thucuoi.%d.exp", newItem->get_ride_id()), 0);
				me->set_save(sprintf("thucuoi.%d.maxexp", newItem->get_ride_id()), CONFIG_THUCUOI->get_expmax2());

				result = HIY + sprintf("Chúc mừng %s ( %d ) đã nâng cấp thần thú thành công và nhận được "HIR"%s.", me->get_name(), me->get_number(), newItem->get_name());
				CHAT_D->sys_channel(0, result);
				send_user(me, "%c%s", ';', "Chúc mừng bạn đã nhận được "HIY"" + newItem->get_name());
			}
			else {
				notify("Không tìm thấy thú cưỡi nào cần để nâng cấp");
			}

			break;
		case 32:
			name = "Thuỷ Long Quy (Cấp 1)";
			exitsItem = TASK_LEGEND_D->check_task_item_amount(me, name);

			if (exitsItem > 0) {
				TASK_LEGEND_D->check_task_item1(me, "Thuỷ Long Quy (Cấp 1)", 1);
				newItem = new(thuyLongQuy2);
				i = newItem->move(me, -1);
				newItem->add_to_user(i);

				me->set_save(sprintf("thucuoi.%d.level", idRide), CONFIG_THUCUOI->get_level_1());
				me->set_save(sprintf("thucuoi.%d.exp", idRide), 0);
				me->set_save(sprintf("thucuoi.%d.maxexp", idRide), CONFIG_THUCUOI->get_expmax());

				me->set_save(sprintf("thucuoi.%d.level", newItem->get_ride_id()), newItem->get_level());
				me->set_save(sprintf("thucuoi.%d.exp", newItem->get_ride_id()), 0);
				me->set_save(sprintf("thucuoi.%d.maxexp", newItem->get_ride_id()), CONFIG_THUCUOI->get_expmax2());

				result = HIY + sprintf("Chúc mừng %s ( %d ) đã nâng cấp thần thú thành công và nhận được "HIR"%s.", me->get_name(), me->get_number(), newItem->get_name());
				CHAT_D->sys_channel(0, result);
				send_user(me, "%c%s", ';', "Chúc mừng bạn đã nhận được "HIY"" + newItem->get_name());
			}
			else {
				notify("Không tìm thấy thú cưỡi nào cần để nâng cấp");
			}

			break;
		/*case 39:
			name = "Tuần Lộc (Cấp 1)";
			exitsItem = TASK_LEGEND_D->check_task_item_amount(me, name);

			if (exitsItem > 0) {
				TASK_LEGEND_D->check_task_item1(me, "Tuần Lộc (Cấp 1)", 1);
				newItem = new(tuanLocDo);
				i = newItem->move(me, -1);
				newItem->add_to_user(i);

				me->set_save(sprintf("thucuoi.%d.level", idRide), CONFIG_THUCUOI->get_level_1());
				me->set_save(sprintf("thucuoi.%d.exp", idRide), 0);
				me->set_save(sprintf("thucuoi.%d.maxexp", idRide), CONFIG_THUCUOI->get_expmax());

				me->set_save(sprintf("thucuoi.%d.level", newItem->get_ride_id()), newItem->get_level());
				me->set_save(sprintf("thucuoi.%d.exp", newItem->get_ride_id()), 0);
				me->set_save(sprintf("thucuoi.%d.maxexp", newItem->get_ride_id()), newItem->get_maxexp());

				result = HIY + sprintf("Chúc mừng %s ( %d ) đã nâng cấp thần thú thành công và nhận được "HIR"%s.", me->get_name(), me->get_number(), newItem->get_name());
				CHAT_D->sys_channel(0, result);
				send_user(me, "%c%s", ';', "Chúc mừng bạn đã nhận được "HIY"" + newItem->get_name());
			}
			else {
				notify("Không tìm thấy thú cưỡi nào cần để nâng cấp");
			}
			break;*/
		default:
			notify("Nâng cấp thất bại");
			return;
			break;
	}

	if (me->get_ride())
	{
		me->set_ride(0);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
		return 0;
	}
}

void do_welcome2(object me,string arg)
{
	int flag, p, iTime,i;
	int z, x, y;
	object who, item;
	string result;
	mixed* mixTime;
	int level, maxexp, exp, thucuoi;
	int kim, moc, thuy, hoa, tho, thuhon;

	who = this_player();
	flag = to_int(arg);
	who->set_time("talk", 0);

	switch (flag)
	{
		case 100:
			iTime = time();
			mixTime = localtime(iTime);

			mixTime[TIME_WDAY];

			if (mixTime[TIME_WDAY] != 0 &&
				mixTime[TIME_WDAY] != 5) {
				send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), sprintf(" %s :\n Ta chưa nghe thấy có chiến trường nào đang diễn ra, quay lại sao nhé!!\n"
					ESC"Thoát", get_name()));
				return;
			}

			if (who->get_save_2("NguHoTuong.Activity") == mixTime[TIME_WDAY]) {
				if (who->get_save_2("NguHoTuong.countCome") > 1) {
					send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), sprintf(" %s :\n Hôm nay bạn đã hết lượt tham gia chiến trường rồi, ngươi hãy từ đi tìm đường nha\n"
						ESC"Thoát", get_name()));
					return;
				}

				send_user(who, "%c%c%w%s", 0x5a, 0, 2, "Đang di chuyển……");
				who->set_2("travel.z", 375);
				who->set_2("travel.p", 088048);
				who->set_2("travel.money", 0);
				set_effect(who, EFFECT_TRAVEL, 2);
				
				who->add_save_2("NguHoTuong.countCome", 1);
				who->add_save_2("NguHoTuong.countGo", 1);
			}
			else {
				who->set_save_2("NguHoTuong.Activity", mixTime[TIME_WDAY]);

				send_user(who, "%c%c%w%s", 0x5a, 0, 2, "Đang di chuyển……");
				who->set_2("travel.z", 375);
				who->set_2("travel.p", 088048);
				who->set_2("travel.money", 0);
				set_effect(who, EFFECT_TRAVEL, 2);

				who->set_save_2("NguHoTuong.countCome", 1);
				who->set_save_2("NguHoTuong.countGo", 1);
			}

		break;

		case 101:
			thucuoi = who->get_ride();
			if (thucuoi == Hoa_Ho_Ly
				|| thucuoi == Hoa_Dai_Hung
				|| thucuoi == Than_Voi_Dia
				|| thucuoi == Thuy_Long_Quy
				|| thucuoi == Tuan_Loc_Do
				|| thucuoi == Dai_Hung
				|| thucuoi == Ho_Ly
				|| thucuoi == Than_Voi
				|| thucuoi == Long_Quy
				|| thucuoi == Tuan_Loc) {

				if (who->get_save(sprintf("thucuoi.%d.level", thucuoi)) <= 0) {
					who->set_save(sprintf("thucuoi.%d.level", thucuoi), CONFIG_THUCUOI->get_level_1());
					who->set_save(sprintf("thucuoi.%d.exp", thucuoi), 0);
					who->set_save(sprintf("thucuoi.%d.maxexp", thucuoi), CONFIG_THUCUOI->get_expmax());
				}

				exp = who->get_save(sprintf("thucuoi.%d.exp", thucuoi));
				maxexp = who->get_save(sprintf("thucuoi.%d.maxexp", thucuoi));
				level = who->get_save(sprintf("thucuoi.%d.level", thucuoi));

				if (level == 1 || level == 2) {
					
					send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), sprintf(" %s :\n Thần Thú của ngươi hiện tại đạt Cấp độ: %d (%d / %d)\n"
						ESC"Thoát", get_name(), level, exp, maxexp));

					return;
				}
				else {
					send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ta không thể kiểm tra được Thần Thú này của ngươi, xin lỗi nhé.\n"
						ESC"Rời khỏi", me->get_name()));

					return;
				}

			}
			else {
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ta không thấy Thần Thú nào ở đây cả.\n"
					ESC"Rời khỏi", me->get_name()));
				return;
			}
		break;

		case 102:
			thucuoi = who->get_ride();
			if (thucuoi == Hoa_Ho_Ly
				|| thucuoi == Hoa_Dai_Hung
				|| thucuoi == Than_Voi_Dia
				|| thucuoi == Thuy_Long_Quy
				|| thucuoi == Tuan_Loc_Do
				|| thucuoi == Dai_Hung
				|| thucuoi == Ho_Ly
				|| thucuoi == Than_Voi
				|| thucuoi == Long_Quy
				|| thucuoi == Tuan_Loc) {


				if (who->get_save(sprintf("thucuoi.%d.level", thucuoi)) <= 0) {
					who->set_save(sprintf("thucuoi.%d.level", thucuoi), CONFIG_THUCUOI->get_level_1());
					who->set_save(sprintf("thucuoi.%d.exp", thucuoi), 0);
					who->set_save(sprintf("thucuoi.%d.maxexp", thucuoi), CONFIG_THUCUOI->get_expmax());
				}

				exp = who->get_save(sprintf("thucuoi.%d.exp", thucuoi));
				maxexp = who->get_save(sprintf("thucuoi.%d.maxexp", thucuoi));
				level = who->get_save(sprintf("thucuoi.%d.level", thucuoi));
				if (exp >= maxexp && level < 3) {
					createThanThu(who, thucuoi);
				}
				else {
					if (level != 1 && level != 2) {
						send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Thần Thú của ngươi đã đạt cấp độ cao nhất rồi.\n"
							ESC"Rời khỏi", me->get_name()));
						return;
					}
					
					if (exp < maxexp) {
						send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Thần Thú của ngươi chưa đủ mức độ luyện hóa, hãy quay lại sao nhé.\n"
							ESC"Rời khỏi", me->get_name()));
						return;
					}

					return;
				}

			}
			else {
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ta không thấy Thần Thú nào ở đây cả.\n"
					ESC"Rời khỏi", me->get_name()));
				return;
			}

			break;

		case 103:
			result = "Ngươi muốn triệu hồi Thú Cưỡi nào?\n";

			kim = TASK_LEGEND_D->check_task_item_amount(who, "Kim Hồn");
			moc = TASK_LEGEND_D->check_task_item_amount(who, "Mộc Hồn");
			thuy = TASK_LEGEND_D->check_task_item_amount(who, "Thủy Hồn");
			hoa = TASK_LEGEND_D->check_task_item_amount(who, "Hỏa Hồn");
			tho = TASK_LEGEND_D->check_task_item_amount(who, "Thổ Hồn");
			thuhon = TASK_LEGEND_D->check_task_item_amount(who, "Thú Hồn");


			if (kim > 0 && moc > 0 && thuy > 0 && hoa > 0 && tho > 0 && thuhon > 0) {

				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Ngươi muốn triệu hồi Thú Cưỡi nào?\n"
					ESC HIW"Triệu hồi "HIY"Hỏa Đại Hùng.\natcride hoadaihung\n"
					ESC HIW"Triệu hồi "HIY"Hỏa Hồ Ly.\natcride hoaholy\n"
					ESC HIW"Triệu hồi "HIY"Thần Voi Địa.\natcride thanvoi\n"
					ESC HIW"Triệu hồi "HIY"Thủy Long Quy.\natcride thuylongquy\n"
					ESC"Rời khỏi", me->get_name()));

				//send_user(who, "%c%s", ':', result +
				//	ESC HIW"Triệu hồi "HIY"Hỏa Đại Hùng.\natcride hoadaihung\n" +
				//	ESC HIW"Triệu hồi "HIY"Hỏa Hồ Ly.\natcride hoaholy\n" +
				//	//ESC HIW"Triệu hồi "HIY"Tuần Lộc Đỏ.\natcride tuanlocdo\n" +
				//	ESC HIW"Triệu hồi "HIY"Thần Voi Địa.\natcride thanvoi\n" +
				//	ESC HIW"Triệu hồi "HIY"Thủy Long Quy.\natcride thuylongquy\n" +
				//	ESC HIW"Rời khỏi.\nCLOSE\n");

				return;
			}
			else {
				notify("Vật phẩm không đủ để triệu hồi thú cưỡi.");
				return;
			}
			break;
	}
}
