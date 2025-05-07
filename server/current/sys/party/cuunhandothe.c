/********************************************************************************************************************************
-----------------------Cứu Nhân Độ Thế --------------------
********************************************************************************************************************************/

#include <time.h>
#include <ansi.h>
#include <cmd.h>

#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

#define DanChung 			"npc/event/danchung"

void generate_scum(int number);
void destroy_scum();
object* Scum;
mapping mpNianshou;
void SAVE_BINARY() { }

void create()
{
	//	restore();
	Scum = ({});
	call_out("check_time", 1);
}

void check_time()
{
	int iTime, rate, level, z, p, x, y;
	int i, * nScene, size;
	mixed* mixTime;
	object robber;

	remove_call_out("check_time");
	iTime = time();

	mixTime = localtime(iTime);

	// cn 0
	//t2 = 1 2 3 4 5 6
	
	if (mixTime[TIME_WDAY] == 1 || mixTime[TIME_WDAY] == 3 || mixTime[TIME_WDAY] == 4  || mixTime[TIME_WDAY] == 5)
	{
		//	destroy_scum();
		call_out("check_time", 3600 * 24);
		return;
	}
	else
	{
		i = 60 * (60 - mixTime[TIME_MIN]);

		if (mixTime[TIME_HOUR] % 2 != 0)
		{
			call_out("check_time", i);
		}
		else
		{
			if (mixTime[TIME_HOUR] < 6 || mixTime[TIME_HOUR] > 23)
				call_out("check_time", i);
			else
			{
				generate_scum(6);
				call_out("check_time", i + 3600);
			}
		}
	}

}

void generate_scum(int number)
{
	int i, size, z, p, x, y, j;
	object npc;


	for (i = 0; i < number; i++)
	{
		if (!(p = efun::get_xy_point(010, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DanChung);
		npc->add_to_scene(010, x, y);
		Scum += ({ npc });
	}
	for (i = 0; i < number; i++)
	{
		if (!(p = efun::get_xy_point(020, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DanChung);
		npc->add_to_scene(020, x, y);
		Scum += ({ npc });
	}
	for (i = 0; i < number; i++)
	{
		if (!(p = efun::get_xy_point(030, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DanChung);
		npc->add_to_scene(030, x, y);
		Scum += ({ npc });
	}
	for (i = 0; i < number; i++)
	{
		if (!(p = efun::get_xy_point(040, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DanChung);
		npc->add_to_scene(040, x, y);
		Scum += ({ npc });
	}
	for (i = 0; i < number; i++)
	{
		if (!(p = efun::get_xy_point(050, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DanChung);
		npc->add_to_scene(050, x, y);
		Scum += ({ npc });
	}
	for (i = 0; i < number; i++)
	{
		if (!(p = efun::get_xy_point(060, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DanChung);
		npc->add_to_scene(060, x, y);
		Scum += ({ npc });
	}
	for (i = 0; i < number; i++)
	{
		if (!(p = efun::get_xy_point(070, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DanChung);
		npc->add_to_scene(070, x, y);
		Scum += ({ npc });
	}
	for (i = 0; i < number; i++)
	{
		if (!(p = efun::get_xy_point(080, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DanChung);
		npc->add_to_scene(080, x, y);
		Scum += ({ npc });
	}

	call_out("check_time2", 5400);

	CHAT_D->sys_channel(0, HIY"Nghe nói ngoài thành các nước xuất hiện rất nhiều dân bị nạn, các vị bằng hữu hãy giúp đỡ họ vượt qua cơn hiểm nghèo !");
	//CHAT_D->sys_channel(0, HIY"Nghe nói ngoài thành các nước xuất hiện rất nhiều dân bị nạn, các vị bằng hữu hãy giúp đỡ họ vượt qua cơn hiểm nghèo !");
	
}
void check_time2()
{
	int i, size;

	for (i = 0, size = sizeof(Scum); i < size; i++)
	{
		if (!objectp(Scum[i]))
			continue;

		Scum[i]->remove_from_scene();
		destruct(Scum[i]);
	}

	Scum -= ({ 0 });
}

