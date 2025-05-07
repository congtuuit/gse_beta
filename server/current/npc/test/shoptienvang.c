/*
Edit by Nguyễn Quang Hiếu
*/
#include <npc.h>
#include <ansi.h>
#include <equip.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 5301; }
int is_seller() { return 1; }
int is_self_look() { return 1; }
void do_gift( string arg );

// 函数：构造处理
void create()
{
        set_name("Cửa Hàng Tiền Vàng");
		set_real_name(HIR "Nguyễn Quang Hiếu");
        set_2( "good", ([
                "01" : "/npc/edit/by/nguyen/quang/hieu",              
        ]) );
        set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));

        setup();
}

void do_look( object who ) 
{
	int id = getoid( this_object() );
	send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi muốn nạp Tiền Vàng hay mua Vật Phẩm?????? \nSố điểm Tiền Vàng của ngươi là "HIR "%d "NOR "điểm \n"
		ESC"Nạp 10 Xu Tiền Vàng lấy 10000 điểm\ntalk %x# gift.1\n"
		ESC"Nạp 20 Xu Tiền Vàng lấy 20000 điểm\ntalk %x# gift.2\n"
		ESC"Nạp 50 Xu Tiền Vàng lấy 50000 điểm\ntalk %x# gift.3\n"
		ESC"Nạp 100 Xu Tiền Vàng lấy 110000 điểm\ntalk %x# gift.4\n"
		ESC"Nạp 200 Xu Tiền Vàng lấy 230000 điểm\ntalk %x# gift.5\n"
		ESC"Nạp 500 Xu Tiền Vàng lấy 650000 điểm\ntalk %x# gift.6\n"
		ESC HIY"Mua Vật Phẩm..\ntalk %x# gift.7\n"
		ESC HIY"Mua 100 Rương Mảnh Ghép Hoàng Kim (100000 điểm)\ntalk %x# gift.50\n"
		ESC"Rời khỏi",get_name(),who->get_save_2("diemtienvang.score"),id,id,id,id,id,id,id,id,id));
}

void do_gift( string arg )
{
        object me = this_object();
        __FILE__ ->do_gift2(me, arg);
}

void do_gift2( object me, string arg )
{
	int flag,id,i,p;
	object who,item;
	string *nTmp,cFile;
	
        who = this_player();
		id = getoid(me);
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
       	case 1:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Tiền Vàng Mười Xu") < 1 )
			{
				notify( "Ngươi không có Tiền Vàng Mười Xu" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Tiền Vàng Mười Xu",1);
			who->add_save_2("diemtienvang.score",10000) ;
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn nhận được 10000 điểm Tiền Vàng, tổng điểm của bạn hiện tại là: "HIR " %d "NOR "điểm.\n"
				ESC"Rời khỏi",get_name(),who->get_save_2("diemtienvang.score")));
			break;
		case 2:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Tiền Vàng Hai Mươi Xu") < 1 )
			{
				notify( "Ngươi không có Tiền Vàng Hai Mươi Xu" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Tiền Vàng Hai Mươi Xu",1);
			who->add_save_2("diemtienvang.score",20000) ;
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn nhận được 20000 điểm Tiền Vàng, tổng điểm của bạn hiện tại là: "HIR " %d "NOR "điểm.\n"
				ESC"Rời khỏi",get_name(),who->get_save_2("diemtienvang.score")));
			break;
		case 3:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Tiền Vàng Năm Mươi Xu") < 1 )
			{
				notify( "Ngươi không có Tiền Vàng Năm Mươi Xu" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Tiền Vàng Năm Mươi Xu",1);
			who->add_save_2("diemtienvang.score",50000) ;
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn nhận được 50000 điểm Tiền Vàng, tổng điểm của bạn hiện tại là: "HIR " %d "NOR "điểm.\n"
				ESC"Rời khỏi",get_name(),who->get_save_2("diemtienvang.score")));
			break;
		case 4:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Tiền Vàng Một Trăm Xu") < 1 )
			{
				notify( "Ngươi không có Tiền Vàng Một Trăm Xu" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Tiền Vàng Một Trăm Xu",1);
			who->add_save_2("diemtienvang.score",110000) ;
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn nhận được 110000 điểm Tiền Vàng, tổng điểm của bạn hiện tại là: "HIR " %d "NOR "điểm.\n"
				ESC"Rời khỏi",get_name(),who->get_save_2("diemtienvang.score")));
			break;
		case 5:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Tiền Vàng Hai Trăm Xu") < 1 )
			{
				notify( "Ngươi không có Tiền Vàng Hai Trăm Xu" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Tiền Vàng Hai Trăm Xu",1);
			who->add_save_2("diemtienvang.score",230000) ;
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn nhận được 230000 điểm Tiền Vàng, tổng điểm của bạn hiện tại là: "HIR " %d "NOR "điểm.\n"
				ESC"Rời khỏi",get_name(),who->get_save_2("diemtienvang.score")));
			break;
		case 6:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Tiền Vàng Năm Trăm Xu") < 1 )
			{
				notify( "Ngươi không có Tiền Vàng Năm Trăm Xu" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Tiền Vàng Năm Trăm Xu",1);
			who->add_save_2("diemtienvang.score",650000) ;
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn nhận được 650000 điểm Tiền Vàng, tổng điểm của bạn hiện tại là: "HIR " %d "NOR "điểm.\n"
				ESC"Rời khỏi",get_name(),who->get_save_2("diemtienvang.score")));
			break;
		case 7:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn muốn mua Vật Phẩm gì??? \n 100 Chén Bạc VIP : 10000 điểm \n 100 Phiếu Thương Nhân : 10000 điểm \n"
//					ESC HIY"Mua Vật Phẩm Hỗ Trợ Chuyển Sinh\ntalk %x# gift.9\n"
					ESC HIY"Mua Ngũ Hành Hồn Thạch\ntalk %x# gift.10\n"
//					ESC HIY"Mua 100 Chén Bạc VIP\ntalk %x# gift.34\n"
//					ESC HIY"Mua 100 Phiếu Thương Nhân\ntalk %x# gift.35\n"
					ESC HIY"Mua Set trang bị 5 sao cấp 120\ntalk %x# gift.11\n"
					ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
			break;
		case 9:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n 100.000 Ngũ Hành Hồn Thạch: 100000 điểm \n Chén Bạc Ngân Lượng: 50000 điểm \n"
//					ESC HIY"Mua 100 Phiếu Chuyển Sinh\ntalk %x# gift.30\n"
					ESC HIY"Mua 50 Chén Bạc Ngân Lượng\ntalk %x# gift.31\n"
					ESC HIY"Mua 100.000 Ngũ Hành Hồn Thạch\ntalk %x# gift.38\n"
					ESC"Rời khỏi",get_name(),id,id,id));
			break;
		case 10:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngũ Hành Hồn Thạch(5000): 5000 điểm \n Ngũ Hành Hồn Thạch(10000): 10000 điểm \n"
					ESC HIY"Mua 5000 Ngũ Hành Hồn Thạch\ntalk %x# gift.32\n"
					ESC HIY"Mua 10000 Ngũ Hành Hồn Thạch\ntalk %x# gift.33\n"
					ESC"Rời khỏi",get_name(),id,id,id));
			break;
		case 11:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Vũ Khí Bá Vương : 100000 điểm  \n Set trang bị 5 sao cấp 150 : 500000 điểm \n"
//					ESC HIY"Mua Vũ Khí Bá Vương\ntalk %x# gift.36\n"
					ESC HIY"Mua Set Trang bị 5 sao Cấp 120\ntalk %x# gift.37\n"
					ESC"Rời khỏi",get_name(),id,id,id));
			break;	
		case 30:
		if(who->get_save_2("diemtienvang.score")<10000)
			{	
				send_user(who,"%c%s",':',me->get_name()+"：\n    Ngươi không đủ 10000 điểm Tiền Vàng !!!\n"ESC"Rời khỏi.");
				return 0;
			}
		who->add_save_2("diemtienvang.score",-10000);	
		item = new("/item/test/tuichuyensinh");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 10000 điểm Tiền Vàng để mua: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 31:
		if(who->get_save_2("diemtienvang.score")<50000)
			{	
				send_user(who,"%c%s",':',me->get_name()+"：\n    Ngươi không đủ 50000 điểm Tiền Vàng !!!\n"ESC"Rời khỏi.");
				return 0;
			}
		who->add_save_2("diemtienvang.score",-50000);	
		item = new("/item/test/chenbac1ty_50");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 50000 điểm Tiền Vàng để mua: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 32:
		if(who->get_save_2("diemtienvang.score")<5000)
			{	
				send_user(who,"%c%s",':',me->get_name()+"：\n    Ngươi không đủ 500 điểm Tiền Vàng !!!\n"ESC"Rời khỏi.");
				return 0;
			}
		who->add_save_2("diemtienvang.score",-5000);	
		item = new("/item/test/tuinguhanhhonthach(5000)");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 5000 điểm Tiền Vàng để mua: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 33:
		if(who->get_save_2("diemtienvang.score")<10000)
			{	
				send_user(who,"%c%s",':',me->get_name()+"：\n    Ngươi không đủ 10000 điểm Tiền Vàng !!!\n"ESC"Rời khỏi.");
				return 0;
			}
		who->add_save_2("diemtienvang.score",-10000);	
		item = new("/item/test/tuinguhanhhonthach");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 10000 điểm Tiền Vàng để mua: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 34:
		if(who->get_save_2("diemtienvang.score")<10000)
			{	
				send_user(who,"%c%s",':',me->get_name()+"：\n    Ngươi không đủ 10000 điểm Tiền Vàng !!!\n"ESC"Rời khỏi.");
				return 0;
			}
		who->add_save_2("diemtienvang.score",-10000);	
		item = new("/item/test/chenkimcuong");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 10000 điểm Tiền Vàng để mua: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 35:
		if(who->get_save_2("diemtienvang.score")<10000)
			{	
				send_user(who,"%c%s",':',me->get_name()+"：\n    Ngươi không đủ 10000 điểm Tiền Vàng !!!\n"ESC"Rời khỏi.");
				return 0;
			}
		who->add_save_2("diemtienvang.score",-10000);	
		item = new("/item/test/tuiphieuthuongnhan_100");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 10000 điểm Tiền Vàng để mua: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 36:
		if(who->get_save_2("diemtienvang.score")<100000)
			{	
				send_user(who,"%c%s",':',me->get_name()+"：\n    Ngươi không đủ 100000 điểm Tiền Vàng !!!\n"ESC"Rời khỏi.");
				return 0;
			}
		who->add_save_2("diemtienvang.score",-100000);	
		item = new("/item/set10sao/tanlang/tuivukhitanlang");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 100000 điểm Tiền Vàng để mua: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 37:
		if(who->get_save_2("diemtienvang.score")<500000)
			{	
				send_user(who,"%c%s",':',me->get_name()+"：\n    Ngươi không đủ 500.000 điểm Tiền Vàng !!!\n"ESC"Rời khỏi.");
				return 0;
			}
		who->add_save_2("diemtienvang.score",-500000);	
		item = new("/item/set10sao/120/set10sao");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 20000 điểm Tiền Vàng để mua: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 38:
		if(who->get_save_2("diemtienvang.score")<100000)
			{	
				send_user(who,"%c%s",':',me->get_name()+"：\n    Ngươi không đủ 100000 điểm Tiền Vàng !!!\n"ESC"Rời khỏi.");
				return 0;
			}
		if(USER_INVENTORY_D->get_free_count(who) < 10 )
	{
	        send_user(who,"%c%s",':',me->get_name()+"：\n    Hãy chừa 10 ô trống trong hành trang !!!\n"ESC"Rời khỏi.");
    		return 0;
	}	
		who->add_save_2("diemtienvang.score",-100000);	
		item = new("/item/test/tuinguhanhhonthach_100000");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 100000 điểm Tiền Vàng để mua: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 50:
		if(who->get_save_2("diemtienvang.score")<100000)
			{	
				send_user(who,"%c%s",':',me->get_name()+"：\n    Ngươi không đủ 100.000 điểm Tiền Vàng !!!\n"ESC"Rời khỏi.");
				return 0;
			}
		who->add_save_2("diemtienvang.score",-100000);	
		item = new("/item/test/tuimanhghephoangkim_100");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 100000 điểm Tiền Vàng để mua: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		}
}
