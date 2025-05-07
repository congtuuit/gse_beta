
#include <ansi.h>

int main(object me, string arg)
{
	int time;
	if (me != this_player(1) || is_player(me))
	{
		notify("Bạn không có đủ quyền hạn");
		return 1;
	}
	if (!arg) time = 10;
	else time = to_int(arg);
	if (time == 0) time = 10;
	USER_D->user_channel(sprintf(HIR "Trò chơi sẽ tắt sau %d phút.", time));

	call_out("do_reboot", 60, time);

	return 1;
}

private void do_reboot(int min)
{
	remove_call_out("do_reboot");

	if (min == 1) {
		USER_D->user_channel(HIR "Đang khởi động lại trò chơi, xin hãy đợi 5 phút và sau đó đăng nhập lại.");
		//"/cmd/base/quanlykenh"->baotri("on");
		"/cmd/base/savedata"->kickAll();
	}

	if (min == 2 || min == 1) {
		"/cmd/base/savedata"->main();
	}

	if (--min)
	{
		USER_D->user_channel(sprintf(HIR "Trò chơi sẽ tắt sau %d phút.", min));
		call_out("do_reboot", 60, min);
	}
	else
	{
		//USER_D->user_channel(HIR "Khởi động lại trò chơi, xin hãy đợi một phút và sau đó đăng nhập lại.");

		"/cmd/base/savedata"->kickAll();
		"/cmd/base/savedata"->main();

		USER_D->save_all_data();
		shutdown(0);
	}
}
