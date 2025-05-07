#include <time.h>

string get_time_string( int time );
string get_full_time_string( int time );

// 函数：命令处理
int main( object me, string arg )
{
        int time = gone_time( me->get_login_time() );
        mixed* mixTime;


        mixTime = localtime(time());

        if ( arg )
        {
        	tell_user( me, "Nhập thời gian：%s [%s]。", short_time( to_int(arg) ));
        	return 1;
        }

        tell_user( me, sprintf("Thời gian hiện tại： %s %s", get_full_time_string(time()), short_time( time()) ) );
        tell_user( me, GAME_NAME " Đã chạy %s", get_time_string( uptime() ) );
        tell_user( me, "Bạn đã trải" GAME_NAME "trong game %s，trải nghiệm %s",
                get_time_string( me->get_game_time() + time ), get_time_string( me->get_online_time() ) );
	if (me->get_double_time()-time-me->get_game_time()>0)
		tell_user( me, "Thời gian nhân đôi kinh nghiệm đóng băng còn %d giây",  me->get_double_time()-time-me->get_game_time() );
        tell_user( me, "Sinh nhật của bạn： %s。" ,short_time( me->get_birthday() ) );
        
        if (is_god(me)) {
            tell_user(me, "Day %d month %d %d ", mixTime[TIME_MDAY], mixTime[TIME_MON] + 1, mixTime[TIME_YEAR]);
        }

        return 1;
}

// 函数：获取时间字串

string get_full_time_string(int _time)
{
    int day, hour, min, sec, iTime;
    string result = "", thu;
    mixed* mixTime;
    string* dayOfWeek = ({ "Chủ Nhật", "Thứ Hai", "Thứ Ba", "Thứ Tư", "Thứ Năm", "Thứ Sáu", "Thứ Bảy", });

    iTime = time();
    mixTime = localtime(iTime);

    _time = abs(_time);

    sec = _time % 60;   _time /= 60;
    min = _time % 60;   _time /= 60;
    hour = _time % 24;  _time /= 24;
    day = _time;

    thu = dayOfWeek[mixTime[TIME_WDAY]];

    if (thu) result += sprintf("%s ", thu);
    /*if (day) result += sprintf("Ngày %d ", day);
    if (hour) result += sprintf(" %d Giờ", hour);
    if (min) result += sprintf(" %d Phút", min);
    result += sprintf(" %d Giây", sec);*/

    return result;
}

string get_time_string( int time )
{
        int day, hour, min, sec, iTime;
        string result = "", thu;
        mixed* mixTime;

        time = abs(time);

        sec = time % 60;   time /= 60;
        min = time % 60;   time /= 60;
        hour = time % 24;  time /= 24;
        day = time;

        if( day ) result += sprintf( "Ngày %d ", day );
        if( hour ) result += sprintf( " %d Giờ", hour );
        if( min ) result += sprintf( " %d Phút", min );
        result += sprintf( " %d Giây", sec );

        return result;
}

// 函数：获取时间字串(简短)
string get_time_string_2( int time )
{
        int min, sec;
        string result = "";

        time = abs(time);

        sec = time % 60;   time /= 60;
        min = time % 60;

        if( min ) result += sprintf( " %d Phút", min );
        result += sprintf( " %d Giây", sec );

        return result;
}


string get_time_string_3(int time)
{
    int day, hour, min, sec, iTime;

    string result = "";

    time = abs(time);

    sec = time % 60;   time /= 60;
    min = time % 60;   time /= 60;
    hour = time % 24;  time /= 24;
    day = time;

    if (day) result += sprintf("%d Ngày ", day);
    if (hour) result += sprintf(" %d Giờ", hour);

    if (result == "")
        result = "0";

    return result;
}

