
#include <ansi.h>
#include <equip.h>

// 函数：命令处理
int main( object me, string arg )
{
        object item;
        string *weapon, file;
        string cmd1, cmd2, cmd3, cmd4;
        string nameItem;
        int number;
        int family, z, x, y, p, i, size;

        if( is_player(me) ) 
        {
                notify( "。" );
		return 1;
        }
        z = get_z(me), x = get_x(me), y = get_y(me);
         
        if( sscanf( arg, "%s %d", nameItem, number) != 3 )
        {
            switch(nameItem)
            {
                case "ppnam": 
                    for (i = 0; i < number; i++)
                    {        	
        	            if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/30/3020");
        		            item->set_value(5000);
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                    }
                    break;
				case "ppnu": 
                    for (i = 0; i < number; i++)
                    {        	
        	            if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/30/3021");
        		            item->set_value(5000);
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                    }
                    break;
				case "canhnam": 
                    for (i = 0; i < number; i++)
                    {        	
        	            if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/30/3031");
        		            item->set_value(5000);
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                    }
                    break;
				case "canhnu": 
                    for (i = 0; i < number; i++)
                    {        	
        	            if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/30/3028");
        		            item->set_value(5000);
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                    }
                    break;
                case "money": 
                    for (i = 0; i < number; i++)
                    {        	
        	            if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/std/0001");
        		            item->set_value(1000000);
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                    }
                    break;

                case "diemphieu": 
                    for (i = 0; i < number; i++)
                    {        	
        	            if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/test/vosongdiemphieu");
        		            item->set_amount(100);
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                    }
                    break;

                case "nhattt": 
                    for (i = 0; i < number; i++)
                    {        	
        	            if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/mop/9005");
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                    }
                break;

                case "nguyettt": 
                    for (i = 0; i < number; i++)
                    {        	
        	            if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/sell/9988");
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                    }
                break;

	       		default: 
                    notify( "Lệnh không hợp lệ" ); break;
			}
           
        }

        
        	
        	
             
        log_file("gm/gm3.dat", sprintf(" %s %s ( %d ) phần thưởng hoạt động %d ( %d %d )\n", short_time(), me->get_id(), me->get_number(), get_z(me), get_x(me), get_y(me) ));
        return 1;
}
