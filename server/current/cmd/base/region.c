#include <ansi.h>

int main(object me, string arg)
{
	object who;
	string chars, content;

	if (!is_god(me)) //Nếu người gõ lệnh không phải là GOD (GM có quyền hạn cao nhất, kiểu như Administrator)
	{
		return 1; //Kết thúc
	}
	

	tell_user(me, "Kenh hien tai %d", MAIN_D->get_region());
	
}
