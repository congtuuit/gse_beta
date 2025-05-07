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
        set_name("Chiến Quốc Lệnh FAKE");
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
        return "Lệnh bài thần kỳ, sau khi sử dụng bạn sẽ nhận được điểm Kinh nghiệm × 2 khi tiêu diệt quái vật trong suốt 1 tiếng.\n (Mỗi tuần chỉ có thể sử dụng tối đa 105 Chiến Quốc Lệnh.)"; 
}

string get_loop_desc( object me )
{
	return "Nhân 2 kinh nghiệm trong 1 giờ.";
}
int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object item) 
{
	string result = "";
	if (!who->get("gmsupport")) {
		result = sprintf("\nVui lòng chọn tính năng cần hỗ trợ!\n");
		result += sprintf(ESC "Đến map\nsudogm go\n");
		result += sprintf(ESC "Kiểm tra người chơi trên map\nsudogm user\n");
		result += sprintf(ESC "Kiểm tra BOSS trên map\nsudogm boss\n");
		result += sprintf(ESC "Bat AutoFarm\nsudogm auto\n");
		result += sprintf(ESC "Tat AutoFarm\nsudogm offauto\n");
		result += sprintf(ESC "Đóng.\nCLOSE\n");
		send_user(who, "%c%c%w%s", ':', 3, 0, result);
	}
}

