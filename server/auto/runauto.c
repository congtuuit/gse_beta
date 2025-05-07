#include <cmd.h>
#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>
#include <time.h>
#include <city.h>
#include <npc.h>
#include <skill.h>

#define GET "cmd/std/get" 

string AUTO = "E100";

int ON = 1;
int OFF = 0;

int removeTitle(object me);
int addTitle(object me);
int backHome(object me);

int finMin(int *rangeArr) {
	int i = 0, position = 0;
	int min = 999999;

	for (i = 0; i < sizeof(rangeArr); i++) {
		if (rangeArr[i] < min){
			min = rangeArr[i];
			position = i;
		}
	}

	return position;
}

object nearObject(object me) {
	object targetNpc, map, * member, * all = ({}), * npc = ({});
	object* item, who, * nObj, empty;

	int z, x, y, p, max_x, max_y, x_me, y_me, range = 13;
	int i, size, index = 0, *rangeArr = ({}), distanceX = 0, distanceY = 0;

	z = get_z(me);
	x_me = get_x(me);
	y_me = get_y(me);

	map = get_map_object(z);
	if (!map) return 0;
	reset_eval_cost();

	z = map->get_id();  max_x = get_map_max_x(z);  max_y = get_map_max_y(z);

	for (x = (x_me - range); x < (x_me + range); x += AREA_SIZE)
	{
		for (y = (y_me - range); y < (y_me + range + 5); y += AREA_SIZE)
		{
			if (have_scene_object(z, x, y, CHAR_TYPE, 1))
			{
				item = get_scene_object(z, x, y, CHAR_TYPE, 1);
				for (i = 0, size = sizeof(item); i < size; i++)
				{
					if (who = item[i])
					{
						if (who->can_be_fighted(me)) 
						{
							//tell_user(me, ECHO"NPC: %s (%d, %d)", who->get_name(), get_x(who), get_y(who));
							distanceX = abs(get_x(who) - x_me);
							distanceY = abs(get_y(who) - y_me);
							distanceX = distanceX * distanceX + distanceY * distanceY;

							rangeArr += ({ distanceX });
							npc += ({ who });
						}
					}
				}
			}
		}
	}

	index = finMin(rangeArr);

	if (sizeof(npc) == 0) {
		return empty;
	}

	if (index >= 0 && sizeof(npc) > 1) {

		return npc[index];
		
	} else {
		return empty;
	}
}

int getItemAround(object me) 
{
	object targetNpc, map, * member, * all = ({}), * npc = ({});
	object* item, _thisItem, * nObj, empty;

	int z, x, y, p, max_x, max_y, x_me, y_me, range = 8;
	int i, size, index = 0, *rangeArr = ({}), distanceX = 0, distanceY = 0;

	z = get_z(me);
	x_me = get_x(me);
	y_me = get_y(me);

	if(!z)
	{
		return 0;
	}

	map = get_map_object(z);
	if (!map) return 0;
	reset_eval_cost();

	z = map->get_id();  max_x = get_map_max_x(z);  max_y = get_map_max_y(z);

	for (x = (x_me - range); x < (x_me + range); x += AREA_SIZE)
	{
		for (y = (y_me - range); y < (y_me + range + 5); y += AREA_SIZE)
		{
			if (have_scene_object(z, x, y, ITEM_TYPE, 1))
			{
				item = get_scene_object(z, x, y, ITEM_TYPE, 1);
				for (i = 0, size = sizeof(item); i < size; i++)
				{
					if (_thisItem = item[i])
					{
						tell_user(me, ECHO"Item: %s (%d, %d)", _thisItem->get_name(), get_x(_thisItem), get_y(_thisItem));
						GET->main(me,sprintf("%d %d", get_x(_thisItem), get_y(_thisItem)));
					}
				}
			}
		}
	}

	return 1;
} 

int autoRecall(object me) {
	object targetNpc, map, * member, * all = ({}), * npc = ({}), oldNpc;
	object* item, who, * nObj;

	int z, x, y, p, max_x, max_y, x_me, y_me, range = 10, d, walk;
	int i, size;
	int  x0, y0, dx, dy;

	int currentStatus = me->get_2("autoFarm");
	string cmd="";

	//Timeout
	if (me->get_save_2("autoFarm") - time() < 0) 
	{
		me->set_2("autoFarm", OFF);
		removeTitle(me);
		backHome(me);
	}

	if (currentStatus == ON) {
		remove_call_out("autoRecall");
		getItemAround(me);

		targetNpc = me->get_2("targetNPC");
		if (targetNpc && !targetNpc->is_die()) {
			me->start_fight(targetNpc);
			call_out("autoRecall", 3, me);
		}
		else {
			me->delete_2("targetNPC");
		}

		oldNpc = me->get_2("targetNPC");
		if (oldNpc && !oldNpc->is_die())
		{
			me->start_fight(targetNpc);
			me->to_front_xy(get_x(targetNpc), get_y(targetNpc));

			call_out("autoRecall", 3, me);
			return 1;
		}

		targetNpc = nearObject(me);
		if (targetNpc && !targetNpc->is_die()) 
		{
			z = get_z(targetNpc);
			x = get_x(targetNpc);
			y = get_y(targetNpc);

			p = get_valid_xy(z, x, y, IS_CHAR_BLOCK);
			if (p)
			{
				x = p / 1000;  y = p % 1000;
				me->add_to_scene(z, x, y, 3);
			}

			me->start_fight(targetNpc);
			me->set_2("targetNPC", targetNpc);
			call_out("autoRecall", 1, me);

			tell_user(me, ECHO"Tấn công mục tiêu: %s (%d, %d) ID %x", targetNpc->get_name(), get_x(targetNpc), get_y(targetNpc), getoid(targetNpc));
			return 1;
		}

		if(!targetNpc)
		{
			getItemAround(me);
			call_out("autoRecall", 3, me);
		}
	}

	return 1;
}

int main(object me, string arg)
{
	object map, * member, * all = ({}), * npc = ({});
	object* item, who, * nObj;
	string cName, titleAuto;

	int z, x, y, p, max_x, max_y;
	int i, size, color = 0;
	int type;

	if (arg) {

		if (arg == "auto") {
			me->set_2("autoFarm", ON);
			if (me->get_save_2("autoFarm") - time() > 0) {
				getItemAround(me);
				autoRecall(me);
				addTitle(me);
			}

			return 1;
		}

		if (arg == "offauto") {
			me->set_2("autoFarm", OFF);
			removeTitle(me);
			return 1;
		}

	}

	return 1;
}


int addTitle(object me)
{
	string cName;
	cName = TITLE_D->get_titlename(AUTO);
	send_user(me, "%c%s", '!', "" + cName);
	me->add_title(AUTO);
	me->show_title(AUTO);
	MAILBOX->sys_mail(me->get_id(), me->get_number(), HIR + cName);

	return 1;
}

int removeTitle(object me)
{
	string cName;
	me->set_title("", "");
	cName = TITLE_D->get_titlename(AUTO);
	me->hide_title(AUTO);
	me->delete_title(AUTO);
	MAILBOX->sys_mail(me->get_id(), me->get_number(), "Ngưng tự động đánh");

	return 1;
}

int backHome(object me)
{
	removeTitle(me);
	me->set_login_flag(2);
    set_invisible(me, 1);
    set_effect(me, EFFECT_USER_LOGIN, 4);
    me->add_to_scene(80, 293 + random(10), 186 + random(10));

	return 1;
}