
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
    int amount;
    string id, type, value, cName;

	int iTime;
	mixed* mixTime;
	int tuvi, timestart, time, hour, levelUp, timeGame, previousTime;
	string showTimeStart, showTime;


    if( is_player(me) ) 
    {
        notify( "Ngươi không đủ quyền hạn" );
	    return 1;
    }
    if(sscanf( arg, "%s %s %s", id, type, value) != 4){
		if(!( who = find_any_char(id) ))
	    {
	        notify( "Không tìm thấy người này" );
			return 1;
	    }
	    
		switch (type)
		{
			case "add":
				who->add_title(sprintf("%s", value));
				who->show_title(sprintf("%s", value));
				who->delete_title(value);
				cName = TITLE_D->get_titlename(value);
				who->add_title(value);
				send_user(who, "%c%s", '!', "Bạn đã nhận được Danh Hiệu mới " + HIR + cName);
				MAILBOX->sys_mail(who->get_id(), who->get_number(), "Chúc mừng bạn nhận được danh hiệu " + HIR + cName);

				break;
			case "remove":
				cName = TITLE_D->get_titlename(value);
				who->delete_title(value);
				MAILBOX->sys_mail(who->get_id(), who->get_number(), "Danh hiệu " + HIR + cName + NOR" đã bị thu hồi");

				break;
		}

    }
    
    return 1;
}