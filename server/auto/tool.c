#include <ansi.h>
#include <skill.h>

#include <equip.h>
#include <effect.h>

inherit ITEM;

int get_item_value() {return 30 ;}
int get_item_value_2() {return 30 ;}
int get_item_number() {return 10001006 ;}
int get_item_color() {return 2 ;}

void create()
{
        set_name("Auto Farm");
        set_picid_1(0096);
        set_picid_2(0096);
        set_value(3);
        set_record(1);
		set_no_give(1);
		set_no_sell(1);

}

int is_usable() {return 1;}

string get_desc() 
{ 
    return "Bật / Tắt Auto Farm"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object item) 
{
	string result = "";
	
	result = sprintf("\nVui lòng chọn tính năng cần hỗ trợ!\n");
	result += sprintf(ESC "Bật AutoFarm\nrunauto auto\n");
	result += sprintf(ESC "Tắt AutoFarm\nrunauto offauto\n");
	result += sprintf(ESC "Đóng.\nCLOSE\n");
	send_user(who, "%c%c%w%s", ':', 3, 0, result);
}

