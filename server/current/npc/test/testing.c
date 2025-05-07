#include <npc.h>
#include <item.h>
#include <ansi.h>
#include <task.h>
#include <music.h>
#include <equip.h>
inherit OFFICER;

#define YUANBAO "sys/sys/test_db"

// 函数：获取人物造型
int get_char_picid() { return 5505; }

void do_welcome(string arg);

//构造初始化
void create()
{
	set_name("NPC Hỗ Trợ");
	set_2("talk", (["welcome":(:do_welcome:)]));
	setup();
}
void do_look(object who)
{
	string result;
	object me = this_object();

	result = sprintf(me->get_name() + ":\n    Ta có thể giúp được gì cho ngươi?\n");
	result += sprintf(ESC "Ta muốn nhận ngân lượng\ntalk %x# welcome.100\n", getoid(me));
	result += sprintf(ESC "Ta muốn nhận KNB\ntalk %x# welcome.110\n", getoid(me));
	result += sprintf(ESC "Rời khỏi");
	send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
}

void do_welcome(string arg)
{
	object me = this_object();
	__FILE__->do_welcome2(me, arg);
}

void do_welcome2(object me, string arg)
{
	int flag, z, x, y, level, * zxy;
	string* key, result, mapname;
	object who;

	who = this_player();
	who->set_time("talk", 0);
	level = who->get_level();
	if (!arg) return;
	key = explode(arg, " ");
	flag = to_int(key[0]);

	switch (flag)
	{
	case 100:
		who->add_cash(1000000);
		tell_user(who, ECHO"Bạn nhận được 1000000 lượng.");
		break;
	case 110:
		YUANBAO->add_yuanbao(who, 5000);
		tell_user(who, ECHO"Bạn nhận được 500 KNB.");
		break;

	}
}