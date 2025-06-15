#include <ansi.h>
#include <time.h>
#include <effect.h>
#include <skill.h>
#include <item.h>
#include <map.h>
#include <action.h>
#include <string.h>

// Daily rotation system
mapping daily_bosses = ([
    0: ({ "Boss Hỏa Long", 80, 150, 200, "/npc/event/PhoBan/5Boss/Boss1-CVQ.c" }),
    1: ({ "Boss Thủy Quái", 85, 160, 220, "/npc/event/PhoBan/5Boss/Boss2-DM.c" }),
    2: ({ "Boss Mộc Yêu", 90, 170, 240, "/npc/event/PhoBan/5Boss/Boss3-CVQ.c" }),
    3: ({ "Boss Kim Thần", 95, 180, 260, "/npc/event/PhoBan/5Boss/Boss4-CVQ.c" }),
    4: ({ "Boss Thổ Ma", 100, 190, 280, "/npc/event/PhoBan/5Boss/Boss5-CVQ.c" }),
    5: ({ "Boss Phong Ma", 105, 200, 300, "/npc/event/PhoBan/Boss60/KinhKha.c" }),
    6: ({ "Boss Lôi Thần", 110, 210, 320, "/npc/event/PhoBan/Boss60/KinhKha2.c" })
]);

mapping daily_items = ([
    0: ({ "Túi Quà Thứ 2", "/item/test2/TuiHoangKimThanhY.c", 1000 }),
    1: ({ "Túi Quà Thứ 3", "/item/test2/TuiPhapBao.c", 800 }),
    2: ({ "Túi Quà Thứ 4", "/item/sell/ruongdutru.c", 600 }),
    3: ({ "Túi Quà Thứ 5", "/item/sell/0012.c", 500 }),
    4: ({ "Túi Quà Thứ 6", "/item/sell/0002.c", 400 }),
    5: ({ "Túi Quà Thứ 7", "/item/sell/0004.c", 300 }),
    6: ({ "Túi Quà Chủ Nhật", "/item/sell/0031.c", 2000 })
]);

mapping daily_events = ([
    0: ({ "Sự Kiện Thứ 2", "Double EXP", 1.5 }),
    1: ({ "Sự Kiện Thứ 3", "Double Money", 2.0 }),
    2: ({ "Sự Kiện Thứ 4", "Double Drop", 2.0 }),
    3: ({ "Sự Kiện Thứ 5", "Free VIP", 1.0 }),
    4: ({ "Sự Kiện Thứ 6", "Double KNB", 1.5 }),
    5: ({ "Sự Kiện Thứ 7", "Lucky Draw", 1.0 }),
    6: ({ "Sự Kiện Chủ Nhật", "Mega Event", 3.0 })
]);

// Daily challenge system
mapping daily_challenges = ([
    "kill_boss": ({ "Tiêu diệt Boss hàng ngày", 1, 500 }),
    "collect_items": ({ "Thu thập 50 items", 50, 200 }),
    "complete_tasks": ({ "Hoàn thành 20 nhiệm vụ", 20, 300 }),
    "reach_level": ({ "Lên 3 cấp", 3, 400 }),
    "earn_money": ({ "Kiếm 500,000 lượng", 500000, 250 }),
    "use_skills": ({ "Sử dụng 100 lần skill", 100, 150 }),
    "join_guild": ({ "Tham gia hoạt động bang phái", 1, 600 })
]);

// Get current day of week (0=Sunday, 1=Monday, etc.)
int get_current_day()
{
    mixed* time_data = localtime(time());
    return time_data[TIME_WDAY];
}

// Get daily boss
string get_daily_boss()
{
    int day = get_current_day();
    if (daily_bosses[day])
    {
        int* boss_data = daily_bosses[day];
        return boss_data[0];
    }
    return "Boss Mặc Định";
}

// Get daily item
string get_daily_item()
{
    int day = get_current_day();
    if (daily_items[day])
    {
        int* item_data = daily_items[day];
        return item_data[0];
    }
    return "Túi Quà Mặc Định";
}

// Get daily event
string get_daily_event()
{
    int day = get_current_day();
    if (daily_events[day])
    {
        int* event_data = daily_events[day];
        return event_data[0];
    }
    return "Sự Kiện Mặc Định";
}

// Spawn daily boss
void spawn_daily_boss()
{
    int day = get_current_day();
    if (daily_bosses[day])
    {
        int* boss_data = daily_bosses[day];
        string boss_name = boss_data[0];
        int boss_level = boss_data[1];
        int boss_hp = boss_data[2];
        int boss_exp = boss_data[3];
        string boss_file = boss_data[4];
        
        // Spawn boss at specific location
        object boss = new(boss_file);
        if (boss)
        {
            boss->set_level(boss_level);
            boss->set_max_hp(boss_hp);
            boss->set_hp(boss_hp);
            boss->add_to_scene(80, 150, 150); // Spawn at map 80, position 150,150
            
            // Announce to all players
            USER_D->user_channel(sprintf(HIR"Boss %s đã xuất hiện tại bản đồ 80! Hãy nhanh chóng tiêu diệt!", boss_name));
            
            log_file("daily_boss.dat", sprintf("%s Daily boss %s spawned\n", short_time(), boss_name));
        }
    }
}

// Give daily login reward
void give_daily_login_reward(object player)
{
    int day = get_current_day();
    int login_streak = player->get_save_2("daily_login.streak");
    int last_login_day = player->get_save_2("daily_login.day");
    
    // Check if consecutive login
    if (day == last_login_day)
    {
        send_user(player, "%c%s", '!', "Bạn đã nhận thưởng đăng nhập hôm nay rồi!");
        return;
    }
    
    // Check if consecutive login
    if (day == (last_login_day + 1) % 7 || login_streak == 0)
    {
        login_streak++;
    }
    else
    {
        login_streak = 1;
    }
    
    // Calculate reward based on streak
    int reward_knb = 50 + (login_streak * 10);
    int reward_cash = 10000 + (login_streak * 5000);
    
    // Give rewards
    "sys/sys/test_db"->add_yuanbao(player, reward_knb * 10);
    player->add_cash(reward_cash);
    
    // Give daily item
    if (daily_items[day])
    {
        int* item_data = daily_items[day];
        string item_file = item_data[1];
        object item = new(item_file);
        if (item)
        {
            int pos = item->move(player, -1);
            item->add_to_user(pos);
            send_user(player, "%c%s", '!', sprintf("Nhận được %s", item->get_name()));
        }
    }
    
    // Save login data
    player->set_save_2("daily_login.streak", login_streak);
    player->set_save_2("daily_login.day", day);
    
    // Announce reward
    send_user(player, "%c%s", ';', sprintf("Đăng nhập ngày thứ %d! Nhận được %d KNB và %d lượng", login_streak, reward_knb, reward_cash));
    
    log_file("daily_login.dat", sprintf("%s %s(%d) daily login streak %d\n", short_time(), player->get_id(), player->get_number(), login_streak));
}

// Apply daily event bonus
void apply_daily_event_bonus(object player)
{
    int day = get_current_day();
    if (daily_events[day])
    {
        int* event_data = daily_events[day];
        string event_name = event_data[0];
        string event_type = event_data[1];
        float bonus_multiplier = event_data[2];
        
        // Apply bonus based on event type
        switch (event_type)
        {
        case "Double EXP":
            player->set_save_2("daily_bonus.exp_multiplier", bonus_multiplier);
            break;
        case "Double Money":
            player->set_save_2("daily_bonus.money_multiplier", bonus_multiplier);
            break;
        case "Double Drop":
            player->set_save_2("daily_bonus.drop_multiplier", bonus_multiplier);
            break;
        case "Free VIP":
            if (!player->get_vip())
            {
                player->set_vip(1);
                player->set_save_2("daily_bonus.free_vip", 1);
            }
            break;
        case "Double KNB":
            player->set_save_2("daily_bonus.knb_multiplier", bonus_multiplier);
            break;
        }
        
        send_user(player, "%c%s", ';', sprintf("Sự kiện %s đang diễn ra! %s", event_name, event_type));
    }
}

// Check daily challenge completion
void check_daily_challenge(object player, string challenge_type, int progress)
{
    int day = get_current_day();
    string challenge_key = sprintf("daily_challenge.%d.%s", day, challenge_type);
    int current_progress = player->get_save_2(challenge_key);
    
    current_progress += progress;
    player->set_save_2(challenge_key, current_progress);
    
    if (daily_challenges[challenge_type])
    {
        int* challenge_data = daily_challenges[challenge_type];
        int required = challenge_data[1];
        int reward_exp = challenge_data[2];
        
        if (current_progress >= required)
        {
            // Check if already completed today
            if (!player->get_save_2(sprintf("daily_challenge_completed.%d.%s", day, challenge_type)))
            {
                // Give reward
                "sys/battlepass/battlepass"->add_battle_pass_exp(player, reward_exp);
                player->add_exp(reward_exp);
                
                // Mark as completed
                player->set_save_2(sprintf("daily_challenge_completed.%d.%s", day, challenge_type), 1);
                
                send_user(player, "%c%s", '!', sprintf("Hoàn thành thử thách: %s (+%d exp)", challenge_data[0], reward_exp));
            }
        }
    }
}

// Reset daily data
void reset_daily_data()
{
    // This would reset all players' daily data
    // For now, just log the reset
    log_file("daily_reset.dat", sprintf("%s Daily data reset\n", short_time()));
}

// Initialize daily system
void create()
{
    // Spawn daily boss at 9:00 AM
    call_out("spawn_daily_boss", 32400); // 9 hours = 32400 seconds
    
    // Reset daily data at midnight
    call_out("reset_daily_data", 86400); // 24 hours = 86400 seconds
}

// Check daily boss status
void check_daily_boss()
{
    // Check if boss is still alive, if not spawn new one
    call_out("check_daily_boss", 3600); // Check every hour
} 