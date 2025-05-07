#include <time.h>
#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <advance.h>

int main( object me, string arg )
{
    int number;
    string result, type;
    object who;

    if( is_player(me) ) 
    {
        notify( "Bạn không có đủ quyền。" );
	    return 1;
    }

    if( sscanf( arg, "%s %s %d", result, type, number) != 4 )
    {
        switch(result)
        {
            case "acc":
                if (!who = find_any_char(type)) {
                    tell_user(me, HIR"Không tìm thấy người chơi.");
                }
                else {
                    if (number > 60 || number < 1) {
                        tell_user(me, sprintf(ECHO"Cấp độ nhân vật %d", who->get_level()));

                    }
                    else {
                        who->set_level(number);

                        send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(who),
                            9043, 1, OVER_BODY, 9044, 1, OVER_BODY, PF_ONCE);

                        result = sprintf(HIC "Bạn tăng lên cấp %d !", number);
                        write_user(who, result);

                        tell_user(me, sprintf(ECHO"Cấp độ nhân vật %d", who->get_level()));
                    }

                }

                break;

            case "get": 
                if(type == "level"){
                    notify( "level max: %d", HELPERS->get_level());
				}
                if(type == "star"){
                    notify( "level max: %d", HELPERS->get_level_star());
				}
                break;
            case "set":

                if(type == "level"){
                    HELPERS->set_level(number);
                    notify( "Thành công, max: %d", HELPERS->get_level());
				}
                if(type == "star"){
                    HELPERS->set_level_star(number);
                    notify( "Thông sao cho phép rèn, max: %d", HELPERS->get_level_star());
				}
                break;
        }
    }
    return 1;
}