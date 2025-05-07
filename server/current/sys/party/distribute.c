#include <ansi.h>
#include <time.h>
#define JINQIAN		"item/std/0001"
#define BAOXIAN		"item/80/0003"

int iStart,iFinish;
int *nScene = ({1,2,3,162});
string *nCountry = ({"Chu Quốc","Tề Quốc","Hàn Quốc","Triệu Quốc","Ngụy Quốc","Tần Quốc","Sở Quốc","Yên Quốc",});
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

	iStart = mktime(year,2,16,19,0,0);
	iFinish = mktime(year,2,27,0,0,0);
	
	call_out("check_time",30);
}

void check_time()
{
	int iHour;
	mixed *mixTime;

	remove_call_out("check_time");
	if (MAIN_D->get_host_type()==2)		//台湾除外
		return ;
	iHour = time();
	if ( iHour > iFinish )
		return ;
	if ( iHour < iStart )	//没到时间
	{
		call_out("check_time",iStart - iHour);
		return ;
	}
	call_out("check_time",3600);
//	generate_money();
//	generate_box();
	generate_gift();
}

void generate_money()
{
	int i,size,z,p,x,y,j,count;
	object *nObj,item;
	
	for(j=0,count=sizeof(nScene);j<count;j++)
	{
		z = nScene[j];
		for(i=0;i<80;i++)
		{
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
				continue;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			item = new(JINQIAN);
			if ( !objectp(item) )
				continue;
			item->set_value(40+random(21));
			item->add_to_scene(z,x,y);	
//			log_file("distribute.txt",sprintf("%s money %d %d %d %d\n",short_time(),i,z,x,y));	
		}
	}
	log_file("distribute.txt",short_time() + " Cất tiền đi\n" );
	CHAT_D->rumor_channel(0,sprintf(HIR "%s Có một cơn gió mạnh.Sau cơn bão, có vẻ như có vài thứ rơi vào làng non nớt, hoang dã, hoang dã, và Bach.",nCountry[random(8)]));
}

void generate_box()
{
	int i,size,z,p,x,y,j,count;
	object *nObj,item;
	
	for(j=0,count=sizeof(nScene);j<count;j++)
	{
		z = nScene[j];
		for(i=0;i<20;i++)
		{
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
				continue;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			item = new(BAOXIAN);
			if ( !objectp(item) )
				continue;
			item->add_to_scene(z,x,y);	
//			log_file("distribute.txt",sprintf("%s box %d %d %d %d\n",short_time(),i,z,x,y));	
		}
	}
	log_file("distribute.txt",short_time() + " Rơi quà\n" );
}

void start_it()
{
	
}

void generate_gift()
{
	int i,size,z,p,x,y,j,count,*nPlace=({1,10,20,30,40,50,60,70});
	object *nObj,item;
	
	for(j=0,count=sizeof(nPlace);j<count;j++)
	{
		z = nPlace[j];
		for(i=0;i<50;i++)
		{
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
				continue;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			item = new("item/04/0419");
			if ( !objectp(item) )
				continue;
			item->add_to_scene(z,x,y);	
//			log_file("distribute.txt",sprintf("%s box %d %d %d %d\n",short_time(),i,z,x,y));	
		}
	}
	log_file("distribute.txt",short_time() + " 放Túi quà lớn\n" );
	CHAT_D->sys_channel( 0, HIR"Một nhóm mới Túi quà lớn Nó mới mẻ bên ngoài các thành phố của các quốc gia khác nhau. Có lẽ s ẽ có một ngạc nhiên." ); 
}