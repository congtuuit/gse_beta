
// 自动生成：/make/npc/make8002

#include <npc.h>
#include <city.h>
#include <task.h>
#include <ansi.h>
#include <equip.h>

#define GENERAL_D       "/inh/city/general"

inherit OFFICER;

void do_patrol( string arg );
void do_soldier( string arg );
void do_armor( string arg );
void do_welcome(string arg);
void do_defence( string arg );

// 函数：获取人物造型
int get_char_picid() { return 5201; }

// 函数：构造处理
void create()
{
        set_name("Sở Quốc Tướng Quân");
	set_real_name("Hạng Vũ");
        set_city_name("Sở Quốc");

        set_2( "talk", ([
                "welcome"	: (: do_welcome :),
        ]) );

        setup();
}

string get_master() { return CITY_CHU->get_master(); }
string get_master_2() { return CITY_CHU->get_master_2(); }
string get_master_3() { return CITY_CHU->get_master_3(); }

void do_defence(string arg) { "/sys/party/defence"->do_defence(this_player(), this_object(), arg); }

void do_look( object who ) 
{
	string tmp="";
	object me = this_object();
	
	
	if (who->get_save_2("hienvien.point") >= 1500)
		tmp = sprintf(ESC HIG "Trang bị Bá Vương\nlist %x#\n",getoid(me));

	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s：\n    %s\n",get_name(),"/quest/word"->get_country_word(me)) +
		tmp +
		ESC"Rời khỏi.");
	else	 
		GENERAL_D->do_look( who, this_object() ); 
}
void do_patrol( string arg ) { GENERAL_D->do_patrol( this_player(), this_object(), arg ); }
void do_soldier( string arg ) { GENERAL_D->do_soldier( this_player(), this_object(), arg ); }
void do_armor( string arg ) { GENERAL_D->do_armor( this_player(), this_object(), arg ); }

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,i,size,p,amount;
        object who,item, *inv;
        string name,place;     
       	string *nTmp,tmp;     

        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_legend(TASK_NEWBIE_03,26) && !who->get_legend(TASK_NEWBIE_03,27) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    听说庄辛吩咐你办了一件事情，怎么？还没办好吗？\n"ESC"Rời khỏi.", me->get_name()));
        	else if ( who->get_legend(TASK_NEWBIE_03,27) && !who->get_legend(TASK_NEWBIE_03,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    所谓亡羊补牢，为时不晚啊～～倘若不是大王及时省悟，我大楚就失去庄辛这个足智多谋的好臣子了！\n"ESC"Hoàn thành任务\ntalk %x# welcome.2\n"ESC"Rời khỏi.", me->get_name(),getoid(me)));
        	break;
        case 2:
        	if ( who->get_legend(TASK_NEWBIE_03,27) && !who->get_legend(TASK_NEWBIE_03,28))
        	{
			if ( !sizeof(who->get_fam_name()) )
			{
				send_user(who,"%c%s",'!',"无门无派可交不了任务哦～");
				return;	
			}
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
        		if ( who->get_fam_name() == "禁卫军" )
        			nTmp = ({"item/74/0010","item/75/0010"});
        		else
        			nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),0,10,WEAPON_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			TASK_LEGEND_D->give_item(who,tmp,1);

			who->delete_save_2("zxkillnpc");
			who->delete_save_2("zxkillnpc1");
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_NEWBIE_03,28);
			who->add_exp(900);
			who->add_potential(100);
			who->add_cash(1800);
			who->set_legend(TASK_NEWBIE_03,28);
			send_user(who,"%c%s",';',sprintf("亡羊补牢 经验 900 tiềm năng 100 Ngân lượng 1800 %s 1",tmp->get_name()));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_DONGTINGHU,2,"" );			
        	}
        	break;
        }
}