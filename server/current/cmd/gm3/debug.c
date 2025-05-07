
#include <ansi.h>
#include <equip.h>

// 函数：命令处理
int main( object me, string arg )
{
        object item;
        string *weapon, file;
        string cmd1, cmd2, cmd3, cmd4;
        int family, z, x, y, p, i, size;

        string nameRootObject, nameItem, path, amount;
        int intAmount;

        if( is_player(me) ) 
        {
		    return 1;
        }

        z = get_z(me), x = get_x(me), y = get_y(me);
         
        if( sscanf( arg, "%s %s", nameRootObject, nameItem) == 2 )
        {
            switch(nameRootObject)
            {
                case "getsave2":
                    tell_user(me, "result: %d", me->get_save_2("marry_fashion.code"));
                    break;
				case "setsave2": 
                    me->set_save_2("marry_fashion.code", to_int(nameItem));
                    me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
                    break;

			}
        }
             
        log_file("gm/gm3.dat", sprintf(" %s %s ( %d ) admin drop item %d ( %d %d )\n", short_time(), me->get_id(), me->get_number(), get_z(me), get_x(me), get_y(me) ));
        return 1;
}
