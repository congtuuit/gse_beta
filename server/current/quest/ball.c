void drop_black_ball(object me)
{
	object item, leader;
	int i, p;
	string owner, id;
	int z, x, y;
	item = new ("/item/04/0443");
	z = get_z(me);  x = get_x(me);  y = get_y(me);
	id = me->get_leader();
	if (!id) owner = me->get_id();
	else
	{
		if (leader = find_player(id))
		{
			owner = leader->get_id();
		}
		else
			owner = me->get_id();
	}
	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		TEAM_D->drop_item(item, me);
		item->set_user_id(owner);
		ITEM_EQUIP_D->init_equip_prop(item);
		item->add_to_scene(z, p / 1000, p % 1000);
		item->set("winner", me);
		item->set("time", time());
	}
	else destruct(item);

}

void drop_dacuonghoa(object me)
{
	object item, leader;
	int i, p;
	string owner, id;
	int z, x, y;
	item = new ("/item/common/dacuonghoa");
	z = get_z(me);  x = get_x(me);  y = get_y(me);
	id = me->get_leader();
	if (!id) owner = me->get_id();
	else
	{
		if (leader = find_player(id))
		{
			owner = leader->get_id();
		}
		else
			owner = me->get_id();
	}
	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		TEAM_D->drop_item(item, me);
		item->set_user_id(owner);
		ITEM_EQUIP_D->init_equip_prop(item);
		item->add_to_scene(z, p / 1000, p % 1000);
		item->set("winner", me);
		item->set("time", time());
	}
	else destruct(item);
}

void drop_keo_event_thieunhi(object me)
{
	object item, leader;
	int i, p;
	string owner, id;
	int z, x, y;
	item = new ("/item/event/KeoDuong");
	z = get_z(me);  x = get_x(me);  y = get_y(me);
	id = me->get_leader();

	return;
	if (!id) owner = me->get_id();
	else
	{
		if (leader = find_player(id))
		{
			owner = leader->get_id();
		}
		else
			owner = me->get_id();
	}
	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		TEAM_D->drop_item(item, me);
		item->set_user_id(owner);
		ITEM_EQUIP_D->init_equip_prop(item);
		item->add_to_scene(z, p / 1000, p % 1000);
		item->set("winner", me);
		item->set("time", time());
	}
	else destruct(item);
}



void drop_blue_ball(object me)
{
	object item, leader;
	int i, p;
	string owner, id;
	int z, x, y;
	item = new ("/item/04/0444");
	z = get_z(me);  x = get_x(me);  y = get_y(me);
	id = me->get_leader();
	if (!id) owner = me->get_id();
	else
	{
		if (leader = find_player(id))
		{
			owner = leader->get_id();
		}
		else
			owner = me->get_id();
	}
	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		TEAM_D->drop_item(item, me);
		item->set_user_id(owner);
		ITEM_EQUIP_D->init_equip_prop(item);
		item->add_to_scene(z, p / 1000, p % 1000);
		item->set("winner", me);
		item->set("time", time());
	}
	else destruct(item);
}

void drop_red_ball(object me)
{
	object item, leader;
	int i, p;
	string owner, id;
	int z, x, y;
	item = new ("/item/04/0445");
	z = get_z(me);  x = get_x(me);  y = get_y(me);
	id = me->get_leader();
	if (!id) owner = me->get_id();
	else
	{
		if (leader = find_player(id))
		{
			owner = leader->get_id();
		}
		else
			owner = me->get_id();
	}
	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		TEAM_D->drop_item(item, me);
		item->set_user_id(owner);
		ITEM_EQUIP_D->init_equip_prop(item);
		item->add_to_scene(z, p / 1000, p % 1000);
		item->set("winner", me);
		item->set("time", time());
	}
	else destruct(item);

}

void drop_flower_ball(object me)
{
	object item, leader;
	int i, p;
	string owner, id;
	int z, x, y;
	item = new ("/item/04/0446");
	z = get_z(me);  x = get_x(me);  y = get_y(me);
	id = me->get_leader();
	if (!id) owner = me->get_id();
	else
	{
		if (leader = find_player(id))
		{
			owner = leader->get_id();
		}
		else
			owner = me->get_id();
	}
	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		TEAM_D->drop_item(item, me);
		item->set_user_id(owner);
		ITEM_EQUIP_D->init_equip_prop(item);
		item->add_to_scene(z, p / 1000, p % 1000);
		item->set("winner", me);
		item->set("time", time());
	}
	else destruct(item);

}

void drop_event_quockhanh(object me)
{
	/*object item, leader;
	int i, p;
	string owner, id;
	int z, x, y;
	item = new ("/item/event/quockhanh/khanh");
	z = get_z(me);  x = get_x(me);  y = get_y(me);
	id = me->get_leader();
	if (!id) owner = me->get_id();
	else
	{
		if (leader = find_player(id))
		{
			owner = leader->get_id();
		}
		else
			owner = me->get_id();
	}
	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		TEAM_D->drop_item(item, me);
		item->set_user_id(owner);
		ITEM_EQUIP_D->init_equip_prop(item);
		item->add_to_scene(z, p / 1000, p % 1000);
		item->set("winner", me);
		item->set("time", time());
	}
	else destruct(item);*/

}

void drop_event_2011(object me)
{
	/*object item, leader;
	int i, p;
	string owner, id;
	int z, x, y;
	item = new ("/item/event/2011/dao");
	z = get_z(me);  x = get_x(me);  y = get_y(me);
	id = me->get_leader();
	if (!id) owner = me->get_id();
	else
	{
		if (leader = find_player(id))
		{
			owner = leader->get_id();
		}
		else
			owner = me->get_id();
	}
	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		TEAM_D->drop_item(item, me);
		item->set_user_id(owner);
		ITEM_EQUIP_D->init_equip_prop(item);
		item->add_to_scene(z, p / 1000, p % 1000);
		item->set("winner", me);
		item->set("time", time());
	}
	else destruct(item);*/

}

void drop_bao_ruong(object me)
{
	object item, leader;
	int i, p;
	string owner, id;
	int z, x, y;
	item = new ("/item/common/box/ruongdong/box");
	z = get_z(me);  x = get_x(me);  y = get_y(me);
	id = me->get_leader();
	if (!id) owner = me->get_id();
	else
	{
		if (leader = find_player(id))
		{
			owner = leader->get_id();
		}
		else
			owner = me->get_id();
	}
	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		TEAM_D->drop_item(item, me);
		item->set_user_id(owner);
		ITEM_EQUIP_D->init_equip_prop(item);
		item->add_to_scene(z, p / 1000, p % 1000);
		item->set("winner", me);
		item->set("time", time());
	}
	else destruct(item);

}

void bavuong_quest(object me) {
	me->set_save_2("hienvien.task", 1);
	send_user(me, "%c%s", '!', "Hoàn thành Bá Vương——Trợ giúp");

	send_user(me, "%c%c%c%w%s", 0x51, 1, 1, 9100, "Bá Vương");
	send_user(me, "%c%c%c%w%w%s", 0x51, 1, 2, 9100, 1, "Trợ giúp (Hoàn thành)");
}