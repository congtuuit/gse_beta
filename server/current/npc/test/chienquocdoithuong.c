
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>
#include <music.h>

inherit OFFICER;

int is_seller() { return 72021; }
int is_self_look() { return 1; }
int get_char_picid() { return 8503; }
void do_welcome(string arg);

void create()
{
	set_name("Chiến Quốc Điểm Phiếu");
	set_2("good", ([
		//"01":"/item/common/box/tukim/item/manhthucuoi",
			//"02" : "/item/common/box/tukim/item/manhngocboi",
			"01" : "/item/common/box/tukim/item/tuitukim85",
			"02" : "/item/common/box/tukim/item/ve5sao",
			"03" : "/item/common/box/tukim/item/tuidacuonghoa5",
			"04" : "/item/mocnap/tuidoanthach1",
			"05" : "/item/common/tuinganluongrandom",

	]));

	set_2("talk", ([
		"welcome":(: do_welcome:),

	]));

	setup();
}
void do_look(object who)
{
	string result = "";
	int id = getoid(this_object());

	if (who->get_quest("hienvien.flag") == 0 || who->get_quest("hienvien.flag") <= 1 || who->get_quest("hienvien.flag") == 101 && who->get_save_2("hienvien.point") < 200)
	{
		result = sprintf(ESC HIY "Trợ giúp\ntalk %x# welcome.100\n", id);
	}

	if (who->get_save_2("hienvien.point") >= 200 && who->get_save_2("hienvien.point") < 500) {
		result = sprintf(ESC HIY "Lục Bảo Tinh Thạch\ntalk %x# welcome.200\n", id);
		result = sprintf(ESC HIY "Tứ Linh Vệ Hồn\ntalk %x# welcome.300\n", id);
	}


	if (who->get_save_2("hienvien.point") >= 500 && who->get_save_2("hienvien.point") < 1000) {
		result = sprintf(ESC HIY "Tiêu diệt Kinh Kha\ntalk %x# welcome.400\n", id);
	}

	if (who->get_save_2("hienvien.point") >= 1000) {
		result = sprintf(ESC HIY "Thăm hỏi Hạng Vũ\ntalk %x# welcome.500\n", id);
	}

	send_user(who, "%c%c%w%s", ':', 3, this_object()->get_char_picid(),
		this_object()->get_name() + " :\n Hoan nghênh! Chiến Quốc Loạn Thế thiên hạ đệ nhất bảo vật quý hiếm trên nhân gian, chỉ cần ngươi giao cho ta Chiến Quốc Điểm Phiếu thì sẽ được tưởng thưởng hậu hĩ\n"
		//+ result
		+ sprintf(ESC"Đổi vật phẩm\nlist2 %x#\n", id)
		//+ sprintf(ESC"Ghép thú cưỡi \ntalk %x# welcome.20\n", id)
		//+ sprintf(ESC"Ghép ngọc bội \ntalk %x# welcome.30\n", id)
		+ ESC"Rời khỏi");

	//tell_user(who, ECHO"Điểm hảo hữu: %d", who->get_save_2("hienvien.point"));
}

void do_welcome(string arg) { __FILE__->do_welcome_callout(this_object(), this_player(), arg); }


void do_welcome_callout(object me, object who, string arg)
{
	int flag, i, size, p;
	flag = to_int(arg);
	switch (flag)
	{
	case 20:
		break;
	case 30:
		break;

	case 100:
		if (who->get_quest("hienvien.flag") <= 1) 
		{
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(),
				sprintf("%s:\n    Trong trường hợp này, sau đó bạn sẽ đến Tang Laozi để tìm kiếm huyền thoại Hạt Giống Bí Ẩn! Nhân tiện, đưa gói này đến Tang Lao, hãy nhớ gói này, nhưng không được mở.!\n"
					ESC "Nhận nhiệm vụ\ntalk %x# welcome.101\n"
					ESC "Rời khỏi", me->get_name(), getoid(me)));
		}

		if (who->get_quest("hienvien.flag") == 101) 
		{
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(),
				sprintf("%s:\n    Trong trường hợp này, sau đó bạn sẽ đến Tang Laozi để tìm kiếm huyền thoại Hạt Giống Bí Ẩn! Nhân tiện, đưa gói này đến Tang Lao, hãy nhớ gói này, nhưng không được mở.!\n"
					ESC "Hoàn thành nhiệm vụ\ntalk %x# welcome.102\n"
					ESC "Rời khỏi", me->get_name(), getoid(me)));
		}

		break;
	case 101:
		if (who->get_quest("hienvien.flag") <= 1) 
		{
			who->set_quest("hienvien.flag", 101);
			send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_NEWITEMS, "Bá Vương");
			send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_NEWITEMS, 1, "Trợ giúp");
			send_user(who, "%c%s", '!', "Nhận nhiệm vụ Bá Vương——Trợ giúp");
		}
		break;
	case 102:
		if (who->get_quest("hienvien.flag") == 101)
		{
			if (who->get_save_2("hienvien.task") >= 1) 
			{
				who->set_save_2("hienvien.point", who->get_save_2("hienvien.point") + 1);
				who->set_quest("hienvien.flag", 0);
				who->set_save_2("hienvien.task", 0);

				send_user(who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_NEWITEMS, 1, "");
				send_user(who, "%c%c%c%w%s", 0x51, 1, 1, TID_NEWITEMS, "");

				send_user(who, "%c%s", ';', "Hoàn thành nhiệm vụ! Phần thưởng: 150.000 Exp Hảo hữu: +1");
				tell_user(who, ECHO"Điểm hảo hữu hiện tại: %d", who->get_save_2("hienvien.point"));
				send_user(who, "%c%w", 0x0d, MUSIC_TASK);
			}
			else {
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(),
					sprintf("%s:\n    Ngươi hoàn thành nhiệm vụ ta đã giao chưa?\n"
						ESC "Rời khỏi", me->get_name(), getoid(me)));
			}
		}
		break;

	
	}
}