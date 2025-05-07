
#include <ansi.h>
#include <equip.h>

// 函数：命令处理
int main( object me, string arg )
{
        object item;
        string *weapon, file;
        string cmd1, cmd2, cmd3, cmd4;
        string nameItem, path;
        string folder, fileName;
        int family, z, x, y, p, i, size;

        if( is_player(me) ) 
        {
                notify( "。" );
		return 1;
        }
        z = get_z(me), x = get_x(me), y = get_y(me);
         
        if( sscanf( arg, "%s %s %s", nameItem, folder, fileName) != 3 )
        {
            switch(nameItem)
            {
				case "item"
        	        if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	        {
                        path = "/" + nameItem + "/" + folder + "/" + fileName;
        		        item = new (path);
        		        item->set_value(5000);
        		        item->add_to_scene(z, p / 1000, p % 1000);
        	        }
                    break;

	       		default: 
                    notify( "Lệnh không hợp lệ" ); break;
			}
           
        }
             
        log_file("gm/gm3.dat", sprintf(" %s %s ( %d ) phần thưởng hoạt động %d ( %d %d )\n", short_time(), me->get_id(), me->get_number(), get_z(me), get_x(me), get_y(me) ));
        return 1;
}
