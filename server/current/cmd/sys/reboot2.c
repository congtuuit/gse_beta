
#include <ansi.h>

int main(string code, string arg)
{
	int time;
	if (code != "autoshutdown") return 0;

	if (!arg) time = 60;
	else time = to_int(arg);
	if (time == 0) time = 60;

	USER_D->user_channel(sprintf(HIR "Trò chơi sẽ tắt sau %d phút.", time));

	call_out("do_reboot", 60, time);

	return 1;
}

private void do_reboot(int min)
{
	remove_call_out("do_reboot");

	if (min <= 1) {
		USER_D->user_channel(HIR "Đang khởi động lại trò chơi, xin hãy đợi 5 phút và sau đó đăng nhập lại.");
		//"/cmd/base/quanlykenh"->baotri("on");
	}

	if (min == 2 || min <= 1) {
		"/cmd/base/savedata"->kickAll();
		"/cmd/base/savedata"->main();
	}

	if (--min)
	{
		USER_D->user_channel(sprintf(HIR "Trò chơi sẽ tắt sau %d phút.", min));
		call_out("do_reboot", 60, min);
	}
	else
	{

		"/cmd/base/savedata"->kickAll();
		"/cmd/base/savedata"->main();
		USER_D->save_all_data();

		shutdown(0);
	}
}
