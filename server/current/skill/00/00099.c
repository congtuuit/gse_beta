
#include <ansi.h>
#include <skill.h>

#define THIS_PERFORM    00099
#define PF_START       "00099"
#define PF_NAME        "Hỗ trợ thi đấu"
string get_desc( object me ) 
{ 
	return "[ " PF_NAME " ]\n Tính năng hỗ trợ đấu giải\n ";
}

void dolook(object me) {
	string result;

	result = sprintf(PF_NAME + ":\nLựa chọn tính năng\n");
	result += sprintf(ESC HIC"Triệu tập thi đấu\npvpsp ? 1\n");
	result += sprintf(ESC HIY"THI ĐẤU\npvpsp @\n");
	result += sprintf(ESC "Kết thúc\npvpsp -\n");
	result += sprintf(ESC "Thoát.\nCLOSE\n");

	send_user(me, "%c%c%w%s", ':', 3, 0, result);
}

int main(object me, string arg)
{
	int mapId = 893;
	int z;

	z = get_z(me);
	if (z != mapId) {
		tell_user(me, HIR"Lệnh chỉ có thể sử dụng tại Minh Chủ Đài (893).");
	}
	else {
		dolook(me);
	}

	return 1;
}

int get_perform_type() { return ON_ME_7; }

void can_perform(object me)
{
	send_user(me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 1, 0, PF_NAME);
}

