#include <npc.h>
#include <ansi.h>
#include <public.h>

inherit BADMAN;

int no_die;

int get_id_color() { return 0xdd0571; }
int is_christmas() { return 1; }
int is_smart_caster() { return 1; }
void auto_fight(object who) { }
int no_die() { return no_die; }
void follow_user(object me) {}

void create()
{
	set_name("圣诞野兔");
	set_char_type(FIGHTER_TYPE);
	set_head_color(0x0);

	NPC_ENERGY_D->init_level(this_object(), 1 + random(2));
	set_max_seek(4);
	setup();
	set_char_type(FIGHTER_TYPE);
}



void win_bonus(object who)
{
	int p;
	object item, owner;
	object me = this_object();

	if (owner = who->get_owner()) who = owner;
	if (who->is_npc()) return;
	who->add_exp(50);

	if (random(100) < 15)
		return;
	item = new("item/04/0412");
	if (!item)
		return;
	p = item->move(who, -1);
	if (!p)
	{
		destruct(item);
		return;
	}
	item->add_to_user(p);
	send_user(who, "%c%s", '!', "Bạn nhận được Vớ !");
}

