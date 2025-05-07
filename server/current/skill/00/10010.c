
#include <ansi.h>
#include <skill.h>

#define THIS_PERFORM    10010
#define PF_START       "10010"
#define PF_NAME        "Ẩn/ Hiện Kỹ Năng Nghề"

string get_desc( object me ) 
{ 
	return "[ " PF_NAME " ]\n Ẩn/ Hiện Kỹ Năng Nghề. Hạn chế tình trạng disconnect.\n ";
}

int main(object me, object who, int x, int y, string arg)
{
	int hide, p, i, z;
	object* objs, target;
	string strText;

	hide = me->get_save_2("hideSkill");

	switch (hide)
	{
		case 1:
			me->set_save_2("hideSkill", 0);
			strText = sprintf(HIC"Hiện"NOR);
			break;
		default:
			me->set_save_2("hideSkill", 1);
			strText = sprintf(HIC"Ẩn"NOR);
			break;
	}

	send_user(me, "%c%s", ';', sprintf("Đã %s Kỹ Năng Trợ Giúp. Vui lòng đăng nhập lại.", strText));

	return 1;
}

// 函数：获取指令类型
int get_perform_type() { return ON_ME_7; }

// 函数：能否使用指令
void can_perform(object me)
{
	send_user(me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 1, 0, PF_NAME);
}

