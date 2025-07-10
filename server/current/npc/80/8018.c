
// 自动生成：/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

void do_task_start();
void do_task_cancel();

//void do_task_finish();
int get_char_picid() { return 5701; }
void do_welcome(string arg);

// 函数：构造处理
void create()
{
        set_name("Cước Phu");
        set_city_name("Triệu Quốc");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ]));
//	set("level",56);
//	set("legend",({32*14+24,32*14+27,32*15+1,32*15+4}));	
	set("mpLegend",([50:({32*15+21}),55:({32*14+24,32*14+27,32*15+1,32*15+4,32*16+17,32*17+4,32*17+13,32*17+28}),105:({32*42+1})]));
	set("mpLegend2",([50:({32*15+23,}),55:({32*14+26,32*14+29,32*15+3,32*15+6,32*16+19,32*17+6,32*17+15,32*17+30,}),]));
        setup();
}

void do_look( object who )
{
	object me = this_object();
	string tmp="";
	
	if ( who->get("escort.finish") == 1 )
	{
		TASK_ESCORT_D->do_look_2( who, me ); 
		return ;
	}
        if(     who->get_quest("escort.flag")    // 运镖任务
        &&      who->get_quest("escort.leader") == 1    // 队长Hoàn thành
        &&      who->get_quest("escort.name") == get_name() 
        && 	who->get_quest("escort.city")+" Quốc" == get_city_name() )    // 找对人了
        {
		TASK_ESCORT_D->do_look_2( who, me ); 
		return ;
	}        
        tmp += CHAIN_D->get_chain_menu(who,me);
	if ( (who->get_level() >=50 && !who->get_legend(TASK_15,21)) || (who->get_legend(TASK_15,21) && !who->get_legend(TASK_15,23)) )
		tmp += sprintf(ESC HIY "Niềm vui thơ ấu\ntalk %x# welcome.13\n",getoid(me));
	if ( (who->get_level() >=55 && !who->get_legend(TASK_14,24)) || (who->get_legend(TASK_14,24) && !who->get_legend(TASK_14,26)) )
		tmp += sprintf(ESC HIY "Những rắc rối của người hầu\ntalk %x# welcome.1\n",getoid(me));
	if ( (who->get_level() >=55 && !who->get_legend(TASK_14,27)) || (who->get_legend(TASK_14,27) && !who->get_legend(TASK_14,29)) )
		tmp += sprintf(ESC HIY "Vạn Lý Trường Thành\ntalk %x# welcome.4\n",getoid(me));
	if ( (who->get_level() >=55 && !who->get_legend(TASK_15,1)) || (who->get_legend(TASK_15,1) && !who->get_legend(TASK_15,3)) )
		tmp += sprintf(ESC HIY "Bức tường vĩ đại\ntalk %x# welcome.7\n",getoid(me));
	if ( (who->get_level() >=55 && !who->get_legend(TASK_15,4)) || (who->get_legend(TASK_15,4) && !who->get_legend(TASK_15,6)) )
		tmp += sprintf(ESC HIY "Rượu ngon\ntalk %x# welcome.10\n",getoid(me));
	if ( (who->get_level() >=55 && !who->get_legend(TASK_16,17)) || (who->get_legend(TASK_16,17) && !who->get_legend(TASK_16,19)) )
		tmp += sprintf(ESC HIY "Ma quỷ đang đến\ntalk %x# welcome.16\n",getoid(me));
	if ( (who->get_level() >=55 && !who->get_legend(TASK_17,4)) || (who->get_legend(TASK_17,4) && !who->get_legend(TASK_17,6)) )
		tmp += sprintf(ESC HIY "Âm thanh của bầu trời đêm\ntalk %x# welcome.19\n",getoid(me));
	if ( (who->get_level() >=55 && !who->get_legend(TASK_17,13)) || (who->get_legend(TASK_17,13) && !who->get_legend(TASK_17,15)) )
		tmp += sprintf(ESC HIY "Ánh sáng kì lạ\ntalk %x# welcome.22\n",getoid(me));
	if ( (who->get_level() >=55 && !who->get_legend(TASK_17,28)) || (who->get_legend(TASK_17,28) && !who->get_legend(TASK_17,30)) )
		tmp += sprintf(ESC HIY "Thông điệp\ntalk %x# welcome.25\n",getoid(me));
	if ( who->get_level() >=105 && !who->get_legend(TASK_42,1) )
		tmp += sprintf(ESC HIY "询问消息\ntalk %x# welcome.28\n",getoid(me));
			
	send_user(who,"%c%s",':',sprintf( "%s：\n    周Quốc的京都镖局尉迟老镖头武艺高强，生性豪爽，真是一条好汉！\n", get_name(),  ) 
			+ tmp +
			ESC"Rời khỏi."
			);

}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,i,size,p,amount;
        object who,item, *inv;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_14,24) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    我前段日子上燕长城的匝道，不小心将自己挣得的苦力钱遗失在那里，你能帮我寻回那苦力钱吗？\n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.2\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_14,24) && !who->get_legend(TASK_14,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    这可是我一家上下老小的活命钱啊！\n"ESC"Rời khỏi.", me->get_name()));
		else if ( who->get_legend(TASK_14,25) && !who->get_legend(TASK_14,26) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    真是太感谢你了！真不知道该如何报答你。\n"ESC"Hoàn thành任务\ntalk %x# welcome.3\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	break;
	case 2:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_14,24) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_14,24);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"Triệu Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,11,"Những rắc rối của người hầu" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ  "HIY"Những rắc rối của người hầu");
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_14,25) && !who->get_legend(TASK_14,26) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"苦力钱",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_14,26);
			who->add_exp(6200);
			who->add_potential(250);
			who->add_cash(6200);
			send_user(who,"%c%s",';',"Những rắc rối của người hầu 经验 6200 tiềm năng 250 Ngân lượng 6200");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,11,"" );
        	}
        	break;   
        case 4:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_14,27) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    害怕……\n    不知道你有没有见过会说话的石头，那天……那天我见到一块会说话的石头，太吓人了，它脸上什么都没有，就一张大大的嘴，一张一合，发出令人心寒的声音，我见到后马上掉头就跑，离了好远，还听见它发出尖锐的嘲笑声，实在是太可怕了！\n    我记得那块石头在燕长城的烽火台，估计是石魂在作祟，你前去调查一下此事！\n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.5\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_14,27) && !who->get_legend(TASK_14,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    太可怕了，以后再也不去那地方了！\n"ESC"Rời khỏi.", me->get_name()));
		else if ( who->get_legend(TASK_14,28) && !who->get_legend(TASK_14,29) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    这下去那里再也不用担心受怕了。\n"ESC"Hoàn thành任务\ntalk %x# welcome.6\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	break;
	case 5:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_14,27) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_14,27);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"Triệu Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,12,"Vạn Lý Trường Thành" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ  "HIY"Vạn Lý Trường Thành");
        	}
        	break;
        case 6:
        	if ( who->get_legend(TASK_14,28) && !who->get_legend(TASK_14,29) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/stuff/0038",2);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_14,29);
			who->add_exp(6100);
			who->add_potential(240);
			who->add_cash(6000);
			send_user(who,"%c%s",';',"Vạn Lý Trường Thành 经验 6100 tiềm năng 240 Ngân lượng 6000 铁丝 2");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,12,"" );
        	}
        	break;      
        case 7:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_15,1) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    你说这世道咋就这么乱呢！\n    我不过是做工经过燕长城，我不过是一个穷苦的工人，居然还有人打劫我！抢去了我辛苦挣得的工钱，还抢走了我身上所有值钱的东西，真是太令人气愤了！\n    %s，你就同情我这个可怜人，替我做主吧！\n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.8\n"ESC"Rời khỏi.", me->get_name(),NPC_RANK_D->get_respect_2(who),getoid(me)));
        	else if ( who->get_legend(TASK_15,1) && !who->get_legend(TASK_15,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    看来以后做生意再也不能从那经过了。\n"ESC"Rời khỏi.", me->get_name()));
		else if ( who->get_legend(TASK_15,2) && !who->get_legend(TASK_15,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    以后做生意从那经过再也不用担心了。\n"ESC"Hoàn thành任务\ntalk %x# welcome.9\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	break;
	case 8:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_15,1) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_15,1);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"Triệu Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,13,"Bức tường vĩ đại" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ  "HIY"Bức tường vĩ đại");
        	}
        	break;
        case 9:
        	if ( who->get_legend(TASK_15,2) && !who->get_legend(TASK_15,3) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/stuff/0258",2);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_15,3);
			who->add_exp(6300);
			who->add_potential(250);
			who->add_cash(6400);
			send_user(who,"%c%s",';',"Bức tường vĩ đại 经验 6300 tiềm năng 250 Ngân lượng 6400 铁环 2");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,13,"" );
        	}
        	break;   
        case 10:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_15,4) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    我最近迷上了酿酒，尝试了很多种不同的新方法，终于找到一种能酿造出旷世美酒的方法，可惜差了灵Kiến这个原料，据说有人在燕长城的匝道见过，你能帮我找到它吗？\n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.11\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_15,4) && !who->get_legend(TASK_15,5) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    看来酿造旷世美酒只能是我心中永远的一个遗憾。\n"ESC"Rời khỏi.", me->get_name()));
		else if ( who->get_legend(TASK_15,5) && !who->get_legend(TASK_15,6) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    这下我心中的梦想可以实现了，呵呵……\n"ESC"Hoàn thành任务\ntalk %x# welcome.12\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	break;
	case 11:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_15,4) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_15,4);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"Triệu Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,14,"Rượu ngon" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ  "HIY"Rượu ngon");
        	}
        	break;
        case 12:
        	if ( who->get_legend(TASK_15,5) && !who->get_legend(TASK_15,6) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"灵Kiến",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_15,6);
			who->add_exp(6300);
			who->add_potential(240);
			who->add_cash(6300);
			send_user(who,"%c%s",';',"Rượu ngon 经验 6300 tiềm năng 240 Ngân lượng 6300");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,14,"" );
        	}
        	break; 
        case 13:
        	if ( who->get_level() >= 50 && !who->get_legend(TASK_15,21) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    每天含辛茹苦，想想童年时候真开心啊，那才是单纯的开心。竹蜻蜓、小伙伴……想想就让人觉得很开心，你能给我找一个竹蜻蜓吗？听说在赵长城1的烽火台上曾有人见过。\n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.14\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_15,21) && !who->get_legend(TASK_15,22) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    也是难为你了，毕竟现在这种东西少了。\n"ESC"Rời khỏi.", me->get_name()));
		else if ( who->get_legend(TASK_15,22) && !who->get_legend(TASK_15,23) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    对的，就是这个，我都好久没有看到过这种东西了，现在的小孩子好象都不玩这个了。\n"ESC"Hoàn thành任务\ntalk %x# welcome.15\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	break;
	case 14:
        	if ( who->get_level() >= 50 && !who->get_legend(TASK_15,21) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_15,21);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"Triệu Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,4,"Niềm vui thơ ấu" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ  "HIY"Niềm vui thơ ấu");
        	}
        	break;
        case 15:
        	if ( who->get_legend(TASK_15,22) && !who->get_legend(TASK_15,23) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"竹蜻蜓",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_15,23);
			who->add_exp(6400);
			who->add_potential(258);
			who->add_cash(5400);
			send_user(who,"%c%s",';',"Niềm vui thơ ấu 经验 6400 tiềm năng 258 Ngân lượng 5400");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,4,"" );
        	}
        	break; 
        case 16:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_16,17) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    最近老遇见一些奇奇怪怪的事情，是我人品不好，还是这世道早已变成一个妖孽横行的世界。\n    上次路过燕长城的烽火台，见妖气冲天，必定是那被封千年的心之魔在蠢蠢欲动，我们得赶在它作孽之前将它除掉，不然后果不堪设想。你是否愿意前去除掉它？\n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.17\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_16,17) && !who->get_legend(TASK_16,18) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    这地方不会安静，看来我得赶快搬家了。\n"ESC"Rời khỏi.", me->get_name()));
		else if ( who->get_legend(TASK_16,18) && !who->get_legend(TASK_16,19) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    这下可好了，再也不用担心那恶魔害人了。\n"ESC"Hoàn thành任务\ntalk %x# welcome.18\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	break;
	case 17:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_16,17) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_16,17);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"Triệu Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,16,"Ma quỷ đang đến" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ  "HIY"Ma quỷ đang đến");
        	}
        	break;
        case 18:
        	if ( who->get_legend(TASK_16,18) && !who->get_legend(TASK_16,19) )
        	{
 			TASK_LEGEND_D->task_finish(who);
 			who->set_legend(TASK_16,19);
			who->add_exp(6300);
			who->add_potential(230);
			who->add_cash(6300);
			send_user(who,"%c%s",';',"Ma quỷ đang đến 经验 6300 tiềm năng 230 Ngân lượng 6300");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,16,"" );
        	}
        	break; 
        case 19:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,4) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    昨天晚上的一声巨响，你听见没？天啦，我怀疑你的耳朵有问题，那么大的响声你居然都没听见？真是服了你！\n    我听得清清楚楚，在燕长城的匝道上空传来一声巨响，当时有很多人都听见了，大家都在讨论，可能是那沉睡千年的混世魔出现了，我看除掉他的事还是交给你们这些武林中人来做吧，趁他还没有完全苏醒，赶紧去燕长城除掉他，不然晚了就来不及了！\n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.20\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_17,4) && !who->get_legend(TASK_17,5) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    真是太可怕了，以后再也不去那里了。\n"ESC"Rời khỏi.", me->get_name()));
		else if ( who->get_legend(TASK_17,5) && !who->get_legend(TASK_17,6) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    这下可有安静日子过了。\n"ESC"Hoàn thành任务\ntalk %x# welcome.21\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	break;
	case 20:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,4) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_17,4);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"Triệu Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,21,"Âm thanh của bầu trời đêm" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ  "HIY"Âm thanh của bầu trời đêm");
        	}
        	break;
        case 21:
        	if ( who->get_legend(TASK_17,5) && !who->get_legend(TASK_17,6) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/63018",1);
 			TASK_LEGEND_D->task_finish(who);
 			who->set_legend(TASK_17,6);
			who->add_exp(6400);
			who->add_potential(230);
			who->add_cash(6400);
			send_user(who,"%c%s",';',"Âm thanh của bầu trời đêm 经验 6400 tiềm năng 230 Ngân lượng 6400 Bổ Tâm Đan图纸 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,21,"" );
        	}
        	break; 
        case 22:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,13) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    夜明珠……玉明珠……\n    听说过夜明珠？我相信。听说过玉明珠？吹牛！你知道玉明珠是拿来干嘛的吗？我相信你一定不知道，因为我也不知道，哈哈哈哈！\n    不过我知道这个东西一定很值钱，能找到一定可以卖个好价钱，所以你去给我找找吧，卖了好价钱我分你一半！那玉明珠就在燕长城的匝道。\n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.23\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_17,13) && !who->get_legend(TASK_17,14) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    我打算让我的儿子去找那宝珠。\n"ESC"Rời khỏi.", me->get_name()));
		else if ( who->get_legend(TASK_17,14) && !who->get_legend(TASK_17,15) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    哈哈……原来世上真有此物啊！\n"ESC"Hoàn thành任务\ntalk %x# welcome.24\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	break;
	case 23:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,13) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_17,13);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"Triệu Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,24,"Ánh sáng kì lạ" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ  "HIY"Ánh sáng kì lạ");
        	}
        	break;
        case 24:
        	if ( who->get_legend(TASK_17,14) && !who->get_legend(TASK_17,15) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"玉明珠",1) != 1 )
        			return;
 			TASK_LEGEND_D->task_finish(who);
 			who->set_legend(TASK_17,15);
			who->add_exp(6800);
			who->add_potential(240);
			who->add_cash(6500);
			send_user(who,"%c%s",';',"Ánh sáng kì lạ 经验 6800 tiềm năng 240 Ngân lượng 6500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,24,"" );
        	}
        	break; 
        case 25:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    昨日，有一客官将一封复命信函遗失在燕长城的匝道处。这位客官在我这里留言，谁能帮他寻到复命信函，他一定重重酬谢！\n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.26\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_17,28) && !who->get_legend(TASK_17,29) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    难道没有人能帮助他吗？\n"ESC"Rời khỏi.", me->get_name()));
		else if ( who->get_legend(TASK_17,29) && !who->get_legend(TASK_17,30) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    这下那位客官可以放心的走了。\n"ESC"Hoàn thành任务\ntalk %x# welcome.27\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	break;
	case 26:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,28) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_17,28);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"Triệu Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,29,"Thông điệp" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ  "HIY"Thông điệp");
        	}
        	break;
        case 27:
        	if ( who->get_legend(TASK_17,29) && !who->get_legend(TASK_17,30) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"复命信函",1) != 1 )
        			return;
 			TASK_LEGEND_D->task_finish(who);
 			who->set_legend(TASK_17,30);
			who->add_exp(6800);
			who->add_potential(250);
			who->add_cash(6700);
			send_user(who,"%c%s",';',"Thông điệp 经验 6800 tiềm năng 250 Ngân lượng 6700");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,29,"" );
        	}
        	break; 
	case 28:
		if ( who->get_level() >=105 && !who->get_legend(TASK_42,1) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    我这几天挑东西送去王府，老是听到内政官在念叨什么，似乎很急切的样子，为Quốc分忧乃是民之本分，我位卑力薄恐怕帮不上忙，只得请壮士前去探询一番，为Quốc贡献也能得些封赏，何乐不为？\n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.29\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
		break;	        	
	case 29:
		if ( who->get_level() >=105 && !who->get_legend(TASK_42,1) )
		{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_42,1);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"Triệu Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,73,"询问消息" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ  "HIY"询问消息");
        	}
		break;
        }
}