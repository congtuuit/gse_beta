#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <music.h>
#include <time.h>

inherit BADMAN;

int no_die;
int iStart, iFinish;

int time_remove = 300;
int get_id_color() { return 0xdd0571; }
//int is_christmas() { return 1; }
int is_smart_caster() { return 1; }
void auto_fight(object who) { }
//int no_die() { return no_die; }
void follow_user(object me) {}

void reset()
{
	if (gone_time(get("birth")) > time_remove)
	{
		remove_from_scene();
		destruct(this_object());
	}
	else {
		call_out("reset", 1);
	}

}

void create()
{
	set_name("圣诞野兔");
	set_char_type(FIGHTER_TYPE);
	set_head_color(0x0);

	NPC_ENERGY_D->init_level(this_object(), 1 + random(2));
	set_max_seek(4);
	setup();
	set_char_type(FIGHTER_TYPE);

	set("birth", time());
	call_out("reset", 1);

}



void win_bonus(object who)
{
	int p, rate, i, x,y,z;
	object item, owner;
	object me = this_object();

	if (owner = who->get_owner()) who = owner;
	if (who->is_npc()) return;
	who->add_exp(500);

	item = new("item/std/0001");
	item->set_value(2000);

	if (!item)
		return;

	if (item) {
		x = get_x(me);
		y = get_y(me);
		z = get_z(me);

		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item->add_to_scene(z, p / 1000, p % 1000);
		}
	}

	rate = random(100);
	if (rate < 5) {
		item = new("item/event/giangsinh/cautuyet");

		if (item) {
			x = get_x(me);
			y = get_y(me);
			z = get_z(me);

			if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
			{
				item->add_to_scene(z, p / 1000, p % 1000);
			}
		}
	}

	rate = random(100);
	if (rate < 30) {
		item = new("item/01/0202");
		if (item) {
			x = get_x(me);
			y = get_y(me);
			z = get_z(me);

			if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
			{
				item->add_to_scene(z, p / 1000, p % 1000);
			}
		}
	}


	send_user(who, "%c%w", 0x0d, MUSIC_TASK);
	
}

