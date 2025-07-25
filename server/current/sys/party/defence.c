/*****劫宝飞贼大搜捕****/

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <time.h>
#include <action.h>
#include <map.h>

#define MAX_DEFENCE	77

mapping DefenceMap = ([ ]);	

int defencecount;
int endcount;
int War;
int State;

void start_defence();
void end_defence();

void SAVE_BINARY() { }

void create()
{
	start_defence();
	call_out("check_time",1);
}

int get_end_count()
{
	return endcount;
}

int set_end_count(int flag)
{
	return endcount = flag;
}

int add_end_count(int flag)
{
	return set_end_count( endcount + flag);
}

int get_count()
{
	return defencecount;
}

int set_count(int flag)
{
	return defencecount = flag;
}

int get_state()
{
	return State;
}

int set_state(int flag)
{
	return State = flag;
}

object * get_city_war(int z)
{
	z /= 10;
	if (sizeof(DefenceMap[z])==0) return ({ });
	return DefenceMap[z];
}

void check_time()
{
	int iTime,rate,level,z,p,x,y;
	int i,*nScene,size;
	mixed *mixTime;
	object robber;

	remove_call_out("check_time");

	return;

	call_out("check_time", 60);
	iTime = time();
	mixTime = localtime(iTime);	


	//if ("/sys/sys/count"->get_war_flag1()<=0 && get_state()==0)
	//{
	//	return;
	//}

	//start_defence();

	if (War==0)
	{
		if ( mixTime[TIME_WDAY] != 6 )
		{
			return ;
		}
		if ( mixTime[TIME_HOUR] == 20 && mixTime[TIME_MIN]== 20 )
		{
			start_defence();
		}
		return;
	}

	War++;

	if (War==11)
	{
		CHAT_D->sys_channel(0,HIY"Yêu ma đã có ý định xâm lấn thành của các quốc gia, hiện "HIR "Thất Quốc Đại Tướng Quân "HIY" đang chiêu binh để bảo vệ thành.Các anh hùng hãy nhanh nhanh trợ giúp !");
	}
	else
	if (War%11==0) CHAT_D->sys_channel(0,HIY"Yêu ma đã có ý định xâm lấn thành của các quốc gia, hiện "HIR "Thất Quốc Đại Tướng Quân "HIY" đang chiêu binh để bảo vệ thành.Các anh hùng hãy nhanh nhanh trợ giúp !");
	
	if (get_end_count()>=MAX_DEFENCE)
	{
		War=0;
		set_state(0);
	}
}

void start_defence()
{
	object map;
	int i, j, z, p;
	end_defence();
	War = 1;
	set_state(1);
	set_end_count(0);
	set_count(get_count()+1);

	CHAT_D->sys_channel(0,HIY"Nghe nói Yêu Ma sau "HIR "10 phút"HIY" nữa sẽ công thành.Hiện"HIR " Thất Quốc Đại Tướng Quân"HIY" đã bắt đầu chiêu binh, anh hùng hào kiệt nhanh nhanh đến trợ giúp!");
	
	DefenceMap[1] = ({ });
	DefenceMap[2] = ({ });
	DefenceMap[3] = ({ });
	DefenceMap[4] = ({ });
	DefenceMap[5] = ({ });
	DefenceMap[6] = ({ });
	DefenceMap[7] = ({ });

	for (i=0;i<4;i++)
	{
		for (j=1;j<=7;j++)
		{
			if( ( z = find_map_flag(NEWBIE_MAP_BEGIN, NEWBIE_MAP_END, 0) ) > 0 )
			{
				p = 886;
				init_virtual_map(z, p);    // 生成虚拟地图
				map = new ("/inh/std/defence");
				map->set_client_id(p);
				set_map_object( map, map->set_id(z) );
				map->set_level(i, j);
				map->init_place(map);
				DefenceMap[j] += ({ map });
			}
		}
	}
}

void end_defence()
{
	object * all, map;
	int i, size;
	all = ({ });
	for (i=1;i<=7;i++)
	{
		if (DefenceMap[i]!=0) all += DefenceMap[i];
	}
	all -= ({ 0 });
	size = sizeof(all);
	for (i=0;i<size;i++)
	{
		if (map = all[i])
		{
			map->before_destruct();
		}
	}
	DefenceMap[1] = ({ });
	DefenceMap[2] = ({ });
	DefenceMap[3] = ({ });
	DefenceMap[4] = ({ });
	DefenceMap[5] = ({ });
	DefenceMap[6] = ({ });
	DefenceMap[7] = ({ });	
	set_state(0);
}

void do_defence(object me, object who, string arg)
{
	int flag, id, z, i, size, begin, end, p, x, y;
	string result, name;
	object * all;
	flag = to_int(arg);
	id = getoid(who);
	z = get_z(who);
	switch(flag)
	{
	case 1:
		result = sprintf("%s\n    Theo thám thử hồi báo, có rất nhiều Yêu Ma đang tụ tập quanh thành, thấy ngươi là người học võ, vậy ngươi có thể giúp ta bảo vệ Thành được không ?\n", who->get_name());
		result += sprintf(ESC"Tìm hiểu Quy Tắc\ntalk %x# defence.2\n",id);
		result += sprintf(ESC HIY "Tham gia chiến đấu\ntalk %x# defence.10\n",id);
		result += ESC"Rời khỏi";
		send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
		break;
	case 2:
		result = sprintf("%s\n    Nhiệm vụ của ngươi là ngăn cản quái vật xâm nhập vào thành, một khi quái vật xâm nhập số lượng đạt tới 100 con thì nhiệm vụ sẽ thất bại, mặt khác nếu tích luỹ quái vật đạt tới 250 con nhiệm vụ cũng sẽ thất bại,  nhưng ngươi phải nhớ Yêu Ma thật sự là rất mạnh !\n", who->get_name());
		result += ESC"Rời khỏi";
		send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
		break;
	case 10:

		if (__FILE__->get_state()==0)
		{
			result = sprintf("%s\n    Vào ngày"HIR " thứ bảy lúc 20:30 phút"NOR ", quái vật sẽ xâm nhập thành, tới lúc đó ngươi hãy giúp ta bảo vệ bản thành này !\n", who->get_name());
			result += ESC"Rời khỏi";
			send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
			break;
		}

		result = sprintf("%s\n    Xin hãy lựa chọn Chiến Trường tương xứng cấp bậc\n", who->get_name());
		all = get_city_war(z);
		if (sizeof(all)!=4)
		{
			result += ESC"Rời khỏi";
			send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
			break;
		}
		result += sprintf(ESC"Huyền Vũ Môn Thủ (40 - 60 cấp)(Nhân số: %d/40)\ntalk %x# defence.11\n", all[0]->sizeof_player_dbase(), id);
		result += sprintf(ESC"Chu Tước Môn Thủ (50 - 70 cấp)(Nhân số: %d/40)\ntalk %x# defence.12\n", all[1]->sizeof_player_dbase(), id);
		result += sprintf(ESC"Thanh Long Môn Thủ (60 - 80 cấp)(Nhân số: %d/40)\ntalk %x# defence.13\n", all[2]->sizeof_player_dbase(), id);
		result += sprintf(ESC"Bạch Hổ Môn Thủ (81 cấp trở lên)(Nhân số: %d/40)\ntalk %x# defence.14\n", all[3]->sizeof_player_dbase(), id);
		result += ESC"Rời khỏi";
		send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
		break;
	case 11:
	case 12:
	case 13:
	case 14:
		switch(flag-11)
		{
		case 0: begin = 40; end = 60; name = "Huyền Vũ Môn"; break;
		case 1: begin = 50; end = 70; name = "Chu Tước Môn"; break;
		case 2: begin = 60; end = 80; name = "Thanh Long Môn"; break;
		case 3: begin = 81; end = 200; name = "Bạch Hổ Môn"; break;
		}
		if (me->get_level()<begin)
		{
			result = sprintf("%s\n    Thực lực của ngươi không đủ để tham gia Chiến Trường %s, hãy lựa chọn cấp bậc tương thích đi !\n", who->get_name(), name);
			result += ESC"Rời khỏi";
			send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
			break;
		}
		if (me->get_level()>end)
		{
			result = sprintf("%s\n    Thực lực của ngươi nếu đi Chiến Trường %s thì quá dễ dàng, hãy lựa chọn cấp bậc tương thích đi !\n", who->get_name(), name);
			result += ESC"Rời khỏi";
			send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
			break;
		}

		all = get_city_war(z);
		if (sizeof(all)!=4) return;
		flag -= 11;

	/*	if (all[flag]->get_war()==2)
		{
			result = sprintf("%s\n    Thật xin lỗi, chiến tranh đã chấm dứt.\n", who->get_name() );
			result += ESC"Rời khỏi";
			send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
			break;
		}*/

		all[flag]->sub_player(me);
		if (all[flag]->sizeof_player_dbase()>=40)
		{
			result = sprintf("%s\n    Thật xin lỗi, Chiến Trường đã đạt nhân số cao nhất, ngươi hãy lựa chọn Chiến Trường khác thích hợp đi !\n", who->get_name() );
			result += ESC"Rời khỏi";
			send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
			break;
		}		
		z = all[flag]->get_id();
		if (random(2)) p = get_jumpin(z, 11);
		else p = get_jumpin(z, 12);
		if( p )
		{
			me->add_to_scene(z, p / 1000, p % 1000, 3);
			send_user(me, "%c%w", 0x1f, 8860);
			all[flag]->add_player(me);
		}		
	}
}

void before_destruct()
{
	end_defence();
}