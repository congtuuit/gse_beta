
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define YUANBAO "sys/sys/test_db"

int tiLeQuiDoi(int gianap) {
	int result = 1;
	int tiLe = 10;

	result = (gianap / 1000) * tile;
	return result;
}

int main(object me, string arg)
{
	object who;
	int i, size, a1, a2, a3, a4;
	int tile, giatrinap, rootValue;
	string chars;
	if (is_player(me))
	{
		notify("Ngươi không đủ quyền hạn");
		return 1;
	}

	if (arg == "") {
		tell_user(me, ECHO"Cú pháp nạp: /nap [ID] [ti-le-khuyen-mai] [Gia-tri-nap-vnd]");
		return 1;
	}

	if (sscanf(arg, "%s %d %d", chars, tile, giatrinap) == 3) {

		if (!(who = find_any_char(chars)))
		{
			notify("Không tìm thấy người này");
			return 1;
		}

		if (tile < 1 || giatrinap < 10000) {
			tell_user(me, ECHO"Cú pháp nạp: /nap [ID] [ti-le-khuyen-mai] [Gia-tri-nap-vnd]");
			return 1;
		}
		else {

			rootValue = tiLeQuiDoi(tiLeQuiDoi);

			if (tile > 1) {
				giatrinap = rootValue + (rootValue / 100 * tile);
			}

			YUANBAO->add_yuanbao(who, giatrinap * 10);

			tell_user(me, sprintf(ECHO"%s (%d) đã nhận được %d Kim Bảo ( %d _ %d Khuyến mãi)", who->get_name(), who->get_number(), giatrinap, rootValue, (rootValue / 100 * tile)));
			tell_user(who, sprintf(HIG"Bạn đã nạp thành công %d Kim Bảo ( %d _ %d Khuyến mãi)", giatrinap, rootValue, (rootValue / 100 * tile)));

			who->set_save_2("donate.total", who->get_save_2("donate.total") + rootValue);
			who->set_save_2("donate.first", who->get_save_2("donate.first") + 1);

			tell_user(who, sprintf(ECHO"Điểm tích lũy nạp bạn hiện có "HIY"%d", who->get_save_2("donate.total")));

		}
		
	}

	return 1;
}