#include <time.h>
#include <ansi.h>
#include <cmd.h>

#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

// 函数：生成二进制码
void SAVE_BINARY() { }

void create()
{
	call_out("check_time", 10);
}

void check_time()
{
	remove_call_out("check_time");

	"/cmd/base/savedata"->main();

	call_out("check_time", 900);
}
