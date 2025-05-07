
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

// 函数：小贩识别
int is_seller() { return 1; }

// 函数：获取人物造型
int get_char_picid() { return 7405; }

// 有自己的do_look函数
int is_self_look() { return 1; }

void do_welcome( string arg );

// 函数：构造处理
void create()
{
        set_name("Chủ Tiệm Trang Sức");
	set_real_name("Nhược Thiền");
        set_city_name("Tần Quốc");

        set_2( "good", ([
                "01" : "/item/88/6020",
                "02" : "/item/88/6030",
                "03" : "/item/88/6040",
                "06" : "/item/87/6020",
                "07" : "/item/87/6030",
                "08" : "/item/87/6040",

        ]) );

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
        setup();
 	set("mpLegend",([65:({32*51+1})]));
 	set("mpLegend2",([65:({32*51+3})]));
}

// 函数：对话处理
void do_look( object who )
{
	object me = this_object();
	string result;
	"/quest/help"->send_help_tips(who, 51);
	result = sprintf("%s：\n    "+"/quest/word"->get_normal_word(me)+"\n", me->get_name() );
	if ( (who->get_level() >= 65 && !who->get_legend(TASK_2_01,1)) || 
		(who->get_legend(TASK_2_01,1) && !who->get_legend(TASK_2_01,3)) )
		result += sprintf(ESC HIY "Sự trở lại của linh hồn\ntalk %x# welcome.1\n",getoid(me));
	result += sprintf(ESC "哪里有适合我的装备？\ntalk %x# welcome.99\n", getoid(me) ) ;        	
	result += sprintf( ESC "Giao dịch\nlist %x#\n" ESC "我只是随便看看\nCLOSE\n", getoid(me) ) ;        	
	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), result );
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
        	if ( who->get_level() >= 65 && !who->get_legend(TASK_2_01,1) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ……………………郎……（看这位姑娘样子痴痴呆呆，问问附近的成快嘴吧。）\n"ESC"Rời khỏi.", me->get_name(),));
		else if ( who->get_legend(TASK_2_01,1) && !who->get_legend(TASK_2_01,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    …………………………\n"ESC"Rời khỏi.", me->get_name(),));
		else if ( who->get_legend(TASK_2_01,2) && !who->get_legend(TASK_2_01,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    哎……唐郎……你教我如何能独活于世啊……\n"ESC"Hoàn thành任务\ntalk %x# welcome.2\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	break;
        case 2:
        	if ( who->get_legend(TASK_2_01,2) && !who->get_legend(TASK_2_01,3) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"Ba linh hồn và sáu linh hồn",1) != 1 )
        			return;
        		TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_2_01,3);
			who->add_exp(16800);
			who->add_potential(400);
			who->add_cash(19600);
			send_user(who,"%c%s",';',"Sự trở lại của linh hồn 经验 16800 tiềm năng 400 Ngân lượng 19600");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,103,"" );
        	}
        	break;
	default:
	case 99:
        	"/npc/base/0005"->do_welcome2(me, "99");
		break;
	}
	
}