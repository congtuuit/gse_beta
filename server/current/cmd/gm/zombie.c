#include <ansi.h>

string get_name() { return "Zombie Monitor Management"; }

int main(object me, string arg)
{
    object monitor;
    mapping stats;
    
    if (is_player(me))
    {
        notify("Bạn không có đủ quyền.");
        return 1;
    }
    
    if (!arg)
    {
        // Hiển thị thống kê
        monitor = find_object("/sys/sys/zombie_monitor");
        if (!monitor)
        {
            tell_user(me, "Zombie monitor chưa được khởi động.");
            tell_user(me, "Sử dụng 'zombie start' để khởi động monitor.");
            return 1;
        }
        
        stats = monitor->get_zombie_stats();
        tell_user(me, sprintf("=== Zombie Monitor Stats ===\n"));
        tell_user(me, sprintf("Current Users: %d\n", stats["current_users"]));
        tell_user(me, sprintf("Last Cleanup: %s\n", ctime(stats["last_cleanup"])));
        tell_user(me, sprintf("Total Cleanups: %d\n", stats["total_cleanups"]));
        tell_user(me, sprintf("Total Zombies Cleaned: %d\n", stats["total_zombies_cleaned"]));
        
        return 1;
    }
    
    if (arg == "start")
    {
        monitor = find_object("/sys/sys/zombie_monitor");
        if (monitor)
        {
            tell_user(me, "Zombie monitor đã đang chạy.");
            return 1;
        }
        
        monitor = new("/sys/sys/zombie_monitor");
        if (monitor)
        {
            tell_user(me, "Đã khởi động zombie monitor thành công.");
            log_file("gm_zombie.log", sprintf("%s GM %s started zombie monitor\n", 
                short_time(), me->get_id()));
        }
        else
        {
            tell_user(me, "Không thể khởi động zombie monitor.");
        }
        
        return 1;
    }
    
    if (arg == "stop")
    {
        monitor = find_object("/sys/sys/zombie_monitor");
        if (!monitor)
        {
            tell_user(me, "Zombie monitor không đang chạy.");
            return 1;
        }
        
        destruct(monitor);
        tell_user(me, "Đã dừng zombie monitor.");
        log_file("gm_zombie.log", sprintf("%s GM %s stopped zombie monitor\n", 
            short_time(), me->get_id()));
        
        return 1;
    }
    
    if (arg == "cleanup")
    {
        monitor = find_object("/sys/sys/zombie_monitor");
        if (!monitor)
        {
            tell_user(me, "Zombie monitor không đang chạy. Sử dụng 'zombie start' trước.");
            return 1;
        }
        
        monitor->cleanup_zombies();
        tell_user(me, "Đã thực hiện manual cleanup zombies.");
        
        return 1;
    }
    
    if (arg == "force")
    {
        monitor = find_object("/sys/sys/zombie_monitor");
        if (!monitor)
        {
            tell_user(me, "Zombie monitor không đang chạy. Sử dụng 'zombie start' trước.");
            return 1;
        }
        
        monitor->force_cleanup_zombies();
        tell_user(me, "Đã thực hiện force cleanup zombies.");
        
        return 1;
    }
    
    tell_user(me, "Cách sử dụng:\n");
    tell_user(me, "zombie          - Hiển thị thống kê\n");
    tell_user(me, "zombie start    - Khởi động monitor\n");
    tell_user(me, "zombie stop     - Dừng monitor\n");
    tell_user(me, "zombie cleanup  - Manual cleanup\n");
    tell_user(me, "zombie force    - Force cleanup\n");
    
    return 1;
} 