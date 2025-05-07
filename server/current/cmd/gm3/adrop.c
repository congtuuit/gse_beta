
#include <ansi.h>
#include <equip.h>

// 函数：命令处理
int main( object me, string arg )
{
        object item, who;
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
         
        if( sscanf( arg, "%s %s %s", nameRootObject, nameItem, amount) != 4 )
        {
            switch(nameRootObject)
            {
                case "core":
                    switch (nameItem)
                    {
                        case "chientruong":

                            if (amount && !(who = find_any_char(amount)))
                            {
                                notify("Bạn không thể tìm thấy người này。");
                                return 1;
                            }
                            who->add_save_2("changping.score", 100);
                            tell_user(me, "Đã cộng 100đ chiến trường");

                            break;
                    }
                    break;

                case "item": 
                    intAmount = to_int(amount);
                    switch(nameItem)
                    {
                        case "top":
                            for (i = 0; i < intAmount; i++)
                            {
                                if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                                {
                                    item = new ("/item/thuongtop/Top");
                                    item->add_to_scene(z, p / 1000, p % 1000);
                                }
                            }
                        break;
                        case "topphuho":
                            for (i = 0; i < intAmount; i++)
                            {
                                if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                                {
                                    item = new ("/item/thuongtop/TopPhuHo1");
                                    item->add_to_scene(z, p / 1000, p % 1000);
                                }

                                if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                                {
                                    item = new ("/item/thuongtop/TopPhuHo2");
                                    item->add_to_scene(z, p / 1000, p % 1000);
                                }
                            }
                            break;
                        case "topthucluc":
                            for (i = 0; i < intAmount; i++)
                            {
                                if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                                {
                                    item = new ("/item/thuongtop/TopThucLuc1");
                                    item->add_to_scene(z, p / 1000, p % 1000);
                                }

                                if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                                {
                                    item = new ("/item/thuongtop/TopThucLuc2");
                                    item->add_to_scene(z, p / 1000, p % 1000);
                                }

                                if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                                {
                                    item = new ("/item/thuongtop/TopThucLuc3");
                                    item->add_to_scene(z, p / 1000, p % 1000);
                                }
                            }
                            break;


                        case "holo":
                            for (i = 0; i < intAmount; i++)
                            {
                                if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                                {
                                    item = new ("/item/33/3325");
                                    item->set_amount(30);
                                    item->add_to_scene(z, p / 1000, p % 1000);
                                }
                            }
                        break;
                        
                        case "diemdanh":
                            for (i = 0; i < intAmount; i++)
                            {
                                if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                                {
                                    item = new ("/item/diemdanh/0438");
                                    item->set_amount(30);
                                    item->add_to_scene(z, p / 1000, p % 1000);
                                }
                            }
                        break;

                        case "holo2":
                            for (i = 0; i < intAmount; i++)
                            {
                                if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                                {
                                    item = new ("/item/event/KeoDuong");
                                    item->set_amount(30);
                                    item->add_to_scene(z, p / 1000, p % 1000);
                                }
                            }
                            break;

                        case "tuiknb2":
                            for (i = 0; i < intAmount; i++)
                            {
                                if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                                {
                                    item = new ("/npc/event/PhoBan/item/tuiknb2");
                                    item->add_to_scene(z, p / 1000, p % 1000);
                                }
                            }
                            break;

                        case "tien":  
                        for (i = 0; i < intAmount; i++)
                        {        	
        	                if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	                {
        		                item = new ("/item/std/0001");
        		                item->set_value(500000);
        		                item->add_to_scene(z, p / 1000, p % 1000);
        	                }
                        }
                        break;
                        case "canhnam":  
	                        if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
    	                    {
	        		            item = new ("/item/ppvacanh/canhnam/canhnam");
	        		            item->add_to_scene(z, p / 1000, p % 1000);
	                        }
                        break;
                        case "canhnam2":
                            if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                            {
                                item = new ("/item/ppvacanh/canhnam/canhnam_2");
                                item->add_to_scene(z, p / 1000, p % 1000);
                            }
                            break;
                        case "pp":
                            if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                            {
                                item = new ("/item/ppvacanh/vgpp/vgpp");
                                item->add_to_scene(z, p / 1000, p % 1000);
                            }
                            break;
                        case "pp2":
                            if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                            {
                                item = new ("/item/ppvacanh/vgpp/vgpp_2");
                                item->add_to_scene(z, p / 1000, p % 1000);
                            }
                            break;
                       
                        case "tk55":  
                            if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	                {
                                path = "/item/test/tuitukim";
                                path->set_star(amount);
        		                item = new (path);
        		                item->add_to_scene(z, p / 1000, p % 1000);
                            }
                        break;
                        case "tk552":
                            if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                            {
                                path = "/item/set/tukim55/set";
                                path->set_star(amount);
                                item = new (path);
                                item->add_to_scene(z, p / 1000, p % 1000);
                            }
                            break;
                        case "tk75":
                            if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                            {
                                path = "/item/test2/tuitukim75";
                                path->set_star(amount);
                                item = new (path);
                                item->add_to_scene(z, p / 1000, p % 1000);
                            }
                            break;

                        case "tk752":
                            if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                            {
                                path = "/item/test/tuitukim85";
                                path->set_star(amount);
                                item = new (path);
                                item->add_to_scene(z, p / 1000, p % 1000);
                            }
                            break;

                        case "tuilinhthach":
                            if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	                {
                                path = "/item/TuiLinhThach/NgauNhien/" + amount;
        		                item = new (path);
        		                item->add_to_scene(z, p / 1000, p % 1000);
                            }
                        break;
                        case "tuva":
                            if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                            {
                                item = new ("/item/std/0095");
                                item->add_to_scene(z, p / 1000, p % 1000);
                            }
                            break;

                        case "vsdp":  
        	            if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/test/vosongdiemphieu");
                            item-> set_amount(500);
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                        break;
                        case "cql":  
        	            if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/08/0001");
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                        break;

                        case "nguhon":
                            if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                            {
                                item = new ("/npc/event/PhoBan/item/1");
                                item->add_to_scene(z, p / 1000, p % 1000);
                            }
                            if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                            {
                                item = new ("/npc/event/PhoBan/item/2");
                                item->add_to_scene(z, p / 1000, p % 1000);
                            }
                            if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                            {
                                item = new ("/npc/event/PhoBan/item/3");
                                item->add_to_scene(z, p / 1000, p % 1000);
                            }
                            if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                            {
                                item = new ("/npc/event/PhoBan/item/4");
                                item->add_to_scene(z, p / 1000, p % 1000);
                            }
                            if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                            {
                                item = new ("/npc/event/PhoBan/item/0");
                                item->add_to_scene(z, p / 1000, p % 1000);
                            }
                            break;

                        case "thuhon":
                            if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                            {
                                item = new ("/npc/event/PhoBan/item/thuhon");
                                item->add_to_scene(z, p / 1000, p % 1000);
                            }
                            break;
                        case "manhngoc":
                            for (i = 0; i < intAmount; i++)
                            {
                                if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                                {
                                    item = new ("/npc/event/PhoBan/item/manhngoc");
                                    item->add_to_scene(z, p / 1000, p % 1000);
                                }
                            }
                            break;
                        case "hoathachcaocap":
                            for (i = 0; i < intAmount; i++)
                            {
                                if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                                {
                                    item = new ("/npc/event/PhoBan/item/hoathachtest");
                                    item->add_to_scene(z, p / 1000, p % 1000);
                                }
                            }
                            break;

                        case "cb":
                            for (i = 0; i < intAmount; i++)
                            {
                                if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                                {
                                    item = new ("/item/test/chenbacvip");
                                    item->add_to_scene(z, p / 1000, p % 1000);
                                }
                            }
                            break;

                        case "chuong":
                            for (i = 0; i < intAmount; i++)
                            {
                                if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                                {
                                    item = new ("/item/mop/9562");
                                    item->add_to_scene(z, p / 1000, p % 1000);
                                }
                            }
                            break;
                        
                        case "vsdp":
                            for (i = 0; i < intAmount; i++)
                            {
                                if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                                {
                                    item = new ("/item/test/vosongdiemphieu");
                                    item->add_to_scene(z, p / 1000, p % 1000);
                                }
                            }
                            break;
                        case "ketdinh":
                            if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                            {
                                item = new ("/item/sell/3032");
                                item->add_to_scene(z, p / 1000, p % 1000);
                            }
                            break;

					}
                    break;
				case "thanthu": 
                    switch(nameItem)
                    {
                        case "kilan":  
        	            if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/ride/018");
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                        break;
                        case "cao":  
                        if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/ride/026");
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                        break;
                        case "holy":  
                        if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/ride/027");
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                        break;
                        case "gau":  
                        if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/ride/028");
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                        break;
                        case "gau2":  
                        if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/ride/029");
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                        break;
                        case "voi":  
                        if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/ride/030");
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                        break;
                        case "voi2":  
                        if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/ride/031");
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                        break;
                        case "rua":  
                        if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/ride/033");
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                        break;
                        case "tuanloc":  
                        if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/ride/038");
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                        break;
                        case "tuanloc2":  
                        if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/ride/038");
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                        break;
                        case "khac":  
                        if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
                            path = "/item/ride/" + amount;
        		            item = new ("/item/ride/");
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                        break;

                        case "phapbao":
                            for (i = 1; i < 6; i++) {
                                if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                                {
                                    item = new(sprintf("item/mop/95%d2", i));
                                    item->add_to_scene(z, p / 1000, p % 1000);
                                }
                            }

                            break;
					}
                    break;

                case "ch":
                    switch (nameItem)
                    {
                    case "ngoaicong":
                        me->set_skill(0430, intAmount);
                        break;
                    case "ngoaikhang":
                        me->set_skill(0431, intAmount);
                        break;

                    case "noicong":
                        me->set_skill(0432, intAmount);
                        break;
                    case "noikhang":
                        me->set_skill(0433, intAmount);
                        break;
                    case "thanthu":
                        me->set_skill(0434, intAmount);
                        break;
                    case "baokich":
                        me->set_skill(0435, intAmount);
                        break;
                    case "duoclieu":
                        me->set_skill(0436, intAmount);
                        break;
                    case "chinhxac":
                        me->set_skill(0437, intAmount);
                        break;
                    case "baoho":
                        me->set_skill(0438, intAmount);
                        break;
                    }
                    break;
                case "phapbao":
                    switch(nameItem)
                    {
                        case "tui":  
        	            if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/phapbaoHK/tuiphapbao");
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                        break;
                        case "tuihk":  
        	            if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/phapbaoHK/tuiphapbaohoangkim");
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                        break;
                        case "tuicc":  
        	            if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            {
        		            item = new ("/item/phapbaoHK/tuiphapbaohoangkimcaocap");
        		            item->add_to_scene(z, p / 1000, p % 1000);
        	            }
                        break;
                        case "tuivip":  
        	            // if ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
        	            // {
        		        //     item = new ("/item/phapbaoHK/tuiphapbaovuongdyt");
        		        //     item->add_to_scene(z, p / 1000, p % 1000);
        	            // }
                        break;
                        
                    }
                    break;
                case "150":
                    switch (nameItem)
                    {
                    case "set":

                        if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                        {
                            item = new ("/item/set10sao/setbavuong/set10sao");
                            item->add_to_scene(z, p / 1000, p % 1000);
                        }

                        break;
                    case "vukhi":
                        if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
                        {
                            item = new ("/item/set10sao/bavuong/tuivukhibavuong");
                            item->add_to_scene(z, p / 1000, p % 1000);
                        }

                        break;
                    }
                    break;
                case "thach":
                    item = new(sprintf("/item/sell/%d", 9301 + to_int(nameItem)));
                    item->set_level(to_int(amount));
                    p = item->move(me, -1);
                    item->add_to_user(p);

                    break;
	       		default: 
                    notify( "Lệnh không hợp lệ item x y and thanthu x y" ); break;
			}
        }
             
        log_file("gm/gm3.dat", sprintf(" %s %s ( %d ) admin drop item %d ( %d %d )\n", short_time(), me->get_id(), me->get_number(), get_z(me), get_x(me), get_y(me) ));
        return 1;
}
