
#include <ansi.h>
#include <equip.h>
#include <city.h>
#include <map.h>
#include <task.h>

int main(object me, string arg)
{
	object who;
	string* line, buff, chars;
	int i, j, size, value;

	if (is_player(me))
	{
		notify("Bạn không đủ quyền lực");
		return 1;
	}
	
	if (sscanf(arg, "%s", chars) == 1) {
		if (!(who = find_any_char(chars)))
		{
			notify("Không tìm thấy người này");
			return 1;
		}

		if (who) {
			
			"cmd/debug/E500"->main(me, chars);
			who->Upgrade();
			tell_user(me, "upgraded %d", who->get_level());
		}
	}

	return 1;
}
