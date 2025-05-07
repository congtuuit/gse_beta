
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>
#include <music.h>

inherit OFFICER;

int is_seller() { return 72022; }
int is_self_look() { return 1; }
int get_char_picid() { return 9031; }
void do_welcome(string arg);

void create()
{
	set_name("Shop Kho Báu");

	set_2("good", ([
		"01":"/item/pet/11",
			"02" : "/item/pet/21",
			"03" : "/item/pet/thomenh",
	]));

	

	setup();
}
void do_look(object who)
{
	string result = "";
	int id = getoid(this_object());


	send_user(who, "%c%c%w%s", ':', 3, this_object()->get_char_picid(),
		this_object()->get_name() + " :\n Hoan nghênh! Chiến Quốc Loạn Thế thiên hạ đệ nhất bảo vật quý hiếm trên nhân gian, chỉ cần ngươi giao cho ta Chiến Quốc Điểm Phiếu thì sẽ được tưởng thưởng hậu hĩ\n"
		+ sprintf(ESC"Đổi vật phẩm\nlist2 %x#\n", id)
		+ ESC"Rời khỏi");
}

