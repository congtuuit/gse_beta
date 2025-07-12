/*******************************
	**门派偷袭战**
*******************************/

#include <time.h>
#include <ansi.h>
#include <cmd.h>

#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

void generate_scum();
void destroy_scum();
int* nScene = ({ 289,273,80,324,269,54,165 });
string* schoolname = ({ "Đào Hoa Nguyên", "Thục Sơn", "Cấm Vệ Quân", "Đường Môn", "Mao Sơn", "Côn Luân", "Vân Mộng Cốc", });
object* Scum;
mapping mpNianshou;
// 函数：生成二进制码
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

	if (MAIN_D->get_test_mode() == 1) {
		generate_scum();
		call_out("check_time", 60 * 5); // Lặp lại sau 1 phút khi test
		return;
	}

	iTime = time();

	mixTime = localtime(iTime);

	//generate_scum();

	/*generate_scum();
	call_out("check_time", i + 3600);*/

	if (mixTime[TIME_WDAY] == 0 ||
		mixTime[TIME_WDAY] == 5) 
	{
	
		i = 60 * (60 - mixTime[TIME_MIN]);
		if (mixTime[TIME_HOUR] % 2 == 0)
		{
			call_out("check_time", i);
			log_file("debugTimeBoss.txt", short_time() + " time % 2 == 0\n");
		}
		else
		{
			if (mixTime[TIME_HOUR] == 21 && mixTime[TIME_WDAY] == 5)
			{
				generate_scum();
				call_out("check_time", i + (3600 * 2));
			}
			else if (mixTime[TIME_HOUR] == 13 && mixTime[TIME_WDAY] == 0) {
				generate_scum();
				call_out("check_time", i + (3600 * 2));
			}
			else {
				call_out("check_time", i + 3600);
				log_file("debugTimeBoss.txt", short_time() + "Time != 21\n");
			}
		}

	}
	else {
		
		call_out("check_time", 3600 * 24);
		log_file("debugTimeBoss.txt", short_time() + "Time day\n");
	}
	
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

	CHAT_D->sys_channel(0, HIY"Ngũ Hổ Tướng Chiến Trận đã kết thúc!");
	CHAT_D->sys_channel(0, HIY"Ngũ Hổ Tướng Chiến Trận đã kết thúc!");
}

void generate_scum()
{
	int i, size, z, p, x, y, j;
	object npc1;
	object npc2;
	object npc3;
	object npc4;
	object npc5;

	int mapId = 375;
	//int mapId = 910;

	destroy_scum();
	//1
	npc1 = new("/npc/event/PhoBan/5Boss/Boss1-CVQ");
	npc1->add_to_scene(mapId, 133, 35);
	Scum += ({ npc1 });
	CHAT_D->sys_channel(0, HIC "Nghe nói Ngũ Hổ Tướng "HIG"Tử Long"HIC" đã xuất hiện tại Ngũ Hổ Tướng Chiến Trận");
	//2
	npc2 = new("/npc/event/PhoBan/5Boss/Boss2-DM");
	npc2->add_to_scene(mapId, 68, 110);
	Scum += ({ npc2 });
	CHAT_D->sys_channel(0, HIC "Nghe nói Ngũ Hổ Tướng "HIG"Nhạc Phi"HIC" đã xuất hiện tại Ngũ Hổ Tướng Chiến Trận");
	//3
	npc3 = new("/npc/event/PhoBan/5Boss/Boss3-CVQ");
	npc3->add_to_scene(mapId, 112, 106);
	Scum += ({ npc3 });
	CHAT_D->sys_channel(0, HIC "Nghe nói Ngũ Hổ Tướng "HIG"Quan Vũ"HIC" đã xuất hiện tại Ngũ Hổ Tướng Chiến Trận");
	//4
	npc4 = new("/npc/event/PhoBan/5Boss/Boss4-CVQ");
	npc4->add_to_scene(mapId, 163, 102);
	Scum += ({ npc4 });
	CHAT_D->sys_channel(0, HIC "Nghe nói Ngũ Hổ Tướng "HIG"Hạng Vũ"HIC" đã xuất hiện tại Ngũ Hổ Tướng Chiến Trận");

	//5
	npc5 = new("/npc/event/PhoBan/5Boss/Boss5-CVQ");
	npc5->add_to_scene(mapId, 160, 127);
	Scum += ({ npc5 });
	CHAT_D->sys_channel(0, HIC "Nghe nói Ngũ Hổ Tướng "HIG"Tôn Vũ"HIC" đã xuất hiện tại Ngũ Hổ Tướng Chiến Trận");

	log_file("boss.txt", short_time() + " Ngũ Hổ Tướng xuất hiện\n");

	call_out("check_time2", 10800);

}

void destroy_scum()
{
	int i, size;
	for (i = 0, size = sizeof(Scum); i < size; i++)
	{
		if (!objectp(Scum[i]))
			continue;
		if (!Scum[i]->get("busy"))
		{
			Scum[i]->remove_from_scene();
			destruct(Scum[i]);
		}
		else
			Scum[i]->set("overdue", 1);
	}

	Scum -= ({ 0 });
}

