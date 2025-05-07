#include <ansi.h>
#include <effect.h>
#include <skill.h>
#include <action.h>
#include <equip.h>

// 函数：命令处理

void call(object me, int n) {
	if (n < 100) {
		me->set_save_2("marry_fashion.code", n);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
		tell_user(me, ECHO"-- %d", n);
		call_out("call", 2, me, n + 1);
	}
	else {
		return;
	}

}




int main(object me, string arg)
{
	object* user, item;
	string result, ipList = "", color, colorCode, cName;
	int i, size;

	if (is_player(me))
	{
		notify("Bạn không có đủ quyền。");
		return 1;
	}

	if (arrayp(user = USER_D->get_user()))
	{
		size = sizeof(user);
		result = sprintf("Bây giờ người chơi có %d：\n", size);
		if (size < 60)
		{
			for (i = 0; i < size; i++) {

				if (!arg) {
					
				} else
				if (arg == "1")
				{
					if (user[i]) {
						user[i]->set_hp(user[i]->get_max_hp());
						user[i]->set_mp(user[i]->get_max_mp());
						user[i]->set_yuan(user[i]->get_max_yuan());

						send_user(get_scene_object_2(user[i], USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(user[i]), 32531, 1, OVER_BODY, PF_ONCE);
						write_user(user[i], HIY "%s chúc phúc bạn khôi phục toàn bộ sinh lực", me->get_name());
					}
				}
				else if (arg == "2") {
					if (user[i]) {
						ipList += sprintf(NOR"%s-_%d_"HIR"%s\n", user[i]->get_name(), user[i]->get_number(), get_ip_name(user[i]));
					}
				}
				else if (arg == "3") {
					if (user[i]) {
						ipList += sprintf(NOR"_%d_"HIR"%s\n", user[i]->get_number(), get_ip_name(user[i]));
					}
				}
				else if (sscanf(arg, "%s %x", color, colorCode) == 2){

					me->set_hair_color(colorCode);
					me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
					send_user(me, "%c%c", 0x56, 0xff);

				}

				if (user[i]) result = sprintf("%s%s%s(%d) "HIY"KNB[%d]"NOR", ",
					result, i % 8 ? "" : "\n", user[i]->get_name(), user[i]->get_number(), "sys/sys/test_db"->get_yuanbao(user[i]) / 10);
			}
				
		}

		result += sprintf("\nBây giờ người chơi có %d：\n", size);
		
		if (ipList != "") {
			tell_user(me, ipList);
		}
		else {
			tell_user(me, result);
		}

	}
	else    tell_user(me, "Chúng tôi không có bất kỳ người chơi");

	/*me->set_ride(18);
	me->set_hair(8);
	me->set_hair_color(0x880800);
	me->set_save_2("marry_fashion.code", 2);
	me->set_save_2("marry_fashion.color", 0x880800);
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
	send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 42432, 1, OVER_BODY, PF_ONCE);*/

	//cName = "|" + sprintf(HIR"WIN - CHIẾN THẮNG！");

	//send_user(me, "%c%c%d%d%d%d%s", 0xA5, 6, 0, 111, 222, 10, cName);

	return 1;
}
