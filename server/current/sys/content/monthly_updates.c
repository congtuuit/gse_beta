#include <ansi.h>
#include <time.h>
#include <effect.h>
#include <skill.h>
#include <item.h>
#include <map.h>
#include <action.h>
#include <string.h>

// Monthly rotation system
mapping monthly_bosses = ([
    1: ({ "Boss Tháng 1", "Tuyết Sơn Lão Tổ", 150, 500, 1000, "/npc/event/PhoBan/Boss60/CVQ.c" }),
    2: ({ "Boss Tháng 2", "Hỏa Diệm Ma Vương", 160, 550, 1200, "/npc/event/PhoBan/Boss60/KinhKha.c" }),
    3: ({ "Boss Tháng 3", "Thủy Long Vương", 170, 600, 1400, "/npc/event/PhoBan/Boss60/KinhKha2.c" }),
    4: ({ "Boss Tháng 4", "Mộc Thần", 180, 650, 1600, "/npc/event/PhoBan/Boss60/KinhKha3.c" }),
    5: ({ "Boss Tháng 5", "Kim Cương Ma Vương", 190, 700, 1800, "/npc/event/PhoBan/5Boss/Boss1-CVQ.c" }),
    6: ({ "Boss Tháng 6", "Thổ Địa Thần", 200, 750, 2000, "/npc/event/PhoBan/5Boss/Boss2-DM.c" }),
    7: ({ "Boss Tháng 7", "Phong Ma Vương", 210, 800, 2200, "/npc/event/PhoBan/5Boss/Boss3-CVQ.c" }),
    8: ({ "Boss Tháng 8", "Lôi Thần", 220, 850, 2400, "/npc/event/PhoBan/5Boss/Boss4-CVQ.c" }),
    9: ({ "Boss Tháng 9", "Quang Minh Thần", 230, 900, 2600, "/npc/event/PhoBan/5Boss/Boss5-CVQ.c" }),
    10: ({ "Boss Tháng 10", "Bóng Tối Ma Vương", 240, 950, 2800, "/npc/event/PhoBan/Boss60/CVQ.c" }),
    11: ({ "Boss Tháng 11", "Thiên Đế", 250, 1000, 3000, "/npc/event/PhoBan/Boss60/KinhKha.c" }),
    12: ({ "Boss Tháng 12", "Địa Ngục Chủ Tể", 260, 1050, 3200, "/npc/event/PhoBan/Boss60/KinhKha2.c" })
]);

mapping monthly_events = ([
    1: ({ "Sự Kiện Tháng 1", "Tết Nguyên Đán", "Lễ hội mùa xuân", 5.0 }),
    2: ({ "Sự Kiện Tháng 2", "Valentine", "Tình yêu và hoa hồng", 3.0 }),
    3: ({ "Sự Kiện Tháng 3", "Mùa Xuân", "Hoa đào nở rộ", 2.5 }),
    4: ({ "Sự Kiện Tháng 4", "Thanh Minh", "Tưởng nhớ tổ tiên", 2.0 }),
    5: ({ "Sự Kiện Tháng 5", "Mùa Hè", "Nắng vàng rực rỡ", 2.5 }),
    6: ({ "Sự Kiện Tháng 6", "Thiếu Nhi", "Ngày của trẻ em", 3.0 }),
    7: ({ "Sự Kiện Tháng 7", "Vu Lan", "Báo hiếu cha mẹ", 2.0 }),
    8: ({ "Sự Kiện Tháng 8", "Trung Thu", "Đêm trăng rằm", 4.0 }),
    9: ({ "Sự Kiện Tháng 9", "Mùa Thu", "Lá vàng rơi", 2.5 }),
    10: ({ "Sự Kiện Tháng 10", "Halloween", "Ma quỷ và kẹo", 3.5 }),
    11: ({ "Sự Kiện Tháng 11", "Mùa Đông", "Tuyết trắng", 2.5 }),
    12: ({ "Sự Kiện Tháng 12", "Giáng Sinh", "Ông già Noel", 5.0 })
]);

mapping monthly_rewards = ([
    1: ({ "Phần Thưởng Tháng 1", "/item/sell/0061.c", 3, 50000 }), // 3 VIP Packages
    2: ({ "Phần Thưởng Tháng 2", "/item/test2/TuiHoangKimThanhY.c", 5, 30000 }), // 5 Golden Bags
    3: ({ "Phần Thưởng Tháng 3", "/item/sell/ruongdutru.c", 3, 40000 }), // 3 Storage Boxes
    4: ({ "Phần Thưởng Tháng 4", "/item/sell/0012.c", 10, 20000 }), // 10 Basic Items
    5: ({ "Phần Thưởng Tháng 5", "/item/sell/0002.c", 15, 15000 }), // 15 Common Items
    6: ({ "Phần Thưởng Tháng 6", "/item/sell/0004.c", 20, 10000 }), // 20 Simple Items
    7: ({ "Phần Thưởng Tháng 7", "/item/sell/0031.c", 2, 60000 }), // 2 Mega Rewards
    8: ({ "Phần Thưởng Tháng 8", "/item/sell/0061.c", 2, 50000 }), // 2 VIP Packages
    9: ({ "Phần Thưởng Tháng 9", "/item/test2/TuiPhapBao.c", 5, 35000 }), // 5 Magic Bags
    10: ({ "Phần Thưởng Tháng 10", "/item/sell/ruongdutru.c", 4, 45000 }), // 4 Storage Boxes
    11: ({ "Phần Thưởng Tháng 11", "/item/sell/0012.c", 12, 25000 }), // 12 Basic Items
    12: ({ "Phần Thưởng Tháng 12", "/item/sell/0031.c", 3, 100000 }) // 3 Mega Rewards
]);

// Monthly challenges
mapping monthly_challenges = ([
    "kill_monthly_boss": ({ "Tiêu diệt Boss tháng", 1, 10000 }),
    "reach_monthly_level": ({ "Lên 50 cấp", 50, 8000 }),
    "complete_monthly_tasks": ({ "Hoàn thành 500 nhiệm vụ", 500, 5000 }),
    "earn_monthly_money": ({ "Kiếm 50,000,000 lượng", 50000000, 3000 }),
    "win_monthly_pvp": ({ "Thắng 200 trận PvP", 200, 6000 }),
    "collect_monthly_items": ({ "Thu thập 2000 items", 2000, 2000 }),
    "join_monthly_guild": ({ "Tham gia 100 hoạt động bang phái", 100, 8000 }),
    "reach_monthly_skill": ({ "Luyện 10 skill lên max", 10, 12000 })
]);

// Get current month
int get_current_month()
{
    mixed* time_data = localtime(time());
    return time_data[TIME_MON] + 1;
}

// Get current year
int get_current_year()
{
    mixed* time_data = localtime(time());
    return time_data[TIME_YEAR] + 1900;
}

// Get monthly boss
string get_monthly_boss()
{
    int month = get_current_month();
    if (monthly_bosses[month])
    {
        int* boss_data = monthly_bosses[month];
        return boss_data[1];
    }
    return "Boss Tháng Mặc Định";
}

// Get monthly event
string get_monthly_event()
{
    int month = get_current_month();
    if (monthly_events[month])
    {
        int* event_data = monthly_events[month];
        return event_data[1];
    }
    return "Sự Kiện Tháng Mặc Định";
}

// Spawn monthly boss
void spawn_monthly_boss()
{
    int month = get_current_month();
    if (monthly_bosses[month])
    {
        int* boss_data = monthly_bosses[month];
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
            boss->add_to_scene(80, 250, 250); // Spawn at map 80, position 250,250
            
            // Announce to all players
            USER_D->user_channel(sprintf(HIR"Boss Tháng %s đã xuất hiện tại bản đồ 80! Hãy nhanh chóng tiêu diệt!", boss_name));
            
            log_file("monthly_boss.dat", sprintf("%s Monthly boss %s spawned\n", short_time(), boss_name));
        }
    }
}

// Start monthly event
void start_monthly_event()
{
    int month = get_current_month();
    if (monthly_events[month])
    {
        int* event_data = monthly_events[month];
        string event_name = event_data[0];
        string event_type = event_data[1];
        string event_desc = event_data[2];
        float bonus_multiplier = event_data[3];
        
        // Apply monthly event bonus to all players
        object* users = USER_D->get_all_users();
        for (int i = 0; i < sizeof(users); i++)
        {
            if (users[i])
            {
                users[i]->set_save_2("monthly_event.type", event_type);
                users[i]->set_save_2("monthly_event.multiplier", bonus_multiplier);
                users[i]->set_save_2("monthly_event.month", month);
                
                send_user(users[i], "%c%s", ';', sprintf("Sự kiện tháng: %s - %s", event_name, event_desc));
            }
        }
        
        // Special handling for different event types
        switch (event_type)
        {
        case "Tết Nguyên Đán":
            start_tet_event();
            break;
        case "Valentine":
            start_valentine_event();
            break;
        case "Trung Thu":
            start_mid_autumn_event();
            break;
        case "Halloween":
            start_halloween_event();
            break;
        case "Giáng Sinh":
            start_christmas_event();
            break;
        default:
            start_general_monthly_event(event_type);
            break;
        }
        
        log_file("monthly_event.dat", sprintf("%s Monthly event %s started\n", short_time(), event_name));
    }
}

// Start Tết Nguyên Đán event
void start_tet_event()
{
    // Spawn special Tết items
    for (int i = 0; i < 20; i++)
    {
        object item = new("/item/sell/0031.c"); // Mega reward item
        if (item)
        {
            int x = random(300) + 50;
            int y = random(300) + 50;
            item->add_to_scene(80, x, y);
        }
    }
    
    // Give all players Tết bonus
    object* users = USER_D->get_all_users();
    for (int i = 0; i < sizeof(users); i++)
    {
        if (users[i])
        {
            "sys/sys/test_db"->add_yuanbao(users[i], 10000); // 1000 KNB
            users[i]->add_cash(1000000); // 1,000,000 lượng
        }
    }
    
    USER_D->user_channel(HIR"Chúc Mừng Năm Mới! Tất cả người chơi nhận được 1000 KNB và 1,000,000 lượng!");
}

// Start Valentine event
void start_valentine_event()
{
    // Spawn Valentine items
    for (int i = 0; i < 15; i++)
    {
        object item = new("/item/test2/TuiHoangKimThanhY.c"); // Golden bag
        if (item)
        {
            int x = random(300) + 50;
            int y = random(300) + 50;
            item->add_to_scene(80, x, y);
        }
    }
    
    USER_D->user_channel(HIM"Valentine Event: Hoa hồng và tình yêu đang chờ đợi!");
}

// Start Mid-Autumn event
void start_mid_autumn_event()
{
    // Spawn moon cakes and lanterns
    for (int i = 0; i < 25; i++)
    {
        object item = new("/item/sell/ruongdutru.c"); // Storage box
        if (item)
        {
            int x = random(300) + 50;
            int y = random(300) + 50;
            item->add_to_scene(80, x, y);
        }
    }
    
    USER_D->user_channel(HIY"Trung Thu: Bánh trung thu và đèn lồng đang chờ đợi!");
}

// Start Halloween event
void start_halloween_event()
{
    // Spawn Halloween items
    for (int i = 0; i < 30; i++)
    {
        object item = new("/item/test2/TuiPhapBao.c"); // Magic bag
        if (item)
        {
            int x = random(300) + 50;
            int y = random(300) + 50;
            item->add_to_scene(80, x, y);
        }
    }
    
    USER_D->user_channel(HIB"Halloween: Ma quỷ và kẹo đang chờ đợi!");
}

// Start Christmas event
void start_christmas_event()
{
    // Spawn Christmas presents
    for (int i = 0; i < 50; i++)
    {
        object item = new("/item/sell/0031.c"); // Mega reward
        if (item)
        {
            int x = random(300) + 50;
            int y = random(300) + 50;
            item->add_to_scene(80, x, y);
        }
    }
    
    // Give all players Christmas bonus
    object* users = USER_D->get_all_users();
    for (int i = 0; i < sizeof(users); i++)
    {
        if (users[i])
        {
            "sys/sys/test_db"->add_yuanbao(users[i], 15000); // 1500 KNB
            users[i]->add_cash(2000000); // 2,000,000 lượng
        }
    }
    
    USER_D->user_channel(HIG"Giáng Sinh: Ông già Noel đã mang quà đến! Tất cả nhận được 1500 KNB và 2,000,000 lượng!");
}

// Start general monthly event
void start_general_monthly_event(string event_type)
{
    // Spawn general items
    for (int i = 0; i < 10; i++)
    {
        object item = new("/item/sell/0012.c"); // Basic item
        if (item)
        {
            int x = random(300) + 50;
            int y = random(300) + 50;
            item->add_to_scene(80, x, y);
        }
    }
    
    USER_D->user_channel(sprintf(HIC"Sự kiện %s: Nhiều phần thưởng đang chờ đợi!", event_type));
}

// Give monthly login reward
void give_monthly_login_reward(object player)
{
    int month = get_current_month();
    int monthly_login_count = player->get_save_2("monthly_login.count");
    int last_month = player->get_save_2("monthly_login.month");
    
    // Check if new month
    if (month != last_month)
    {
        monthly_login_count = 0;
    }
    
    monthly_login_count++;
    
    // Give reward based on login count
    if (monthly_login_count >= 30)
    {
        // Full month login reward
        if (monthly_rewards[month])
        {
            int* reward_data = monthly_rewards[month];
            string item_file = reward_data[1];
            int item_count = reward_data[2];
            int bonus_knb = reward_data[3];
            
            // Give items
            for (int i = 0; i < item_count; i++)
            {
                object item = new(item_file);
                if (item)
                {
                    int pos = item->move(player, -1);
                    item->add_to_user(pos);
                    send_user(player, "%c%s", '!', sprintf("Nhận được %s", item->get_name()));
                }
            }
            
            // Give KNB bonus
            "sys/sys/test_db"->add_yuanbao(player, bonus_knb * 10);
            
            send_user(player, "%c%s", ';', sprintf("Đăng nhập đủ 30 ngày! Nhận được %d KNB", bonus_knb));
            
            // Reset count
            monthly_login_count = 0;
        }
    }
    
    // Save data
    player->set_save_2("monthly_login.count", monthly_login_count);
    player->set_save_2("monthly_login.month", month);
    
    log_file("monthly_login.dat", sprintf("%s %s(%d) monthly login count %d\n", short_time(), player->get_id(), player->get_number(), monthly_login_count));
}

// Check monthly challenge completion
void check_monthly_challenge(object player, string challenge_type, int progress)
{
    int month = get_current_month();
    string challenge_key = sprintf("monthly_challenge.%d.%s", month, challenge_type);
    int current_progress = player->get_save_2(challenge_key);
    
    current_progress += progress;
    player->set_save_2(challenge_key, current_progress);
    
    if (monthly_challenges[challenge_type])
    {
        int* challenge_data = monthly_challenges[challenge_type];
        int required = challenge_data[1];
        int reward_exp = challenge_data[2];
        
        if (current_progress >= required)
        {
            // Check if already completed this month
            if (!player->get_save_2(sprintf("monthly_challenge_completed.%d.%s", month, challenge_type)))
            {
                // Give reward
                "sys/battlepass/battlepass"->add_battle_pass_exp(player, reward_exp);
                player->add_exp(reward_exp);
                
                // Mark as completed
                player->set_save_2(sprintf("monthly_challenge_completed.%d.%s", month, challenge_type), 1);
                
                send_user(player, "%c%s", '!', sprintf("Hoàn thành thử thách tháng: %s (+%d exp)", challenge_data[0], reward_exp));
            }
        }
    }
}

// Reset monthly data
void reset_monthly_data()
{
    // Reset all players' monthly data
    object* users = USER_D->get_all_users();
    for (int i = 0; i < sizeof(users); i++)
    {
        if (users[i])
        {
            // Clear monthly event data
            users[i]->delete_save_2("monthly_event.type");
            users[i]->delete_save_2("monthly_event.multiplier");
            users[i]->delete_save_2("monthly_event.month");
            
            // Clear monthly challenge data
            users[i]->delete_save_2("monthly_challenge");
            users[i]->delete_save_2("monthly_challenge_completed");
        }
    }
    
    log_file("monthly_reset.dat", sprintf("%s Monthly data reset\n", short_time()));
}

// Initialize monthly system
void create()
{
    // Start monthly event on 1st of month at 9:00 AM
    call_out("start_monthly_event", 32400); // 9 hours = 32400 seconds
    
    // Spawn monthly boss on 15th of month at 2:00 PM
    call_out("spawn_monthly_boss", 50400); // 14 hours = 50400 seconds
    
    // Reset monthly data on last day of month at midnight
    call_out("reset_monthly_data", 2592000); // 30 days = 2592000 seconds
}

// Check monthly event status
void check_monthly_event()
{
    // Check if monthly event is still active
    call_out("check_monthly_event", 3600); // Check every hour
} 