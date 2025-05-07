//Ket noi kenh CHAT
//Update kenh
#include <ansi.h>

void connectKenhChat(object me) {
	"/cmd/debug/update"->main(me,"sys/party/chat_channel");
}

void partyK1(object me) {
	"/cmd/debug/update"->main(me, "sys/party/chat_channel");

}

int main(object me, string arg)
{
	object obj;
	string file, err;

	connectKenhChat(me);
	tell_user(me, sprintf(HIR"%s", "Đã kết nối kênh chat"));

	"/sys/sys/callout"->run();

	return 1;
}
