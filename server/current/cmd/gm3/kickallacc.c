
#include <ansi.h>
#include <cmd.h>

// 函数：命令处理
int main(object me, string arg)
{
	object* user;
	string result;
	int i, size;
	object who;

	if (is_player(me))
	{
		notify("Bạn không có đủ quyền。");
		return 1;
	}

	if (arrayp(user = USER_D->get_user()))
	{
		size = sizeof(user);
		result = sprintf("Bây giờ người chơi có %d：\n", size);
		if (size < 60)
		{
			for (i = 0; i < size; i++) {
				if (!(who = find_player(sprintf("%d", user[i]->get_number()))))
				{
					return 1;
				}
				
				if (me->get_security_class() < who->get_security_class())
				{
					return 1;
				}

				tell_user(me, "Bạn sẽ đuổi " + who->get_name() + " ra khỏi trò chơi。");

				//result += who->get_name() + " ";

				if (who != me)
				{
					QUIT_CMD->main(who, "");
				}
				
			}

			tell_user(me, result);
		}
	}
	else    tell_user(me, "Chúng tôi không có bất kỳ người chơi。");


	return 1;
}
