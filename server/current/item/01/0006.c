#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>
#include <task.h>

inherit ITEM;
inherit COMBINED;

int get_item_value() { return 5; }
int get_item_value_2() { return 5; }
int get_item_number() { return 99; }

// 函数：构造处理
void create()
{
    set_name("Rương Dự Trữ");
    set_picid_1(0080);
    set_picid_2(0080);
    set_value(1);
    set_amount(1);
}

// 函数：获取描述
string get_desc()
{
    return "Có thể thay thế Trưởng Phòng Tiên Sinh dự trữ tất cả vật phẩm, phải sau khi giao lại cho Trưởng Phòng Tiên Sinh mới có thể Hoàn thành nhiệm vụ.";
}
