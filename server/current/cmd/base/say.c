
#include <ansi.h>

int main(object me, string arg)
{
    object who;
    string name, id;
    object *users;
    int t;

    if (is_player(me) && gone_time(me->get_time("say")) < 3)
    {
        notify("Không nên sử dụng kênh Chat thường xuyên");
        return 1;
    }

    me->set_time("say", time());

    if (!arg)
    {
        notify("Bạn muốn nói gì ?");
        return 1;
    }
    
    if (me->sizeof_chblk_dbase())
    {
        t = gone_time(me->get_chblk("time"));
        me->add_chblk("chat", -t);
        me->add_chblk("rumor", -t);
        me->add_chblk("trade", -t);
        me->add_chblk("city", -t);
        me->add_chblk("family", -t);
        me->add_chblk("say", -t);
        me->add_chblk("org", -t);
        me->set_chblk("time", time());

        if (me->get_chblk("chat") < 1 && me->get_chblk("rumor") < 1 && me->get_chblk("trade") < 1
            && me->get_chblk("city") < 1 && me->get_chblk("family") < 1 && me->get_chblk("org") < 1 && me->get_chblk("say") < 1)
            me->init_chblk_dbase();

        if ((t = me->get_chblk("say")) > 0)
        {
            notify("Bình Thường kênh sau %d phút sẽ mở ra", t / 60 + 1);
            return 1;
        }
    }

    "/quest/help"->send_help_tips(me, 44);
    "/quest/help"->send_help_tips(me, 45);
    //name = sprintf( NAME_LEFT "%s" NAME_RIGHT, me->get_name() );

    if (is_god(me)) {
        name = sprintf("%c+%d,%s=%d%c-", '\t', 0xff3300, me->get_name(), me->get_number(), '\t');
    }
    else {
        name = sprintf("%c+%d,%s=%d%c-", '\t', 0xffffff, me->get_name(), me->get_number(), '\t');
    }

    //users = get_range_object_2(me, 10, USER_TYPE);
    users = get_range_object_2_by_channel(me, 10, USER_TYPE);

    if (arg[0] == '#' && (arg[1] < '0' || arg[1] > '9'))
    {
        arg = arg[1.. < 1];

        send_user(users, "%c%c%d%s", 0x43, 6, me->get_number(), sprintf(CHAT "%s%s", name, arg));
    }
    else if (arg[0] == '*')
    {
        arg = arg[1.. < 1];

        if (sscanf(arg, "%s %s", arg, id) == 2)
        {
            if (id == "i" || id == "me")
            {
                who = me;
            }
            else if (!(who = find_char(id)))
            {
                notify("Không tìm thấy người này");
                return 1;
            }
            arg = EMOTE_D->do_emote(me, name, arg, who);
        }
        else    arg = EMOTE_D->do_emote(me, name, arg, 0);

        if (!arg) return 1;

        send_user(users, "%c%c%d%s", 0x43, 6, me->get_number(), CHAT + arg);
    }
    else
    {
        send_user(users, "%c%c%d%s", 0x43, 6, me->get_number(), sprintf(CHAT " %s : %s ", name, arg));    // get_scene_object_2(me, USER_TYPE)
    }

    return 1;
}

void say(object me, string arg)
{
    if (me->is_user())
        send_user(get_range_object_2(me, 10, USER_TYPE), "%c%c%d%s", 0x43, 6, me->get_number(),
            sprintf(CHAT NAME_LEFT " %s " NAME_RIGHT ": %s ", me->get_name(), arg));
    else    send_user(get_range_object_2(me, 10, USER_TYPE), "%c%c%d%s", 0x43, 16, getoid(me),
        sprintf(CHAT NAME_LEFT " %s " NAME_RIGHT ": %s ", me->get_name(), arg));
}
