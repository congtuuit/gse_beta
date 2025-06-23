#include <public.h>

#define MONITOR_INTERVAL    60    // Monitor mỗi 60 giây
#define ZOMBIE_THRESHOLD    60    // Timeout zombie sau 60 giây
#define MAX_ZOMBIE_RATIO    0.3   // Tối đa 30% zombie connections

private int last_cleanup_time = 0;
private int total_cleanups = 0;
private int total_zombies_cleaned = 0;

void create()
{
    call_out("monitor_zombies", MONITOR_INTERVAL);
}

void monitor_zombies()
{
    object *users, user;
    int i, size, zombie_count = 0, total_users = 0;
    int current_time = time();
    
    users = USER_D->get_user();
    size = sizeof(users);
    
    if (size == 0)
    {
        call_out("monitor_zombies", MONITOR_INTERVAL);
        return;
    }
    
    // Đếm zombie connections
    for (i = 0; i < size; i++)
    {
        user = users[i];
        if (!objectp(user))
            continue;
            
        total_users++;
        
        if (!interactive(user) || user->get_idle_time() > ZOMBIE_THRESHOLD)
        {
            zombie_count++;
        }
    }
    
    // Log thống kê
    if (zombie_count > 0)
    {
        float zombie_ratio = (float)zombie_count / total_users;
        
        log_file("zombie_monitor.log", sprintf("%s Users: %d, Zombies: %d, Ratio: %.2f%%\n", 
            short_time(), total_users, zombie_count, zombie_ratio * 100));
        
        // Nếu tỷ lệ zombie quá cao, force cleanup
        if (zombie_ratio > MAX_ZOMBIE_RATIO)
        {
            force_cleanup_zombies();
        }
        // Nếu có zombie và đã qua 5 phút từ lần cleanup cuối
        else if (current_time - last_cleanup_time > 300)
        {
            cleanup_zombies();
        }
    }
    
    call_out("monitor_zombies", MONITOR_INTERVAL);
}

void cleanup_zombies()
{
    object *users, user;
    int i, size, cleaned = 0;
    
    users = USER_D->get_user();
    size = sizeof(users);
    
    for (i = 0; i < size; i++)
    {
        user = users[i];
        if (!objectp(user))
            continue;
            
        if (!interactive(user) || user->get_idle_time() > ZOMBIE_THRESHOLD)
        {
            log_file("zombie_cleanup.log", sprintf("%s Cleanup zombie: %s (idle: %d, interactive: %d)\n", 
                short_time(), user->get_id(), user->get_idle_time(), interactive(user)));
                
            if (user->get_login_flag() >= 2)
            {
                QUIT_CMD->main(user, "");
            }
            else
            {
                destruct(user);
            }
            cleaned++;
        }
    }
    
    if (cleaned > 0)
    {
        last_cleanup_time = time();
        total_cleanups++;
        total_zombies_cleaned += cleaned;
        
        log_file("zombie_cleanup.log", sprintf("%s Cleaned %d zombies. Total: %d cleanups, %d zombies\n", 
            short_time(), cleaned, total_cleanups, total_zombies_cleaned));
    }
}

void force_cleanup_zombies()
{
    object *users, user;
    int i, size, cleaned = 0;
    
    users = USER_D->get_user();
    size = sizeof(users);
    
    log_file("zombie_cleanup.log", sprintf("%s FORCE CLEANUP - High zombie ratio detected\n", short_time()));
    
    for (i = 0; i < size; i++)
    {
        user = users[i];
        if (!objectp(user))
            continue;
            
        if (!interactive(user) || user->get_idle_time() > ZOMBIE_THRESHOLD)
        {
            log_file("zombie_cleanup.log", sprintf("%s FORCE cleanup zombie: %s (idle: %d, interactive: %d)\n", 
                short_time(), user->get_id(), user->get_idle_time(), interactive(user)));
                
            if (user->get_login_flag() >= 2)
            {
                QUIT_CMD->main(user, "");
            }
            else
            {
                destruct(user);
            }
            cleaned++;
        }
    }
    
    last_cleanup_time = time();
    total_cleanups++;
    total_zombies_cleaned += cleaned;
    
    log_file("zombie_cleanup.log", sprintf("%s FORCE cleaned %d zombies. Total: %d cleanups, %d zombies\n", 
        short_time(), cleaned, total_cleanups, total_zombies_cleaned));
}

// Function để lấy thống kê
mapping get_zombie_stats()
{
    return ([
        "last_cleanup": last_cleanup_time,
        "total_cleanups": total_cleanups,
        "total_zombies_cleaned": total_zombies_cleaned,
        "current_users": sizeof(USER_D->get_user())
    ]);
} 