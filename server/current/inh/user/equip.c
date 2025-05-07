
#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <time.h>

private static object *Equip = ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}); // 装备数组：头、颈、手、身、腰、脚、法宝

private static int *armor_code = ({20000, 20100, 30000, 30100, 40000, 40100, 50000, 50100, 80000, 80100, 60000, 60100, 70000, 70100, 10000, 10100, 10200, 10300});

int get_login_flag();

// -------------------------------------------------------------

object *get_all_equip() { return copy(Equip); }

object get_equip(int index)
{
	switch (index)
	{
	case HEAD_TYPE:
		return Equip[HEAD_POSITION];
	case NECK_TYPE:
		return Equip[NECK_POSITION];
	case WEAPON_TYPE:
		return Equip[WEAPON_POSITION];
	case ARMOR_TYPE:
		return Equip[ARMOR_POSITION];
	case WAIST_TYPE:
		return Equip[WAIST_POSITION];
	case BOOTS_TYPE:
		return Equip[BOOTS_POSITION];
	case HAND_TYPE:
		return Equip[HAND_POSITION];
	case FAMILY_TYPE:
		return Equip[FAMILY_POSITION];
	case BACK_TYPE:
		return Equip[BACK_POSITION];
	case FASHION_TYPE:
		return Equip[FASHION_POSITION];
	default:
		return 0;
	}
}

object set_equip(int index, object item)
{
	switch (index)
	{
	case HEAD_TYPE:
		return Equip[HEAD_POSITION] = item;
	case NECK_TYPE:
		return Equip[NECK_POSITION] = item;
	case WEAPON_TYPE:
		return Equip[WEAPON_POSITION] = item;
	case ARMOR_TYPE:
		return Equip[ARMOR_POSITION] = item;
	case WAIST_TYPE:
		return Equip[WAIST_POSITION] = item;
	case BOOTS_TYPE:
		return Equip[BOOTS_POSITION] = item;
	case HAND_TYPE:
		return Equip[HAND_POSITION] = item;
	case FAMILY_TYPE:
		return Equip[FAMILY_POSITION] = item;
	case BACK_TYPE:
		return Equip[BACK_POSITION] = item;
	case FASHION_TYPE:
		return Equip[FASHION_POSITION] = item;
	default:
		return 0;
	}
}

int use_equip(object equip) { return USER_EQUIP_D->use_equip(this_object(), equip); }

int restore_equip(object equip) { return USER_EQUIP_D->restore_equip(this_object(), equip); }

int remove_equip(int index) { return USER_EQUIP_D->remove_equip(this_object(), index); }

int drop_equip(int index) { return USER_EQUIP_D->drop_equip(this_object(), index); }

// -------------------------------------------------------------

int get_gender();

int get_armor_code()
{
	object me = this_object();
	int family, gender, level, i, size;
	int suits, armor;
	armor = 0;
	if (get_effect(me, EFFECT_MAGIC_4243))
	{
		armor = me->get_save("pf#4243");
	}
	else if (get_effect(me, EFFECT_MAGIC_CARD))
	{
		armor = me->get_save("magic_card");
	}
	else if (me->get_save_2("marry_fashion.time") > time())
	{
		if (me->get_gender() == 1)
			armor = 10000 + me->get_save_2("marry_fashion.code");
		else
			armor = 11000 + me->get_save_2("marry_fashion.code");
	}
	else if (me->get_equip(FASHION_TYPE))
	{
		if (me->get_gender() == 1)
			armor = 10000 + Equip[FASHION_POSITION]->get_fashion_code();
		else
			armor = 11000 + Equip[FASHION_POSITION]->get_fashion_code();
	}
	else if (me->get_save("temp_act"))
	{
		armor = me->get_save("temp_act");
	}
	else if (me->get("temp_act"))
	{
		armor = me->get("temp_act");
	}
	if (armor > 0)
		return armor;

	//	if (MAIN_D->get_host_type()!=1000) return Code;
	family = me->get_fam_type();
	if (family == 0)
		family = 8;
	if (family > 8)
		family = 8;
	gender = me->get_gender();
	family -= 1;
	gender -= 1;
	if (gender < 0 || gender > 1)
		gender = 0;

	armor = me->get_equip(ARMOR_TYPE);
	//	if ( armor )
	//	{
	//		suits = armor->get_equip_serial();
	//	}
	if ("/sys/sys/count"->get_new_person())
	{
		gender = me->get_gender();
		family = me->get_fam_type();
		if (gender == 1)
			gender = 0;
		else
			gender = 1000;
		if (family == 8)
			family = 0;
		if (me->get_fam_type() == 5)
			family = 7;
		if (me->get_fam_type() == 6)
			family = 5;
		if (me->get_fam_type() == 7)
			family = 6;
		family++;
		return 10000 + gender + family;
	}

	return armor_code[2 * family + gender] + suits;
	/*
			if( objectp( Equip[ARMOR_POSITION] ) ) return Equip[ARMOR_POSITION]->get_armor_code();
	//        if (MAIN_D->get_host_type()!=1000)
		if (0)
				return get_gender() == 1 ? M_DUANGUA : F_DUANSHAN;
			else
				return get_gender() == 1 ? 10000 : 10100;
	*/
}

int get_armor_color_1()
{
	object me = this_object();
	return me->get_save_2("marry_fashion.color") > 0 ? me->get_save_2("marry_fashion.color") : (objectp(Equip[ARMOR_POSITION]) ? Equip[ARMOR_POSITION]->get_armor_color_1() : 0x42084208);
}

int get_armor_color_2() { return objectp(Equip[ARMOR_POSITION]) ? Equip[ARMOR_POSITION]->get_armor_color_2() : 0x42084208; }

int get_head_code()
{
	if (objectp(Equip[HEAD_POSITION]))
		return Equip[HEAD_POSITION]->get_head_code();
	else
		return get_gender() == 1 ? M_BANGDAI : F_BANGDAI;
}

int get_head_color() { return objectp(Equip[HEAD_POSITION]) ? Equip[HEAD_POSITION]->get_head_color() : 0x42084208; }

int get_weapon_code()
{

	if (objectp(Equip[WEAPON_POSITION]))
	{
		if (Equip[WEAPON_POSITION]->get_lasting() < 100)
			return UNARMED;
		if (get_effect(this_object(), EFFECT_NO_WEAPON))
			return UNARMED;
		return Equip[WEAPON_POSITION]->get_weapon_type();
	}
	else
		return UNARMED;
}

int get_weapon_code_2()
{
	int level, color, type, level_item;
	if (objectp(Equip[WEAPON_POSITION]))
	{
		if (Equip[WEAPON_POSITION]->get_lasting() < 100)
			return UNARMED;
		level = Equip[WEAPON_POSITION]->get_weapon_level();
		color = Equip[WEAPON_POSITION]->get_item_color();
		type = Equip[WEAPON_POSITION]->get_weapon_type();

		// level_item = Equip[WEAPON_POSITION]->get_level() / 10;
		/*if (level_item == 0)
		{
			level_item == 1;
		}

		level_item += 1;

		if (level_item > 14) level_item = 14;

		if (level <= 0) {
			level = level_item;
		}*/

		if (level == 0)
		{
			level = Equip[WEAPON_POSITION]->get_level();
			level /= 10;
			if (level > 14)
				level = 14;
		}
		if (color == 2)
		{
			if (Equip[WEAPON_POSITION]->get_level() < 80)
				level = 12;
			else
				level = 13;
		}
		else if (color == 3)
			level = 14;
		else if (color == 0 && level >= 10)
			level = 9;

		return type | (level << 8);
	}
	else
		return UNARMED;
}

int get_weapon_color()
{
	int level, color;
	object me = this_object();

	if (objectp(Equip[WEAPON_POSITION]))
	{
		if (Equip[WEAPON_POSITION]->get("gold_time") - time() > 0)
		{

			Equip[WEAPON_POSITION]->set_weapon_color(YELLOW);
		}

		if (me->get_pk() >= 100)
		{
			Equip[WEAPON_POSITION]->set_weapon_color(M_RED);
		}

		// color from tich doc
		if (color = me->get_2("weaponColor"))
		{
			Equip[WEAPON_POSITION]->set_weapon_color(color);
		}

		return Equip[WEAPON_POSITION]->get_weapon_color();
	}
	else
		return 0;
}

int get_weapon_color_2()
{
	int level, color, ret, star;
	string forge;
	if (objectp(Equip[WEAPON_POSITION]))
	{
		if (Equip[WEAPON_POSITION]->get_lasting() < 100)
			return 0;
		color = Equip[WEAPON_POSITION]->get_item_color();

		/* if (color == 0 || color == 4) {
			 if (color == 0) {
				 return 0;
			 }
			 else {
				 forge = Equip[WEAPON_POSITION]->get("forge");
				 star = strlen(forge);

				 if (color == 4 && star > 6) {
					 ret = 0x5fed;
				 }

				 return ret;
			 }
		 } */

		level = Equip[WEAPON_POSITION]->get_level();
		switch (color)
		{
		case 0:
			break;
		case 1:
			if (level <= 50) /* ret = 0xffff*/
				;
			else if (level <= 70)
				ret = 0xbdc;
			else
				ret = 0x1a56;
			break;
		case 2:
			if (level <= 50)
				ret = 0x4fed;
			else if (level <= 70)
				ret = 0x4d0;
			else if (level <= 119)
				// ret = 0xfc62;
				ret = 0x00FFFF00;
			else
				// ret = 0x6000;
				ret = 0x00FFFF00;
			break;
		case 3:

		default:
			if (level <= 50)
				ret = 0x831d;
			else if (level <= 70)
				ret = 0x4898;
			else
				ret = 0x680d;
			break;
		}

		if (color == 10)
		{
			ret = 0x00CBC0FF;
		}

		if (Equip[WEAPON_POSITION]->get_item_color() == 10)
		{
			ret = 0xff5f00;
		}

		forge = Equip[WEAPON_POSITION]->get("forge");
		star = strlen(forge);
		if (star > 6)
		{
			ret = 0x7000;
		}

		if (star > 7)
		{
			ret = 0x00E22B8A;
			ret = 0x00F5F5F5;
		}

		if (star > 8)
		{
			// trang hong
			ret = 0x00F5F5F5;
		}

		return ret;
	}
	else
		return 0;
}

int get_back()
{
	if (objectp(Equip[BACK_POSITION]))
	{
		return Equip[BACK_POSITION]->get_back_type();
	}
	else
		return 0;
}

int get_back_color()
{
	if (objectp(Equip[BACK_POSITION]))
	{
		return Equip[BACK_POSITION]->get_back_color();
	}
	else
		return 0;
}

int get_back2()
{
	if (objectp(Equip[BACK_POSITION]))
	{
		return Equip[BACK_POSITION]->get_back2_type();
	}
	else
		return 0;
}

int get_back2_color()
{
	if (objectp(Equip[BACK_POSITION]))
	{
		return Equip[BACK_POSITION]->get_back2_color();
	}
	else
		return 0;
}