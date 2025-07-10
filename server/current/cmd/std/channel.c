#include <cmd.h>
#include <public.h>

string get_name() { return "Channel Switch"; }

int main(object me, string arg)
{
    int new_channel;
    int current_channel;
    object *target_users;
    
    if (!arg)
    {
        tell_user(me, "Cú pháp: channel [1-4]");
        tell_user(me, "Ví dụ: channel 2 - Chuyển sang kênh 2");
        return 1;
    }
    
    if (sscanf(arg, "%d", new_channel) != 1)
    {
        tell_user(me, "Cú pháp: channel [1-4]");
        return 1;
    }
    
    if (new_channel < 1 || new_channel > 4)
    {
        tell_user(me, "Channel phải từ 1-4.");
        return 1;
    }
    
    current_channel = me->get_channel();
    if (current_channel == new_channel)
    {
        tell_user(me, sprintf("Bạn đã ở kênh %d rồi.", current_channel));
        return 1;
    }
    
    if (!CHANNEL_D)
    {
        tell_user(me, "Channel Manager chưa được khởi động.");
        return 1;
    }
    
    // Check if target channel is full
    target_users = CHANNEL_D->get_channel_users(new_channel);
    if (sizeof(target_users) >= 1000)
    {
        tell_user(me, sprintf("Kênh %d đã đầy, vui lòng thử kênh khác.", new_channel));
        return 1;
    }
    
    // Switch channel
    if (CHANNEL_D->add_user_to_channel(me, new_channel))
    {
        tell_user(me, sprintf("Đã chuyển từ kênh %d sang kênh %d.", current_channel, new_channel));
        
        // Notify users in old channel
        if (current_channel > 0)
        {
            CHAT_D->chat_channel(current_channel, sprintf("%s đã rời khỏi kênh.", me->get_name()));
        }
        
        // Notify users in new channel
        CHAT_D->chat_channel(new_channel, sprintf("%s đã tham gia kênh.", me->get_name()));
        
        // Update user's channel display
        me->set_channel(new_channel);
    }
    else
    {
        tell_user(me, "Không thể chuyển kênh, vui lòng thử lại.");
    }
    
    return 1;
} 