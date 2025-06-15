#include <cmd.h>
#include <ansi.h>

inherit CMD_BASE;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string result;
	
	if (!arg || arg == "")
	{
		// Show achievement menu
		result = sprintf(" %s :\n", "Hệ Thống Thành Tựu");
		result += "════════════════════════════════════════\n";
		result += sprintf(ESC"Xem tất cả thành tựu\nachievement all\n");
		result += sprintf(ESC"Thành tựu chiến đấu\nachievement combat\n");
		result += sprintf(ESC"Thành tựu cấp độ\nachievement level\n");
		result += sprintf(ESC"Thành tựu kỹ năng\nachievement skill\n");
		result += sprintf(ESC"Thành tựu thu thập\nachievement collection\n");
		result += sprintf(ESC"Thành tựu xã hội\nachievement social\n");
		result += sprintf(ESC"Thành tựu khám phá\nachievement exploration\n");
		result += sprintf(ESC"Thành tựu sự kiện\nachievement event\n");
		result += sprintf(ESC"Thống kê thành tựu\nachievement stats\n");
		result += sprintf(ESC"Tìm Achievement Master\nachievement master\n");
		result += ESC"Đóng\nCLOSE\n";
		
		send_user(me, "%c%s", ':', result);
		return 1;
	}
	
	if (arg == "all")
	{
		// "sys/achievement/achievement"->show_achievement_interface(me);
		send_user(me, "%c%s", '!', "Hệ thống thành tựu đang được bảo trì!");
		return 1;
	}
	
	if (arg == "combat")
	{
		// show_achievement_category(me, "combat");
		send_user(me, "%c%s", '!', "Hệ thống thành tựu đang được bảo trì!");
		return 1;
	}
	
	if (arg == "level")
	{
		// show_achievement_category(me, "level");
		send_user(me, "%c%s", '!', "Hệ thống thành tựu đang được bảo trì!");
		return 1;
	}
	
	if (arg == "skill")
	{
		// show_achievement_category(me, "skill");
		send_user(me, "%c%s", '!', "Hệ thống thành tựu đang được bảo trì!");
		return 1;
	}
	
	if (arg == "collection")
	{
		// show_achievement_category(me, "collection");
		send_user(me, "%c%s", '!', "Hệ thống thành tựu đang được bảo trì!");
		return 1;
	}
	
	if (arg == "social")
	{
		// show_achievement_category(me, "social");
		send_user(me, "%c%s", '!', "Hệ thống thành tựu đang được bảo trì!");
		return 1;
	}
	
	if (arg == "exploration")
	{
		// show_achievement_category(me, "exploration");
		send_user(me, "%c%s", '!', "Hệ thống thành tựu đang được bảo trì!");
		return 1;
	}
	
	if (arg == "event")
	{
		// show_achievement_category(me, "event");
		send_user(me, "%c%s", '!', "Hệ thống thành tựu đang được bảo trì!");
		return 1;
	}
	
	if (arg == "stats")
	{
		// show_achievement_stats(me);
		send_user(me, "%c%s", '!', "Hệ thống thành tựu đang được bảo trì!");
		return 1;
	}
	
	if (arg == "master")
	{
		// Teleport to Achievement Master
		me->move("/npc/achievement/achievement_master");
		send_user(me, "%c%s", '!', HIG"Đã đến gặp Achievement Master!"NOR);
		return 1;
	}
	
	// GM Commands for testing
	if (is_gm(me) || is_gm2(me) || is_gm3(me))
	{
		if (arg == "gm_test")
		{
			result = sprintf(" %s :\n", "GM Achievement Test Menu");
			result += "════════════════════════════════════════\n";
			result += sprintf(ESC"Test Combat Achievement\ntest_achievement combat\n");
			result += sprintf(ESC"Test Level Achievement\ntest_achievement level\n");
			result += sprintf(ESC"Test Skill Achievement\ntest_achievement skill\n");
			result += sprintf(ESC"Test Collection Achievement\ntest_achievement collection\n");
			result += sprintf(ESC"Test Social Achievement\ntest_achievement social\n");
			result += sprintf(ESC"Test Login Achievement\ntest_achievement login\n");
			result += sprintf(ESC"Test Task Achievement\ntest_achievement task\n");
			result += sprintf(ESC"Complete All Achievements\ntest_achievement all\n");
			result += sprintf(ESC"Reset All Achievements\ntest_achievement reset\n");
			result += sprintf(ESC"Give Random Achievement\ntest_achievement random\n");
			result += ESC"Đóng\nCLOSE\n";
			
			send_user(me, "%c%s", ':', result);
			return 1;
		}
		
		if (sscanf(arg, "test_achievement %s", string test_type) == 1)
		{
			/*
			switch (test_type)
			{
			case "combat":
				// Test combat achievements
				"sys/achievement/achievement"->check_achievement_progress(me, "first_kill", 1);
				"sys/achievement/achievement"->check_achievement_progress(me, "kill_100", 100);
				"sys/achievement/achievement"->check_achievement_progress(me, "kill_1000", 1000);
				"sys/achievement/achievement"->check_achievement_progress(me, "first_boss", 1);
				"sys/achievement/achievement"->check_achievement_progress(me, "first_pvp", 1);
				send_user(me, "%c%s", '!', HIG"✅ Đã test thành tựu chiến đấu!"NOR);
				break;
				
			case "level":
				// Test level achievements
				"sys/achievement/achievement"->check_achievement_progress(me, "reach_level_10", 10);
				"sys/achievement/achievement"->check_achievement_progress(me, "reach_level_30", 30);
				"sys/achievement/achievement"->check_achievement_progress(me, "reach_level_50", 50);
				"sys/achievement/achievement"->check_achievement_progress(me, "reach_level_80", 80);
				"sys/achievement/achievement"->check_achievement_progress(me, "reach_level_100", 100);
				send_user(me, "%c%s", '!', HIG"✅ Đã test thành tựu cấp độ!"NOR);
				break;
				
			case "skill":
				// Test skill achievements
				"sys/achievement/achievement"->check_achievement_progress(me, "learn_first_skill", 1);
				"sys/achievement/achievement"->check_achievement_progress(me, "learn_5_skills", 5);
				"sys/achievement/achievement"->check_achievement_progress(me, "learn_10_skills", 10);
				"sys/achievement/achievement"->check_achievement_progress(me, "max_1_skill", 1);
				send_user(me, "%c%s", '!', HIG"✅ Đã test thành tựu kỹ năng!"NOR);
				break;
				
			case "collection":
				// Test collection achievements
				"sys/achievement/achievement"->check_achievement_progress(me, "collect_10_items", 10);
				"sys/achievement/achievement"->check_achievement_progress(me, "collect_100_items", 100);
				"sys/achievement/achievement"->check_achievement_progress(me, "collect_500_items", 500);
				"sys/achievement/achievement"->check_achievement_progress(me, "collect_1000_items", 1000);
				send_user(me, "%c%s", '!', HIG"✅ Đã test thành tựu thu thập!"NOR);
				break;
				
			case "social":
				// Test social achievements
				"sys/achievement/achievement"->check_achievement_progress(me, "join_guild", 1);
				"sys/achievement/achievement"->check_achievement_progress(me, "make_10_friends", 10);
				"sys/achievement/achievement"->check_achievement_progress(me, "help_50_players", 50);
				"sys/achievement/achievement"->check_achievement_progress(me, "guild_leader", 1);
				send_user(me, "%c%s", '!', HIG"✅ Đã test thành tựu xã hội!"NOR);
				break;
				
			case "login":
				// Test login achievements
				"sys/achievement/achievement"->check_achievement_progress(me, "first_login", 1);
				"sys/achievement/achievement"->check_achievement_progress(me, "login_7_days", 7);
				"sys/achievement/achievement"->check_achievement_progress(me, "login_30_days", 30);
				"sys/achievement/achievement"->check_achievement_progress(me, "login_100_days", 100);
				send_user(me, "%c%s", '!', HIG"✅ Đã test thành tựu đăng nhập!"NOR);
				break;
				
			case "task":
				// Test task achievements
				"sys/achievement/achievement"->check_achievement_progress(me, "complete_monthly_tasks", 10);
				"sys/achievement/achievement"->check_achievement_progress(me, "complete_monthly_tasks", 50);
				"sys/achievement/achievement"->check_achievement_progress(me, "complete_monthly_tasks", 100);
				send_user(me, "%c%s", '!', HIG"✅ Đã test thành tựu nhiệm vụ!"NOR);
				break;
				
			case "all":
				// Complete all achievements
				"sys/achievement/achievement"->complete_all_achievements(me);
				send_user(me, "%c%s", '!', HIG"✅ Đã hoàn thành tất cả thành tựu!"NOR);
				break;
				
			case "reset":
				// Reset all achievements
				"sys/achievement/achievement"->reset_all_achievements(me);
				send_user(me, "%c%s", '!', HIG"✅ Đã reset tất cả thành tựu!"NOR);
				break;
				
			case "random":
				// Give random achievement
				"sys/achievement/achievement"->give_random_achievement(me);
				break;
				
			default:
				send_user(me, "%c%s", '!', "Loại test không hợp lệ!");
				break;
			}
			*/
			send_user(me, "%c%s", '!', "Hệ thống thành tựu đang được bảo trì!");
			return 1;
		}
	}
	
	send_user(me, "%c%s", '!', "Lệnh không hợp lệ. Gõ 'achievement' để xem hướng dẫn.");
	return 1;
}

// Helper functions
void show_achievement_category(object me, string category)
{
	int category_id = 0;
	
	switch (category)
	{
	case "combat": category_id = 1; break;
	case "level": category_id = 2; break;
	case "skill": category_id = 3; break;
	case "collection": category_id = 7; break;
	case "social": category_id = 5; break;
	case "exploration": category_id = 6; break;
	case "event": category_id = 8; break;
	default: category_id = 1; break;
	}
	
	string msg = sprintf("=== THÀNH TỰU %s ===\n\n", "sys/achievement/achievement"->get_category_name(category_id));
	
	string* achievement_ids = "sys/achievement/achievement"->get_achievements_by_category(category_id);
	
	for (int i = 0; i < sizeof(achievement_ids); i++)
	{
		string achievement_id = achievement_ids[i];
		int* data = "sys/achievement/achievement"->get_achievement_data(achievement_id);
		
		if (data)
		{
			string name = data[0];
			string description = data[1];
			int tier = data[3];
			int required = data[4];
			int current = "sys/achievement/achievement"->get_achievement_progress(me, achievement_id);
			int completed = "sys/achievement/achievement"->is_achievement_completed(me, achievement_id);
			
			string tier_name = "sys/achievement/achievement"->get_tier_name(tier);
			string status = completed ? HIG"✓ Hoàn thành" : 
				(current > 0 ? HIY"Đang tiến hành" : HIW"Chưa bắt đầu");
			
			msg += sprintf("%s (%s): %s (%d/%d) - %s\n", 
				name, tier_name, description, current, required, status);
		}
	}
	
	send_user(me, "%c%s", ';', msg);
}

void show_achievement_stats(object me)
{
	int total = "sys/achievement/achievement"->get_total_achievements();
	int completed = "sys/achievement/achievement"->get_completed_achievements(me);
	float rate = "sys/achievement/achievement"->get_achievement_completion_rate(me);
	
	string msg = "=== THỐNG KÊ THÀNH TỰU ===\n\n";
	msg += sprintf("Tổng số thành tựu: %d\n", total);
	msg += sprintf("Thành tựu đã hoàn thành: %d\n", completed);
	msg += sprintf("Tỷ lệ hoàn thành: %.1f%%\n", rate);
	msg += "\n";
	
	// Show by categories
	for (int category = 1; category <= 8; category++)
	{
		string category_name = "sys/achievement/achievement"->get_category_name(category);
		string* achievement_ids = "sys/achievement/achievement"->get_achievements_by_category(category);
		int category_completed = 0;
		
		for (int i = 0; i < sizeof(achievement_ids); i++)
		{
			if ("sys/achievement/achievement"->is_achievement_completed(me, achievement_ids[i]))
			{
				category_completed++;
			}
		}
		
		float category_rate = (float)category_completed / sizeof(achievement_ids) * 100;
		msg += sprintf("%s: %d/%d (%.1f%%)\n", category_name, category_completed, sizeof(achievement_ids), category_rate);
	}
	
	send_user(me, "%c%s", ';', msg);
} 