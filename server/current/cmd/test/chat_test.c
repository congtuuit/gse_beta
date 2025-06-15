#include <cmd.h>
#include <public.h>

// Test command cho Chat Channel
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
        show_chat_test_help(me);
        return 1;
    }
    
    if (sscanf(arg, "%s %s", cmd, param) != 2)
        cmd = arg;
    
    switch (cmd)
    {
        case "chat":
            test_chat_channel(me, param);
            break;
            
        case "rumor":
            test_rumor_channel(me, param);
            break;
            
        case "sys":
            test_sys_channel(me, param);
            break;
            
        case "vip":
            test_vip_channel(me, param);
            break;
            
        case "vip_specific":
            test_vip_specific(me, param);
            break;
            
        case "all":
            test_all_channels(me, param);
            break;
            
        case "help":
            show_chat_test_help(me);
            break;
            
        default:
            notify("Lệnh không hợp lệ. Gõ 'chat_test help' để xem hướng dẫn.");
            break;
    }
    
    return 1;
}

// Hiển thị help
void show_chat_test_help(object me)
{
    string help = @HELP
Lệnh test Chat Channel:
  chat_test chat [channel] [msg] - Test chat trong channel cụ thể
  chat_test rumor [channel] [msg] - Test rumor trong channel cụ thể
  chat_test sys [channel] [msg] - Test system message trong channel
  chat_test vip [channel] [msg] - Test VIP chat (tất cả VIP users thấy, không phân biệt channel)
  chat_test vip_specific [channel] [msg] - Test VIP chat trong channel cụ thể
  chat_test all [msg] - Test gửi tới tất cả channel
  chat_test help - Hiển thị hướng dẫn này

Ví dụ:
  chat_test chat 1 "Hello Channel 1"
  chat_test rumor 2 "Rumor in Channel 2"
  chat_test sys 0 "System message to all"
  chat_test vip 1 "VIP message to all VIP users"
  chat_test vip_specific 2 "VIP message to channel 2 only"

Lưu ý:
  - VIP chat thường gửi tới tất cả VIP users ở mọi channel
  - VIP chat specific chỉ gửi tới VIP users trong channel cụ thể
HELP;
    
    send_user(me, "%c%s", '>', help);
}

// Test chat channel
void test_chat_channel(object me, string param)
{
    int channel;
    string message;
    
    if (!param || sscanf(param, "%d %s", channel, message) != 2)
    {
        notify("Cú pháp: chat_test chat [channel] [message]");
        return;
    }
    
    if (channel < 1 || channel > 4)
    {
        notify("Channel phải từ 1-4.");
        return;
    }
    
    if (!CHANNEL_D)
    {
        notify("Channel Manager chưa được load!");
        return;
    }
    
    // Gửi chat message tới channel cụ thể
    CHAT_D->chat_channel(channel, sprintf("[TEST] %s: %s", me->get_name(), message));
    
    notify(sprintf("Đã gửi chat message tới channel %d: %s", channel, message));
}

// Test rumor channel
void test_rumor_channel(object me, string param)
{
    int channel;
    string message;
    
    if (!param || sscanf(param, "%d %s", channel, message) != 2)
    {
        notify("Cú pháp: chat_test rumor [channel] [message]");
        return;
    }
    
    if (channel < 1 || channel > 4)
    {
        notify("Channel phải từ 1-4.");
        return;
    }
    
    // Gửi rumor message tới channel cụ thể
    CHAT_D->rumor_channel(channel, sprintf("[TEST RUMOR] %s: %s", me->get_name(), message));
    
    notify(sprintf("Đã gửi rumor message tới channel %d: %s", channel, message));
}

// Test system channel
void test_sys_channel(object me, string param)
{
    int channel;
    string message;
    
    if (!param || sscanf(param, "%d %s", channel, message) != 2)
    {
        notify("Cú pháp: chat_test sys [channel] [message]");
        return;
    }
    
    if (channel < 0 || channel > 4)
    {
        notify("Channel phải từ 0-4 (0 = toàn server).");
        return;
    }
    
    // Gửi system message
    CHAT_D->sys_channel(channel, sprintf("[TEST SYSTEM] %s: %s", me->get_name(), message));
    
    if (channel == 0)
        notify("Đã gửi system message tới toàn server.");
    else
        notify(sprintf("Đã gửi system message tới channel %d.", channel));
}

// Test VIP channel
void test_vip_channel(object me, string param)
{
    int channel;
    string message;
    
    if (!param || sscanf(param, "%d %s", channel, message) != 2)
    {
        notify("Cú pháp: chat_test vip [channel] [message]");
        return;
    }
    
    if (channel < 1 || channel > 4)
    {
        notify("Channel phải từ 1-4.");
        return;
    }
    
    // Gửi VIP message tới tất cả VIP users (không phân biệt channel)
    CHAT_D->vip_channel(channel, sprintf("[TEST VIP] %s: %s", me->get_name(), message));
    
    notify(sprintf("Đã gửi VIP message tới tất cả VIP users (không phân biệt channel): %s", message));
}

// Test VIP channel specific
void test_vip_specific(object me, string param)
{
    int channel;
    string message;
    
    if (!param || sscanf(param, "%d %s", channel, message) != 2)
    {
        notify("Cú pháp: chat_test vip_specific [channel] [message]");
        return;
    }
    
    if (channel < 1 || channel > 4)
    {
        notify("Channel phải từ 1-4.");
        return;
    }
    
    // Gửi VIP message tới channel cụ thể
    CHAT_D->vip_channel_specific(channel, sprintf("[TEST VIP SPECIFIC] %s: %s", me->get_name(), message));
    
    notify(sprintf("Đã gửi VIP message tới channel %d: %s", channel, message));
}

// Test all channels
void test_all_channels(object me, string param)
{
    if (!param)
    {
        notify("Cú pháp: chat_test all [message]");
        return;
    }
    
    // Gửi message tới tất cả channel
    CHAT_D->chat_all_channels(sprintf("[TEST ALL] %s: %s", me->get_name(), param));
    
    notify("Đã gửi message tới tất cả channel.");
} 