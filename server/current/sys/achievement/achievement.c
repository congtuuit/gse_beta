#include <ansi.h>
#include <time.h>
#include <effect.h>
#include <skill.h>
#include <item.h>
#include <map.h>
#include <action.h>
#include <string.h>

/* Định nghĩa các hằng số cho danh mục và cấp bậc thành tựu */
#define ACHIEVEMENT_COMBAT     1
#define ACHIEVEMENT_LEVEL      2
#define ACHIEVEMENT_SKILL      3
#define ACHIEVEMENT_ITEM       4
#define ACHIEVEMENT_SOCIAL     5
#define ACHIEVEMENT_EXPLORATION 6
#define ACHIEVEMENT_COLLECTION 7
#define ACHIEVEMENT_EVENT      8

#define ACHIEVEMENT_BRONZE     1
#define ACHIEVEMENT_SILVER     2
#define ACHIEVEMENT_GOLD       3
#define ACHIEVEMENT_PLATINUM   4
#define ACHIEVEMENT_DIAMOND    5

/* Định nghĩa class Achievement */
class Achievement {
    string name;
    string description;
    int category;
    int tier;
    int requirement;
    int exp_reward;
    int knb_reward;
    string item_reward;
}

// Khai báo và khởi tạo danh sách thành tựu
private class Achievement *achievements = ({
    // Combat
    new(class Achievement, name : "Tiêu diệt đầu tiên", description : "Tiêu diệt 1 con quái", category : ACHIEVEMENT_COMBAT, tier : ACHIEVEMENT_BRONZE, requirement : 1, exp_reward : 100, knb_reward : 50, item_reward : "/item/sell/0002.c"),
    new(class Achievement, name : "Sát thủ", description : "Tiêu diệt 100 con quái", category : ACHIEVEMENT_COMBAT, tier : ACHIEVEMENT_SILVER, requirement : 100, exp_reward : 500, knb_reward : 200, item_reward : "/item/sell/0004.c"),
    new(class Achievement, name : "Chiến binh", description : "Tiêu diệt 1,000 con quái", category : ACHIEVEMENT_COMBAT, tier : ACHIEVEMENT_GOLD, requirement : 1000, exp_reward : 1000, knb_reward : 500, item_reward : "/item/sell/0012.c"),
    new(class Achievement, name : "Đại chiến binh", description : "Tiêu diệt 10,000 con quái", category : ACHIEVEMENT_COMBAT, tier : ACHIEVEMENT_PLATINUM, requirement : 10000, exp_reward : 2000, knb_reward : 1000, item_reward : "/item/test2/TuiHoangKimThanhY.c"),
    new(class Achievement, name : "Thánh chiến binh", description : "Tiêu diệt 100,000 con quái", category : ACHIEVEMENT_COMBAT, tier : ACHIEVEMENT_DIAMOND, requirement : 100000, exp_reward : 5000, knb_reward : 2000, item_reward : "/item/sell/0061.c"),
    new(class Achievement, name : "Boss Hunter", description : "Tiêu diệt 1 Boss", category : ACHIEVEMENT_COMBAT, tier : ACHIEVEMENT_BRONZE, requirement : 1, exp_reward : 200, knb_reward : 100, item_reward : "/item/sell/0004.c"),
    new(class Achievement, name : "Boss Slayer", description : "Tiêu diệt 10 Boss", category : ACHIEVEMENT_COMBAT, tier : ACHIEVEMENT_SILVER, requirement : 10, exp_reward : 1000, knb_reward : 500, item_reward : "/item/sell/0012.c"),
    new(class Achievement, name : "Boss Master", description : "Tiêu diệt 50 Boss", category : ACHIEVEMENT_COMBAT, tier : ACHIEVEMENT_GOLD, requirement : 50, exp_reward : 2000, knb_reward : 1000, item_reward : "/item/test2/TuiHoangKimThanhY.c"),
    new(class Achievement, name : "Boss Legend", description : "Tiêu diệt 100 Boss", category : ACHIEVEMENT_COMBAT, tier : ACHIEVEMENT_PLATINUM, requirement : 100, exp_reward : 5000, knb_reward : 2000, item_reward : "/item/sell/0061.c"),
    new(class Achievement, name : "PvP Rookie", description : "Thắng 1 trận PvP", category : ACHIEVEMENT_COMBAT, tier : ACHIEVEMENT_BRONZE, requirement : 1, exp_reward : 300, knb_reward : 150, item_reward : "/item/sell/0004.c"),
    new(class Achievement, name : "PvP Fighter", description : "Thắng 10 trận PvP", category : ACHIEVEMENT_COMBAT, tier : ACHIEVEMENT_SILVER, requirement : 10, exp_reward : 1500, knb_reward : 750, item_reward : "/item/sell/0012.c"),
    new(class Achievement, name : "PvP Warrior", description : "Thắng 50 trận PvP", category : ACHIEVEMENT_COMBAT, tier : ACHIEVEMENT_GOLD, requirement : 50, exp_reward : 3000, knb_reward : 1500, item_reward : "/item/test2/TuiHoangKimThanhY.c"),
    new(class Achievement, name : "PvP Champion", description : "Thắng 100 trận PvP", category : ACHIEVEMENT_COMBAT, tier : ACHIEVEMENT_PLATINUM, requirement : 100, exp_reward : 6000, knb_reward : 3000, item_reward : "/item/sell/0061.c"),

    // Level
    new(class Achievement, name : "Tân thủ", description : "Đạt cấp 10", category : ACHIEVEMENT_LEVEL, tier : ACHIEVEMENT_BRONZE, requirement : 10, exp_reward : 200, knb_reward : 100, item_reward : "/item/sell/0002.c"),
    new(class Achievement, name : "Trung cấp", description : "Đạt cấp 30", category : ACHIEVEMENT_LEVEL, tier : ACHIEVEMENT_SILVER, requirement : 30, exp_reward : 500, knb_reward : 250, item_reward : "/item/sell/0004.c"),
    new(class Achievement, name : "Cao cấp", description : "Đạt cấp 50", category : ACHIEVEMENT_LEVEL, tier : ACHIEVEMENT_GOLD, requirement : 50, exp_reward : 1000, knb_reward : 500, item_reward : "/item/sell/0012.c"),
    new(class Achievement, name : "Chuyên gia", description : "Đạt cấp 80", category : ACHIEVEMENT_LEVEL, tier : ACHIEVEMENT_PLATINUM, requirement : 80, exp_reward : 2000, knb_reward : 1000, item_reward : "/item/test2/TuiHoangKimThanhY.c"),
    new(class Achievement, name : "Bậc thầy", description : "Đạt cấp 100", category : ACHIEVEMENT_LEVEL, tier : ACHIEVEMENT_DIAMOND, requirement : 100, exp_reward : 5000, knb_reward : 2000, item_reward : "/item/sell/0061.c"),

    // Skill
    new(class Achievement, name : "Học việc", description : "Học 1 skill", category : ACHIEVEMENT_SKILL, tier : ACHIEVEMENT_BRONZE, requirement : 1, exp_reward : 100, knb_reward : 50, item_reward : "/item/sell/0002.c"),
    new(class Achievement, name : "Đa tài", description : "Học 5 skills", category : ACHIEVEMENT_SKILL, tier : ACHIEVEMENT_SILVER, requirement : 5, exp_reward : 300, knb_reward : 150, item_reward : "/item/sell/0004.c"),
    new(class Achievement, name : "Tài năng", description : "Học 10 skills", category : ACHIEVEMENT_SKILL, tier : ACHIEVEMENT_GOLD, requirement : 10, exp_reward : 600, knb_reward : 300, item_reward : "/item/sell/0012.c"),
    new(class Achievement, name : "Chuyên môn", description : "Luyện 1 skill lên max", category : ACHIEVEMENT_SKILL, tier : ACHIEVEMENT_PLATINUM, requirement : 1, exp_reward : 1000, knb_reward : 500, item_reward : "/item/test2/TuiHoangKimThanhY.c"),
    new(class Achievement, name : "Bậc thầy", description : "Luyện 5 skills lên max", category : ACHIEVEMENT_SKILL, tier : ACHIEVEMENT_DIAMOND, requirement : 5, exp_reward : 3000, knb_reward : 1500, item_reward : "/item/sell/0061.c"),

    // Item
    new(class Achievement, name : "Thu thập", description : "Thu thập 10 items", category : ACHIEVEMENT_ITEM, tier : ACHIEVEMENT_BRONZE, requirement : 10, exp_reward : 100, knb_reward : 50, item_reward : "/item/sell/0002.c"),
    new(class Achievement, name : "Sưu tầm", description : "Thu thập 100 items", category : ACHIEVEMENT_ITEM, tier : ACHIEVEMENT_SILVER, requirement : 100, exp_reward : 300, knb_reward : 150, item_reward : "/item/sell/0004.c"),
    new(class Achievement, name : "Nhà sưu tầm", description : "Thu thập 500 items", category : ACHIEVEMENT_ITEM, tier : ACHIEVEMENT_GOLD, requirement : 500, exp_reward : 600, knb_reward : 300, item_reward : "/item/sell/0012.c"),
    new(class Achievement, name : "Bảo tàng", description : "Thu thập 1,000 items", category : ACHIEVEMENT_ITEM, tier : ACHIEVEMENT_PLATINUM, requirement : 1000, exp_reward : 1200, knb_reward : 600, item_reward : "/item/test2/TuiHoangKimThanhY.c"),
    new(class Achievement, name : "Thánh sưu tầm", description : "Thu thập 5,000 items", category : ACHIEVEMENT_ITEM, tier : ACHIEVEMENT_DIAMOND, requirement : 5000, exp_reward : 3000, knb_reward : 1500, item_reward : "/item/sell/0061.c"),

    // Social
    new(class Achievement, name : "Đoàn kết", description : "Tham gia bang phái", category : ACHIEVEMENT_SOCIAL, tier : ACHIEVEMENT_BRONZE, requirement : 1, exp_reward : 200, knb_reward : 100, item_reward : "/item/sell/0004.c"),
    new(class Achievement, name : "Giao lưu", description : "Kết bạn với 10 người", category : ACHIEVEMENT_SOCIAL, tier : ACHIEVEMENT_SILVER, requirement : 10, exp_reward : 400, knb_reward : 200, item_reward : "/item/sell/0012.c"),
    new(class Achievement, name : "Hảo tâm", description : "Giúp đỡ 50 người chơi", category : ACHIEVEMENT_SOCIAL, tier : ACHIEVEMENT_GOLD, requirement : 50, exp_reward : 800, knb_reward : 400, item_reward : "/item/test2/TuiHoangKimThanhY.c"),
    new(class Achievement, name : "Thủ lĩnh", description : "Trở thành bang chủ", category : ACHIEVEMENT_SOCIAL, tier : ACHIEVEMENT_PLATINUM, requirement : 1, exp_reward : 1500, knb_reward : 750, item_reward : "/item/sell/0061.c"),

    // Exploration
    new(class Achievement, name : "Du lịch", description : "Thăm 5 bản đồ", category : ACHIEVEMENT_EXPLORATION, tier : ACHIEVEMENT_BRONZE, requirement : 5, exp_reward : 150, knb_reward : 75, item_reward : "/item/sell/0002.c"),
    new(class Achievement, name : "Khám phá", description : "Thăm 20 bản đồ", category : ACHIEVEMENT_EXPLORATION, tier : ACHIEVEMENT_SILVER, requirement : 20, exp_reward : 400, knb_reward : 200, item_reward : "/item/sell/0004.c"),
    new(class Achievement, name : "Nhà thám hiểm", description : "Thăm 50 bản đồ", category : ACHIEVEMENT_EXPLORATION, tier : ACHIEVEMENT_GOLD, requirement : 50, exp_reward : 800, knb_reward : 400, item_reward : "/item/sell/0012.c"),
    new(class Achievement, name : "Thám hiểm gia", description : "Thăm 100 bản đồ", category : ACHIEVEMENT_EXPLORATION, tier : ACHIEVEMENT_PLATINUM, requirement : 100, exp_reward : 1500, knb_reward : 750, item_reward : "/item/test2/TuiHoangKimThanhY.c"),

    // Collection
    new(class Achievement, name : "Bộ sưu tập", description : "Hoàn thành 1 bộ trang bị", category : ACHIEVEMENT_COLLECTION, tier : ACHIEVEMENT_BRONZE, requirement : 1, exp_reward : 300, knb_reward : 150, item_reward : "/item/sell/0004.c"),
    new(class Achievement, name : "Nhà sưu tập", description : "Hoàn thành 5 bộ trang bị", category : ACHIEVEMENT_COLLECTION, tier : ACHIEVEMENT_SILVER, requirement : 5, exp_reward : 600, knb_reward : 300, item_reward : "/item/sell/0012.c"),
    new(class Achievement, name : "Bảo tàng", description : "Hoàn thành 10 bộ trang bị", category : ACHIEVEMENT_COLLECTION, tier : ACHIEVEMENT_GOLD, requirement : 10, exp_reward : 1200, knb_reward : 600, item_reward : "/item/test2/TuiHoangKimThanhY.c"),

    // Event
    new(class Achievement, name : "Tham gia", description : "Tham gia 1 sự kiện", category : ACHIEVEMENT_EVENT, tier : ACHIEVEMENT_BRONZE, requirement : 1, exp_reward : 200, knb_reward : 100, item_reward : "/item/sell/0004.c"),
    new(class Achievement, name : "Sự kiện gia", description : "Tham gia 10 sự kiện", category : ACHIEVEMENT_EVENT, tier : ACHIEVEMENT_SILVER, requirement : 10, exp_reward : 500, knb_reward : 250, item_reward : "/item/sell/0012.c"),
    new(class Achievement, name : "Chuyên gia sự kiện", description : "Tham gia 50 sự kiện", category : ACHIEVEMENT_EVENT, tier : ACHIEVEMENT_GOLD, requirement : 50, exp_reward : 1000, knb_reward : 500, item_reward : "/item/test2/TuiHoangKimThanhY.c"),
    new(class Achievement, name : "Chiến thắng", description : "Thắng 1 sự kiện", category : ACHIEVEMENT_EVENT, tier : ACHIEVEMENT_PLATINUM, requirement : 1, exp_reward : 2000, knb_reward : 1000, item_reward : "/item/sell/0061.c")
});

#define NUM_ACHIEVEMENTS (sizeof(achievements) / sizeof(Achievement))

/* Forward declarations */
void complete_achievement(object player, int achievement_index);
void check_legendary_title(object player, int achievement_index);

// Hàm lấy tên cấp bậc theo kiểu LPC
string get_tier_name(int tier)
{
    switch (tier)
    {
        case ACHIEVEMENT_BRONZE:   return "Đồng";
        case ACHIEVEMENT_SILVER:   return "Bạc";
        case ACHIEVEMENT_GOLD:     return "Vàng";
        case ACHIEVEMENT_PLATINUM: return "Bạch Kim";
        case ACHIEVEMENT_DIAMOND:  return "Kim Cương";
        default:                   return "Không rõ";
    }
}

// Hàm lấy tên danh mục theo kiểu LPC
string get_category_name(int category)
{
    switch (category)
    {
        case ACHIEVEMENT_COMBAT:       return "Chiến đấu";
        case ACHIEVEMENT_LEVEL:        return "Cấp độ";
        case ACHIEVEMENT_SKILL:        return "Kỹ năng";
        case ACHIEVEMENT_ITEM:         return "Vật phẩm";
        case ACHIEVEMENT_SOCIAL:       return "Xã hội";
        case ACHIEVEMENT_EXPLORATION:  return "Khám phá";
        case ACHIEVEMENT_COLLECTION:   return "Sưu tầm";
        case ACHIEVEMENT_EVENT:        return "Sự kiện";
        default:                       return "Không rõ";
    }
}

/* Hàm kiểm tra thành tựu đã hoàn thành chưa */
int is_achievement_completed(object player, int achievement_index) {
    if (achievement_index < 0 || achievement_index >= NUM_ACHIEVEMENTS) return 0;
    return player->achievements_completed[achievement_index];
}

/* Hàm lấy tiến độ thành tựu */
int get_achievement_progress(object player, int achievement_index) {
    if (achievement_index < 0 || achievement_index >= NUM_ACHIEVEMENTS) return 0;
    return player->achievements_progress[achievement_index];
}

/* Hàm đặt tiến độ thành tựu */
void set_achievement_progress(object player, int achievement_index, int progress) {
    if (achievement_index < 0 || achievement_index >= NUM_ACHIEVEMENTS) return;
    player->achievements_progress[achievement_index] = progress;
}

/* Hàm đánh dấu thành tựu hoàn thành */
void mark_achievement_completed(object player, int achievement_index) {
    if (achievement_index < 0 || achievement_index >= NUM_ACHIEVEMENTS) return;
    player->achievements_completed[achievement_index] = 1;
    player->achievements_completed_time[achievement_index] = (int)time(NULL);
}

/* Hàm kiểm tra và cập nhật tiến độ thành tựu */
void check_achievement_progress(object player, int achievement_index, int progress) {
    int current_progress, required_progress;

    if (achievement_index < 0 || achievement_index >= NUM_ACHIEVEMENTS) return;
    if (is_achievement_completed(player, achievement_index)) return;

    current_progress = get_achievement_progress(player, achievement_index);
    required_progress = achievements[achievement_index].requirement;

    current_progress += progress;
    set_achievement_progress(player, achievement_index, current_progress);

    if (current_progress >= required_progress) {
        complete_achievement(player, achievement_index);
    }
}

// Hàm hoàn thành thành tựu và trao thưởng
void complete_achievement(object player, int achievement_index)
{
    string message;
    string title_code;
    int current_time;

    if (achievement_index < 0 || achievement_index >= sizeof(achievements)) return;

    // Đánh dấu đã hoàn thành
    mark_achievement_completed(player, achievement_index);

    // Trao thưởng kinh nghiệm
    player->add_exp(achievements[achievement_index]->exp_reward);

    // Trao thưởng KNB (giả định là yuanbao, x10)
    player->add_yuanbao(achievements[achievement_index]->knb_reward * 10);

    // Trao vật phẩm nếu có
    if (achievements[achievement_index]->item_reward != "")
    {
        // Giả định hàm add_item(string path) tồn tại
        player->add_item(achievements[achievement_index]->item_reward);
        tell_object(player, sprintf("Bạn nhận được vật phẩm: %s\n", achievements[achievement_index]->item_reward));
    }

    // Thông báo hoàn thành thành tựu
    message = sprintf("Hoàn thành thành tựu: %s (%s) +%d exp, +%d KNB",
        achievements[achievement_index]->name,
        get_tier_name(achievements[achievement_index]->tier),
        achievements[achievement_index]->exp_reward,
        achievements[achievement_index]->knb_reward);

    tell_object(player, message);

    // Ghi log (ghi file append)
    current_time = time();
    write_file("/log/achievement.log", sprintf("%s %s completed achievement %d\n",
        ctime(current_time), player->get_id(), achievement_index));

    // Trao danh hiệu (giả định có hàm get_achievement_title)
    title_code = get_achievement_title(achievement_index, achievements[achievement_index]->tier);
    if (title_code != "")
    {
        player->add_title(title_code);
        tell_object(player, sprintf("Chúc mừng! Bạn đã nhận được danh hiệu: %s\n", title_code));
    }

    // Kiểm tra danh hiệu huyền thoại
    check_legendary_title(player, achievement_index);
}

// Hiển thị giao diện thành tựu cho người chơi
void show_achievement_interface(object player)
{
    int i, j;
    int completed_achievements = 0;
    int total_achievements = sizeof(achievements);
    string message = "=== HỆ THỐNG THÀNH TỰU ===\n\n";
    string status;

    for (i = 1; i <= 8; i++)
    {
        message += "--- " + get_category_name(i) + " ---\n";

        for (j = 0; j < total_achievements; j++)
        {
            if (achievements[j]->category == i)
            {
                if (is_achievement_completed(player, j))
                    status = "✓ Hoàn thành";
                else if (get_achievement_progress(player, j) > 0)
                    status = "Đang tiến hành";
                else
                    status = "Chưa bắt đầu";

                message += sprintf("%s: %s (%d/%d) - %s\n",
                    achievements[j]->name,
                    achievements[j]->description,
                    get_achievement_progress(player, j),
                    achievements[j]->requirement,
                    status);
            }
        }

        message += "\n";
    }

    // Thống kê tổng kết
    for (i = 0; i < total_achievements; i++)
    {
        if (is_achievement_completed(player, i))
            completed_achievements++;
    }

    float rate = total_achievements > 0
        ? (to_float(completed_achievements) / total_achievements * 100.0)
        : 0.0;

    message += sprintf("=== THỐNG KÊ ===\nHoàn thành: %d/%d thành tựu\nTỷ lệ hoàn thành: %.1f%%\n",
        completed_achievements, total_achievements, rate);

    tell_object(player, message);
}

// Hàm lấy mã danh hiệu dựa trên tên thành tựu
string get_achievement_title(int achievement_index, int tier)
{
    string name;
    mapping title_map;

    if (achievement_index < 0 || achievement_index >= sizeof(achievements))
        return "";

    name = achievements[achievement_index]->name;

    title_map = ([
        "Tiêu diệt đầu tiên"      : "ACH001",
        "Sát thủ"                 : "ACH002",
        "Chiến binh"             : "ACH003",
        "Đại chiến binh"         : "ACH004",
        "Thánh chiến binh"       : "ACH005",
        "Boss Hunter"            : "ACH006",
        "PvP Rookie"             : "ACH007",
        "PvP Champion"           : "ACH008",

        "Tân thủ"                : "ACH101",
        "Trung cấp"              : "ACH102",
        "Cao cấp"                : "ACH103",
        "Chuyên gia"             : "ACH104",
        "Bậc thầy"               : "ACH105",

        "Học việc"               : "ACH201",
        "Đa tài"                 : "ACH202",
        "Tài năng"               : "ACH203",
        "Chuyên môn"             : "ACH204",

        "Thu thập"               : "ACH301",
        "Sưu tầm"                : "ACH302",
        "Nhà sưu tầm"            : "ACH303",
        "Bảo tàng"               : "ACH304",

        "Đoàn kết"               : "ACH401",
        "Giao lưu"               : "ACH402",
        "Hảo tâm"                : "ACH403",
        "Thủ lĩnh"               : "ACH404",

        "Du lịch"                : "ACH501",
        "Khám phá"               : "ACH502",
        "Nhà thám hiểm"          : "ACH503",
        "Thám hiểm gia"          : "ACH504",

        "Bộ sưu tập"             : "ACH601",
        "Nhà sưu tập"            : "ACH602",
        "Bảo tàng"               : "ACH603",

        "Tham gia"               : "ACH701",
        "Sự kiện gia"            : "ACH702",
        "Chuyên gia sự kiện"     : "ACH703",
        "Chiến thắng"            : "ACH704"
    ]);

    return title_map[name] || "";
}

void check_legendary_title(object player, int achievement_index)
{
    int i, combat_count = 0, level_count = 0, skill_count = 0;
    string name = achievements[achievement_index]->name;
    string id = player->get_id(); // giả định hàm này tồn tại
    string msg;

    // === THÀNH TỰU CHIẾN ĐẤU ===
    if (name == "Thánh chiến binh") {
        for (i = 0; i < sizeof(achievements); i++) {
            if (achievements[i]->category == ACHIEVEMENT_COMBAT && player->achievements_completed[i])
                combat_count++;
        }
        if (combat_count >= 13) {
            player->titles += ({ "ACH999" });
            msg = sprintf("🔥🔥🔥 THIÊN HẠ VÔ ĐỊCH! Bạn đã hoàn thành tất cả thành tựu chiến đấu! 🔥🔥🔥");
            tell_object(player, msg);
            CHANNEL_D->do_channel(this_object(), "rumor",
                sprintf("🔥 %s đã đạt được danh hiệu THIÊN HẠ VÔ ĐỊCH! 🔥", id));
        }
    }

    // === THÀNH TỰU CẤP ĐỘ ===
    if (name == "Bậc thầy") {
        for (i = 0; i < sizeof(achievements); i++) {
            if (achievements[i]->category == ACHIEVEMENT_LEVEL && player->achievements_completed[i])
                level_count++;
        }
        if (level_count >= 5) {
            player->titles += ({ "ACH888" });
            tell_object(player, "💎💎💎 BÁ CHỦ THẾ GIỚI! Bạn đã hoàn thành tất cả thành tựu cấp độ! 💎💎💎");
            CHANNEL_D->do_channel(this_object(), "rumor",
                sprintf("💎 %s đã đạt được danh hiệu BÁ CHỦ THẾ GIỚI! 💎", id));
        }
    }

    // === THÀNH TỰU KỸ NĂNG ===
    if (name == "Bậc thầy") {
        for (i = 0; i < sizeof(achievements); i++) {
            if (achievements[i]->category == ACHIEVEMENT_SKILL && player->achievements_completed[i])
                skill_count++;
        }
        if (skill_count >= 5) {
            player->titles += ({ "ACH777" });
            tell_object(player, "👑👑👑 VÕ ĐẾ TỐI THƯỢNG! Bạn đã hoàn thành tất cả thành tựu kỹ năng! 👑👑👑");
            CHANNEL_D->do_channel(this_object(), "rumor",
                sprintf("👑 %s đã đạt được danh hiệu VÕ ĐẾ TỐI THƯỢNG! 👑", id));
        }
    }
}

/* Hàm hoàn thành tất cả thành tựu (GM) */
void complete_all_achievements(object player) {
    int i;
    for (i = 0; i < NUM_ACHIEVEMENTS; i++) {
        check_achievement_progress(player, i, achievements[i].requirement);
    }
}

/* Hàm trao thành tựu ngẫu nhiên (GM) */
void give_random_achievement(object player) {
    string message;
    int achievement_index = rand() % NUM_ACHIEVEMENTS;
    int random_progress = (rand() % 100) + 1;

    check_achievement_progress(player, achievement_index, random_progress);
    sprintf(message, "🎲 Đã trao thành tựu ngẫu nhiên: %s (Tiến độ: %d)",
            achievements[achievement_index].name, random_progress);
    printf("%s\n", message);
}

/* Hàm reset tất cả thành tựu (GM) */
void reset_all_achievements(object player) {
    int i;
    for (i = 0; i < NUM_ACHIEVEMENTS; i++) {
        player->achievements_progress[i] = 0;
        player->achievements_completed[i] = 0;
        player->achievements_completed_time[i] = 0;
    }
    player->title_count = 0;
    printf("Đã reset tất cả thành tựu!\n");
}

