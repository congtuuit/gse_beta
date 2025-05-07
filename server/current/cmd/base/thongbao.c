#include <ansi.h>

int main(object me, string arg)
{
	object who;
	string chars, content;

	if (!is_god(me)) //Nếu người gõ lệnh không phải là GOD (GM có quyền hạn cao nhất, kiểu như Administrator)
	{
		return 1; //Kết thúc
	}
	if (!arg) //Nếu nội dung thông báo trống
	{
		notify("Nội dung thông báo phải có ít nhất 1 ký tự");
		return 1; //Kết thúc
	}

	if (sscanf(arg, "%s? %s", chars, content) != 3) {
		if (!(who = find_any_char(chars)))
		{
			notify("Không tìm thấy người này");
			return 1;
		}

		tell_user(who, sprintf(HIR"%s", content));

		tell_user(me, sprintf("Bạn gửi tin đến %s: %s", who->get_name(), content));
		return 1; //Kết thúc
	}
}
