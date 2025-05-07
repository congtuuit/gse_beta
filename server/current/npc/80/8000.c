
// 自动生成：/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <equip.h>

inherit OFFICER;

void do_task_start(string arg);
void accept_task();
void join_task();
void do_welcome( string arg );
void do_task_list();

// 函数：获取人物造型
int get_char_picid() { return 6800; }

// 函数：构造处理
void create()
{
        set_name("Vận Tiêu Lão Đầu");
        set_city_name("－－");

        set_2( "talk", ([
                "task"          : (: do_task_start :),
                "accept"        : (: accept_task :),
                "join"		: (: join_task :),
                "welcome"          : (: do_welcome :),
                "tasklist"          : (: do_task_list :),
        ]));      
	set("mpLegend",([30:({32}),]));
        setup();
}

// 函数：对话处理
   void do_look( object who ) { TASK_ESCORT_D->do_look( who, this_object() ); }

// 函数：开始任务
   void do_task_start(string arg) { TASK_ESCORT_D->do_task_start( this_player(), this_object(),arg ); }
// 函数：接受任务
   void accept_task() { TASK_ESCORT_D->accept_task( this_player(), this_object() ); }
// 函数：加入任务
   void join_task() { TASK_ESCORT_D->join_task( this_player(), this_object() ); }

   void do_task_list() { TASK_ESCORT_D->do_task_list( this_player(), this_object() ); }
   
void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag, date , status, p, z, x, y, i;
        object who, obj, item;     
        string cmd1, cmd2, cmd3, cmd4, cmd5, result;
        who = this_player();
	if (arg=="cancel")
	{
	        item = who->get_equip(HAND_TYPE);
		if (item && item->get_item_number()==10001078)
		{	
			send_user( who, "%c%c%s", 0x59, 1, sprintf("Bạn có sử dụng để loại bỏ khoảng thời gian nhiệm vụ của bạn？\n"
	                	ESC "%c\n"ESC"use %x# escort2\n"
	                        , 1, getoid(item) ) );			
			return;
		}		
	}        
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 1:
		if ( !who->get_legend(TASK_NEWBIE_00, 13) || who->get_legend(TASK_NEWBIE_00, 14) )
			return;
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    Gần đây ông fairy giới thiệu rất nhiều người đến với tôi, một số người có thể thực sự ...... Oh, không nói, bạn có thể không gọi cho tôi xuống! Giới trẻ có động lực để làm việc này, bạn biết đấy, giống như bản gốc, khi tôi còn trẻ ......\n"ESC"Nhiệm vụ hoàn thành\ntalk %x# welcome.2\n"ESC"Rời khỏi.",me->get_name(),getoid(me)));
		break;
	case 2:
		if ( !who->get_legend(TASK_NEWBIE_00, 13) || who->get_legend(TASK_NEWBIE_00, 14) )
			return;
		TASK_LEGEND_D->task_finish(who);
		who->set_legend(TASK_NEWBIE_00, 14);
		who->add_exp(250);
		who->add_potential(30);
		send_user(who,"%c%s",';',"Watson nói về tìm cậu chủ cũ kinh nghiệm 250 Tiềm năng 30");
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,2,"" );		
		me->do_welcome(3);
		break;		
	case 3:
		if ( who->get_level()>=30 && !who->get_legend(TASK_49,13) && !who->get_quest("escort.flag"))
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    Đây là nơi tôi có thể cung cấp cho bạn một cơ hội để kiếm tiền, bạn có thể những ngày này, có một số bất tài mà không đức Villains, cho tôi tên của các biểu ngữ của sự giúp đỡ từ rất nhiều Biaoyin tôi lừa, vì vậy sau khi những người muốn trong vận chuyển phi tiêu của tôi về mọi người, tôi đã phải lần đầu tiên vượt qua bài kiểm tra tắt này。\n    đầu tiên cho tôi tại Biaoyin này, bạn chuyển đến Mada Han Han lê bên ngoài làng, lần này tôi không chấp nhận đặt cọc của bạn, nhưng bạn hãy nhớ rằng, trong quá trình vận chuyển phi tiêu không thể sử dụng đạo cụ ma thuật như đường bưu điện hoặc chức năng truyền, nếu không nhiệm vụ của bạn sẽ thất bại！\n"ESC"Chấp nhận\ntalk %x# welcome.4\n"ESC"Rời khỏi.",me->get_name(),getoid(me)));
		break;		
	case 4:
		if ( who->get_level()>=30 && !who->get_legend(TASK_49,13) && !who->get_quest("escort.flag"))
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			if( sizeof_inventory(who, 1, MAX_CARRY) >= MAX_CARRY )
	                {
	                        send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),me->get_name()+":\n    Bạn đã có rất nhiều điều, người ta ước tính không có nơi nào an toàn để đưa xuống các vật có giá trị, suy nghĩ, hoặc không cung cấp cho bạn. Vì vậy, bạn có thể đặt xuống bài viết này, bạn sau đó đến với tôi。");
	                        return;
	                }
			
	                item = new( "/item/98/0237" );
	                if( p = item->move(who, -1) ) item->add_to_user(p);
			who->set_legend(TASK_49,13);
		        who->set_quest("escort.time", time() );
			send_user( who, "%c%s", '!', "Bạn chấp nhận"HIY"Khám phá tình hình thực tế"NOR"任务");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"Tần Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,15,"Khám phá tình hình thực tế" );
		}
		break;		
	case 5:
		if ( who->get_legend(TASK_2_00,14) && !who->get_legend(TASK_2_00,15) ) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    Xu cố vấn giới thiệu gần đây có rất nhiều người đến với tôi, một số người có thể thực sự ...... Oh, không nói, bạn có thể không gọi cho tôi xuống! Giới trẻ có động lực để làm việc này, bạn biết đấy, giống như bản gốc, khi tôi còn trẻ ......\n"ESC"Nhiệm vụ hoàn thành\ntalk %x# welcome.6\n"ESC"đi chỗ khác",me->get_name(),getoid(me)));
		break;
	case 6:
		if ( who->get_legend(TASK_2_00,14) && !who->get_legend(TASK_2_00,15) ) 
		{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_2_00,15);
			who->add_exp(300);
			who->add_potential(35);
			who->add_cash(500);
			send_user(who,"%c%s",';',sprintf("Thăm Yuchi kinh nghiệm cậu chủ cũ tiềm năng của 35 300 500 Money"));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,17,"" );
			me->do_welcome(7);
		}
		break;		
	case 7:
		if ( who->get_legend(TASK_2_00,15) && !who->get_legend(TASK_2_00,16) ) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    Gần đây tôi đã nghe xuất hiện trong di tích cổ xưa gọi là con dấu con quỷ bên gương, con quỷ gương kín bên trong từ hàng trăm năm nay bởi cuộc chiến tranh được sản xuất. kho báu này hiện rơi vào tay của một người đàn ông tên Hengyu, ông được tuyển vào những con quái vật bên con dấu anh hùng để tiêu diệt các gương quỷ, bạn đang quan tâm đến quá khứ để tìm thấy anh ta nói về nó. Từ cửa trước của tôi để đi ra ngoài, đi về phía đông xuống đường, bạn có thể nhìn thấy Hengyu, anh đứng dưới gốc cây lớn。\n"ESC"Chấp nhận\ntalk %x# welcome.8\n"ESC"đi chỗ khác",me->get_name(),getoid(me)));
		break;		
	case 8:
		if ( who->get_legend(TASK_2_00,15) && !who->get_legend(TASK_2_00,16) ) 
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_2_00,16);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"Tần Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,18,"Thăm Hengyu" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ "HIY"Thăm Hengyu");
		}
		break;	

	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		TASK_ESCORT_D->biaowang(me,who,flag);
		break;

	}
}
