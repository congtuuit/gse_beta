#include <npc.h>
#include <ansi.h>
#include <equip.h>

inherit OFFICER;

// NPC appearance
int get_char_picid() { return 5302; }
int is_self_look() { return 1; }

// Achievement functions
void show_achievements(object who);
void show_achievement_category(object who, string category);
void show_achievement_tier(object who, string tier);
void show_achievement_stats(object who);
void reset_achievements(object who);

// Create NPC
void create()
{
    set_name("Achievement Master");
    set_real_name(HIG "Thành Tựu Sư" NOR);
    
    set_2("talk", ([
        "achievements": (: show_achievements :),
        "combat": (: show_achievement_category, "combat" :),
        "level": (: show_achievement_category, "level" :),
        "skill": (: show_achievement_category, "skill" :),
        "item": (: show_achievement_category, "item" :),
        "social": (: show_achievement_category, "social" :),
        "exploration": (: show_achievement_category, "exploration" :),
        "collection": (: show_achievement_category, "collection" :),
        "event": (: show_achievement_category, "event" :),
        "bronze": (: show_achievement_tier, "bronze" :),
        "silver": (: show_achievement_tier, "silver" :),
        "gold": (: show_achievement_tier, "gold" :),
        "platinum": (: show_achievement_tier, "platinum" :),
        "diamond": (: show_achievement_tier, "diamond" :),
        "stats": (: show_achievement_stats :),
        "reset": (: reset_achievements :),
    ]));

    setup();
}

// Main interaction
void do_look(object who)
{
    int id = getoid(this_object());
    string intro = sprintf("Bạn thấy %s đang nghiên cứu sách thành tựu.\n\n", get_name());
    
    intro += "=== THÀNH TỰU SƯ ===\n";
    intro += "Ta là người quản lý hệ thống thành tựu của thế giới này.\n";
    intro += "Hãy nói chuyện với ta để xem thành tựu của bạn.\n\n";
    
    intro += "Các lệnh có thể sử dụng:\n";
    intro += "- achievements: Xem tất cả thành tựu\n";
    intro += "- combat: Thành tựu chiến đấu\n";
    intro += "- level: Thành tựu cấp độ\n";
    intro += "- skill: Thành tựu kỹ năng\n";
    intro += "- item: Thành tựu vật phẩm\n";
    intro += "- social: Thành tựu xã hội\n";
    intro += "- exploration: Thành tựu khám phá\n";
    intro += "- collection: Thành tựu sưu tầm\n";
    intro += "- event: Thành tựu sự kiện\n";
    intro += "- stats: Thống kê thành tựu\n";
    intro += "- reset: Reset thành tựu (chỉ cho admin)\n";
    
    send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), intro);
}

// Show all achievements
void show_achievements(object who)
{
    "sys/achievement/achievement"->show_achievement_interface(who);
}

// Show achievements by category
void show_achievement_category(object who, string category)
{
    int category_id = 0;
    
    switch (category)
    {
    case "combat": category_id = 1; break;
    case "level": category_id = 2; break;
    case "skill": category_id = 3; break;
    case "item": category_id = 4; break;
    case "social": category_id = 5; break;
    case "exploration": category_id = 6; break;
    case "collection": category_id = 7; break;
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
            int current = "sys/achievement/achievement"->get_achievement_progress(who, achievement_id);
            int completed = "sys/achievement/achievement"->is_achievement_completed(who, achievement_id);
            
            string tier_name = "sys/achievement/achievement"->get_tier_name(tier);
            string status = completed ? HIG"✓ Hoàn thành" : 
                (current > 0 ? HIY"Đang tiến hành" : HIW"Chưa bắt đầu");
            
            msg += sprintf("%s (%s): %s (%d/%d) - %s\n", 
                name, tier_name, description, current, required, status);
        }
    }
    
    send_user(who, "%c%s", ';', msg);
}

// Show achievements by tier
void show_achievement_tier(object who, string tier)
{
    int tier_id = 0;
    
    switch (tier)
    {
    case "bronze": tier_id = 1; break;
    case "silver": tier_id = 2; break;
    case "gold": tier_id = 3; break;
    case "platinum": tier_id = 4; break;
    case "diamond": tier_id = 5; break;
    default: tier_id = 1; break;
    }
    
    string msg = sprintf("=== THÀNH TỰU %s ===\n\n", "sys/achievement/achievement"->get_tier_name(tier_id));
    
    string* achievement_ids = "sys/achievement/achievement"->get_achievements_by_tier(tier_id);
    
    for (int i = 0; i < sizeof(achievement_ids); i++)
    {
        string achievement_id = achievement_ids[i];
        int* data = "sys/achievement/achievement"->get_achievement_data(achievement_id);
        
        if (data)
        {
            string name = data[0];
            string description = data[1];
            int category = data[2];
            int required = data[4];
            int current = "sys/achievement/achievement"->get_achievement_progress(who, achievement_id);
            int completed = "sys/achievement/achievement"->is_achievement_completed(who, achievement_id);
            
            string category_name = "sys/achievement/achievement"->get_category_name(category);
            string status = completed ? HIG"✓ Hoàn thành" : 
                (current > 0 ? HIY"Đang tiến hành" : HIW"Chưa bắt đầu");
            
            msg += sprintf("%s (%s): %s (%d/%d) - %s\n", 
                name, category_name, description, current, required, status);
        }
    }
    
    send_user(who, "%c%s", ';', msg);
}

// Show achievement statistics
void show_achievement_stats(object who)
{
    int total = "sys/achievement/achievement"->get_total_achievements();
    int completed = "sys/achievement/achievement"->get_completed_achievements(who);
    float rate = "sys/achievement/achievement"->get_achievement_completion_rate(who);
    
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
            if ("sys/achievement/achievement"->is_achievement_completed(who, achievement_ids[i]))
            {
                category_completed++;
            }
        }
        
        float category_rate = (float)category_completed / sizeof(achievement_ids) * 100;
        msg += sprintf("%s: %d/%d (%.1f%%)\n", category_name, category_completed, sizeof(achievement_ids), category_rate);
    }
    
    msg += "\n";
    
    // Show by tiers
    for (int tier = 1; tier <= 5; tier++)
    {
        string tier_name = "sys/achievement/achievement"->get_tier_name(tier);
        string* achievement_ids = "sys/achievement/achievement"->get_achievements_by_tier(tier);
        int tier_completed = 0;
        
        for (int i = 0; i < sizeof(achievement_ids); i++)
        {
            if ("sys/achievement/achievement"->is_achievement_completed(who, achievement_ids[i]))
            {
                tier_completed++;
            }
        }
        
        float tier_rate = (float)tier_completed / sizeof(achievement_ids) * 100;
        msg += sprintf("%s: %d/%d (%.1f%%)\n", tier_name, tier_completed, sizeof(achievement_ids), tier_rate);
    }
    
    send_user(who, "%c%s", ';', msg);
}

// Reset achievements (admin only)
void reset_achievements(object who)
{
    if (who->get_level() < 100) // Only for high level players (admin check)
    {
        send_user(who, "%c%s", '!', "Bạn không có quyền reset thành tựu!");
        return;
    }
    
    "sys/achievement/achievement"->reset_all_achievements(who);
    send_user(who, "%c%s", '!', "Đã reset tất cả thành tựu!");
}

// Talk function
void do_talk(object who, string topic)
{
    if (topic == "achievements")
    {
        show_achievements(who);
    }
    else if (topic == "combat" || topic == "level" || topic == "skill" || 
             topic == "item" || topic == "social" || topic == "exploration" || 
             topic == "collection" || topic == "event")
    {
        show_achievement_category(who, topic);
    }
    else if (topic == "bronze" || topic == "silver" || topic == "gold" || 
             topic == "platinum" || topic == "diamond")
    {
        show_achievement_tier(who, topic);
    }
    else if (topic == "stats")
    {
        show_achievement_stats(who);
    }
    else if (topic == "reset")
    {
        reset_achievements(who);
    }
    else
    {
        send_user(who, "%c%s", ';', "Hãy nói 'achievements' để xem thành tựu của bạn.");
    }
} 