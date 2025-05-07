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

    if (sscanf(arg, "%s %d", idObject, star) == 2) {

        if (!(item = find_any_object(idObject)))
        {
            notify("Không thể tìm thấy một cái gì đó như thế này。");
            return 1;
        }

        item->set_char_id_2(star);
        send_user(me, "%c%d%c", 0x31, getoid(item), 0);
    }

    return 1;
}
