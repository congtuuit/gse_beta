/*
Edit by Nguyễn Quang Hiếu
*/
#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <time.h>
#include <effect.h>
#include <skill.h>

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
        set_name("Sứ Giả Hoạt Động 2");
		set_real_name(HIR "Việt Nam");
        set_2( "good", ([
                "01" : "/item/test2/HoaHong2",
        ]) );
        set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));

        setup();
}

void do_look( object who ) 
{
	int id = getoid( this_object() );
	send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi có điểm Chiến Tích hay điểm Công Đức ? Muốn đổi cái gì đây ?????? \n"
		ESC HIY"Đổi điểm Chiến Tích lấy phần thưởng....\ntalk %x# gift.2\n"
		ESC HIY"Kiểm tra điểm Chiến Tích....\ntalk %x# gift.4\n"
		ESC HIY"Nhận thưởng Chiến Quốc Minh Chủ....\ntalk %x# gift.3\n"
		ESC HIY"Mua Hoa Hồng cho những ngày Quốc Tế Phi Phụ Nữ\nlist %x#\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id,id,id));
}

void do_gift( string arg )
{
        object me = this_object();
        __FILE__ ->do_gift2(me, arg);
}

void do_gift2( object me, string arg )
{
	int flag,id,i,p,iTime,iDay,iGio,rate,l,tien;
	object who,item,item1,item2,item3;
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
		rate = random(100);
        switch(flag)
        {
       	case 1:
			break;
		case 2:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi muốn dùng điểm Chiến Tích để đổi Kim Nguyên Bảo phải không ????? \n"
					ESC HIY"5.000 điểm đổi lấy [25 Kim Nguyên Bảo]\ntalk %x# gift.101\n"
					ESC HIY"10.000 điểm đổi lấy [50 Kim Nguyên Bảo]\ntalk %x# gift.102\n"
					ESC HIY"20.000 điểm đổi lấy [105 Kim Nguyên Bảo]\ntalk %x# gift.103\n"
					ESC HIY"50.000 điểm đổi lấy [260 Kim Nguyên Bảo]\ntalk %x# gift.104\n"
					ESC"Rời khỏi",get_name(),id,id,id,id,id,id,id,id,id));
			break;
		case 3:
			break;
		case 4:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi hiện tại đang có : "HIB"%d "NOR " điểm Chiến Tích ????? \n"
					ESC HIY"Vâng, tôi đã kiểm tra xong\ntalk %x# gift.9999\n"
					ESC"Rời khỏi",get_name(),who->get_save_2("changping.score"),id,id,id,id,id,id,id,id,id));
			break;	
		case 101:
			if ( who->get_save_2("changping.score") < 5000 )
			{
				send_user(who,"%c%s",':',me->get_name()+"：\n    Không đủ 5000 điểm Chiến Tích !!!\n"ESC"Rời khỏi.");
        		return;
			}
			who->add_save_2("changping.score",-5000);
			"sys/sys/test_db"->add_yuanbao(who,250);
			send_user(who,"%c%s",';',"Bạn nhận được 25 Kim Nguyên Bảo");
			break;
		case 102:
			if ( who->get_save_2("changping.score") < 10000 )
			{
				send_user(who,"%c%s",':',me->get_name()+"：\n    Không đủ 10.000 điểm Chiến Tích !!!\n"ESC"Rời khỏi.");
        		return;
			}
			who->add_save_2("changping.score",-10000);
			"sys/sys/test_db"->add_yuanbao(who,500);
			send_user(who,"%c%s",';',"Bạn nhận được 50 Kim Nguyên Bảo");
			break;
		case 103:
			if ( who->get_save_2("changping.score") < 20000 )
			{
				send_user(who,"%c%s",':',me->get_name()+"：\n    Không đủ 20.000 điểm Chiến Tích !!!\n"ESC"Rời khỏi.");
        		return;
			}
			who->add_save_2("changping.score",-20000);
			"sys/sys/test_db"->add_yuanbao(who,1050);
			send_user(who,"%c%s",';',"Bạn nhận được 105 Kim Nguyên Bảo");
			break;
		case 104:
			if ( who->get_save_2("changping.score") < 50000 )
			{
				send_user(who,"%c%s",':',me->get_name()+"：\n    Không đủ 50.000 điểm Chiến Tích !!!\n"ESC"Rời khỏi.");
        		return;
			}
			who->add_save_2("changping.score",-50000);
			"sys/sys/test_db"->add_yuanbao(who,2600);
			send_user(who,"%c%s",';',"Bạn nhận được 260 Kim Nguyên Bảo");
			break;	
		}
}
