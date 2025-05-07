
#include <ansi.h>
#include <equip.h>
#include <city.h>
#include <map.h>
#include <task.h>

void upgrade(object me, object who, int second)
{
	string name, * all, * names, file, name2;
	object orgnpc;
	mapping skls;
	int level, contrib, store, i, size, skill, level2;
	name = me->get_org_name();
	orgnpc = CITY_ZHOU->get_2(sprintf("org.%s", name));
	if (!objectp(orgnpc)) return;
	level = me->get_level();
	contrib = level * 12 / 10;
	store = 100000;
	if (store > 0)
	{
		skls = orgnpc->get_skill_dbase();
		size = sizeof(skls);
		all = ({ });
		names = sort_array(keys(skls), 1);
		for (i = 0; i < size; i++)
		{
			skill = to_int(to_int(names[i]));
			if (skill == 408 || skill == 409) continue;
			if (skill >= 430 && skill <= 438) continue;
			if (orgnpc->get_skill(skill) > 1)
			{
				all += ({ names[i] });
			}
		}
		if (sizeof(all) == 0) all = ({ "0109" });
		i = random(sizeof(all));
		skill = to_int(to_int(all[i]));
		level2 = orgnpc->get_skill(to_int(all[i]));
		orgnpc->improve_skill(to_int(all[i]), store);
		orgnpc->set_member_contribute(me->get_number(), orgnpc->get_member_contribute(me->get_number()) + contrib);
		orgnpc->save();
		if (load_object(file = SKILL->get_skill_file(skill)) && (file->is_basic_skill() || file->is_vita_skill()))
			name2 = file->get_name();
		else
			name2 = all[i];
		if (level2 < orgnpc->get_skill(to_int(all[i]))) {
			FAMILY_D->org_channel(name, 0, sprintf("Chúc mừng Bang phái của"HIR " %s "NOR "Độ thuần thục tăng %d điểm. "HIR " %s "NOR "nâng lên cấp %d .", name2, store, name2, orgnpc->get_skill(to_int(all[i]))));
			tell_user(who, sprintf("Chúc mừng Bang phái của"HIR " %s "NOR "Độ thuần thục tăng %d điểm. "HIR " %s "NOR "nâng lên cấp %d .", name2, store, name2, orgnpc->get_skill(to_int(all[i]))));
		}
		else
		{
			FAMILY_D->org_channel(name, 0, sprintf("Chúc mừng Bang phái %s của"HIR " %s "NOR "Độ thuần thục tăng %d điểm.", name, name2, store));
			tell_user(who, sprintf("Chúc mừng Bang phái %s của"HIR " %s "NOR "Độ thuần thục tăng %d điểm.", name,name2, store));
		}

		tell_user(who,HIG"Lượt %d", second);
	}

	second--;
	if (second > 0) {
		call_out("upgrade", 1, me, who, second);
	}
}

int main(object me, string arg)
{
	object who, who2;
	string* line, buff, chars, type, value;
	int i, j, size;

	if (is_player(me))
	{
		notify("Bạn không đủ quyền lực");
		return 1;
	}
	
	if (sscanf(arg, "%s %s %s", type, chars, value) == 3) {
		if (!(who = find_any_char(chars)))
		{
			notify("Không tìm thấy người này");
			return 1;
		}

		switch (type)
		{
		case "add":
			who2 = find_any_char(value);
			if (who && who2) {

				who2->set_org_position(ORG_MEMBER);
				who2->set_org_position(ORG_MASTER_2);
				who2->set_org_name(who->get_org_name());
				who2->set_org_time(time());

				tell_user(me, "joined %s", me->get_org_name());
				tell_user(who2, "joined %s", who2->get_org_name());
			}
			break;

		case "out":
			who2 = find_any_char(value);
			if (who && who2) {
				who2->set_org_position(ORG_MEMBER);
				who2->set_org_position(ORG_MASTER_2);
				who2->set_org_name("");
				tell_user(me, "removed org");
				tell_user(who2, "removed org");
			}
			break;
		case "up":
			if (who) {
				tell_user(me, "upgrading...");
				for (i = 0; i < to_int(value); i++) {
				}
				upgrade(who, me, to_int(value));

				tell_user(me, "upgraded");
			}
			break;
		}

		
	}

	return 1;
}
