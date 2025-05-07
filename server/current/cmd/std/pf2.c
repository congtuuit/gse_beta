
#include <skill.h>
#include <action.h>
#include <effect.h>

// 函数：命令处理
int main(object me, string arg)
{
	object file, what;
	string id, item;
	int busy, pf, x, y, which;

	//   if (me->get_ride()) return 1;

	//if (!is_god(me) && gone_time(me->get_time("pf2")) < 30)
	//{
	//	//me->set_time("pf2", time());
	//	notify("Chưa thể sử dụng lại lúc này");
	//	return 1;
	//}


	if (me->is_store_open())
	{
		notify("Bạn thiết lập một gian hàng, không bị phân tâm。");
		return 1;
	}

	if (busy = get_effect(me, EFFECT_CHAR_BUSY))
	{
		notify("Bạn còn phải bận %d giây", busy);
		return 1;
	}


	if (get_effect(me, EFFECT_CHAR_FAINT)
		|| get_effect(me, EFFECT_CHAR_FAINT_2)
		|| get_effect(me, EFFECT_SLEEP)
		|| get_effect(me, EFFECT_MAGIC_4243)
		|| get_effect(me, EFFECT_CHAR_FREEZE)
		|| get_effect(me, EFFECT_CHAR_DREAM_1)
		|| get_effect(me, EFFECT_CHAR_DREAM)) return 1;

	if (!arg) return 1;

	if (me->get_char_action() != DEFAULT_ACT) me->set_char_action(DEFAULT_ACT);

	if (sscanf(arg, "%d %d,%d", pf, x, y) == 3)
	{
		if ((file = load_object(SKILL->get_perform_file(pf)))
			&& file->get_perform_type() != ON_ME_7)
			file->main(me, 0, x, y, "");
	}
	else if (sscanf(arg, "%d (%d)", pf, which) == 2)
	{
		if ((file = load_object(SKILL->get_perform_file(pf)))
			&& file->get_perform_type() == ON_ITEM_7
			&& (what = number_present(me, which, 1, MAX_CARRY)))
			file->main(me, what, 0, 0, "");
	}
	else if (sscanf(arg, "%d %s %d", pf, id, which) == 3)
	{
		if ((file = load_object(SKILL->get_perform_file(pf)))
			&& file->get_perform_type() == ON_ITEM_8
			&& (what = find_char(id))
			&& number_present(what, which, 1, MAX_CARRY))
			file->main(me, what, 0, 0, sprintf("%d", which));
	}
	else if (sscanf(arg, "%d %s", pf, arg) == 2)
	{
		if ((file = load_object(SKILL->get_perform_file(pf)))
			&& (file->get_perform_type() == ON_CHAR_7 || file->get_perform_type() == ON_TALISMAN)
			&& (what = find_char(arg))) {

			if (!inside_screen_2(me, what) && pf == 900)
			{
				if (/*!is_god(me) && */gone_time(me->get_time("pf2")) < 120)
				{
					notify("Tái sử dụng sau %d giây.", 121 - gone_time(me->get_time("pf2")));
					return 1;
				}

				notify("Bạn cách %s quá xa rồi.", what->get_name());
				return 1;
			}

			file->main(me, what, 0, 0, "");
			me->set_time("pf2", time());

		}

	}
	else if (sscanf(arg, "%d.%s", pf, arg) == 2)
	{
		if ((file = load_object(SKILL->get_perform_file(pf)))
			&& (file->get_perform_type() == ON_ME_7 || file->get_perform_type() == ON_TALISMAN))
			file->main(me, 0, 0, 0, arg);
	}
	else if (pf = to_int(arg))
	{
		/*if (pf == 98) {
			return 1;
		}*/

		if ((file = load_object(SKILL->get_perform_file(pf)))
			&& (file->get_perform_type() == ON_ME_7 || file->get_perform_type() == ON_TALISMAN))
			file->main(me, 0, 0, 0, "");
	}


	return 1;
}
