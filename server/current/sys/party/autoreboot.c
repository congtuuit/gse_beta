#include <time.h>
#include <cmd.h>
#include <public.h>

#define TimeOFF		3

void SAVE_BINARY() { }

void create()
{
	call_out("check_time", 10);
}

void check_time()
{
	int iTime, i;
	mixed* mixTime;

	remove_call_out("check_time");

	iTime = time();
	mixTime = localtime(iTime);
	i = 60 * (60 - mixTime[TIME_MIN]);


	if (mixTime[TIME_HOUR] == TimeOFF) {
		log_file("autoReboot.txt", sprintf("%s auto reboot\n", short_time()));
		"/cmd/sys/reboot2"->main("autoshutdown", "30");
		return;
	}

	call_out("check_time", i);
}
