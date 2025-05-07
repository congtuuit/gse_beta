
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#include <action.h>

#define THIS_SKILL      0281
#define THIS_PERFORM    02816
#define PF_START       "02816"
#define PF_NAME        "Thủy Phong Cầu"

#define SKILL_LEVEL     45
#define TIME_INTERVAL   4
#define SUB_MP          ( 18 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 10 * 4 )
#define ADD_AP          ( 35 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 10 * 15 )

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

int get_cast_seal() { return 9101; } 

string get_desc(object me)
{
    int level = me->get_skill(THIS_SKILL);
    int cur_level;
    string result;
    if (level < SKILL_LEVEL)
        return HIR + PF_NAME + "\n Võ công yêu cầu: 45 cấp\n Phạm vi: 3x3\nTriệu gọi thủy phong cầu, sát thương từ xa, kỹ năng lan đến các mục liêu kế bên.";
    cur_level = (level - SKILL_LEVEL) / 10 + 1;
    result = sprintf(HIC" %s (Cấp %d )\n " NOR "Võ công yêu cầu: Cấp %d \n Pháp Lực tiêu hao: %d điểm\n Tái sử dụng sau: %d giây\n Hô gọi thủy phong cầu, tăng thêm %d điểm Nội Công khi tấn công 1 mục tiêu từ xa, phạm vi lan rộng 3x3.\n " HIC"Cấp tiếp theo:\n "NOR "Võ công yêu cầu: " HIR "Cấp %d " NOR "\n    Tăng thêm %d điểm Nội Công.",
        PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_AP, cur_level * 10 + SKILL_LEVEL, ADD_AP + 15, );
    return result;
}

int main(object me, object who, int x, int y, string arg)
{
    object* user;
    int z;
    int level, mp;


    if ((level = me->get_skill(THIS_SKILL)) < SKILL_LEVEL) return 1;

    if (gone_time(me->get_perform(PF_START)) < TIME_INTERVAL)
    {
        printf(ECHO "Sử dụng \"" PF_NAME "\" khoảng cách sử dụng chưa đủ");
        return 1;
    }

    if (me->get_mp() < (mp = SUB_MP))
    {
        printf(ECHO "Sử dụng \" %s \"cần %d điểm Pháp Lực.", PF_NAME, mp);
        return 1;
    }

    if (who)
    {
        if (!inside_screen_2(me, who)) return 1;

        x = get_x(who);  y = get_y(who);
    }
    else if (objectp(who = me->get_enemy_2()) && inside_screen_2(me, who))
    {
        x = get_x(who);  y = get_y(who);
    }
    else
    {
        z = get_z(me);

        if (!inside_screen(get_x(me), get_y(me), x, y)) return 1;
        if (!objectp(who = get_xy_object(z, x, y, CHAR_TYPE)) && !objectp(who = get_xy_object(z, x, y, USER_TYPE)))
        {
            send_user(me, "%c%w%c%w", 0x50, 0, 0xff, 2);
            me->set_time("pf", time());

            me->to_front_xy(x, y);
            user = get_scene_object_2(me, USER_TYPE);
            send_user(me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP);
            me->add_mp(-mp);
            set_heart_state(me, MAGIC_STAT);
            set_heart_count_2(me, 5);
            me->add_2("go_count.count2", 5);
            me->set_cast_file(__FILE__);
            me->set_cast_arg(sprintf("%d,%d,%d", z, x, y));

            return 1;
        }
    }

    send_user(me, "%c%w%c%w", 0x50, 0, 0xff, 2);
    me->set_time("pf", time());

    me->set_enemy_2(who);

    me->to_front_xy(x, y);
    user = get_scene_object_2(me, USER_TYPE);
    send_user(user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN);
    send_user(get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END);
    send_user(me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP);

    me->add_mp(-mp);

    set_heart_state(me, MAGIC_STAT);
    set_heart_count_2(me, 5);
    me->add_2("go_count.count2", 5);
    me->set_cast_file(__FILE__);
    me->set_cast_arg(sprintf("%s,%d", who->get_char_id(), level));
    send_user(me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0);
    me->set_perform(PF_START, time());
    return 1;
}

int cast_done(object me)
{
    object* user, who, * char;
    string arg;
    int z, x, y, i;
    int level, rate, size, ret;

    if (!stringp(arg = me->get_cast_arg())) return 1;

    if (sscanf(arg, "%s,%d", arg, level) != 2) return 1;

    if (!objectp(who = find_char(arg))) return 1;

    //custom
    x = get_x(who);
    y = get_y(who);
    z = get_z(who);

    char = get_scene_object(z, x, y, USER_TYPE);
    char = get_range_object(z, x, y, 3, CHAR_TYPE) + get_range_object(z, x, y, 2, USER_TYPE) - ({ me });

    size = sizeof(char);
    for (i = 0; i < size; i++)
    {
        if (who = char[i])
        {
            if (!who) continue;
            if (!who->can_be_fighted(me) || !me->can_fight(who)) continue;
            
            send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who),
                21175, 1, OVER_BODY, PF_ONCE);

            CHAR_FIGHT_D->cast_done(me, who, ADD_AP);
            if (who && !who->is_die())
                CHAR_FIGHT_D->set_enmity(me, who, 40);

        }
    }

    return 2;
}

int perform_action_npc(object me, object who)
{
    object* user;
    object * char;

    int x, y, z, size, i;

    if (!inside_screen_2(me, who)) return 0;

    me->to_front_xy(get_x(who), get_y(who));
    user = get_scene_object_2(me, USER_TYPE);

    send_user(user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN);
    send_user(get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END);
   
    x = get_x(who);
    y = get_y(who);
    z = get_z(who);

    char = get_scene_object(z, x, y, USER_TYPE);
    char = get_range_object(z, x, y, 3, CHAR_TYPE) + get_range_object(z, x, y, 2, USER_TYPE) - ({ me });

    size = sizeof(char);
    for (i = 0; i < size; i++)
    {
        if (who = char[i])
        {
            if (!who) continue;
            if (!who->can_be_fighted(me) || !me->can_fight(who)) continue;

            send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who),
                21175, 1, OVER_BODY, PF_ONCE);

            CHAR_FIGHT_D->cast_done(me, who, ADD_AP);
            if (who && !who->is_die())
                CHAR_FIGHT_D->set_enmity(me, who, 40);

        }
    }

    set_heart_state(me, MAGIC_STAT);
    set_heart_count_2(me, 9);
    me->set_cast_file(__FILE__);
    //me->set_cast_arg(sprintf("%s,%d", who->get_char_id(), me->get_skill(THIS_SKILL)));

    return 1;
}

int cast_done_npc(object me)
{
    object* user, who;
    string arg;
    int z, x, y;
    int level, rate;

    if (!stringp(arg = me->get_cast_arg())) return 1;

    if (sscanf(arg, "%s,%d", arg, level) != 2) return 1;
    if (!objectp(who = find_char(arg))) return 1;

    send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(who),
        42321, 1, OVER_BODY, 42322, 1, UNDER_FOOT, PF_ONCE);

    if (!who->can_be_fighted(me) || !me->can_fight(who)) return 2; 

    CHAR_FIGHT_D->cast_done(me, who, ADD_AP); 
    if (who && !who->is_die())
        CHAR_FIGHT_D->set_enmity(me, who, 40);
    return 2; 
}

int get_perform_type() { return ON_CHAR; }

void can_perform(object me)
{
    int interval;
    string name;

    if (me->get_skill(THIS_SKILL) < SKILL_LEVEL)
    {
        send_user(me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME);
        return;
    }
    name = sprintf(" %s (Cấp %d )", PF_NAME, (me->get_skill(THIS_SKILL) - SKILL_LEVEL) / 10 + 1);
    interval = TIME_INTERVAL - gone_time(me->get_perform(PF_START));
    if (interval < 0)
        send_user(me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name);
    else    send_user(me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name);
    send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 0, 10, MAGIC_ACT_BEGIN, 0, 5, 0);
}
