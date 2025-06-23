#include <ansi.h>

string get_name() { return "Cleanup Zombie Connections"; }

int main(object me, string arg)
{
    object *users, user;
    int i, size, zombie_count = 0, total_count = 0;
    int force_disconnect = 0;
    
    if (is_player(me))
    {
        notify("Bạn không có đủ quyền.");
        return 1;
    }
    
    // Kiểm tra argument
    if (arg == "force")
    {
        force_disconnect = 1;
    }
    
    users = USER_D->get_user();
    size = sizeof(users);
    
    if (size == 0)
    {
        tell_user(me, "Không có người dùng nào online.");
        return 1;
    }
    
    tell_user(me, sprintf("Kiểm tra %d người dùng online...", size));
    
    for (i = 0; i < size; i++)
    {
        user = users[i];
        if (!objectp(user))
            continue;
            
        total_count++;
        
        // Kiểm tra zombie connection
        if (!interactive(user) || user->get_idle_time() > 60)
        {
            zombie_count++;
            
            if (force_disconnect)
            {
                tell_user(me, sprintf("Force disconnect zombie: %s (idle: %d, interactive: %d)", 
                    user->get_id(), user->get_idle_time(), interactive(user)));
                    
                if (user->get_login_flag() >= 2)
                {
                    QUIT_CMD->main(user, "");
                }
                else
                {
                    destruct(user);
                }
            }
            else
            {
                tell_user(me, sprintf("Zombie detected: %s (idle: %d, interactive: %d)", 
                    user->get_id(), user->get_idle_time(), interactive(user)));
            }
        }
    }
    
    if (force_disconnect)
    {
        tell_user(me, sprintf("Đã force disconnect %d zombie connections.", zombie_count));
        log_file("gm_cleanup.log", sprintf("%s GM %s force disconnected %d zombies\n", 
            short_time(), me->get_id(), zombie_count));
    }
    else
    {
        tell_user(me, sprintf("Tìm thấy %d zombie connections trong tổng số %d users.", zombie_count, total_count));
        if (zombie_count > 0)
        {
            tell_user(me, "Sử dụng 'cleanup force' để force disconnect tất cả zombies.");
        }
    }
    
    return 1;
} 