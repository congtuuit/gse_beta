#include <ansi.h>
#include <equip.h>
#include <item.h>

// 函数：命令处理
int main(object me, string arg)
{
    object item;
    int star = 1, i;
    string forge = "";
    string idObject;

    if (is_player(me))
    {
        //notify("Bạn không có đủ quyền。");
        return 1;
    }

    if (!arg)
    {
        notify("Bạn muốn biến vàng thành gì?");
        return 1;
    }

    /*if (!(item = find_any_object(arg)))
    {
        notify("Không thể tìm thấy một cái gì đó như thế này。");
        return 1;
    }*/
    /*if (item == me)
    {
        notify("Bạn muốn làm rõ chính mình？");
        return 1;
    }
    if (item->get_equip_type() == 0)
    {
        notify("Chỉ có thể biến bánh răng thành vàng");
        return 1;*/
    //}

    //tell_user(me, "Bạn sẽ %s thành hoàng kim。", item->get_name());

    if (sscanf(arg, "%s %d", idObject, star) == 2) {

        if (!(item = find_any_object(idObject)))
        {
            notify("Không thể tìm thấy một cái gì đó như thế này。");
            return 1;
        }

        //"/sys/item/equip"->init_equip_prop_3(item);
        item->delete("sao");
        "/sys/item/equip"->reset_tuchat(item);
        for (i = 0; i < star; i++)
        {
            "/sys/item/equip"->tuchat(item, i);
            forge += "1";
            item->set("sao", forge);
        }

        send_user(me, "%c%d%c", 0x31, getoid(item), 0);

        if (star == 7 && TASK_LEGEND_D->check_task_item_amount(me, "Đoạn Thạch 7 Cấp") > 0) {
            TASK_LEGEND_D->check_task_item1(me, "Đoạn Thạch 7 Cấp", 1);
        }

    }

    return 1;
}
