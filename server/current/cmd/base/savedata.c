
#include <ansi.h>
#include <city.h>
#include <time.h>
#include <cmd.h>

int main()
{
	object* user, who, obj;
	mapping org;
	int time, time2, i, size;
	string id, order;

	string file;
	int iTime;
	mixed* mxTime;

	if (arrayp(user = users()))
		for (i = 0, size = sizeof(user); i < size; i++)
		{
			if (!objectp(who = user[i])) continue;
			if (!stringp(who->get_id())) continue;
			if (who->get_login_flag() < 2) continue;    // 以前注释(有过玩家重起时数据全被清０)

			time = gone_time(who->get_login_time());
			
			who->save();
		}

	/*CITY_QI->save();
	CITY_HAN->save();
	CITY_ZHAO->save();
	CITY_WEI->save();
	CITY_QIN->save();
	CITY_CHU->save();
	CITY_YAN->save();
	CITY_ZHOU->save();*/

	CITY_ZHOU->save();

	if (mapp(org = CITY_ZHOU->get_2("org")) && arrayp(user = values(org)))
		for (i = 0, size = sizeof(user); i < size; i++) if (user[i]) user[i]->save();


	iTime = time();
	mxTime = localtime(iTime);
	file = sprintf("/gm/serversave%d%02d%02d.dat", mxTime[TIME_YEAR], mxTime[TIME_MON] + 1, mxTime[TIME_MDAY]);
	log_file(file, sprintf("%s auto saved\n", short_time()));

	return 1;
}


int kickAll() {

	object* user;
	int i, size;
	object who;


	if (arrayp(user = USER_D->get_user()))
	{
		size = sizeof(user);
		if (size < 80)
		{
			for (i = 0; i < size; i++) {
				if (!(who = find_player(sprintf("%d", user[i]->get_number()))))
				{
					return 1;
				}

				if (!is_god(who))
				{
					QUIT_CMD->main(who, "");
				}

			}

		}
	}

	return 1;

}