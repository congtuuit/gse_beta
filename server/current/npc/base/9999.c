
#include <npc.h>
#include <cmd.h>
#include <ansi.h>

inherit SAVE_F;
inherit OFFICER;

static string* nCard = ({ "0010","0011","0050","0051","0052","0053","0101","0102","0150",
			"0151","0152","0200","0201","0202","0250","0251","0252","8011",
			"8010","0300","0301","0302","0303","0304","0350","0351","0352",
			"0400","0401","0402","0450","0500","0502","0550","0551","0552",
	});

#define SAVE_FILE       "data/city/diamond" SAVE_EXTENSION

int is_seller() { return 2; }

int get_char_picid() { return 5420; }

void reset_good();

void create()
{
	set_name("Thương Nhân Thần Bí");
	set_save("diamond_count", 100);
	setup();
	restore();
	reset_good();
	if (get_save("diamond_count") == 0)
	{
		set_save("diamond_count", 100);
		save();
	}
}


void reset()
{
	string buf;

	if (gone_time(get("reset_good")) < 60 * 29)
		return;

	//log_file("reset_good.txt",sprintf("%s 变身卡\n",short_time()));

	reset_good();
	if (MAIN_D->get_host_type() != 4)
		buf = "Người ta nói rằng những thương gia bí ẩn ở đất nước Chu có một  số thẻ chuyển dạng và đá pha lê mới để bán.！";
	else
		buf = "Người ta nói rằng những thương gia bí ẩn ở đất nước Chu có một mẻ đá tinh thể khác để bán！";
	CHAT_D->rumor_channel(0, CHAT + buf);
}

void reset_good()
{
	int i, size;
	string* nTmp = ({}), cTmp;
	object me = this_object();

	string* diamond = ({ "9301", "9302", "9303", "9304", "9305", "9306", "9307", "9308", "9309", "9310", });
	string* diamondgood = ({ });

	size = sizeof(diamond);

	for (i = 0; i < size; i++)
	{
		if (me->get_save_2("diamond." + diamond[i]) >= 105)
			me->add_save_2("diamond." + diamond[i], -5);
		else
			me->set_save_2("diamond." + diamond[i], 100);
	}

	set("reset_good", time());
	size = sizeof(nCard);
	while (sizeof(nTmp) < 3)
	{
		cTmp = nCard[random(size)];
		if (member_array(cTmp, nTmp) != -1)
			continue;
		nTmp += ({ cTmp });
	}
	while (sizeof(diamondgood) < 4)
	{
		cTmp = diamond[random(sizeof(diamond))];
		diamondgood += ({ cTmp });
		diamond -= ({ cTmp });
	}

	if (MAIN_D->get_host_type() == 4 || MAIN_D->get_host_type() == 2)
	{
		me->set_2("good", ([
			"01":"item/54/" + nTmp[0],
				"02" : "item/54/" + nTmp[1],
				"03" : "item/54/" + nTmp[2],
				"04" : "item/93/" + diamondgood[0],
				"05" : "item/93/" + diamondgood[1],
				"06" : "item/93/" + diamondgood[2],
				"07" : "item/93/" + diamondgood[3],
		]));

		me->set_2("list", ([
			"01":5,
				"02" : 5,
				"03" : 5,
				"04" : 5,
				"05" : 5,
				"06" : 5,
				"07" : 5,
		]));
	}
	else
	{
		me->set_2("good", ([
			"01":"item/54/" + nTmp[0],
				"02" : "item/54/" + nTmp[1],
				"03" : "item/54/" + nTmp[2],
				"04" : "item/93/" + diamondgood[0],
				"05" : "item/93/" + diamondgood[1],
				"06" : "item/93/" + diamondgood[2],
				"07" : "/item/sell/1026",
				"08" : "/item/sell/1027",
				
				//"09" : "/item/mop/0200",
				"09" : "/item/common/box/ruongdong/key",
				//"10" : "/item/mop/0201",
				"10" : "/item/common/box/trangbi/key",
				//"11" : "/item/mop/0202",
				"11" : "/item/common/box/tukim/key",
		]));

		me->set_2("list", ([
			"01":5,
				"02" : 5,
				"03" : 5,
				"04" : 5,
				"05" : 5,
				"06" : 5,
				"07" : 20,
				"08" : 20,
				"09" : 10,
				"10" : 10,
				"11" : 5,
		]));
	}
	me->save();
}

void do_look(object who)
{
	object npc = this_object();
	if (sizeof(npc->get_2("good")) != 0)
	{
		send_user(who, "%c%c%w%s", ':', 3, npc->get_char_picid(),
			sprintf("%s：\n    Chỉ những kẻ có số phận mới tìm được tôi. có vẻ như anh là người có số mạng của tôi. anh có thể chọn tôi có cái gì!Tôi không bao giờ keo kiệt với những người có số m ạng." + "/quest/word"->get_normal_word(npc) + "\n"
				ESC "Giao dịch\nlist %x#\n"
				ESC "Rời khỏi.\nCLOSE\n", npc->get_name(), getoid(npc)));
	}
	else
	{
		send_user(who, "%c%c%w%s", ':', 3, npc->get_char_picid(),
			sprintf("%s：\n    Trời ơi, anh t ới hơi trễ. bộ sưu tập cuối cùng của tôi vừa được mua bởi những người khác. có vẻ như số phận của chúng ta vẫn chưa tới. Đừng lo. chờ từ từ。" + "/quest/word"->get_normal_word(npc) + "\n"
				ESC "Rời khỏi.\nCLOSE\n", npc->get_name(), getoid(npc)));
	}

}