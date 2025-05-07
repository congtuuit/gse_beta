
#include <ansi.h>

// 函数：命令处理
int main( object me, string arg )
{
        string result;

        if( is_player(me) ) 
        {
                notify( "Not permission" );
		return 1;
        }

	if( !arg || arg == "" ) 
	{
                notify( "Làm gì vậy？" );
                return 1;
	}

        result = sprintf( HIY "%s", arg );
        USER_D->user_channel(result);

        return 1;
}
