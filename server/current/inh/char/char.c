
#include <cmd.h>
#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#include <city.h>

inherit DBASE_F;

private static int Type;    // 人物类别
private static int PicId;   // 人物造型
private static int PhotoId; // 人物头像

private int Gender;  // 性别
private int NoFight; // 禁战标志(安全区)
private
    string StartPlace; // 连接场景

private static int Ride; // 骑宠

private int Channel;

// channel extend function
int set_channel(int input)
{
        return Channel = input;
}

int get_channel()
{
        return Channel;
}

// 函数：人物识别函数
int is_char() { return 1; }

// 函数：获取人物标识(用于 find_char 函数)
string get_char_id() { return sprintf("%x#", getoid(this_object())); } // 涉及太广，禁止改动

// -------------------------------------------------------------

// 函数：获取动作状态
int get_char_action() { return DEFAULT_ACT; }

// 函数：获取人物类别
int get_char_type() { return Type; }

// 函数：Thiết lập 人物类别
int set_char_type(int type)
{
        if (Type != type)
                send_user(get_scene_object_2(this_object(), USER_TYPE), "%c%c%d%c", 0x3d, 1, getoid(this_object()), type);
        return Type = type;
}

// 函数：获取人物造型
int get_char_picid() { return PicId; }

// 函数：Thiết lập 人物造型
int set_char_picid(int id) { return PicId = id; }

// 函数：获取人物造型
int get_char_photoid() { return PhotoId > 0 ? PhotoId : PicId; }

// 函数：Thiết lập 人物造型
int set_char_photoid(int id) { return PhotoId = id; }

// 函数：获取性别标志
int get_gender() { return Gender; }

// 函数：Thiết lập 性别标志
int set_gender(int flag) { return Gender = flag; }

// 函数：获取禁战标志
int get_no_fight() { return NoFight; }

// 函数：Thiết lập 禁战标志
int set_no_fight(int flag) { return NoFight = flag; }

// 函数：获取骑宠
int get_ride() { return Ride; }

// 函数：Thiết lập 骑宠
int set_ride(int flag) { return Ride = flag; }

// 函数：获取连线场景
string get_start_place() { return StartPlace; }

// 函数：Thiết lập 连线场景
string set_start_place(string place) { return StartPlace = place; }

// -------------------------------------------------------------

int to_front(int d)
{
        object me = this_object();

        d = range_value(d, 1, 8);

        if (get_d(me) != d)
        {
                set_d(me, d);
                send_user(get_scene_object_2(me, USER_TYPE), "%c%d%c", 0x5e, getoid(me), get_d(me));
        }

        return d;
}

int to_front_xy(int x1, int y1)
{
        return to_front(get_front_xy(get_x(this_object()), get_y(this_object()), x1, y1));
}

void to_front_eachother(object who)
{
        // to_front_xy( get_x(who), get_y(who) );

        switch (to_front(get_front_xy(get_x(this_object()), get_y(this_object()), get_x(who), get_y(who))))
        {
        case 1:
                who->to_front(5);
                break;
        case 2:
                who->to_front(6);
                break;
        case 3:
                who->to_front(7);
                break;
        case 4:
                who->to_front(8);
                break;
        case 5:
                who->to_front(1);
                break;
        case 6:
                who->to_front(2);
                break;
        default:
                who->to_front(3);
                break;
        case 8:
                who->to_front(4);
                break;
        }
}

// -------------------------------------------------------------

string get_short();
int get_hp_cent();
int get_walk_speed();

// NPC map
// Chức năng: Danh sách người chơi mới (đối thủ vào trận) (chỉ dành cho NPC)
void show_to_user(object who)
{
        object me = this_object();
        int id = getoid(me);
        int type = 0;

        // channel feature
        // Do not show NPC to user if not same channel
        if (who->get_channel() > 0 && me->get_channel() > 0 && who->get_channel() != me->get_channel())
        {
                return;
        }

        if (get_char_picid())
                type = get_char_picid();
        if (get_effect(me, EFFECT_MAGIC_4243))
                type = get("pf#4243");

        if (type)
        {
                send_user(who, "%c%c%d%w%w%c%c%c%w%c%c%d%s", 0x69, 128, id,
                          get_x(me), get_y(me), get_d(me), get_char_type(), get_char_action(), type,
                          get_hp_cent(), get_walk_speed(), 0, get_short());
                if (get_head_color())
                {
                        //                	if (MAIN_D->get_host_type()!=1000)
                        if (0)
                                send_user(who, "%c%d%c%w%w%w%w", 0x23, id, 99, get_head_color(), 0, 0, 0);
                        else
                                send_user(who, "%c%d%d%w%w%w%w", 0x23, id, 99, get_head_color(), 0, 0, 0);
                }
        }
        else
        {
                //        	if (MAIN_D->get_host_type()!=1000)
                if (0)
                        send_user(who, "%c%c%d%w%w%c%c%c%c%d%d%w%d%w%c%c%c%c%d%s", 0x69, 0, id,
                                  get_x(me), get_y(me), get_d(me), get_char_type(), get_char_action(),
                                  get_armor_code(), get_armor_color_1(), get_armor_color_2(),
                                  get_head_code(), get_head_color(), get_weapon_code_2(), 0, 0,
                                  get_hp_cent(), get_walk_speed(), 0, get_short());
                else
                        send_user(who, "%c%c%d%w%w%c%c%c%d%w%w%c%c%c%c%d%s", 0x69, 0, id,
                                  get_x(me), get_y(me), get_d(me), get_char_type(), get_char_action(),
                                  get_armor_code(), get_armor_color_1(), get_weapon_code_2(), 0, 0,
                                  get_hp_cent(), get_walk_speed(), 0, get_short());
        }
        if (me->get_id_color())
                send_user(who, "%c%d%d", 0x66, id, me->get_id_color());
        if (me->get_ride())
                send_user(who, "%c%d%d", 0x62, id, me->get_ride());
        CHAR_CHAR_D->send_loop_perform(me, who);   // 显示持续效果
        CHAR_CHAR_D->send_loop_perform_2(me, who); // 显示持续图标
}

// Chức năng: Được liệt kê cho người chơi (cảnh mới vào) (chỉ dành cho NPC)
varargs void show_to_scene(object *user, int x, int y, int d, int add_pf, int add_pf_2)
{
        object me = this_object();
        int id = getoid(me);
        int type = 0, i, size;

        // channel feature
        // hide to user not same channel
        user = filter_by_channel(user, me->get_channel());

        if (get_char_picid())
                type = get_char_picid();
        if (get_effect(me, EFFECT_MAGIC_4243))
                type = get("pf#4243");
        if (type)
        {
                if (!add_pf)
                        send_user(user, "%c%c%d%w%w%c%c%c%w%c%c%d%s", 0x69, 128, id,
                                  x, y, d, get_char_type(), get_char_action(), type,
                                  get_hp_cent(), get_walk_speed(), 0, get_short());
                else if (!add_pf_2)
                        send_user(user, "%c%c%d%w%w%c%c%c%w%c%w%c%c%c%d%s", 0x69, 129, id,
                                  x, y, d, get_char_type(), get_char_action(), type,
                                  get_hp_cent(), add_pf, 1, OVER_BODY, get_walk_speed(), 0, get_short());
                else
                        send_user(user, "%c%c%d%w%w%c%c%c%w%c%w%c%c%w%c%c%c%d%s", 0x69, 130, id,
                                  x, y, d, get_char_type(), get_char_action(), type,
                                  get_hp_cent(), add_pf, 1, OVER_BODY, add_pf_2, 1, OVER_BODY, get_walk_speed(), 0, get_short());

                if (get_head_color())
                {
                        // if (MAIN_D->get_host_type()!=1000)
                        if (0)
                                send_user(user, "%c%d%c%w%w%w%w", 0x23, id, 99, get_head_color(), 0, 0, 0);
                        else
                                send_user(user, "%c%d%d%w%w%w%w", 0x23, id, 99, get_head_color(), 0, 0, 0);
                }
        }
        else
        {
                if (!add_pf)
                        send_user(user, "%c%c%d%w%w%c%c%c%d%w%w%c%c%c%c%d%s", 0x69, 0, id,
                                  x, y, d, get_char_type(), get_char_action(),
                                  get_armor_code(), get_armor_color_1(), get_weapon_code_2(), 0, 0,
                                  get_hp_cent(), get_walk_speed(), 0, get_short());
                else if (!add_pf_2)
                        send_user(user, "%c%c%d%w%w%c%c%c%d%w%w%c%c%c%w%c%c%c%d%s", 0x69, 1, id,
                                  x, y, d, get_char_type(), get_char_action(),
                                  get_armor_code(), get_armor_color_1(), get_weapon_code_2(), 0, 0,
                                  get_hp_cent(), add_pf, 1, OVER_BODY, get_walk_speed(), 0, get_short());
                else
                        send_user(user, "%c%c%d%w%w%c%c%c%d%w%w%c%c%c%w%c%c%w%c%c%c%d%s", 0x69, 2, id,
                                  x, y, d, get_char_type(), get_char_action(),
                                  get_armor_code(), get_armor_color_1(), get_weapon_code_2(), 0, 0,
                                  get_hp_cent(), add_pf, 1, OVER_BODY, add_pf_2, 1, OVER_BODY, get_walk_speed(), 0, get_short());
        }
        if (me->get_id_color())
                send_user(user, "%c%d%d", 0x66, id, me->get_id_color());
        if (me->get_ride())
                send_user(user, "%c%d%d", 0x62, id, me->get_ride());
        CHAR_CHAR_D->send_loop_perform(me, user);
        CHAR_CHAR_D->send_loop_perform_2(me, user);
}

// Chức năng: Nhập xử lý cảnh (chỉ dành cho NPC)
varargs void add_to_scene(int z, int x, int y, int d, int add_pf, int add_pf_2, int rm_pf, int rm_pf_2)
{
        object me = this_object();
        object who = me->get_owner();
        int z0 = get_z(me), x0 = get_x(me), y0 = get_y(me);
        int me_oid = getoid(me);
        int me_channel = me->get_channel();
        object *user, *npc;

        // Xóa block cũ và thông báo xoá
        remove_block(z0, x0, y0, CHAR_BLOCK);

        user = get_scene_object(z0, x0, y0, USER_TYPE) - ({me});
        user = filter_by_channel(user, me_channel);

        if (!rm_pf)
                send_user(user, "%c%d", 0x78, me_oid);
        else if (!rm_pf_2)
                send_user(user, "%c%d%w%c%c", 0x78, me_oid, rm_pf, 1, OVER_BODY);
        else
                send_user(user, "%c%d%w%c%c%w%c%c", 0x78, me_oid, rm_pf, 1, OVER_BODY, rm_pf_2, 1, OVER_BODY);

        // Di chuyển
        set_z(me, z);
        set_x(me, x);
        set_y(me, y);
        set_d(me, d);
        set_block(z, x, y, CHAR_BLOCK);

        if (objectp(who) && who->is_user())
                move_object(me, z, x, y, USER_TYPE);
        else
                move_object(me, z, x, y, CHAR_TYPE);

        // Gửi hiển thị mới
        user = get_scene_object(z, x, y, USER_TYPE);
        user = filter_by_channel(user, me_channel);
        show_to_scene(user, x, y, d, add_pf, add_pf_2);

        // Xử lý vùng an toàn
        if (MAP_D->is_inside_safe_zone(z, x, y))
        {
                me->set_no_fight(1);
        }
        else
        {
                me->set_no_fight(0);

                if (me->get_action_mode() == 1)
                {
                        if (objectp(who)) // Có chủ
                        {
                                npc = get_range_object_2(me, 6, CHAR_TYPE);
                                if (sizeof(npc))
                                {
                                        npc->init_heart_beat_idle();
                                        npc->auto_fight(me);
                                }
                        }
                        else
                        {
                                who = get_near_object(z, x, y, 6, USER_TYPE);
                                if (objectp(who))
                                        me->auto_fight(who);
                        }
                }
        }

        // Loại bỏ hiệu ứng "dính tay"
        if (get_effect(me, EFFECT_CHAR_CHAN))
                set_effect(me, EFFECT_CHAR_CHAN, 1);
}

void remove_to_user(object who)
{
        send_user(who, "%c%d", 0x78, getoid(this_object()));
}

varargs void remove_from_scene(int rm_pf, int rm_pf_2)
{
        object *user, me, owner;

        me = this_object();

        remove_block(get_z(me), get_x(me), get_y(me), CHAR_BLOCK);
        user = get_scene_object_2(me, USER_TYPE) - ({me});

        if (!rm_pf)
                send_user(user, "%c%d", 0x78, getoid(me));
        else if (!rm_pf_2)
                send_user(user, "%c%d%w%c%c", 0x78, getoid(me), rm_pf, 1, OVER_BODY);
        else
                send_user(user, "%c%d%w%c%c%w%c%c", 0x78, getoid(me), rm_pf, 1, OVER_BODY, rm_pf_2, 1, OVER_BODY);
        if (owner = me->get_owner())
        {
                send_user(owner, "%c%c%d", 0x2c, 0, getoid(me)); // 更新召唤兽坐标
        }
        set_x(me, 0);
        set_y(me, 0);
        set_z(me, 0);
}
