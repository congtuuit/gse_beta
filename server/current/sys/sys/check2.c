#include <advance.h>

#define USERNAME        0
#define PASSWORD        1
#define BANNED          2
#define MAX_LOGIN		3

int beta_test = 1;

/**
 * XỬ LÝ LOGIC ĐĂNG NHẬP
 */
int is_legal_user(object me, string id, string passwd) {
    int i, size, size2, exist = 0;
    object* user, *user2;
    string errstr = 0, *line, *data;
    string user_logged = "", BaoTriPath, loginPath, accountsFilePath;

    if (passwd == "") {
        send_user(me, "%c%s", '!', "Bạn chưa nhập mật khẩu!");
        send_user(me, "%c%c", 0xff, 0x11);
        return 0;
    }

    accountsFilePath = HELPERS->get_account_txt();
    line = explode(read_file(accountsFilePath), "\n");
    for (i = 0, size = sizeof(line); i < size; i++) {
        data = explode(line[i], " ");
        if (sizeof(data) < 3) continue; // Bỏ qua dòng không hợp lệ
        if (id == data[USERNAME]) {
            exist = 1;
            user_logged = id;
            if (data[BANNED] == "1") {
                errstr = "Tài khoản đang tạm khóa!";
            } else if (passwd != data[PASSWORD]) {
                errstr = "Tài khoản hoặc mật khẩu không đúng!";
            }
            break;
        }
    }

    if (!exist) {
        if (beta_test == 1) {
            loginPath = HELPERS->get_login_txt();
            if (!file_exist(loginPath)) {
                ghi_file(loginPath, sprintf(""));
            }
            ghi_file(accountsFilePath, sprintf("%s %s 0\n", id, passwd));
            // Cho phép tạo tài khoản mới trong beta_test
            return 1;
        } else {
            errstr = "Tài khoản không tồn tại.";
        }
    }

    if (!errstr && user_logged != "") {
        // Kiểm tra số lượng user online
        if (arrayp(user2 = USER_D->get_user())) {
            size2 = sizeof(user2);
            if (size2 >= "/sys/sys/count"->get_max_user()) {
                errstr = "Người chơi đã đầy !";
            }
        }
        // Một IP chỉ onl được 3 tài khoản
        if (!errstr) {
            user = filter_array(USER_D->get_user(), (: get_ip_name($1) == $2 :), get_ip_name(me));
            if (sizeof(user) >= MAX_LOGIN) {
                errstr = sprintf("Chỉ có thể trực tuyến %d Tài khoản !", MAX_LOGIN);
            }
        }
        // Kiểm tra bảo trì
        if (!errstr) {
            BaoTriPath = HELPERS->get_baotri_txt();
            if (file_exist(BaoTriPath)) {
                errstr = "Máy chủ đang bảo trì.";
            }
        }
    }

    // Kenh login
    if (!errstr && user_logged != "") {
        loginPath = HELPERS->get_login_txt();
        if (!file_exist(loginPath)) {
            ghi_file(loginPath, sprintf(""));
        }
        switch ("/cmd/base/quanlykenh"->is_loggedin(loginPath, id, MAIN_D->get_region())) {
        case 0:
            ghi_file(loginPath, sprintf("%s>%d\n", id, MAIN_D->get_region()));
            break;
        case -1:
            break;
        default:
            // Có thể thêm thông báo nếu cần
            break;
        }
    }

    if (errstr) {
        send_user(me, "%c%s", '!', errstr);
        send_user(me, "%c%c", 0xff, 0x11);
        return 0;
    }

    return 1;
}

