#include <ansi.h>
#include <cmd.h>
#include <music.h>
#include <task.h>
#include <time.h>
#include <equip.h>
#include <effect.h>

// 函数：读书效果
void into_effect(object me)
{
	int skill = me->get_save("study");

	if (!me->get_skill(skill)) return;
	USER_SKILL_D->improve_skill_2(me, skill, 250);
	
	tell_user(me, ECHO "Mức độ tu luyện của bạn tăng thêm 250 điểm.");

	if (!get_effect(me, EFFECT_USER_STUDY))
	{
		send_user(me, "%c%s", '!', "您无法从翻阅得残破不全的书中领悟到什么。");
	}
}
