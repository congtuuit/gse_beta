
#include <ansi.h>
#include <cmd.h>

#define KICKOUT_LOG     "gm/kickout.txt"        // 踢人日志文件

string get_name() { return "游戏系统"; }

// 函数：命令处理
int main( object me, string arg )
{
        object who;

        if( me != this_player(1) || is_player(me) ) 
        {
                notify( "Bạn không có đủ quyền。" );
		return 1;
        }

	if( !arg ) 
        {
                send_user( me, "%c%c%d%s", '?', 1, 0, sprintf( "Buộc người chơi đang ẩn。\n\nVui lòng nhập sốＩＤ：\n"
                        ESC "kickout %%s\n" ) );
                return 1;
        }

	if( !( who = find_player(arg) ) )
        {
                notify( "您找不到这位玩家。" );
		return 1;
        }
        if( who == me )
        {
                notify( "不能强迫自己离线。" );
		return 1;
        }
        if( me->get_security_class() < who->get_security_class() )
        {
                notify( "。" );
		return 1;
        }

        tell_user( who, HIR "游戏管理员ＧＭ突然出现在你面前。\n"
                        HIR "ＧＭ说道：“这里不欢迎你，你还是快走吧！”\n"
                        HIR "ＧＭ说罢将你踢出了游戏。" );

	tell_user( me, "Bạn sẽ đuổi "+ who->get_name()+" ra khỏi trò chơi。" );
//        CHAT_D->rumor_channel( 0, sprintf( HIM "%s：%s(%d)被踢出了游戏。", 
//                get_name(), who->get_name(), who->get_number() ) );
//        USER_D->gm_channel( sprintf( HIR "%s：%s(%d)将%s(%d)踢出游戏。", 
//                get_name(), me->get_name(), me->get_number(), who->get_name(), who->get_number() ) );
        log_file( KICKOUT_LOG, sprintf( "%s %s 将 %s(%s) Đuổi ra khỏi hệ thống。\n", 
                short_time(), me->get_id(), who->get_name(), who->get_id() ) );

        QUIT_CMD->main( who, "" );

        return 1;
}
