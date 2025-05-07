
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

        //"/sys/item/equip"->init_equip_prop_3(item);
        //item->delete("forge");
        //"/sys/item/equip"->reset_equip_prop(item);

       /* for (i = 0; i < star; i++)
        {
            "/sys/item/equip"->init_equip_prop_5(item);
            forge += "1";
            item->set("forge", forge);
        }*/

        item->add("hp*", star);
        item->set("hp*+", star);
        item->set_hide(0);
        item->set_bind(1);

        send_user(me, "%c%d%c", 0x31, getoid(item), 0);
    }

    return 1;
}
