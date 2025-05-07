/*
Edit by Nguyễn Quang Hiếu
*/
#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <time.h>
#include <effect.h>

inherit OFFICER;

// 函数：获取人物造型
void reset();
int get_char_picid() { return 6010; }
int is_seller() { return 1; }
int is_self_look() { return 1; }
void do_gift( string arg );

// 函数：构造处理
void create()
{
        set_name("Nữ Tổng Quản");
		set_real_name(HIR "Tổng Giám Đốc");
        set_2( "good", ([
                "01" : "/item/sell/0032",
        ]) );
        set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));

        setup();
}

void do_look( object who ) 
{
	int id = getoid( this_object() );
	send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi muốn làm gì đây?????? \nNgươi hiện đang có "HIR "%d "NOR " Kim Nguyên Bảo !! \n"
	//	ESC HIY"Nhận hỗ trợ Tân Thủ....\ntalk %x# gift.500\n"
		ESC HIY"Đổi Kim Nguyên Bảo....\ntalk %x# gift.1\n"
		ESC HIC"Chào mừng tới Shop Donate Kim Nguyên Bảo....\ntalk %x# gift.1000\n"
		ESC"Rời khỏi",get_name(),"sys/sys/test_db"->get_yuanbao(who)/10,id,id,id,id,id,id,id));
}

void do_gift( string arg )
{
        object me = this_object();
        __FILE__ ->do_gift2(me, arg);
}

void do_gift2( object me, string arg )
{
	int flag,id,i,p,iTime,iDay,iGio;
	object who,item;
	string *nTmp,cFile,cTmp,cFinal,result;
	mixed *mxTime;
	iTime = time();
	mxTime = localtime(iTime);     
	iDay = mxTime[TIME_YDAY];
	iGio = mxTime[TIME_HOUR];
	
        who = this_player();
		id = getoid(me);
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
       	case 1:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi muốn đổi vật phẩm gì bằng Kim Nguyên Bảo? \nNgươi hiện đang có : %d Kim Nguyên Bảo \n"
					ESC HIY"Chuyển Sinh Hoán Kĩ Năng [50 Kim Nguyên Bảo]\ntalk %x# gift.100\n"
					ESC HIY"5000 điểm Cống Hiến Môn Phái [300 Kim Nguyên Bảo]\ntalk %x# gift.101\n"
					ESC HIY"Thần Thú - Thần Tướng [300 Kim Nguyên Bảo]\ntalk %x# gift.119\n"
				//	ESC HIY"Túi Pháp Bảo Vương Giả (1000 Kim Nguyên Bảo]\ntalk %x# gift.120\n"
					ESC HIY"Áo cưới Không hiệu ứng Tóc\ntalk %x# gift.4\n"
					ESC HIY"Túi Tinh Thạch\ntalk %x# gift.3\n"
					ESC HIY"Set Hoàng Kim 5 sao\ntalk %x# gift.2\n"
					ESC"Rời khỏi",get_name(),"sys/sys/test_db"->get_yuanbao(who)/10,id,id,id,id,id,id,id));
			break;
		case 2:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi muốn đổi trang bị hoàng kim nào? \nNgươi hiện đang có : %d Kim Nguyên Bảo \n"
					ESC HIY"Cấp 60 - 5 sao [20 Kim Nguyên Bảo]\ntalk %x# gift.102\n"
					ESC HIY"Cấp 80 - 5 sao [25 Kim Nguyên Bảo]\ntalk %x# gift.103\n"
					ESC HIY"Cấp 100 - 5 sao [30 Kim Nguyên Bảo]\ntalk %x# gift.104\n"
					ESC HIY"Cấp 120 - 5 sao [50 Kim Nguyên Bảo]\ntalk %x# gift.105\n"
					ESC HIY"Cấp 130 - 5 sao [150 Kim Nguyên Bảo]\ntalk %x# gift.106\n"
					ESC"Rời khỏi",get_name(),"sys/sys/test_db"->get_yuanbao(who)/10,id,id,id,id,id,id));
			break;
		case 3:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi muốn đổi Túi Tinh Thạch cấp mấy? \nNgươi hiện đang có : %d Kim Nguyên Bảo \n"
					ESC HIY"Cấp 4 [10 Kim Nguyên Bảo]\ntalk %x# gift.110\n"
					ESC HIY"Cấp 5 [20 Kim Nguyên Bảo]\ntalk %x# gift.111\n"
					ESC HIY"Cấp 6 [40 Kim Nguyên Bảo]\ntalk %x# gift.112\n"
					ESC HIY"Cấp 7 [80 Kim Nguyên Bảo]\ntalk %x# gift.113\n"
					ESC HIY"Cấp 8 [150 Kim Nguyên Bảo]\ntalk %x# gift.114\n"
					ESC HIY"Cấp 9 [300 Kim Nguyên Bảo]\ntalk %x# gift.115\n"
					ESC HIY"Cấp 10 [600 Kim Nguyên Bảo]\ntalk %x# gift.116\n"
					ESC"Rời khỏi",get_name(),"sys/sys/test_db"->get_yuanbao(who)/10,id,id,id,id,id,id,id,id));
			break;
		case 4:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi muốn đổi Trạng Nguyên Phục hay Hôn Sa? \nNgươi hiện đang có : %d Kim Nguyên Bảo \n"
					ESC HIY"Trạng Nguyên Phục [50 Kim Nguyên Bảo]\ntalk %x# gift.117\n"
					ESC HIY"Hôn Sa [30 Kim Nguyên Bảo]\ntalk %x# gift.118\n"
					ESC"Rời khỏi",get_name(),"sys/sys/test_db"->get_yuanbao(who)/10,id,id,id));
			break;	
		case 100:
		if("sys/sys/test_db"->get_yuanbao(who)<500)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi không có đủ 50 Kim Nguyên Bảo !!!\n Ngươi hiện chỉ có :" HIR "%d Kim Nguyên Bảo "NOR "mà thôi !!","sys/sys/test_db"->get_yuanbao(who)/10));
			return 0;
		}
		"sys/sys/test_db"->add_yuanbao(who,-500);
		item = new(sprintf("item/PhanThuongChuyenSinh/ChuyenSinhHoanKiNang"));	
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",':',me->get_name()+"：\nNgươi đổi thành công Chuyển Sinh Hoán Kĩ Năng !!\n"ESC"Rời khỏi.");
		break;
		case 101:
		if("sys/sys/test_db"->get_yuanbao(who)<3000)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi không có đủ 300 Kim Nguyên Bảo !!!\n Ngươi hiện chỉ có :" HIR "%d Kim Nguyên Bảo "NOR "mà thôi !!","sys/sys/test_db"->get_yuanbao(who)/10));
			return 0;
		}
		"sys/sys/test_db"->add_yuanbao(who,-3000);
		who->set_fam_contribute(who->get_fam_contribute()+5000);
		send_user(who,"%c%s",':',me->get_name()+"：\nNgươi đổi thành công 5000 điểm Cống hiến Môn phái !!\n"ESC"Rời khỏi.");
		break;
		case 102:
		if("sys/sys/test_db"->get_yuanbao(who)<200)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi không có đủ 20 Kim Nguyên Bảo !!!\n Ngươi hiện chỉ có :" HIR "%d Kim Nguyên Bảo "NOR "mà thôi !!","sys/sys/test_db"->get_yuanbao(who)/10));
			return 0;
		}
		"sys/sys/test_db"->add_yuanbao(who,-200);
		item = new(sprintf("item/set10sao/60/set10sao"));	
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",':',me->get_name()+"：\nNgươi đổi thành công Túi Hoàng Kim 5 sao cấp 60 !!\n"ESC"Rời khỏi.");
		break;
		case 103:
		if("sys/sys/test_db"->get_yuanbao(who)<250)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi không có đủ 25 Kim Nguyên Bảo !!!\n Ngươi hiện chỉ có :" HIR "%d Kim Nguyên Bảo "NOR "mà thôi !!","sys/sys/test_db"->get_yuanbao(who)/10));
			return 0;
		}
		"sys/sys/test_db"->add_yuanbao(who,-250);
		item = new(sprintf("item/set10sao/80/set10sao"));	
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",':',me->get_name()+"：\nNgươi đổi thành công Túi Hoàng Kim 5 sao cấp 80 !!\n"ESC"Rời khỏi.");
		break;
		case 104:
		if("sys/sys/test_db"->get_yuanbao(who)<300)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi không có đủ 30 Kim Nguyên Bảo !!!\n Ngươi hiện chỉ có :" HIR "%d Kim Nguyên Bảo "NOR "mà thôi !!","sys/sys/test_db"->get_yuanbao(who)/10));
			return 0;
		}
		"sys/sys/test_db"->add_yuanbao(who,-300);
		item = new(sprintf("item/set10sao/100/set10sao"));	
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",':',me->get_name()+"：\nNgươi đổi thành công Túi Hoàng Kim 5 sao cấp 100 !!\n"ESC"Rời khỏi.");
		break;
		case 105:
		if("sys/sys/test_db"->get_yuanbao(who)<500)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi không có đủ 50 Kim Nguyên Bảo !!!\n Ngươi hiện chỉ có :" HIR "%d Kim Nguyên Bảo "NOR "mà thôi !!","sys/sys/test_db"->get_yuanbao(who)/10));
			return 0;
		}
		"sys/sys/test_db"->add_yuanbao(who,-500);
		item = new(sprintf("item/set10sao/120/set10sao"));	
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",':',me->get_name()+"：\nNgươi đổi thành công Túi Hoàng Kim 5 sao cấp 120 !!\n"ESC"Rời khỏi.");
		break;
		case 106:
		if("sys/sys/test_db"->get_yuanbao(who)<1500)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi không có đủ 150 Kim Nguyên Bảo !!!\n Ngươi hiện chỉ có :" HIR "%d Kim Nguyên Bảo "NOR "mà thôi !!","sys/sys/test_db"->get_yuanbao(who)/10));
			return 0;
		}
		"sys/sys/test_db"->add_yuanbao(who,-1500);
		item = new(sprintf("item/set10sao/130/set10sao"));	
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",':',me->get_name()+"：\nNgươi đổi thành công Túi Hoàng Kim 5 sao cấp 130 !!\n"ESC"Rời khỏi.");
		break;
		case 110:
		if("sys/sys/test_db"->get_yuanbao(who)<100)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi không có đủ 10 Kim Nguyên Bảo !!!\n Ngươi hiện chỉ có :" HIR "%d Kim Nguyên Bảo "NOR "mà thôi !!","sys/sys/test_db"->get_yuanbao(who)/10));
			return 0;
		}
		"sys/sys/test_db"->add_yuanbao(who,-100);
		item = new(sprintf("item/TuiLinhThach/NgauNhien/4"));	
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",':',me->get_name()+"：\nNgươi đổi thành công Túi Tinh Thạch cấp 4 !!\n"ESC"Rời khỏi.");
		break;
		case 111:
		if("sys/sys/test_db"->get_yuanbao(who)<200)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi không có đủ 20 Kim Nguyên Bảo !!!\n Ngươi hiện chỉ có :" HIR "%d Kim Nguyên Bảo "NOR "mà thôi !!","sys/sys/test_db"->get_yuanbao(who)/10));
			return 0;
		}
		"sys/sys/test_db"->add_yuanbao(who,-200);
		item = new(sprintf("item/TuiLinhThach/NgauNhien/5"));	
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",':',me->get_name()+"：\nNgươi đổi thành công Túi Tinh Thạch cấp 5 !!\n"ESC"Rời khỏi.");
		break;
		case 112:
		if("sys/sys/test_db"->get_yuanbao(who)<400)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi không có đủ 40 Kim Nguyên Bảo !!!\n Ngươi hiện chỉ có :" HIR "%d Kim Nguyên Bảo "NOR "mà thôi !!","sys/sys/test_db"->get_yuanbao(who)/10));
			return 0;
		}
		"sys/sys/test_db"->add_yuanbao(who,-400);
		item = new(sprintf("item/TuiLinhThach/NgauNhien/6"));	
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",':',me->get_name()+"：\nNgươi đổi thành công Túi Tinh Thạch cấp 6 !!\n"ESC"Rời khỏi.");
		break;
		case 113:
		if("sys/sys/test_db"->get_yuanbao(who)<800)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi không có đủ 80 Kim Nguyên Bảo !!!\n Ngươi hiện chỉ có :" HIR "%d Kim Nguyên Bảo "NOR "mà thôi !!","sys/sys/test_db"->get_yuanbao(who)/10));
			return 0;
		}
		"sys/sys/test_db"->add_yuanbao(who,-800);
		item = new(sprintf("item/TuiLinhThach/NgauNhien/7"));	
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",':',me->get_name()+"：\nNgươi đổi thành công Túi Tinh Thạch cấp 7 !!\n"ESC"Rời khỏi.");
		break;
		case 114:
		if("sys/sys/test_db"->get_yuanbao(who)<1500)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi không có đủ 150 Kim Nguyên Bảo !!!\n Ngươi hiện chỉ có :" HIR "%d Kim Nguyên Bảo "NOR "mà thôi !!","sys/sys/test_db"->get_yuanbao(who)/10));
			return 0;
		}
		"sys/sys/test_db"->add_yuanbao(who,-1500);
		item = new(sprintf("item/TuiLinhThach/NgauNhien/8"));	
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",':',me->get_name()+"：\nNgươi đổi thành công Túi Tinh Thạch cấp 8 !!\n"ESC"Rời khỏi.");
		break;
		case 115:
		if("sys/sys/test_db"->get_yuanbao(who)<3000)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi không có đủ 300 Kim Nguyên Bảo !!!\n Ngươi hiện chỉ có :" HIR "%d Kim Nguyên Bảo "NOR "mà thôi !!","sys/sys/test_db"->get_yuanbao(who)/10));
			return 0;
		}
		"sys/sys/test_db"->add_yuanbao(who,-3000);
		item = new(sprintf("item/TuiLinhThach/NgauNhien/9"));	
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",':',me->get_name()+"：\nNgươi đổi thành công Túi Tinh Thạch cấp 9 !!\n"ESC"Rời khỏi.");
		break;
		case 116:
		if("sys/sys/test_db"->get_yuanbao(who)<6000)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi không có đủ 600 Kim Nguyên Bảo !!!\n Ngươi hiện chỉ có :" HIR "%d Kim Nguyên Bảo "NOR "mà thôi !!","sys/sys/test_db"->get_yuanbao(who)/10));
			return 0;
		}
		"sys/sys/test_db"->add_yuanbao(who,-6000);
		item = new(sprintf("item/TuiLinhThach/NgauNhien/10"));	
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",':',me->get_name()+"：\nNgươi đổi thành công Túi Tinh Thạch cấp 10 !!\n"ESC"Rời khỏi.");
		break;
		case 117:
		if("sys/sys/test_db"->get_yuanbao(who)<500)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi không có đủ 50 Kim Nguyên Bảo !!!\n Ngươi hiện chỉ có :" HIR "%d Kim Nguyên Bảo "NOR "mà thôi !!","sys/sys/test_db"->get_yuanbao(who)/10));
			return 0;
		}
		"sys/sys/test_db"->add_yuanbao(who,-500);
		item = new(sprintf("item/std/0008"));	
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",':',me->get_name()+"：\nNgươi đổi thành công Trạng Nguyên Phục (gốc) !!\n"ESC"Rời khỏi.");
		break;
		case 118:
		if("sys/sys/test_db"->get_yuanbao(who)<300)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi không có đủ 30 Kim Nguyên Bảo !!!\n Ngươi hiện chỉ có :" HIR "%d Kim Nguyên Bảo "NOR "mà thôi !!","sys/sys/test_db"->get_yuanbao(who)/10));
			return 0;
		}
		"sys/sys/test_db"->add_yuanbao(who,-300);
		item = new(sprintf("item/std/0009"));	
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",':',me->get_name()+"：\nNgươi đổi thành công Hôn Sa (gốc) !!\n"ESC"Rời khỏi.");
		break;
		case 119:
		if("sys/sys/test_db"->get_yuanbao(who)<3000)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi không có đủ 300 Kim Nguyên Bảo !!!\n Ngươi hiện chỉ có :" HIR "%d Kim Nguyên Bảo "NOR "mà thôi !!","sys/sys/test_db"->get_yuanbao(who)/10));
			return 0;
		}
		"sys/sys/test_db"->add_yuanbao(who,-3000);
		item = new(sprintf("item/test2/ThanThuThanTuong"));	
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",':',me->get_name()+"：\nNgươi đổi thành công Thần Thú - Thần Tướng !!\n"ESC"Rời khỏi.");
		break;
		case 120:
		if("sys/sys/test_db"->get_yuanbao(who)<10000)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi không có đủ 1000 Kim Nguyên Bảo !!!\n Ngươi hiện chỉ có :" HIR "%d Kim Nguyên Bảo "NOR "mà thôi !!","sys/sys/test_db"->get_yuanbao(who)/10));
			return 0;
		}
		"sys/sys/test_db"->add_yuanbao(who,-10000);
		item = new(sprintf("item/phapbaoHK/tuiphapbaovuong"));	
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",':',me->get_name()+"：\nNgươi đổi thành công Túi Pháp Bảo Vương Giả !!\n"ESC"Rời khỏi.");
		break;
	/*	case 500:
		if ( who->get_level() >= 150 )
				{
        		send_user(who,"%c%s",':',me->get_name()+"：\n    Ngươi đã vượt qua cấp 149, không thể nhận hỗ trợ Tân Thủ được nữa !!!\n"ESC"Rời khỏi.");
        		return;
				}
		if(who->get_save_2("nhanhotro1.score")>=1)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Thiệt là ham hố quá đy !!!\n Ngươi đã nhận hỗ trợ :" HIR " %d "NOR "lần rồi",who->get_save_2("nhanhotro1.score")));
			return 0;
		}
		who->add_save_2("nhanhotro1.score",1);
		item = new(sprintf("item/test/vosongdiemphieu"));
		item->set_amount(1200);		
		i = item->move2(who,-1);
		item->add_to_user(i);
	//	who->add_save("kimnguyenbaocs1.diem",1);
		who->set_level(150);
		send_user(who,"%c%s",':',me->get_name()+"：\nNhận hỗ trợ Tân Thủ thành công!! \nVô Song Điểm Phiếu x1200 \nThăng lên cấp 150 \n"ESC"Rời khỏi.");
		break;*/
		case 1000:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn hiện đang có : %d Kim Nguyên Bảo \nĐến với Cửa hàng Donate Kim Nguyên Bảo của tôi chắc chắc bạn sẽ hài lòng về những vật phẩm mà tôi bày bán \nKý tên : vợ của Ben !!! \n"
					ESC"Rời khỏi",get_name(),"sys/sys/test_db"->get_yuanbao(who)/10,id));
			break;
		}
}
