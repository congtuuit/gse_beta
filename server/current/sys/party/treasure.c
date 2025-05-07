/*****************************
	**挖宝**
*****************************/
#include <time.h>
#include <ansi.h>
#include <cmd.h>

#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

inherit SAVE_F;
int iStart1,iFinish1;
int check_time();
void generate_chutou(object who);
void set_open(object who,string arg);
void set_close(object who);
int is_open();
void next_session();
void active_party();
void SAVE_BINARY(){}
string get_save_file()	{ return "data/wabaozongdongyuan"SAVE_EXTENSION;}
void create()
{
	restore();
	active_party();
	check_time();
}

int check_time()
{
	int iHour;
	int interval;
	int year = 0, i, pass, pass2;
	mixed* mixTime;
	mixTime = localtime(time());

	remove_call_out("check_time");
	iHour = time();

	i = 60 * (60 - mixTime[TIME_MIN]);

	if (mixTime[TIME_HOUR] == 9 ||
		mixTime[TIME_HOUR] == 19
		) {

		if (mixTime[TIME_MIN] >= 50) {
			call_out("check_time", i);
		}
		else {
			USER_D->user_channel("Chiến dịch đào kho báu đã chính thức bắt đầu，Đi đi"
				HIR"Vương bộ đầu Chu Quốc"NOR" để nhận lấy cuốc");
			call_out("check_time", i + 3600);
		}

	}
	else {
		pass = mixTime[TIME_HOUR] - 9;
		pass2 = mixTime[TIME_HOUR] - 19;

		if (pass == 1 || pass2 == 1) {
			USER_D->user_channel("Thời gian khai quật truy tìm kho báu đã kết thúc, hãy chờ đến lần sau~");
		}

		call_out("check_time", i);
	}


	//if( iHour < iStart1)
	//{
	//	if((interval = iStart1 - iHour)<=300)
	//	{
	//		USER_D->user_channel(sprintf("Việc khai thác các kho báu %d sẽ bắt đầu trong vài phút，vui lòng đợi"
	//		"chuẩn bị，ở "HIR"Vương bộ đầu Chu Quốc"NOR" Nhận lấy cái cuốc kho báu", interval/60));
	//		call_out("check_time",interval);
	//	}
	//	else
	//	{
	//		call_out("check_time",interval- 300);
	//	}
	//}
	//else if(iHour >= iStart1&& iHour < iFinish1)
	//{
	//	USER_D->user_channel("Chiến dịch đào kho báu đã chính thức bắt đầu，Đi đi"
	//	HIR"Vương bộ đầu Chu Quốc"NOR" để nhận lấy cuốc");
	//	call_out("check_time",iFinish1-iHour);
	//}
	//else if(iHour >= iFinish1)
	//{
	//	if((interval = iHour - iFinish1)< 30)
	//	{
	//		USER_D->user_channel("Hôm nay, nỗ lực khai quật kho báu đã kết thúc，Tôi có một cái xẻng đào kho báu"
	//		"Người chơi có thể tiếp tục đào kho báu。Hãy chờ đến lần sau~");
	//		//next_session();
	//	}
	//}	

}


void next_session()
{
	mixed time_info ;
	time_info= localtime(iStart1);

	if(time_info[TIME_WDAY] == 6)
	{
		iStart1 = iFinish1 + 3600*24;
		iFinish1 = iStart1 + 3600;
		call_out("check_time",3);
		save();
	}

	if(time_info[TIME_WDAY] == 0)
	{
		iStart1 = iFinish1+ 3600*24*6;
		iFinish1 = iStart1 + 3600;
		call_out("check_time",3);
		save();
	}
}

void generate_chutou(object who)
{
	int move_result;
	object goods;
	goods = new("item/std/hoe");
	if(!goods)
	{
		return ;
	}
	if(move_result = goods->move(who,-1))
	{
		goods->add_to_user(move_result);
	}
	else
	{
		destruct(goods);
	}
}

void set_open(object who,string arg)
{
	int year,mon,day,hour,min;
	string cTmp1,cTmp2;
	if ( sscanf(arg ,"%s-%s",cTmp1,cTmp2) != 2 )
	{
		send_user(who,"%c%s",'!',"Sai định dạng！");	
		return 0;
	}

	//20070518 2000
	year = to_int(cTmp1[0..3]);
	mon = to_int(cTmp1[4..5]);
	day = to_int(cTmp1[6..7]);
	hour = to_int(cTmp1[8..9]);
	min = to_int(cTmp1[10..11]);

	iStart1 = mktime(year,mon,day,hour,min,0);	//活动开始时间

	year = to_int(cTmp2[0..3]);
	mon = to_int(cTmp2[4..5]);
	day = to_int(cTmp2[6..7]);
	hour = to_int(cTmp2[8..9]);
	min = to_int(cTmp2[10..11]);

	iFinish1 = mktime(year,mon,day,hour,min,0);	//结束时间

	if ( !iStart1 || !iFinish1 )
	{
		send_user(who,"%c%s",'!',"Không đúng lúc！");	
		return 0;
	}
	if ( iStart1 > iFinish1 || iFinish1 < time() )
	{
		send_user(who,"%c%s",'!',"Không đúng lúc！！");	
		return 0;
	}

	tell_user(who,"Bắt đầu đào kho báu：%s！",arg);	
	send_user(who,"%c%s",'!',"Bắt đầu đào kho báu！");
	call_out("check_time",3);	
	check_time();
	save();
}

void set_close(object who)
{
	remove_call_out("check_time");
	iStart1 = 0;
	iFinish1 = 0;
	send_user(who,"%c%s",'!',"Đóng kho báu！");
	save();
}


void active_party() {
	int year = 0;
	mixed* mixTime;
	mixTime = localtime(time());
	year = mixTime[TIME_YEAR];

	iStart1 = mktime(year, 1, 1, 1, 0, 0);
	iFinish1 = mktime(year, 12, 30, 0, 0, 0);

}


int is_valid_time() {
	int year = 0;
	mixed* mixTime;
	mixTime = localtime(time());

	if (mixTime[TIME_HOUR] == 9 ||
		mixTime[TIME_HOUR] == 19
		) {

		return 1;
	}
	else {
		return 0;
	}
}


int is_open()
{
	int iHour = time();

	if(!iStart1 || !iFinish1)
	{
		return 0;
	}

	if(iHour >= iStart1 && iHour < iFinish1)
	{
		return 1;
	}
	else if(iHour >= iFinish1)
	{
		return 0;
	}	
}
