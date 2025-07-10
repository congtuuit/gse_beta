
// 自动生成：/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;
string *TalkTable = ({ 
        "Đầu năm nay rối loạn, muốn áp tiêu cũng không dễ dàng...",
        "Muốn tìm Tiêu Cục Kinh Đô hộ tống hành hoá nhưng hắn không rảnh...",
        "Muốn tìm Tiêu Cục Kinh Đô hộ tống người thân nhưng hắn không rảnh...",
        "Chu Quốc Kinh Đô Tiêu Cục võ nghệ cao cường, trời sinh tính tình sảng khói, thật là một hảo hán !",
});
void do_task_start();
void do_task_cancel();

//void do_task_finish();
int get_char_picid() { return 5301; }
void do_welcome( string arg );

// 函数：构造处理
void create()
{
        set_name("Hàn Tổng Quản");
        set_city_name("Hàn Quốc");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ])); 

	set("mpLegend2",([0:({32*25+10,32*25+13,32*25+16,}),15:({32*37+18}),70:({32*38+8}),]));
        setup();
}

// 函数：对话处理
void do_look( object who ) 
{
	string tmp="";
	object me = this_object();
	if ("/sys/task/master"->do_look_quest10(who, this_object())>0) return;
	if ( who->get("escort.finish") == 1 )
	{
		TASK_ESCORT_D->do_look_2( who, this_object() ); 
		return ;
	}
        if(     who->get_quest("escort.flag")    // 运镖任务
        &&      who->get_quest("escort.leader") == 1    // 队长Hoàn thành
        &&      who->get_quest("escort.name") == get_name() 
        && 	who->get_quest("escort.city")+" Quốc" == get_city_name() )    // 找对人了
        {
		TASK_ESCORT_D->do_look_2( who, this_object() ); 
		return ;
	}        
	
        tmp += CHAIN_D->get_chain_menu(who,me);
	if ( who->get_legend(TASK_25,9) && !who->get_legend(TASK_25,10) )
		tmp += sprintf(ESC HIY "寻根问底\ntalk %x# welcome.1\n",getoid(me));
	if ( (who->get_legend(TASK_25,10) && !who->get_legend(TASK_25,11)) || (who->get_legend(TASK_25,11) && !who->get_legend(TASK_25,13)) )
	{
		tmp += sprintf(ESC HIY "Chứng minh bản thân\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( (who->get_legend(TASK_25,13) && !who->get_legend(TASK_25,14)) || (who->get_legend(TASK_25,14) && !who->get_legend(TASK_25,16)) )
	{
		tmp += sprintf(ESC HIY "Tìm hiểu bí ẩn của kho báu\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( who->get_level() >= 15 && who->get_legend(TASK_37,17) && !who->get_legend(TASK_37,18) )
		tmp += sprintf(ESC HIY "韩总管的帮助\ntalk %x# welcome.7\n",getoid(me));
	if ( who->get_level() >= 70 && who->get_legend(TASK_38,7) && !who->get_legend(TASK_38,8) )
		tmp += sprintf(ESC HIY "韩总管的托付\ntalk %x# welcome.9\n",getoid(me));

	send_user(who,"%c%s",':',sprintf( "%s：\n    %s\n", get_name(), TalkTable[ random(sizeof(TalkTable))] ) 
			+ tmp +
			ESC"Rời khỏi."
			);

}


// 函数：开始任务
// void do_task_start() { TASK_ESCORT_D->do_task_start( this_player(), this_object() ); }
// 函数：取消任务
// void do_task_cancel() { TASK_ESCORT_D->do_task_cancel( this_player(), this_object() ); }

int accept_money(object who, int gold)
{
	return "/sys/task/master"->accept_money(this_object(), who, gold);
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,p;
        object who,item;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
		if ( who->get_legend(TASK_25,9) && !who->get_legend(TASK_25,10) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    你怎么知道我有藏宝图？一定是财政官那家伙告诉你的吧？但是能让财政官那家伙漏这口风看来你也不简单。\n"ESC"Hoàn thành任务\ntalk %x# welcome.2\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_25,10) && !who->get_legend(TASK_25,11) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    你来得正好，能让财政官那家伙漏这口风看来你也不简单。我正要找个有点能耐的人帮我去做件事，但是我现在还不相信你的实力，如果你想证明你的实力的话就先去灵谷洞杀掉20个豆兵和20个Ác ma trong lọ吧！等你杀掉这些妖怪还能安然回来的话，我会把我要委托你的事告诉你。当然，如果你能顺利Hoàn thành的话你最终将获得我这藏宝图。\n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.3\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_25,11) && !who->get_legend(TASK_25,12) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    你怎么跑回来了？难道说你没有那么实力消灭那些妖怪？\n"ESC"Rời khỏi.", me->get_name()));
		else if ( who->get_legend(TASK_25,12) && !who->get_legend(TASK_25,13) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    呵呵……你果然是有点实力，看来我烦恼多时的事终于可以找到一个可以委托的人了。\n"ESC"Hoàn thành任务\ntalk %x# welcome.4\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_25,13) && !who->get_legend(TASK_25,14) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    前一阵子我外出巡视，路过灵谷洞附近的时候被从里面跳出来的一群豆兵和Ác ma trong lọ把我的传家之宝——翠玉之晴抢走了，翠玉之晴可是我们家代代相传的宝物，我可不能让它在我手上失传了。现在那些豆兵和Ác ma trong lọ已经被你制服了。你现在要做的是再去灵谷洞的2层替我将翠玉之晴找回来。等你把翠玉之晴找回来之后我会把我的藏宝图交给你。\n"ESC"Nhận nhiệm vụ\ntalk %x# welcome.5\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_25,14) && !who->get_legend(TASK_25,15) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    如果翠玉之晴找不回来的话，我如何面对我们的列祖列宗啊？\n"ESC"Rời khỏi.", me->get_name()));
		else if ( who->get_legend(TASK_25,15) && !who->get_legend(TASK_25,16) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    哈哈！你可把翠玉之晴给我找回来了，这样的话我可放下心头大石了。这次真的要谢谢你呀。放心，你期待的藏宝图就在这里，你拿去吧，我想这个藏宝图所指示的地点一定有不错的宝藏。\n"ESC"Hoàn thành任务\ntalk %x# welcome.6\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));

        	break;
        case 2:
        	if ( who->get_legend(TASK_25,9) && !who->get_legend(TASK_25,10) )
        	{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_25,10);
			who->add_exp(32000);
			who->add_potential(500);
			who->add_cash(31000);
			send_user(who,"%c%s",';',"寻根问底 经验 32000 tiềm năng 500 Ngân lượng 31000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,18,"" );
			me->do_welcome(1);
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_25,10) && !who->get_legend(TASK_25,11) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_25,11);
        		who->delete_save_2("hzgdoubing");
        		who->delete_save_2("hzgguanzy");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_HANGUO,"Hàn Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,19,"Chứng minh bản thân" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ  "HIY"Chứng minh bản thân");
        	}
        	break;
         case 4:
        	if ( who->get_legend(TASK_25,12) && !who->get_legend(TASK_25,13) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/63028",1);
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_25,13);
        		who->delete_save_2("hzgdoubing");
        		who->delete_save_2("hzgguanzy");
			who->add_exp(34000);
			who->add_potential(510);
			who->add_cash(32000);
			send_user(who,"%c%s",';',"Chứng minh bản thân 经验 34000 tiềm năng 510 Ngân lượng 32000 丧命散图纸 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,19,"" );
			me->do_welcome(1);
        	}
        	break;
        case 5:
        	if ( who->get_legend(TASK_25,13) && !who->get_legend(TASK_25,14) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_25,14);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_HANGUO,"Hàn Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,20,"Tìm hiểu bí ẩn của kho báu" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ  "HIY"Tìm hiểu bí ẩn của kho báu");
        	}
        	break;
         case 6:
        	if ( who->get_legend(TASK_25,15) && !who->get_legend(TASK_25,16) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"翠玉之睛",1) != 1 )
        			return;
        		TASK_LEGEND_D->give_item(who,"item/product/63029",1);
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_25,16);
			who->add_exp(33000);
			who->add_potential(500);
			who->add_cash(33000);
			send_user(who,"%c%s",';',"Tìm hiểu bí ẩn của kho báu 经验 33000 tiềm năng 500 Ngân lượng 33000 龙涎草图纸 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,20,"" );
        	}
        	break;
        case 7:
	 	if ( who->get_level() >= 15 && who->get_legend(TASK_37,17) && !who->get_legend(TASK_37,18) )
			send_user(who,"%c%s",':',sprintf("%s:\n    唉，这孩子就是孝顺，之前为他母亲的病累坏了，现在还想再打份工。我会为他找份好点的事的，谢谢你过来告诉我情况。\n"ESC"Hoàn thành任务\ntalk %x# welcome.8\n"ESC"Rời khỏi.",me->get_name(),getoid(me)));
        	break;
        case 8:
        	if ( who->get_level() >= 15 && who->get_legend(TASK_37,17) && !who->get_legend(TASK_37,18) )
        	{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_37,18);
			who->add_exp(600);
			who->add_potential(35);
			who->add_cash(1200);
			send_user(who,"%c%s",';',"韩总管的帮助 经验 600 tiềm năng 35 Ngân lượng 1200");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,43,"" );
        	}
        	break;
        case 9:
       		if ( who->get_level() >= 70 && who->get_legend(TASK_38,7) && !who->get_legend(TASK_38,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    这些糊涂虫，我要找的人根本就不是你！不过也不能怪你，是他们搞错人了，辛苦你跑了这一趟了。\n"ESC"Hoàn thành任务\ntalk %x# welcome.10\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
		break;
        case 10:
       		if ( who->get_level() >= 70 && who->get_legend(TASK_38,7) && !who->get_legend(TASK_38,8) )
		{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_38,8);
			who->add_exp(20000);
			who->add_potential(210);
			who->add_cash(22000);
			send_user(who,"%c%s",';',"韩总管的托付 经验 20000 tiềm năng 210 Ngân lượng 22000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,91,"" );
        	}
		break;		
        }
}