#include <time.h>
#include <ansi.h>
#include <cmd.h>

#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

#define JINQIAN		"item/test2/ChienY"
#define BAOXIAN		"item/test2/ChienY"
#define BOSS		"npc/boss/CoVuong"

int iStart, iFinish;
//int *nScene = ({1,2,3,162});
int* nScene = ({ 2,3,162 });
string* nCountry = ({ "Chu Quốc","Tề Quốc","Hàn Quốc","Triệu Quốc","Ngụy Quốc","Tần Quốc","Sở Quốc","Yên Quốc", });
void generate_money();
void generate_box();
void generate_gift();

// 函数：生成二进制码
void SAVE_BINARY() { }

void create()
{
	int year = 0;
	mixed* mixTime;
	mixTime = localtime(time());
	year = mixTime[TIME_YEAR];

	iStart = mktime(year, 8, 23, 6, 0, 0);
	iFinish = mktime(year, 9, 10, 23, 0, 0);

	//	iStart = mktime(2007,1,17,13,0,0);	
	//	iFinish = mktime(2007,1,17,17,0,0);		
	call_out("check_time", 30);
}

void check_time()
{
	int iHour, iTime, i, x,y,p;
	object npc;
	mixed* mixTime;

	remove_call_out("check_time");

	if (MAIN_D->get_host_type() == 2)		//台湾除外
		return;

//	iHour = time();
//	if (iHour > iFinish)
//		return;
//	if (iHour < iStart)	//没到时间
//	{
//		call_out("check_time", iStart - iHour);
//		return;
//	}
//	call_out("check_time", 9000);//2h30
////	generate_money();
////	generate_box();
//	

	iTime = time();
	mixTime = localtime(iTime);

	iHour = time();
	if (iHour > iFinish) {
		return;
	}

	if (mixTime[TIME_WDAY] == 2 ||
		mixTime[TIME_WDAY] == 4 ||
		mixTime[TIME_WDAY] == 6
		)
	{
		i = 60 * (60 - mixTime[TIME_MIN]);
		call_out("check_time", i + 3600);
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
			if (mixTime[TIME_HOUR] == 1 ||
				mixTime[TIME_HOUR] == 2 ||
				mixTime[TIME_HOUR] == 3 ||
				mixTime[TIME_HOUR] == 4 ||
				mixTime[TIME_HOUR] == 5 ||
				mixTime[TIME_HOUR] == 6 ||
				mixTime[TIME_HOUR] == 7
				|| mixTime[TIME_HOUR] == 9
				|| mixTime[TIME_HOUR] == 11
				|| mixTime[TIME_HOUR] == 13
				|| mixTime[TIME_HOUR] == 15
				|| mixTime[TIME_HOUR] == 17
				|| mixTime[TIME_HOUR] == 19
				|| mixTime[TIME_HOUR] == 21
				|| mixTime[TIME_HOUR] == 23)
				call_out("check_time", i + 3600);
			else
			{
				if (mixTime[TIME_MIN] >= 45) {
					call_out("check_time", i + 3600);
				}
				else {

					if (mixTime[TIME_HOUR] == 12 || mixTime[TIME_HOUR] == 20) {
						npc = new(BOSS);
						npc->add_to_scene(142, 159, 138);
					}

					generate_gift();
					call_out("check_time", i + 3600);
				}

			}
		}
	}

}

void generate_money()
{
	int i, size, z, p, x, y, j, count;
	object* nObj, item;

	for (j = 0, count = sizeof(nScene); j < count; j++)
	{
		z = nScene[j];
		for (i = 0; i < 80; i++)
		{
			if (!(p = efun::get_xy_point(z, IS_CHAR_BLOCK)))
				continue;
			x = (p % 1000000) / 1000;  y = p % 1000;
			item = new(JINQIAN);
			if (!objectp(item))
				continue;
			item->set_value(40 + random(21));
			item->add_to_scene(z, x, y);
			log_file("CoTuong.txt", sprintf("%s money %d %d %d %d\n", short_time(), i, z, x, y));
		}
	}
	log_file("distribute.txt", short_time() + " Đặt tiền.\n");
	CHAT_D->rumor_channel(0, sprintf(HIY"%s nổi lên một trận cuồng phong, sau trận cuồng phong đó có rất nhiều Chiến Y đột nhiên rớt xuống ở U Cốc, Thanh Khê, Ba Khâu ! Nghe nói Sứ Giả Hoạt Động đang tìm kiếm vật phẩm này đấy !", nCountry[random(8)]));
}

void generate_box()
{
	int i, size, z, p, x, y, j, count;
	object* nObj, item;

	for (j = 0, count = sizeof(nScene); j < count; j++)
	{
		z = nScene[j];
		for (i = 0; i < 20; i++)
		{
			if (!(p = efun::get_xy_point(z, IS_CHAR_BLOCK)))
				continue;
			x = (p % 1000000) / 1000;  y = p % 1000;
			item = new(BAOXIAN);
			if (!objectp(item))
				continue;
			item->add_to_scene(z, x, y);
			//			log_file("distribute.txt",sprintf("%s box %d %d %d %d\n",short_time(),i,z,x,y));	
		}
	}
	log_file("distribute.txt", short_time() + " Phóng to gói\n");
}

void start_it()
{

}

void generate_gift()
{
	int i, size, z, p, x, y, j, count, * nPlace = ({ 1,10,20,30,40,50,60,70,80 });
	object* nObj, item;

	for (j = 0, count = sizeof(nPlace); j < count; j++)
	{
		z = nPlace[j];
		for (i = 0; i < 60; i++)
		{
			if (!(p = efun::get_xy_point(z, IS_CHAR_BLOCK)))
				continue;
			x = (p % 1000000) / 1000;  y = p % 1000;
			item = new("item/test2/CoTuong");
			if (!objectp(item))
				continue;
			item->add_to_scene(z, x, y);
			item->set("time", time());

			//log_file("distribute.txt",sprintf("%s box %d %d %d %d\n",short_time(),i,z,x,y));	
		}
	}

	log_file("cotuong.txt", short_time() + " Rơi cờ tướng\n");
	CHAT_D->sys_channel(0, " Rất nhiều Cờ Tướng đã rơi xuống Tân Thủ Thôn và ngoài thành 7 Quốc Gia, Nghe nói Tiên Cô Thiên Sứ - Tiểu Long Nữ đang tìm kiếm những cái Cờ Tướng này !");
}