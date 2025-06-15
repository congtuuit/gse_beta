#include <cmd.h>
#include <public.h>

// Test command cho VIP Chat
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
        show_vip_test_help(me);
        return 1;
    }
    
    if (sscanf(arg, "%s %s", cmd, param) != 2)
        cmd = arg;
    
    switch (cmd)
    {
        case "status":
            test_vip_status(me);
            break;
            
        case "set":
            test_set_vip(me, param);
            break;
            
        case "chat":
            test_vip_chat(me, param);
            break;
            
        case "list":
            test_list_vip_users(me);
            break;
            
        case "help":
            show_vip_test_help(me);
            break;
            
        default:
            notify("Lệnh không hợp lệ. Gõ 'vip_test help' để xem hướng dẫn.");
            break;
    }
    
    return 1;
}

// Hiển thị help
void show_vip_test_help(object me)
{
    string help = @HELP
Lệnh test VIP Chat:
  vip_test status - Kiểm tra VIP status của bản thân
  vip_test set [user_id] [0/1] - Set VIP status cho user
  vip_test chat [msg] - Test VIP chat (gửi tới tất cả VIP users)
  vip_test list - Liệt kê tất cả VIP users
  vip_test help - Hiển thị hướng dẫn này

Ví dụ:
  vip_test status
  vip_test set player123 1
  vip_test chat "Hello VIP users!"
  vip_test list
HELP;
    
    send_user(me, "%c%s", '>', help);
}

// Test VIP status
void test_vip_status(object me)
{
    int vip_status = me->get_vip();
    string status_text = vip_status ? "VIP" : "Normal";
    
    send_user(me, "%c%s", '>', sprintf("=== VIP STATUS ==="));
    send_user(me, "%c%s", '>', sprintf("User: %s", me->get_name()));
    send_user(me, "%c%s", '>', sprintf("Status: %s", status_text));
    send_user(me, "%c%s", '>', sprintf("Channel: %d", me->get_channel()));
    send_user(me, "%c%s", '>', "================");
}

// Test set VIP
void test_set_vip(object me, string param)
{
    string user_id;
    int vip_status;
    
    if (!param || sscanf(param, "%s %d", user_id, vip_status) != 2)
    {
        notify("Cú pháp: vip_test set [user_id] [0/1]");
        return;
    }
    
    if (vip_status != 0 && vip_status != 1)
    {
        notify("VIP status phải là 0 hoặc 1.");
        return;
    }
    
    object target = find_player(user_id);
    if (!target)
    {
        notify("Không tìm thấy người chơi.");
        return;
    }
    
    target->set_vip(vip_status);
    
    string status_text = vip_status ? "VIP" : "Normal";
    notify(sprintf("Đã set %s thành %s.", target->get_name(), status_text));
    
    send_user(target, "%c%s", '>', sprintf("Bạn đã được set thành %s bởi GM %s.", 
        status_text, me->get_name()));
}

// Test VIP chat
void test_vip_chat(object me, string param)
{
    if (!param)
    {
        notify("Cú pháp: vip_test chat [message]");
        return;
    }
    
    // Gửi VIP message tới tất cả VIP users
    CHAT_D->vip_channel(0, sprintf("[VIP TEST] %s: %s", me->get_name(), param));
    
    notify(sprintf("Đã gửi VIP message: %s", param));
}

// Test list VIP users
void test_list_vip_users(object me)
{
    if (!CHANNEL_D)
    {
        notify("Channel Manager chưa được load!");
        return;
    }
    
    object *all_vip_users = ({});
    int i;
    
    for (i = 1; i <= 4; i++)
    {
        object *channel_users = CHANNEL_D->get_channel_users(i);
        int j, size = sizeof(channel_users);
        
        for (j = 0; j < size; j++)
        {
            object user = channel_users[j];
            if (objectp(user) && user->get_vip())
            {
                all_vip_users += ({user});
            }
        }
    }
    
    // Loại bỏ duplicate users
    all_vip_users = unique_array(all_vip_users);
    
    send_user(me, "%c%s", '>', "=== VIP USERS LIST ===");
    
    if (sizeof(all_vip_users) == 0)
    {
        send_user(me, "%c%s", '>', "Không có VIP users nào.");
    }
    else
    {
        int k, vip_size = sizeof(all_vip_users);
        for (k = 0; k < vip_size; k++)
        {
            object vip_user = all_vip_users[k];
            send_user(me, "%c%s", '>', sprintf("%d. %s (%s) - Channel %d", 
                k + 1, vip_user->get_name(), vip_user->get_id(), vip_user->get_channel()));
        }
    }
    
    send_user(me, "%c%s", '>', sprintf("Tổng cộng: %d VIP users", sizeof(all_vip_users)));
    send_user(me, "%c%s", '>', "=====================");
} 