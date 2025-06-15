#include <npc.h>
#include <ansi.h>
#include <equip.h>

inherit OFFICER;

// NPC appearance
int get_char_picid() { return 5301; }
int is_self_look() { return 1; }

// Battle Pass functions
void show_battle_pass(object who);
void buy_premium_pass(object who);
void show_challenges(object who);
void show_rewards(object who);

// Create NPC
void create()
{
    set_name("Battle Pass Master");
    set_real_name(HIR "Battle Pass System");
    
    set_2("talk", ([
        "battlepass": (: show_battle_pass :),
        "buy_premium": (: buy_premium_pass :),
        "challenges": (: show_challenges :),
        "rewards": (: show_rewards :),
    ]));

    setup();
}

// Main interaction
void do_look(object who)
{
    int id = getoid(this_object());
    string interface = sprintf(
        "%s:\n"
        "Chào mừng đến với Battle Pass System!\n"
        "Tôi sẽ giúp bạn theo dõi tiến độ và nhận thưởng.\n\n"
        ESC"Xem Battle Pass\n"
        "talk %x# battlepass\n"
        ESC"Xem Thử Thách\n"
        "talk %x# challenges\n"
        ESC"Xem Phần Thưởng\n"
        "talk %x# rewards\n"
        ESC"Mua Premium Pass\n"
        "talk %x# buy_premium\n"
        ESC"Rời khỏi",
        get_name(), id, id, id, id
    );
    
    send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), interface);
}

// Show battle pass interface
void show_battle_pass(object who)
{
    "sys/battlepass/battlepass"->show_battle_pass_interface(who);
}

// Buy premium pass
void buy_premium_pass(object who)
{
    int result = "sys/battlepass/battlepass"->buy_premium_battle_pass(who);
    
    if (result)
    {
        string interface = sprintf(
            "%s:\n"
            "Chúc mừng! Bạn đã mua Premium Battle Pass thành công!\n"
            "Bây giờ bạn có thể nhận thêm phần thưởng độc quyền.\n\n"
            ESC"Xem Battle Pass\n"
            "talk %x# battlepass\n"
            ESC"Rời khỏi",
            get_name(), getoid(this_object())
        );
        send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), interface);
    }
    else
    {
        string interface = sprintf(
            "%s:\n"
            "Không thể mua Premium Battle Pass.\n"
            "Vui lòng kiểm tra lại số dư KNB.\n\n"
            ESC"Thử lại\n"
            "talk %x# buy_premium\n"
            ESC"Rời khỏi",
            get_name(), getoid(this_object())
        );
        send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), interface);
    }
}

// Show challenges
void show_challenges(object who)
{
    int id = getoid(this_object());
    string interface = sprintf(
        "%s:\n"
        "=== THỬ THÁCH HÀNG NGÀY ===\n"
        "• Giết 100 quái (+50 exp)\n"
        "• Hoàn thành 10 nhiệm vụ (+100 exp)\n"
        "• Tham gia bang phái (+200 exp)\n"
        "• Sử dụng 50 lần skill (+75 exp)\n"
        "• Thu thập 20 items (+80 exp)\n\n"
        "=== THỬ THÁCH HÀNG TUẦN ===\n"
        "• Lên 5 cấp (+500 exp)\n"
        "• Thắng 20 trận PvP (+800 exp)\n"
        "• Hoàn thành 10 dungeon (+600 exp)\n"
        "• Kiếm 1,000,000 lượng (+400 exp)\n"
        "• Kết bạn với 10 người (+300 exp)\n\n"
        ESC"Xem Battle Pass\n"
        "talk %x# battlepass\n"
        ESC"Rời khỏi",
        get_name(), id
    );
    
    send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), interface);
}

// Show rewards
void show_rewards(object who)
{
    int id = getoid(this_object());
    string interface = sprintf(
        "%s:\n"
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
        "• Level 100: 2000 KNB + VIP 30 ngày\n\n"
        ESC"Mua Premium Pass\n"
        "talk %x# buy_premium\n"
        ESC"Rời khỏi",
        get_name(), id
    );
    
    send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), interface);
} 