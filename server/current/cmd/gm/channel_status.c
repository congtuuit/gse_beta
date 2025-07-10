#include <ansi.h>

string get_name() { return "Channel Status Monitor"; }

int main(object me, string arg)
{
    int i;
    object *users;
    int user_count;
    int capacity;
    int percentage;
    string status_color;
    object *all_users;
    
    if (is_player(me))
    {
        notify("Bạn không có đủ quyền.");
        return 1;
    }
    
    if (!CHANNEL_D)
    {
        notify("Channel Manager chưa được khởi động.");
        return 1;
    }
    
    send_user(me, "%c%s", '>', "=== CHANNEL STATUS ===");
    
    for (i = 1; i <= 4; i++)
    {
        users = CHANNEL_D->get_channel_users(i);
        user_count = sizeof(users);
        capacity = 1000;
        percentage = (user_count * 100) / capacity;
        
        status_color = "";
        if (percentage >= 90) status_color = HIR;      // Red - Full
        else if (percentage >= 70) status_color = HIY; // Yellow - High
        else status_color = HIG;                       // Green - Normal
        
        send_user(me, "%c%s", '>', sprintf("Kênh %d: %s%d/%d (%d%%)%s", 
            i, status_color, user_count, capacity, percentage, NOR));
    }
    
    // Show total users
    all_users = USER_D->get_user();
    send_user(me, "%c%s", '>', sprintf("Tổng cộng: %d users online", sizeof(all_users)));
    send_user(me, "%c%s", '>', "=====================");
    
    return 1;
} 