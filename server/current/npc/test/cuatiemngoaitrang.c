
#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

// 函数：获取人物造型
int is_seller() { return 4; }
int is_self_look() { return 1; }
int get_char_picid() { return 5502; }
void do_welcome( string arg );
void do_bonus(string arg);

// 函数：构造处理
void create()
{
        set_name("Cửa Hàng Ngoại Trang");
		set_real_name("Lão Gầy");
        set_2( "good", ([
				"01" : "/item/100/10051",
				"02" : "/item/100/10052",
				"03" : "/item/100/10053",
				"04" : "/item/100/10054",
				"07" : "/item/100/10055",
				"08" : "/item/100/10056",
				"09" : "/item/100/10057",
				"10" : "/item/100/10058",
				"11" : "/item/100/10059",
				"12" : "/item/100/11051",
				"13" : "/item/100/11052",
				"14" : "/item/100/11053",
				"15" : "/item/100/11054",
				"16" : "/item/100/11055",
				"17" : "/item/100/11056",
				"18" : "/item/100/11057",
				"19" : "/item/100/11058",
				"20" : "/item/100/11059",
        ]) );
		
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
	send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Chào mừng các bạn đến với Cửa Hàng "HIR " phi Phong và Cánh \n Chỗ ni bán đủ loại Phi Phong,Cánh chỉ cần bạn đưa tôi Ngũ Hành Thạch là mọi thứ Okê!!!!\n"
//			ESC HIY " Mua Phi Phong và Cánh .... \ntalk %x# welcome.2\n"
//			ESC HIY " 100.000 NgũHồnThạch = Bí Kíp Cường Hoá Môn Phái 150\ntalk %x# bonus.30\n"
			ESC HIY " Mua Ngoại Trang vật phẩm\nlist %x#\n"
			ESC"Rời khỏi\n",id,id,id,id));
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
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Chào mừng các bạn đến với Cửa Hàng "HIR " phi Phong và Cánh \n Chỗ ni bán đủ loại Phi Phong,Cánh chỉ cần bạn đưa tôi Ngũ Hành Thạch là mọi thứ Okê!!!!\n"
				ESC"Mua (Phi Phong) Nam \ntalk %x# welcome.3\n"
				ESC"Mua (Phi Phong) Nữ \ntalk %x# welcome.4\n"
				ESC"Mua (Cánh) Nam \ntalk %x# welcome.5\n"
				ESC"Mua (Cánh) Nữ \ntalk %x# welcome.6\n"
				ESC"Rời khỏi\n",id,id,id,id,id));
			break;
		case 3:
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Chào mừng các bạn đến với Cửa Hàng "HIR " phi Phong và Cánh \n Chỗ ni bán "HIR " Phi Phong "NOR " dành cho "HIR " Nam "NOR " chỉ cần đưa tui NHT là Okê..!!!\n"
				ESC"1000 NgũHồnThạch = Phi Phong Siêu Phàm Hi Ký\ntalk %x# bonus.2\n"
				ESC"2000 NgũHồnThạch = Phi Phong Ngự Không Phùng Hư\ntalk %x# bonus.3\n"
				ESC"3000 NgũHồnThạch = Phi Phong Hỗn Thiên Trấn Nguyên\ntalk %x# bonus.4\n"
				ESC"4000 NgũHồnThạch = Phi Phong Sồ Phượng Linh Vũ\ntalk %x# bonus.5\n"
				ESC"5000 NgũHồnThạch = Phi Phong Tiềm Long Ngâm Uyên\ntalk %x# bonus.6\n"
				ESC"20.000 NgũHồnThạch = Phi Phong Chí Tôn Truyền Thuyết\ntalk %x# bonus.7\n"
				ESC"40.000 NgũHồnThạch = Phi Phong VÔ SONG\ntalk %x# bonus.8\n"
				ESC"Rời khỏi\n",id,id,id,id,id,id,id,id));
			break;
		case 4:
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Chào mừng các bạn đến với Cửa Hàng "HIR " phi Phong và Cánh \n Chỗ ni bán "HIR " Phi Phong "NOR " dành cho "HIR " Nữ "NOR " chỉ cần đưa tui NHT là Okê..!!!\n"
				ESC"1000 NgũHồnThạch = Phi Phong Siêu Phàm Hi Ký\ntalk %x# bonus.9\n"
				ESC"2000 NgũHồnThạch = Phi Phong Ngự Không Phùng Hư\ntalk %x# bonus.10\n"
				ESC"3000 NgũHồnThạch = Phi Phong Hỗn Thiên Trấn Nguyên\ntalk %x# bonus.11\n"
				ESC"4000 NgũHồnThạch = Phi Phong Sồ Phượng Linh Vũ\ntalk %x# bonus.12\n"
				ESC"5000 NgũHồnThạch = Phi Phong Tiềm Long Ngâm Uyên\ntalk %x# bonus.13\n"
				ESC"20.000 NgũHồnThạch = Phi Phong Chí Tôn Truyền Thuyết\ntalk %x# bonus.14\n"
				ESC"40.000 NgũHồnThạch = Phi Phong VÔ SONG\ntalk %x# bonus.15\n"
				ESC"Rời khỏi\n",id,id,id,id,id,id,id,id));
			break;
			break;	
		case 5:
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Chào mừng các bạn đến với Cửa Hàng "HIR " phi Phong và Cánh \n Chỗ ni bán "HIR " Cánh "NOR " dành cho "HIR " Nam "NOR " chỉ cần đưa tui NHT là Okê..!!!\n"
				ESC"1000 NgũHồnThạch = Thánh Linh Ô Sương\ntalk %x# bonus.20\n"
				ESC"4000 NgũHồnThạch = Thánh Linh Vân Sương\ntalk %x# bonus.21\n"
				ESC"5000 NgũHồnThạch = Thánh Linh Kim Sương\ntalk %x# bonus.22\n"
				ESC"20.000 NgũHồnThạch = Thánh Linh Ngạo Sương\ntalk %x# bonus.23\n"
				ESC"40.000 NgũHồnThạch = Thánh Linh VÔ SONG\ntalk %x# bonus.24\n"
				ESC"Rời khỏi\n",id,id,id,id,id,id));
			break;
		case 6:
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Chào mừng các bạn đến với Cửa Hàng "HIR " phi Phong và Cánh \n Chỗ ni bán "HIR " Cánh "NOR " dành cho "HIR " Nữ "NOR " chỉ cần đưa tui NHT là Okê..!!!\n"
				ESC"1000 NgũHồnThạch = Thánh Linh Ô Sương\ntalk %x# bonus.25\n"
				ESC"4000 NgũHồnThạch = Thánh Linh Vân Sương\ntalk %x# bonus.26\n"
				ESC"5000 NgũHồnThạch = Thánh Linh Kim Sương\ntalk %x# bonus.27\n"
				ESC"20.000 NgũHồnThạch = Thánh Linh Ngạo Sương\ntalk %x# bonus.28\n"
				ESC"40.000 NgũHồnThạch = Thánh Linh VÔ SONG\ntalk %x# bonus.29\n"
				ESC"Rời khỏi\n",id,id,id,id,id,id));
			break;
		case 7:
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Bí Kíp cấp 150 tất cả Môn Phái.... \nMột quyển Bí Kíp giá "HIR " 100000 Ngũ Hành Hồn Thạch "NOR "  \n500 Chén Bạc V.I.P giá "HIR " 50000 Ngũ Hành Hồn Thạch "NOR "  \nBạn có muốn mua không >>???\n"
				ESC HIY " 100.000 NgũHồnThạch = Bí Kíp Cường Hoá Môn Phái 150\ntalk %x# bonus.30\n"
				ESC HIY " 70.000 NgũHồnThạch = 100 Chén Bạc V.I.P\ntalk %x# bonus.31\n"
				ESC"Ta muốn mua Phi Phong và Cánh....\ntalk %x# welcome.2\n"
				ESC"Rời khỏi\n",id,id,id,id));
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
	object who,item;
	string cTmp,cFile;
	who = this_player();
	flag = to_int(arg);
        switch(flag)
        {
       	case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
       	case 8:
       	case 9:
		case 10:	
       	case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 20:
		case 21:
		case 22:
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
			if ( flag == 2 )
			{
				point = 1000;
				cFile = "item/ppvacanh/phiphong/nam/lv0";
			}
			else if ( flag == 3 )
			{
				point = 2000;
				cFile = "item/ppvacanh/phiphong/nam/lv30";
			}
			else if ( flag == 4 )
			{
				point = 3000;
				cFile = "item/ppvacanh/phiphong/nam/lv60";
			}
			else if ( flag == 5 )
			{
				point = 4000;
				cFile = "item/ppvacanh/phiphong/nam/lv80";
			}
			else if ( flag == 6 )
			{
				point = 5000;
				cFile = "item/ppvacanh/phiphong/nam/lv100";
			}
			else if ( flag == 7 )
			{
				point = 20000;
				cFile = "item/ppvacanh/phiphong/nam/lv120";
			}
			else if ( flag == 8 )
			{
				point = 40000;
				cFile = "item/ppvacanh/phiphong/nam/lv150";
			}
			else if ( flag == 9 )
			{
				point = 1000;
				cFile = "item/ppvacanh/phiphong/nu/lv0";
			}
			else if ( flag == 10 )
			{
				point = 2000;
				cFile = "item/ppvacanh/phiphong/nu/lv30";
			}
			else if ( flag == 11 )
			{
				point = 3000;
				cFile = "item/ppvacanh/phiphong/nu/lv60";
			}
			else if ( flag == 12 )
			{
				point = 4000;
				cFile = "item/ppvacanh/phiphong/nu/lv80";
			}
			else if ( flag == 13 )
			{
				point = 5000;
				cFile = "item/ppvacanh/phiphong/nu/lv100";
			}
			else if ( flag == 14 )
			{
				point = 20000;
				cFile = "item/ppvacanh/phiphong/nu/lv120";
			}
			else if ( flag == 15 )
			{
				point = 40000;
				cFile = "item/ppvacanh/phiphong/nu/lv150";
			}
			else if ( flag == 20 )
			{
				point = 1000;
				cFile = "item/ppvacanh/canh/nam/lv0";
			}
			else if ( flag == 21 )
			{
				point = 4000;
				cFile = "item/ppvacanh/canh/nam/lv60";
			}
			else if ( flag == 22 )
			{
				point = 5000;
				cFile = "item/ppvacanh/canh/nam/lv100";
			}
			else if ( flag == 23 )
			{
				point = 20000;
				cFile = "item/ppvacanh/canh/nam/lv120";
			}
			else if ( flag == 24 )
			{
				point = 40000;
				cFile = "item/ppvacanh/canh/nam/lv150";
			}
			else if ( flag == 25 )
			{
				point = 1000;
				cFile = "item/ppvacanh/canh/nu/lv0";
			}
			else if ( flag == 26 )
			{
				point = 4000;
				cFile = "item/ppvacanh/canh/nu/lv60";
			}
			else if ( flag == 27 )
			{
				point = 5000;
				cFile = "item/ppvacanh/canh/nu/lv100";
			}
			else if ( flag == 28 )
			{
				point = 20000;
				cFile = "item/ppvacanh/canh/nu/lv120";
			}
			else if ( flag == 29 )
			{
				point = 40000;
				cFile = "item/ppvacanh/canh/nu/lv150";
			}
			else if ( flag == 30 )
			{
				point = 100000;
				cFile = "item/tuimattich150";
			}
			else if ( flag == 31 )
			{
				point = 70000;
				cFile = "item/test/chenkimcuong";
			}
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Ngũ Hành Hồn Thạch") < point )
			{
				notify( "Ngũ Hành Hồn Thạch của bạn không đủ" );
				return ;	
			}
			if( USER_INVENTORY_D->count_empty_carry(who) < 1 )
			{
				send_user(who,"%c%s",'!',"Hành trang của bạn không đủ chỗ");
				return 0;
			}
			TASK_LEGEND_D->check_task_item1(who,"Ngũ Hành Hồn Thạch",point);
			item = new(cFile);
			i = item->move(who,-1);
			if ( !i )
			{
				destruct(item);
				return ;	
			}
			item->add_to_user(i);
			item->set_hide(0);
			USER_D->user_channel(sprintf(HIG" "HIR "Thông Báo:"HIG " Bằng hữu "HIC "%s" HIG" vừa từ cửa hàng Phi Phong và Cánh mua: " HIY"%s " HIG " !! ", who->get_name(),item->get_name() ));
			send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
			break;
        }	
}