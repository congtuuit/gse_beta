
#include <npc.h>
#include <ansi.h>
#include <map.h>
#include <task.h>

inherit OFFICER;

void do_welcome(string arg);

// 函数：获取人物造型
int get_char_picid() { return 5201; }

// 函数：构造处理
void create()
{
	set_name("GM");
	setup();
}

void do_look(object who)
{
	int status;
	int time;
	string result;
	object me = this_object();
	time = "/cmd/gm/findgm"->get_save("gm_time");
	if (who->get_save("findgm") == time)
	{
		send_user(who, "%c%c%w%s", ':', 3, 5201,
			sprintf("%s：\n    Cảm ơn rất nhiều hôm nay, nhưng hãy để cho người khác có cơ hội này.\n"
				, me->get_name()));
		return;
	}
	send_user(who, "%c%c%w%s", ':', 3, 5201,
		sprintf("%s：\n    Cuối cùng cũng đến cứu tôi.Tôi muốn cảm ơn anh vì đã cứu mạng tôi.！\n"
			, me->get_name()));
	who->add_cash(30000);
	who->set_save("findgm", time);
	result = sprintf(HIY "%s Thành công cứu mạng GM，nhận phần thưởng 30000 Ngân lượng", who->get_name());
	USER_D->user_channel(result);
	me->remove_from_scene();
	destruct(me);
}
