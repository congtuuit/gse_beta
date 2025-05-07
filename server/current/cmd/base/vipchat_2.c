#include <ansi.h>
int say(string channel_id, string name_user, string arg)
{
	object who;
	string name, id, legend, chat_content;
	int t, level, time;
	string channel_name = sprintf("[Kênh %s]", channel_id);

	if (!arg)
	{
		return 1;
	}

	name_user = sprintf("%c+%d,%s=%d%c-", '\t', 243 * 256 + 229, name_user, 0, '\t');
	name_user = replace_string(name_user, "#", "＃");
	CHAT_D->vip_channel(0, sprintf(CHAT"%s %s: %s ", channel_name, name_user, arg));

	return 1;
}


int orgchat(string channel_id, string orgname, string name_user, string arg)
{
	object who;
	object* user;
	string name, id, legend, chat_content;
	int t, level, time, size, i;
	string channel_name = sprintf("[Kênh %s]", channel_id);

	if (!arg)
	{
		return 1;
	}

	name_user = sprintf("%c+%d,%s=%d%c-", '\t', 255 * 256 * 256 + 102 * 256, name_user, 0, '\t');
	name_user = replace_string(name_user, "#", "＃");

	FAMILY_D->org_channel(orgname, 0, sprintf(CHAT"%s "ECHO"%s"NOR": %s ", channel_name, name_user, arg));

	return 1;
}