/*-----------------------------------------------------------------------------------------*\
	《真假虎王》活动配置NPC ---- 临时传送工
	由cjxx创建
	使用此文件时需要配合活动主控文件。
\*-----------------------------------------------------------------------------------------*/
#include <npc.h>
#include <ansi.h>
#include <effect.h>

inherit OFFICER;

#define GUESS_TRUE_TIGER	"/sys/party/guess_true_tiger"

void do_tiger_active(string arg);	//	真假虎王相关对话操作

int get_char_picid() { return 0351; }

void create() {
	set_name("Công Nông");
	
	set_2("talk", ([
		"tiger" : (: do_tiger_active :),
	]));
	setup();
}

//	玩家点击NPC
void do_look(object who) {
	__FILE__->do_look_reflash(who,this_object());
}
//	do_look 的在线更新函数
void do_look_reflash(object who,object me) {
	int id = getoid(me);
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf(
		"%s: \n    Ta đã bị tên vua hổ đó bắt làm sứ giả, và ta không được phép nói ai mới là vua hổ thực sự！\n"
		ESC"Về thôn\ntalk %x# tiger.1\n"
		ESC"Rời khỏi.",me->get_name(),id,
	));
}
void do_tiger_active(string arg) {
	__FILE__->do_tiger_active_reflash(this_object(),arg);
}
void do_tiger_active_reflash(object me, string arg) {
	object who;
	int flag,id;
	who = this_player();
	if(get_effect(who,EFFECT_PROGRESS2)) {
		return;
	}
	
	flag= to_int(arg);
	id  = getoid(me);
	switch(flag) {
		default:
		case 1:
			send_user(who, "%c%c%w%s", 0x5a, 0, 6, "Đang di chuyển……");
			set_effect(who, EFFECT_PROGRESS2, 6);
			who->set_progress_file(__FILE__);
			break;
	}
}

void into_effect(object who) {
	send_user(who, "%c%c%c", 0x5a, 1, 1);
	who->add_to_scene(1, 152, 130, 3);
}