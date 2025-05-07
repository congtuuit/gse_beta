
#include <ansi.h>

// 函数：命令处理
int main( object me, string arg )
{
        string result;

        if( is_player(me) ) 
        {
                notify( "You do not have sufficient permissions" );
		return 1;
        }

	if( !arg || arg == "" ) 
	{
                notify( "Error" );
                return 1;
	}

        result = sprintf( HIY "%s", arg );
        USER_D->user_channel(result);

        return 1;
}
