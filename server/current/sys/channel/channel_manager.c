#include <channel.h>

// Channel Manager - Quản lý tất cả channel
private mapping channel_users = ([]);  // channel -> array of users
private mapping user_channels = ([]);  // user_id -> channel
private mapping channel_stats = ([]);  // channel -> stats

void create()
{
    // Khởi tạo các channel
    channel_users[CHANNEL_1] = ({});
    channel_users[CHANNEL_2] = ({});
    channel_users[CHANNEL_3] = ({});
    channel_users[CHANNEL_4] = ({});
    
    // Khởi tạo stats
    channel_stats[CHANNEL_1] = (["online": 0, "max": MAX_USERS_PER_CHANNEL]);
    channel_stats[CHANNEL_2] = (["online": 0, "max": MAX_USERS_PER_CHANNEL]);
    channel_stats[CHANNEL_3] = (["online": 0, "max": MAX_USERS_PER_CHANNEL]);
    channel_stats[CHANNEL_4] = (["online": 0, "max": MAX_USERS_PER_CHANNEL]);
}

// Thêm user vào channel
int add_user_to_channel(object user, int channel)
{
    if (!objectp(user) || !is_valid_channel(channel))
        return 0;
        
    string user_id = user->get_id();
    if (!user_id)
        return 0;
    
    // Xóa user khỏi channel cũ
    remove_user_from_channel(user);
    
    // Thêm vào channel mới
    channel_users[channel] += ({user});
    user_channels[user_id] = channel;
    
    // Cập nhật stats
    channel_stats[channel]["online"] = sizeof(channel_users[channel]);
    
    // Set channel cho user
    user->set_channel(channel);
    
    return 1;
}

// Xóa user khỏi channel
int remove_user_from_channel(object user)
{
    if (!objectp(user))
        return 0;
        
    string user_id = user->get_id();
    if (!user_id || !user_channels[user_id])
        return 0;
        
    int old_channel = user_channels[user_id];
    
    // Xóa khỏi array
    channel_users[old_channel] -= ({user});
    map_delete(user_channels, user_id);
    
    // Cập nhật stats
    channel_stats[old_channel]["online"] = sizeof(channel_users[old_channel]);
    
    return 1;
}

// Lấy tất cả user trong channel
object *get_channel_users(int channel)
{
    if (!is_valid_channel(channel))
        return ({});
        
    // Clean up disconnected users
    clean_channel_users(channel);
    
    return channel_users[channel];
}

// Clean up users đã disconnect
void clean_channel_users(int channel)
{
    if (!channel_users[channel])
        return;
        
    object *valid_users = ({});
    int i, size = sizeof(channel_users[channel]);
    
    for (i = 0; i < size; i++)
    {
        object user = channel_users[channel][i];
        if (objectp(user) && user->get_id())
            valid_users += ({user});
    }
    
    channel_users[channel] = valid_users;
    channel_stats[channel]["online"] = sizeof(valid_users);
}

// Kiểm tra channel hợp lệ
int is_valid_channel(int channel)
{
    return (channel >= CHANNEL_1 && channel <= MAX_CHANNELS);
}

// Lấy channel của user
int get_user_channel(object user)
{
    if (!objectp(user))
        return 0;
        
    string user_id = user->get_id();
    return user_channels[user_id] || 0;
}

// Broadcast message tới channel
int broadcast_to_channel(int channel, string message)
{
    object *users = get_channel_users(channel);
    int i, size = sizeof(users);
    
    for (i = 0; i < size; i++)
    {
        if (objectp(users[i]))
            send_user(users[i], "%c%s", '>', message);
    }
    
    return size;
}

// Lấy stats của channel
mapping get_channel_stats(int channel)
{
    if (!is_valid_channel(channel))
        return ([]);
        
    return channel_stats[channel];
}

// Lấy tất cả stats
mapping get_all_channel_stats()
{
    return channel_stats;
}

// Kiểm tra channel có đầy không
int is_channel_full(int channel)
{
    if (!is_valid_channel(channel))
        return 1;
        
    return channel_stats[channel]["online"] >= channel_stats[channel]["max"];
}

// Tìm channel ít người nhất
int find_least_populated_channel()
{
    int best_channel = CHANNEL_1;
    int min_users = channel_stats[CHANNEL_1]["online"];
    int i;
    
    for (i = CHANNEL_2; i <= MAX_CHANNELS; i++)
    {
        if (channel_stats[i]["online"] < min_users)
        {
            min_users = channel_stats[i]["online"];
            best_channel = i;
        }
    }
    
    return best_channel;
} 