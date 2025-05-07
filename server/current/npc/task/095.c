
// 自动生成：/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
inherit LEGEND_NPC;

int is_caster() { return 1; }

//int get_char_picid() { return 1001; }
int get_char_picid() { return 8273; }

// 函数：构造处理
void create()
{
	set_name(PPM"Ngọc Trụ");

	set_level(100);
	set_max_hp(2000000);
	set_ap(5000);
	set_dp(10000);
	set_cp(5000);
	set_pp(10000);
	set_sp(0);
	set_walk_speed(4);
	set_attack_speed(15);
	set_max_seek(50);

	setup();
	set_char_type(FIGHTER_TYPE_2);
}

int get_weapon_code() { return UNARMED; }


int perform_action(object who) {
	return PF_FILE_04232->perform_action_npc(this_object(), who);
}

void check_legend_task(object who)
{
	int p;
	object item;
	if (objectp(who) && who->get_legend(TASK_04, 1) && !who->get_legend(TASK_04, 2))
	{
		item = new("item/98/0009");
		if (!item)
			return;
		p = item->move(who, -1);
		if (!p)
			return;
		item->add_to_user(p);
		who->set_legend(TASK_04, 2);
		send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2, TID_HANGUO, 1, "Kho bạc bị đánh cắp(Hoàn thành)");
		send_user(who, "%c%s", '!', "一箱黄金 1/1");
	}

}