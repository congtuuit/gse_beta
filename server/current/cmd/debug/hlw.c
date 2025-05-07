
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

// 函数：命令处理
int main(object me, string arg)
{
	object who;
	int i, size, a1, a2, a3, a4;
	if (is_player(me))
	{
		notify("Ngươi không đủ quyền hạn");
		return 1;
	}
	if (arg && !(who = find_any_char(arg)))
	{
		notify("Không tìm thấy người này");
		return 1;
	}

	
	who->set_save_2("maphalloween.today", 0);
	who->set_save_2("maphalloween.go", 1);
	
	who->set_save_2("halloween.status", 2);
	tell_user(who, "Hoàn thành nhiệm vụ Halloween");

	return 1;
}
