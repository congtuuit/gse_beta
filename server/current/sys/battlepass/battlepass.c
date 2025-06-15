#include <ansi.h>
#include <time.h>
#include <effect.h>
#include <skill.h>
#include <item.h>
#include <map.h>
#include <action.h>
#include <string.h>

#define BATTLE_PASS_PRICE 1000  // 1000 KNB
#define SEASON_DURATION 7776000 // 90 days in seconds
#define MAX_LEVEL 100

// Global season data
int current_season_id = 1;
int season_start_time = 0;
int season_end_time = 0;

// Free pass rewards
mapping free_rewards = ([
    1: ({ 10, "KNB" }),
    5: ({ 50, "KNB" }),
    10: ({ 100, "KNB" }),
    20: ({ 200, "KNB" }),
    30: ({ 300, "KNB" }),
    40: ({ 400, "KNB" }),
    50: ({ 500, "KNB" }),
    60: ({ 600, "KNB" }),
    70: ({ 700, "KNB" }),
    80: ({ 800, "KNB" }),
    90: ({ 900, "KNB" }),
    100: ({ 1000, "KNB" })
]);

// Premium pass rewards
mapping premium_rewards = ([
    1: ({ 50, "KNB", "VIP 1 ngày" }),
    5: ({ 100, "KNB", "Trang bị độc quyền" }),
    10: ({ 200, "KNB", "Pet độc quyền" }),
    15: ({ 300, "KNB", "Mount độc quyền" }),
    20: ({ 500, "KNB", "Title độc quyền" }),
    25: ({ 600, "KNB", "Skill độc quyền" }),
    30: ({ 700, "KNB", "Effect độc quyền" }),
    40: ({ 800, "KNB", "Item độc quyền" }),
    50: ({ 1000, "KNB", "VIP 7 ngày" }),
    60: ({ 1200, "KNB", "Trang bị legendary" }),
    70: ({ 1400, "KNB", "Pet legendary" }),
    80: ({ 1600, "KNB", "Mount legendary" }),
    90: ({ 1800, "KNB", "Title legendary" }),
    100: ({ 2000, "KNB", "VIP 30 ngày" })
]);

// Daily challenges
mapping daily_challenges = ([
    "kill_monsters": ({ "Giết 100 quái", 100, 50 }),
    "complete_tasks": ({ "Hoàn thành 10 nhiệm vụ", 10, 100 }),
    "join_guild": ({ "Tham gia bang phái", 1, 200 }),
    "use_skills": ({ "Sử dụng 50 lần skill", 50, 75 }),
    "collect_items": ({ "Thu thập 20 items", 20, 80 })
]);

// Weekly challenges  
mapping weekly_challenges = ([
    "reach_level": ({ "Lên 5 cấp", 5, 500 }),
    "win_pvp": ({ "Thắng 20 trận PvP", 20, 800 }),
    "complete_dungeon": ({ "Hoàn thành 10 dungeon", 10, 600 }),
    "earn_money": ({ "Kiếm 1,000,000 lượng", 1000000, 400 }),
    "make_friends": ({ "Kết bạn với 10 người", 10, 300 })
]);

// Initialize battle pass
void init_battle_pass()
{
    int current_time = time();
    
    // Check if new season needed
    if (current_time >= season_end_time || season_end_time == 0)
    {
        current_season_id++;
        season_start_time = current_time;
        season_end_time = current_time + SEASON_DURATION;
        
        // Reset all players' battle pass data
        reset_all_players_battle_pass();
    }
}

// Get player's battle pass data
int get_player_season_id(object player)
{
    return player->get_save_2("battlepass.season_id");
}

int get_player_level(object player)
{
    return player->get_save_2("battlepass.level");
}

int get_player_exp(object player)
{
    return player->get_save_2("battlepass.exp");
}

int get_player_premium(object player)
{
    return player->get_save_2("battlepass.premium");
}

// Save player's battle pass data
void save_player_battle_pass(object player, int season_id, int level, int exp, int premium)
{
    player->set_save_2("battlepass.season_id", season_id);
    player->set_save_2("battlepass.level", level);
    player->set_save_2("battlepass.exp", exp);
    player->set_save_2("battlepass.premium", premium);
}

// Add experience to battle pass
void add_battle_pass_exp(object player, int exp)
{
    int player_season = get_player_season_id(player);
    int player_level = get_player_level(player);
    int player_exp = get_player_exp(player);
    int player_premium = get_player_premium(player);
    
    // Check if season is current
    if (player_season != current_season_id)
    {
        player_season = current_season_id;
        player_level = 0;
        player_exp = 0;
        player_premium = 0;
    }
    
    player_exp += exp;
    
    // Calculate new level (100 exp per level)
    int new_level = player_exp / 100;
    if (new_level > MAX_LEVEL) new_level = MAX_LEVEL;
    
    // Check for level up
    if (new_level > player_level)
    {
        int levels_gained = new_level - player_level;
        player_level = new_level;
        
        // Give rewards for each level gained
        for (int i = player_level - levels_gained + 1; i <= player_level; i++)
        {
            give_battle_pass_rewards(player, i, player_premium);
        }
        
        send_user(player, "%c%s", ';', sprintf("Battle Pass lên cấp %d! Nhận thưởng!", player_level));
    }
    
    save_player_battle_pass(player, player_season, player_level, player_exp, player_premium);
}

// Give battle pass rewards
void give_battle_pass_rewards(object player, int level, int is_premium)
{
    // Give free rewards
    if (free_rewards[level])
    {
        int* reward = free_rewards[level];
        if (reward[1] == "KNB")
        {
            "sys/sys/test_db"->add_yuanbao(player, reward[0] * 10);
            send_user(player, "%c%s", '!', sprintf("Battle Pass Level %d: %d KNB", level, reward[0]));
        }
    }
    
    // Give premium rewards if player has premium pass
    if (is_premium && premium_rewards[level])
    {
        int* reward = premium_rewards[level];
        if (reward[1] == "KNB")
        {
            "sys/sys/test_db"->add_yuanbao(player, reward[0] * 10);
            send_user(player, "%c%s", '!', sprintf("Premium Level %d: %d KNB + %s", level, reward[0], reward[2]));
        }
    }
}

// Buy premium battle pass
int buy_premium_battle_pass(object player)
{
    int player_premium = get_player_premium(player);
    
    // Check if already premium
    if (player_premium)
    {
        send_user(player, "%c%s", '!', "Bạn đã có Premium Battle Pass!");
        return 0;
    }
    
    // Check if player has enough KNB
    if ("sys/sys/test_db"->get_yuanbao(player) < BATTLE_PASS_PRICE * 10)
    {
        send_user(player, "%c%s", '!', "Không đủ KNB để mua Premium Battle Pass!");
        return 0;
    }
    
    // Deduct KNB and give premium
    "sys/sys/test_db"->add_yuanbao(player, -BATTLE_PASS_PRICE * 10);
    player_premium = 1;
    
    int player_level = get_player_level(player);
    
    // Give all premium rewards for current level
    for (int i = 1; i <= player_level; i++)
    {
        if (premium_rewards[i])
        {
            give_battle_pass_rewards(player, i, 1);
        }
    }
    
    save_player_battle_pass(player, current_season_id, player_level, get_player_exp(player), player_premium);
    send_user(player, "%c%s", ';', "Mua Premium Battle Pass thành công!");
    
    return 1;
}

// Show battle pass interface
void show_battle_pass_interface(object player)
{
    int player_level = get_player_level(player);
    int player_exp = get_player_exp(player);
    int player_premium = get_player_premium(player);
    int current_time = time();
    int time_left = season_end_time - current_time;
    int days_left = time_left / 86400;
    
    string interface = sprintf(
        "=== BATTLE PASS SEASON %d ===\n"
        "Thời gian còn lại: %d ngày\n"
        "Level hiện tại: %d/%d\n"
        "Kinh nghiệm: %d/100\n"
        "Premium: %s\n\n"
        "=== FREE REWARDS ===\n",
        current_season_id,
        days_left,
        player_level,
        MAX_LEVEL,
        player_exp % 100,
        player_premium ? "Có" : "Không"
    );
    
    // Show next 5 free rewards
    for (int i = player_level + 1; i <= player_level + 5 && i <= MAX_LEVEL; i++)
    {
        if (free_rewards[i])
        {
            int* reward = free_rewards[i];
            interface += sprintf("Level %d: %d %s\n", i, reward[0], reward[1]);
        }
    }
    
    if (player_premium)
    {
        interface += "\n=== PREMIUM REWARDS ===\n";
        for (int i = player_level + 1; i <= player_level + 5 && i <= MAX_LEVEL; i++)
        {
            if (premium_rewards[i])
            {
                int* reward = premium_rewards[i];
                interface += sprintf("Level %d: %d %s + %s\n", i, reward[0], reward[1], reward[2]);
            }
        }
    }
    else
    {
        interface += sprintf("\nMua Premium Pass: %d KNB\n", BATTLE_PASS_PRICE);
    }
    
    send_user(player, "%c%c%w%s", ':', 3, 0, interface);
}

// Reset all players' battle pass data
void reset_all_players_battle_pass()
{
    // This would need to be implemented to reset all online players
    // For now, just log the season change
    log_file("battlepass.dat", sprintf("%s New season %d started\n", short_time(), current_season_id));
}

// Daily challenge completion
void complete_daily_challenge(object player, string challenge_type)
{
    if (daily_challenges[challenge_type])
    {
        int* challenge = daily_challenges[challenge_type];
        int exp_gained = challenge[2];
        
        add_battle_pass_exp(player, exp_gained);
        send_user(player, "%c%s", '!', sprintf("Hoàn thành thử thách: %s (+%d exp)", challenge[0], exp_gained));
    }
}

// Weekly challenge completion
void complete_weekly_challenge(object player, string challenge_type)
{
    if (weekly_challenges[challenge_type])
    {
        int* challenge = weekly_challenges[challenge_type];
        int exp_gained = challenge[2];
        
        add_battle_pass_exp(player, exp_gained);
        send_user(player, "%c%s", '!', sprintf("Hoàn thành thử thách tuần: %s (+%d exp)", challenge[0], exp_gained));
    }
}

// Initialize on startup
void create()
{
    init_battle_pass();
    call_out("check_season", 3600); // Check every hour
}

// Check season status
void check_season()
{
    init_battle_pass();
    call_out("check_season", 3600);
} 