
#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>
#include <time.h>

//cn t2 t3 t4 t5 t6 t7
//0	 1	2   3  4  5  6

#define CN 0
#define T2 1
#define T3 2
#define T4 3
#define T5 4
#define T6 5
#define T7 6

int main(object me, string arg)
{
	int iTime, today;
	mixed* mixTime;
	string result = HIC"Hoạt động diễn ra hôm nay: \n", all;

	iTime = time();
	mixTime = localtime(iTime);

	today = mixTime[TIME_WDAY];

	if (arg == "all") {

		result = sprintf("1.Đổi cầu: Thứ 6, 7, Chủ nhật.\n");
		result += sprintf("2.Hoàng Kim Thánh Y: Khung giờ (7-9-11-13-15-17-19-21-23) từ thứ 2 đến thứ 5 hàng tuần\n");
		result += sprintf("3.Cổ Mộ Mật Thất: Bắt đầu 20h30 -> 22h hàng ngày\n");

		result += sprintf("4.Sơn Tặc: Khung giờ (7-9-11-13-15-17-19-21-23) vào thứ (2-4-6-Chủ nhật)\n");
		result += sprintf("Phi Tặc: Khung giờ (7-9-11-13-15-17-19-21-23) vào thứ (3-5-7)\n");

		result += sprintf("5.Đoạt Bảo Mã Tặc: Khung giờ (8-10-12-14-16-18-20-22) vào thứ (2-4-6)\n");
		result += sprintf("6.Cứu nhân độ thế: Khung giờ (8-10-12-14-16-18-20-22) vào thứ (3-7-Chủ nhật)\n");
		result += sprintf("7.Đào Kho Báu: diễn ra 9h và 19h hằng ngày tại NPC Vương Bộ Đầu (Chu Quốc)\n");
		result += sprintf(HIY"8. Boss Phi Tặc Vương "NOR"21h (Thứ 2-4-6-CN)\n");
		result += sprintf(HIY"9. Boss Tinh Linh Ảo Ảnh "NOR"21h (Thứ 3-5-7-CN)\n");

	}
	else {
		result += sprintf(HIY"1.Cổ Mộ Mật Thất: "NOR"Bắt đầu 20h30 -> 22h hàng ngày\n");
		result += sprintf(HIY"2.Đào Kho Báu: "NOR"diễn ra 9h và 19h hằng ngày tại NPC Vương Bộ Đầu (Chu Quốc)\n");

		switch (today)
		{
		case T2:
			result += sprintf(HIY"3.Hoàng Kim Thánh Y: "NOR"Khung giờ (7-9-11-13-15-17-19-21-23) từ thứ 2 đến thứ 5 hàng tuần\n");
			result += sprintf(HIY"4.Sơn Tặc: "NOR"Khung giờ (7-9-11-13-15-17-19-21-23) vào thứ (2-4-6-Chủ nhật)\n");
			result += sprintf(HIY"5.Đoạt Bảo Mã Tặc: "NOR"Khung giờ (8-10-12-14-16-18-20-22) vào thứ (2-4-6)\n");
			result += sprintf(HIY"6. Boss Sơn Đại Vương "NOR"20h30 (Thứ 2 đến thứ 6)\n");
			result += sprintf(HIY"7. Boss Phi Tặc Vương "NOR"21h (Thứ 2-4-6-CN)\n");
			break;
		case T3:
			result += sprintf(HIY"3.Hoàng Kim Thánh Y: "NOR"Khung giờ (7-9-11-13-15-17-19-21-23) từ thứ 2 đến thứ 5 hàng tuần\n");
			result += sprintf(HIY"4.Phi Tặc: "NOR"Khung giờ (7-9-11-13-15-17-19-21-23) vào thứ (3-5-7)\n");
			result += sprintf(HIY"5.Cứu nhân độ thế: "NOR"Khung giờ (8-10-12-14-16-18-20-22) vào thứ (3-7-Chủ nhật)\n");
			result += sprintf(HIY"6. Boss Sơn Đại Vương "NOR"20h30 (Thứ 2 đến thứ 6)\n");
			result += sprintf(HIY"7. Boss Tinh Linh Ảo Ảnh "NOR"21h (Thứ 3-5-7-CN)\n");
			break;
		case T4:
			result += sprintf(HIY"3.Sơn Tặc: "NOR"Khung giờ (7-9-11-13-15-17-19-21-23) vào thứ (2-4-6-Chủ nhật)\n");
			result += sprintf(HIY"4.Hoàng Kim Thánh Y: "NOR"Khung giờ (7-9-11-13-15-17-19-21-23) từ thứ 2 đến thứ 5 hàng tuần\n");
			result += sprintf(HIY"5.Đoạt Bảo Mã Tặc: "NOR"Khung giờ (8-10-12-14-16-18-20-22) vào thứ (2-4-6)\n");
			result += sprintf(HIY"6. Boss Sơn Đại Vương "NOR"20h30 (Thứ 2 đến thứ 6)\n");
			result += sprintf(HIY"7. Boss Phi Tặc Vương "NOR"21h (Thứ 2-4-6-CN)\n");

			break;
		case T5:
			result += sprintf(HIY"3.Hoàng Kim Thánh Y: "NOR"Khung giờ (7-9-11-13-15-17-19-21-23) từ thứ 2 đến thứ 5 hàng tuần\n");
			result += sprintf(HIY"4.Phi Tặc: "NOR"Khung giờ (7-9-11-13-15-17-19-21-23) vào thứ (3-5-7)\n");
			result += sprintf(HIY"6. Boss Sơn Đại Vương "NOR"20h30 (Thứ 2 đến thứ 6)\n");
			result += sprintf(HIY"7. Boss Tinh Linh Ảo Ảnh "NOR"21h (Thứ 3-5-7-CN)\n");
			break;
		case T6:
			result += sprintf(HIY"3.Đổi cầu: "NOR"Thứ 6, 7, Chủ nhật.\n");
			result += sprintf(HIY"4.Sơn Tặc: "NOR"Khung giờ (7-9-11-13-15-17-19-21-23) vào thứ (2-4-6-Chủ nhật)\n");
			result += sprintf(HIY"5.Đoạt Bảo Mã Tặc: "NOR"Khung giờ (8-10-12-14-16-18-20-22) vào thứ (2-4-6)\n");
			result += sprintf(HIY"6. Boss Sơn Đại Vương "NOR"20h30 (Thứ 2 đến thứ 6)\n");
			result += sprintf(HIY"7. Boss Phi Tặc Vương "NOR"21h (Thứ 2-4-6-CN)\n");

			break;
		case T7:
			result += sprintf(HIY"3.Đổi cầu: "NOR"Thứ 6, 7, Chủ nhật.\n");
			result += sprintf(HIY"4.Phi Tặc: "NOR"Khung giờ (7-9-11-13-15-17-19-21-23) vào thứ (3-5-7)\n");
			result += sprintf(HIY"5.Cứu nhân độ thế: "NOR"Khung giờ (8-10-12-14-16-18-20-22) vào thứ (3-7-Chủ nhật)\n");
			result += sprintf(HIY"6. Boss Tinh Linh Ảo Ảnh "NOR"21h (Thứ 3-5-7-CN)\n");
			break;
		case CN:
			result += sprintf(HIY"3.Sơn Tặc: "NOR"Khung giờ (7-9-11-13-15-17-19-21-23) vào thứ (2-4-6-Chủ nhật)\n");
			result += sprintf(HIY"4.Đổi cầu: "NOR"Thứ 6, 7, Chủ nhật.\n");
			result += sprintf(HIY"5.Cứu nhân độ thế: "NOR"Khung giờ (8-10-12-14-16-18-20-22) vào thứ (3-7-Chủ nhật)\n");
			result += sprintf(HIY"6. Boss Phi Tặc Vương "NOR"21h (Thứ 2-4-6-CN)\n");
			result += sprintf(HIY"7. Boss Tinh Linh Ảo Ảnh "NOR"21h (Thứ 3-5-7-CN)\n");
			break;
		}
	}


	result += sprintf(HIY"BOSS Huyễn Thú: "NOR"Khung giờ (20-21-22) hằng ngày.\n");
	tell_user(me, "%s", result);
	return 1;
}