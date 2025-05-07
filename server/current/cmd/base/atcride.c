#include <ansi.h>
#include <equip.h>
#include <item.h>
#include <effect.h>
#include <city.h>
#include <public.h>
#include <task.h>
#include <npc.h>

inherit ITEM;
inherit USABLE;

int main(object me, string arg)
{
    object item;
    string* weapon, file;
    string cmd1, cmd2, cmd3, cmd4;
    int family, z, x, y, p, i, size;

    string nameRootObject, nameItem, path, amount;
    string nameOfItem, result="";

    int getOK = 0;
    int intAmount;

    if (sscanf(arg, "%s", nameItem) == 1)
    {
        if (USER_INVENTORY_D->get_free_count(me) < 2)
        {
            notify("Hành trang không đủ 2 chỗ trống");
            return;
        }

        switch (nameItem)
        {
            case "hoadaihung":
                item = new ("/npc/event/PhoBan/item/ThuCuoi/001");
                i = item->move(me, -1);
                item->add_to_user(i);
                nameOfItem = "Hỏa Đại Hùng";
                getOK = 1;
                break;
            case "hoaholy":
                item = new ("/npc/event/PhoBan/item/ThuCuoi/002");
                i = item->move(me, -1);
                item->add_to_user(i);
                nameOfItem = "Hỏa Hồ Ly";
                getOK = 1;
                break;
            case "tuanlocdo":
                item = new ("/npc/event/PhoBan/item/ThuCuoi/006");
                i = item->move(me, -1);
                item->add_to_user(i);
                nameOfItem = "Tuần Lộc Đỏ";
                getOK = 1;
                break;
            case "thanvoi":
                item = new ("/npc/event/PhoBan/item/ThuCuoi/004");
                i = item->move(me, -1);
                item->add_to_user(i);
                nameOfItem = "Thần Voi Địa";
                getOK = 1;
                break;
            case "thuylongquy":
                item = new ("/npc/event/PhoBan/item/ThuCuoi/005");
                i = item->move(me, -1);
                item->add_to_user(i);
                nameOfItem = "Thủy Long Quy";
                getOK = 1;
                break;
        }

        if (getOK == 1) {

            TASK_LEGEND_D->check_task_item1(me, "Thú Hồn", 1);
            TASK_LEGEND_D->check_task_item1(me, "Kim Hồn", 1);
            TASK_LEGEND_D->check_task_item1(me, "Mộc Hồn", 1);
            TASK_LEGEND_D->check_task_item1(me, "Thủy Hồn", 1);
            TASK_LEGEND_D->check_task_item1(me, "Hỏa Hồn", 1);
            TASK_LEGEND_D->check_task_item1(me, "Thổ Hồn", 1);

            result = HIY + sprintf("Chúc mừng %s ( %d ) đã triệu hồi được linh thú "HIR"%s.", me->get_name(), me->get_number(), nameOfItem);
            CHAT_D->sys_channel(0, result);
            send_user(me, "%c%s", ';', "Chúc mừng bạn đã nhận được "HIY"" + nameOfItem);

            log_file("gm/gm3.dat", sprintf(" %s %s ( %d ) nhận được item từ Thú Hồn %d ( %d %d )\n", short_time(), me->get_id(), me->get_number(), get_z(me), get_x(me), get_y(me)));
            
            return 1;
        }
        
        return 1;
    }
}