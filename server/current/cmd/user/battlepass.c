#include <ansi.h>
#include <cmd.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

int main(object me, string arg)
{
    if (!arg)
    {
        // Show battle pass interface
        "sys/battlepass/battlepass"->show_battle_pass_interface(me);
        return 1;
    }
    
    switch (arg)
    {
    case "buy":
    case "premium":
        // Buy premium pass
        "sys/battlepass/battlepass"->buy_premium_battle_pass(me);
        break;
        
    case "challenges":
    case "daily":
        // Show daily challenges
        send_user(me, "%c%s", ';', 
            "=== THỬ THÁCH HÀNG NGÀY ===\n"
            "• Giết 100 quái (+50 exp)\n"
            "• Hoàn thành 10 nhiệm vụ (+100 exp)\n"
            "• Tham gia bang phái (+200 exp)\n"
            "• Sử dụng 50 lần skill (+75 exp)\n"
            "• Thu thập 20 items (+80 exp)"
        );
        break;
        
    case "weekly":
        // Show weekly challenges
        send_user(me, "%c%s", ';',
            "=== THỬ THÁCH HÀNG TUẦN ===\n"
            "• Lên 5 cấp (+500 exp)\n"
            "• Thắng 20 trận PvP (+800 exp)\n"
            "• Hoàn thành 10 dungeon (+600 exp)\n"
            "• Kiếm 1,000,000 lượng (+400 exp)\n"
            "• Kết bạn với 10 người (+300 exp)"
        );
        break;
        
    case "rewards":
        // Show rewards
        send_user(me, "%c%s", ';',
            "=== PHẦN THƯỞNG BATTLE PASS ===\n\n"
            "FREE PASS:\n"
            "• Level 1: 10 KNB\n"
            "• Level 10: 100 KNB\n"
            "• Level 50: 500 KNB\n"
            "• Level 100: 1000 KNB\n\n"
            "PREMIUM PASS:\n"
            "• Level 1: 50 KNB + VIP 1 ngày\n"
            "• Level 10: 200 KNB + Pet độc quyền\n"
            "• Level 50: 1000 KNB + VIP 7 ngày\n"
            "• Level 100: 2000 KNB + VIP 30 ngày"
        );
        break;
        
    case "help":
        // Show help
        send_user(me, "%c%s", ';',
            "=== BATTLE PASS COMMANDS ===\n"
            "battlepass - Xem Battle Pass\n"
            "battlepass buy - Mua Premium Pass\n"
            "battlepass challenges - Xem thử thách hàng ngày\n"
            "battlepass weekly - Xem thử thách hàng tuần\n"
            "battlepass rewards - Xem phần thưởng\n"
            "battlepass help - Hiển thị trợ giúp"
        );
        break;
        
    default:
        send_user(me, "%c%s", '!', "Lệnh không hợp lệ. Gõ 'battlepass help' để xem trợ giúp.");
        break;
    }
    
    return 1;
} 