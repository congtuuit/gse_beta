private object *Chat = ({});
private object *Rumor = ({});

void add_chat(object who);
void add_rumor(object who);

void SAVE_BINARY() {}

void create()
{
        object *user;
        int i;
        int size;

        if (arrayp(user = users()))
        {
                for (i = 0, size = sizeof(user); i < size; i++)
                {
                        add_chat(user[i]);
                        add_rumor(user[i]);
                }
        }
}

object *get_chat()
{
        Chat -= ({0});
        return copy(Chat);
}

object *get_rumor()
{
        Rumor -= ({0});
        return copy(Rumor);
}

void add_chat(object who)
{
        if (objectp(who) && who->get_chat_open())
                Chat = Chat - ({who, 0}) + ({who});
}

void add_rumor(object who)
{
        if (objectp(who) && who->get_rumor_open())
                Rumor = Rumor - ({who, 0}) + ({who});
}

void sub_chat(object who)
{
        if (objectp(who))
                Chat -= ({who, 0});
}

void sub_rumor(object who)
{
        if (objectp(who))
                Rumor -= ({who, 0});
}

void chat_channel(int id, string chat)
{
        object *channel_users;

        Chat -= ({0});
        if (sizeof(Chat))
        {


                // Filter users by channel if channel_id is specified
                if (id > 0 && CHANNEL_D)
                {

                       channel_users  = CHANNEL_D->get_channel_users(id);
                        if (sizeof(channel_users))
                                send_user(channel_users, "%c%c%d%s", 0x43, 1, id, chat);

        log_file("_debug.txt", sprintf("LOG chat_channel size %s %s %d\n", short_time(), sizeof(channel_users), id));

                }
                else
                {
                        // Send to all users (global chat)
                        send_user(Chat, "%c%c%d%s", 0x43, 1, id, chat);
                }
        }
}

void rumor_channel(int id, string chat)
{
        Rumor -= ({0});
        if (sizeof(Rumor))
        {
                // Filter users by channel if channel_id is specified
                if (id > 0 && CHANNEL_D)
                {
                        object *channel_users = CHANNEL_D->get_channel_users(id);
                        if (sizeof(channel_users))
                                send_user(channel_users, "%c%c%d%s", 0x43, 2, id, chat);
                }
                else
                {
                        // Send to all users (global rumor)
                        send_user(Rumor, "%c%c%d%s", 0x43, 2, id, chat);
                }
        }
}

void rumor_player_channel(int id, string chat)
{
        object *user = Rumor - USER_D->get_gm();
        if (sizeof(user))
                send_user(user, "%c%c%d%s", 0x43, 2, id, chat);
}

void rumor_gm_channel(int id, string chat)
{
        object *user = USER_D->get_gm();
        if (sizeof(user))
                send_user(user, "%c%c%d%s", 0x43, 2, id, chat);
}

void sys_channel(int id, string chat)
{
        Chat -= ({0});
        if (sizeof(Chat))
                send_user(Chat, "%c%c%d%s", 0x43, 10, id, chat);
}

void vip_channel(int id, string chat)
{
        Chat -= ({0});
        if (sizeof(Chat))
                send_user(Chat, "%c%c%d%s", 0x43, 9, id, chat);
}
