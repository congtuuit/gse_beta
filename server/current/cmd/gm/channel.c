
#include <ansi.h>

#define DEFAULT_TIME    43200                   // 缺省封闭一个月
#define CHANNEL_LOG     "gm/channel.txt"        // 频道管理日志

// 函数：命令处理
int main( object me, string arg )
{
        object who;
        string cmd1, cmd2, cmd3, cmd4, cmd5;
        string id, channel;
        int min, t, n;

        if( is_player(me) ) 
        {
                notify( "。" );
		return 1;
        }

        if( !arg )
        {
                id = "?";  channel = "?";  min = -1;
        }
        else if( sscanf( arg, "%s %s %d", id, channel, min ) != 3 )
	{
                min = DEFAULT_TIME;
                if( sscanf( arg, "%s %s", id, channel ) != 2 )
                {
                        id = arg;  channel = "";
                }
	}

        if( id == "?" )
        {
                send_user( me, "%c%c%d%s", '?', 1, 0, sprintf( "频道管理。\n\n请输入对方的数字ＩＤ：\n"
                        ESC "channel %%s %s %d\n", channel, min ) );
                return 1;
        }
        if( !( who = find_player(id) ) ) 
        {
                notify( "您找不到这位玩家。" );
                return 1;
        }
/*        if( !is_player(who) )
        {
                notify( "您只能封闭玩家的频道。" );
                return 1;
        }*/

        if( channel == "?" )
        {
                cmd1 = sprintf( "channel %s all %d\n", id, min );
                cmd2 = sprintf( "channel %s chat %d\n", id, min );
                cmd3 = sprintf( "channel %s rumor %d\n", id, min );
                cmd4 = sprintf( "channel %s vipchat %d\n", id, min );
                cmd5 = sprintf( "channel %s\n", id );
                send_user( me, "%c%s", ':', sprintf( "您要管理%s(%d)哪个频道？\n", who->get_name(), who->get_number() ) +
                        ESC "管理所有频道。\n" + cmd1 +
                        ESC "管理公众频道。\n" + cmd2 +
                        ESC "管理谣言频道。\n" + cmd3 +
                        ESC "管理VIP频道。\n" + cmd4 +
                        ESC "查看频道封闭情况。\n" + cmd5 +
                        ESC "我再想想……\nCLOSE\n" );
                return 1;
        }

        if( min < 0 )
        {
                send_user( me, "%c%c%d%s", '?', 1, DEFAULT_TIME, sprintf( "封闭%s(%d)频道。\n\n请输入要封闭的分钟数：(0 表示打开频道)\n"
                        ESC "channel %s %s %%s\n", who->get_name(), who->get_number(), id, channel ) );
                return 1;
        }
        if( min < 0 || min > DEFAULT_TIME ) min = DEFAULT_TIME;

        t = gone_time( who->get_chblk("time") );
        if( !channel || channel == "" )
        {
                if( ( n = who->get_chblk("chat") - t ) > 0 ) 
                        tell_user( me, "%s公众频道被封闭 %d 分。", who->get_name(), n / 60 + 1 );
                else    tell_user( me, who->get_name() + "公众频道：打开。" );
                if( ( n = who->get_chblk("rumor") - t ) > 0 ) 
                        tell_user( me, "%s谣言频道被封闭 %d 分。", who->get_name(), n / 60 + 1 );
                else    tell_user( me, who->get_name() + "谣言频道：打开。" );
                if( ( n = who->get_chblk("vipchat") - t ) > 0 ) 
                        tell_user( me, "%sVIP频道被封闭 %d 分。", who->get_name(), n / 60 + 1 );
                else    tell_user( me, who->get_name() + "VIP频道：打开。" );
        } 
        else if( channel == "all" )
        {
                if( min )
                {
                        tell_user( me, "%s所有频道被封闭 %d 分。", who->get_name(), min );
                        who->set_chblk("chat", min * 60 );
                        who->set_chblk("rumor", min * 60 );
                        who->set_chblk("family", min * 60 );
                        who->set_chblk("say", min * 60 );
                        who->set_chblk("city", min * 60 );
                        who->set_chblk("vipchat", min * 60 );
                        who->set_chblk("time", time() );
                        who->set_save("nomail", time()+min*60);
//                      who->save();

//                        CHAT_D->chat_channel( 0, sprintf( HIC "游戏管理员ＧＭ封闭%s(%d)的所有频道 %d 分钟。", 
//                                who->get_name(), who->get_number(), min ) );
//                        CHAT_D->rumor_channel( 0, sprintf( HIM "游戏管理员ＧＭ封闭%s(%d)的谣言频道 %d 分钟。", 
//                                who->get_name(), who->get_number(), min ) );
                        log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s 封闭 %s(%d)%s 的全部频道 %d 分钟。(ＧＭ)\n", 
                                short_time(), me->get_name(), me->get_number(), me->get_id(),
                                who->get_name(), who->get_number(), who->get_id(), min ) );
                }
                else
                {
                        tell_user( me, who->get_name() + "所有频道已打开。" );
                        who->delete_chblk("chat");
                        who->delete_chblk("rumor");
                        who->delete_chblk("say");
                        who->delete_chblk("city");
                        who->delete_chblk("family");
                        who->delete_chblk("vipchat");
                        who->delete_chblk("time");
                        who->set_save("nomail", 0);
//                      who->save();

//                        CHAT_D->chat_channel( 0, sprintf( HIC "游戏管理员ＧＭ打开%s(%d)的所有频道。", 
//                              who->get_name(), who->get_number() ) );
//                        CHAT_D->rumor_channel( 0, sprintf( HIM "游戏管理员ＧＭ打开%s(%d)的谣言频道。", 
//                                who->get_name(), who->get_number() ) );
                        log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s 打开 %s(%d)%s 的全部频道。(ＧＭ)\n", 
                                short_time(), me->get_name(), me->get_number(), me->get_id(),
                                who->get_name(), who->get_number(), who->get_id() ) );
                }
        }
        else if( channel == "chat" )
        {
                if( min )
                {
                        if( ( n = who->get_chblk("chat") - t ) > 0 ) 
                                tell_user( me, "%s公众频道已经被封闭 %d 分。", who->get_name(), n / 60 + 1 );
                        else 
                        {
                                tell_user( me, "%s公众频道被封闭 %d 分。", who->get_name(), min );
                                if( who->get_chblk("rumor") )
                                {
                                        if( who->add_chblk("rumor", -t ) < 1 ) 
                                                who->delete_chblk("rumor");
                                }
                                if( who->get_chblk("vipchat") )
                                {
                                        if( who->add_chblk("vipchat", -t ) < 1 ) 
                                                who->delete_chblk("vipchat");
                                }
                                who->set_chblk("chat", min * 60 );
                                who->set_chblk("time", time() );

                                log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s 封闭 %s(%d)%s 的 chat 频道 %d 分钟。(ＧＭ)\n", 
                                        short_time(), me->get_name(), me->get_number(), me->get_id(),
                                        who->get_name(), who->get_number(), who->get_id(), min ) );
                        }
                }
                else
                {
                        if( !who->get_chblk("chat") ) 
                                tell_user( me, who->get_name() + "公众频道已打开。" );
                        else 
                        {
                                tell_user( me, who->get_name() + "公众频道已打开。" );
                                who->delete_chblk("chat");

                                log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s 打开 %s(%d)%s 的 chat 频道。(ＧＭ)\n", 
                                        short_time(), me->get_name(), me->get_number(), me->get_id(),
                                        who->get_name(), who->get_number(), who->get_id() ) );
                        }
                }
        }
        else if( channel == "rumor" )
        {
                if( min )
                {
                        if( ( n = who->get_chblk("rumor") - t ) > 0 ) 
                                tell_user( me, "%s谣言频道已经被封闭 %d 分。", who->get_name(), n / 60 + 1 );
                        else 
                        {
                                tell_user( me, "%s谣言频道被封闭 %d 分。", who->get_name(), min );
                                if( who->get_chblk("chat") )
                                {
                                        if( who->add_chblk("chat", -t ) < 1 ) 
                                                who->delete_chblk("chat");;
                                }
                                if( who->get_chblk("vipchat") )
                                {
                                        if( who->add_chblk("vipchat", -t ) < 1 ) 
                                                who->delete_chblk("vipchat");
                                }
                                who->set_chblk("rumor", min * 60 );
                                who->set_chblk("time", time() );
//                              who->save();

//                                CHAT_D->rumor_channel( 0, sprintf( HIM "游戏管理员ＧＭ封闭%s(%d)的谣言频道 %d 分钟。", 
//                                        who->get_name(), who->get_number(), min ) );
                                log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s 封闭 %s(%d)%s 的 rumor 频道 %d 分钟。(ＧＭ)\n", 
                                        short_time(), me->get_name(), me->get_number(), me->get_id(),
                                        who->get_name(), who->get_number(), who->get_id(), min ) );
                        }
                }
                else
                {
                        if( !who->get_chblk("rumor") ) 
                                tell_user( me, who->get_name() + "谣言频道已打开。" );
                        else 
                        {
                                tell_user( me, who->get_name() + "谣言频道已打开。" );
                                who->delete_chblk("rumor");

                                log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s 打开 %s(%d)%s 的 rumor 频道。(ＧＭ)\n", 
                                        short_time(), me->get_name(), me->get_number(), me->get_id(),
                                        who->get_name(), who->get_number(), who->get_id() ) );
                        }
                }
        }
        else if(channel == "vipchat")
        {
        	if( min )
                {
                        if( ( n = who->get_chblk("vipchat") - t ) > 0 ) 
                                tell_user( me, "%sVIP频道已经被封闭 %d 分。", who->get_name(), n / 60 + 1 );
                        else 
                        {
                                tell_user( me, "%sVIP频道被封闭 %d 分。", who->get_name(), min );
                                if( who->get_chblk("chat") )
                                {
                                        if( who->add_chblk("chat", -t ) < 1 ) 
                                                who->delete_chblk("chat");
                                }
                                if( who->get_chblk("rumor") )
                                {
                                        if( who->add_chblk("rumor", -t ) < 1 ) 
                                                who->delete_chblk("rumor");
                                }
                                who->set_chblk("vipchat", min * 60 );
                                who->set_chblk("time", time() );

                                log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s 封闭 %s(%d)%s 的 vipchat 频道 %d 分钟。(ＧＭ)\n", 
                                        short_time(), me->get_name(), me->get_number(), me->get_id(),
                                        who->get_name(), who->get_number(), who->get_id(), min ) );
                        }
                }
                else
                {
                        if( !who->get_chblk("vipchat") ) 
                                tell_user( me, who->get_name() + "VIP频道已打开。" );
                        else 
                        {
                                tell_user( me, who->get_name() + "VIP频道已打开。" );
                                who->delete_chblk("vipchat");

                                log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s 打开 %s(%d)%s 的 VIP 频道。(ＧＭ)\n", 
                                        short_time(), me->get_name(), me->get_number(), me->get_id(),
                                        who->get_name(), who->get_number(), who->get_id() ) );
                        }
                }
        }
        else 
        {
                notify( "您能封闭的频道有：chat, rumor,vipchat" );
		return 1;
        }

        return 1;
}
