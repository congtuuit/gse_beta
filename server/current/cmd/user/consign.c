#include <ansi.h>
#include <public.h>
#include <time.h>
#include <action.h>
#include <effect.h>
#include <cmd.h>
#include <music.h>

#define YUANBAO "sys/sys/test_db"
#define FILE_DATA_50  "data/city/KyGuiKNB50.dat"
#define FILE_DATA_100 "data/city/KyGuiKNB100.dat"
#define FILE_DATA_200 "data/city/KyGuiKNB200.dat"

static mapping cardlist = ([
	50:([]),
		100 : ([]),
		200 : ([]),
]);

int reset_time = 0;

int ID = 0;
int KNB = 1;
int PRICE = 2;
int TIME = 3;
int UID = 4;
int STATUS = 5;

static int* cur_reset = ({ 0, 0, 0 });

static string* TABLE_ITEMS = ({});

string* getItems(int uid, string path) {
	int i, sizeFile, tempValue, tempPrice, tempSellerID;
	string* line, * data, newContents = "", fileData, *result;

	if (!file_exist(path)) {
		return;
	}

	fileData = read_file(path);

	if (strlen(fileData) < 2) {
		return;
	}

	line = explode(fileData, "\n");

	result = ({});
	for (i = 0, sizeFile = sizeof(line); i < sizeFile; i++)
	{
		data = explode(line[i], ":");
		if (to_int(data[UID]) == uid) {
			result += ({ line[i] });
		}
	}

	return result;
}

void search_history(object me) {
	string * data, * historys;
	int uid, i, flag, found = 0;

	uid = me->get_number();
	send_user(me, "%c%c%c", 0x92, 1, 3);

	historys = getItems(uid, FILE_DATA_50);
	if (historys) {

		for (i = 0; i < sizeof(historys); i++)
		{
			//send_user(me, "%c%c%d%d%d%d%d", 0x92, 3, id, value, price, time, flag);
			//flag chưa bán: 0
			//flag Quá hạn: 1
			//flag Success: 2

			data = explode(historys[i], ":");

			flag = to_int(data[STATUS]);
			if (flag == 0 && to_int(data[TIME]) < time()) {
				flag = 1;
			}

			send_user(me, "%c%c%d%d%d%d%d", 0x92, 3, to_int(data[ID]), to_int(data[KNB]), to_int(data[PRICE]), to_int(data[TIME]), flag);
		}

		found = 1;
	}

	historys = getItems(uid, FILE_DATA_100);
	if (historys) {

		for (i = 0; i < sizeof(historys); i++)
		{
			//send_user(me, "%c%c%d%d%d%d%d", 0x92, 3, id, value, price, time, flag);
			//flag chưa bán: 0
			//flag Quá hạn: 1
			//flag Success: 2

			data = explode(historys[i], ":");

			flag = to_int(data[STATUS]);
			if (flag == 0 && to_int(data[TIME]) < time()) {
				flag = 1;
			}

			send_user(me, "%c%c%d%d%d%d%d", 0x92, 3, to_int(data[ID]), to_int(data[KNB]), to_int(data[PRICE]), to_int(data[TIME]), flag);
		}

		found = 1;
	}

	historys = getItems(uid, FILE_DATA_200);
	if (historys) {

		for (i = 0; i < sizeof(historys); i++)
		{
			//send_user(me, "%c%c%d%d%d%d%d", 0x92, 3, id, value, price, time, flag);
			//flag chưa bán: 0
			//flag Quá hạn: 1
			//flag Success: 2

			data = explode(historys[i], ":");

			flag = to_int(data[STATUS]);
			if (flag == 0 && to_int(data[TIME]) < time()) {
				flag = 1;
			}

			send_user(me, "%c%c%d%d%d%d%d", 0x92, 3, to_int(data[ID]), to_int(data[KNB]), to_int(data[PRICE]), to_int(data[TIME]), flag);
		}

		found = 1;
	}

	if (found == 0) {
		notify("Không tìm thấy dữ liệu");
	}
	

	me->set_pay_money_buy_item(0);
}

void add_to_record(object player, int amountKNB, int amountPrice, int xTime)
{
	int size, index, pos, oldid, id1, amount, i, iTimeFrom, iTimeTo, itemID;
	int userId = player->get_number();
	string strData, userName = player->get_name();
	iTimeFrom = time();
	iTimeTo = iTimeFrom + xTime;
	
	itemID = iTimeFrom + userId;
	switch (amountKNB)
	{
	case 100:
		ghi_file(FILE_DATA_100, sprintf("%d:%d:%d:%d:%d:%d\n", itemID, amountKNB, amountPrice, iTimeTo, userId,0));
		break;
	case 200:
		ghi_file(FILE_DATA_200, sprintf("%d:%d:%d:%d:%d:%d\n", itemID, amountKNB, amountPrice, iTimeTo, userId,0));
		break;
	default:
		ghi_file(FILE_DATA_50, sprintf("%d:%d:%d:%d:%d:%d\n", itemID, amountKNB, amountPrice, iTimeTo, userId,0));
		break;
	}

	send_user(player, "%c%w", 0x0d, MUSIC_TASK);
	send_user(player, "%c%c%d", 0x45, 2, YUANBAO->get_yuanbao(player));
	notify("Ký gửi thành công!");
	send_user(player, "%c%s", ';', sprintf("Ký gửi thành công!"));
}

void remove(object me, string path, int id) {
	int i, sizeFile, tempValue, tempPrice, tempSellerID;
	string* line, * data, newContents = "", fileData;

	if (!file_exist(path)) {
		return;
	}

	fileData = read_file(path);

	if (strlen(fileData) < 2) {
		return;
	}

	line = explode(fileData, "\n");

	for (i = 0, sizeFile = sizeof(line); i < sizeFile; i++)
	{
		data = explode(line[i], ":");

		if (id == to_int(data[ID])) {
			tempSellerID = to_int(data[UID]);
			tempValue = to_int(data[KNB]);
			tempPrice = to_int(data[PRICE]);

			continue;
		}

		newContents += line[i] + "\n";
	}

	rm(path);
	write_file(path, newContents);

	if (tempSellerID > 0 && tempValue > 0 && tempPrice > 0) {
		me->add_cash(tempPrice);
		log_file("buycard.dat", sprintf("%s %s(%d) đã bán thành công %d KNB giá %d\n", short_time(), me->get_id(), me->get_number(), tempValue, tempPrice));
		send_user(me, "%c%s", ';', sprintf("Bạn nhận được "HIC"%d"NOR" lượng từ Ký gửi KNB！", tempPrice));
		send_user(me, "%c%w", 0x0d, MUSIC_EXCHANGE);

		return;
	}
}

void updateStatus(object me, string path, int userId) {
	int i, sizeFile, tempValue, tempPrice, tempSellerID, percent = 1, ck;
	string* line, * data, newContents = "", fileData, soldStr;
	object seller;


	if (!file_exist(path)) {
		return;
	}

	fileData = read_file(path);

	if (strlen(fileData) < 2) {
		return;
	}

	line = explode(fileData, "\n");

	for (i = 0, sizeFile = sizeof(line); i < sizeFile; i++)
	{
		data = explode(line[i], ":");

		if (userId == to_int(data[ID])) {
			tempSellerID = to_int(data[UID]);
			tempValue = to_int(data[KNB]);
			tempPrice = to_int(data[PRICE]);

			if (me->get_cash() < tempPrice) {
				notify("Ngân lượng không đủ!");
				tell_user(me, ECHO"Ngân lượng không đủ!");
				return;
			}

			soldStr = sprintf("%d:%d:%d:%d:%d:%d", to_int(data[ID]), tempValue, tempPrice, to_int(data[TIME]), to_int(data[UID]), 2);

			continue;
		}

		newContents += line[i] + "\n";
	}

	newContents += soldStr + "\n";

	rm(path);
	write_file(path, newContents);

	if (tempSellerID > 0 && tempValue > 0 && tempPrice > 0) {
		me->add_cash(-tempPrice);

		ck = (tempValue * 10) - ((tempValue * 10) * percent / 100);

		YUANBAO->add_yuanbao(me, ck);
		ck = (tempValue * 10) - ck;

		tell_user(me, sprintf(HIR"Bạn dùng %d lượng thu mua %d Kim Bảo. Phí %d Kim Ngân Bảo.", tempPrice, tempValue, ck));

		log_file("buycard.dat", sprintf("%s %s(%d) mua %d giá %d\n", short_time(), me->get_id(), me->get_number(), tempValue, tempPrice));

		send_user(me, "%c%s", ';', sprintf("Giao dịch thành công, số dư hiện có "HIY"%d "NOR"Kim Bảo！", YUANBAO->get_yuanbao(me) / 10));
		send_user(me, "%c%c%d", 0x45, 2, YUANBAO->get_yuanbao(me));

		send_user(me, "%c%w", 0x0d, MUSIC_GIVE);


		if ((seller = find_any_char(data[UID])) && seller != me)
		{
			MAILBOX->sys_mail(seller->get_id(), seller->get_number(), sprintf("Bạn đã bán thành công "HIY"%d KNB"NOR" với giá %d lượng. Hãy đến Nhân Viên Ký Gửi để nhận tiền...", tempValue, tempPrice));
		}

	}
}

void remove_item(object me, int id, int amountKNB) {

	switch (amountKNB)
	{
	case 100:
		updateStatus(me, FILE_DATA_100, id);
		break;
	case 200:
		updateStatus(me, FILE_DATA_200, id);
		break;
	default:
		updateStatus(me, FILE_DATA_50, id);
		break;
	}
}

int isExist(int id, int amountKNB) {
	int i, sizeFile;
	string* line, * data, newContents = "", fileData, path;

	switch (amountKNB)
	{
	case 100:
		path = FILE_DATA_100;
		break;
	case 200:
		path = FILE_DATA_200;
		break;
	default:
		path = FILE_DATA_50;
		break;
	}

	if (!file_exist(path)) {
		return;
	}

	fileData = read_file(path);

	if (strlen(fileData) < 2) {
		return;
	}

	line = explode(fileData, "\n");

	for (i = 0, sizeFile = sizeof(line); i < sizeFile; i++)
	{
		data = explode(line[i], ":");

		if (id == to_int(data[ID])) {
			if (to_int(data[TIME]) < time() || to_int(data[STATUS]) == 2) {
				return -1;
			}

			return 1;
		}
	}

	return 0;
}

void show_data(object me, string path) {
	int i, sizeFile;
	string* line, * data, newContents = "", fileData;

	if (!file_exist(path)) {
		return;
	}

	fileData = read_file(path);

	if (strlen(fileData) < 2) {
		return;
	}

	line = explode(fileData, "\n");

	for (i = 0, sizeFile = sizeof(line); i < sizeFile; i++)
	{
		data = explode(line[i], ":");

		if (to_int(data[TIME]) < time() || to_int(data[STATUS]) == 2) {
			continue;
		}

		send_user(me, "%c%c%d%d%d%d", 0x92, 2, to_int(data[ID]), to_int(data[KNB]), to_int(data[PRICE]), to_int(data[TIME]));
	}
}

void show_list(object me) {
	int amountKNB;
	amountKNB = me->get("consign");

	switch (amountKNB)
	{
	case 100:
		show_data(me, FILE_DATA_100);
		break;
	case 200:
		show_data(me, FILE_DATA_200);
		break;
	default:
		show_data(me, FILE_DATA_50);
		break;
	}

	send_user(me, "%c%c%d", 0x45, 2, YUANBAO->get_yuanbao(me));
	me->set_pay_money_buy_item(0);

}

void get_money(object me, int id) {
	remove(me, FILE_DATA_50, id);
	remove(me, FILE_DATA_100, id);
	remove(me, FILE_DATA_200, id);
}

void cancel(object me, int id) {
	int i, sizeFile, tempValue, tempPrice, tempSellerID, flag = 0;
	string* line, * data, newContents = "", fileData, path;


	path = FILE_DATA_50;

	if (!file_exist(path)) {
		return;
	}

	fileData = read_file(path);

	if (strlen(fileData) < 2) {
		return;
	}

	line = explode(fileData, "\n");

	for (i = 0, sizeFile = sizeof(line); i < sizeFile; i++)
	{
		data = explode(line[i], ":");

		if (id == to_int(data[ID])) {
			tempSellerID = to_int(data[UID]);
			tempValue = to_int(data[KNB]);
			tempPrice = to_int(data[PRICE]);
			flag = 1;
			continue;
		}

		newContents += line[i] + "\n";
	}

	if (flag == 1) {
		rm(path);
		write_file(path, newContents);
	}
	else {
		flag = 0;
		newContents = "";
		path = FILE_DATA_100;

		if (!file_exist(path)) {
			return;
		}

		fileData = read_file(path);

		if (strlen(fileData) < 2) {
			return;
		}

		line = explode(fileData, "\n");

		for (i = 0, sizeFile = sizeof(line); i < sizeFile; i++)
		{
			data = explode(line[i], ":");

			if (id == to_int(data[ID])) {
				tempSellerID = to_int(data[UID]);
				tempValue = to_int(data[KNB]);
				tempPrice = to_int(data[PRICE]);
				flag = 1;
				continue;
			}

			newContents += line[i] + "\n";
		}

		if (flag == 1) {
			rm(path);
			write_file(path, newContents);
		}
		else {
			flag = 0;
			newContents = "";
			path = FILE_DATA_200;

			if (!file_exist(path)) {
				return;
			}

			fileData = read_file(path);

			if (strlen(fileData) < 2) {
				return;
			}

			line = explode(fileData, "\n");

			for (i = 0, sizeFile = sizeof(line); i < sizeFile; i++)
			{
				data = explode(line[i], ":");

				if (id == to_int(data[ID])) {
					tempSellerID = to_int(data[UID]);
					tempValue = to_int(data[KNB]);
					tempPrice = to_int(data[PRICE]);
					flag = 1;
					continue;
				}

				newContents += line[i] + "\n";
			}

			if (flag == 1) {
				rm(path);
				write_file(path, newContents);
			}
		}
	}

	if (tempSellerID > 0 && tempValue > 0 && tempPrice > 0) {

		YUANBAO->add_yuanbao(me, tempValue * 10);
		log_file("buycard.dat", sprintf("[cancel] %s %s(%d) thu hồi %d KNB giá %d\n", short_time(), me->get_id(), me->get_number(), tempValue, tempPrice));
		send_user(me, "%c%s", ';', sprintf("Bạn thu hồi "HIY"%d"NOR" lượng từ Ký gửi KNB！", tempValue));
		send_user(me, "%c%w", 0x0d, MUSIC_EXCHANGE);
		return;
	}

}

void buy_item(object me, int id) {
	int valueToBuy = me->get("consign");
	int isValid = 0;
	
	isValid = isExist(id, valueToBuy);
	if (isValid > 0) {
		remove_item(me, id, valueToBuy);
		send_user(me, "%c%c%c", 0x92, 1, 2);
		show_list(me);
	}
	else if (isValid < 0) {
		notify("Đã bán hoặc đã hết hạn!");
		return;
	}
	else {
		return;
	}

}

void sync(object me) {

}

int main(object me, string arg)
{
	mapping	list;
	int value, time, price, i, j, size;
	string* key, file, desc, name, legend, result;
	object item;
	int* prices;
	
	if (!arg)
	{
		return 1;
	}

	sync(me);

	if (me->get_pay_money_buy_item() > 0)
	{
		send_user(me, "%c%s", '!', "Yêu cầu của bạn đang được xử lý, vui lòng đợi...");
		return 1;
	}

	key = explode(arg, " ");
	switch (key[0])
	{
	case "sale":
	case "sale2":
		if (sizeof(key) != 4) return;
		if (sscanf(arg, "%s %d %d %d", result, value, time, price) != 4) return 1;
		if (value != 50 && value != 100 && value != 200)
		{
			send_user(me, "%c%s", '!', "Mệnh giá không hợp lệ!");
			return 1;
		}
		time /= 3600;
		if (time != 8 && time != 12 && time != 24)
		{
			send_user(me, "%c%s", '!', "Thời gian ký gửi không hợp lệ");
			return 1;
		}
		if (price < 10000)
		{
			send_user(me, "%c%s", '!', "Giá trị tối thiểu là 10.000 lượng");
			return 1;
		}
		if (price % 1000)
		{
			send_user(me, "%c%s", '!', "Giá trị phải là bội số của 1000");
			return 1;
		}
		if (key[0] == "sale")
		{
			result = sprintf("Bạn có chắc chắn ký gửi "HIR "%d Kim Bảo" NOR " với giá bán" HIR " %d lượng" NOR " không?\n", value, price);
			result += sprintf(ESC "Đồng ý\nconsign sale2 %d %d %d\n", value, time * 3600, price);
			result += ESC "Hủy bỏ\n";
			send_user(me, "%c%c%w%s", ':', 3, 0, result);
			return;
		}

		if (YUANBAO->get_yuanbao(me) < (value * 10)) {
			notify("Khoảng dư không đủ!");
			return;
		}

		log_file("buycard.dat", sprintf("%s %s(%d) Ký gửi %d Kim bảo giá %d thời gian %d\n", short_time(), me->get_id(), me->get_number(), value, price, time));
		
		me->set_pay_money_buy_item(1);

		if (YUANBAO->get_yuanbao(me) > (value * 10)) {
			add_to_record(me, value, price, time * 3600);
			YUANBAO->add_yuanbao(me, value * 10 * (-1));
		}

		me->set_pay_money_buy_item(0);

		break;
	case "list":
		me->set_pay_money_buy_item(1);

		if (sizeof(key) != 2) return;
		value = to_int(key[1]);
		me->set("consign", value);
		send_user(me, "%c%c%c", 0x92, 1, 2);
		show_list(me);
		me->set_pay_money_buy_item(0);

		break;
	case "buy":
		me->set_pay_money_buy_item(1);

		if (sizeof(key) != 2) return;
		value = to_int(key[1]);
		//tell_user(me, "id %d", value);
		buy_item(me, value);
		
		me->set_pay_money_buy_item(0);
		break;
	case "status":
		me->set_pay_money_buy_item(1);
		search_history(me);
		me->set_pay_money_buy_item(0);
		break;
	case "cancel":
		me->set_pay_money_buy_item(1);
		if (sizeof(key) != 2) return;
		value = to_int(key[1]);

		cancel(me, value);

		me->set_pay_money_buy_item(0);
		
		break;
	case "get":
		me->set_pay_money_buy_item(1);

		if (sizeof(key) != 2) return;
		value = to_int(key[1]);

		get_money(me, value);
		search_history(me);

		me->set_pay_money_buy_item(0);

		break;
	}
	return 1;
}

void php_result(object me, string type, string result)
{
	string* key, consignString, *sellArray;
	int i, j, size, id, time, price, value, flag;
	if (me->get_pay_money_buy_item() != 8) return;
	log_file("cardphp.dat", sprintf("%s\n", result));

	switch (type)
	{
	case "1":
		if (MAIN_D->get_host_type() == 0)
			result = "ok:100";
		key = explode(result, ":");
		if (sizeof(key) != 2)
		{
			//send_user(me, "%c%s", '!', "Chuyển đổi thất bại！");
			return;
		}
		value = me->get("cardvalue");
		me->set("cardvalue", 0);
		switch (key[0])
		{
		case "ok":
			send_user(me, "%c%s", ';', sprintf("Bạn ký gửi thành công "HIR "%d"NOR " KNB, khấu trừ hệ thống"HIR " 1%% "NOR "Phí。", value));
			log_file("buycard.dat", sprintf("%s %s(%d) Yêu cầu bán\n", short_time(), me->get_id(), me->get_number()));
			send_user(me, "%c%c%d", 0x45, 2, to_int(key[1]));
			break;
		case "fail":
			switch (key[1])
			{
			case "1":
				send_user(me, "%c%s", ';', sprintf("KNB không đủ "HIR "%d"NOR " . Vui lòng quay lại sau!", value + 1));
				break;
			case "2":
				send_user(me, "%c%s", '!', "Trở nên quá 20！");
				break;
			case "98":
				send_user(me, "%c%s", '!', "Thông số ký gửi thẻ điểm Lỗi！");
				break;
			case "99":
				send_user(me, "%c%s", '!', "Lỗi không xác định");
				break;
			}
			break;
		default:
			send_user(me, "%c%s", '!', "Lỗi trả về giá trị cung cấp thẻ！");
			break;
		}
		break;
	case "2":

		value = me->get("consign");
		if (value == 0) value = 50;

		send_user(me, "%c%c%c", 0x92, 1, 2);
		show_list(me);

		break;

	case "3":	// 购买点卡
		if (MAIN_D->get_host_type() == 0)
			result = "ok:100";
		key = explode(result, ":");
		price = me->get_save("consigncash");
		i = me->get("buyvalue");
		if (sizeof(key) != 2)
		{
			//log_file("buycard.dat", sprintf("%s %s(%d) 购买点卡花费%d失败\n", short_time(), me->get_id(), me->get_number(), price));
			//me->add_cash(price);
			//send_user(me, "%c%s", '!', "点卡购买失败！");
			return;
		}
		switch (key[0])
		{
		case "ok":
			//log_file("buycard.dat", sprintf("%s %s(%d) 购买点卡花费%d成功\n", short_time(), me->get_id(), me->get_number(), price));
			me->delete_save("consigncash");
			send_user(me, "%c%s", ';', sprintf("你已成功购买了%d点元宝！", i));
			"/inh/user/mail"->sys_mail(me->get_id(), me->get_number(), sprintf("你成功购买了%d点的元宝，对应元宝已充入您的账号中！谢谢您的惠顾，欢迎下次光临。", i));
			send_user(me, "%c%c%d", 0x45, 2, to_int(key[1]));
			value = me->get("consign");
			if (value > 0) send_user(me, "%c%c%d%d%d%d", 0x92, 2, value, 0, 0, 0);
			break;
		case "fail":
			//log_file("buycard.dat", sprintf("%s %s(%d) 购买点卡花费%d失败\n", short_time(), me->get_id(), me->get_number(), price));
			//me->add_cash(price);
			switch (key[1])
			{
			case "1":
				//send_user(me, "%c%s", '!', "点卡无效！");
				break;
			case "2":
				//send_user(me, "%c%s", '!', "点卡已经Giao dịch！");
				break;
			case "3":
				//send_user(me, "%c%s", '!', "点卡已经过期！");
				break;
			case "4":
				//send_user(me, "%c%s", '!', "不能用同一个帐号转帐");
				break;
			case "98":
				//send_user(me, "%c%s", '!', "点卡购买参数错误！");
				break;
			case "99":
				//send_user(me, "%c%s", '!', "未知错误。");
				break;
			}
			break;
		default:
			//log_file("buycard.dat", sprintf("%s %s(%d) 购买点卡花费%d失败\n", short_time(), me->get_id(), me->get_number(), price));
			//me->add_cash(price);
			//send_user(me, "%c%s", '!', "点卡购买返回值错误！");
			break;
		}
		break;

		//Status
	case "4":		// 寄售查询
		/*if (MAIN_D->get_host_type() == 0)
			result = "123:999999:0:200:10000\n124:999999:1:200:20000\n125:999999:2:200:30000";
		if (result[0..4] == "fail:")
		{
			switch (result[5.. < 1])
			{
			case "1":
				send_user(me, "%c%c%c", 0x92, 1, 3);
				break;
			case "98":
				send_user(me, "%c%s", '!', "错误的参数！");
				break;
			case "99":
				send_user(me, "%c%s", '!', "未知错误。");
				break;
			default:
				send_user(me, "%c%s", '!', "寄售查询返回值错误！");
				break;
			}
			break;
		}*/


		//key = explode(result, "\n");
		//size = sizeof(key);
		//send_user(me, "%c%c%c", 0x92, 1, 3);
		//for (i = 0; i < size; i++)
		//{
		//	if (sscanf(key[i], "%d:%d:%d:%d:%d", id, time, flag, value, price) == 5)
		//	{
		//		if (flag < 0) flag = 0;
		//		if (flag > 2) flag = 0;
		//		send_user(me, "%c%c%d%d%d%d%d", 0x92, 3, id, value, price, time, flag);
		//	}
		//}

		
		break;
	case "5":
	case "6":
		if (MAIN_D->get_host_type() == 0)
		{
			if (type == "5")
				result = "okgold:100";
			else
				result = "okmoney:100";
		}
		key = explode(result, ":");
		i = me->get("buyvalue");
		if (sizeof(key) != 2)
		{
			send_user(me, "%c%s", '!', "点卡取回失败！");
			return;
		}
		switch (key[0])
		{
		case "okgold":
			send_user(me, "%c%s", '!', "赎回点卡成功！");
			log_file("buycard.dat", sprintf("%s %s(%d) 赎回点卡成功\n", short_time(), me->get_id(), me->get_number()));
			send_user(me, "%c%c%d", 0x45, 2, to_int(key[1]));
			if (i > 0) send_user(me, "%c%c%d%d%d%d%d", 0x92, 3, value, 0, 0, 0, 0);
			break;
		case "okmoney":
			send_user(me, "%c%s", '!', "取回点卡出售所得成功！");
			me->add_cash(to_int(key[1]));
			log_file("buycard.dat", sprintf("%s %s(%d) 取回点卡收益%d\n", short_time(), me->get_id(), me->get_number(), to_int(key[1])));
			//			send_user(me, "%c%c%d", 0x45, 2, to_int(key[1]) );
			if (i > 0) send_user(me, "%c%c%d%d%d%d%d", 0x92, 3, value, 0, 0, 0, 0);
			break;
		case "fail":
			switch (key[1])
			{
			case "1":
				send_user(me, "%c%s", '!', "Không tồn tại！");
				break;
			case "2":
				send_user(me, "%c%s", '!', "Thẻ điểm đã được đổi！");
				break;
			case "3":
				send_user(me, "%c%s", '!', "Mua lại hoàn hảo！");
				break;
			case "98":
				send_user(me, "%c%s", '!', "Tham số không chính xác！");
				break;
			case "99":
				send_user(me, "%c%s", '!', "Lỗi không xác định");
				break;
			}
			break;
		default:
			send_user(me, "%c%s", '!', "Nhấn vào để mua lại lỗi giá trị trả về！");
			break;
		}
		break;
	}
}

int set_reset_time(int i)
{
	reset_time = i;
}

int get_reset_time() { return reset_time; }