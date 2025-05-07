/*-----------------------------------------------------------------------------------------*\
	《真假虎王》活动配置NPC ---- 活动天使
	由cjxx创建
	使用此文件时需要配合活动主控文件。
\*-----------------------------------------------------------------------------------------*/
#include <npc.h>
#include <ansi.h>
#include <time.h>

inherit SAVE_F;
inherit OFFICER;

#define GUESS_TRUE_TIGER	"/sys/party/guess_true_tiger"
#define _DEBUG(str) 		;//if(objectp(find_char("1"))) {tell_user(find_char("1"),str);}

void do_tiger_active(string arg);	//	真假虎王相关对话操作

int get_char_picid() { return 0951; }

void create() {
	set_name("Thiên sứ hoạt động");
	
	set_2("talk", ([
		"tiger" : (: do_tiger_active :),
	]));
	setup();
}

void do_look(object who) {
	__FILE__->do_look_reflash(who,this_object());
}
void do_look_reflash(object who,object me) {
	int id = getoid(me);
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf(
		"%s: \n Tôi là thiên thần đáng yêu nhất, thiên thần trao đổi bên cạnh xấu xí hơn t ôi nhiều, tôi chịu trách nhiệm cho tất cả các hoạt động của thời kỳ của hiệp ước\n"
		//ESC"Vua Thuần Thật Giả\ntalk %x# tiger.1\n"
		ESC"Xiêm Cá\ntalk %x# tiger.100\n"
		ESC"Rời khỏi.",me->get_name(),id,id
	));
}
void play_next_stage(object who,int level) {
	GUESS_TRUE_TIGER->delete_tigers_on_player(who,0);
	GUESS_TRUE_TIGER->active_main_logic(who,level);
	who->set("now_call_out_next_stage",0);
}
//	玩家放弃活动
void give_up_the_activity(object who) {
	string *active_bonus,say_word;
	int level = who->get_save("guess_true_tiger");	
	if(level > 0) {
		active_bonus = active_bonus = GUESS_TRUE_TIGER->get_active_bonus(level);
		if(level > 1) {		
			say_word = sprintf("Bạn đã thành công vượt qua thử thách，sẽ có %s Đồng tiền hiệp và các nhân vật Trung Quốc“"HIR"%s"NOR"”Vinh danh，Làm ơn tới NPC trao đổi sự kiện để lấy phần thưởng.",active_bonus[2],active_bonus[1]);
		} else {			
			say_word = sprintf("Bạn đã thành công vượt qua thử thách，sẽ có“"HIR"%s"NOR"”Vinh danh，Làm ơn tới NPC trao đổi sự kiện để lấy phần thưởng.",active_bonus[1]);
		}
		GUESS_TRUE_TIGER->delete_tigers_on_player(who,0);
		send_user(who,"%c%s",';',say_word);
		MAILBOX->sys_mail(who->get_id(),who->get_number(),say_word);
		who->delete("guess_true_tiger_map");
	} else {
		_DEBUG("DEBUG -- 错误！玩家没有得到闯关等级奖励!");
	}
}

void call_out_next_stage(object who) {	
	string *active_bonus,say_word;
	int level = who->get_save("guess_true_tiger");
	if(level >=6) {
		active_bonus = active_bonus = GUESS_TRUE_TIGER->get_active_bonus(level);
		say_word = sprintf("您闯关成功，将获得%s战国币与“"HIR"%s"NOR"”称号的奖励，请去活动兑换天使处领取奖励。",active_bonus[2],active_bonus[1]);
		send_user(who,"%c%s",';',say_word);
		MAILBOX->sys_mail(who->get_id(),who->get_number(),say_word);		
	} else {
		if(get_z(who) == who->get("guess_true_tiger_map")) {
			if(who->get("guess_true_tiger_nojump")) {
				return;
			}
			GUESS_TRUE_TIGER->delete_tigers_on_player(who,0);
			if(!who->get("now_call_out_next_stage")) {
				send_user(who,"%c%s",'!',sprintf("5秒后将进入第%d关。",level+1));
				call_out("play_next_stage",5,who,level+1);
				who->set("now_call_out_next_stage",1);
			} else {
				who->add("define_tiger_attacking",1);
				if(who->get("define_tiger_attacking")>5) {
					play_next_stage(who,7);
					who->set("define_tiger_attacking",0);
				}
			}
		} else {
			_DEBUG("DEBUG -- 玩家已经不在活动场地");
			GUESS_TRUE_TIGER->delete_tigers_on_player(who,0);
			play_next_stage(who,7);
		}
	}
}
//	《真假虎王》过一关后的对白操作
void do_next_stage(object who) {
	__FILE__->do_next_stage_reflash(who,this_object());
}
//	do_next_stage 的在线更新函数
void do_next_stage_reflash(object who,object me) {
	int id = getoid(me);
	int level = who->get_save("guess_true_tiger");
	if(level>0) {
		if(level < 6) {
			send_user(who, "%c%s", ':',sprintf("您闯关成功，是否继续第 %d 关？如果失败，您将失去所有奖励，但是成功后的奖励是非常丰厚的。\n"
				ESC"Tiếp tục\ndesc tiger_next\n"
				ESC"Rời khỏi\ndesc tiger_drop\n",level+1
			));
		} else {
			give_up_the_activity(who);
		}
	}
}
//	《真假虎王》相关对话操作
void do_tiger_active(string arg) {
	__FILE__->do_tiger_active_reflash(this_object(),arg);
}
//	《真假虎王》活动在线更新函数
void do_tiger_active_reflash(object me, string arg) {
	object who,*tmp_team, item;
	string say_word;
	int flag,id,level, iDay, iTime, p;

	mixed* mxTime;
	iTime = time();
	mxTime = localtime(iTime);
	iDay = mxTime[TIME_YDAY];

	who  = this_player();
	flag = to_int(arg);	
	id   = getoid(me);
	switch(flag) {
		case 1:	//	主对白
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \n真假虎王是一个过关类的活动，你可以在我这里了解详细情况。\n"
				ESC"Chi tiết hoạt động\ntalk %x# tiger.2\n"
				ESC"Tham gia hoạt động\ntalk %x# tiger.3\n"
				ESC"Rời khỏi.",me->get_name(),id,id
			));
			break;
		case 2:	//	活动说明
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \n真假虎王活动需要你单独参加，不能够组队，收取10000战国币的门票费。\n    进入活动地图后，你面前会出现七只造型完全相同而能力不同的虎王，你可以挑选一只进行战斗，打败虎王则过一关。\n    第一关的七只虎王中有１只能力超强，剩下的６只都可以轻松打败，第二关的七只虎王中有２只能力超强，剩下的５只都可以轻松打败，以此类推，直到第六关的七只虎王中有６只能力超强，只剩下１只可以轻松打败。\n    如果你能连闯６关，那么你就可以得到至高无上的奖励，当然，你也可以中途放弃，那你将只能得到你当前过关的奖励，但是如果你在继续闯关的过程中失败了，那你将不会获得任何奖励。\n"
				ESC"Rời khỏi.",me->get_name()
			));
			break;
		case 3:
			if(GUESS_TRUE_TIGER->is_in_active_area()) {
				level= who->get_save("guess_true_tiger");
				if(level >1) {
					say_word = "你上次闯关的奖励还没有领取，确定要再次进去Thử thách吗？这样会让你失去上次的奖励！";
				} else {
					say_word = "Thử thách虎王需要10000战国币的门票，你进活动场景后也可以让你的朋友来帮助你！";
				}
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \n%s\n"
					ESC"Thử thách\ntalk %x# tiger.4\n"
					ESC"Rời khỏi.",me->get_name(),say_word,id
				));
			} else {
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \n现在还不能参加真假虎王的游戏，%s 才是活动时间。\n"
					ESC"Rời khỏi.",me->get_name(),GUESS_TRUE_TIGER->get_active_time()
				));
			}
			break;
		case 4:	//	选择Thử thách
			if(GUESS_TRUE_TIGER->is_in_active_area()) {
				tmp_team = who->get_team();
				if(tmp_team != 0 && sizeof(tmp_team)>1) {
					send_user(who, "%c%s", '!', "您在队伍中，不能参加此次活动");
				} else {
					if(who->get_cash() >= 10000) {
						GUESS_TRUE_TIGER->active_main_logic(who,1);
					} else {
						send_user(who, "%c%s", '!', "您的战国币不够10000");
					}					
				}
			} else {
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \n现在还不能参加真假虎王的游戏，%s 才是活动时间。\n"
					ESC"Rời khỏi.",me->get_name(),GUESS_TRUE_TIGER->get_active_time()
				));				
			}
			break;

		case 100:
			if (who->get_save_2("xiemca.today") == iDay)
			{
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s: \nHôm nay đã hết lượt hỗ trợ mục này rồi\n"
					ESC"Rời khỏi.", me->get_name()
				));
				return ;
			}

			if (USER_INVENTORY_D->get_free_count(who) < 1)
			{
				notify("Hành trang không đủ 1 chỗ trống");
				return ;
			}

			item = new("item/common/xiem");
			if (item)
			{
				send_user(who, "%c%s", ';', sprintf("Bạn nhận được "HIY "%s ", item->get_name()));
				p = item->move2(who);
				item->add_to_user(p);

				who->set_save_2("xiemca.today", iDay);
			}


			break;
	}
}