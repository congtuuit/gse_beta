
#include <equip.h>
int sub_time;

int is_player(object who) { return who->get_security_class() <= 1; }

int is_gm(object who)
{
	if (who->get("is_gm"))
		return 1;
	return who->get_security_class() == 2;
}

int is_gm3(object who) { return who->get_security_class() == 3; }

int is_gm2(object who) { return who->get_security_class() == 4; }

int is_god(object who) { return who->get_security_class() == 5; }

string get_class(object who)
{
	switch (who->get_security_class())
	{
	case 1:
		return PLAYER_CLASS;
	case 2:
		return GM_CLASS;
	case 3:
		return GM3_CLASS;
	case 4:
		return GM2_CLASS;
	case 5:
		return GOD_CLASS;
	default:
		return NPC_CLASS;
	}
}

int file_exist(string file) { return file_size(file) > 0; }

int directory_exist(string path) { return file_size(path) == -2; }

int user_exist(string id)
{
	if (!id)
		return 0;
	return file_size(sprintf("data/%c/%c/%c/%s/user" SAVE_EXTENSION, id[0], id[1], id[2], id)) > 0;
}

string absolute_path(object me, string path) { return FILE_D->resolve_path(me->get_cwd(), path); }

int log_file(string file, string log)
{
	int result;

	if (catch(result = efun::log_file("log/" + file, log)))
	{
		return -1;
	}

	return result;
}

int ghi_file(string file, string log)
{
	int result;

	if (catch(result = efun::log_file(file, log)))
	{
		return -1;
	}

	return result;
}

int add_debug_log(string log) { return efun::log_file("log/debug.log", log); }

string *update_file(string file)
{
	string *line;
	int i, size;

	if (!file_exist(file))
		return 0;

	line = explode(read_file(file), "\n");
	for (i = 0, size = sizeof(line); i < size; i++)
	{
		if (line[i][0] == '#')
			line[i] = 0;
		else if (line[i][ < 1] <= ' ')
			line[i] = line[i][0.. < 2];
	}

	return line;
}

int is_chinese(string name)
{
	int i, size = strlen(name);

	if (size < 1)
		return 0;
	for (i = 0; i < size; i++)
		if (name[i] == '`' || name[i] == ';' || name[i] == ',' || name[i] == ' ' || name[i] == '\'' || name[i] == '"' || name[i] == '%')
			return 0;
	// if( name[i] < 128 || name[i] > 255 ) return 0;

	return 1;
}

object find_any_object(string what)
{
	object me, *inv, item;
	int i, size;

	if (!stringp(what) || what == "")
		return 0;

	me = this_player();
	if (what == "me")
		return me;
	if (sscanf(what, "(%d)", i))
		switch (i)
		{
		case HEAD_TYPE:
			return me->get_equip(HEAD_TYPE);
		case NECK_TYPE:
			return me->get_equip(NECK_TYPE);
		case WEAPON_TYPE:
			return me->get_equip(WEAPON_TYPE);
		case ARMOR_TYPE:
			return me->get_equip(ARMOR_TYPE);
		case WAIST_TYPE:
			return me->get_equip(WAIST_TYPE);
		case BOOTS_TYPE:
			return me->get_equip(BOOTS_TYPE);
		case HAND_TYPE:
			return me->get_equip(HAND_TYPE);
		default:
			return number_present(me, i, 0, 0);
		}
	if (item = present(what, me, 0, 0))
		return item;
	if (item = find_player(what))
		return item;
	if (item = find_living(what))
		return item;
	if (item = load_object(absolute_path(me, what)))
		return item;
	if (item = load_object(what))
		return item;

	inv = me->get_all_equip();
	for (i = 0, size = sizeof(inv); i < size; i++)
		if (objectp(inv[i]) && inv[i]->id(what))
			return inv[i];
	inv = get_range_object_2(me, 5, ITEM_TYPE);
	for (i = 0, size = sizeof(inv); i < size; i++)
		if (objectp(inv[i]) && inv[i]->id(what))
			return inv[i];
	inv = get_scene_object_2(me, CHAR_TYPE);
	for (i = 0, size = sizeof(inv); i < size; i++)
		if (objectp(inv[i]) && inv[i]->id(what))
			return inv[i];
	inv = get_range_object_2(me, 5, SEAL_TYPE);
	for (i = 0, size = sizeof(inv); i < size; i++)
		if (objectp(inv[i]) && inv[i]->id(what))
			return inv[i];

	return 0;
}

object find_user_item(string what, object who)
{
	object *inv, item;
	int i, size;

	if (!stringp(what) || what == "")
		return 0;

	if (sscanf(what, "(%d)", i))
		switch (i)
		{
		case HEAD_TYPE:
			return who->get_equip(HEAD_TYPE);
		case NECK_TYPE:
			return who->get_equip(NECK_TYPE);
		case WEAPON_TYPE:
			return who->get_equip(WEAPON_TYPE);
		case ARMOR_TYPE:
			return who->get_equip(ARMOR_TYPE);
		case WAIST_TYPE:
			return who->get_equip(WAIST_TYPE);
		case BOOTS_TYPE:
			return who->get_equip(BOOTS_TYPE);
		case HAND_TYPE:
			return who->get_equip(HAND_TYPE);
		default:
			return number_present(who, i, 0, 0);
		}
	if (item = present(what, who, 0, 0))
		return item;
	inv = who->get_all_equip();
	for (i = 0, size = sizeof(inv); i < size; i++)
		if (objectp(inv[i]) && inv[i]->id(what))
			return inv[i];

	return 0;
}

// Hàm: tìm người xác định (cho lệnh GM
object find_any_char(string what)
{
	object *inv, who, me;
	int i, size;

	if (!stringp(what) || what == "")
		return 0;

	me = this_player();
	if (what == "me")
		return me;
	if (what[ < 1] != '#' && objectp(who = find_player(what)))
		return who;
	if (what[ < 1] == '#' && objectp(who = find_living(what)))
		return who;
	if (!me)
		return 0;
	inv = get_scene_object_2(me, CHAR_TYPE);
	for (i = 0, size = sizeof(inv); i < size; i++)
		if (objectp(inv[i]) && inv[i]->id(what))
			return inv[i];

	return 0;
}

// Hàm: tìm người đã xác định
object find_char(string what)
{
	if (!stringp(what) || what == "")
		return 0;
	return what[ < 1] == '#' ? find_living(what) : find_player(what);
}

// Tạo giây giờ chuẩn theo thời gian lịch
int mktime(int year, int mon, int day, int hour, int min, int sec)
{
	if (0 >= (mon -= 2))
	{			   /* 1..12 -> 11,12,1..10 */
		mon += 12; /* Puts Feb last since it has leap day */
		year -= 1;
	}

	return (((
				 (year / 4 - year / 100 + year / 400 + 367 * mon / 12 + day) +
				 year * 365 - 719499) *
				 24 +
			 hour /* now have hours */
			 ) * 60 +
			min /* now have minutes */
			) * 60 +
		   sec /* finally seconds */
		   - 28800;
}

string rawurlencode2(string code)
{
	string *input, *output, ret;
	int i, size, begin, end;
	input = ({});
	output = ({});
	ret = "";
	size = strlen(code);
	if (size == 0)
		return ret;
	for (i = 0; i < size; i += 20)
	{
		begin = i;
		end = begin + 20;
		if (end > size)
			end = size;
		end--;
		input += ({code[begin..end]});
	}
	size = sizeof(input);
	for (i = 0; i < size; i++)
	{
		output += ({rawurlencode(input[i])});
	}
	for (i = 0; i < size; i++)
		ret = ret + output[i];
	return ret;
}

int get_party_time()
{
	return time() - sub_time;
}

int set_party_time(int year, int mon, int day, int hour, int min, int sec)
{
	sub_time = time() - mktime(year, mon, day, hour, min, sec);
	return time() - sub_time;
}

// file database
string SYSTEM_DB = "/data/system/main.dat";
string system_get(string key_search)
{
	string *line, key, value = "";
	int i, size;

	line = explode(read_file(SYSTEM_DB), "\n");
	for (i = 0, size = sizeof(line); i < size; i++)
	{
		if (line[i][0] == '#' || line[i] == "")
			continue;
		if (line[i][ < 1] <= ' ')
			line[i] = line[i][0.. < 2];
		if (line[i][0] == '#' || line[i] == "")
			continue;
		if (!sscanf(line[i], "%s : %s", key, value))
		{
			continue;
		}

		if (key == key_search)
		{
			break;
		}
	}

	return value;
}

int system_set(string key_search, string value)
{
	string *line, key, content = "", old_value;
	int i, size, existed = 0;

	line = explode(read_file(SYSTEM_DB), "\n");
	for (i = 0, size = sizeof(line); i < size; i++)
	{
		if (line[i][0] == '#' || line[i] == "")
			continue;
		if (line[i][ < 1] <= ' ')
			line[i] = line[i][0.. < 2];
		if (line[i][0] == '#' || line[i] == "")
			continue;
		if (!sscanf(line[i], "%s : %s", key, old_value))
		{
			continue;
		}

		if (key == key_search)
		{
			content += sprintf("%s : %s\n", key_search, value);
			existed = 1;
			continue;
		}

		content += line[i] + "\n";
	}

	if (existed == 1)
	{
		rm(SYSTEM_DB);
		write_file(SYSTEM_DB, content);
	}
	else
	{
		ghi_file(SYSTEM_DB, sprintf("%s : %s\n", key_search, value));
	}

	return 1;
}

int system_delete_all()
{
	rm(SYSTEM_DB);
	write_file(SYSTEM_DB, "");
	return 1;
}

int get_this_channel(object me)
{
	return me->get_channel();
}

object *filter_by_channel(object *users, int channel)
{
	return filter_array(users, ( : get_this_channel($1) == $2 || get_this_channel($1) == 0 :), channel);
}

// OPTIMIZED
object *get_range_object_2_by_channel(object me, int range, int type)
{
    object *objects, *result;
    int i, sz, channel;

    // Lấy tất cả đối tượng trong phạm vi
    objects = get_range_object_2(me, range, type);

    // Không cần lọc nếu không phải người
    if (type != USER_TYPE && type != CHAR_TYPE) return objects;

    // Khởi tạo kênh và kết quả
    channel = me->get_channel();
    result = ({});

    sz = sizeof(objects);
    for (i = 0; i < sz; i++)
    {
        object obj = objects[i];
        if (!objectp(obj)) continue;

        if ((obj->is_user() || obj->is_player()) && obj->get_channel() == channel)
        {
            result += ({ obj });
        }
    }

    // Chèn chính mình nếu cần
    if ((me->is_user() || me->is_player()) && member_array(me, result) == -1)
    {
        result += ({ me });
    }

    return result;
}
