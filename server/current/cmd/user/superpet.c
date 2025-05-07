#include <item.h>
#include <ansi.h>
#include <effect.h>
#include <skill.h>
#include <npc.h>
#include <equip.h>
#include <task.h>

//5 phut giam 1 tuoi tho
private int timeLifeDown = 300;

private int timeExpUp = 120;

private int expUpPoint = 2;

//const
private int minLife = 10;

void reset_buff_pet(object me, object item);
int main(object me, string arg)
{
	return 0;
}

int max_exp(object item) {
	int result = 0;
	int level = item->get("itemLevel");

	switch (level)
	{
	case 0:
	case 1:
		result = 1024;
		break;
	case 2:
		result = 4420;
		break;
	case 3:
		result = 12200;
		break;
	case 4:
		result = 46080;
		break;
	case 5:
		result = 99999;
		break;
	}

	return result;
}

void life_down(object me, object item) {
	object* obj, zombie;
	int size, index;

	if (item->get("itemLife") < 1) {
		item->set("itemLife", 100);
	}

	if (item->get("itemLife") < 5) {
		//remove_pet(me);
		return;
	}

	item->add("itemLife", -1);
	if (item->get("itemLife") < minLife) {
		obj = me->get("zombie");
		size = sizeof(obj);
		if (size)
		{
			for (index = 0; index < size; index++)
			{
				zombie = obj[index];
				if (!objectp(zombie)) continue;
				send_user(get_scene_object_2(zombie, USER_TYPE), "%c%w%w%w%c%c%c", 0x4f, get_x(zombie), get_y(zombie), 9414, 1, OVER_BODY, PF_ONCE);
				send_user(me, "%c%c%d", 0x2c, 0, getoid(zombie));
				zombie->remove_from_scene();
				destruct(zombie);
			}

			reset_buff_pet(me, item);
			remove_call_out("life_down");
			return;
		}
	}

	send_user(me, "%c%d%c", 0x31, getoid(item), 0);
	call_out("life_down", timeLifeDown, me, item);
	
}

void exp_up(object me, object item) {
	if (item->get("itemExp") < max_exp(item)) {
		item->add("itemExp", expUpPoint);

		if (item->get("itemLevel") < 5) {
			if (item->get("itemExp") >= max_exp(item)) {
				item->add("itemLevel", 1);
			}
		}
		else {
			tell_user(me, ECHO"Thần thú đã đạt cấp độ tối đa.");
			remove_call_out("exp_up");
			return;
		}
	}
	else {
		if (item->get("itemLevel") < 5) {
			item->add("itemLevel", 1);
			item->add("itemExp", expUpPoint);
		}
		else {
			tell_user(me, ECHO"Thần thú đã đạt cấp độ tối đa.");
			remove_call_out("exp_up");
			return;
		}
	}

	send_user(me, "%c%d%c", 0x31, getoid(item), 0);
	call_out("exp_up", timeExpUp, me, item);
}

void reset_buff_pet(object me, object item) {
	me->delete("12pet_item");
	me->delete("zombie");
	me->delete_2("jiguan");

	//item->delete("superpetOnline");

	USER_ENERGY_D->count_all_prop(me);
	remove_call_out("exp_up");
	remove_call_out("life_down");

	me->set_2("callPet", time());
}

void remove_pet(object me) {
	object* obj, zombie, npc;
	int size, index, p, z, x, y;

	me->set_2("callPet", time());

	me->delete("12pet_item");
	me->delete("zombie");
	me->delete_2("jiguan");

	remove_call_out("exp_up");
	remove_call_out("life_down");

}

//subRateDouble : ti le ra giam thuong
//subDouble : ti le giam thuong

//addRateDouble : ti le ra tang bao kich
//addDouble : tang bao kick

void init_buff_pet_black(object me, object item) {
	int level = item->get("itemLevel");
	int ad, ap, dp, pp, doubleA, antiA, timeCalled;

	switch (level)
	{
	case 1:
		ad = 20;
		dp = 1;
		ap = 20;
		pp = 1;
		doubleA = 5;
		break;
	case 2:
		ad = 22;
		dp = 2;
		ap = 22;
		pp = 2;
		doubleA = 6;
		break;
	case 3:
		ad = 24;
		dp = 3;
		ap = 24;
		pp = 3;
		doubleA = 7;
		break;
	case 4:
		ad = 26;
		dp = 4;
		ap = 26;
		pp = 4;
		doubleA = 8;
		break;
	case 5:
		ad = 30;
		dp = 5;
		ap = 32;
		pp = 5;
		doubleA = 10;
		break;
	}

	me->delete_2("jiguan");

	me->set_2("jiguan.cp", ad);
	me->set_2("jiguan.ap", ap);
	me->set_2("jiguan.dp", dp);
	me->set_2("jiguan.pp", pp);

	//me->set_2("jiguan.anti_hurt", doubleA);

	me->set_2("jiguan.addDouble", doubleA);
	me->set_2("jiguan.addRateDouble", 99);

	USER_ENERGY_D->count_all_prop(me);

	call_out("exp_up", timeExpUp, me, item);

	if (me->get_2("callPet") > 0) {
		timeCalled = time() - me->get_2("callPet");

		if (timeCalled < timeLifeDown) {
			call_out("life_down", timeLifeDown - timeCalled, me, item);
		}
	}
	else {
		call_out("life_down", timeLifeDown, me, item);
	}

}

void init_buff_pet_red(object me, object item) {
	int level = item->get("itemLevel");
	int ad, ap, dp, pp, doubleA, antiA, timeCalled;

	switch (level)
	{
	case 1:
		ad = 18;
		ap = 18;
		pp = 5;
		antiA = 2;
		break;
	case 2:
		ad = 20;
		dp = 7;
		ap = 20;
		pp = 7;
		antiA = 4;
		break;
	case 3:
		ad = 22;
		dp = 9;
		ap = 22;
		pp = 9;
		antiA = 6;
		break;
	case 4:
		ad = 24;
		dp = 11;
		ap = 24;
		pp = 11;
		antiA = 9;
		break;
	case 5:
		ad = 27;
		dp = 15;
		ap = 27;
		pp = 15;
		antiA = 14;
		break;
	}

	me->delete_2("jiguan");

	me->set_2("jiguan.cp", ad);
	me->set_2("jiguan.ap", ap);
	me->set_2("jiguan.dp", dp);
	me->set_2("jiguan.pp", pp);

	me->set_2("jiguan.anti_hurt", antiA);

	//me->set_2("jiguan.addDouble", doubleA);
	//me->set_2("jiguan.addRateDouble", 99);

	USER_ENERGY_D->count_all_prop(me);

	call_out("exp_up", timeExpUp, me, item);

	if (me->get_2("callPet") > 0) {
		timeCalled = time() - me->get_2("callPet");

		if (timeCalled < timeLifeDown) {
			call_out("life_down", timeLifeDown - timeCalled, me, item);
		}
	}
	else {
		call_out("life_down", timeLifeDown, me, item);
	}

}

string get_string_pet_black(object item) {
	string result = "";
	int itemLevel, itemMaxExp, itemExp, itemLife;
	itemLevel = item->get("itemLevel");
	itemExp = item->get("itemExp");
	itemLife = item->get("itemLife");
	itemMaxExp = max_exp(item);

	result = sprintf("\n"PPM"Huyễn Thú Cấp %d\nThọ Mệnh: %d\n"HIG"Kinh nghiệm: %d/%d\n(Thọ mệnh dưới 10 sẽ không thể triệu hồi)", itemLevel, itemLife, itemExp, itemMaxExp);

	return result;
}

string get_string_pet_red(object item) {
	string result = "";
	int itemLevel, itemMaxExp, itemExp, itemLife;
	itemLevel = item->get("itemLevel");
	itemExp = item->get("itemExp");
	itemLife = item->get("itemLife");
	itemMaxExp = max_exp(item);

	result = sprintf("\n"PPM"Huyễn Thú Cấp %d\nThọ Mệnh: %d\n"HIG"Kinh nghiệm: %d/%d\n(Thọ mệnh dưới 10 sẽ không thể triệu hồi)", itemLevel, itemLife, itemExp, itemMaxExp);

	return result;
}

string get_desc_black(object item) {
	int level = item->get("itemLevel");
	string result;

	int ad, ap, dp, pp, doubleA, antiA;
	switch (level)
	{
	case 1:
		ad = 20;
		dp = 1;
		ap = 20;
		pp = 1;
		doubleA = 5;
		break;
	case 2:
		ad = 22;
		dp = 2;
		ap = 22;
		pp = 2;
		doubleA = 6;
		break;
	case 3:
		ad = 24;
		dp = 3;
		ap = 24;
		pp = 3;
		doubleA = 7;
		break;
	case 4:
		ad = 26;
		dp = 4;
		ap = 26;
		pp = 4;
		doubleA = 8;
		break;
	case 5:
		ad = 30;
		dp = 5;
		ap = 32;
		pp = 5;
		doubleA = 10;
		break;
	}

	result = sprintf(PPM"Ngoại công: +%d%%\n"PPM"Ngoại kháng: +%d%%\n"PPM"Nội công: +%d%%\n"PPM"Nội kháng: +%d%%\n"PPM"Sát thương bạo kích: +%d%%",
		ad,dp,ap,pp,doubleA);
	return result;
}

string get_desc_red(object item) {
	int level = item->get("itemLevel");
	string result;

	int ad, ap, dp, pp, doubleA, antiA;
	switch (level)
	{
	case 1:
		ad = 18;
		ap = 18;
		pp = 5;
		antiA = 2;
		break;
	case 2:
		ad = 20;
		dp = 7;
		ap = 20;
		pp = 7;
		antiA = 4;
		break;
	case 3:
		ad = 22;
		dp = 9;
		ap = 22;
		pp = 9;
		antiA = 6;
		break;
	case 4:
		ad = 24;
		dp = 11;
		ap = 24;
		pp = 11;
		antiA = 9;
		break;
	case 5:
		ad = 27;
		dp = 15;
		ap = 27;
		pp = 15;
		antiA = 14;
		break;
	}

	result = sprintf(PPM"Ngoại công: +%d%%\n"PPM"Ngoại kháng: +%d%%\n"PPM"Nội công: +%d%%\n"PPM"Nội kháng: +%d%%\n"PPM"Giảm thương: +%d%%",
		ad, dp, ap, pp, antiA);
	return result;
}