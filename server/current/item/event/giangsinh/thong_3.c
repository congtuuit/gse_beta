#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <music.h>

inherit OFFICER;
int get_char_picid() { return 2702; }
void do_welcome(string arg);
void create_badman(object tree, int number);

#define SANTACLAUS	"npc/party/santaclaus"
#define SANTANBADMAN		"npc/party/noel"

//bien mat sau 15p
int time_remove = 900;


void reset()
{
    if (gone_time(get("birth")) > time_remove)
    {
        remove_from_scene();
        destruct(this_object());
	}
	else if (gone_time(get("birth")) % 300 == 0 ) {
		create_badman(this_object(), 3);
		call_out("reset", 1);
	}
    else {
        call_out("reset", 1);
    }

}

void create()
{
    set_name("Cây Thông Noel");
    set_2("talk", (["welcome":(:do_welcome:)]));
    setup();

    call_out("reset", 1);
}

void create_badman(object tree, int number) {
	int i, size, z, p, x, y;
	object* nObj, npc;

	x = get_x(tree);
	y = get_y(tree);
	z = get_z(tree);

	for (i = 0; i < number; i++)
	{
		if (p = get_valid_xy(z, x, y, IS_CHAR_BLOCK))
		{
			npc = new(SANTANBADMAN);
			if (!objectp(npc))
				return;

			npc->set_name("Quán Yêu Noel");
			npc->set_char_picid(1291);
			npc->set_max_hp(1);
			npc->set_ap(1);
			npc->set_dp(1);
			npc->set_cp(1);
			npc->set_pp(1);
			npc->set_sp(1);
			npc->set_walk_speed(2);
			npc->set_attack_speed(3);


			nObj = SANTACLAUS->get("plant");
			if (!arrayp(nObj))
				nObj = ({}); 

			npc->add_to_scene(z, x, y);

			nObj += ({ npc });
			SANTACLAUS->set("plant", nObj);

		}
		

	}
}

void do_look(object who)
{
    object me = this_object();
    int id = getoid(me);
    send_user(who, "%c%c%s", ':', 3, sprintf("   Cây thông noel: Thời gian tồn tại còn %d giây.\n\n"
        //ESC"Trang trí cây \ntalk %x# welcome.1\n"
        ESC"Rời khỏi", time_remove - gone_time(get("birth")) ));

}

void do_welcome(string arg)
{
	object me = this_object();
	__FILE__->do_welcome_2(me, arg);
}

void move_item_to_user(object who, int amount_s, string name)
{
	int p, total, amount;
	object item;
	string name_s;

	item = new(name);

	if (item)
	{
		name_s = item->get_name();
		if (item->get_max_combined() > 1)
		{
			total = amount_s;
			amount = USER_INVENTORY_D->carry_combined_item(who, item, total);
			if (amount > 0 && item->set_amount(amount))
			{
				if (p = item->move(who, -1))
				{
					item->add_to_user(p);
				}
			}
			else
			{
				item->add_amount(-total);
			}
		}
		else
		{
			if (p = item->move(who, -1))
			{
				item->add_to_user(p);
			}
		}

		USER_D->user_channel("Chúc mừng "HIY + who->get_name() + NOR" từ Sự kiện trang trí cây thông Noel nhận được " + HIR + name_s + ".\n");
	}
}

void do_welcome_2(object me, string arg)
{
    int x, y, z, flag;
    object who, item, player, gift, next_tree, * nObj;
    string name, cTmp, id1;
    mixed* mixTime;
    who = this_player();
    who->set_time("talk", 0);

    flag = to_int(arg);

	tell_user(who,"welcome");
	create_badman(me, 5);

    switch (flag)
    {
    case 1:
        break;
    }
}

