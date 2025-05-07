
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

inherit DBASE_F;

object *userlist = ({});
string *ret = ({});
string get_exchange_urs_string_2(object me);

// 函数：命令处理
int main(object me, string arg)
{
	int i, size;
	object user;
	string result;

	size = sizeof(userlist);
	if (size == 0)
	{
		for (i = 0; i < 30; i++)
		{
			user = new(USER);
			user->set_id(sprintf("test%d", i + 1));
			userlist += ({user});
			ret += ({" "});
		}
	}
	size = sizeof(userlist);
	if (!arg)
	{
		for (i = 0; i < size; i++)
		{
			tell_user(me, sprintf("%d: %s\n", i + 1, ret[i]));
		}
		return;
	}
	switch (arg)
	{
	case "delete":
		for (i = 0; i < size; i++)
			destruct(userlist[i]);
		userlist = ({});
		ret = ({});
		tell_user(me, "删除完毕。");
		break;
	case "add":
		for (i = 0; i < 30; i++)
		{
			user = new(USER);
			user->set_id(sprintf("test%d", i + 1));
			userlist += ({user});
			ret += ({" "});
		}
		break;
	case "start":
		tell_user(me, "DEBUG。%s", sprintf("127.0.0.1"));

		db_user_authentic(me, "ten", "ok|11|11");
		tell_user(me, "DEBUG 2");
		result = get_exchange_urs_string_2(me);
		tell_user(me, "result >> " + result);

		// for (i = 0; i < size; i++)
		// {
		// 	tell_user(userlist[i], "DEBUG。");

		// 	db_user_authentic(userlist[i], "ten", sprintf(MAIN_D->get_php_ip() + ":80\n"
		// 																		 "GET /xq2/authentic.php?id=%s&passwd=1234567890&region=1&host=1\r\n",
		// 												  "ten"));
		// 	call_out("check_auth_result", 1, userlist[i], i);
		// }
		break;
	}

	return 1;
}

string get_exchange_urs_string_2(object me)
{
	string filename, content;
	filename = sprintf("/log/auth/%s.dat", me->get_id());
	if (!file_exist(filename))
		return "";

	content = read_file(filename);
	rm(filename);

	return content;
}

void check_auth_result(object me, int order)
{
	int size;
	string result = get_exchange_urs_string(me);
	if (result == "")
	{
		call_out("check_auth_result", 1, me, order);
		return;
	}
	size = sizeof(ret);
	if (order >= size)
		return;
	ret[order] = result;
}