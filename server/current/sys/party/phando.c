/************************************************************************************
			-----------------------Cấm Vệ Quân Phản Đồ--------------------
*************************************************************************************/

#include <time.h>
#include <ansi.h>
#include <cmd.h>

#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

#define PhanDo 			"npc/event/phando"

void generate_scum();
void destroy_scum();
int *nScene = ({010,020,030,040,050,060,070});

int* schoolMap = ({ 289,273,80,324,269,54,165 });
string* schoolname = ({ "Đào Hoa Nguyên", "Thục Sơn", "Cấm Vệ Quân", "Đường Môn", "Mao Sơn", "Côn Luân", "Vân Mộng Cốc", });
string *cityname = ({"Tề Quốc", "Hàn Quốc", "Triệu Quốc", "Ngụy Quốc", "Tần Quốc", "Sở Quốc", "Yên Quốc", });
object *Scum;
mapping mpNianshou;
// 函数：生成二进制码
void SAVE_BINARY() { }

int iStart, iFinish;
void create()
{
//	restore();
	Scum = ({});


	int year = 0;
	mixed* mixTime;
	mixTime = localtime(time());
	year = mixTime[TIME_YEAR];


	iStart = mktime(year, 6, 4, 8, 0, 0);
	iFinish = mktime(year, 6, 30, 23, 0, 0);

	call_out("check_time",1);
}

void check_time()
{
	int iTime, rate, level, z, p, x, y;
	int i,*nScene,size;
	mixed *mixTime;
	object robber;
	
	remove_call_out("check_time");
	iTime = time();
	if (iTime > iFinish)
		return;
	if (iTime < iStart)
		return;

	mixTime = localtime(iTime);

	i = 60*(60-mixTime[TIME_MIN]);

	if ( mixTime[TIME_HOUR] < 9 )
	{
		call_out("check_time",i);
	} else if (mixTime[TIME_HOUR] > 22)
	{
		call_out("check_time", i+3600);
	} 
	else if(mixTime[TIME_MIN] > 30)
	{
		call_out("check_time",i);
	}
	else {
		generate_scum();
		call_out("check_time", i + 3600);
	}
}

void generate_scum()
{
	int i,size,z,p,x,y,j;
	object npc;

	destroy_scum();
	j = random(7);
	z = schoolMap[j];
	for (i = 0; i < 10; i++)
	{
		if (!(p = efun::get_xy_point(z, IS_CHAR_BLOCK)))
			continue;
		x = (p % 1000000) / 1000;
		y = p % 1000;
		npc = new(PhanDo);
		npc->add_to_scene(z, x, y);
		Scum += ({ npc });
	}

	call_out("check_time2",3000);

	CHAT_D->sys_channel(0, sprintf(HIC "Nghe nói có một đám Phản đồ của Cấm Vệ Quân đang tụ tập bầy mưu tính kế tại "HIY"%s"HIR " ,anh hùng tứ phương hãy ra tay trợ giúp "HIY "%s đệ tử"HIR " tiêu diệt đám bại hoại này.", schoolname[j], schoolname[j]));
	CHAT_D->sys_channel(0, sprintf(HIC "Nghe nói có một đám Phản đồ của Cấm Vệ Quân đang tụ tập bầy mưu tính kế tại "HIY"%s"HIR " ,anh hùng tứ phương hãy ra tay trợ giúp "HIY "%s đệ tử"HIR " tiêu diệt đám bại hoại này.", schoolname[j], schoolname[j]));
}

void destroy_scum()
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

//Sau 55 phút từ khi Phản Đồ xuất hiện, Phản Đồ sẽ tự động biến mất 
void check_time2()
{
	int i,size;
	
	for(i=0,size=sizeof(Scum);i<size;i++)
	{
		if ( !objectp(Scum[i])	)
			continue;

		Scum[i]->remove_from_scene();
		destruct(Scum[i]);
	}
	Scum -= ({ 0 });
}