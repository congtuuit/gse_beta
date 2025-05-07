#include <advance.h>

#define USERNAME        0
#define PASSWORD        1
#define BANNED          2
#define MAX_LOGIN		3

int beta_test = 1;

int is_legal_user(object me, string id, string passwd) {
	int i, size, size2, exist = 0, len;
	object* user, * user2;
	string errstr, * line, * data, * serverCheck, * dataServerCheck;
	string user_logged, BaoTriPath, loginPath, accountsFilePath;

	accountsFilePath = HELPERS->get_account_txt();
	line = explode(read_file(accountsFilePath), "\n");
	for (i = 0, size = sizeof(line); i < size; i++) {
		data = explode(line[i], " ");
		if (id == data[USERNAME]) {
			exist = 1;
			user_logged = id;
			if (data[BANNED] == "1") {
				errstr = "Tài khoản đang tạm khóa!";
			}
			else if (passwd == "") {
				errstr = "Bạn chưa nhập mật khẩu!";
			}
			else if (passwd != data[PASSWORD]) {
				errstr = "Tài khoản hoặc mật khẩu không đúng!";
			}
			break;
		}
	}

	if (arrayp(user2 = USER_D->get_user()))
	{
		size2 = sizeof(user2);
		if (size2 >= "/sys/sys/count"->get_max_user())
		{
			errstr = "Người chơi đã đầy !";
		}
	}

	//if (user_logged != "tuadmin" && user_logged != "admin" && user_logged != "taiadmin" && user_logged != "adm") {
	if (user_logged != "") {
		// Một IP chỉ onl được 3 tài khoản
		user = filter_array(USER_D->get_user(), (: get_ip_name($1) == $2 : ), get_ip_name(me));
		for (i = 0, size = sizeof(user); i < size; i++) {
			if (size >= MAX_LOGIN) {
				errstr = sprintf("Chỉ có thể trực tuyến %d Tài khoản !", MAX_LOGIN);
			}
		}

		BaoTriPath = HELPERS->get_baotri_txt();
		if (file_exist(BaoTriPath)) {
			errstr = "Máy chủ đang bảo trì.";
		}
	}

	//if (exist >= 1) {
	//	//errstr = "Tài khoản này đã tồn tại!";
	//}
	//else {
	//	if (passwd == "") {
	//		errstr = "Bạn chưa nhập mật khẩu!";
	//	}
	//	//else {
	//	//	//ghi_file(accountsFilePath, sprintf("%s %s\n", id, passwd));
	//	//	//log_file("taikhoan.txt", sprintf("%s %s\n", id, passwd));
	//	//}
	//}

	if (passwd == "") {
		errstr = "Bạn chưa nhập mật khẩu!";
	}

	if (exist == 0) {
		if (beta_test == 1) {
			ghi_file(loginPath, sprintf("%s %s 0\n", id, passwd));
		} else {
			errstr = "Tài khoản không tồn tại.";
		}
	}

	//Kenh login
	loginPath = HELPERS->get_login_txt();
	if (!file_exist(loginPath)) {
		ghi_file(loginPath, sprintf(""));
	}

	switch ("/cmd/base/quanlykenh"->is_loggedin(loginPath, id, MAIN_D->get_region()))
	{
	case 0:
		if (!errstr) {
			ghi_file(loginPath, sprintf("%s>%d\n", id, MAIN_D->get_region()));
		}
		break;
	case -1:
		break;
	default:
		//errstr = sprintf("Tài khoản đang đăng nhập ở kênh %d!", "cmd/base/quanlykenh"->is_loggedin(loginPath, id, MAIN_D->get_region()));
		break;
	}

	if (errstr) {
		send_user(me, "%c%s", '!', errstr);
		send_user(me, "%c%c", 0xff, 0x11);
		return 0;
	}

	return 1;
}

