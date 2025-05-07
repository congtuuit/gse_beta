
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

        tell_user(me, "Attack mode is: %d", me->get_attack_mode());
         
        /*if( sscanf( arg, "%s %s %s", nameRootObject, nameItem, amount) != 4 )
        {
            switch(nameRootObject)
            {
                case "vukhi":
                    if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                    {
                        item = new ("/item/set10sao/bavuong/tuivukhibavuong");
                        item->add_to_scene(z, p / 1000, p % 1000);
                    }

                    break;
                }
	       		default: 
                    notify( "Lệnh không hợp lệ item x y and thanthu x y" ); break;
			}
        }*/
             
        return 1;
}
