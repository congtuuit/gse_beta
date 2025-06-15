#include <ansi.h>
#include <time.h>
#include <effect.h>
#include <skill.h>
#include <item.h>
#include <map.h>
#include <action.h>
#include <string.h>

// Weekly rotation system
mapping weekly_bosses = ([
    1: ({ "Boss Tuần 1", "Thiên Ma Vương", 120, 300, 500, "/npc/event/PhoBan/Boss60/CVQ.c" }),
    2: ({ "Boss Tuần 2", "Địa Ngục Chủ", 125, 320, 550, "/npc/event/PhoBan/Boss60/KinhKha3.c" }),
    3: ({ "Boss Tuần 3", "Huyền Thiên Đế", 130, 340, 600, "/npc/event/PhoBan/5Boss/Boss1-CVQ.c" }),
    4: ({ "Boss Tuần 4", "Cửu U Ma Vương", 135, 360, 650, "/npc/event/PhoBan/5Boss/Boss2-DM.c" })
]);

mapping weekly_events = ([
    1: ({ "Sự Kiện Tuần 1", "Boss Raid", "Tất cả boss xuất hiện cùng lúc", 2.0 }),
    2: ({ "Sự Kiện Tuần 2", "PvP Tournament", "Giải đấu bang phái", 1.5 }),
    3: ({ "Sự Kiện Tuần 3", "Treasure Hunt", "Tìm kho báu ẩn", 2.5 }),
    4: ({ "Sự Kiện Tuần 4", "Guild War", "Chiến tranh bang phái", 3.0 })
]);

mapping weekly_rewards = ([
    1: ({ "Phần Thưởng Tuần 1", "/item/sell/0061.c", 1, 5000 }), // VIP Package
    2: ({ "Phần Thưởng Tuần 2", "/item/test2/TuiHoangKimThanhY.c", 1, 3000 }), // Golden Bag
    3: ({ "Phần Thưởng Tuần 3", "/item/sell/ruongdutru.c", 1, 4000 }), // Storage Box
    4: ({ "Phần Thưởng Tuần 4", "/item/sell/0031.c", 1, 10000 }) // Mega Reward
]);

// Weekly challenges
mapping weekly_challenges = ([
    "kill_weekly_boss": ({ "Tiêu diệt Boss tuần", 1, 2000 }),
    "reach_weekly_level": ({ "Lên 10 cấp", 10, 1500 }),
    "complete_weekly_tasks": ({ "Hoàn thành 100 nhiệm vụ", 100, 1000 }),
    "earn_weekly_money": ({ "Kiếm 5,000,000 lượng", 5000000, 800 }),
    "win_pvp_matches": ({ "Thắng 50 trận PvP", 50, 1200 }),
    "collect_weekly_items": ({ "Thu thập 500 items", 500, 600 }),
    "join_guild_activities": ({ "Tham gia 20 hoạt động bang phái", 20, 1500 })
]);

// Get current week of month (1-4)
int get_current_week()
{
    mixed* time_data = localtime(time());
    int day = time_data[TIME_MDAY];
    return ((day - 1) / 7) + 1;
}

// Get current month
int get_current_month()
{
    mixed* time_data = localtime(time());
    return time_data[TIME_MON] + 1;
}

// Get weekly boss
string get_weekly_boss()
{
    int week = get_current_week();
    if (weekly_bosses[week])
    {
        int* boss_data = weekly_bosses[week];
        return boss_data[1];
    }
    return "Boss Tuần Mặc Định";
}

// Get weekly event
string get_weekly_event()
{
    int week = get_current_week();
    if (weekly_events[week])
    {
        int* event_data = weekly_events[week];
        return event_data[1];
    }
    return "Sự Kiện Tuần Mặc Định";
}

// Spawn weekly boss
void spawn_weekly_boss()
{
    int week = get_current_week();
    if (weekly_bosses[week])
    {
        int* boss_data = weekly_bosses[week];
        string boss_name = boss_data[1];
        int boss_level = boss_data[2];
        int boss_hp = boss_data[3];
        int boss_exp = boss_data[4];
        string boss_file = boss_data[5];
        
        // Spawn boss at specific location
        object boss = new(boss_file);
        if (boss)
        {
            boss->set_level(boss_level);
            boss->set_max_hp(boss_hp);
            boss->set_hp(boss_hp);
            boss->add_to_scene(80, 200, 200); // Spawn at map 80, position 200,200
            
            // Announce to all players
            USER_D->user_channel(sprintf(HIR"Boss Tuần %s đã xuất hiện tại bản đồ 80! Hãy nhanh chóng tiêu diệt!", boss_name));
            
            log_file("weekly_boss.dat", sprintf("%s Weekly boss %s spawned\n", short_time(), boss_name));
        }
    }
}

// Start weekly event
void start_weekly_event()
{
    int week = get_current_week();
    if (weekly_events[week])
    {
        int* event_data = weekly_events[week];
        string event_name = event_data[0];
        string event_type = event_data[1];
        string event_desc = event_data[2];
        float bonus_multiplier = event_data[3];
        
        // Apply weekly event bonus to all players
        object* users = USER_D->get_all_users();
        for (int i = 0; i < sizeof(users); i++)
        {
            if (users[i])
            {
                users[i]->set_save_2("weekly_event.type", event_type);
                users[i]->set_save_2("weekly_event.multiplier", bonus_multiplier);
                users[i]->set_save_2("weekly_event.week", week);
                
                send_user(users[i], "%c%s", ';', sprintf("Sự kiện tuần: %s - %s", event_name, event_desc));
            }
        }
        
        // Special handling for different event types
        switch (event_type)
        {
        case "Boss Raid":
            // Spawn multiple bosses
            spawn_multiple_bosses();
            break;
        case "PvP Tournament":
            // Start PvP tournament
            start_pvp_tournament();
            break;
        case "Treasure Hunt":
            // Spawn treasure chests
            spawn_treasure_chests();
            break;
        case "Guild War":
            // Start guild war
            start_guild_war();
            break;
        }
        
        log_file("weekly_event.dat", sprintf("%s Weekly event %s started\n", short_time(), event_name));
    }
}

// Spawn multiple bosses for Boss Raid event
void spawn_multiple_bosses()
{
    string* boss_files = ({
        "/npc/event/PhoBan/5Boss/Boss1-CVQ.c",
        "/npc/event/PhoBan/5Boss/Boss2-DM.c",
        "/npc/event/PhoBan/5Boss/Boss3-CVQ.c",
        "/npc/event/PhoBan/5Boss/Boss4-CVQ.c",
        "/npc/event/PhoBan/5Boss/Boss5-CVQ.c"
    });
    
    int* positions = ({ 150, 160, 170, 180, 190 });
    
    for (int i = 0; i < sizeof(boss_files); i++)
    {
        object boss = new(boss_files[i]);
        if (boss)
        {
            boss->set_level(100 + i * 5);
            boss->set_max_hp(200 + i * 20);
            boss->set_hp(200 + i * 20);
            boss->add_to_scene(80, positions[i], positions[i]);
        }
    }
    
    USER_D->user_channel(HIR"Boss Raid Event: 5 Boss đã xuất hiện cùng lúc!");
}

// Start PvP tournament
void start_pvp_tournament()
{
    // Create tournament brackets
    object* users = USER_D->get_all_users();
    object* pvp_users = ({});
    
    // Filter users who want to participate
    for (int i = 0; i < sizeof(users); i++)
    {
        if (users[i] && users[i]->get_save_2("pvp_tournament.join"))
        {
            pvp_users += ({ users[i] });
        }
    }
    
    // Create tournament brackets
    if (sizeof(pvp_users) >= 8)
    {
        // Start tournament
        for (int i = 0; i < sizeof(pvp_users); i++)
        {
            pvp_users[i]->set_save_2("pvp_tournament.active", 1);
            pvp_users[i]->set_save_2("pvp_tournament.round", 1);
        }
        
        USER_D->user_channel(HIR"PvP Tournament đã bắt đầu! Chúc may mắn!");
    }
    else
    {
        USER_D->user_channel(HIY"PvP Tournament cần ít nhất 8 người tham gia!");
    }
}

// Spawn treasure chests for Treasure Hunt
void spawn_treasure_chests()
{
    // Spawn treasure chests at random locations
    for (int i = 0; i < 10; i++)
    {
        object chest = new("/item/test2/TuiHoangKimThanhY.c");
        if (chest)
        {
            int x = random(200) + 100;
            int y = random(200) + 100;
            chest->add_to_scene(80, x, y);
        }
    }
    
    USER_D->user_channel(HIY"Treasure Hunt: 10 kho báu đã được giấu trên bản đồ 80!");
}

// Start guild war
void start_guild_war()
{
    // Get all guilds
    object* guilds = GUILD_D->get_all_guilds();
    
    if (sizeof(guilds) >= 2)
    {
        // Pair guilds for war
        for (int i = 0; i < sizeof(guilds) - 1; i += 2)
        {
            object guild1 = guilds[i];
            object guild2 = guilds[i + 1];
            
            if (guild1 && guild2)
            {
                guild1->set_save_2("guild_war.opponent", guild2->get_id());
                guild2->set_save_2("guild_war.opponent", guild1->get_id());
                
                // Notify guild members
                object* members1 = guild1->get_members();
                object* members2 = guild2->get_members();
                
                for (int j = 0; j < sizeof(members1); j++)
                {
                    if (members1[j])
                    {
                        send_user(members1[j], "%c%s", ';', sprintf("Guild War: %s vs %s", guild1->get_name(), guild2->get_name()));
                    }
                }
                
                for (int j = 0; j < sizeof(members2); j++)
                {
                    if (members2[j])
                    {
                        send_user(members2[j], "%c%s", ';', sprintf("Guild War: %s vs %s", guild2->get_name(), guild1->get_name()));
                    }
                }
            }
        }
        
        USER_D->user_channel(HIR"Guild War đã bắt đầu! Các bang phái hãy chuẩn bị chiến đấu!");
    }
    else
    {
        USER_D->user_channel(HIY"Guild War cần ít nhất 2 bang phái!");
    }
}

// Give weekly login reward
void give_weekly_login_reward(object player)
{
    int week = get_current_week();
    int weekly_login_count = player->get_save_2("weekly_login.count");
    int last_week = player->get_save_2("weekly_login.week");
    
    // Check if new week
    if (week != last_week)
    {
        weekly_login_count = 0;
    }
    
    weekly_login_count++;
    
    // Give reward based on login count
    if (weekly_login_count >= 7)
    {
        // Full week login reward
        if (weekly_rewards[week])
        {
            int* reward_data = weekly_rewards[week];
            string item_file = reward_data[1];
            int item_count = reward_data[2];
            int bonus_knb = reward_data[3];
            
            // Give item
            object item = new(item_file);
            if (item)
            {
                int pos = item->move(player, -1);
                item->add_to_user(pos);
                send_user(player, "%c%s", '!', sprintf("Nhận được %s", item->get_name()));
            }
            
            // Give KNB bonus
            "sys/sys/test_db"->add_yuanbao(player, bonus_knb * 10);
            
            send_user(player, "%c%s", ';', sprintf("Đăng nhập đủ 7 ngày! Nhận được %d KNB", bonus_knb));
            
            // Reset count
            weekly_login_count = 0;
        }
    }
    
    // Save data
    player->set_save_2("weekly_login.count", weekly_login_count);
    player->set_save_2("weekly_login.week", week);
    
    log_file("weekly_login.dat", sprintf("%s %s(%d) weekly login count %d\n", short_time(), player->get_id(), player->get_number(), weekly_login_count));
}

// Check weekly challenge completion
void check_weekly_challenge(object player, string challenge_type, int progress)
{
    int week = get_current_week();
    string challenge_key = sprintf("weekly_challenge.%d.%s", week, challenge_type);
    int current_progress = player->get_save_2(challenge_key);
    
    current_progress += progress;
    player->set_save_2(challenge_key, current_progress);
    
    if (weekly_challenges[challenge_type])
    {
        int* challenge_data = weekly_challenges[challenge_type];
        int required = challenge_data[1];
        int reward_exp = challenge_data[2];
        
        if (current_progress >= required)
        {
            // Check if already completed this week
            if (!player->get_save_2(sprintf("weekly_challenge_completed.%d.%s", week, challenge_type)))
            {
                // Give reward
                "sys/battlepass/battlepass"->add_battle_pass_exp(player, reward_exp);
                player->add_exp(reward_exp);
                
                // Mark as completed
                player->set_save_2(sprintf("weekly_challenge_completed.%d.%s", week, challenge_type), 1);
                
                send_user(player, "%c%s", '!', sprintf("Hoàn thành thử thách tuần: %s (+%d exp)", challenge_data[0], reward_exp));
            }
        }
    }
}

// Reset weekly data
void reset_weekly_data()
{
    // Reset all players' weekly data
    object* users = USER_D->get_all_users();
    for (int i = 0; i < sizeof(users); i++)
    {
        if (users[i])
        {
            // Clear weekly event data
            users[i]->delete_save_2("weekly_event.type");
            users[i]->delete_save_2("weekly_event.multiplier");
            users[i]->delete_save_2("weekly_event.week");
            
            // Clear weekly challenge data
            users[i]->delete_save_2("weekly_challenge");
            users[i]->delete_save_2("weekly_challenge_completed");
        }
    }
    
    log_file("weekly_reset.dat", sprintf("%s Weekly data reset\n", short_time()));
}

// Initialize weekly system
void create()
{
    // Start weekly event on Monday at 9:00 AM
    call_out("start_weekly_event", 32400); // 9 hours = 32400 seconds
    
    // Spawn weekly boss on Wednesday at 2:00 PM
    call_out("spawn_weekly_boss", 50400); // 14 hours = 50400 seconds
    
    // Reset weekly data on Sunday at midnight
    call_out("reset_weekly_data", 604800); // 7 days = 604800 seconds
}

// Check weekly event status
void check_weekly_event()
{
    // Check if weekly event is still active
    call_out("check_weekly_event", 3600); // Check every hour
} 