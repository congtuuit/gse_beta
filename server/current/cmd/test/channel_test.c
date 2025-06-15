#include <cmd.h>
#include <public.h>

// Test command cho Channel Manager
int main(object me, string arg)
{
    string cmd, param;
    
    if (!is_gm(me))
    {
        notify("Chỉ GM mới có thể test.");
        return 1;
    }
    
    if (!arg)
    {
        show_test_help(me);
        return 1;
    }
    
    if (sscanf(arg, "%s %s", cmd, param) != 2)
        cmd = arg;
    
    if (!CHANNEL_D)
    {
        notify("Channel Manager chưa được load!");
        return 1;
    }
    
    switch (cmd)
    {
        case "info":
            test_channel_info(me);
            break;
            
        case "add":
            test_add_user(me, param);
            break;
            
        case "remove":
            test_remove_user(me);
            break;
            
        case "broadcast":
            test_broadcast(me, param);
            break;
            
        case "stats":
            test_stats(me);
            break;
            
        case "clean":
            test_clean(me);
            break;
            
        case "help":
            show_test_help(me);
            break;
            
        default:
            notify("Lệnh không hợp lệ. Gõ 'channel_test help' để xem hướng dẫn.");
            break;
    }
    
    return 1;
}

// Hiển thị help
void show_test_help(object me)
{
    string help = @HELP
Lệnh test Channel Manager:
  channel_test info      - Test thông tin channel
  channel_test add [ch]  - Test thêm user vào channel
  channel_test remove    - Test xóa user khỏi channel
  channel_test broadcast [msg] - Test broadcast message
  channel_test stats     - Test thống kê
  channel_test clean     - Test dọn dẹp
  channel_test help      - Hiển thị hướng dẫn này
HELP;
    
    send_user(me, "%c%s", '>', help);
}

// Test channel info
void test_channel_info(object me)
{
    send_user(me, "%c%s", '>', "=== TEST CHANNEL INFO ===");
    
    int i;
    for (i = 1; i <= 4; i++)
    {
        object *users = CHANNEL_D->get_channel_users(i);
        
        send_user(me, "%c%s", '>', sprintf("Channel %d: Users: %d", 
            i, sizeof(users)));
    }
    
    send_user(me, "%c%s", '>', "========================");
}

// Test add user
void test_add_user(object me, string param)
{
    int channel;
    
    if (!param || sscanf(param, "%d", channel) != 1)
    {
        channel = 1; // Default to channel 1
    }
    
    if (channel < 1 || channel > 4)
    {
        notify("Channel không hợp lệ.");
        return;
    }
    
    int old_channel = CHANNEL_D->get_user_channel(me);
    if (CHANNEL_D->add_user_to_channel(me, channel))
    {
        notify(sprintf("Test thành công: Đã chuyển từ channel %d sang channel %d", 
            old_channel, channel));
    }
    else
    {
        notify("Test thất bại: Không thể thêm user vào channel.");
    }
}

// Test remove user
void test_remove_user(object me)
{
    int old_channel = CHANNEL_D->get_user_channel(me);
    if (CHANNEL_D->remove_user_from_channel(me))
    {
        notify(sprintf("Test thành công: Đã xóa user khỏi channel %d", old_channel));
    }
    else
    {
        notify("Test thất bại: Không thể xóa user khỏi channel.");
    }
}

// Test broadcast
void test_broadcast(object me, string param)
{
    if (!param)
        param = "Test message";
    
    int channel = CHANNEL_D->get_user_channel(me);
    if (channel == 0)
    {
        notify("Bạn chưa ở trong channel nào.");
        return;
    }
    
    int count = CHANNEL_D->broadcast_to_channel(channel, 
        sprintf("[TEST] %s", param));
    
    notify(sprintf("Test thành công: Đã gửi tin nhắn tới %d user trong channel %d", 
        count, channel));
}

// Test stats
void test_stats(object me)
{
    send_user(me, "%c%s", '>', "=== TEST CHANNEL STATS ===");
    
    string *info = CHANNEL_D->get_all_channels_info();
    
    int i, size = sizeof(info);
    for (i = 0; i < size; i++)
    {
        send_user(me, "%c%s", '>', info[i]);
    }
    
    send_user(me, "%c%s", '>', "=========================");
}

// Test clean
void test_clean(object me)
{
    send_user(me, "%c%s", '>', "=== TEST CLEANUP ===");
    
    int i;
    for (i = 1; i <= 4; i++)
    {
        int before = sizeof(CHANNEL_D->get_channel_users(i));
        CHANNEL_D->clean_channel_users(i);
        int after = sizeof(CHANNEL_D->get_channel_users(i));
        
        send_user(me, "%c%s", '>', sprintf("Channel %d: %d -> %d users", 
            i, before, after));
    }
    
    send_user(me, "%c%s", '>', "===================");
} 