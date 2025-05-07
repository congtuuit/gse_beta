#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
//inherit USABLE;

int get_item_value() { return 70; }
int get_item_value_2() { return 70; }
int get_item_color() { return 3; }
int get_item_number() { return 30; }

void create()
{
    set_name("Thú Hồn");
    set_picid_1(4108);
    set_picid_2(4108);
    set_value(70);
    set_no_give(1);
    //set_no_sell(1);
    set_no_drop(1);
}

// 函数：获取描述
string get_desc(object me)
{
    return "Vật phẩm không thể giao dịch\nThú Hồn cùng với Kim-Mộc-Thủy-Hỏa-Thổ hồn có thể triệu hồi thú cưỡi huyền thoại. \n (Hãy đến NPC để đổi Thần Thú)";
}

int get_use_effect(object me)
{
    return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
	int gender, family, type, i, k, l, m;
	object item, item1, item2, item3;
	string cTmp, cFile, cFile1, cFile2, cFile3, p;
    string result = "Ngươi muốn triệu hồi Thú Cưỡi nào?\n";

    int kim, moc, thuy, hoa, tho;

    kim = TASK_LEGEND_D->check_task_item_amount(who, "Kim Hồn");
    moc = TASK_LEGEND_D->check_task_item_amount(who, "Mộc Hồn");
    thuy = TASK_LEGEND_D->check_task_item_amount(who, "Thủy Hồn");
    hoa = TASK_LEGEND_D->check_task_item_amount(who, "Hỏa Hồn");
    tho = TASK_LEGEND_D->check_task_item_amount(who, "Thổ Hồn");

    if (kim > 0 && moc > 0 && thuy > 0 && hoa > 0 && tho > 0) {
        send_user(who, "%c%s", ':', result +
            ESC HIW"Triệu hồi "HIY"Hỏa Đại Hùng.\natcride hoadaihung\n" +
            ESC HIW"Triệu hồi "HIY"Hỏa Hồ Ly.\natcride hoaholy\n" +
            //ESC HIW"Triệu hồi "HIY"Tuần Lộc Đỏ.\natcride tuanlocdo\n" +
            ESC HIW"Triệu hồi "HIY"Thần Voi Địa.\natcride thanvoi\n" +
            ESC HIW"Triệu hồi "HIY"Thủy Long Quy.\natcride thuylongquy\n" +
            ESC HIW"Rời khỏi.\nCLOSE\n");

        return 1;
    }
    else {
        notify("Vật phẩm không đủ để triệu hồi thú cưỡi.");
        return 0;
    }
}
