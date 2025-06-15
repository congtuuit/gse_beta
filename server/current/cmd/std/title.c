#include <ansi.h>

// 函数：命令处理
int main( object me, string arg )
{
	string com,arg1;
	
	if ( sscanf(arg,"%s %s",com,arg1) != 2 )
		com = arg;
	if ( com == "hide" )
		me->hide_title();
	else if ( com == "show" )
		me->show_title(arg1);
	
	// GM Commands for testing titles
	if (is_gm(me) || is_gm2(me) || is_gm3(me))
	{
		if (arg == "gm_test")
		{
			string result = sprintf(" %s :\n", "GM Title Test Menu");
			result += "════════════════════════════════════════\n";
			result += sprintf(ESC"Test Combat Title\ntitle test_combat\n");
			result += sprintf(ESC"Test Level Title\ntitle test_level\n");
			result += sprintf(ESC"Test Skill Title\ntitle test_skill\n");
			result += sprintf(ESC"Test Collection Title\ntitle test_collection\n");
			result += sprintf(ESC"Test Social Title\ntitle test_social\n");
			result += sprintf(ESC"Test Login Title\ntitle test_login\n");
			result += sprintf(ESC"Test Task Title\ntitle test_task\n");
			result += sprintf(ESC"Test Legendary Title\ntitle test_legendary\n");
			result += sprintf(ESC"Give All Achievement Titles\ntitle give_all\n");
			result += sprintf(ESC"Remove All Achievement Titles\ntitle remove_all\n");
			result += ESC"Đóng\nCLOSE\n";
			
			send_user(me, "%c%s", ':', result);
			return 1;
		}
		
		if (sscanf(arg, "test_%s", string test_type) == 1)
		{
			switch (test_type)
			{
			case "combat":
				// Test combat titles
				me->add_title("A001");
				me->add_title("A002");
				me->add_title("A003");
				send_user(me, "%c%s", '!', HIG"✅ Đã test danh hiệu chiến đấu!"NOR);
				break;
				
			case "level":
				// Test level titles
				me->add_title("A020");
				me->add_title("A021");
				me->add_title("A022");
				send_user(me, "%c%s", '!', HIG"✅ Đã test danh hiệu cấp độ!"NOR);
				break;
				
			case "skill":
				// Test skill titles
				me->add_title("B001");
				me->add_title("B002");
				me->add_title("B003");
				send_user(me, "%c%s", '!', HIG"✅ Đã test danh hiệu kỹ năng!"NOR);
				break;
				
			case "collection":
				// Test collection titles
				me->add_title("A999");
				me->add_title("A900");
				send_user(me, "%c%s", '!', HIG"✅ Đã test danh hiệu thu thập!"NOR);
				break;
				
			case "social":
				// Test social titles
				me->add_title("C001");
				me->add_title("C002");
				me->add_title("C003");
				send_user(me, "%c%s", '!', HIG"✅ Đã test danh hiệu xã hội!"NOR);
				break;
				
			case "login":
				// Test login titles
				me->add_title("G001");
				me->add_title("G002");
				send_user(me, "%c%s", '!', HIG"✅ Đã test danh hiệu đăng nhập!"NOR);
				break;
				
			case "task":
				// Test task titles
				me->add_title("P001");
				me->add_title("P002");
				me->add_title("P003");
				send_user(me, "%c%s", '!', HIG"✅ Đã test danh hiệu nhiệm vụ!"NOR);
				break;
				
			case "legendary":
				// Test legendary titles
				me->add_title("A111");
				me->add_title("A112");
				send_user(me, "%c%s", '!', HIR"🔥 Đã test danh hiệu huyền thoại!"NOR);
				break;
				
			case "give_all":
				// Give all achievement titles
				give_all_titles(me);
				send_user(me, "%c%s", '!', HIG"✅ Đã trao tất cả danh hiệu!"NOR);
				break;
				
			case "remove_all":
				// Remove all achievement titles
				remove_all_titles(me);
				send_user(me, "%c%s", '!', HIG"✅ Đã xóa tất cả danh hiệu!"NOR);
				break;
				
			default:
				send_user(me, "%c%s", '!', "Loại test không hợp lệ!");
				break;
			}
			return 1;
		}
	}
        
	return 1;
}

// GM Helper Functions
void give_all_titles(object me)
{
	// Combat titles
	me->add_title("A001");
	me->add_title("A002");
	me->add_title("A003");
	me->add_title("A004");
	me->add_title("A005");
	
	// Level titles
	me->add_title("A020");
	me->add_title("A021");
	me->add_title("A022");
	me->add_title("A023");
	
	// Skill titles
	me->add_title("B001");
	me->add_title("B002");
	me->add_title("B003");
	me->add_title("B004");
	
	// Collection titles
	me->add_title("A999");
	me->add_title("A900");
	
	// Social titles
	me->add_title("C001");
	me->add_title("C002");
	me->add_title("C003");
	me->add_title("C004");
	
	// Login titles
	me->add_title("G001");
	me->add_title("G002");
	
	// Task titles
	me->add_title("P001");
	me->add_title("P002");
	me->add_title("P003");
	me->add_title("P004");
	
	// Legendary titles
	me->add_title("A111");
	me->add_title("A112");
}

void remove_all_titles(object me)
{
	string *all_titles = ({
		"A001", "A002", "A003", "A004", "A005",
		"A020", "A021", "A022", "A023",
		"B001", "B002", "B003", "B004",
		"A999", "A900",
		"C001", "C002", "C003", "C004",
		"G001", "G002",
		"P001", "P002", "P003", "P004",
		"A111", "A112"
	});
	
	for (int i = 0; i < sizeof(all_titles); i++)
	{
		me->remove_title(all_titles[i]);
	}
}