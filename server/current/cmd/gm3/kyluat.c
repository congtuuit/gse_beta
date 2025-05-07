
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#include <time.h>

void check_time(object who) {
	"cmd/base/quit"->main(who, "");
}

int main( object me, string arg )
{
	object who;
    int i, size, a1, a2, a3, a4;
    int amount, value;
    string id, type;

	int iTime;
	mixed* mixTime;
	int tuvi, timestart, time, hour, levelUp, timeGame, previousTime;
	string showTimeStart, showTime;


    if( is_player(me) ) 
    {
        notify( "Ngươi không đủ quyền hạn" );
	    return 1;
    }
    if(sscanf( arg, "%s %s %d", id, type, value) != 4){
		if(!( who = find_any_char(id) ))
	    {
	        notify( "Không tìm thấy người này" );
			return 1;
	    }
	    
		switch (type)
		{
			case "camchat":
				who->set_chblk("chat", 15 * 60);
				who->set_chblk("rumor", 15 * 60);
				who->set_chblk("family", 15 * 60);
				who->set_chblk("say", 15 * 60);
				who->set_chblk("city", 15 * 60);
				who->set_chblk("vipchat", 15 * 60);
				who->set_chblk("time", time());
				who->set_save("nomail", time() + 15 * 60); 

				tell_user(me, "đã cấm chat %s", who->get_name());
				return 1;

				break;
			case "nhottu":
				if (get_z(who) != 704)
				{
					me->set("timentuben", time());
					"sys/party/vst4"->add_revive2(me, 1);
					//cam chat
					who->set_chblk("chat", 15 * 60);
					who->set_chblk("rumor", 15 * 60);
					who->set_chblk("family", 15 * 60);
					who->set_chblk("say", 15 * 60);
					who->set_chblk("city", 15 * 60);
					who->set_chblk("vipchat", 15 * 60);
					who->set_chblk("time", time());

					who->set_save("gietnguoi", 1);
					who->set_save("vaotu", value);
					who->set_save("vaotuluc", time());
					who->set_login_flag(2);
					set_invisible(who, 1);
					set_effect(who, EFFECT_USER_LOGIN, 4);
					who->add_to_scene(704, 35, 25);
					send_user(who, "%c%c%w%s", ':', 3, 9963, "Giám Ngục Quan :\nNgươi đã bị nhốt vào tù!\n"
						ESC "Xác nhận\nCLOSE\n");
					
					CHAT_D->rumor_channel(0, CHAT + sprintf(HIM"Bằng hữu %s (%d) đã bị nhốt vào tù %d phút !!", who->get_name(), who->get_number(), value));
					return 1;
				}
				else
				{
					write_user(me, ECHO "Đối phương đang ở trong Nhà ngục !");
					send_user(me, "%c%c%w%s", ':', 3, 5502, "Đặc quyền Vô Song : \nĐối phương vẫn đang còn ở trong Nhà ngục ! \n"ESC"Xác nhận");
					return 1;
				}
				break;
			
		}

    }
    
    return 1;
}