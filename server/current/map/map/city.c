
inherit SCENE;

//Load NPC theo kenh
void create()
{
	mapping char;
	object npc;
	string* key;
	int z, x, y, d, p, i, size;

	//kenh 1
	if (MAIN_D->get_region() == 1) {
		MAP_D->load_npc_file(this_object(), "/map/npc/city.npc");
	}
	//kenh2
	else {
		MAP_D->load_npc_file(this_object(), "/map/npc/city2.npc");
	}

	if (mapp(char = get_xy_dbase()))
	{
		size = sizeof(key = keys(char));
		for (i = 0; i < size; i++)
		{
			if (!sscanf(key[i], "%d-%d,%d,%d", z, x, y, d)
				|| !(p = get_valid_xy(z, x, y, IS_CHAR_BLOCK))
				|| !load_object(char[key[i]])) continue;

			npc = new(char[key[i]]);
			npc->add_to_scene(z, p / 1000, p % 1000, d);
			set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
			add_npc(key[i], npc);
		}
	}
}
