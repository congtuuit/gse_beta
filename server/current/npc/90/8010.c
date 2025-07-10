
#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

void do_goto( int flag );
void accept_task(string arg);

int get_char_picid() { return 4143; }
void do_welcome( string arg );

void create()
{
        set_name("Sứ Giả Môn Phái");

        set_2( "talk", ([
                "1"    : (: do_goto, 1 :),
                "2"    : (: do_goto, 2 :),
                "3"    : (: do_goto, 3 :),
                "4"    : (: do_goto, 4 :),
                "5"    : (: do_goto, 5 :),
                "6"    : (: do_goto, 6 :),
                "7"    : (: do_goto, 7 :),
                "task" : (: accept_task :),
                "welcome"        : (: do_welcome :),

        ]));
//        set("level", 10);
//	set("legend", ({33}));
	set("mpLegend",([5:({32*50+10})]));
	set("mpLegend2",([0:({32*49+10,32*49+8})]));
        setup();
}

// 函数：对话处理
void do_look( object who )
{
        int id = getoid( this_object() );
	string result="";
	object item;
//	if (who->get_level()>=10&&(!who->get_legend(TASK_NEWBIE_01, 1)||!who->get_legend(TASK_NEWBIE_01, 2)) )
//		result = ESC"老村长的委托。\n" + sprintf("talk %x# task.1\n", id); 	
//	if ( "sys/sys/count"->get_new_story() )
//		result = ESC"去武功修练场。\n" + sprintf("talk %x# welcome.10\n", id);
	if ( who->get_legend(TASK_NEWBIE_01, 21) && !who->get_legend(TASK_NEWBIE_01, 22) )	
	{
		if (sizeof(result))
			result += ESC "Nỗi khổ của Ngưu Nhị.\n" + sprintf("talk %x# task.3\n", id);
		else
			result = ESC "Nỗi khổ của Ngưu Nhị.\n" + sprintf("talk %x# task.3\n", id);
	}
	if (who->get_level() >= 5 && !who->get_legend(TASK_2_00, 10))
		result += ESC HIY "Cơ Hội Từ Vương Bộ Đầu.\n" + sprintf("talk %x# welcome.1\n", id);
	if (who->get_legend(TASK_49, 9) && !who->get_legend(TASK_49, 10) && objectp(item = present("Vòng tay bị mất", who, 1, MAX_CARRY)) && item->is_souzuo() == 1)
		result += sprintf(ESC HIY "Vòng tay bị mất\ntalk %x# welcome.3\n", id);
	if (who->get_legend(TASK_49, 7) && !who->get_legend(TASK_49, 8))
		result += sprintf(ESC + HIY + "Giao dịch\ntalk %x# welcome.5\n", id);
	if (who->get_fam_name() == "")

                send_user( who, "%c%c%w%s", ':', 3, 4153, sprintf( " %s :\n Vị " + NPC_RANK_D->get_respect(who) + " này nếu muốn đến nơi những cao nhân sống ẩn dật, ta đây không lấy phí.\n"
                        ESC "Đi đến Đào Hoa Nguyên.\n"   + sprintf( "talk %x# 1\n", id ) +
                        ESC "Đi đến Thục Sơn\n"     + sprintf( "talk %x# 2\n", id ) +
                        ESC "Đi đến Đại Chu Doanh trại quân đội.\n" + sprintf( "talk %x# 3\n", id ) +
                        ESC "Đi đến Trang Viện.\n"     + sprintf( "talk %x# 4\n", id ) +
                        ESC "Đi đến Mao Sơn.\n"     + sprintf( "talk %x# 5\n", id ) +
                        ESC "Đi đến Côn Luân Sơn.\n"   + sprintf( "talk %x# 6\n", id ) +
                        ESC "Đi đến ĐầmVân Mộng.\n"   + sprintf( "talk %x# 7\n", id ) +
			result +
                        ESC "Rời khỏi.\nCLOSE\n", get_name() ) );

        else        send_user( who, "%c%c%w%s", ':', 3, 4153, sprintf( " %s :\n Vị " + NPC_RANK_D->get_respect(who) + " này muốn trở về môn phái à?\n"
                        ESC "Quay về môn phái.\n"     + sprintf( "talk %x# 1\n", id ) +
			result +
                        ESC "Rời khỏi.\nCLOSE\n", get_name() ) );
}

// 函数：移动处理
void do_goto( int flag )
{
        object map, me, who, npc;
        int gold, z, x, y, p;

        me = this_object();  who = this_player();

/*      if( present("钱票", who, 1, MAX_CARRY) )
        {
                send_user( who, "%c%s", '!', "您不能携带钱票。" );    // 带着钱票不能使用驿站。
                return;
        }       */
        if( who->get_level()<10 )
        {
                send_user( who, "%c%s", '!', "Đẳng cấp của bạn quá thấp, không thích hợp với những con đường gồ ghề." );
                return;
        }          
        if (present("Vật phẩm quý giá", who, 1, MAX_CARRY))
		{
			send_user(who, "%c%s", '!', "Bạn không thể mang theo vật phẩm quý giá."); // Mang vật phẩm quý giá không thể sử dụng dịch trạm.
			return;
		}
		if (objectp(npc = who->get_quest("escort.robber#")) && npc->is_escort_robber()) // Tìm kiếm người bịt mặt
		{
			send_user(who, "%c%s", '!', "Người bịt mặt xuất hiện, hành động của bạn bị ảnh hưởng.");
			return;
		}
        gold = 0;

        switch (who->get_fam_name())
		{
			default:
				gold = 0;
				break;
			case "Đào Hoa Nguyên":
				flag = 1;
				break;
			case "Thục Sơn":
				flag = 2;
				break;
			case "Cấm Vệ Quân":
				flag = 3;
				break;
			case "Đường Môn":
				flag = 4;
				break;
			case "Mao Sơn":
				flag = 5;
				break;
			case "Côn Luân":
				flag = 6;
				break;
			case "Vân Mộng Cốc":
				flag = 7;
				break;
		}

        if( who->get_cash() < gold )
        {
                send_user(who, "%c%s", '!', "Tiền mặt trên tay bạn không đủ.");
                return;
        }

        switch( flag )
        {
      default :
       case 1 : z = 289;  p = get_jumpin(z, 20);  break;
       case 2 : z = 273;  p = get_jumpin(z, 20);  break;
       case 3 : z = 080;  p = get_jumpin(z, 20);  break;
       case 4 : z = 324;  p = get_jumpin(z, 20);  break;
       case 5 : z = 269;  p = get_jumpin(z, 20);  break;
       case 6 : z = 054;  p = get_jumpin(z, 20);  break;
       case 7 : z = 165;  p = get_jumpin(z, 20);  break;
        }

        if (p)
		{
			// who->add_cash( -gold );  who->add_gold_log("pay", gold);
			who->add_to_scene(z, p / 1000, p % 1000, get_d(who), 40971, 0, 40971, 0);

			if (map = get_map_object(z) && gold > 0)
			{
				write_user(who, ECHO "Bạn đã tiêu tốn %d vàng để đến %s。\n", gold, map->get_name());
			}
		}
}

void accept_task(string arg)
{
	int i;
	object who=this_player(),item;
	if ( who->get_level()<5 )
		return ;

	i = to_int(arg);
	if (i == 1)
	{
		if (!who->get_legend(TASK_NEWBIE_01, 1))
			send_user(who, "%c%c%w%s", ':', 3, 4153, sprintf("%s\n    Nghe nói từ trưởng làng già, gần đây trong làng không được yên bình, có thể cần sự giúp đỡ của những người giang hồ như các bạn. Bạn hãy đến gặp ông ấy xem sao, nếu ông ấy giao phó cho bạn làm việc gì đó, bạn chắc chắn sẽ nhận được phần thưởng hậu hĩnh! \n    Trưởng làng già cũng không xa chỗ tôi, ở phía tây nam của tôi, tận cùng phía nam của làng.\n" ESC "Nhận nhiệm vụ\ntalk %x# task.2\n" ESC "Rời khỏi.", get_name(), getoid(this_object())));
		else if (!who->get_legend(TASK_NEWBIE_01, 2))
			send_user(who, "%c%c%w%s", ':', 3, 4153, sprintf("%s\n    Người trẻ tuổi, làm việc phải tích cực lên, chậm chạp như vậy, chẳng có chút sức sống nào cả! Trưởng làng già đang cần gấp, bạn mau đến đó đi!\n" ESC "Rời khỏi.", get_name()));
	}
	else if ( i == 2 && !who->get_legend(TASK_NEWBIE_01, 1))
	{
		who->set_legend(TASK_NEWBIE_01, 1);
		send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Tân Thủ Thôn");
		send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 12, "Sự ủy thác của trưởng làng già");
		send_user(who, "%c%s", '!', "Bạn đã nhận" HIY "Sự ủy thác của trưởng làng già" NOR "nhiệm vụ");
	}
	else if (i == 3 && who->get_legend(TASK_NEWBIE_01, 21) && !who->get_legend(TASK_NEWBIE_01, 22))
	{
		send_user(who, "%c%c%w%s", ':', 3, 4153, sprintf("%s:\n    Không phải tôi không muốn giúp anh ta! Nhưng việc không nhận người trưởng thành là truyền thống lâu đời của các môn phái lớn. Bạn bảo tôi giới thiệu kiểu gì đây? Nể tình sách cờ, tôi sẽ thử một lần xem sao! Thành hay không thì tùy vào số phận của anh ta.\n" ESC "Hoàn thành nhiệm vụ\ntalk %x# task.4\n" ESC "Rời khỏi.", get_name(), getoid(this_object())));
	}
	else if ( i ==  4 && who->get_legend(TASK_NEWBIE_01, 21) && !who->get_legend(TASK_NEWBIE_01, 22))
	{
		if (!objectp(item = present("Sách cờ", who, 1, MAX_CARRY)) || item->is_qipu() != 1)
		{
			send_user(who, "%c%s", '!', "Sách cờ của bạn đâu rồi?");
			return;
		}
		item->remove_from_user();
		destruct(item);
		who->set_legend(TASK_NEWBIE_01, 22);
		who->add_exp(100);
		who->add_potential(50);
		send_user(who, "%c%s", ';', "Nỗi khổ của Ngưu Nhị Kinh nghiệm 100 Tiềm năng 50");
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,11,"" );			
	}
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,p;
        object who,item,obj;  
        string cmd1;
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
		if ( who->get_level() >= 5 && !who->get_legend(TASK_2_00,10) ) 
			send_user(who, "%c%c%w%s", ':', 3, 4153, sprintf("%s:\n    Đội trưởng bộ khoái Vương Quốc không phải là người tầm thường, dù là đạo tặc vặt vãnh hay giang hồ đại đạo, cũng đừng hòng thoát khỏi tay ông ấy.\n    Tuy nhiên, gần đây chỗ đội trưởng Vương thiếu người làm việc, công việc thì chất đống, nghe nói là do phạm nhân bỏ trốn. Vương Quốc đã treo thưởng để bắt những kẻ này. Nghĩ mà xem, lệnh do Vương Quốc ban ra, phần thưởng chắc chắn không nhỏ đâu. Khi đến đó, nhớ phải khôn khéo một chút, đưa cho đội trưởng Vương chút quà ra mắt, đạo lý này chắc không cần ta nói thêm nhỉ. Đội trưởng Vương ở ngay cạnh trạm dịch trong thành Vương Quốc, cũng khá gần, bạn chịu khó tìm một chút nhé! \n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.2\n"ESC"Rời khỏi.", me->get_name(),getoid(me))); 	
		break;
        case 2:
		if ( who->get_level() >= 5 && !who->get_legend(TASK_2_00,10) ) 
        	{
//        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
//        			return ;
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
//        		TASK_LEGEND_D->give_item(who,"item/98/0177",1);	
//        		who->set_legend(TASK_49,11);
			who->set_legend(TASK_2_00, 10);
			send_user(who, "%c%c%c%w%s", 0x51, 2, 1, TID_NEWBIE_01, "Tân Thủ Thôn");
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_NEWBIE_01, 119, "Nhiệm vụ tuyệt vời của Vương Bộ Đầu");
			send_user(who, "%c%s", '!', "Nhận nhiệm vụ  " HIY "Nhiệm vụ tuyệt vời của Vương Bộ Đầu");
        	}
        	break;
        	
        case 3:
		if ( who->get_legend(TASK_49, 9) && !who->get_legend(TASK_49, 10) && objectp( item = present("Vòng tay bị mất", who, 1, MAX_CARRY) ) && item->is_souzuo() == 1 )
			send_user(who, "%c%c%w%s", ':', 3, 4153, sprintf("%s:\n    Đưa vòng tay cho tôi trước, tôi sẽ khử trùng cẩn thận, sau đó tôi sẽ tự mình giao cho chủ khách sạn。\n"ESC"Hoàn thành nhiệm vụ\ntalk %x# welcome.4\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
		break;
        case 4:
		if ( who->get_legend(TASK_49, 9) && !who->get_legend(TASK_49, 10) && objectp( item = present("Vòng tay bị mất", who, 1, MAX_CARRY) ) && item->is_souzuo() == 1 )
		{
			if( objectp( item = present("Vòng tay bị mất", who, 1, MAX_CARRY) ) && item->is_souzuo() == 1 )
			{
				item->remove_from_user();
				destruct(item);
				item = new("item/87/9999");
				p = item->move(who,-1);
				item->add_to_user(p);
				who->add_potential(20);
				who->add_exp(250);
				who->delete_save_2("dssouzuo");
				who->delete_save_2("dssouzuo1");
				TASK_LEGEND_D->task_finish(who);
				who->set_legend(TASK_49,10);
				send_user(who,"%c%s",';',"Vòng tay bị mất 经验 300 tiềm năng 20 初学者腰带 1 ");
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,117,"" );
				me->do_welcome(1);
			}
		}
		break;
	case 5:
		if ( who->get_legend(TASK_49, 7) && !who->get_legend(TASK_49, 8))
			send_user(who,"%c%s",':',sprintf("%s\n    “Không ngờ ông chủ tiệm cầm đồ lại quan tâm đến việc của tôi như vậy, cảm ơn bạn đã tìm được những Hỏa Thạch này cho tôi giải trí. Đây là phần thưởng dành cho bạn！”\n"ESC"Hoàn thành nhiệm vụ\ntalk %x# welcome.6\n"ESC"Rời khỏi.",me->get_name(),getoid(me))); 		
		break;
	case 6:
		 if ( who->get_legend(TASK_49, 7) && !who->get_legend(TASK_49, 8))
       		 {
        		if (TASK_LEGEND_D->check_task_item(who, "Hỏa Thạch", 5) != 1)
        			return;
        		who->delete_save("huoyanshi");
			item = new( "/item/91/9100" );   //行军散
			item->set_amount(10);
	                p =item->move(who, -1);
	                item->add_to_user(p);
			who->add_potential(30);
			who->add_exp(280);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_49,8);
			who->set_legend(TASK_49,9);	//取消丢失的手镯任务
			who->set_legend(TASK_49,10);
			send_user(who,"%c%s",';',"Giao dịch 经验 280 tiềm năng 30 行军散 10 ");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,116,"" );
			me->do_welcome(1);
		}
		break;
/*	case 10:
		if ( "sys/sys/count"->get_new_story() == 0 )
			return ;
		p = get_jumpin(887, 1);
		who->add_to_scene(887,p / 1000,p % 1000);
		break;*/
	}
}