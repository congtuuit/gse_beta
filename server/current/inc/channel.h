#ifndef __CHANNEL_H__
#define __CHANNEL_H__

// Channel constants - Đơn giản hóa
#define CHANNEL_GLOBAL     0    // Global channel - visible to all
#define CHANNEL_1          1    // Channel 1 (Port 8001)
#define CHANNEL_2          2    // Channel 2 (Port 8002)
#define CHANNEL_3          3    // Channel 3 (Port 8003) - future use
#define CHANNEL_4          4    // Channel 4 (Port 8004) - future use

// Channel names
#define CHANNEL_NAME_1     "Kênh 1"
#define CHANNEL_NAME_2     "Kênh 2"
#define CHANNEL_NAME_3     "Kênh 3"
#define CHANNEL_NAME_4     "Kênh 4"

// Channel limits
#define MAX_CHANNELS       4
#define MAX_USERS_PER_CHANNEL 1000

// Channel status
#define CHANNEL_STATUS_OFFLINE  0
#define CHANNEL_STATUS_ONLINE   1
#define CHANNEL_STATUS_MAINTENANCE 2

// Function prototypes - Đơn giản hóa
object *filter_by_channel(object *users, int channel);
object *get_users_in_channel(int channel);
int is_user_in_channel(object user, int channel);
int broadcast_to_channel(int channel, string message);
int count_users_in_channel(int channel);
int add_user_to_channel(object user, int channel);
int remove_user_from_channel(object user);
int auto_assign_user_to_channel(object user);
string get_channel_info(int channel);
string *get_all_channels_info();

#endif 