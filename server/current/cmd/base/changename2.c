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

#define TEN_NHAN_VAT "../current/tennhanvat.txt"


void check_time(object who) {
    "cmd/base/quit"->main(who, "");
}

int main(object me, string arg)
{
    object who, obj;
    int time, time2, i, size, level, cash, saving, size2, exist, EXIST_NAME = 0;
    string id, order, filePath, newName, currentUser;
    string* line, * data;

    if (sscanf(arg, "@ %s %s", newName, currentUser) == 2)
    {
        if (!(who = find_any_char(currentUser)))
        {
            notify("Không tìm thấy người này");
            return 1;
        }

        line = explode(read_file(TEN_NHAN_VAT), "\n");
        for (i = 0, size = sizeof(line); i < size; i++)
        {
            data = explode(line[i], " ");

            if (newName == data[EXIST_NAME]) {
                exist = 1;
                break;
            }
        }

        if (exist == 1) {
            notify("Tên này đã có người sử dụng");
            return 0;
        }

        obj = new ("/inh/user/list");
        id = who->get_id();
        obj->set_owner(who->get_real_id());

        if (who->get_real_id() == id) order = "1";
        else order = id[< 1.. < 1];

        obj->set_save_2(order + ".name", newName);
        TASK_LEGEND_D->check_task_item1(who, "Thẻ Đổi Tên Đặc Biệt", 1);
        obj->save();

        send_user(who, "%c%s", ';', sprintf(HIY"Bạn đã đổi tên thành công!"));

        tell_user(who, HIY"Tài khoản đã được cập nhật, thoát sau vài giây!");
        notify(HIY"Tài khoản đã được cập nhật, thoát sau vài giây!");

        call_out("check_time", 5, who, "");

        return 1;
    }
}