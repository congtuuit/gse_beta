#include <ansi.h>
#include <public.h>

// Biến: Danh sách tệp bộ sưu tập
string* FileTable = ({
		"/item/97/9701",
		"/item/97/9702",
		"/item/97/9703",
		"/item/97/9704",
		"/item/97/9705",
		"/item/97/9706",
		"/item/97/9707",
		"/item/97/9708",
		"/item/97/9709",
		"/item/97/9710",
		"/item/97/9711",
		"/item/97/9712",
		"/item/97/9713",
		"/item/97/9714",
		"/item/97/9715",
		"/item/97/9716",
		"/item/97/9717",
		"/item/97/9720",
		"/item/97/9721",
		"/item/97/9722",
		"/item/97/9723",
		"/item/97/9724",
		"/item/97/9725",
		"/item/97/9726",
		"/item/97/9727",
		"/item/97/9728",
		"/item/97/9729",
		"/item/97/9730",
		"/item/97/9731",
		"/item/97/9732",
		"/item/97/9733",
		"/item/97/9750",
		"/item/97/9751",
		"/item/97/9752",
		"/item/97/9753",
		"/item/97/9754",
		"/item/97/9755",
		"/item/97/9770",
		"/item/97/9771",

	});

int sizeof_file = sizeof(FileTable);

// Biến: Danh sách tên bộ sưu tập

string* NameTable = ({
		"Đại Học",
		"Trung Dung",
		"Luận Ngữ",
		"Mạnh Tử",
		"Thi Kinh",
		"Thượng Thư",
		"Lễ Ký",
		"Chu Dịch",
		"Xuân Thu",
		"Hiên Viên Bản Ký",
		"Thập Châu Ký",
		"Chu Thư",
		"Cửu Ca",
		"Thiên Vấn",
		"Cổ Kính Ký",
		"Quy Tàng",
		"Long Ngư Hà Đồ",
		"Tứ Quý Đồ·Xuân",
		"Tứ Quý Đồ·Hạ",
		"Tứ Quý Đồ·Thu",
		"Tứ Quý Đồ·Đông",
		"Tả Ý Hoa Thảo·Mai",
		"Tả Ý Hoa Thảo·Lan",
		"Tả Ý Hoa Thảo·Cúc",
		"Tả Ý Hoa Thảo·Trúc",
		"Hà Đường Nguyệt Sắc Đồ",
		"Bích Thủy Uyên Ương Đồ",
		"Vân Sơn Phi Bộc Đồ",
		"Bách Phụng Triều Hoàng Đồ",
		"Thiên Nữ Tán Hoa Đồ",
		"Bạch Trạch Đồ",
		"Long Văn Ngọc Bội",
		"Phụng Văn Ngọc Bội",
		"Hổ Văn Ngọc Bội",
		"Tước Văn Ngọc Bội",
		"Uyên Ương Ngọc Bội",
		"Hòa Thị Bích",
		"Thanh Hoa Ngư Văn Bàn",
		"Thanh Đồng Cổ Kính",
	});

int sizeof_name = sizeof(NameTable);

string get_collect_file() { return FileTable[random(sizeof_file)]; }

string get_collect_name() { return NameTable[random(sizeof_name)]; }

void do_look(object who, object npc)
{
	string cmd = "";
	if (who->get_save_2("qixi.flag") == 3 && time() < "sys/party/qixi"->get_qixi_time())
		cmd = sprintf(ESC "Tìm kiếm một nữ Hoàng.\ntalk %x# qixi.1\n", getoid(npc));
	if (time() < "sys/party/qixi"->get_qixi_time() && (who->get_save_2("qixi.flag") == 8 || who->get_save_2("qixi.flag") == 9 || who->get_save_2("qixi.flag") == 10 || who->get_save_2("qixi.flag") == 11))
		cmd = sprintf(ESC "Dũng cảm ơn trời（2）\ntalk %x# qixi.1\n", getoid(npc));
	if (sizeof(npc->get_2("good")) != 0)
	{
		if (who->get_save_2("mastertask.type") != 7 || who->get_save_2("mastertask.status") == 99)
			send_user(who, "%c%c%w%s", ':', 3, npc->get_char_picid(),
				sprintf("%s：\n    Hey, chỉ là số phận của người có thể tìm thấy tôi, kể từ khi cô có thể đến với tôi quá nhanh, dường như là số phận của tôi, tôi có một cái gì đó, bạn có thể lựa chọn nó!Tôi không bao giờ tiết kiệm những người đang có nghĩa là phải." + "/quest/word"->get_normal_word(npc) + "\n"
					ESC "Kinh doanh\nlist %x#\n"
					ESC "Để lại.\nCLOSE\n", npc->get_name(), getoid(npc)) + cmd);
		else
			send_user(who, "%c%c%w%s", ':', 3, npc->get_char_picid(),
				sprintf("%s：\n    Hey, chỉ là số phận của người có thể tìm thấy tôi, kể từ khi cô có thể đến với tôi quá nhanh, dường như là số phận của tôi, tôi có một cái gì đó, bạn có thể lựa chọn nó!Tôi không bao giờ tiết kiệm những người đang có nghĩa là phải." + "/quest/word"->get_normal_word(npc) + "\n"
					ESC "Có được rượu.\ntalk %x# accept_task.1\n"
					ESC "Kinh doanh\nlist %x#\n"
					ESC "Để lại.\nCLOSE\n", npc->get_name(), getoid(npc), getoid(npc)));
	}
	else
	{
		if (who->get_save_2("mastertask.type") != 7 || who->get_save_2("mastertask.status") == 99)
			send_user(who, "%c%c%w%s", ':', 3, npc->get_char_picid(),
				sprintf("%s：\n    Hey, chỉ là số phận của người có thể tìm thấy tôi, kể từ khi cô có thể đến với tôi quá nhanh, dường như là số phận của tôi, tôi có một cái gì đó, bạn có thể lựa chọn nó!Tôi không bao giờ tiết kiệm những người đang có nghĩa là phải.。" + "/quest/word"->get_normal_word(npc) + "\n"
					ESC "Để lại.\nCLOSE\n", npc->get_name(), getoid(npc)) + cmd);
		else
			send_user(who, "%c%c%w%s", ':', 3, npc->get_char_picid(),
				sprintf("%s：\n    Hey, chỉ là số phận của người có thể tìm thấy tôi, kể từ khi cô có thể đến với tôi quá nhanh, dường như là số phận của tôi, tôi có một cái gì đó, bạn có thể lựa chọn nó!Tôi không bao giờ tiết kiệm những người đang có nghĩa là phải.。" + "/quest/word"->get_normal_word(npc) + "\n"
					ESC "Có được rượu.\ntalk %x# accept_task.1\n"
					ESC "Để lại.\nCLOSE\n", npc->get_name(), getoid(npc), getoid(npc)));
	}

}
