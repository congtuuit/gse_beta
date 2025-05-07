
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

mapping	allgood = ([
	"good1":([
			"01":"/item/sell/0061",
			//"02":"/item/common/loalon",
			
			// "03":"/item/nghe/kynangrenduc",
			// "04":"/item/nghe/kynangmaymac",
			// "05" : "/item/nghe/kynangdieukhac",
			// "06" : "/item/final/33/1770",
			// "07":"/item/std/6007",
			// "08" : "/item/test2/TheGiamGia",
			// "09" : "/item/trangbi110/thanbinhpho/1100",
			// "10" : "/item/trangbi110/thanbinhpho/2100",
			// "11" : "/item/trangbi110/thanbinhpho/3100",
			// "12" : "/item/trangbi110/thanbinhpho/4100",
			// "13" : "/item/trangbi110/thanbinhpho/5100",
			// "14" : "/item/trangbi110/thanbinhpho/6100",
			// "15" : "/item/sell/lenhbaithap",

			//"09":"/item/common/tinhthach",
			//"10" : "/item/common/huong",
			//"03" : "/npc/event/PhoBan/item/manhngoc",
			//"04" : "/item/ride/newRide/hoasulenh",
			//"05" : "/item/ride/newRide/thientuong",
			//"06" : "/item/ride/newRide/holy",
			//"04" : "/npc/event/PhoBan/item/0",
			//"05" : "/npc/event/PhoBan/item/1",
			//"06" : "/npc/event/PhoBan/item/2",
			//"07" : "/npc/event/PhoBan/item/3",
			//"08" : "/npc/event/PhoBan/item/4",
			//"09" : "/item/SpItem/Keo",
			//"13" : "/item/event/halloween/buahangma",
			//"13" : "/item/test2/GiayGoiHoa",
			//"10" : "/item/sell/lenhbaithap",

			//Giang sinh
			//"11" : "item/event/tet/phao",
			//"12" : "item/event/valentine/resetnv",
			//"14" : "item/04/0414",
			//"15" : "item/event/giangsinh/cautuyet",

			//"15" : "/item/sell/lenhbaiphucma",
			//"15" : "/item/event/2011/su",
			//"14" : "/item/the/thedoiten",
	]),
		"good2": ([
				"01":"/item/test/tuihoangkimtanthucap20",
				"02" : "/item/08/0001",
				"03" : "/item/08/0002",
				"04" : "/item/08/0003",
				"05" : "/item/08/0004",
				"06" : "/item/sell/0002",
				"07" : "/item/sell/0004",
				"08" : "/item/91/9166",
				"09" : "/item/sell/0044",
				"10" : "/item/sell/0200",
				"11" : "/item/sell/0201",
				"12" : "/item/sell/0202",
				"13" : "/item/mop/9988", // nhat nguyet tinh than

				// "09" : "/item/common/box/ruongdong/key",
				// "10" : "/item/common/box/trangbi/key",
				// "11" : "/item/common/box/tukim/key",
				// "12" : "/item/91/9178",
				// "13" : "/item/sell/0006",

				// "14" : "/item/mop/9988",
				// "15" : "/item/sell/0044",
				// "16" : "/item/test2/AXP",
				// "17" : "/item/common/ketdanthach",
				
		]),
			"good3": ([

				"01":"/item/sell/0025",
					//"02" : "/item/test2/ThanThuSongNgu",
					"02" : "/item/08/shuiping",
					
					//"03" : "/item/test2/TuiThanThu",
					//"04" : "/item/test2/TuiThuCuoi",
					//"05" : "/item/test2/TuiThanThuHoangDao",

					"03" : "/item/sell/TinhNguyenDon/74216",
					"04" : "/item/sell/TinhNguyenDon/74217",
					"05" : "/item/sell/TinhNguyenDon/74218",
					"06" : "/item/sell/TinhNguyenDon/74219",
					"07" : "/item/sell/TinhNguyenDon/74220",
					"08" : "/item/sell/TinhNguyenDon/74225",
					"09" : "/item/sell/TinhNguyenDon/74226",
					"10" : "/item/sell/TinhNguyenDon/74230",
					"11" : "/item/sell/TinhNguyenDon/74231",
					"12" : "/item/sell/TinhNguyenDon/74232",
					"13" : "/item/sell/TinhNguyenDon/74233",
					"14" : "/item/sell/TinhNguyenDon/74234",
					"15" : "/item/sell/TinhNguyenDon/74235",
					"16" : "/item/sell/TinhNguyenDon/74236",
					"17" : "/item/sell/TinhNguyenDon/74201",
					"18" : "/item/sell/TinhNguyenDon/74202",
					"19" : "/item/sell/TinhNguyenDon/74203",
					"20" : "/item/sell/TinhNguyenDon/74204",
					"21" : "/item/sell/TinhNguyenDon/74205",
					"22" : "/item/sell/TinhNguyenDon/74206",
					"23" : "/item/sell/TinhNguyenDon/74207",
					"24" : "/item/sell/TinhNguyenDon/74208",
					"25" : "/item/sell/TinhNguyenDon/74209",
					"26" : "/item/sell/TinhNguyenDon/74210",
					"27" : "/item/sell/TinhNguyenDon/74211",
					"28" : "/item/sell/TinhNguyenDon/74212",
					"29" : "/item/sell/TinhNguyenDon/74213",
					"30" : "/item/sell/TinhNguyenDon/74214",
					"31" : "/item/sell/TinhNguyenDon/74137",
					"32" : "/item/sell/TinhNguyenDon/74238",
					"33" : "/item/sell/TinhNguyenDon/74239",
					"34" : "/item/sell/TinhNguyenDon/74124",
					"35" : "/item/sell/TinhNguyenDon/74125",
					"36" : "/item/sell/TinhNguyenDon/74126",
					"37" : "/item/sell/TinhNguyenDon/74129",
					"38" : "/item/sell/TinhNguyenDon/74131",

					/*"39" : "/item/sell/TinhNguyenDon/74212",
					"40" : "/item/sell/TinhNguyenDon/74213",
					"41" : "/item/sell/TinhNguyenDon/74214",*/

			]),
				"good4":  ([
					/*
						"01" : "/item/sell/9301",
						"02" : "/item/sell/9302",
						"03" : "/item/sell/9303",
						"04" : "/item/sell/9304",
						"05" : "/item/sell/9305",
						"06" : "/item/sell/9306",
						"07" : "/item/sell/9307",
						"08" : "/item/sell/9308",
						"09" : "/item/sell/9309",
						"10" : "/item/sell/9310",
					*/
						//"02" : "/item/TuiLinhThach/NgauNhien/1_3",
						"01" : "/item/00/0062",
						"02" : "/item/00/0063",
						"03" : "/item/00/0064",
						"04" : "/item/00/0065",
						"05" : "/item/test2/LTDB",

						"06" : "/item/sell/0015",
						"07" : "/item/sell/0016",
						"08" : "/item/sell/0017",
						"09" : "/item/sell/0018",
						"10" : "/item/sell/0019",

						//tay diem
						"11" : "/item/sell/0015",
						"12" : "/item/sell/0016",
						"13" : "/item/sell/0017",
						"14" : "/item/sell/0018",
						"15" : "/item/sell/0019",

				]),
					"good5": ([
						    "01":"/item/sell/0045",
							"02" : "/item/sell/0012",
							"03" : "/item/test2/TuiQuaVoSong",
							"04" : "/item/test2/TuiPhapBao",
							"05" : "/item/sell/0031",
							"06" : "/item/sell/0026",
							"07" : "/item/sell/0027",
							"08" : "/item/sell/ruongdutru",
							"09" : "/item/sell/0030",
							"10" : "/item/sell/0029",
							"11" : "/item/sell/0033",
							"12" : "/item/sell/0043",
							"13" : "/item/sell/0042",
							//"06" : "/item/SpItem/dauChucPhucSP",
							//"15" : "/item/common/box/trangbi/1",
							//"16" : "/item/std/8000",
							//"17" : "/item/std/8005",
							//"18" : "/item/common/thetrangbi",
							//"19" : "/item/test2/bbbzzz/CongHienBangPhai",

					]),
						"good6": ([
								"01" : "/item/std/0004", // trang nguyen phuc
								"02" : "/item/std/0005",

								"03" : "/item/trangphuc/ngoaitrang/03", // le phuc
								"04" : "/item/trangphuc/ngoaitrang/04",

								"05":"/item/100/10059", // ngoai trang chinh xac
								"06" : "/item/100/11059",

								/*"07" : "/item/trangphuc/ngoaitrang/1002",
								"08" : "/item/trangphuc/ngoaitrang/1003",
								"09" : "/item/trangphuc/ngoaitrang/1004",
								"10" : "/item/trangphuc/ngoaitrang/1005",
								"11" : "/item/trangphuc/ngoaitrang/1007",
								"12" : "/item/trangphuc/ngoaitrang/1008",

								"13" : "/item/trangphuc/ngoaitrang/11053",
								"14" : "/item/trangphuc/ngoaitrang/11052",
								"15" : "/item/trangphuc/ngoaitrang/11055",
								"16" : "/item/trangphuc/ngoaitrang/11057",
								"17" : "/item/trangphuc/ngoaitrang/11058",*/

								//Le phuc do
								/*"18" : "/item/trangphuc/ngoaitrang/2001",
								"19" : "/item/trangphuc/ngoaitrang/2101",*/
						]),

							//----------------这个只是在国庆卖的一个特殊物品，而且是不显示的------------------------------------
								/*"good99": ([
									"01":"/item/mop/9003",
										"02" : "/item/mop/9006",
								]),*/
								//--------------------------------------------------------------------------------------------
]);
mapping	gonggao = ([
	"Đầu lên cung cấp":"Từ ngày 11 Tháng 11 năm 2020, những ai mua phôi (bất kể nạp phương pháp), mỗi duy nhất nạp 100 phôi có thể nhận thêm một Tử Sâm Đơn, nếu một nạp thỏi tiền vượt quá 100, mỗi hơn 100 sẽ cho thêm một Tử Sâm Đơn(+ 2000 tiềm năng sau khi sử dụng）",
		"Trách nhiệm trực tiếp cung cấp" : "Từ ngày 11 năm 2020, những ai mua phôi qua thẻ ngân hàng trực tiếp phí chức năng của các Chiến Bang chính thức trang web có thể nhận thêm trò chơi đạo cụ theo số nạp.Xem ece cho một mô tả chi tiết của sự event.mop.com liên quan thông báo sự kiện.",
]);


void send_gonggao(object me);

mapping	goodprice = ([]);

void create()
{
	string cpp, * line;
	int i, size, a, b, c, d, ret;
	cpp = read_file("/quest/good.dat");
	if (!cpp)
	{
		return;
	}
	line = explode(cpp, "\n");
	size = sizeof(line);
	if (size == 0) return;
	for (i = 0; i < size; i++)
	{
		if (sscanf(line[i], "%d %d %d %d", a, b, c, d) != 4)
		{
			continue;
		}
		goodprice[a] = ({ b, c, d });
	}
}

int main(object me, string arg)
{
	mapping	list;
	int iVip, i, size, price, type, what, total, amount, count, p, x, y, z, itemid;
	string* key, file, desc, name, legend;
	object item;
	int* prices;
	//	iVip = me->get_vip();
	//	if (time()<iVip) iVip =	1;
	//	else iVip = 0;

	if (!arg)
	{
		tell_user(me, "Mở cửa hàng kho báu ");
		send_user(me, "%c%c%c", 0x45, 1, 0);

		if (MAIN_D->get_host_type() == 1 || MAIN_D->get_host_type() == 1000)
		{
			send_user(me, "%c%c%d", 0x45, 2, "sys/sys/test_db"->get_yuanbao(me));
		}
		else
			if (MAIN_D->get_host_type() == 6012)
			{
				me->set_pay_money_buy_item(1);
				me->set_pay_type(5);
				me->set_buy_item_cmd_string("  ");

				// db_user_pay(me, sprintf("210.48.144.183:2500\n"
				// 	"21,\"%s\",%d\r\n", me->get_real_id(), me->get_acountno()));
			}
			else
				if (me->get_pay_money_buy_item() == 0 && !me->get("phpbalance"))
				{
					me->set_pay_money_buy_item(1);
					me->set_pay_type(5);
					me->set_buy_item_cmd_string("  ");
					
					// db_user_pay(me, sprintf("%s:80\n"
					// 	"GET http:/""/%s/querybalance.php?t=%s&u=%d\r\n", MAIN_D->get_php_ip(),
					// 	MAIN_D->get_php_ip(), short_time_2(), me->get_acountid()));
							
				}

		//send_user(me, "%c%c%d", 0x45, 2, 999);

		arg = "2";
	}
	if (arg == "notice")
	{
		send_gonggao(me);
		return 1;
	}
	key = explode(arg, " ");
	if (sizeof(key) == 1)
	{
		list = allgood["good" + arg];
		if (!mapp(list)) return	1;
		key = keys(list);
		size = sizeof(key);
		if (size == 0) return 1;
		key = sort_array(key, 1);
		send_gonggao(me);
		for (i = 0; i < size; i++)
		{
			file = list[key[i]];
			desc = file->get_short();
			prices = goodprice[file->get_item_number()];
			if (sizeof(prices) == 3)
			{
				if (iVip == 0) price = prices[0];
				else
				{
					if (prices[2] > 0) price = prices[2];
					else price = prices[1];
				}
				if (prices[2] > 0 && prices[2] < price) 	//存在促销价
					price = prices[2];

				if (desc == 0) desc = file->get_desc();
				name = sprintf("%-40s%s", file->get_name(), desc);
				send_user(me, "%c%c%c%c%d%d%d%w%w%c%c%s", 0x45, 3, to_int(arg), to_int(key[i]), prices[0], prices[1], price,
					file->get_picid_2(), file->get_amount(), 0, file->get_item_color(), name);
			}
			else
			{
				price = file->get_item_value();
				if (iVip == 0) price = file->get_item_value();
				else
				{
					if (file->get_item_value_3() > 0)	price = file->get_item_value_3();
					else price = file->get_item_value_2();
				}
				if (desc == 0) desc = file->get_desc();
				name = sprintf("%-40s%s", file->get_name(), desc);
				send_user(me, "%c%c%c%c%d%d%d%w%w%c%c%s", 0x45, 3, to_int(arg), to_int(key[i]), file->get_item_value(), file->get_item_value_2(), price,
					file->get_picid_2(), file->get_amount(), 0, file->get_item_color(), name);
			}
		}


		return 1;
	}

	if (key[0] == "desc")
	{
		if (sizeof(key) != 3) return 1;
		type = to_int(key[1]);
		what = to_int(key[2]);

		if (!stringp(file = allgood[sprintf("good%d.%02d", type, what)])) return 1;
		send_user(me, "%c%c%c%c%s", 0x45, 4, type, what, file->get_desc());
		return 1;
	}

	if (sscanf(arg, "%d %d %d", type, what, total) != 3) return 1;
	if (total < 1)
	{
		notify("Ngài mua đích cái sổ đắc lớn hơn 0.");
		return 1;
	}
	if (MAIN_D->get_host_type() == 1 || MAIN_D->get_host_type() == 1000)
	{
		list = allgood[sprintf("good%d", type)];
		if (!mapp(list))
		{
			notify("Đạo cụ này không có bán ra");
			return 1;
		}
		file = list[sprintf("%02d", what + 1)];
		if (!stringp(file))
		{
			notify("Không có đạo cụ bán ra");
			return 1;
		}
		if ((amount = USER_INVENTORY_D->can_carry_3(me, load_object(file))) < 1)
		{
			notify("Hãy chừa 1 chỗ trống");
			return 1;
		}
		if ((price = file->get_item_value()) < 1)
		{
			notify("Không có đạo cụ bán ra");
			return 1;
		}
		if (file->question_before_buy(me, arg) == 1)
			return 1;
		if (file->get_sell_amount() && amount > file->get_sell_amount())
			amount = file->get_sell_amount();
		if (total > amount) total = amount;
		prices = goodprice[file->get_item_number()];
		if (sizeof(prices) == 3)
		{
			price = prices[0];
			if (iVip > 0)
			{
				if (prices[2] > 0)  price = prices[2];
				else
					if (prices[1] > 0)  price = prices[1];
			}
			if (prices[2] > 0 && prices[2] < price)
				price = prices[2];
		}
		else
		{
			price = file->get_item_value();
			if (iVip > 0)
			{
				if (file->get_item_value_3() > 0)	 price = file->get_item_value_3();
				else
					if (file->get_item_value_2() > 0)	 price = file->get_item_value_2();
			}
		}
		price *= total;
		if ("sys/sys/test_db"->get_yuanbao(me) < price)
		{
			notify("Ngươi không có đủ Kim Nguyên Bảo");
			return 1;
		}
		"sys/sys/test_db"->add_yuanbao(me, -price);
		send_user(me, "%c%c%d", 0x45, 2, "sys/sys/test_db"->get_yuanbao(me));
		"/sys/sys/id"->add_buy(total, price);
		if (file->give_item_to_user(me))
			return;
		else if (file->is_combined())
		{
			if (amount = USER_INVENTORY_D->carry_combined_item(me, load_object(file), total))
			{

				item = new(file);
				item->set_hide(0);
				item->set_amount(amount);
				count = "/sys/sys/count"->add_buy_count(1);
				itemid = "/sys/sys/id"->add_max_itemid(1);
				item->set_user_id(sprintf("#%d#", itemid));
				log_file("itemid.dat", sprintf("%s %d %s %s\n", short_time(), itemid, item->get_name(), "/sys/item/item"->get_pawn_save_string(item)));
				legend = sprintf("Đã mua @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", "Ngân Khố", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), amount, item->get_user_id(), get_z(me), get_x(me), get_y(me));
				"/sys/user/cmd"->log_item(legend);
				if (p = item->move2(me))
				{
					item->add_to_user(p);
				}
				else if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
				{
					item->add_to_scene(z, p / 1000, p % 1000);
				}
			}
		}
		else for (i = 0; i < total; i++)
		{
			item = new(file);
			item->set_hide(0);
			count = "/sys/sys/count"->add_buy_count(1);
			itemid = "/sys/sys/id"->add_max_itemid(1);
			item->set_user_id(sprintf("#%d#", itemid));
			log_file("itemid.dat", sprintf("%s %d %s %s\n", short_time(), itemid, item->get_name(), "/sys/item/item"->get_pawn_save_string(item)));
			legend = sprintf("Đã mua @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", "Ngân Khố", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(me), get_x(me), get_y(me));
			"/sys/user/cmd"->log_item(legend);
			if (p = item->move2(me))
			{
				item->add_to_user(p);
			}
			else if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
			{
				item->add_to_scene(z, p / 1000, p % 1000);
			}
		}
		log_file("buyitem.dat", sprintf("%s %s(%d) mua %s thành công %d %d\n", short_time(), me->get_id(), me->get_number(), file->get_name(), total, price));
		send_user(me, "%c%s", '!', sprintf("Bạn đã mua %s .", file->get_name()));
		return 1;
	}

	if (!me->get_pay_money_buy_item())
	{
		if (me->get("paycount") < 0)
		{
			notify("Ngươi không đủ Kim Nguyên Bảo,nếu ngươi đã bổ sung hãy reset trò chơi rồi lại mua đạo cụ");
			return 1;
		}
		list = allgood[sprintf("good%d", type)];
		if (!mapp(list))
		{
			notify("Không có đạo cụ bán ra");
			return 1;
		}
		file = list[sprintf("%02d", what + 1)];
		if (!stringp(file))
		{
			notify("Không có đạo cụ bán ra");
			return 1;
		}
		if ((amount = USER_INVENTORY_D->can_carry_3(me, load_object(file))) < 1)
		{
			notify("Bạn mang nhiều thứ quá.");
			return 1;
		}
		if ((price = file->get_item_value()) < 1)
		{
			notify("Không có đạo cụ bán ra");
			return 1;
		}
		if (file->question_before_buy(me, arg) == 1)
			return 1;
		if (file->get_sell_amount() && amount > file->get_sell_amount())
			amount = file->get_sell_amount();
		if (total > amount) total = amount;
		prices = goodprice[file->get_item_number()];
		if (sizeof(prices) == 3)
		{
			price = prices[0];
			if (iVip > 0)
			{
				if (prices[2] > 0)  price = prices[2];
				else
					if (prices[1] > 0)  price = prices[1];
			}
			if (prices[2] > 0 && prices[2] < price)
				price = prices[2];
		}
		else
		{
			price = file->get_item_value();
			if (iVip > 0)
			{
				if (file->get_item_value_3() > 0)	 price = file->get_item_value_3();
				else
					if (file->get_item_value_2() > 0)	 price = file->get_item_value_2();
			}
		}
		price *= total;
		me->set_pay_money_buy_item(1);
		me->set_pay_type(6);
		me->set_buy_item_cmd_string(sprintf("%d %d %d", type, what, total));
		log_file("buyitem.dat", sprintf(" %s %s ( %d ) đã mua %s %d \n", short_time(), me->get_id(), me->get_number(), file->get_name(), total));
		
		//// DB_ONLINE
		// if (MAIN_D->get_host_type() == 4 || MAIN_D->get_host_type() == 0)
		// {
		// 	db_user_pay(me, sprintf("%s:80\n"
		// 		"GET http:/""/%s/purchase.php?t=%s&u=%d&o=%d&n=%d&m=%d&c=%d&ip=%s&r=%d&h=%d\r\n", MAIN_D->get_php_ip(),
		// 		MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), me->get_number(), total, price, file->get_item_number(), get_ip_name(me), MAIN_D->get_region(), MAIN_D->get_host()));
		// }
		// else
		// 	if (MAIN_D->get_host_type() == 6012)
		// 	{
		// 		db_user_pay(me, sprintf("210.48.144.183:2500\n"
		// 			"22,\"%s\",%d,\"99\",99,%d,\"%d\",\"%d\",\"%s\",\"%s\"\r\n", me->get_real_id(), me->get_acountno(), price, "/sys/sys/id"->get_transid(), file->get_item_number(), file->get_name(), get_ip_name(me)));
		// 		"/sys/sys/id"->add_transid(1);
		// 	}
		// 	else
		// 		db_user_pay(me, sprintf("%s:80\n"
		// 			"GET /xq2/buy.php?id=%s&time=%d&region=%d&host=%d&item=%d&point=%d&ip=%s\r\n", MAIN_D->get_php_ip(),
		// 			rawurlencode(me->get_id()), time(), MAIN_D->get_region(), MAIN_D->get_host(), file->get_item_number(), price, get_ip_name(me)));	// 扣点！
		
		
		return 1;
	}
	if (me->get_pay_money_buy_item() == 8 && me->get_pay_type() == 6)    // Đã mua！
	{
		me->set_pay_money_buy_item(0);	  // Đã mua
		me->set_pay_type(0);

		list = allgood[sprintf("good%d", type)];
		if (!mapp(list))
		{
			notify("Không có đạo cụ bán ra");
			return 1;
		}
		file = list[sprintf("%02d", what + 1)];
		if (!stringp(file))
		{
			log_file("buyitem.dat", sprintf("%s %s(%d) không có mua đối tượng\n", short_time(), me->get_id(), me->get_number()));
			notify("Không có đạo cụ bán ra");
			return 1;
		}
		if ((price = file->get_item_value()) < 1)
		{
			log_file("buyitem.dat", sprintf("%s %s(%d) mua thương phẩm không đúng\n", short_time(), me->get_id(), me->get_number()));
			notify("Không có đạo cụ bán ra");
			return 1;
		}

		if ((amount = USER_INVENTORY_D->can_carry_3(me, load_object(file))) < 1)
		{
			log_file("buyitem.dat", sprintf("%s %s(%d) mua không đủ không vị\n", short_time(), me->get_id(), me->get_number()));
			notify("Hành trang không đủ chỗ trống");
			return 1;
		}
		prices = goodprice[file->get_item_number()];
		if (sizeof(prices) == 3)
		{
			price = prices[0];
			if (iVip > 0)
			{
				if (prices[2] > 0)  price = prices[2];
				else
					if (prices[1] > 0)  price = prices[1];
			}
			if (prices[2] > 0 && prices[2] < price)
				price = prices[2];
		}
		else
		{
			price = file->get_item_value();
			if (iVip > 0)
			{
				if (file->get_item_value_3() > 0)	 price = file->get_item_value_3();
				else
					if (file->get_item_value_2() > 0)	 price = file->get_item_value_2();
			}
		}
		if (file->get_sell_amount() && amount > file->get_sell_amount())
			amount = file->get_sell_amount();
		if (total > amount) total = amount;
		price *= total;
		"/sys/sys/id"->add_buy(total, price);
		if (file->give_item_to_user(me))
			return;
		else if (file->is_combined())
		{
			if (amount = USER_INVENTORY_D->carry_combined_item(me, load_object(file), total))
			{

				item = new(file);
				item->set_hide(0);
				item->set_amount(amount);
				count = "/sys/sys/count"->add_buy_count(1);
				itemid = "/sys/sys/id"->add_max_itemid(1);
				item->set_user_id(sprintf("#%d#", itemid));
				log_file("itemid.dat", sprintf("%s %d %s %s\n", short_time(), itemid, item->get_name(), "/sys/item/item"->get_pawn_save_string(item)));
				legend = sprintf("Đã mua @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", "Ngân Khố", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), amount, item->get_user_id(), get_z(me), get_x(me), get_y(me));
				"/sys/user/cmd"->log_item(legend);
				if (p = item->move2(me))
				{
					item->add_to_user(p);
				}
				else if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
				{
					item->add_to_scene(z, p / 1000, p % 1000);
				}
			}
		}
		else for (i = 0; i < total; i++)
		{
			item = new(file);
			item->set_hide(0);
			count = "/sys/sys/count"->add_buy_count(1);
			itemid = "/sys/sys/id"->add_max_itemid(1);
			item->set_user_id(sprintf("#%d#", itemid));
			log_file("itemid.dat", sprintf("%s %d %s %s\n", short_time(), itemid, item->get_name(), "/sys/item/item"->get_pawn_save_string(item)));
			legend = sprintf("Đã mua @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", "Ngân Khố", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(me), get_x(me), get_y(me));
			"/sys/user/cmd"->log_item(legend);
			if (p = item->move2(me))
			{
				item->add_to_user(p);
			}
			else if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
			{
				item->add_to_scene(z, p / 1000, p % 1000);
			}
		}
		log_file("buyitem.dat", sprintf(" %s %s ( %d ) đã mua %s thành công %d %d \n", short_time(), me->get_id(), me->get_number(), file->get_name(), total, price));
		send_user(me, "%c%s", '!', sprintf("Bạn đã mua %s .", file->get_name()));
		if (file->get_name() == "Túi quà Quốc Khánh") send_user(me, "%c%s", ';', "恭喜你成功购买了一份国庆疯狂Túi quà lớn，同时获得了"HIR "200元宝"NOR "，赶快去体验这个礼包带来的热闹国庆吧！");
	}
	else
	{
		if (me->get_pay_money_buy_item() > 0)
		{
			send_user(me, "%c%s", '!', "Đang xử lý, xin chờ 1 chút");
			return;
		}
	}
	return 1;
}

void send_gonggao(object me)
{
	int i, size;
	string* key;
	key = keys(gonggao);
	size = sizeof(key);
	for (i = 0; i < size; i++)
	{
		send_user(me, "%c%c%c%s", 0x45, 5, i + 1, key[i]);
		send_user(me, "%c%c%c%s", 0x45, 6, i + 1, gonggao[key[i]]);
	}
}