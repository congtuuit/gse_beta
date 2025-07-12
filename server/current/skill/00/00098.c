//
//#include <ansi.h>
//#include <skill.h>
//
//#define THIS_PERFORM    00098
//#define PF_START       "00098"
//#define PF_NAME        "Sử dụng Quản Khố"
//
//// 函数：获取描述
//string get_desc( object me ) 
//{ 
//        return "[ " PF_NAME " ]\n Chức năng đặc biệt để mở ra Kho chứa đồ của Quản Khố.\n "; 
//}
//
//// 函数：命令处理
//int main( object me, object who, int x, int y, string arg )
//{
//	int type;
//	object * objs, target;
//	int i, size;
//		
//		if ( arg=="" )
//		{	
//        	
//	if (get_z(me)==001)
//	objs = children("/npc/base/0001");
//	else if (get_z(me)==010)
//	objs = children("/npc/base/1001");
//	else if (get_z(me)==020)
//	objs = children("/npc/base/2001");
//	else if (get_z(me)==030)
//	objs = children("/npc/base/3001");
//	else if (get_z(me)==040)
//	objs = children("/npc/base/4001");
//	else if (get_z(me)==050)
//	objs = children("/npc/base/5001");
//	else if (get_z(me)==060)
//	objs = children("/npc/base/6001");
//	else if (get_z(me)==070)
//	objs = children("/npc/base/7001");
//	else if (get_z(me)==080)
//	objs = children("/npc/base/8001");
//	else if (get_z(me)==549)
//	objs = children("/npc/base/0911");
//	else
//	objs = children("/npc/base/1001");
//	size = sizeof(objs);
//	if (size==0) return 0;
//	for (i=0;i<size;i++)
//	{
//		if (objectp(objs[i]) )
//		{
//			target = objs[i];
//			break;
//		}
//	}
//	if (!target) return 0;	
//	me->set("pawn_time", time());
//	"/cmd/std/pawn"->do_list(me, sprintf("%x#", getoid(target)), 1);
//            return 1; 
//		}
// 
//        return 1;
//}
//
//// 函数：获取指令类型
//int get_perform_type() { return ON_ME_7; }
//
//// 函数：能否使用指令
//void can_perform( object me )
//{
//        send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 1, 0, PF_NAME );
//}



#include <ansi.h>
#include <skill.h>

#define THIS_PERFORM    00098
#define PF_START       "00098"
#define PF_NAME        "Trợ giúp trò chơi"

string get_desc(object me)
{
	return "[ " PF_NAME " ]\n Tính năng nâng cao hỗ trợ người chơi\n ";
}


void do_look(object me)
{
	string result;

	result = sprintf(PF_NAME + ":\nVui lòng chọn tính năng cần hỗ trợ!\n");
	result += sprintf(ESC "Bật AutoFarm\nrunauto auto\n");
	result += sprintf(ESC "Tắt AutoFarm\nrunauto offauto\n");

	// result += sprintf(ESC "Trang phục\nsupport ? 1\n");
	// result += sprintf(ESC "Hiệu ứng\nsupport ? 2\n");
	// result += sprintf(ESC "Ẩn/hiện kỹ năng nghề\nsupport ? 3\n");
	// result += sprintf(ESC "Sử dụng Kho từ xa\nsupport ? 4\n");
	// result += sprintf(ESC HIY"Danh hiệu\nsupport ? 5\n");
	// result += sprintf(ESC "Hoạt động hôm nay\ntimeparty\n");
	// result += sprintf(ESC "Tất cả hoạt động\ntimeparty all\n");
	// result += sprintf(ESC "Mốc nạp\nmocnap\n");
	// result += sprintf(ESC "Nhận thưởng mốc nạp\nmocnap @\n");
	result += sprintf(ESC "Đóng.\nCLOSE\n");
	send_user(me, "%c%c%w%s", ':', 3, 0, result);
}

//int main(object me, object who, int x, int y, string arg)
int main(object me, string arg)
{
	do_look(me);

	return 1;
}


int get_perform_type() { return ON_ME_7; }

void can_perform(object me)
{
	send_user(me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 1, 0, PF_NAME);
}

