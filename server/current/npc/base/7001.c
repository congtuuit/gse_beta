
// 自动生成:/make/npc/make0001

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// 函数:Quản Khố
int is_banker() { return 1; }

// 函数:获取人物造型
int get_char_picid() { return 5301; }
void do_welcome( string arg );

// 函数:构造处理
void create()
{
        set_name("Quản Khố");
        set_real_name("Quản Khố");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
//	set("level",49);
//	set("legend",({32*13+7})); 
	set("mpLegend",([50:({32*13+7}),]));
	set("mpLegend2",([50:({32*13+9}),]));
        setup();
}

// 函数:对话处理
void do_look( object who )
{
	int i, size, exist;
	string tmp="", *line, *data;

	if ( ( who->get_level() >= 50 && !who->get_legend(TASK_13,7) ) || ( who->get_legend(TASK_13,7) && !who->get_legend(TASK_13,9) ) )
		tmp =  sprintf(ESC HIY "Lời tiên tri khủng khiếp\ntalk %x# welcome.1\n",getoid(this_object()));
	
		send_user( who, "%c%c%w%s", ':', 1, get_char_picid(), 
                sprintf("   %s :\n    "+"/quest/word"->get_normal_word(this_object())+"\n"
                        //ESC "Ta muốn sử dụng kho\npawn %x# 1\n"
                		ESC "Ta muốn sử dụng kho\ntalk %x# welcome.99\n"
                        ESC "Ta muốn mở rộng kho\npawn expand %x# 0\n"
						//ESC HIG"Đặt mật khẩu bảo vệ Kho\ntalk %x# welcome.100\n"
						//ESC HIG"Đổi mật khẩu bảo vệ Kho\ntalk %x# welcome.101\n"
						//ESC HIG"Xoá mật khẩu bảo vệ Kho\ntalk %x# welcome.102\n"
                        + tmp +
                        ESC "Ta chỉ xem qua\nCLOSE\n", get_name(), getoid(this_object()), getoid(this_object()), getoid(this_object()), getoid(this_object()), getoid(this_object()) ) );
	"/quest/help"->send_help_tips(who, 4);                        
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
		string input;

        int flag,p;
        object who,item,obj;  
        string cmd1;
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_level() >= 50 && !who->get_legend(TASK_13,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    听风水先生预言，不久后在郑国渠一带将有妖孽横空出世，这妖孽不知道会做出什么危害人间的事情，所以应该防范于未然，阻止他的出世，如果我没猜错的话，应该是逆世鬼在作祟，你是否愿意前去将此事调查清楚？\n"ESC"接受任务\ntalk %x# welcome.2\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_13,7) && !who->get_legend(TASK_13,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    这段时间我是不会从郑国渠那里经过，以防万一。\n"ESC"Rời khỏi.", me->get_name()));
		else if ( who->get_legend(TASK_13,8) && !who->get_legend(TASK_13,9) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    这下再也不用担心那预言是真是假，可以安静的过日子了。\n"ESC"Hoàn thành任务\ntalk %x# welcome.3\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        		
        	break;
	case 2:
        	if( who->get_level() >=50 && !who->get_legend(TASK_13,7) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_13,7);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"Yên Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,13,"Lời tiên tri khủng khiếp" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ  "HIY"Lời tiên tri khủng khiếp");
        	}
        	break;       
        case 3:
        	if ( who->get_legend(TASK_13,8) && !who->get_legend(TASK_13,9) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/64074",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_13,9);
			who->add_exp(5600);
			who->add_potential(220);
			who->add_cash(4800);
			send_user(who,"%c%s",';',"Lời tiên tri khủng khiếp 经验 5600 tiềm năng 220 Ngân lượng 4800 踏云甲图纸 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,13,"" );
        	}
        	break; 
        	case 99:
			if ( who->get_save("passquankho") )
			{
				input = who->get_save("statusQuanKho");
				
				if(input == "block"){
					send_user( who, "%c%c%d%s", '?', 16, 8, "Quản Khố :\nVui lòng nhập mật khẩu mở khóa\n(Tối đa 8 ký tự) \n" ESC "unblockandopen %s\n" );
				}
				else {
					"cmd/base/unblockandopen"->do_open(who,1);
				}

				return ;
			}
			"cmd/base/unblockandopen"->do_open(who,1);
        	break;

		case 100:
			if ( who->get_save("passquankho") )
			{
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Quản Khố:\nBạn đã có thiết lập Mật khẩu bảo vệ Kho rồi, hãy nhập đúng Mật khẩu bảo vệ Kho và chọn Đổi Mật khẩu !\n"ESC"Xác nhận");
				return;
			}
			send_user( who, "%c%c%d%s", '?', 16, 8, "Quản Khố :\nXin nhập Mật khẩu bảo vệ     Kho : \n(giới hạn 8 ký tự) \n" ESC "quankho %s\n" );
			break;
		case 101:
			if ( !who->get_save("passquankho") )
			{
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Quản Khố:\nBạn chưa đặt Mật khẩu bảo vệ Kho, không thể sử dụng chức năng này!\n"ESC"Xác nhận");
			}

			input = who->get_save("statusQuanKho");
			if(input == "block"){
				send_user( who, "%c%c%d%s", '?', 16, 8, "Quản Khố :\nVui lòng nhập mật khẩu mở khóa\n(Tối đa 8 ký tự) \n" ESC "mokhoaquankho %s\n" );
			}
			else {
				send_user( who, "%c%c%d%s", '?', 16, 8, "Quản Khố :\nXin nhập Mật khẩu bảo vệ Kho mới : \n(giới hạn 8 ký tự) \n" ESC "quankho %s\n" );
			}

			return ;
			break;
		case 102:
			if ( !who->get_save("passquankho") )
			{
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Quản Khố:\nBạn chưa đặt Mật khẩu bảo vệ Kho, không thể sử dụng chức năng này!\n"ESC"Xác nhận");

				return;
			}

			input = who->get_save("statusQuanKho");
				
			if(input == "block"){
				send_user( who, "%c%c%d%s", '?', 16, 8, "Quản Khố :\nVui lòng nhập mật khẩu mở khóa\n(Tối đa 8 ký tự) \n" ESC "mokhoaquankho %s\n" );
			}
			else {
				
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Quản Khố:\nBạn chắc chắn phải xoá Mật khẩu bảo vệ Kho không ?\n"
				ESC"Xác nhận\ntalk %x# welcome.103\n"
				ESC"Huỷ bỏ\nCLOSE\n",getoid(me)));	
			}

			return ;

			break;
		case 103:
			if ( !who->get_save("passquankho") )
			{
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Quản Khố:\nBạn chưa đặt Mật khẩu bảo vệ Kho, không thể sử dụng chức năng này!\n"ESC"Xác nhận");
				return;
			}

			input = who->get_save("statusQuanKho");

			if(input == "block")
			{
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Quản Khố:\nBạn phải nhập Mật khẩu bảo vệ Kho vào mới có thể Xoá Mật khẩu bảo vệ Kho !\n"ESC"Xác nhận");
				return;
			}			

			who->delete_save("passquankho");
			who->set_save("statusQuanKho","unblock");
			send_user(who, "%c%s",';', "Bạn đã xoá Mật khẩu bảo vệ Kho thành công !");
			break;	
	}
	return ;

}
