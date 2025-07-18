
// 自动生成：/make/npc/make0001

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// 函数：当铺老板
int is_banker() { return 1; }
void do_welcome(string arg);

// 函数：获取人物造型
int get_char_picid() { return 5301; }

// 函数：构造处理
void create()
{
        set_name("Quản Khố");
        set_real_name("Quản Khố");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
//        set("level",0);
//        set("legend",({32*40+17}));
//	set("mpLegend",([0:({32*2+1,32*40+17}),5:({32*40+24})]));
	set("mpLegend",([0:({32*40+17})]));
	set("mpLegend2",([0:({32*48+30,32*49+5,32*40+19}),]));
        setup();
}

// 函数：对话处理
void do_look( object who )
{
	int i, size, exist;
	string tmp="", *line, *data;
	
	
	if ( !who->get_legend(TASK_40,19) )
		tmp +=  sprintf(ESC +HIY+  "Tự Rèn Luyện\ntalk %x# welcome.4\n",getoid(this_object()));
	if ( who->get_legend(TASK_48, 29) && !who->get_legend(TASK_48, 30))
		tmp +=  sprintf(ESC +HIY+  "Trang Trí Phòng Ốc\ntalk %x# welcome.10\n",getoid(this_object()));
//	if ( !who->get_legend(TASK_NEWBIE_02,3) )
	if ( who->get_legend(TASK_49, 5) && !who->get_legend(TASK_49, 6))
		tmp +=  sprintf(ESC  +HIY+ "Giao Dịch Của Chủ Tiệm Cầm Đồ\ntalk %x# welcome.1\n",getoid(this_object()));
       	if ( who->get_legend(TASK_48, 30) && !who->get_legend(TASK_49, 1))
//	if ( (who->get_level() >= 5 &&!who->get_legend(TASK_40,24)) || (who->get_legend(TASK_40,28) && !who->get_legend(TASK_40,29)) )
		tmp +=  sprintf(ESC  +HIY+ "Chứng Bệnh Đau Đầu\ntalk %x# welcome.7\n",getoid(this_object()));
       	if ( who->get_legend(TASK_49, 4) && !who->get_legend(TASK_49, 5))
		tmp +=  sprintf(ESC  +HIY+ "Chứng Bệnh Đau Đầu(3)\ntalk %x# welcome.7\n",getoid(this_object()));
	tmp += sprintf(ESC "Nhận lãnh Chiến Quốc Bảo Điển\ntalk %x# welcome.12\n",getoid(this_object()));

		send_user( who, "%c%c%w%s", ':', 3, get_char_picid(), 
                sprintf(" %s :\n "+"/quest/word"->get_normal_word(this_object())+"\n"     
						ESC "Ta muốn sử dụng kho\npawn %x# 1\n"
						//ESC "Ta muốn sử dụng kho\ntalk %x# welcome.99\n"

			ESC "Ta muốn mở rộng kho của ta\npawn expand %x# 0\n"
			//ESC HIG"Đặt mật khẩu bảo vệ Kho\ntalk %x# welcome.100\n"
			//ESC HIG"Đổi mật khẩu bảo vệ Kho\ntalk %x# welcome.101\n"
			//ESC HIG"Xoá mật khẩu bảo vệ Kho\ntalk %x# welcome.102\n"
                        + tmp +
            ESC "Ta chỉ xem qua\nCLOSE\n",get_name(), getoid(this_object()), getoid(this_object()), getoid(this_object()), getoid(this_object()), getoid(this_object()) ) );
	"/quest/help"->send_help_tips(who, 4);                        
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i,size,p,amount;
	object who,*inv,item;

	string input;

	who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {	
		case 1:
//			if (!who->get_legend(TASK_NEWBIE_02,1) )
			if ( who->get_legend(TASK_49, 5) && !who->get_legend(TASK_49, 6))
				send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
					sprintf("%s:\n    嘿，看来你需要一些行军散，这可是对你的气血非常有用的。对吗？\n    我很愿意给你一些行军散，但是，我有一个条件，门派向导一直想找点Hỏa Thạch玩玩，我想讨好他，所以你帮他弄一些Hỏa Thạch来，你看怎么样？\n    你去洞庭湖杀掉那些讨厌的持扇草人、赤褐蚁或子母蛙，就可能会有Hỏa Thạch了，拿到后交给门派向导，他只需要5个，去吧！\n    做完任务后，用alt+w打开人物属性界面，再使用新手信物就可以快速回到新手村哦！\n"ESC"接受\ntalk %x# welcome.2\n"ESC"Rời khỏi.",me->get_name(),getoid(me)));
			else if (!who->get_legend(TASK_NEWBIE_02,2) )
				send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
					sprintf("%s:\n   %s ，我交给你的任务呢？Hoàn thành了吗？我还等着你呢！村外就有很多野兔，你杀死它们就可以拿到Hỏa Thạch了！”\n"ESC"Rời khỏi.",me->get_name(),NPC_RANK_D->get_respect_2(who)));
			else if (!who->get_legend(TASK_NEWBIE_02,3) )
				send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
					sprintf("%s:\n    没想到你这么快就回来了，%s。青出于蓝而胜于蓝啊！我这把老骨头了，一个人也挺寂寞的，谢谢你找来这些Hỏa Thạch供我把玩。这是给你的奖励！\n"ESC"Hoàn thành任务\ntalk %x# welcome.3\n"ESC"Rời khỏi.",me->get_name(),NPC_RANK_D->get_respect_2(who),getoid(me)));
			break;
		case 2:
//			if ( who->get_legend(TASK_NEWBIE_02,1) )
//				return ;
			if ( who->get_legend(TASK_49, 5) && !who->get_legend(TASK_49, 6))
			{
				if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
				who->set_legend(TASK_49,6);
				who->delete_save_2("huoyanshi");
				send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"Tân Thủ Thôn" );
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,116,"Giao dịch" );
				send_user( who, "%c%s", '!', "你接受了"HIY"Giao dịch"NOR "任务");
			}
			break;
		case 3:
			if ( !who->get_legend(TASK_NEWBIE_02,1) || !who->get_legend(TASK_NEWBIE_02,2) || who->get_legend(TASK_NEWBIE_02,3) )
				return ;	
			if( !objectp( item = present("Hỏa Thạch", who, 1, MAX_CARRY) ) || item->is_huoyanshi() != 1 )
			{
				send_user(who,"%c%s",'!',"你的Hỏa Thạch呢?");
				return;	
			}
			inv = all_inventory(who, 1, MAX_CARRY);
               		inv -= ({ 0});
               		for( i = 0, size = sizeof(inv); i < size; i ++ )
               		{
                		if ( !objectp(inv[i]) )
                			continue;
                		if ( inv[i]->get_name() != "Hỏa Thạch" || inv[i]->is_huoyanshi() != 1 )
                			continue;
                		amount += inv[i]->get_amount();               			
               		}
               		if ( amount < 5 )
               		{
               			send_user(who,"%c%s",'!',"数量不够吧?");
				return;
               		}
                	for( i = 0, size = sizeof(inv); i < size; i ++ )
                	{
                		if ( !objectp(inv[i]) )
                			continue;
                		if ( inv[i]->get_name() != "Hỏa Thạch" || inv[i]->is_huoyanshi() != 1 )
                			continue;
                		inv[i]->remove_from_user();
                		destruct(inv[i]);
                	}
                	item = new("/item/91/9100");
                	if ( !item )
                		return ;
                	item->set_amount(10);
                	p = item->move(who,-1);
                	if ( !p )
                	{
                		send_user(who,"%c%s",'!',"你身上的东西太多了");
                		return;
                	}
                	item->add_to_user(p);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_NEWBIE_02,3);
			who->delete_save_2("huoyanshi");
			who->add_exp(100);
			send_user(who,"%c%s",';',"Giao dịch 经验 100 行军散 10");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,14,"" );
			break;
        case 4:
        	if ( !who->get_legend(TASK_40,17) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    看上去你很少参加战斗，%s，我猜想你肯定还没有去过村外，也没有见过那些恼人的小山鸡、小野兔、稻草人，我觉得，你应该出村锻炼下自己，不止能让你自身的能力得到提高，还能让人见到一些你从未见过的东西，开阔你的视野。\n    我看不如这样吧，你去村外消灭3只小怪物（小山鸡、小野兔、稻草人），回来向我交差，我会给奖励给你的！\n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.5\n"ESC"Rời khỏi.", me->get_name(), who->get_name(),getoid(me)));
		else if ( !who->get_legend(TASK_40,18) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    你应该出村锻炼下自己。\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	else if ( !who->get_legend(TASK_40,19) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    真不错！没想到你能这么快就回来。拿好你的奖励，孩子。\n"ESC"Hoàn thành任务\ntalk %x# welcome.6\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	
        	break;
	case 5:
        	if ( !who->get_legend(TASK_40,17) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_40,17);
        		who->delete_save("dplbxiaogw");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"Tân Thủ Thôn" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,32,"Rèn luyện bản thân" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ  "HIY"Rèn luyện bản thân");
        	}
        	break;
        case 6:
        	if ( who->get_legend(TASK_40,18) && !who->get_legend(TASK_40,19) )
        	{
        		TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_40,19);
        		who->delete_save("dplbxiaoyt");
        		who->delete_save("dplbdaocr");
			who->add_exp(280);
			who->add_potential(15);
			who->add_cash(500);
			send_user(who,"%c%s",';',"Rèn luyện bản thân 经验 280 tiềm năng 15 Ngân lượng 500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,32,"" );
        	}
        	break;   
        case 7:
//        	if ( who->get_level() >= 5 &&!who->get_legend(TASK_40,24) )
	       	if ( who->get_legend(TASK_48, 30) && !who->get_legend(TASK_49, 1))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    为了这个当铺，我是日夜操劳，白天忙着为客人服务，晚上又得清算盘点，久而久之，便有了Đau đầu，每当遇到烦恼的事情时，脑袋里就撕裂般的疼痛，有时候实在是疼得受不了，我便拿自己的头往墙壁上撞。\n    我听说灵芝草对头疼有很强的疗效，我想请你去找野味收购商讨点灵芝草来，他收购野味应该也会收购一些药材，如果他有其他条件，你尽管答应好了，我会想办法让你做到的。\n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.8\n"ESC"Rời khỏi.", me->get_name(), getoid(me)));
//        	else if ( who->get_legend(TASK_40,28) && !who->get_legend(TASK_40,29) )
	       	else if ( who->get_legend(TASK_49, 4) && !who->get_legend(TASK_49, 5))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    果然不负我所望，将灵芝草给我讨了来，我这Đau đầu就全靠你这颗灵芝草了，我要好好答谢你！\n"ESC"Hoàn thành任务\ntalk %x# welcome.9\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
       	
        	break;
	case 8:
//        	if ( who->get_level() >= 5 &&!who->get_legend(TASK_40,24) )
	       	if ( who->get_legend(TASK_48, 30) && !who->get_legend(TASK_49, 1))
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_49,1);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"Tân Thủ Thôn" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,113,"Đau đầu（1）" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ  "HIY"Đau đầu（1）");
        	}
        	break;
	case 9:
//		if( who->get_legend(TASK_40,28) && !who->get_legend(TASK_40,29) )
		if ( who->get_legend(TASK_49, 4) && !who->get_legend(TASK_49, 5))
		{
			if (TASK_LEGEND_D->check_task_item(who,"灵芝草",1) != 1 )
        			return;
			if(who->get_gender()==1) item = new("item/65/0001");
				else item = new("item/66/0001");
			p =item->move(who, -1);
			item->add_to_user(p);
			who->add_exp(280);
			who->add_potential(40);
			who->add_cash(1000);
			who->set_legend(TASK_49, 5);
			send_user(who,"%c%s",';',"Đau đầu（3） 经验 280 tiềm năng 40 Ngân lượng 1000 新手帽子 1");			
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,115,"" );
			me->do_welcome(1);
		}
		break;	
        case 10:
		if ( who->get_legend(TASK_48, 29) && !who->get_legend(TASK_48, 30))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    不错，就是这种Hoa huệ，是我最喜欢的！\n"ESC"Hoàn thành任务\ntalk %x# welcome.11\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	break;
        case 11:
        	if ( who->get_legend(TASK_48, 29) && !who->get_legend(TASK_48, 30))
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"Hoa huệ",3) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_48,30);
        		who->delete_save("wdzbaihh");
			who->add_exp(550);
			who->add_potential(30);
			who->add_cash(1000);
			send_user(who,"%c%s",';',"Trang trí nhà cửa 经验 550 tiềm năng 30 Ngân lượng 1000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,112,"" );
			me->do_welcome(7);
        	}
        	break; 
        case 12:
		if(objectp(item = "/quest/zg_dict"->want_an_zgdict(me,who))) {
			p = item->move(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%s",'!',"Ngươi đạt được Chiến Quốc Bảo Điển");
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
