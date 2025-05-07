/***********
套装处理模块
*************/
#include <effect.h>
#include <skill.h>
#include <ansi.h>
#include <equip.h>

void SAVE_BINARY() { }
void remove_suit_effect(object who, string name, int amount);
void suit_effect(object who, string name, int amount);

void create()
{

}
void remove_suit_equip(object who)
{
	int i, size, j, count;
	string* nTmp;
	mapping mpTmp;

	mpTmp = who->get_2("suit_equip");
	if (!mapp(mpTmp))
		return;
	nTmp = keys(mpTmp);
	for (i = 0, size = sizeof(mpTmp); i < size; i++)
	{
		count = mpTmp[nTmp[i]]["count"];
		for (j = 2; j <= count; j++)
			remove_suit_effect(who, nTmp[i], j);
	}
}
void check_suit_equip(object who)
{
	int i, size, j, count, max;
	object* nEquip, oEquip, * inv;
	mapping mpTmp;
	string* nTmp, desc;

	remove_suit_equip(who);
	nEquip = who->get_all_equip();
	nEquip -= ({ 0 });
	who->delete_2("suit_equip");
	for (i = 0, size = sizeof(nEquip); i < size; i++)
	{
		oEquip = nEquip[i];
		if (oEquip->is_suit())
		{
			who->add_2(sprintf("suit_equip.%s.count", oEquip->get_suit_name()), 1);
			who->set_2(sprintf("suit_equip.%s.equip.%s", oEquip->get_suit_name(), oEquip->get_name()), 1);
		}
	}
	mpTmp = who->get_2("suit_equip");
	if (!mapp(mpTmp))
		return;
	nTmp = keys(mpTmp);
	for (i = 0, size = sizeof(mpTmp); i < size; i++)
	{
		count = mpTmp[nTmp[i]]["count"];
		for (j = 2; j <= count; j++)
			suit_effect(who, nTmp[i], j);
		if (count > max)
			max = count;
	}
	if (max >= 2)
		set_effect_2(who, EFFECT_USER_SUIT, 1, 5);

	for (i = 1; i <= HAND_TYPE - HEAD_TYPE + 1; i++)	//已经装备的物品
	{
		"cmd/base/desc"->main(who, sprintf("%d", i));
	}
	inv = all_inventory(who, 0, 0);
	for (i = 0, size = sizeof(inv); i < size; i++)
	{
		if (!objectp(inv[i]) || inv[i]->is_suit() != 1)
			continue;
		send_user(who, "%c%d%c", 0x31, getoid(inv[i]), 0);
	}
}

void suit_effect(object who, string name, int amount)
{
	int hp;
	object npc;

	switch (name)
	{

		case "Cự Tương":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->set_2(sprintf("suit_sec.%s.hp.add", name), 5);
				who->set_2(sprintf("suit_sec.%s.hp.time", name), time());
				who->set_2(sprintf("suit_sec.%s.hp.interval", name), 5);
				break;
			case 3:
				who->set_2(sprintf("suit_effect.ap.%s", name), 80);
				USER_ENERGY_D->count_ap(who);
				break;
			case 4:
				who->set_2(sprintf("suit_effect.pp.%s", name), 100);
				USER_ENERGY_D->count_pp(who);
				break;
			case 5:
				who->set_2("suit_effect.double1", 30);
				who->set_2("suit_effect.double2", 50);
				break;
			}
			break;
		}

		case "Tích Long":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->set_2(sprintf("suit_sec.%s.hp.add", name), 100);
				who->set_2(sprintf("suit_sec.%s.hp.time", name), time());
				who->set_2(sprintf("suit_sec.%s.hp.interval", name), 5);
				break;
			case 3:
				who->set_2(sprintf("suit_effect.ap.%s", name), 160);
				USER_ENERGY_D->count_ap(who);
				break;
			case 4:
				who->set_2(sprintf("suit_effect.pp.%s", name), 160);
				USER_ENERGY_D->count_pp(who);
				break;
			case 5:
				who->set_2("suit_effect.double1", 50);
				who->set_2("suit_effect.double2", 80);
				break;
			}
			break;
		}
		case "Mãnh Hổ":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->set_2(sprintf("suit_sec.%s.mp.add", name), 5);
				who->set_2(sprintf("suit_sec.%s.mp.time", name), time());
				who->set_2(sprintf("suit_sec.%s.mp.interval", name), 5);
				break;
			case 3:
				who->set_2(sprintf("suit_effect.maxhp.%s", name), 100);
				USER_ENERGY_D->count_max_hp(who);
				break;
			case 4:
				who->set_2(sprintf("suit_effect.ap.%s", name), 80);
				who->set_2(sprintf("suit_effect.cp.%s", name), 80);
				USER_ENERGY_D->count_ap(who);
				USER_ENERGY_D->count_cp(who);
				break;
			case 5:
				who->set_2("suit_effect.double_rate", 200);
				USER_ENERGY_D->count_hit_rate(who);
				break;
			}
			break;
		}
		case "Thái Dương":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->set_2(sprintf("suit_sec.%s.mp.add", name), 100);
				who->set_2(sprintf("suit_sec.%s.mp.time", name), time());
				who->set_2(sprintf("suit_sec.%s.mp.interval", name), 5);
				break;
			case 3:
				who->set_2(sprintf("suit_effect.maxhp.%s", name), 200);
				USER_ENERGY_D->count_max_hp(who);
				break;
			case 4:
				who->set_2(sprintf("suit_effect.ap.%s", name), 160);
				who->set_2(sprintf("suit_effect.cp.%s", name), 160);
				USER_ENERGY_D->count_ap(who);
				USER_ENERGY_D->count_cp(who);
				break;
			case 5:
				who->set_2("suit_effect.double_rate", 400);
				USER_ENERGY_D->count_hit_rate(who);
				break;
			}
			break;
		}
		case "Cuồng Sư":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->set_2("suit_effect.no_drop", 1);
				break;
			case 3:
				who->set_2(sprintf("suit_effect.ap.%s", name), 80);
				USER_ENERGY_D->count_ap(who);
				break;
			case 4:
				who->set_2(sprintf("suit_effect.pp.%s", name), 60);
				USER_ENERGY_D->count_pp(who);
				break;
			case 5:
				who->set_2("suit_effect.double_rate", 200);
				USER_ENERGY_D->count_hit_rate(who);
				break;
			}
			break;
		}
		case "Lôi Quang":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->set_2("suit_effect.no_drop", 1);
				break;
			case 3:
				who->set_2(sprintf("suit_effect.ap.%s", name), 160);
				USER_ENERGY_D->count_ap(who);
				break;
			case 4:
				who->set_2(sprintf("suit_effect.pp.%s", name), 120);
				USER_ENERGY_D->count_pp(who);
				break;
			case 5:
				who->set_2("suit_effect.double_rate", 400);
				USER_ENERGY_D->count_hit_rate(who);
				break;
			}
			break;
		}
		case "Lạp Báo":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->set_2("suit_effect.poison", 30);
				break;
			case 3:
				who->set_2(sprintf("suit_effect.ap.%s", name), 40);
				USER_ENERGY_D->count_ap(who);
				break;
			case 4:
				who->set_2("suit_effect.dodge", 4);
				break;
			case 5:
				who->set_2("suit_effect.double_rate", 200);
				USER_ENERGY_D->count_hit_rate(who);
				break;
			}
			break;
		}
		case "Toàn Phong":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->set_2("suit_effect.poison", 60);
				break;
			case 3:
				who->set_2(sprintf("suit_effect.ap.%s", name), 80);
				USER_ENERGY_D->count_ap(who);
				break;
			case 4:
				who->set_2("suit_effect.dodge", 6);
				break;
			case 5:
				who->set_2("suit_effect.double_rate", 400);
				USER_ENERGY_D->count_hit_rate(who);
				break;
			}
			break;
		}
		case "Bạch Lang":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->set_2(sprintf("suit_sec.%s.mp.add", name), 5);
				who->set_2(sprintf("suit_sec.%s.mp.time", name), time());
				who->set_2(sprintf("suit_sec.%s.mp.interval", name), 5);
				break;
			case 3:
				who->set_2(sprintf("suit_effect.dp.%s", name), 60);
				USER_ENERGY_D->count_dp(who);
				break;
			case 4:
				who->set_2(sprintf("suit_effect.cp.%s", name), 80);
				USER_ENERGY_D->count_cp(who);
				break;
			case 5:
				who->set_2("suit_effect.summon", 1);
				npc = who->get("soldier");
				if (npc && !npc->get("suit_effect"))
				{
					npc->add_max_hp((hp = npc->get_max_hp() / 10));
					npc->set("suit_effect", hp);
					npc->add_dp(50);
				}
				break;
			}
			break;
		}
		case "Chiến Lang":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->set_2(sprintf("suit_sec.%s.mp.add", name), 100);
				who->set_2(sprintf("suit_sec.%s.mp.time", name), time());
				who->set_2(sprintf("suit_sec.%s.mp.interval", name), 5);
				break;
			case 3:
				who->set_2(sprintf("suit_effect.dp.%s", name), 240);
				USER_ENERGY_D->count_dp(who);
				break;
			case 4:
				who->set_2(sprintf("suit_effect.cp.%s", name), 320);
				USER_ENERGY_D->count_cp(who);
				break;
			case 5:
				who->set_2("suit_effect.summon", 1);
				npc = who->get("soldier");
				if (npc && !npc->get("suit_effect"))
				{
					npc->add_max_hp((hp = npc->get_max_hp() / 30));
					npc->set("suit_effect", hp);
					npc->add_dp(200);
				}
				break;
			}
			break;
		}
		case "Tuyết Điêu":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->set_2(sprintf("suit_sec.%s.mp.add", name), 5);
				who->set_2(sprintf("suit_sec.%s.mp.time", name), time());
				who->set_2(sprintf("suit_sec.%s.mp.interval", name), 5);
				break;
			case 3:
				who->set_2("suit_effect.damage2", 10);
				break;

			case 4:
				who->set_2(sprintf("suit_effect.maxmp.%s", name), 60);
				USER_ENERGY_D->count_max_mp(who);
				break;
			case 5:
				who->set_2("suit_effect.damage_rate1", 5);
				who->set_2("suit_effect.damage_rate3", 5);
				break;
			}
			break;
		}
		case "Liệp Ưng":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->set_2(sprintf("suit_sec.%s.mp.add", name), 80);
				who->set_2(sprintf("suit_sec.%s.mp.time", name), time());
				who->set_2(sprintf("suit_sec.%s.mp.interval", name), 5);
				break;
			case 3:
				who->set_2("suit_effect.damage2", 50);
				break;

			case 4:
				who->set_2(sprintf("suit_effect.maxmp.%s", name), 100);
				USER_ENERGY_D->count_max_mp(who);
				break;
			case 5:
				who->set_2("suit_effect.damage_rate1", 5);
				who->set_2("suit_effect.damage_rate3", 5);
				break;
			}
			break;
		}
		case "Linh Hồ":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->set_2(sprintf("suit_sec.%s.mp.add", name), 10);
				who->set_2(sprintf("suit_sec.%s.mp.time", name), time());
				who->set_2(sprintf("suit_sec.%s.mp.interval", name), 5);
				break;
			case 3:
				who->set_2(sprintf("suit_effect.dp.%s", name), 60);
				USER_ENERGY_D->count_dp(who);
				break;
			case 4:
				who->set_2(sprintf("suit_effect.maxhp.%s", name), 100);
				USER_ENERGY_D->count_max_hp(who);
				break;
			case 5:
				who->set_2("suit_effect.damage_rand2", 33);
				break;
			}
			break;
		}
		case "Linh Lộc":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->set_2(sprintf("suit_sec.%s.mp.add", name), 80);
				who->set_2(sprintf("suit_sec.%s.mp.time", name), time());
				who->set_2(sprintf("suit_sec.%s.mp.interval", name), 5);
				break;
			case 3:
				who->set_2(sprintf("suit_effect.dp.%s", name), 120);
				USER_ENERGY_D->count_dp(who);
				break;
			case 4:
				/*who->set_2(sprintf("suit_effect.maxhp.%s",name),300);
				USER_ENERGY_D->count_max_hp(who);*/

				who->set_2(sprintf("suit_effect.cp.%s", name), 160);
				USER_ENERGY_D->count_max_hp(who);
				break;
			case 5:
				who->set_2("suit_effect.damage_rand2", 100);
				break;
			}
			break;
		}

		//Huyet long suit
		case "Huyết Long CL":
			switch (amount)
			{
			default:
				break;
			case 2:
				who->set_2(sprintf("suit_sec.%s.mp.add", name), 5);
				who->set_2(sprintf("suit_sec.%s.mp.time", name), time());
				who->set_2(sprintf("suit_sec.%s.mp.interval", name), 100);
				break;
			case 3:
				who->set_2("suit_effect.damage2", 120);
				break;

			case 4:
				who->set_2(sprintf("suit_effect.maxmp.%s", name), 200);
				USER_ENERGY_D->count_max_mp(who);
				break;
			case 5:
				who->set_2("suit_effect.damage_rate1", 6);
				who->set_2("suit_effect.damage_rate3", 6);
				break;
			}
		break;

		case "Huyết Long CVQ":
			switch (amount)
			{
				default:
					break;
				case 2:
					who->set_2("suit_effect.no_drop", 1);
					break;
				case 3:
					who->set_2(sprintf("suit_effect.ap.%s", name), 250);
					USER_ENERGY_D->count_ap(who);
					break;
				case 4:
					who->set_2(sprintf("suit_effect.pp.%s", name), 150);
					USER_ENERGY_D->count_pp(who);
					break;
				case 5:
					who->set_2("suit_effect.double_rate", 500);
					USER_ENERGY_D->count_hit_rate(who);
					break;
			}
		break;

		case "Huyết Long ĐHN":
			switch (amount)
			{
			default:
				break;
			case 2:
				who->set_2(sprintf("suit_sec.%s.hp.add", name), 100);
				who->set_2(sprintf("suit_sec.%s.hp.time", name), time());
				who->set_2(sprintf("suit_sec.%s.hp.interval", name), 5);
				break;
			case 3:
				who->set_2(sprintf("suit_effect.ap.%s", name), 240);
				USER_ENERGY_D->count_ap(who);
				break;
			case 4:
				who->set_2(sprintf("suit_effect.pp.%s", name), 200);
				USER_ENERGY_D->count_pp(who);
				break;
			case 5:
				who->set_2("suit_effect.double1", 50);
				who->set_2("suit_effect.double2", 90);
				break;
			}
		break;

		case "Huyết Long ĐM":
			switch (amount)
			{
				default:
					break;
				case 2:
					who->set_2("suit_effect.poison", 100);
					break;
				case 3:
					who->set_2(sprintf("suit_effect.ap.%s", name), 120);
					USER_ENERGY_D->count_ap(who);
					break;
				case 4:
					who->set_2("suit_effect.dodge", 10);
					break;
				case 5:
					who->set_2("suit_effect.double_rate", 500);
					USER_ENERGY_D->count_hit_rate(who);
					break;
				}
		break;

		case "Huyết Long MS":
			switch (amount)
			{
			default:
				break;
			case 2:
				who->set_2(sprintf("suit_sec.%s.mp.add", name), 100);
				who->set_2(sprintf("suit_sec.%s.mp.time", name), time());
				who->set_2(sprintf("suit_sec.%s.mp.interval", name), 5);
				break;
			case 3:
				who->set_2(sprintf("suit_effect.dp.%s", name), 240);
				USER_ENERGY_D->count_dp(who);
				break;
			case 4:
				who->set_2(sprintf("suit_effect.cp.%s", name), 350);
				USER_ENERGY_D->count_cp(who);
				break;
			case 5:
				who->set_2("suit_effect.summon", 1);
				npc = who->get("soldier");
				if (npc && !npc->get("suit_effect"))
				{
					npc->add_max_hp((hp = npc->get_max_hp() / 30));
					npc->set("suit_effect", hp);
					npc->add_dp(500);
				}
				break;
			}
		break;
		
		case "Huyết Long TS":
			switch (amount)
			{
			default:
				break;
			case 2:
				who->set_2(sprintf("suit_sec.%s.mp.add", name), 50);
				who->set_2(sprintf("suit_sec.%s.mp.time", name), time());
				who->set_2(sprintf("suit_sec.%s.mp.interval", name), 5);
				break;
			case 3:
				who->set_2(sprintf("suit_effect.maxhp.%s", name), 300);
				USER_ENERGY_D->count_max_hp(who);
				break;
			case 4:
				who->set_2(sprintf("suit_effect.ap.%s", name), 160);
				who->set_2(sprintf("suit_effect.cp.%s", name), 160);
				USER_ENERGY_D->count_ap(who);
				USER_ENERGY_D->count_cp(who);
				break;
			case 5:
				who->set_2("suit_effect.double_rate", 400);
				USER_ENERGY_D->count_hit_rate(who);
				break;
			}
		break;

		case "Huyết Long VMC":
			switch (amount)
			{
			default:
				break;
			case 2:
				who->set_2(sprintf("suit_sec.%s.mp.add", name), 80);
				who->set_2(sprintf("suit_sec.%s.mp.time", name), time());
				who->set_2(sprintf("suit_sec.%s.mp.interval", name), 5);
				break;
			case 3:
				who->set_2(sprintf("suit_effect.dp.%s", name), 300);
				USER_ENERGY_D->count_dp(who);
				break;
			case 4:
				who->set_2(sprintf("suit_effect.maxhp.%s",name),300);
				USER_ENERGY_D->count_max_hp(who);
				break;
			case 5:
				who->set_2("suit_effect.damage_rand2", 200);
				break;
			}
		break;
	}
}

void remove_suit_effect(object who, string name, int amount)
{
	int hp;
	object npc;

	switch (name)
	{
		case "Cự Tương":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2(sprintf("suit_sec.%s", name));
				break;
			case 3:
				who->delete_2(sprintf("suit_effect.ap.%s", name));
				USER_ENERGY_D->count_ap(who);
				break;
			case 4:
				who->delete_2(sprintf("suit_effect.pp.%s", name));
				USER_ENERGY_D->count_pp(who);
				break;
			case 5:
				who->delete_2("suit_effect.double1", 30);
				who->delete_2("suit_effect.double2", 50);
				break;
			}
		}
		case "Tích Long":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2(sprintf("suit_sec.%s", name));
				break;
			case 3:
				who->delete_2(sprintf("suit_effect.ap.%s", name));
				USER_ENERGY_D->count_ap(who);
				break;
			case 4:
				who->delete_2(sprintf("suit_effect.pp.%s", name));
				USER_ENERGY_D->count_pp(who);
				break;
			case 5:
				who->delete_2("suit_effect.double1", 60);
				who->delete_2("suit_effect.double2", 100);
				break;
			}
		}
		case "Mãnh Hổ":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2(sprintf("suit_sec.%s", name));
				break;
			case 3:
				who->delete_2(sprintf("suit_effect.maxhp.%s", name));
				USER_ENERGY_D->count_max_hp(who);
				break;
			case 4:
				who->delete_2(sprintf("suit_effect.ap.%s", name));
				who->delete_2(sprintf("suit_effect.cp.%s", name));
				USER_ENERGY_D->count_ap(who);
				USER_ENERGY_D->count_cp(who);
				break;
			case 5:
				who->delete_2("suit_effect.double_rate");
				USER_ENERGY_D->count_hit_rate(who);
				break;
			}
			break;
		}
		case "Thái Dương":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2(sprintf("suit_sec.%s", name));
				break;
			case 3:
				who->delete_2(sprintf("suit_effect.maxhp.%s", name));
				USER_ENERGY_D->count_max_hp(who);
				break;
			case 4:
				who->delete_2(sprintf("suit_effect.ap.%s", name));
				who->delete_2(sprintf("suit_effect.cp.%s", name));
				USER_ENERGY_D->count_ap(who);
				USER_ENERGY_D->count_cp(who);
				break;
			case 5:
				who->delete_2("suit_effect.double_rate");
				USER_ENERGY_D->count_hit_rate(who);
				break;
			}
			break;
		}
		case "Cuồng Sư":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2("suit_effect.no_drop");
				break;
			case 3:
				who->delete_2(sprintf("suit_effect.ap.%s", name));
				USER_ENERGY_D->count_ap(who);
				break;
			case 4:
				who->delete_2(sprintf("suit_effect.pp.%s", name));
				USER_ENERGY_D->count_pp(who);
				break;
			case 5:
				who->delete_2("suit_effect.double_rate");
				USER_ENERGY_D->count_hit_rate(who);
				break;
			}
			break;
		}
		case "Lôi Quang":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2("suit_effect.no_drop");
				break;
			case 3:
				who->delete_2(sprintf("suit_effect.ap.%s", name));
				USER_ENERGY_D->count_ap(who);
				break;
			case 4:
				who->delete_2(sprintf("suit_effect.pp.%s", name));
				USER_ENERGY_D->count_pp(who);
				break;
			case 5:
				who->delete_2("suit_effect.double_rate");
				USER_ENERGY_D->count_hit_rate(who);
				break;
			}
			break;
		}
		case "Lạp Báo":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2("suit_effect.poison");
				break;
			case 3:
				who->delete_2(sprintf("suit_effect.ap.%s", name));
				USER_ENERGY_D->count_ap(who);
				break;
			case 4:
				who->delete_2("suit_effect.dodge");
				break;
			case 5:
				who->delete_2("suit_effect.double_rate");
				USER_ENERGY_D->count_hit_rate(who);
				break;
			}
			break;
		}
		case "Toàn Phong":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2("suit_effect.poison");
				break;
			case 3:
				who->delete_2(sprintf("suit_effect.ap.%s", name));
				USER_ENERGY_D->count_ap(who);
				break;
			case 4:
				who->delete_2("suit_effect.dodge");
				break;
			case 5:
				who->delete_2("suit_effect.double_rate");
				USER_ENERGY_D->count_hit_rate(who);
				break;
			}
			break;
		}
		case "Bạch Lang":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2(sprintf("suit_sec.%s", name));
				break;
			case 3:
				who->delete_2(sprintf("suit_effect.dp.%s", name));
				USER_ENERGY_D->count_dp(who);
				break;
			case 4:
				who->delete_2(sprintf("suit_effect.cp.%s", name));
				USER_ENERGY_D->count_cp(who);
				break;
			case 5:
				who->delete_2("suit_effect.summon");
				npc = who->get("soldier");
				if (npc && (hp = npc->get("suit_effect")))
				{
					npc->delete("suit_effect");
					npc->add_max_hp(-hp);
					npc->add_dp(-50);
				}
				break;
			}
			break;
		}
		case "Chiến Lang":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2(sprintf("suit_sec.%s", name));
				break;
			case 3:
				who->delete_2(sprintf("suit_effect.dp.%s", name));
				USER_ENERGY_D->count_dp(who);
				break;
			case 4:
				who->delete_2(sprintf("suit_effect.cp.%s", name));
				USER_ENERGY_D->count_cp(who);
				break;
			case 5:
				who->delete_2("suit_effect.summon");
				npc = who->get("soldier");
				if (npc && (hp = npc->get("suit_effect")))
				{
					npc->delete("suit_effect");
					npc->add_max_hp(-hp);
					npc->add_dp(-200);
				}
				break;
			}
			break;
		}
		case "Tuyết Điêu":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2(sprintf("suit_sec.%s", name));
				break;
			case 3:
				who->delete_2("suit_effect.damage2");
				break;

			case 4:
				who->delete_2(sprintf("suit_effect.maxmp.%s", name));
				USER_ENERGY_D->count_max_mp(who);
				break;
			case 5:
				who->delete_2("suit_effect.damage_rate1");
				who->delete_2("suit_effect.damage_rate3");
				break;
			}
			break;
		}
		case "Liệp Ưng":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2(sprintf("suit_sec.%s", name));
				break;
			case 3:
				who->delete_2("suit_effect.damage2");
				break;

			case 4:
				who->delete_2(sprintf("suit_effect.maxmp.%s", name));
				USER_ENERGY_D->count_max_mp(who);
				break;
			case 5:
				who->delete_2("suit_effect.damage_rate1");
				who->delete_2("suit_effect.damage_rate3");
				break;
			}
			break;
		}
		case "Linh Hồ":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2(sprintf("suit_sec.%s", name));
				break;
			case 3:
				who->delete_2(sprintf("suit_effect.dp.%s", name));
				USER_ENERGY_D->count_dp(who);
				break;
			case 4:
				who->delete_2(sprintf("suit_effect.maxhp.%s", name));
				USER_ENERGY_D->count_max_hp(who);
				break;
			case 5:
				who->delete_2("suit_effect.damage_rand2");
				break;
			}
			break;
		}
		case "Linh Lộc":
		{
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2(sprintf("suit_sec.%s", name));
				break;
			case 3:
				who->delete_2(sprintf("suit_effect.dp.%s", name));
				USER_ENERGY_D->count_dp(who);
				break;
			case 4:
				who->delete_2(sprintf("suit_effect.maxhp.%s", name));
				USER_ENERGY_D->count_max_hp(who);
				break;
			case 5:
				who->delete_2("suit_effect.damage_rand2");
				break;
			}
			break;
		}


		//Huyet long suit
		case "Huyết Long CL":
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2(sprintf("suit_sec.%s", name));
				
				break;
			case 3:
				who->delete_2("suit_effect.damage2");
				break;

			case 4:
				who->delete_2(sprintf("suit_effect.maxmp.%s", name));
				USER_ENERGY_D->count_max_mp(who);
				break;
			case 5:
				who->delete_2("suit_effect.damage_rate1");
				who->delete_2("suit_effect.damage_rate3");
				break;
			}
			break;

		case "Huyết Long CVQ":
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2("suit_effect.no_drop");
				break;
			case 3:
				who->delete_2(sprintf("suit_effect.ap.%s", name));
				USER_ENERGY_D->count_ap(who);
				break;
			case 4:
				who->delete_2(sprintf("suit_effect.pp.%s", name));
				USER_ENERGY_D->count_pp(who);
				break;
			case 5:
				who->delete_2("suit_effect.double_rate");
				USER_ENERGY_D->count_hit_rate(who);
				break;
			}
			break;

		case "Huyết Long ĐHN":
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2(sprintf("suit_sec.%s", name));
				break;
			case 3:
				who->delete_2(sprintf("suit_effect.ap.%s", name));
				USER_ENERGY_D->count_ap(who);
				break;
			case 4:
				who->delete_2(sprintf("suit_effect.pp.%s", name));
				USER_ENERGY_D->count_pp(who);
				break;
			case 5:
				who->delete_2("suit_effect.double1");
				who->delete_2("suit_effect.double2");
				break;
			}
			break;

		case "Huyết Long ĐM":
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2("suit_effect.poison");
				break;
			case 3:
				who->delete_2(sprintf("suit_effect.ap.%s", name));
				USER_ENERGY_D->count_ap(who);
				break;
			case 4:
				who->delete_2("suit_effect.dodge");
				break;
			case 5:
				who->delete_2("suit_effect.double_rate");
				USER_ENERGY_D->count_hit_rate(who);
				break;
			}
			break;

		case "Huyết Long MS":
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2(sprintf("suit_sec.%s", name));
				break;
			case 3:
				who->delete_2(sprintf("suit_effect.dp.%s", name));
				USER_ENERGY_D->count_dp(who);
				break;
			case 4:
				who->delete_2(sprintf("suit_effect.cp.%s", name));
				USER_ENERGY_D->count_cp(who);
				break;
			case 5:
				who->delete_2("suit_effect.summon");
				break;
			}
			break;

		case "Huyết Long TS":
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2(sprintf("suit_sec.%s", name));
				break;
			case 3:
				who->delete_2(sprintf("suit_effect.maxhp.%s", name));
				USER_ENERGY_D->count_max_hp(who);
				break;
			case 4:
				who->delete_2(sprintf("suit_effect.ap.%s", name));
				who->delete_2(sprintf("suit_effect.cp.%s", name));
				USER_ENERGY_D->count_ap(who);
				USER_ENERGY_D->count_cp(who);
				break;
			case 5:
				who->delete_2("suit_effect.double_rate");
				USER_ENERGY_D->count_hit_rate(who);
				break;
			}
			break;

		case "Huyết Long VMC":
			switch (amount)
			{
			default:
				break;
			case 2:
				who->delete_2(sprintf("suit_sec.%s", name));
				break;
			case 3:
				who->delete_2(sprintf("suit_effect.dp.%s", name));
				USER_ENERGY_D->count_dp(who);
				break;
			case 4:
				who->delete_2(sprintf("suit_effect.maxhp.%s", name));
				USER_ENERGY_D->count_max_hp(who);
				break;
			case 5:
				who->delete_2("suit_effect.damage_rand2");
				break;
			}
			break;
	}

}

void into_effect(object who)
{
	int i, size, iTime;
	string* nTmp;

	if (!mapp(who->get_2("suit_sec")))
		return;
	set_effect_2(who, EFFECT_USER_SUIT, 1, 5);
	nTmp = keys(who->get_2("suit_sec"));
	size = sizeof(nTmp);
	if (!size)
		who->delete_2("suit_sec");
	iTime = time();
	for (i = 0; i < size; i++)
	{
		if (mapp(who->get_2(sprintf("suit_sec.%s.hp", nTmp[i]))) && gone_time(who->get_2(sprintf("suit_sec.%s.hp.time", nTmp[i]))) >= who->get_2(sprintf("suit_sec.%s.hp.interval", nTmp[i])))
		{
			who->add_hp(who->get_2(sprintf("suit_sec.%s.hp.add", nTmp[i])));
			who->set_2(sprintf("suit_sec.%s.hp.time", nTmp[i]), iTime);
		}
		if (mapp(who->get_2(sprintf("suit_sec.%s.mp", nTmp[i]))) && gone_time(who->get_2(sprintf("suit_sec.%s.mp.time", nTmp[i]))) >= who->get_2(sprintf("suit_sec.%s.mp.interval", nTmp[i])))
		{
			who->add_mp(who->get_2(sprintf("suit_sec.%s.mp.add", nTmp[i])));
			who->set_2(sprintf("suit_sec.%s.mp.time", nTmp[i]), iTime);
		}
	}
}

string get_suit_desc(object who, object oEquip)
{
	string ret = "", name;
	int count;
	object owner;

	owner = oEquip->get_owner();
	if (owner && owner->is_user())
		who = owner;
	if (!who)
		return oEquip->get_suit_desc();
	name = oEquip->get_suit_name();
	count = who->get_2(sprintf("suit_equip.%s.count", name));
	switch (name)
	{
		default:
			break;
		case "Cự tương":
		case "Cự Tương":
			ret += sprintf("%s Cự Tương (%d/5)\n", count >= 2 ? PPM : WHT, count);
			ret += sprintf("%s Cự Tương Đầu Khôi\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Cự Tương Đầu Khôi")) ? PPM : WHT);
			ret += sprintf("%s Cự Tương Khôi Giáp\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Cự Tương Khôi Giáp")) ? PPM : WHT);
			ret += sprintf("%s Cự Tương Hạng Liên\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Cự Tương Hạng Liên")) ? PPM : WHT);
			ret += sprintf("%s Cự Tương Yêu Đới\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Cự Tương Yêu Đới")) ? PPM : WHT);
			ret += sprintf("%s Cự Tương Chi Ngoa\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Cự Tương Chi Ngoa")) ? PPM : WHT);
			ret += sprintf("%s 2 Món： Mỗi 5 giây hồi phục 5 điểm Khí Huyết\n", count >= 2 ? PPM : WHT);
			ret += sprintf("%s 3 Món： Ngoại công Tăng thêm 80 điểm\n", count >= 3 ? PPM : WHT);
			ret += sprintf("%s 4 Món： Nội kháng Tăng thêm 100 điểm\n", count >= 4 ? PPM : WHT);
			ret += sprintf("%s 5 Món： Giảm sát thương 30％—50％ khi bị đánh bạo kích\n", count >= 5 ? PPM : WHT);
			break;
			//case "Đằng Long":
			//	ret += sprintf("%s Đằng Long (%d/5)\n",count>=2?PPM:WHT,count);
			////	ret += sprintf("%s Đằng Long Đầu Khôi\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"Đằng Long Đầu Khôi"))?PPM:WHT);
			////	ret += sprintf("%s Đằng Long Chiến Bào\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"Đằng Long Chiến Bào"))?PPM:WHT);
			////	ret += sprintf("%s Đằng Long Hạng Liên\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"Đằng Long Hạng Liên"))?PPM:WHT);
			////	ret += sprintf("%s Đằng Long Yêu Đới\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"Đằng Long Yêu Đới"))?PPM:WHT);
			////	ret += sprintf("%s Đằng Long Chi Ngoa\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"Đằng Long Chi Ngoa"))?PPM:WHT);
			//	ret += sprintf("%s 2 món : 5 giây hồi 100 Khí Huyết\n",count>=2?PPM:WHT);
			//	ret += sprintf("%s 3 món : Tăng 160 Ngoại Công\n",count>=3?PPM:WHT);
			//	ret += sprintf("%s 4 món : Tăng 200 Nội Kháng\n",count>=4?PPM:WHT);
			//	ret += sprintf("%s 5 món : giảm sát thương 40%%—60%% bạo kích\n",count>=5?PPM:WHT);
			//	break;
		case "Tích long":
		case "Tích Long":
			ret += sprintf(" %s Tích Long (%d/5)\n", count >= 2 ? PPM : WHT, count);
			ret += sprintf(" %s Mũ Tích Long\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Mũ Tích Long")) ? PPM : WHT);
			ret += sprintf(" %s Tích Long Giáp\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Tích Long Giáp")) ? PPM : WHT);
			ret += sprintf(" %s Tích Long Hạng Liên\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Tích Long Hạng Liên")) ? PPM : WHT);
			ret += sprintf(" %s Tích Long Yêu Đới\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Tích Long Yêu Đới")) ? PPM : WHT);
			ret += sprintf(" %s Tích Long Hài\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Tích Long Hài")) ? PPM : WHT);
			ret += sprintf(" %s 2 Món: Mỗi 5 giây phục hồi 100 Khí Huyết\n", count >= 2 ? PPM : WHT);
			ret += sprintf(" %s 3 Món: Tăng 160 Ngoại Công\n", count >= 3 ? PPM : WHT);
			ret += sprintf(" %s 4 Món: Tăng 160 nội kháng\n", count >= 4 ? PPM : WHT);
			ret += sprintf(" %s 5 Món: Giảm 50-80％ thời gian nhiễm các trạng thái\n", count >= 5 ? PPM : WHT);
			break;
		case "Mãnh hổ":
		case "Mãnh Hổ":
			ret += sprintf("%s Mãnh Hổ (%d/5)\n", count >= 2 ? PPM : WHT, count);
			ret += sprintf("%s Mãnh Hổ Mão Quán\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Mãnh Hổ Mão Quán")) ? PPM : WHT);
			ret += sprintf("%s Mãnh Hổ Bì Y\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Mãnh Hổ Bì Y")) ? PPM : WHT);
			ret += sprintf("%s Mãnh Hổ Hạng Liên\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Mãnh Hổ Hạng Liên")) ? PPM : WHT);
			ret += sprintf("%s Mãnh Hổ Yêu Đới\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Mãnh Hổ Yêu Đới")) ? PPM : WHT);
			ret += sprintf("%s Mãnh Hổ Chi Ngoa\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Mãnh Hổ Chi Ngoa")) ? PPM : WHT);
			ret += sprintf("%s 2 Món： Mỗi 5 giây hồi phục 5 điểm Pháp lực\n", count >= 2 ? PPM : WHT);
			ret += sprintf("%s 3 Món： Gia tăng Khí huyết cao nhất 100 điểm\n", count >= 3 ? PPM : WHT);
			ret += sprintf("%s 4 Món： Gia tăng 80 điểm Ngoại công\n%s gia tăng 80 điểm Nội Công\n", count >= 4 ? PPM : WHT, count >= 4 ? PPM : WHT);
			ret += sprintf("%s 5 Món： Bạo Kích gia tăng 2％\n", count >= 5 ? PPM : WHT);
			break;
		case "Thái dương":
		case "Thái Dương":
			ret += sprintf(" %s Thái Dương (%d/5)\n", count >= 2 ? PPM : WHT, count);
			ret += sprintf(" %s Mũ Thái Dương\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Mũ Thái Dương")) ? PPM : WHT);
			ret += sprintf(" %s Thái Dương Chiến Giáp\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Thái Dương Chiến Giáp")) ? PPM : WHT);
			ret += sprintf(" %s Thái Dương Hạng Liên\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Thái Dương Hạng Liên")) ? PPM : WHT);
			ret += sprintf(" %s Thái Dương Yêu Đới\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Thái Dương Yêu Đới")) ? PPM : WHT);
			ret += sprintf(" %s Hài Thái Dương\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Hài Thái Dương")) ? PPM : WHT);
			ret += sprintf(" %s 2 Món: Mỗi 5 giây phục hồi 10 Ma Lực\n", count >= 2 ? PPM : WHT);
			ret += sprintf(" %s 3 Món: Tăng tối đa 200 Khí Huyết\n", count >= 3 ? PPM : WHT);
			ret += sprintf(" %s 4 Món: Tăng công kích Ngoại Công 160,\n %s Tăng công kích Nội Công 160\n", count >= 4 ? PPM : WHT, count >= 4 ? PPM : WHT);
			ret += sprintf(" %s 5 Món: Tăng 4％ tỷ lệ trúng đòn\n", count >= 5 ? PPM : WHT);
			break;
		case "Cuồng Sư":
		case "Cuồng sư":
			ret += sprintf(" %s Cuồng Sư( %d /5)\n", count >= 2 ? PPM : WHT, count);
			ret += sprintf(" %s Cuồng Sư Đầu Khôi\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Cuồng Sư Đầu Khôi")) ? PPM : WHT);
			ret += sprintf(" %s Cuồng Sư Chiến Giáp\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Cuồng Sư Chiến Giáp")) ? PPM : WHT);
			ret += sprintf(" %s Cuồng Sư Hạng Liên\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Cuồng Sư Hạng Liên")) ? PPM : WHT);
			ret += sprintf(" %s Cuồng Sư Yêu Đới\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Cuồng Sư Yêu Đới")) ? PPM : WHT);
			ret += sprintf(" %s Cuồng Sư Ngoa\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Cuồng Sư Ngoa")) ? PPM : WHT);
			ret += sprintf(" %s 2 Món: Vũ khí không bị rơi\n", count >= 2 ? PPM : WHT);
			ret += sprintf(" %s 3 Món: Tăng Ngoại Công 80 điểm\n", count >= 3 ? PPM : WHT);
			ret += sprintf(" %s 4 Món: Tăng Nội Công 60 điểm\n", count >= 4 ? PPM : WHT);
			ret += sprintf(" %s 5 Món: Tăng tỉ lệ Bạo Kích 2％\n", count >= 5 ? PPM : WHT);
			break;
		case "Lôi Quang":
		case "Lôi quang":
			ret += sprintf(" %s Lôi Quang (%d/5)\n", count >= 2 ? PPM : WHT, count);
			ret += sprintf(" %s Mũ Lôi Quang\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Mũ Lôi Quang")) ? PPM : WHT);
			ret += sprintf(" %s Lôi Quang Giáp\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Lôi Quang Giáp")) ? PPM : WHT);
			ret += sprintf(" %s Lôi Quang Hạng Liên\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Lôi Quang Hạng Liên")) ? PPM : WHT);
			ret += sprintf(" %s Lôi Quang Yêu Đới\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Lôi Quang Yêu Đới")) ? PPM : WHT);
			ret += sprintf(" %s Lôi Quang Hài\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Lôi Quang Hài")) ? PPM : WHT);
			ret += sprintf(" %s 2 Món: Không rớt vũ khí\n", count >= 2 ? PPM : WHT);
			ret += sprintf(" %s 3 Món: Tăng 160 Ngoại Công\n", count >= 3 ? PPM : WHT);
			ret += sprintf(" %s 4 Món: Tăng 120 nội kháng\n", count >= 4 ? PPM : WHT);
			ret += sprintf(" %s 5 Món: Tăng 4％ tỷ lệ trúng đòn\n", count >= 5 ? PPM : WHT);
			break;
		case "Lạp báo":
		case "Lạp Báo":
			ret += sprintf(" %s Lạp Báo ( %d /5)\n", count >= 2 ? PPM : WHT, count);
			ret += sprintf(" %s Lạp Báo Đầu Cân\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Lạp Báo Đầu Cân")) ? PPM : WHT);
			ret += sprintf(" %s Lạp Báo Phi Phong\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Lạp Báo Phi Phong")) ? PPM : WHT);
			ret += sprintf(" %s Lạp Báo Hạng Liên\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Lạp Báo Hạng Liên")) ? PPM : WHT);
			ret += sprintf(" %s Lạp Báo Yêu Đới\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Lạp Báo Yêu Đới")) ? PPM : WHT);
			ret += sprintf(" %s Lạp Báo Ngoa\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Lạp Báo Ngoa")) ? PPM : WHT);
			ret += sprintf(" %s 2 Món: Tăng độc tính 30 điểm\n", count >= 2 ? PPM : WHT);
			ret += sprintf(" %s 3 Món: Tăng Ngoại Công 40 điểm\n", count >= 3 ? PPM : WHT);
			ret += sprintf(" %s 4 Món: Gia tăng 4％ mức độ Thân Thủ\n", count >= 4 ? PPM : WHT);
			ret += sprintf(" %s 5 Món: Tăng tỉ lệ bạo kích 2％\n", count >= 5 ? PPM : WHT);
			break;
		case "Toàn Phong":
		case "Toàn phong":
			ret += sprintf(" %s Toàn Phong (%d/5)\n", count >= 2 ? PPM : WHT, count);
			ret += sprintf(" %s Mũ Toàn Phong\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Mũ Toàn Phong")) ? PPM : WHT);
			ret += sprintf(" %s Toàn Phong Giáp\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Toàn Phong Giáp")) ? PPM : WHT);
			ret += sprintf(" %s Toàn Phong Hạng Liên\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Toàn Phong Hạng Liên")) ? PPM : WHT);
			ret += sprintf(" %s Toàn Phong Yêu Đới\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Toàn Phong Yêu Đới")) ? PPM : WHT);
			ret += sprintf(" %s Toàn Phong Hài\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Toàn Phong Hài")) ? PPM : WHT);
			ret += sprintf(" %s 2 Món: Tăng 60 độc tính\n", count >= 2 ? PPM : WHT);
			ret += sprintf(" %s 3 Món: Tăng 80 Ngoại Công\n", count >= 3 ? PPM : WHT);
			ret += sprintf(" %s 4 Món: Tăng 6％ Thân Thủ\n", count >= 4 ? PPM : WHT);
			ret += sprintf(" %s 5 Món: Tăng 4％ bạo kích\n", count >= 5 ? PPM : WHT);
			break;
		case "Bạch Lang":
		case "Bạch lang":
			ret += sprintf("Sói Trắng ( %d /5)\n", count);
			ret += sprintf(" %s Bạch Lang Bì Mão\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Bạch Lang Bì Mão")) ? PPM : WHT);
			ret += sprintf(" %s Bạch Lang Bì Y\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Bạch Lang Bì Y")) ? PPM : WHT);
			ret += sprintf(" %s Bạch Lang Hạng Liên\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Bạch Lang Hạng Liên")) ? PPM : WHT);
			ret += sprintf(" %s Bạch Lang Yêu Đới\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Bạch Lang Yêu Đới")) ? PPM : WHT);
			ret += sprintf(" %s Bạch Lang Chi Ngoa\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Bạch Lang Chi Ngoa")) ? PPM : WHT);
			ret += sprintf(" %s 2 Món: Khôi phục phép lực mỗi 5 giây 5 điểm\n", count >= 2 ? PPM : WHT);
			ret += sprintf(" %s 3 Món: Nâng cao Ngoại Kháng 60 điểm\n", count >= 3 ? PPM : WHT);
			ret += sprintf(" %s 4 Món: Nâng cao Nội Công 80 điểm\n", count >= 4 ? PPM : WHT);
			ret += sprintf(" %s 5 Món: Nâng cao 10％ khí huyết Thú triệu gọi Mao Sơn 10％,\n %s Nâng cao Ngoại Kháng 50\n", count >= 5 ? PPM : WHT, count >= 5 ? PPM : WHT);
			break;
		case "Chiến Lang":
		case "Chiến lang":
			ret += sprintf("Chiến Lang ( %d /5)\n", count);
			ret += sprintf(" %s Chiến Lang Bì Mão\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Chiến Lang Bì Mão")) ? PPM : WHT);
			ret += sprintf(" %s Chiến Lang Bì Y\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Chiến Lang Bì Y")) ? PPM : WHT);
			ret += sprintf(" %s Chiến Lang Hạng Liên\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Chiến Lang Hạng Liên")) ? PPM : WHT);
			ret += sprintf(" %s Chiến Lang Yêu Đới\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Chiến Lang Yêu Đới")) ? PPM : WHT);
			ret += sprintf(" %s Chiến Lang Chi Ngoa\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Chiến Lang Chi Ngoa")) ? PPM : WHT);
			ret += sprintf(" %s 2 món : 5 giây hồi 100 Ma Lực\n", count >= 2 ? PPM : WHT);
			ret += sprintf(" %s 3 món : Tăng 240 Ngoại Kháng\n", count >= 3 ? PPM : WHT);
			ret += sprintf(" %s 4 món : Tăng 320 Nội Công\n", count >= 4 ? PPM : WHT);
			ret += sprintf(" %s 5 món : Tăng 30%% Khí Huyết và 200 Ngoại Kháng thú triệu hồi.\n", count >= 5 ? PPM : WHT);
			break;
		case "Tuyết Điêu":
		case "Tuyết điêu":
			ret += sprintf("%s Tuyết Điêu (%d/5)\n", count >= 2 ? PPM : WHT, count);
			ret += sprintf("%s Tuyết Điêu Vũ Mão\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Tuyết Điêu Vũ Mão")) ? PPM : WHT);
			ret += sprintf("%s Tuyết Điêu Vũ Y\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Tuyết Điêu Vũ Y")) ? PPM : WHT);
			ret += sprintf("%s Tuyết Điêu Hạng Liên\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Tuyết Điêu Hạng Liên")) ? PPM : WHT);
			ret += sprintf("%s Tuyết Điêu Vũ Đới\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Tuyết Điêu Vũ Đới")) ? PPM : WHT);
			ret += sprintf("%s Tuyết Điêu Vũ Ngoa\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Tuyết Điêu Vũ Ngoa")) ? PPM : WHT);
			ret += sprintf("%s 2 Món： Mỗi 5 giây hồi phục 5 điểm Pháp lực\n", count >= 2 ? PPM : WHT);
			ret += sprintf("%s 3 Món： Hiệu quả thương tổn Nội công gia tăng 10 điểm\n", count >= 3 ? PPM : WHT);
			ret += sprintf("%s 4 Món： Gia tăng Pháp lực tối đa 60 điểm\n", count >= 4 ? PPM : WHT);
			ret += sprintf("%s 5 Món： Giảm sát thương cận chiến nhận được 5％\n", count >= 5 ? PPM : WHT);
			break;
		case "Liệp Ưng":
		case "Liệp ưng":
			ret += sprintf("%s Liệp Ưng (%d/5)\n", count >= 2 ? PPM : WHT, count);
			ret += sprintf("%s Liệp Ưng Vũ Mão\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Liệp Ưng Vũ Mão")) ? PPM : WHT);
			ret += sprintf("%s Liệp Ưng Vũ Y\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Liệp Ưng Vũ Y")) ? PPM : WHT);
			ret += sprintf("%s Liệp Ưng Hạng Liên\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Liệp Ưng Hạng Liên")) ? PPM : WHT);
			ret += sprintf("%s Liệp Ưng Vũ Đới\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Liệp Ưng Vũ Đới")) ? PPM : WHT);
			ret += sprintf("%s Liệp Ưng Vũ Ngoa\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Liệp Ưng Vũ Ngoa")) ? PPM : WHT);
			ret += sprintf("%s 2 Món： Mỗi 5 giây hồi phục 80 điểm Pháp lực\n", count >= 2 ? PPM : WHT);
			ret += sprintf("%s 3 Món： Hiệu quả thương tổn Nội công gia tăng 50 điểm\n", count >= 3 ? PPM : WHT);
			ret += sprintf("%s 4 Món： Gia tăng Pháp lực tối đa 100 điểm\n", count >= 4 ? PPM : WHT);
			ret += sprintf("%s 5 Món： Giảm sát thương cận chiến nhận được 5％\n", count >= 5 ? PPM : WHT);
			break;
		case "Linh Hồ":
		case "Linh hồ":
			ret += sprintf("%s Linh Hồ (%d/5)\n", count >= 2 ? PPM : WHT, count);
			ret += sprintf("%s Linh Hồ Nhung Mão\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Linh Hồ Nhung Mão")) ? PPM : WHT);
			ret += sprintf("%s Linh Hồ Bì Y\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Linh Hồ Bì Y")) ? PPM : WHT);
			ret += sprintf("%s Linh Hồ Hạng Liên\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Linh Hồ Hạng Liên")) ? PPM : WHT);
			ret += sprintf("%s Linh Hồ Yêu Đới\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Linh Hồ Yêu Đới")) ? PPM : WHT);
			ret += sprintf("%s Linh Hồ Chi Ngoa\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Linh Hồ Chi Ngoa")) ? PPM : WHT);
			ret += sprintf("%s 2 Món： Mỗi 5 giây hồi phục 10 điểm Pháp lực\n", count >= 2 ? PPM : WHT);
			ret += sprintf("%s 3 Món： Gia tăng 60 điểm Ngoại kháng\n", count >= 3 ? PPM : WHT);
			ret += sprintf("%s 4 Món： Gia tăng Khí huyết tối đa 100 điểm\n", count >= 4 ? PPM : WHT);
			ret += sprintf("%s 5 Món： Hiệu quả thương tổn Nội công gia tăng 33 điểm\n", count >= 5 ? PPM : WHT);
			break;
		case "Linh Lộc":
		case "Linh lộc":
			ret += sprintf("%s Linh Lộc (%d/5)\n", count >= 2 ? PPM : WHT, count);
			ret += sprintf("%s Linh Lộc Mão\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Linh Lộc Mão")) ? PPM : WHT);
			ret += sprintf("%s Linh Lộc Bì Y\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Linh Lộc Y")) ? PPM : WHT);
			ret += sprintf("%s Linh Lộc Hạng Liên\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Linh Lộc Hạng Liên")) ? PPM : WHT);
			ret += sprintf("%s Linh Lộc Yêu Đới\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Linh Lộc Yêu Đới")) ? PPM : WHT);
			ret += sprintf("%s Linh Lộc Ngoa\n", who->get_2(sprintf("suit_equip.%s.equip.%s", name, "Linh Lộc Ngoa")) ? PPM : WHT);
			ret += sprintf("%s 2 Món： Mỗi 5 giây hồi phục 80 điểm Pháp lực\n", count >= 2 ? PPM : WHT);
			ret += sprintf("%s 3 Món： Gia tăng 120 điểm Ngoại kháng\n", count >= 3 ? PPM : WHT);
			ret += sprintf("%s 4 Món： Gia tăng Khí huyết tối đa 300 điểm\n", count >= 4 ? PPM : WHT);
			ret += sprintf("%s 5 Món： Hiệu quả thương tổn Nội công gia tăng 100 điểm\n", count >= 5 ? PPM : WHT);
			break;

		//Huyet long
		case "Huyết Long CL":
			ret += sprintf("%s Huyết Long (%d/5)\n", count >= 2 ? HIR : WHT, count);
			ret += sprintf("%s 2 Món： Mỗi 5 giây hồi phục 100 điểm Pháp lực\n", count >= 2 ? HIR : WHT);
			ret += sprintf("%s 3 Món： Hiệu quả thương tổn Nội công gia tăng 120 điểm\n", count >= 3 ? HIR : WHT);
			ret += sprintf("%s 4 Món： Gia tăng Pháp lực tối đa 200 điểm\n", count >= 4 ? HIR : WHT);
			ret += sprintf("%s 5 Món： Giảm sát thương cận chiến nhận được 6％\n", count >= 5 ? HIR : WHT);
			break;
		case "Huyết Long CVQ":
			ret += sprintf(" %s Huyết Long (%d/5)\n", count >= 2 ? HIR : WHT, count);
			ret += sprintf(" %s 2 Món: Không rớt vũ khí\n", count >= 2 ? HIR : WHT);
			ret += sprintf(" %s 3 Món: Tăng 250 Ngoại Công\n", count >= 3 ? HIR : WHT);
			ret += sprintf(" %s 4 Món: Tăng 150 nội kháng\n", count >= 4 ? HIR : WHT);
			ret += sprintf(" %s 5 Món: Tăng 5％ tỷ lệ trúng đòn\n", count >= 5 ? HIR : WHT);
			break;
		case "Huyết Long ĐHN":
			ret += sprintf(" %s Huyết Long (%d/5)\n", count >= 2 ? HIR : WHT, count);
			ret += sprintf(" %s 2 Món: Mỗi 5 giây phục hồi 100 Khí Huyết\n", count >= 2 ? HIR : WHT);
			ret += sprintf(" %s 3 Món: Tăng 240 Ngoại Công\n", count >= 3 ? HIR : WHT);
			ret += sprintf(" %s 4 Món: Tăng 200 nội kháng\n", count >= 4 ? HIR : WHT);
			ret += sprintf(" %s 5 Món: Có tỉ lệ giảm 50-90％ sát thương bạo kích\n", count >= 5 ? HIR : WHT);
			break;
		case "Huyết Long ĐM":
			ret += sprintf(" %s Huyết Long (%d/5)\n", count >= 2 ? HIR : WHT, count);
			ret += sprintf(" %s 2 món : Tăng 100 độc tính\n", count >= 2 ? HIR : WHT);
			ret += sprintf(" %s 3 món : Tăng 120 Ngoại Công\n", count >= 3 ? HIR : WHT);
			ret += sprintf(" %s 4 món : Tăng 10％ Thân Thủ\n", count >= 4 ? HIR : WHT);
			ret += sprintf(" %s 5 món : Tăng 5％ bạo kích\n", count >= 5 ? HIR : WHT);
			break;
		case "Huyết Long MS":
			ret += sprintf(" %s Huyết Long (%d/5)\n", count >= 2 ? HIR : WHT, count);
			ret += sprintf(" %s 2 món : 5 giây hồi 100 Ma Lực\n", count >= 2 ? HIR : WHT);
			ret += sprintf(" %s 3 món : Tăng 240 Ngoại Kháng\n", count >= 3 ? HIR : WHT);
			ret += sprintf(" %s 4 món : Tăng 350 Nội Công\n", count >= 4 ? HIR : WHT);
			ret += sprintf(" %s 5 món : Tăng 30%% Khí Huyết và 500 Ngoại Kháng thú triệu hồi.\n", count >= 5 ? HIR : WHT);
			break;
		case "Huyết Long TS":
			ret += sprintf(" %s Huyết Long (%d/5)\n", count >= 2 ? HIR : WHT, count);
			ret += sprintf(" %s 2 Món: Mỗi 5 giây phục hồi 50 Ma Lực\n", count >= 2 ? HIR : WHT);
			ret += sprintf(" %s 3 Món: Tăng tối đa 300 Khí Huyết\n", count >= 3 ? HIR : WHT);
			ret += sprintf(" %s 4 Món: Tăng công kích Ngoại Công 160,\n %s Tăng công kích Nội Công 160\n", count >= 4 ? HIR : WHT, count >= 4 ? HIR : WHT);
			ret += sprintf(" %s 5 Món: Tăng 4％ tỷ lệ trúng đòn\n", count >= 5 ? HIR : WHT);
			break;
		case "Huyết Long VMC":
			ret += sprintf(" %s Huyết Long (%d/5)\n", count >= 2 ? HIR : WHT, count);
			ret += sprintf("%s 2 Món： Mỗi 5 giây hồi phục 80 điểm Pháp lực\n", count >= 2 ? HIR : WHT);
			ret += sprintf("%s 3 Món： Gia tăng 300 điểm Ngoại kháng\n", count >= 3 ? HIR : WHT);
			ret += sprintf("%s 4 Món： Gia tăng Khí huyết tối đa 300 điểm\n", count >= 4 ? HIR : WHT);
			ret += sprintf("%s 5 Món： Hiệu quả thương tổn Nội công gia tăng 200 điểm\n", count >= 5 ? HIR : WHT);
			break;
	}
	return ret;
}