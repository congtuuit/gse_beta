#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit LEGEND_ITEM;

int iOwner;
int is_souzuo() { return 1;}
int who_can_get() { return iOwner; }
int set_owner(int i) { return iOwner=i; }

// 函数：构造处理
void create()
{
        set_name( "Vòng tay bị mất" );
        set_picid_1(8614);
        set_picid_2(8614);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// 函数：获取描述
string get_desc() 
{ 
        return "Vật phẩm nhiệm vụ. Một chiếc vòng tay được chạm khắc từ ngọc bích trắng được truyền lại từ gia đình chủ khách sạn."; 
}