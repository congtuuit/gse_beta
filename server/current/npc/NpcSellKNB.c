
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// 函数：小贩识别
int is_seller() { return 7003; }
int is_self_look() { return 1; }

// 函数：获取人物造型
int get_char_picid() { return 5502; }

// 函数：构造处理
void create()
{
        set_name("Ký Gửi KNB");
		set_2("talk", ([
			"gift":(: do_gift:),
		]));

        set_2( "good", ([
				"01" : "/item/100/10051",

        ]) );

        setup();
}

void do_look(object who)
{
	int id = getoid(this_object());
		send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), sprintf(" %s :\n Ngươi cần ký gửi KNB phải không?\n"

		ESC HIC"Ta muốn ký gửi KNB\ntalk %x# gift.1\n"
		ESC HIY"Thu mua Kim Bảo\nlist %x#\n"
		ESC"Rời khỏi", get_name(), id));
}

void do_gift(string arg)
{
	object me = this_object();
	__FILE__->do_gift2(me, arg);
}

void do_gift2(object me, string arg)
{
	int flag, id, i, p, iTime, iDay, iGio, rate, l, tien;
	object who, item, item1, item2, item3;
	string *nTmp, cFile, cTmp, cFinal, result;
	mixed *mxTime;
	iTime = time();
	mxTime = localtime(iTime);
	iDay = mxTime[TIME_YDAY];
	iGio = mxTime[TIME_HOUR];

	who = this_player();
	id = getoid(me);
	flag = to_int(arg);

	switch (flag)
	{
		case 1:
			break;
	}
}
