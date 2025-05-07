#include <ansi.h>
#include <skill.h>
inherit COMBINED;
inherit ITEM;

int get_item_value() {return 500 ;}
int get_item_value_2() {return 500 ;}
int get_item_number() {return 30 ;}
int get_item_color() {return 2 ;}

void create()
{
        set_name("Kết Đan Thạch");
        set_picid_1(9811);
        set_picid_2(9811);
        set_value(3);
        set_amount(1);
}

int is_usable() {return 1;}
string get_desc() 
{ 
	return "Sau khi sử dụng bạn sẽ nhận thêm điểm Kinh nghiệm × 4 khi tiêu diệt quái vật trong suốt 1 tiếng.\n Vật phẩm không cộng thêm thời gian khi sử dụng chồng lên nhau. \n Thời gian từ vật phẩm này không thể đóng băng.";
}

string get_loop_desc( object me )
{
	return "Nhân 4 kinh nghiệm trong 1 giờ.";
}
int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object item) 
{
	int i,iWeek;

	if ( gone_time( who->get_login_time() )+ who->get_game_time()<who->get_double_time())
	{
		if (who->get_save_2("super_double") - time() >= 0) {
			send_user(who, "%c%c%w%s", ':', 3, 0, sprintf("Bạn đang có thời gian x4 rồi, sau khi sử dụng sẽ x16 điểm kinh nghiệm.\n"ESC"Chấp nhận\nuse ! %x#\n"ESC"Huỷ bỏ", getoid(item)));
		}
		else {
			send_user(who, "%c%c%w%s", ':', 3, 0, sprintf("Bạn đang có thời gian x2 rồi, sau khi sử dụng sẽ x8 điểm kinh nghiệm.\n"ESC"Chấp nhận\nuse ! %x#\n"ESC"Huỷ bỏ", getoid(item)));
		}

		return 0;
	}
	else {
		if (who->get_save_2("super_double") - time() >= 0) {
			send_user(who, "%c%c%w%s", ':', 3, 0, sprintf("Bạn đang có thời gian x2 rồi, sau khi sử dụng sẽ x8 điểm kinh nghiệm.\n"ESC"Chấp nhận\nuse ! %x#\n"ESC"Huỷ bỏ", getoid(item)));
			return 0;
		}
	}


	i = gone_time( who->get_login_time() );		
	who->add_save_2("double_time.time1",1);

	who->set_save_2("ketdanthach", time() + 3600);

	send_user( who, "%c%w%w%c", 0x81, 9998, 3600, EFFECT_GOOD );
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"Viện Trợ trò chơi" ); 
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "Thời Gian Nhân 4" ); 
	"/sys/task/task"->send_task_intro(who, 1, 1, 1);
	return 1;
}

// 函数：使用效果
int confirm_use( object me ) { return __FILE__ ->confirm_use_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int confirm_use_callout( object who, object item )
{
	int i,iWeek;

	i = gone_time( who->get_login_time() );	

	who->set_save_2("ketdanthach", time() + 3600);

	send_user( who, "%c%w%w%c", 0x81, 9998, who->get_double_time() - i - who->get_game_time(), EFFECT_GOOD );
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"Viện Trợ trò chơi" ); 
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "Thời Gian Nhân 4" ); 
	"/sys/task/task"->send_task_intro(who, 1, 1, 1);
	return 1;
}