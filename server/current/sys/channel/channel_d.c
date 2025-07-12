
#include <public.h>
#include <ansi.h>

#define MAX_CHANNELS           4
#define MAX_USERS_PER_CHANNEL  1000
#define CLEANUP_INTERVAL       15    // Cleanup mỗi 15 giây thay vì 30
#define ZOMBIE_TIMEOUT         60    // Timeout zombie connection sau 60 giây
#define FORCE_DISCONNECT_TIME  120   // Force disconnect sau 120 giây

#define CHANNEL_STATUS_OFFLINE     0
#define CHANNEL_STATUS_ONLINE      1
#define CHANNEL_STATUS_MAINTENANCE 2

private mapping channel_users = ([]);  // channel -> array of users
private mapping user_channels = ([]);  // user_id -> channel
private mapping user_last_activity = ([]); // user_id -> last activity time

int add_user_to_channel(object user, int channel);
int remove_user_from_channel(object user);
int auto_assign_user_to_channel(object user);
int get_user_channel(object user);
int is_user_in_channel(object user, int channel);
int broadcast_to_channel(int channel, string message);
int count_users_in_channel(int channel);
int find_least_populated_channel();
int is_valid_channel(int channel);

object *get_channel_users(int channel);
object *filter_by_channel(object *users, int channel);

void clean_channel_users(int channel);
void cleanup_disconnected_users();

void create()
{

    int i;
    for (i = 1; i <= MAX_CHANNELS; i++)
    {
        channel_users[i] = ({});
    }

    //call_out("cleanup_disconnected_users", CLEANUP_INTERVAL);
}

int add_user_to_channel(object user, int channel)
{
    int user_id;

    if (!objectp(user) || channel < 1 || channel > MAX_CHANNELS)
        return 0;

    user_id = user->get_number();


    __FILE__->remove_user_from_channel(user);

    channel_users[channel] += ({ user });
    user_channels[user_id] = channel;
    user->set_channel(channel);

    return 1;
}

int remove_user_from_channel(object user)
{
    int user_id;
    int old_channel;

    if (!objectp(user))
        return 0;

    user_id = user->get_number();
    old_channel = user_channels[user_id];

    if (old_channel) {
        channel_users[old_channel] -= ({ user });
    }

    map_delete(user_channels, user_id);

    return 1;
}

object *get_channel_users(int channel)
{
    if (channel < 1 || channel > MAX_CHANNELS)
        return ({});

    __FILE__->clean_channel_users(channel);
    return channel_users[channel];
}

void clean_channel_users(int channel)
{
    object *valid_users, *users;
    object user;
    int i, size;

    valid_users = ({});
    users = channel_users[channel];
    size = sizeof(users);

    for (i = 0; i < size; i++)
    {
        user = users[i];
        if (objectp(user) && user->get_number())
        {
            valid_users += ({ user });
        }
    }

    channel_users[channel] = valid_users;
}

int get_user_channel(object user)
{
    int user_id;

    if (!objectp(user))
        return 0;

    user_id = user->get_number();
    

    return user_channels[user_id] || 0;
}

int broadcast_to_channel(int channel, string message)
{
    // object *users;
    // int i, size;

    // users = get_channel_users(channel);
    // size = sizeof(users);

    // for (i = 0; i < size; i++)
    // {
    //     if (objectp(users[i]))
    //         send_user(users[i], "%c%s", '>', message);
    // }

    // return size;
}

int count_users_in_channel(int channel)
{
    // if (channel < 1 || channel > MAX_CHANNELS)
    //     return 0;

    // clean_channel_users(channel);
    // return sizeof(channel_users[channel]);
}

int find_least_populated_channel()
{
    // int best_channel, min_users, i;

    // best_channel = 1;
    // min_users = sizeof(channel_users[1]);

    // for (i = 2; i <= MAX_CHANNELS; i++)
    // {
    //     if (sizeof(channel_users[i]) < min_users)
    //     {
    //         min_users = sizeof(channel_users[i]);
    //         best_channel = i;
    //     }
    // }

    // return best_channel;
}

int auto_assign_user_to_channel(object user)
{
    // int best_channel;
    // best_channel = find_least_populated_channel();
    // return __FILE__->add_user_to_channel(user, best_channel);
}

int is_user_in_channel(object user, int channel)
{
    // if (!objectp(user) || channel < 1 || channel > MAX_CHANNELS)
    //     return 0;

    // return __FILE__->get_user_channel(user) == channel;
}

object *filter_by_channel(object *users, int channel)
{
    object *result, *channel_list;
    int i;

    result = ({});
    channel_list = __FILE__->get_channel_users(channel);

    for (i = 0; i < sizeof(users); i++)
    {
        if (objectp(users[i]) && member_array(users[i], channel_list) != -1)
        {
            result += ({ users[i] });
        }
    }

    return result;
}

int is_valid_channel(int channel)
{
    return channel >= 1 && channel <= MAX_CHANNELS;
}

void cleanup_disconnected_users()
{
    // object *users, user;
    // string user_id;
    // int i, size, current_time;
    
    // current_time = time();
    
    // // Cleanup tất cả channels
    // for (i = 1; i <= MAX_CHANNELS; i++)
    // {
    //     users = channel_users[i];
    //     size = sizeof(users);
        
    //     for (int j = 0; j < size; j++)
    //     {
    //         user = users[j];
    //         if (!objectp(user))
    //             continue;
                
    //         user_id = user->get_number();
    //         if (!stringp(user_id))
    //             continue;
            
    //         // Kiểm tra zombie connection
    //         if (!interactive(user) || user->get_idle_time() > ZOMBIE_TIMEOUT)
    //         {
    //             // Force disconnect zombie user
    //             log_file("zombie_cleanup.log", sprintf("%s Force disconnect zombie user: %s (idle: %d)\n", 
    //                 short_time(), user_id, user->get_idle_time()));
                
    //             // Gọi quit command để cleanup đúng cách
    //             if (user->get_login_flag() >= 2)
    //             {
    //                 QUIT_CMD->main(user, "");
    //             }
    //             else
    //             {
    //                 destruct(user);
    //             }
                
    //             // Xóa khỏi channel
    //             remove_user_from_channel(user);
    //         }
    //         else
    //         {
    //             // Cập nhật last activity time
    //             user_last_activity[user_id] = current_time;
    //         }
    //     }
    // }
    
    // // Schedule next cleanup
    // call_out("cleanup_disconnected_users", CLEANUP_INTERVAL);
}

// Thêm function để force disconnect tất cả zombie users
// int force_disconnect_zombies()
// {
//     object *all_users, user;
//     int i, size;
    
//     all_users = USER_D->get_user();
//     size = sizeof(all_users);
    
//     for (i = 0; i < size; i++)
//     {
//         user = all_users[i];
//         if (!objectp(user))
//             continue;
            
//         // Kiểm tra nếu user không interactive hoặc idle quá lâu
//         if (!interactive(user) || user->get_idle_time() > FORCE_DISCONNECT_TIME)
//         {
//             log_file("force_disconnect.log", sprintf("%s Force disconnect: %s (idle: %d, interactive: %d)\n", 
//                 short_time(), user->get_number(), user->get_idle_time(), interactive(user)));
                
//             if (user->get_login_flag() >= 2)
//             {
//                 QUIT_CMD->main(user, "");
//             }
//             else
//             {
//                 destruct(user);
//             }
//         }
//     }
// }
