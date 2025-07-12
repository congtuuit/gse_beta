
#include <time.h>
#include <ansi.h>
#include <cmd.h>

#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

#define SDV 			"npc/boss/0021"
#define RONG 			"npc/npc/03951"
#define HUYENTHU 			"/npc/boss/huyenthu"
#define HUYENTHU_2 			"/npc/boss/huyenthu2"
#define THUONG_NHAN "npc/base/9999"
#define PHI_TAC_VUONG "npc/boss/PhiTacVuong"
#define TINH_LINH_AO_ANH "npc/boss/TinhLinhAoAnh"

void generate_scum();
void destroy_scum();
//CHAT_D->rumor_channel(0, CHAT + "Nghe nói Huyễn Thú lại xuất hiện ở Cự Thú Đảo!");
void call_rong();
void call_huyenthu();
void call_huyenthu_2(int mapId);
void call_boss_ao_canh();
void call_thuong_nhan_bi_an();
void call_PhiTacVuong();

int* nSceneBoss = ({ 10,20,30,40,50,60,70, });
string* cityname = ({ "Tề Quốc", "Hàn Quốc", "Triệu Quốc", "Ngụy Quốc", "Tần Quốc", "Sở Quốc", "Yên Quốc", });

string* schoolname = ({ "Đào Hoa Nguyên", "Thục Sơn", "Cấm Vệ Quân", "Đường Môn", "Mao Sơn", "Côn Luân", "Vân Mộng Cốc", });
object* Scum, * Scum_thuong_nhan;
mapping mpNianshou;

int called_thuong_nhan = -1;

void SAVE_BINARY() { }

void create()
{
	//	restore();
	Scum = ({});
	Scum_thuong_nhan = ({});
	call_out("check_time", 1);
}

void check_time()
{
	int iTime, rate, level, z, p, x, y, rate_thuong_nhan;
	int i, * nScene, size;
	mixed* mixTime;
	object robber;

	remove_call_out("check_time");

	if (MAIN_D->get_test_mode() == 1) {
		call_huyenthu();
		call_PhiTacVuong();
		call_boss_ao_canh();
		call_rong();
		call_thuong_nhan_bi_an();
		generate_scum();
		call_out("check_time", 60 * 5); // Lặp lại sau 1 phút khi test
		return;
	}

	iTime = time();

	mixTime = localtime(iTime);

	i = 60 * (60 - mixTime[TIME_MIN]);

	rate_thuong_nhan = random(4) + 19;
	
	if (
			((mixTime[TIME_HOUR] == 22 || mixTime[TIME_HOUR] == 20 || mixTime[TIME_HOUR] == 21))
			)
		{
			call_huyenthu();
			
			if (mixTime[TIME_HOUR] == 21)
			{
				//call_huyenthu_2(0);
				//call_huyenthu_2(1);
				//call_huyenthu_2(2);
				//call_huyenthu_2(3);
				//call_huyenthu_2(4);
				//call_huyenthu_2(5);
				//call_huyenthu_2(6);
			}
			
			
		}

	if ((mixTime[TIME_WDAY] == 0 || mixTime[TIME_WDAY] == 1 || mixTime[TIME_WDAY] == 3 || mixTime[TIME_WDAY] == 5) && mixTime[TIME_HOUR] == 21)
	{
		call_PhiTacVuong();
	}

	if ((mixTime[TIME_WDAY] == 0 || mixTime[TIME_WDAY] == 6 || mixTime[TIME_WDAY] == 2 || mixTime[TIME_WDAY] == 4) && mixTime[TIME_HOUR] == 21)
	{
		call_boss_ao_canh();
	}
		

	if (mixTime[TIME_HOUR] % 2 == 1)
	{
		call_out("check_time", i);
	}
	else
	{
		if (
			(mixTime[TIME_WDAY] == 2 || mixTime[TIME_WDAY] == 0 || mixTime[TIME_WDAY] == 4) &&
			(mixTime[TIME_HOUR] >= 19 && mixTime[TIME_HOUR] < 23)
			) {
			
			//7h cn 3 5
			call_rong();
			log_file("boss.txt", short_time() + " Thiên Long\n");
		}
	

		if (mixTime[TIME_WDAY] == 0 || mixTime[TIME_WDAY] == 3 || mixTime[TIME_WDAY] == 6) {

			//7h cn 3 5
			if (mixTime[TIME_HOUR] == rate_thuong_nhan && called_thuong_nhan != mixTime[TIME_WDAY]) {

				called_thuong_nhan = mixTime[TIME_WDAY];
				call_thuong_nhan_bi_an();
				log_file("boss.txt", short_time() + " Thương nhân\n");
					
			}
		}


		if ((mixTime[TIME_WDAY] != 0 || mixTime[TIME_WDAY] != 6) &&
			mixTime[TIME_HOUR] == 20) {
			//8h30 toi hang ngay (tru t7 va cn)
			generate_scum();
			log_file("boss.txt", short_time() + " Sơn đại vương\n");
			call_out("check_time", i);
		}
		else
		{
			call_out("check_time", i);
		}
	}
}


void generate_scum()
{
	call_out("check_time3", 1800);
}

void call_huyenthu()
{
	int i, size, z, p, x, y, j;
	object npc;

	for (i = 0; i < 1; i++)
	{
		if (!(p = efun::get_xy_point(549, IS_CHAR_BLOCK)))
			continue;

		x = p / 1000;
		y = p % 1000;
		npc = new(HUYENTHU);
		npc->add_max_hp(100000);
		npc->add_to_scene(549, 200 + random(40), 127 + random(15), 2);
		Scum += ({ npc });
	}

	call_out("check_time2", 10800);
}

void call_huyenthu_2(int mapId){
	int i, size, z, p, x, y, j, count;
	object* nObj, npc;
	
	j = mapId;
	
	z = nSceneBoss[j];

	if (!(p = efun::get_xy_point(z, IS_CHAR_BLOCK)))
		return;

	x = (p % 1000000) / 1000;
	y = p % 1000;

	npc = new(HUYENTHU_2);
	if (!objectp(npc))
		return;
		
	npc->add_max_hp(100000);
	npc->add_to_scene(z, x, y);
	Scum += ({ npc });

	call_out("check_time2", 10800);
	CHAT_D->rumor_channel(0, CHAT + sprintf("Nghe nói Huyễn Thú lại xuất hiện ở  "HIC"" + cityname[j] + " (" + x + "," + y + ")" + "!"));
}

void call_PhiTacVuong()
{
	int i, size, z, p, x, y, j;
	object npc;

	for (i = 0; i < 1; i++)
	{
		z = 536;
		if (!(p = efun::get_xy_point(z, IS_CHAR_BLOCK)))
			return;

		x = (p % 1000000) / 1000;
		y = p % 1000;

		npc = new(PHI_TAC_VUONG);
		npc->add_to_scene(z, x, y);
		Scum += ({ npc });
	}

	call_out("check_time2", 18000);
}


void call_boss_ao_canh()
{
	int i, size, z, p, x, y, j, map_level, level;
	object npc, map;

	map_level = 2;
	level = 50;

	for (i = 0; i < 1; i++)
	{
		z = 541;
		map = get_map_object(z);
		if (!(p = efun::get_xy_point(z, IS_CHAR_BLOCK)))
			return;

		x = (p % 1000000) / 1000;
		y = p % 1000;

		npc = new(TINH_LINH_AO_ANH);
		
		npc->add_to_scene(z, x, y);
		Scum += ({ npc });

		CHAT_D->rumor_channel(0, CHAT + sprintf(HIM"Nghe nói Tinh Linh Ảo Ảnh xuất hiện ở %s, mau xem thực hư thế nào?", map->get_name()));
	}

	call_out("check_time2", 18000);
}


void call_rong()
{
	int i, size, z, p, x, y, j;
	object npc;

	for (i = 0; i < 1; i++)
	{
		if (!(p = efun::get_xy_point(395, IS_CHAR_BLOCK)))
			continue;

		x = p / 1000;
		y = p % 1000;
		npc = new(RONG);
		npc->add_to_scene(395, 194 + random(40), 130 + random(15), 2);
		Scum += ({ npc });
	}

	call_out("check_time2", 18000);
}

void call_thuong_nhan_bi_an() {
	int i, size, z, p, x, y, j, count;
	object* nObj, npc;

	j = random(sizeof(nSceneBoss));
	z = nSceneBoss[j];

	if (!(p = efun::get_xy_point(z, IS_CHAR_BLOCK)))
		return;

	x = (p % 1000000) / 1000;
	y = p % 1000;

	npc = new(THUONG_NHAN);
	if (!objectp(npc))
		return;
	npc->add_to_scene(z, x, y);
	Scum_thuong_nhan += ({ npc });

	call_out("remove_thuong_nhan", 300);
	CHAT_D->rumor_channel(0, CHAT + sprintf("Nghe nói Thương nhân thần bí đang dừng chân ở "HIC"" + cityname[j] + " (" + x + "," + y + ") 5 phút sau hắn sẽ rời đi" + ", mau mau ghé xem cửa hàng hắn có gì?"));
}


void remove_thuong_nhan()
{
	int i, size;

	for (i = 0, size = sizeof(Scum_thuong_nhan); i < size; i++)
	{
		if (!objectp(Scum_thuong_nhan[i]))
			continue;

		Scum_thuong_nhan[i]->remove_from_scene();
		destruct(Scum_thuong_nhan[i]);
	}

	Scum_thuong_nhan -= ({ 0 });
}


void check_time3()
{
	int i, size, z, p, x, y, j;
	object npc;

	for (i = 0; i < 1; i++)
	{
		if (!(p = efun::get_xy_point(151, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(SDV);
		npc->add_to_scene(151, x, y);
		Scum += ({ npc });
	}

	call_out("check_time2", 21600);
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