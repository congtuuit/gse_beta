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

// 函数:获取人物造型
void reset();
int get_char_picid() { return 6009; }
void do_gift( string arg );

// 函数:构造处理
void create()
{
        set_name("Hỏa Sư Linh Thú");
		set_real_name(HIR "Hỏa Sư");
    /*    set_2( "good", ([
                "01" : "/item/test/tuihoangkimtanthucap20",
                "02" : "/item/test/tuihoangkimtanthucap30",
                "03" : "/item/test/tuihoangkimtanthucap40",
                "04" : "/item/test/tuihoangkimtanthucap50",
                "05" : "/item/test/tuihoangkimtanthucap60",
                "06" : "/item/test/tuihoangkimtanthucap70",
                "07" : "/item/test/tuihoangkimtanthucap80",
                "08" : "/item/test/tuihoangkimtanthucap90",
                "09" : "/item/test/tuihoangkimtanthucap100",
                "10" : "/item/test/tuihoangkimtanthucap110",
                "11" : "/item/test/tuihoangkimtanthucap120",
                "12" : "/item/test/tuihoangkimtanthucap130",
        ]) );*/
        set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));

        setup();
}

void do_look( object who ) 
{
	int id = getoid( this_object() );
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Nếu Ngươi có Hoa Cầu, Lam Cầu, Hồng Cầu, Hắc Cầu có thể đem đến giao cho ta để đổi lấy phần thưởng \nỞ chỗ ta cũng có thể Đổi phần thưởng sau khi Nạp Thẻ !!!\nNgươi muốn đổi thưởng không?????? \n"
		ESC HIC"Ta muốn nhận linh thú....\ntalk %x# gift.1\n"
		ESC HIG"Ta muốn nâng cấp linh thú....\ntalk %x# gift.2\n"
		ESC"Rời khỏi",get_name(),id,id));	
}

void do_gift( string arg )
{
        object me = this_object();
        __FILE__ ->do_gift2(me, arg);
}

void do_gift2( object me, string arg )
{
	int flag,id,i,p,iTime,iDay,iGio,rate,l,tien,item1,gioitinh;
	object who,item,item2,item3;
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
		gioitinh = who->get_gender() == 1 ? 10 : 11;
        switch(flag)
        {
       	case 1:
			break;
		case 2:
			break;

				/*send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi muốn dùng loại Cầu nào để đổi thưởng ?? Nếu có 4 Loại thì càng tốt !!! \n"
					ESC HIY"[Dùng Hắc Cầu đổi thưởng]\ntalk %x# gift.28\n"
					ESC HIY"[Dùng Lam Cầu đổi thưởng]\ntalk %x# gift.29\n"
					ESC HIY"[Dùng Hồng Cầu đổi thưởng]\ntalk %x# gift.30\n"
					ESC HIY"[Dùng Hoa Cầu đổi thưởng]\ntalk %x# gift.31\n"
					ESC HIY"[Dùng Hắc + Lam + Hồng + Hoa Cầu đổi thưởng]\ntalk %x# gift.32\n"
					ESC"Rời khỏi",get_name(),id,id,id,id,id,id,id,id,id));
			break;*/
		}
}
