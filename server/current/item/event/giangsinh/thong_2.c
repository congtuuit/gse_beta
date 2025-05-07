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
#define CHIRISTMAS	"sys/party/christmas"
#define NEXT_TREE	"item/event/giangsinh/thong_3"
int get_char_picid() { return 3031; }

//bien mat sau 15p
int time_remove = 600;

void do_welcome(string arg);
void reset()
{
    if (gone_time(get("birth")) > time_remove)
    {
        remove_from_scene();
        destruct(this_object());
    }
    else {
        call_out("reset", 1);
    }

}

void create()
{
    set_name("Cây Thông");
    set_2("talk", (["welcome":(:do_welcome:)]));
    setup();
    call_out("reset", 1);
}


void do_look(object who)
{
    object me = this_object();
    int id = getoid(me);
    send_user(who, "%c%c%s", ':', 3, sprintf("   Cây thông Noel: trang trí cây thông cần "HIR"1 bình Linh Thủy"NOR" & "HIR" Cầu Tuyết"NOR" & "HIR"Vớ dài"NOR"\n"
        ESC"Trang trí cây \ntalk %x# welcome.1\n"
        ESC"Rời khỏi", id));
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

    }
}


void exchange(object who, string itemName, int amount) {
    string item;
    
    item = "item/event/giangsinh/trangtri";

    if (TASK_LEGEND_D->check_task_item1(who, itemName, amount)) {
        move_item_to_user(who, 1, item);
    }

}

void do_welcome_2(object me, string arg)
{
    int x, y, z,flag, exchanged=0, iStart, iFinish, i;
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
            !isExistItem(who, "Cầu Tuyết") ||
            !isExistItem(who, "Vớ dài") ||
            !isExistItem(who, "Linh Thủy")
            ) 
        {
            notify("Vật phẩm trang trí không đủ.");
            return 0;
        }

        if (isExistItem(who, "Linh Thủy") < 1) {
            notify("Vật phẩm trang trí không đủ.");
            return 0;
        }

        if (isExistItem(who, "Cầu Tuyết") && isExistItem(who, "Vớ dài") && isExistItem(who, "Linh Thủy")) {
            exchange(who, "Cầu Tuyết", 1);
            exchange(who, "Vớ dài", 1);
            exchange(who, "Linh Thủy", 1);
            exchanged = 1;
        }

        if (exchanged == 0) {
            notify("Vật phẩm trang trí không đủ.");
            return 0;
        }

        x = get_x(me);
        y = get_y(me);
        z = get_z(me);

        next_tree = new(NEXT_TREE);
        next_tree->set("birth", time());
        next_tree->add_to_scene(z, x, y);

        nObj = SANTACLAUS->get("plant");
        if (!arrayp(nObj))
            nObj = ({});
        nObj += ({ next_tree });
        SANTACLAUS->set("plant", nObj);

        me->remove_from_scene();
        destruct(me);

        if (i > iStart && i < iFinish)
        {
            if (who->get_save("ChristmasPoint") < 1) {
                who->set_save("ChristmasPoint", 1);
            }
            else {
                who->add_save("ChristmasPoint", 1);
            }

            CHIRISTMAS->update_record(who);
        }

        break;
    }
}