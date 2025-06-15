#include <map.h>
#include <effect.h>
#include <ansi.h>
#include <equip.h>
#include <skill.h>
#include <effect.h>
#include <city.h>
#include <cmd.h>

#define SERVER INI_DIR "server.ini"
#define WELCOME "welcome.txt"
#define LOGIN_LOG "loginfo.txt"
#define NEW_LOGIC_LOGIN 0

private string welcome;
private static int logintime;

void SAVE_BINARY() {}
void move_to_pvp_lobby(object me);
void updateOrgChange(object me);

private void auto_check_login(object me)
{
	if ("/cmd/base/quanlykenh"->is_logged_other(me->get_id()) == 1)
	{
		QUIT_CMD->main(me, "");
	}
}

private void create()
{
	string *line, indexServer, lemma, content;
	int i, size;

	line = explode(read_file(SERVER), "\n");
	MAIN_D->set_host_type(0);

	welcome = read_file("/" WELCOME);

	for (i = 0, size = sizeof(line); i < size; i++)
	{
		if (line[i][0] == '#' || line[i] == "")
			continue;
		if (line[i][ < 1] <= ' ')
			line[i] = line[i][0.. < 2];
		if (line[i][0] == '#' || line[i] == "")
			continue;
		if (!sscanf(line[i], "%s : %s", lemma, content))
		{
			log_file(ERROR, sprintf("Lỗi: " SERVER " %d Lỗi định nghĩa đường kiểm tra.\n", i + 1));
			continue;
		}

		switch (lemma)
		{
		case "region":
			if (MAIN_D->get_region() < 1)
			{
				MAIN_D->set_region(to_int(content));
			}
			break;
		case "host":
			if (MAIN_D->get_host() < 1)
			{
				MAIN_D->set_host(to_int(content));
			}
			break;
		case "hosttype":
			if (MAIN_D->get_host_type() < 1)
			{
				MAIN_D->set_host_type(to_int(content));
			}
			break;
		}
	}

	if (file_exist(WELCOME))
		welcome = read_file("/" WELCOME);
}

string get_name() { return "--> Kết nối "; }

void logon(object me)
{
	string ip = get_ip_name(me);
	int key1, key2, key3, key4, key5, key6, key7, key8;

	if (!CHECK_D->is_passed_ip(ip) && CHECK_D->is_banned_ip(ip))
	{
		send_user(me, "%c%s", '!', "Thật xin lỗi địa chỉ " + ip + " ở " GAME_NAME " không được hoan nghênh");
		destruct(me);
	}
	else
	{
		key1 = random(MAX_NUMBER);
		key2 = random(MAX_NUMBER);
		key3 = random(MAX_NUMBER);
		key4 = random(MAX_NUMBER);
		key5 = random(MAX_NUMBER);
		key6 = random(MAX_NUMBER);
		key7 = random(MAX_NUMBER);
		key8 = MAIN_D->get_absolute_random_number();
		if (MAIN_D->get_host_type() == 0)
		{
			key1 = 100;
			key2 = 100;
			key3 = 100;
			key4 = 100;
			key5 = 100;
			key6 = 100;
			key7 = 100;
			key8 = 100;
		}
		me->set("key", sprintf("%08X%08X%08X%08X%08X%08X%08X%08X", key1, key2, key3, key4, key5, key6, key7, key8));
		send_user(me, "%c%c%w%d%d%d%d%d%d%d%d%d", 0x49, 0x01, 1, key1, key2, key3, key4, key5, key6, key7, key8, time()); // time() 防加速器
		me->enable_logon_cmds();
	}
}

void connect(object me, string id, string code, int order)
{
	string lowId, passwd, lowId2, passwd2, result, api;
	object *user;
	int size, time, number, isBaoTri = 0;
	string errstr, *line, *data, *serverCheck, *dataServerCheck;

	passwd = passwd_decrypt(me->get("key"), code);

	if (me->get_login_flag() >= 2)
		return;
	if (me->get_id() != "" && me->get_id() != 0)
		return;

	// Check login
	/*if (MAIN_D->get_host_type() == 6012)
	{
		lowId = id;
		me->set_id(id);
		me->set_real_id(id);
		log_file("php.dat", sprintf(MAIN_D->get_php_ip() + ":80\n"
			"GET /xq2/authentic.php?key=%s\r\n", id));
		log_file("php.dat", sprintf(MAIN_D->get_php_ip() + ":80\n"
			"GET /xq2/authentic.php?key=%s\r\n", rawurlencode2(id)));
		db_user_authentic(me, lowId, sprintf(MAIN_D->get_php_ip() + ":80\n"
			"GET /xq2/authentic.php?key=%s\r\n", rawurlencode2(id)));
		me->authentic_callout();
		me->user_authentic_callout("", order);
		return;
	}*/

	if (!CHECK_D->is_legal_id(me, lowId = strlwr(id)))
		return;

	// Kiểm tra thông tin đăng nhập từ file
	if (!"sys/sys/check2"->is_legal_user(me, lowId = strlwr(id), passwd))
	{
		destruct(me);
		return;
	}

	// object me is empty
	me->set_id(id);
	me->set_real_id(id);
	user = USER_D->get_user();
	size = sizeof(user);
	if (size >= "/sys/sys/count"->get_max_user())
	{
		send_user(me, "%c%s", '!', GAME_NAME "Nhân số đã đạt tối đa, quay trở lại sau.");
		destruct(me);
		return;
	}

	if (me->get_id() != lowId)
	{
		send_user(me, "%c%s", '!', GAME_NAME "Trò chơi đang bảo trì, hãy quay lại sau");
		destruct(me);
		return;
	}

	lowId2 = rawurlencode(lowId);
	passwd2 = rawurlencode(passwd);

	if (NEW_LOGIC_LOGIN == 1)
	{
		// Logauth
		//result = sprintf("GET http://%s/xq2/authentic.php?u=%s&p=%s\r\n", "127.0.0.1", lowId2, passwd2);
		//log_file("auth.dat", result);

		db_user_authentic(me, lowId2, passwd2);

		//db_user_authentic(me, lowId2, result);
		me->authentic_callout();

		// Gọi vòng lặp để check kết quả
		me->user_authentic_callout(passwd, order);
	}
	else
	{
		db_user_authentic(me, lowId2, passwd2);

		// Gọi vòng lặp để check kết quả
		me->authentic_callout();
		// Gọi vòng lặp để check kết quả
		me->user_authentic_callout(passwd, order);
	}
}

void do_user_exist(object me, string passwd, string name)
{
	object *user, body, temp, *alluser;
	string lowId, ip1, ip2, realid;
	int i, size, acountid, channelCode;

	channelCode = me->get_channel();

	lowId = me->get_id();
	acountid = me->get_acountid();
	realid = me->get_real_id();
	if (me->get_login_flag() >= 2)
		return;

	alluser = users();
	alluser -= ({me});
	alluser -= ({0});
	if (arrayp(alluser) && sizeof(alluser) > 0 && arrayp(user = filter_array(alluser - ({me}), ( : $1->get_id() == $2:), lowId)) // 判断ＩＤ吻合(除自己外)
		&& sizeof(user) && objectp(body = user[0]))
	{

		if (channelCode != body->get_channel())
		{
			send_user(me, "%c%s", '!', sprintf("Tài khoản đang đăng nhập ở kênh %d !", body->get_channel()));
			db_user_clear(me, me->get_id());
			destruct(me);
			return;
		}

		if (body->get_login_flag() < 2)
		{
			db_user_clear(body, body->get_id());
			destruct(body);
		}
		else if (body->is_user())
		{
			/*if( body->get( "quit" ) )
			{
					send_user( me, "%c%s", '!', "Quit hoạt động không hoàn chỉnh, không quá nhanh chóng đăng nhập" );
					db_user_clear( me, me->get_id() );
					destruct(me);
					return;
			}*/

			ip1 = get_ip_name(me);
			ip2 = get_ip_name(body);
			if ((is_gm(body) && CHECK_D->check_gm_ip(ip1, 1) != 1) || (is_gm2(body) && CHECK_D->check_gm_ip(ip1, 2) != 1) || (is_gm3(body) && CHECK_D->check_gm_ip(ip1, 3) != 1) || (is_god(body) && CHECK_D->check_gm_ip(ip1, 4) != 1))
			{
				send_user(me, "%c%s", '!', "Tài khoản không được phép đăng nhập vào IP này");
				db_user_clear(me, me->get_id());
				destruct(me);
				return;
			}
			if (is_gm3(body) && "/sys/sys/count"->get_can_gm3() == 0)
			{
				send_user(me, "%c%s", '!', "Hiện nay không cho phép hoạt động số đăng nhập");
				db_user_clear(me, me->get_id());
				destruct(me);
				return;
			}
			tell_user(me, HIR "Có người đang dùng số tài khoản của bạn ở %s , bạn hãy đuổi hắn ta ra khỏi trò chơi.", ip1 == ip2 ? ip2 : RED + ip2 + HIR);
			tell_user(body, HIR "Số tài khoản của bạn ở %s đã bị số tài khoản %s đuổi ra khỏi trò chơi.", ip1 == ip2 ? ip1 : RED + ip1 + HIR, ip2);
			me->set_save("ndmkk", 0);
			body->set_save("ndmkk", 0);
			me->set_save("ndmkhtk", 0);
			body->set_save("ndmkhtk", 0);

			record_login(body, body->get_id(), 0);
			record_login(body, body->get_id(), 1);

			temp = new(USER);
			exec(temp, body);
			destruct(temp);

			LOGIN_1_D->reconnect(me, body);
			return;
		}
	}
	alluser -= ({me});
	alluser -= ({0});
	if (arrayp(alluser) && sizeof(alluser) > 0 && arrayp(user = filter_array(alluser, ( : $1->get_real_id() == $2:), realid)) // 判断ＩＤ吻合(除自己外)
		&& sizeof(user) && objectp(body = user[0]))
	{
		send_user(me, "%c%s", '!', "Đã có một nhân vật khác cùng Tài khoản này trong trò chơi.");
		db_user_clear(me, me->get_id());
		destruct(me);
		return;
	}
	db_user_exist(me, lowId);

	me->user_exist_callout(lowId, passwd, name, channelCode); // handle channel
}

void do_user_restore(object me, string id, string passwd, string name, int channelCode)
{
	db_user_restore(me, me->get_id());
	me->user_restore_callout(id, passwd, name, me->get_acountid(), channelCode);
}

private void enter_world(object me, int channelCode);

void enter(object me, string passwd, int channelCode)
{
	if (me->get_save("khoanhanvat") >= 1)
	{
		send_user(me, "%c%s", '!', "Nhân vật này đã bị Khoá");
		destruct(me);
		return;
	}

	send_user(me, "%c%c", 0x49, 0x02);
	enter_world(me, channelCode);
	"sys/party/mingren"->check_mingren_upline(me);
	//	 "sys/party/bxh_cap"->update_bxh_cap(me);
	"sys/party/bxh_cap"->update_thongbao(me);
	"sys/party/bxh_ts"->update_thongbao(me);
	//	 "sys/party/bxh_trongcay"->update_thongbao(me);
}

void enter_world(object me, int channelCode)
{
	object *user, map, city, mailbox, npc, item;
	string id, name, ip1, ip2, start_place, cTmp;
	int number, z, x, y, d, p, level, point, time, distanceTime;

	object file;

	/*
	 * Chú thích: Ở đây không thể dùng hàm `users()` vì lo ngại:
	 *       1. Tính duy nhất của dữ liệu USER đang load (ví dụ: xóa, sửa đổi thành viên bang hội, v.v.)
	 *       2. USER đang kết nối có thể chưa trở thành thành viên của `users()`
	 */
	// Quan trọng: Ngăn chặn lỗi trùng lặp (đảm bảo không có ID trùng lặp) (cấm người chơi sau này đăng nhập)
	if (arrayp(user = children(USER) - ({load_object(USER)}))								  // 获取所有玩家  users()
		&& arrayp(user = filter_array(user - ({me}), ( : $1->get_id() == $2:), me->get_id())) // 判断ＩＤ吻合(除自己外)
		&& sizeof(user))																	  // 用户个数大于０
	{
		db_user_clear(me, me->get_id());
		destruct(me);
		return;
	}

	if ("/sys/sys/count"->get_test() == 1)
	{
		me->set("is_gm", 1);
		me->delete_save_2("Newbie.Login");
		if (!me->get_name())
		{
			me->set_name(sprintf("Vai trò %d", me->get_number()));
		}
	}

	me->setup();

	// Handle channel feature
	me->set_channel(channelCode);

	if ((is_gm(me) && CHECK_D->check_gm_ip(get_ip_name(me), 1) != 1) || (is_gm2(me) && CHECK_D->check_gm_ip(get_ip_name(me), 2) != 1) || (is_gm3(me) && CHECK_D->check_gm_ip(get_ip_name(me), 3) != 1) || (is_god(me) && CHECK_D->check_gm_ip(get_ip_name(me), 4) != 1))
	{
		send_user(me, "%c%s", '!', "Tài khoản không được phép đăng nhập vào IP này");
		db_user_clear(me, me->get_id());
		destruct(me);
		return;
	}
	if (is_gm3(me) && "/sys/sys/count"->get_can_gm3() == 0)
	{
		send_user(me, "%c%s", '!', "Hiện nay không cho phép hoạt động số đăng nhập");
		db_user_clear(me, me->get_id());
		destruct(me);
		return;
	}

	USER_D->add_user(me);
	// if ((is_gm(me) || is_gm3(me)) && ("/sys/sys/count"->get_test() == 0))
	// {
	// 	me->set_name("Quản Lý Viên");
	// }
	if ((is_gm(me) || is_gm3(me)))
	{
		me->set_name("Quản Lý Viên");
	}
	if (is_god(me))
	{
		me->set_name("Admin");
	}

	ip1 = me->get_quit_ip();
	ip2 = get_ip_name(me);
	if (ip1)
	{
		tell_user(me, "Lần trước tuyến nối là %s từ %s .\n", short_time(me->get_quit_time()), ip1 == ip2 ? ip1 : HIR + ip1 + NOR);
	}

	tell_user(me, "Tuyến nối hiện tại %s từ %s .\n", short_time(), ip2);

	/*
		distanceTime = time() - me->get_quit_time();
		if (distanceTime >= 400000 && me->get_quit_time() > 0) {
			if (me->get_save("distanceTime") <= distanceTime) {
				me->set_save("distanceTime", distanceTime);
			}
			tell_user(me, HIR"Hình như ngươi có quà mừng ngày trở về, mau mau đến Thần Tiên Gia Gia (Chu Quốc) để kiểm tra nhé!");
		}
	*/

	me->set_fam_name(me->get_fam_name());

	tell_user(me, HIY "Đăng nhập vào kênh %d.", me->get_channel());

	if (welcome && welcome != "")
	{
		tell_user(me, "%s\nChúc %s vui vẻ khi tham gia trò chơi !", welcome, me->get_name());
	}

	// me->set_pk(me->get_pk());
	if (me->get_pk() >= 100 || get_effect(me, EFFECT_USER_PK))
	{
		me->set_attack_mode(0);
		write_user(me, "Hình thức tấn công của bạn: Tấn công tự do.");
	}
	else
	{
		me->set_attack_mode(1);
		write_user(me, "Hình thức tấn công của bạn: Hòa bình.");
	}

	// me->set_attack_mode(1);
	// set_effect(me, EFFECT_USER_PK, 0);

	if (me->get_save_2("doatbaomatac.status") == 1)
	{
		me->delete_save_2("doatbaomatac");
	}

	//	if ( me->get_save("trungsinh")>=1 ) "/sys/party/bxh_ts"->update_bxh_cap(me);
	// me->set_attack_mode();
	me->set_save("ndmkk", 0);
	me->set_save("ndmkhtk", 0);

	// block quankho
	//"/cmd/base/quankho"->do_block(me);

	// MAILBOX->sys_mail(me->get_id(),me->get_number(),sprintf("Chúc %s chơi vui vẻ !",me->get_name()));
	time = me->get_save("suicide");
	if (time > 0)
	{
		write_user(me, HIY "Bạn quyết định tự sát, hãy cân nhắc lại kĩ càng");
	}

	me->count_gift();
	me->restore_inventory();
	me->restore_beast();
	me->disable_logon_cmds();
	USER_SUIT_D->check_suit_equip(me);

	send_user(me, "%c%c%d", 0x49, 10, get_heart_timer(me));
	me->set_2("go_count.time2", get_heart_timer(me));

	me->set_login_flag(2);
	if (get_effect(me, EFFECT_MAGIC_CARD))
		MAGIC_CARD_D->effect_break(me);

	record_login(me, me->get_id(), 1);
	me->send_legend();

	send_user(me, "%c%c%c%s", 0x3d, 49, me->get_org_position(), me->get_org_name());
	if (stringp(start_place = me->get_start_place()) && sscanf(start_place, "%d:(%d,%d)%d", z, x, y, d) == 4 && z < 1000 && (p = get_valid_xy(z, x, y, IS_CHAR_BLOCK)))
	{
		me->add_to_scene(z, p / 1000, p % 1000, d);
	}
	else
	{
		MAP_D->add_to_void(me);
	}

	CONNECT_D->init_user(me);

	// if( me->is_die() && get_effect(me, EFFECT_USER_DIE) ) set_effect(who, EFFECT_USER_DIE, 1);
	// me->save();

	if (me->get_perform("03191") && me->get_fam_name() != "Đào Hoa Nguyên")
	{
		me->set_perform("03191", 0);
	}
	if (me->get_perform("03192") && me->get_fam_name() != "Đào Hoa Nguyên")
	{
		me->set_perform("03192", 0);
	}
	if (me->get_perform("02221#") && me->get_fam_name() != "Thục Sơn")
	{
		me->set_perform("02221#", 0);
	}
	if (me->get_perform("02222#") && me->get_fam_name() == "Thục Sơn")
	{
		me->set_perform("02222#", 0);
	}

	if (me->get_save("login_count") > 2)
		log_file("errlogin.txt", sprintf("id:%s number:%d\n", me->get_id(), me->get_number()));
	me->add_save("login_count", 1);
	// // Achievement System Integration - Login Achievements
	// "sys/achievement/achievement"->check_achievement_progress(me, "first_login", 1);
	// "sys/achievement/achievement"->check_achievement_progress(me, "login_7_days", 1);
	// "sys/achievement/achievement"->check_achievement_progress(me, "login_30_days", 1);
	// "sys/achievement/achievement"->check_achievement_progress(me, "login_100_days", 1);
	
	// Daily/Weekly/Monthly challenge integration
	// "sys/content/daily_updates"->check_daily_challenge(me, "daily_login", 1);
	// "sys/content/weekly_updates"->check_weekly_challenge(me, "weekly_login", 1);
	// "sys/content/monthly_updates"->check_monthly_challenge(me, "monthly_login", 1);

	USER_D->gm_channel(sprintf(HIR "%s : %s (%d) kết nối từ %s [%d].",
							   get_name(), me->get_name(), me->get_number(), get_ip_name(me), me->get_channel()));
	log_file(LOGIN_LOG, sprintf("%s %s %d %s %s - - [%x#] kết nối với nhập\n", me->get_id(), me->get_name(), me->get_number(), get_ip_name(me), short_time(), getoid(me)));

	// me->send_to_friend(1);
	me->receive_friends();
	me->send_black();

	mailbox = new(MAILBOX);
	mailbox->set_owner(me->get_id());
	if (mailbox->check_mails2(me))
		send_user(me, "%c", 0x4d);
	destruct(mailbox);

	me->set_login_time(time());
	// me->clean_online_time();    // 清除沉迷时间
	// me->add_strength( gone_time( me->get_quit_time() ) / 360 );    // 离线也可恢复体力
	set_effect(me, EFFECT_USER_LOGIN, 20);

	if (city = CITY_D->get_city_object(me))
		city->pay_salary_baseon_contribute(me);

	me->login_timeout();

	USER_SLAVE_D->restore_all_slave(me); // 召唤兽保留１分钟

	if (me->get_quest("escort.flag") == 1 && stringp(id = me->get_quest("escort.robber")) // 寻找蒙面人
		&& objectp(npc = find_char(id)) && npc->is_escort_robber() && present("Vật Phẩm Quý Bấu", me, 1, MAX_CARRY * 4))
	{
		npc->start_fight(me);
		me->set_quest("escort.robber#", npc);
		send_user(me, "%c%s", '!', "Kẻ lạ xuất hiện, hành động bị ảnh hưởng.");
	}

	if ((name = me->get_org_name()) && name != "") // 更新帮派信息
	{
		npc = CITY_ZHOU->get_2(sprintf("org.%s", name));
		if (objectp(npc))
		{
			if ((number = me->get_number()) && npc->get_member_id(number))
			{
				npc->set_member_quit(number, 0);
				npc->set_member_id(number, me->get_id());
			}
		}
		else
		{
			me->set_org_name("");
			me->set_org_position(0);
			me->delete_title("C001");
			me->delete_title("C002");
			me->delete_title("C003");
			me->delete_title("C004");
			me->delete_title("C005");
			me->delete_title("C006");
			me->delete_title("C007");
			me->delete_title("C008");
			send_user(me, "%c%c%c%c", 0x3d, 49, 0, 0);
		}
	}

	if ((z = 60 - gone_time(me->get_save_2("familyuse"))) > 0)
	{
		send_user(me, "%c%c%c%w", 0x30, 0, 8, z);
	}
	if ((z = me->get_extra_double_time() - me->get_game_time()) > 0)
		send_user(me, "%c%w%w%c", 0x81, 9998, z, EFFECT_GOOD);
	if ((z = me->get_extra_exp_time() - time()) > 0)
		send_user(me, "%c%w%w%c", 0x81, 9999, z, EFFECT_GOOD);

	if (me->get_fam_name() && !me->get_save("famrec"))
	{
		"/sys/sys/count"->add_family(me->get_fam_name(), 1);
		me->set_save("famrec", 1);
	}
	CHAR_CHAR_D->send_loop_perform(me, me);	  // 显示持续效果
	CHAR_CHAR_D->send_loop_perform_2(me, me); // 显示持续图标

	if (item = me->get_equip(HAND_TYPE))
		if (item->get("time_item"))
		{
			if (time() < item->get_lock_time() || item->get_lock_time() == 0)
			{
				item->start_loop_perform(me);
			}
		}
	if (item = me->get_equip(BACK_TYPE))
	{
		item->get_equip_effect(me);
	}
	if (item = me->get_equip(FASHION_TYPE))
	{
		item->get_equip_effect(me);
	}
	//-----------------------------------------------------------------------------
	if (get_effect_3(me, EFFECT_CHAR_INVISIBLE))
	{
		if (get_effect_3(me, EFFECT_03643) || me->get_save("no_visible"))
			send_user(me, "%c%c%c", 0x3d, 241, 2);
	}
	me->add_title("X");
	me->send_title_list();

	if (me->get_vip())
		"item/sell/0061"->vip_effect(me);
	USER_RANK_D->online_rank(me, 0);
	send_user(me, "%c%c%c", 0xA2, 10, me->get_save_2("online_rank.level"));
	//	WUSHUANG->check_org_title(me);
	//	"sys/party/vst3"->check_org_title(me);
	"sys/party/vstfix"->check_org_title(me);

	// Is Logged another channel
	// call_out("auto_check_login", 2, me);
	// call_out("auto_check_login", 5, me);

	if (me->have_title("Z888"))
	{
		CHAT_D->sys_channel(0, HIY "Cung nghênh Vô Song Thành chủ đại danh vang dội " HIG + me->get_name() + HIY " Đăng nhập Chiến Quốc Loạn Thế Anh Hùng!");
		if (WUSHUANG->get_save("wg_duty") > 20000000)
			MAILBOX->sys_mail(me->get_id(), me->get_number(), HIW "Bạn chiếm lĩnh Vô Song Thành thuế đã đạt tối đa, thuế sẽ không còn tăng");
	}

	if (me->have_title("A111"))
	{
		CHAT_D->sys_channel(0, HIY "Cung nghênh " + HIR "Chiến Quốc Minh Chủ" + HIY " đại danh vang dội " HIG + me->get_name() + HIY " Đăng nhập Chiến Quốc Loạn Thế Anh Hùng!");
	}

	if (me->have_title("A112"))
	{
		CHAT_D->sys_channel(0, HIY "Cung nghênh " + HIR "Chiến Quốc Tiểu Minh Chủ" + HIY " đại danh vang dội " HIG + me->get_name() + HIY " Đăng nhập Chiến Quốc Loạn Thế Anh Hùng!");
	}

	if (me->have_title("A999"))
	{
		CHAT_D->sys_channel(0, HIR "Thợ Săn Kho Báu" + HIY " uy danh lừng lãy " HIG + me->get_name() + HIY " Đăng nhập!");
	}

	if (me->have_title("Y025"))
	{
		CHAT_D->sys_channel(0, HIB "Thiên Hạ Vô Song " HIY + me->get_name() + NOR " đã đăng nhập!");
	}
	if (me->get_cash() >= 50000000)
	{
		CHAT_D->sys_channel(0, HIY "Phú Hộ " HIG + me->get_name() + HIY " đã Đăng nhập Chiến Quốc Loạn Thế Anh Hùng!");
	}

	updateOrgChange(me);
	// move_to_pvp_lobby(me);
}

void updateOrgChange(object me)
{
	if (MAIN_D->get_region() == 1)
	{
		// if (me->get_org_name() != "") "/sys/sys/manager"->upgrade_async(me);
	}
}

void move_to_pvp_lobby(object me)
{
	int channelCode = MAIN_D->get_region();
	int mapId = 891;

	if (channelCode != 1)
	{
		me->set_login_flag(2);
		set_invisible(me, 1);
		set_effect(me, EFFECT_USER_LOGIN, 4);
		me->add_to_scene(mapId, 40 + random(5), 32 + random(5));
	}
	else if (get_z(me) == 891)
	{
		me->set_login_flag(2);
		set_invisible(me, 1);
		set_effect(me, EFFECT_USER_LOGIN, 4);
		me->add_to_scene(80, 292 + random(5), 185 + random(5));
	}
}