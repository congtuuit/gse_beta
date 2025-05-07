#include <ansi.h>
#include <equip.h>
#include <item.h>

int main(object me, string arg)
{
    object item;
    int star = 1, i;
    string forge = "";
    string idObject, result, requiredItem;

    if (!arg)
    {
        notify("Bạn muốn biến vàng thành gì?");
        return 1;
    }

    if (sscanf(arg, "%s %d", idObject, star) == 2) {

        if (!(item = find_any_object(idObject)))
        {
            notify("Không thể tìm thấy một cái gì đó như thế này。");
            return 1;
        }

        requiredItem = sprintf("Vé Cường Hóa %d Sao", star);
        if (star > 0 && TASK_LEGEND_D->check_task_item_amount(me, requiredItem) > 0) {
            TASK_LEGEND_D->check_task_item1(me, requiredItem, 1);

            item->delete("forge");
            "/sys/item/equip"->reset_equip_prop(item);

            for (i = 0; i < star; i++)
            {
                "/sys/item/equip"->init_equip_prop_5(item);
                forge += "1";
                item->set("forge", forge);
            }

            send_user(me, "%c%d%c", 0x31, getoid(item), 0);
            tell_user(me, sprintf(ECHO"Trang bị %s cường hóa thành công!", item->get_name()));

        }
        else {
            //tell_user(me, ECHO"Bạn không có đá cường hóa");
        }

    }

    return 1;
}
