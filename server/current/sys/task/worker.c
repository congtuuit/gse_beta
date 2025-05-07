#include <ansi.h>
#include <skill.h>
#include <task.h>
#include <effect.h>

#define TIME_INTERVAL   20
#define CASH_BONUS	2000
#define EXP_BONUS	5000
#define POT_BONUS	10
#define SUB_STR		20

void SAVE_BINARY() { }

void effect_work_break(object me);

void gift_bonus(object me) {
	int rate, i;
	object item;

	if (USER_INVENTORY_D->get_free_count(me) < 1)
	{
		notify("Hành trang không đủ 1 chỗ trống");
		effect_work_break(me);
		return;
	}

	rate = random(100);

	if (rate < 3) {
		item = new("/item/spitem/ve/ve5sao");
	}
	else if (rate < 10) {

		item = new("/item/common/tinhthach");
	}
	else if (rate < 40) {
		item = new("/item/test2/tuiphapbao");
	}
	else if (rate < 55) {
		item = new(sprintf("item/ThanThuNew/%d", 0 + random(5)));
	}
	else if (rate < 65) {
		item = new(sprintf("item/TuiLinhThach/ngaunhien/1"));
	}
	else if (rate < 70) {
		item = new(sprintf("item/common/camnang"));
	}

	if (item) {
		i = item->move(me, -1);
		item->add_to_user(i);

		USER_D->user_channel(sprintf(HIG"Chúc mừng "HIR"%s"HIG" lao động cực khổ tại Đốc Công may mắn nhận được "HIR"%s ", me->get_name(), item->get_name()));

	}
	else {
		me->add_exp(EXP_BONUS);
	}

}

void gift_bonus_2(object me) {
	int rate, i;
	object item;

	if (USER_INVENTORY_D->get_free_count(me) < 1)
	{
		notify("Hành trang không đủ 1 chỗ trống");
		effect_work_break(me);
		return;
	}

	rate = random(100);

	if (rate < 5) {
		item = new ("/item/common/box/tukim/item/ngoc25");
	}
	else if (rate < 9) {
		item = new("/item/pet/hon");
	}
	else if (rate < 15) {
		item = new("/item/common/box/tukim/item/ve5sao");
	}
	else if (rate < 20) {
		item = new("/item/sell/0034");
	}
	else if (rate < 40) {
		item = new("/item/test2/tuiphapbao");
	}
	else if (rate < 65) {
		item = new(sprintf("item/TuiLinhThach/ngaunhien/1"));
	}
	else if (rate < 75) {
		item = new("/item/pet/hon");
	}


	if (item) {
		i = item->move(me, -1);
		item->add_to_user(i);

		USER_D->user_channel(sprintf(HIC"Chúc mừng "HIR"%s"HIC" thắp hương tại Phong Thần Đại được chúc phúc và  nhận được "HIR"%s ", me->get_name(), item->get_name()));
	}
	else {
		me->add_exp(EXP_BONUS);
	}

}


void begin_work(object me, int iType)
{
	int iTime;
	me->set("work_type", iType);
	iTime = me->get_strength();
	set_effect_2(me, EFFECT_USER_WORK, iTime / SUB_STR + 2, TIME_INTERVAL);	//20秒调用一次
	send_user(me, "%c%c%w%s", 0x5a, 0, iTime / SUB_STR * TIME_INTERVAL, "Công việc khó khăn...");
	send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 02011, 10, OVER_BODY, PF_LOOP);
}

void effect_work_break(object me)
{
	set_effect(me, EFFECT_USER_WORK, 0);
	send_user(me, "%c%c%c", 0x5a, 1, 0);
	send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 02011, 0, OVER_BODY, PF_STOP);
	me->delete("work_type");
}

void work_bonus(object me)
{
	int iType, money;
	iType = me->get("work_type");

	if (me->get_strength(me) < SUB_STR)
	{
		effect_work_break(me);
		return;
	}

	if (iType == 3) {

		if (random(100) < 80) {
			//gift_bonus_2(me);
		}

		me->add_exp(EXP_BONUS * 2);
		me->add_potential(POT_BONUS);
		write_user(me, ECHO "Bạn nhận được " + EXP_BONUS * 2 + " kinh nghiệm, " + POT_BONUS + " tiềm năng。");
	}
	else {

		me->add_strength(-SUB_STR);

		if (iType == NEWBIE_WORK)
		{
			me->add_exp(EXP_BONUS);
			me->add_potential(POT_BONUS);
			me->add_cash(CASH_BONUS / 2);
			me->add_log("&newbiework", EXP_BONUS);
			me->add_log("*newbiework", POT_BONUS);
			me->add_log("$newbiework", CASH_BONUS / 2);
			me->add_log("#newbiework", 1);
			money = CASH_BONUS / 2;
			write_user(me, ECHO "Bạn nhận được " + EXP_BONUS + " kinh nghiệm," + money + " ngân lượng, " + POT_BONUS + " tiềm năng。");
		}

		else if (iType == ZHOU_WORK)	//Chu Quốc
		{
			me->add_exp(EXP_BONUS);
			me->add_cash(CASH_BONUS);
			"/sys/sys/count"->add_income("work", CASH_BONUS);
			me->add_log("&newbiework", EXP_BONUS);
			me->add_log("$newbiework", CASH_BONUS);
			me->add_log("#newbiework", 1);
			write_user(me, ECHO "Bạn nhận được " + EXP_BONUS + " kinh nghiệm, " + CASH_BONUS + " ngân lượng");
		}

		if (random(100) < 60) {
			//gift_bonus(me);
		}

		if (me->get_strength(me) <= 0)
		{
			effect_work_break(me);
			return;
		}
	}

}


void begin_thaphuong(object me)
{
	int iTime;
	me->set("work_type", 3);

	set_effect_2(me, EFFECT_USER_WORK, 10, 5);
	send_user(me, "%c%c%w%s", 0x5a, 0, 10, "Đang thắp hương...");

	call_out("effect_work_break", 12, me);
}
