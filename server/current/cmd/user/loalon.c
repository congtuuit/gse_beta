#include <ansi.h>

void chat_string(object who, string arg) {

	arg = sprintf("%s hét lớn: %s", who->get_name(), arg);
	send_user(CHAT_D->get_chat(), "%c%s", 0xA3, HIY + arg);
}

int main(object me, string arg)
{

	string currentUser, str;
	object who;

	if (!arg)
	{
		notify("Nội dung thông báo phải có ít nhất 1 ký tự");
		return 1;
	}

	if (sscanf(arg, "@ %s %s", str, currentUser) == 2)
	{
		
		if (!(who = find_any_char(currentUser)))
		{
			notify("Không tìm thấy người này");
			return 1;
		}

		TASK_LEGEND_D->check_task_item1(who, "Loa Lớn", 1);

		chat_string(who, str);

		return 1;
	}

	return 1;
}
