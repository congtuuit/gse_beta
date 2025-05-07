#include <ansi.h>
#include <effect.h>
#include <skill.h>
#include <action.h>

// 函数：命令处理
int main(object me, string arg)
{
	object* user;
	string result, ipList = "";
	int i, size;

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
				if (user[i]) {
					
					user[i]->delete_save("tuzi");
					user[i]->delete_save("tuziHalloween");
					user[i]->delete_save("ChristmasPoint");
					
					result = sprintf("%s%s%s(%d) "HIY"point[%d]"NOR", ",
						result, i % 8 ? "" : "\n", user[i]->get_name(), user[i]->get_number(), user[i]->get_save("tuzi"));
				}
			}
				
		}

		tell_user(me, "Đã xóa");
	}
	else    tell_user(me, "Chúng tôi không có bất kỳ người chơi。");

	return 1;
}
