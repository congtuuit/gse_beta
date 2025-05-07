
#include <npc.h>
#include <ansi.h>
#include <task.h>
inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 5407; }
void do_welcome( string arg );
void do_bonus(string arg);

// 函数：构造处理
void create()
{
        set_name("Thợ Rèn Bí Ẩn");
        set_2( "talk", ([
				"welcome"          : (: do_welcome :),
				"bonus"        : (: do_bonus :),
        ]));

       setup();
}

// 函数：对话处理
void do_look( object who )
{
	int id = getoid( this_object() );
	send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Hoan nghênh! Hãy mang cho ta những sợi Lông Vũ Đặc Biệt, ta có thể rèn và kết tinh ra những trang bị cực phẩm!\n"
		ESC"Đổi 500 Lông Vũ Đặc Biệt lấy Vương Giả Phi Phong +1\ntalk %x# bonus.1\n"
		ESC"Đổi 500 Lông Vũ Đặc Biệt lấy Xí Nhiệt Phi Phong +1\ntalk %x# bonus.2\n"
		ESC"Đổi 500 Lông Vũ Đặc Biệt lấy Thánh Linh Chi Dực·Vàng Nhạt +1 \ntalk %x# bonus.3\n"
		ESC"Đổi 500 Lông Vũ Đặc Biệt lấy Thánh Linh Chi Dực·Trắng Thuần +1\ntalk %x# bonus.4\n"
		ESC"Trang kế tiếp\ntalk %x# welcome.2\n",id,id,id,id,id));
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,id,p;
	object who,item;
	
        who = this_player();
		id = getoid(me);
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
       	case 1:
        	break;
		case 2:
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Hoan nghênh! Vô Song Thành là thiên hạ đệ nhất đại thành với những bảo vật quý hiếm trên nhân gian, chỉ cần ngươi giao cho ta Vô Song Điểm Phiếu thì sẽ được tưởng thưởng hậu hĩ!\n"
				ESC"Đổi 2500 Lông Vũ Đặc Biệt lấy Vương Giả Phi Phong +2\ntalk %x# bonus.5\n"
				ESC"Đổi 2500 Lông Vũ Đặc Biệt lấy Xí Nhiệt Phi Phong +2\ntalk %x# bonus.6\n"
				ESC"Đổi 2500 Lông Vũ Đặc Biệt lấy Thánh Linh Chi Dực·Vàng Nhạt +2\ntalk %x# bonus.7\n"
				ESC"Đổi 2500 Lông Vũ Đặc Biệt lấy Thánh Linh Chi Dực·Trắng Thuần +2\ntalk %x# bonus.8\n"
				ESC"Đổi 12000 Lông Vũ Đặc Biệt lấy Vương Giả Phi Phong +3\ntalk %x# bonus.9\n"
				ESC"Đổi 12000 Lông Vũ Đặc Biệt lấy Xí Nhiệt Phi Phong +3\ntalk %x# bonus.10\n"
				ESC"Đổi 12000 Lông Vũ Đặc Biệt lấy Thánh Linh Chi Dực·Vàng Nhạt +3\ntalk %x# bonus.11\n"
				ESC"Đổi 12000 Lông Vũ Đặc Biệt lấy Thánh Linh Chi Dực·Trắng Thuần +3\ntalk %x# bonus.12\n"
				ESC"Thoát\n",id,id,id,id,id,id,id,id));
			break;
        }	
}

void do_bonus(string arg)
{
	__FILE__->do_bonus_2(this_object(),arg);
}

void do_bonus_2( object me, string arg )
{
	int flag,point,i,id,p;
	int isItem = 0;
	object who,item;
	string cTmp,cFile;
	who = this_player();
	flag = to_int(arg);
        switch(flag)
        {
       	case 1:
			send_user(who,"%c%s",':',sprintf( "Bạn muốn dùng 500 Lông Vũ Đặc Biệt lấy"HIR"Vương Giả Phi Phong +1 "NOR"không?\n"
				ESC"Đồng ý\ntalk %x# bonus.31\n"
				ESC"Không",getoid(me)));
			break;
		case 2:
			send_user(who,"%c%s",':',sprintf( "Bạn muốn dùng 500 Lông Vũ Đặc Biệt lấy"HIR"Xí Nhiệt Phi Phong +1 "NOR"không?\n"
				ESC"Đồng ý\ntalk %x# bonus.32\n"
				ESC"Không",getoid(me)));
			break;
		case 3:
			send_user(who,"%c%s",':',sprintf( "Bạn muốn dùng 500 Lông Vũ Đặc Biệt lấy"HIR"Thánh Linh Chi Dực·Vàng Nhạt +1 "NOR"không?\n"
				ESC"Đồng ý\ntalk %x# bonus.33\n"
				ESC"Không",getoid(me)));
			break;
		case 4:
			send_user(who,"%c%s",':',sprintf( "Bạn muốn dùng 500 Lông Vũ Đặc Biệt lấy"HIR"Thánh Linh Chi Dực·Trắng Thuần +1 "NOR"không?\n"
				ESC"Đồng ý\ntalk %x# bonus.34\n"
				ESC"Không",getoid(me)));
			break;
		case 5:
			send_user(who,"%c%s",':',sprintf( "Bạn muốn dùng 500 Lông Vũ Đặc Biệt lấy"HIR"Vương Giả Phi Phong +2 "NOR"không?\n"
				ESC"Đồng ý\ntalk %x# bonus.35\n"
				ESC"Không",getoid(me)));
			break;
		case 6:
			send_user(who,"%c%s",':',sprintf( "Bạn muốn dùng 500 Lông Vũ Đặc Biệt lấy"HIR"Xí Nhiệt Phi Phong +2 "NOR"không?\n"
				ESC"Đồng ý\ntalk %x# bonus.36\n"
				ESC"Không",getoid(me)));
			break;
		case 7:
			send_user(who,"%c%s",':',sprintf( "Bạn muốn dùng 500 Lông Vũ Đặc Biệt lấy"HIR"Thánh Linh Chi Dực·Vàng Nhạt +2"NOR"không?\n"
				ESC"Đồng ý\ntalk %x# bonus.37\n"
				ESC"Không",getoid(me)));
			break;
       	case 8:
			send_user(who,"%c%s",':',sprintf( "Bạn muốn dùng 500 Lông Vũ Đặc Biệt lấy"HIR"Thánh Linh Chi Dực·Trắng Thuần +2"NOR"không?\n"
				ESC"Đồng ý\ntalk %x# bonus.38\n"
				ESC"Không",getoid(me)));
			break;
       	case 9:
			send_user(who,"%c%s",':',sprintf( "Bạn muốn dùng 500 Lông Vũ Đặc Biệt lấy"HIR"Vương Giả Phi Phong +2 "NOR"không?\n"
				ESC"Đồng ý\ntalk %x# bonus.39\n"
				ESC"Không",getoid(me)));
			break;
		case 10:
			send_user(who,"%c%s",':',sprintf( "Bạn muốn dùng 500 Lông Vũ Đặc Biệt lấy"HIR"Xí Nhiệt Phi Phong +2 "NOR"không?\n"
				ESC"Đồng ý\ntalk %x# bonus.40\n"
				ESC"Không",getoid(me)));
			break;
		case 11:
			send_user(who,"%c%s",':',sprintf( "Bạn muốn dùng 500 Lông Vũ Đặc Biệt lấy"HIR"Thánh Linh Chi Dực·Vàng Nhạt +2"NOR"không?\n"
				ESC"Đồng ý\ntalk %x# bonus.41\n"
				ESC"Không",getoid(me)));
			break;
		case 12:
			send_user(who,"%c%s",':',sprintf( "Bạn muốn dùng 500 Lông Vũ Đặc Biệt lấy"HIR"Thánh Linh Chi Dực·Trắng Thuần +2"NOR"không?\n"
				ESC"Đồng ý\ntalk %x# bonus.42\n"
				ESC"Không",getoid(me)));
			break;
		case 31:
		case 32:
		case 33:
		case 34:
		case 35:
		case 36:
		case 37:
		case 38:
		case 39:
		case 40:
		case 41:
		case 42:
			if ( flag == 31 )
			{
				isItem == 1;
				point = 500;
				cFile = "/item/ppvacanh/vgpp/vgpp_1";
			}
			else if ( flag == 32 )
			{
				isItem == 1;
				point = 500;
				cFile = "/item/ppvacanh/xnpp/xnpp_1";
			}
			else if ( flag == 33 )
			{
				isItem == 1;
				point = 500;
				cFile = "/item/ppvacanh/canhnam/canhnam_1";
			}
			else if ( flag == 34 )
			{
				isItem == 1;
				point = 500;
				cFile = "/item/ppvacanh/canhnu/canhnu_1";
			}
			else if ( flag == 35 )
			{
				isItem == 1;
				point = 2500;
				cFile = "/item/ppvacanh/vgpp/vgpp_2";
			}
			else if ( flag == 36 )
			{
				isItem == 1;
				point = 2500;
				cFile = "/item/ppvacanh/xnpp/xnpp_2";
			}
			else if ( flag == 37 )
			{
				isItem == 1;
				point = 2500;
				cFile = "/item/ppvacanh/canhnam/canhnam_2";
			}
			else if ( flag == 38 )
			{
				isItem == 1;
				point = 2500;
				cFile = "/item/ppvacanh/canhnu/canhnu_2";
			}
			else if ( flag == 39 )
			{
				isItem == 1;
				point = 12000;
				cFile = "/item/ppvacanh/vgpp/vgpp_3";
			}
			else if ( flag == 40 )
			{
				isItem == 1;
				point = 12000;
				cFile = "/item/ppvacanh/xnpp/xnpp_3";
			}
			else if ( flag == 41 )
			{
				isItem == 1;
				point = 12000;
				cFile = "/item/ppvacanh/canhnam/canhnam_3";
			}
			else if ( flag == 42 )
			{
				isItem == 1;
				point = 12000;
				cFile = "/item/ppvacanh/canhnu/canhnu_3";
			}

			if ( TASK_LEGEND_D->check_task_item_amount(who,"Lông Vũ Đặc Biệt") < point )
			{
				notify( "Lông Vũ Đặc Biệt của bạn không đủ" );
				return ;	
			}
			if( USER_INVENTORY_D->count_empty_carry(who) < 1 )
			{
				send_user(who,"%c%s",'!',"Hành trang của bạn không đủ chỗ");
				return 0;
			}

			if(TASK_LEGEND_D->check_task_item1(who,"Lông Vũ Đặc Biệt",point)){
				item = new(cFile);
				i = item->move(who,-1);
				if ( !i )
				{
					destruct(item);
					return ;	
				}
				item->add_to_user(i);
				send_user(who,"%c%s",';',"Bạn nhận được "HIY+item->get_name());
				USER_D->user_channel(sprintf("Chúc mừng %s nhận được "HIY"%s",who->get_name()  ,item->get_name() ));
				
			}
			break;
        }	
}

