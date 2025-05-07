#include <public.h>
#include <time.h>
#include <action.h>
#include <effect.h>
#include <cmd.h>
#include <music.h>

//inherit SAVE_F;
//#define SAVE_FILE       "data/city/consign" SAVE_EXTENSION

inherit DBASE_F;
inherit SAVE_F;

void SAVE_BINARY() { }
string get_save_file() { return "data/city/consign" SAVE_EXTENSION; }

static mapping cardlist = ([
	50:([]),
		100 : ([]),
		200 : ([]),
]);

int reset_time = 0;

static int* cur_reset = ({ 0, 0, 0 });


void create()
{
	restore();
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

		log_file("buycard.dat", sprintf("%s %s(%d) Ký gửi %d Kim bảo giá %d thời gian %d\n", short_time(), me->get_id(), me->get_number(), value, price, time));
		me->set_pay_type(7);
		me->set_buy_item_cmd_string("1");
		me->set_pay_money_buy_item(1);
		me->set("cardvalue", value);

		//// DB_ONLINE
		// db_user_pay(me, sprintf("%s:80\n"
		// 	"GET http:/""/%s/ctrade/sell.php?t=%s&u=%d&o=%d&r=%d&h=%d&m=%d&g=%d&a=%d\r\n", MAIN_D->get_php_ip(),
		// 	MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), me->get_number(), MAIN_D->get_region(), MAIN_D->get_host(), value, price, time));
		
		// log_file("cardphp.dat", sprintf("%s:80\n"
		// 	"GET http:/""/%s/ctrade/sell.php?t=%s&u=%d&o=%d&r=%d&h=%d&m=%d&g=%d&a=%d\r\n", MAIN_D->get_php_ip(),
		// 	MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), me->get_number(), MAIN_D->get_region(), MAIN_D->get_host(), value, price, time));
		
		break;
	case "list":
		if (sizeof(key) != 2) return;
		value = to_int(key[1]);
		if (value != 50 && value != 100 && value != 200)
		{
			send_user(me, "%c%s", '!', "Mệnh giá không hợp lệ");
			return 1;
		}
		// 检查是否需要重新查询
		if (value == 50) j = 0;
		else
			if (value == 100) j = 1;
			else j = 2;
		if (reset_time > 0)
		{
			if (time() < cur_reset[j] + reset_time)
			{
				send_user(me, "%c%c%c", 0x92, 1, 2);
				list = cardlist[value];
				key = keys(list);
				size = sizeof(key);
				if (size == 0)
				{
					return 1;
				}
				for (i = 0; i < size; i++)
				{
					send_user(me, "%c%c%d%d%d%d", 0x92, 2, to_int(key[i]), value, list[key[i]][0], list[key[i]][1]);
				}
				return 1;
			}
		}
		me->set_pay_type(7);
		me->set("consign", value);
		me->set_buy_item_cmd_string("2");
		me->set_pay_money_buy_item(1);

		/// DB_ONLINE
		// db_user_pay(me, sprintf("%s:80\n"
		// 	"GET http:/""/%s/ctrade/query.php?g=%d\r\n", MAIN_D->get_php_ip(),
		// 	MAIN_D->get_php_ip(), value));
		// log_file("cardphp.dat", sprintf("%s:80\n"
		// 	"GET http:/""/%s/ctrade/query.php?g=%d\r\n", MAIN_D->get_php_ip(),
		// 	MAIN_D->get_php_ip(), value));

		break;
	case "buy":
		if (sizeof(key) != 2) return;
		value = to_int(key[1]);
		prices = cardlist[50][sprintf("%d", value)];
		i = 50;
		if (prices == 0)
		{
			prices = cardlist[100][sprintf("%d", value)];
			i = 100;
		}
		if (prices == 0)
		{
			prices = cardlist[200][sprintf("%d", value)];
			i = 200;
		}
		if (prices == 0)
		{
			send_user(me, "%c%s", '!', "Ký gửi đã hết hạn");
			return 1;
		}
		if (me->get_cash() < prices[0])
		{
			send_user(me, "%c%s", ';', "Ngươi không đủ ngân lượng！");
			return 1;
		}
		me->add_cash(-prices[0]);
		me->set_save("consigncash", prices[0]);
		log_file("buycard.dat", sprintf("%s %s(%d) mua %d giá %d\n", short_time(), me->get_id(), me->get_number(), value, prices[0]));
		me->set_pay_type(7);
		me->set_buy_item_cmd_string("3");
		me->set_pay_money_buy_item(1);
		me->set("buyvalue", i);
		me->set("consign", value);
		
		/// DB_ONLINE
		// db_user_pay(me, sprintf("%s:80\n"
		// 	"GET http:/""/%s/ctrade/buy.php?t=%s&u=%d&o=%d&r=%d&h=%d&i=%d\r\n", MAIN_D->get_php_ip(),
		// 	MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), me->get_number(), MAIN_D->get_region(), MAIN_D->get_host(), value));
		// log_file("cardphp.dat", sprintf("%s:80\n"
		// 	"GET http:/""/%s/ctrade/buy.php?t=%s&u=%d&o=%d&r=%d&h=%d&i=%d\r\n", MAIN_D->get_php_ip(),
		// 	MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), me->get_number(), MAIN_D->get_region(), MAIN_D->get_host(), value));
		
		break;
	case "status":
		me->set_pay_type(7);
		me->set_buy_item_cmd_string("4");
		me->set_pay_money_buy_item(1);

		/// DB_ONLINE
		// db_user_pay(me, sprintf("%s:80\n"
		// 	"GET http:/""/%s/ctrade/status.php?t=%s&u=%d&o=%d&r=%d\r\n", MAIN_D->get_php_ip(),
		// 	MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), me->get_number(), MAIN_D->get_region()));
		// log_file("cardphp.dat", sprintf("%s:80\n"
		// 	"GET http:/""/%s/ctrade/status.php?t=%s&u=%d&o=%d&r=%d\r\n", MAIN_D->get_php_ip(),
		// 	MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), me->get_number(), MAIN_D->get_region()));
		
		break;
	case "cancel":
		if (sizeof(key) != 2) return;
		value = to_int(key[1]);
		me->set_pay_type(7);
		me->set_buy_item_cmd_string("5");
		me->set_pay_money_buy_item(1);
		me->set("consign", value);

		/// DB_ONLINE
		// db_user_pay(me, sprintf("%s:80\n"
		// 	"GET http:/""/%s/ctrade/checkout.php?t=%s&u=%d&o=%d&r=%d&i=%d\r\n", MAIN_D->get_php_ip(),
		// 	MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), me->get_number(), MAIN_D->get_region(), value));
		// log_file("cardphp.dat", sprintf("%s:80\n"
		// 	"GET http:/""/%s/ctrade/checkout.php?t=%s&u=%d&o=%d&r=%d&i=%d\r\n", MAIN_D->get_php_ip(),
		// 	MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), me->get_number(), MAIN_D->get_region(), value));
		
		break;
	case "get":
		if (sizeof(key) != 2) return;
		value = to_int(key[1]);
		me->set_pay_type(7);
		me->set_buy_item_cmd_string("6");
		me->set_pay_money_buy_item(1);
		me->set("consign", value);

		/// DB_ONLINE
		// db_user_pay(me, sprintf("%s:80\n"
		// 	"GET http:/""/%s/ctrade/checkout.php?t=%s&u=%d&o=%d&r=%d&i=%d\r\n", MAIN_D->get_php_ip(),
		// 	MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), me->get_number(), MAIN_D->get_region(), value));
		// log_file("cardphp.dat", sprintf("%s:80\n"
		// 	"GET http:/""/%s/ctrade/checkout.php?t=%s&u=%d&o=%d&r=%d&i=%d\r\n", MAIN_D->get_php_ip(),
		// 	MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), me->get_number(), MAIN_D->get_region(), value));

		break;
	}
	return 1;
}

void php_result(object me, string type, string result)
{
	string* key;
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
			send_user(me, "%c%s", '!', "Chuyển đổi thất bại！");
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
		if (MAIN_D->get_host_type() == 0)
			result = "123:99999999:12000";
		if (result[0..4] == "fail:")
		{
			switch (result[5.. < 1])
			{
			case "1":
				send_user(me, "%c%c%c", 0x92, 1, 2);
				break;
			case "98":
				send_user(me, "%c%s", '!', "错误的参数！");
				break;
			case "99":
				send_user(me, "%c%s", '!', "未知错误。");
				break;
			default:
				send_user(me, "%c%s", '!', "点卡查询返回值错误！");
				break;
			}
			break;
		}
		value = me->get("consign");
		if (value == 0) value = 50;
		if (value == 50) j = 0;
		else
			if (value == 100) j = 1;
			else j = 2;
		cur_reset[j] = time();
		key = explode(result, "\n");
		size = sizeof(key);
		send_user(me, "%c%c%c", 0x92, 1, 2);
		cardlist[value] = ([]);
		for (i = 0; i < size; i++)
		{
			if (sscanf(key[i], "%d:%d:%d", id, time, price) == 3)
			{
				if (MAIN_D->get_host_type() == 0) time = time() + 4 * 3600;
				cardlist[value][sprintf("%d", id)] = ({ price, time });
				send_user(me, "%c%c%d%d%d%d", 0x92, 2, id, value, price, time);
			}
		}
		break;
	case "3":	// 购买点卡
		if (MAIN_D->get_host_type() == 0)
			result = "ok:100";
		key = explode(result, ":");
		price = me->get_save("consigncash");
		i = me->get("buyvalue");
		if (sizeof(key) != 2)
		{
			log_file("buycard.dat", sprintf("%s %s(%d) 购买点卡花费%d失败\n", short_time(), me->get_id(), me->get_number(), price));
			me->add_cash(price);
			send_user(me, "%c%s", '!', "点卡购买失败！");
			return;
		}
		switch (key[0])
		{
		case "ok":
			log_file("buycard.dat", sprintf("%s %s(%d) 购买点卡花费%d成功\n", short_time(), me->get_id(), me->get_number(), price));
			me->delete_save("consigncash");
			send_user(me, "%c%s", ';', sprintf("你已成功购买了%d点元宝！", i));
			"/inh/user/mail"->sys_mail(me->get_id(), me->get_number(), sprintf("你成功购买了%d点的元宝，对应元宝已充入您的账号中！谢谢您的惠顾，欢迎下次光临。", i));
			send_user(me, "%c%c%d", 0x45, 2, to_int(key[1]));
			value = me->get("consign");
			if (value > 0) send_user(me, "%c%c%d%d%d%d", 0x92, 2, value, 0, 0, 0);
			break;
		case "fail":
			log_file("buycard.dat", sprintf("%s %s(%d) 购买点卡花费%d失败\n", short_time(), me->get_id(), me->get_number(), price));
			me->add_cash(price);
			switch (key[1])
			{
			case "1":
				send_user(me, "%c%s", '!', "点卡无效！");
				break;
			case "2":
				send_user(me, "%c%s", '!', "点卡已经Giao dịch！");
				break;
			case "3":
				send_user(me, "%c%s", '!', "点卡已经过期！");
				break;
			case "4":
				send_user(me, "%c%s", '!', "不能用同一个帐号转帐");
				break;
			case "98":
				send_user(me, "%c%s", '!', "点卡购买参数错误！");
				break;
			case "99":
				send_user(me, "%c%s", '!', "未知错误。");
				break;
			}
			break;
		default:
			log_file("buycard.dat", sprintf("%s %s(%d) 购买点卡花费%d失败\n", short_time(), me->get_id(), me->get_number(), price));
			me->add_cash(price);
			send_user(me, "%c%s", '!', "点卡购买返回值错误！");
			break;
		}
		break;
	case "4":		// 寄售查询
		if (MAIN_D->get_host_type() == 0)
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
		}
		key = explode(result, "\n");
		size = sizeof(key);
		send_user(me, "%c%c%c", 0x92, 1, 3);
		for (i = 0; i < size; i++)
		{
			if (sscanf(key[i], "%d:%d:%d:%d:%d", id, time, flag, value, price) == 5)
			{
				if (flag < 0) flag = 0;
				if (flag > 2) flag = 0;
				send_user(me, "%c%c%d%d%d%d%d", 0x92, 3, id, value, price, time, flag);
			}
		}
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
	save();
}

int get_reset_time() { return reset_time; }