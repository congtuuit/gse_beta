#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>
#include <equip.h>
#include <time.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

inherit OFFICER;

#define SANTACLAUS	"npc/party/santaclaus"
#define NEXT_TREE	"item/event/giangsinh/thong_2"
int get_char_picid() { return 3032; }

//phat trien sau 
int time_remove = 600;

void do_welcome(string arg);

void reset()
{
    int x, y, z;
    object next_tree, * nObj;

    if (get("eat") >= 5) {
        x = get_x(this_object());
        y = get_y(this_object());
        z = get_z(this_object());

        next_tree = new(NEXT_TREE);
        next_tree->set("birth", time());
        next_tree->add_to_scene(z, x, y);

        nObj = SANTACLAUS->get("plant");
        if (!arrayp(nObj))
            nObj = ({});
        nObj += ({ next_tree });
        SANTACLAUS->set("plant", nObj);

        remove_from_scene();
        destruct(this_object());

        return;
    }

    if (gone_time(get("birth")) > time_remove)
    {
        if (get("eat") > 2) {
            x = get_x(this_object());
            y = get_y(this_object());
            z = get_z(this_object());

            next_tree = new(NEXT_TREE);
            next_tree->set("birth", time());
            next_tree->add_to_scene(z, x, y);

            nObj = SANTACLAUS->get("plant");
            if (!arrayp(nObj))
                nObj = ({});
            nObj += ({ next_tree });
            SANTACLAUS->set("plant", nObj);

            remove_from_scene();
            destruct(this_object());
        }
        else {
            remove_from_scene();
            destruct(this_object());
        }

    }
    else {
        call_out("reset", 1);
    }

}

void create()
{
    set_name("Cây non");
    set_2("talk", (["welcome":(:do_welcome:)]));
    setup();
    call_out("reset", 1);
}


void do_look(object who)
{
    object me = this_object();
    int id = getoid(me);

    send_user(who, "%c%c%s", ':', 3, sprintf("   Cây non: Cây non chưa trưởng thành, trưởng thành sau %d giấy nữa\n"
        ESC"Tưới cây \ntalk %x# welcome.1\n"
        ESC"Rời khỏi", time_remove - gone_time(get("birth")),id));
}

void do_welcome(string arg)
{
    object me = this_object();
    __FILE__->do_welcome_2(me, arg);
}


int isExistItem(object who, string itemName) {
    return TASK_LEGEND_D->check_task_item_amount(who, itemName);
}


void move_item_to_user(object who, int amount_s, string name)
{
    int p, total, amount;
    object item;
    string name_s;

    item = new(name);

    if (item)
    {
        name_s = item->get_name();
        if (item->get_max_combined() > 1)
        {
            total = amount_s;
            amount = USER_INVENTORY_D->carry_combined_item(who, item, total);
            if (amount > 0 && item->set_amount(amount))
            {
                if (p = item->move(who, -1))
                {
                    item->add_to_user(p);
                }
            }
            else
            {
                item->add_amount(-total);
            }
        }
        else
        {
            if (p = item->move(who, -1))
            {
                item->add_to_user(p);
            }
        }

        USER_D->user_channel("Chúc mừng "HIY + who->get_name() + NOR" chăm sóc cây non nhận được phần thưởng " + HIR + item->get_name() + ".\n");
    }
}

void exchange(object who, string itemName, int amount) {

    int rate;
    string item;
    item = "item/event/giangsinh/trangtri";

    rate = random(100);
    if (TASK_LEGEND_D->check_task_item1(who, itemName, amount)) {
        if (rate < 40) {
            move_item_to_user(who, 1, item);
        }
    }
   

}

void do_welcome_2(object me, string arg)
{
    int x, y, z, flag, exchanged = 0, iStart, iFinish, i, timeOut;
    object who, item, player, gift, next_tree, * nObj;
    string name, cTmp, id1;
    mixed* mixTime;

    iStart = mktime(2021, 12, 12, 9, 0, 0);
    iFinish = mktime(2021, 12, 30, 23, 0, 0);

    i = time();

    who = this_player();
    who->set_time("talk", 0);

    flag = to_int(arg);

    switch (flag)
    {
    case 1:
        if (
            !isExistItem(who, "Linh Thủy")
            )
        {
            notify("Bạn không có Linh Thủy");
            return 0;
        }

        if (isExistItem(who, "Linh Thủy") < 1) {
            notify("Bạn không có Linh Thủy");
            return 0;
        }

        if (isExistItem(who, "Linh Thủy")) 
        {

            timeOut = time_remove - gone_time(me->get("birth"));
            if (timeOut > 0) {
                exchange(who, "Linh Thủy", 1);
                me->set("birth", me->get("birth") - 60);
                me->set("eat", me->get("eat") + 1);
                exchanged = 1;
            }
        }

        break;
    }
}