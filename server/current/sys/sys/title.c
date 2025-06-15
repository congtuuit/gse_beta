//称谓处理模块
#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

//称谓编码表
mapping mpTitle = ([

		"A001":"Anh Hùng Đả Hổ",
		"A002" : "Uy Võ Thiên Hạ",
		"A003" : "Công việc vinh quang nhất",
		"A004" : "Con ong chăm chỉ",
		"A005" : "Mô hình chiến tranh mạnh mẽ",
		"A006" : "Vận Tiêu Đại Siêu Nhân",
		"A007" : "Địa Ngục Thiếu Niên",
		"A008" : "Địa Ngục Thiếu Nữ",
		"A009" : "Thanh Đồng Thánh Đấu Sĩ",
		"A010" : "Bạch Ngân Thánh Đấu Sĩ",
		"A011" : "Hoàng Kim Thánh Đấu Sĩ",
		"A012" : "Hắc Ám Thánh Đấu Sĩ",
		"A013" : "一马平川",
		"A014" : "二龙戏珠",
		"A015" : "入木三分",
		"A016" : "遨游四海",
		"A017" : "武松打虎",
		"A018" : "过五关斩六将",

		"A020" : "Thiên Hạ Đệ Nhất",
		"A021" : "Nhất Đại Phú Hộ",
		"A022" : "Công Đức Vô Lượng",
		"A023" : "Giáo Lý Thiên Hạ",
		"A111" : "Chiến Quốc Minh Chủ",
		"A112" : "Chiến Quốc Tiểu Minh Chủ",
		"A999" : "Thợ Săn Kho Báu",
		"A900" : "Thập Đại Cao Thủ",

		// Achievement Titles - Combat
		"ACH001" : HIR"⚔️ Sát Thủ Đầu Tiên ⚔️"NOR,
		"ACH002" : HIR"🔥 Chiến Binh Bách Trận 🔥"NOR,
		"ACH003" : HIR"⚡ Chiến Thần Thiên Trận ⚡"NOR,
		"ACH004" : HIR"💀 Sát Thần Vạn Quái 💀"NOR,
		"ACH005" : HIR"👑 Bá Chủ Chiến Trường 👑"NOR,
		"ACH006" : HIR"⚔️ Boss Slayer ⚔️"NOR,
		"ACH007" : HIR"🔥 PvP Master 🔥"NOR,
		"ACH008" : HIR"⚡ Arena Champion ⚡"NOR,
		
		// Achievement Titles - Level
		"ACH101" : HIG"🌟 Tân Binh Võ Lâm 🌟"NOR,
		"ACH102" : HIG"⭐ Võ Sĩ Trung Cấp ⭐"NOR,
		"ACH103" : HIG"💫 Đại Võ Sĩ 💫"NOR,
		"ACH104" : HIG"✨ Võ Thánh ✨"NOR,
		"ACH105" : HIG"👑 Võ Đế 👑"NOR,
		
		// Achievement Titles - Skill
		"ACH201" : HIC"📚 Học Trò Chăm Chỉ 📚"NOR,
		"ACH202" : HIC"🎓 Thạc Sĩ Võ Học 🎓"NOR,
		"ACH203" : HIC"🏆 Bậc Thầy Võ Thuật 🏆"NOR,
		"ACH204" : HIC"👨‍🏫 Võ Sư Tối Cao 👨‍🏫"NOR,
		
		// Achievement Titles - Collection
		"ACH301" : HIY"💎 Thợ Săn Kho Báu 💎"NOR,
		"ACH302" : HIY"🏺 Nhà Sưu Tầm 🏺"NOR,
		"ACH303" : HIY"💍 Sở Hữu Hiếm Có 💍"NOR,
		"ACH304" : HIY"👑 Bộ Sưu Tập Hoàn Hảo 👑"NOR,
		
		// Achievement Titles - Social
		"ACH401" : HIM"🤝 Người Kết Giao 🤝"NOR,
		"ACH402" : HIM"👥 Lãnh Đạo Cộng Đồng 👥"NOR,
		"ACH403" : HIM"🌟 Ngôi Sao Xã Hội 🌟"NOR,
		"ACH404" : HIM"👑 Vua Giao Tiếp 👑"NOR,
		
		// Achievement Titles - Login
		"ACH501" : HIB"🌅 Người Kiên Trì 🌅"NOR,
		"ACH502" : HIB"📅 Chuyên Cần 📅"NOR,
		"ACH503" : HIB"⏰ Trung Thành ⏰"NOR,
		"ACH504" : HIB"👑 Vua Online 👑"NOR,
		
		// Achievement Titles - Task
		"ACH601" : HIG"📋 Nhiệm Vụ Hoàn Thành 📋"NOR,
		"ACH602" : HIG"🎯 Mục Tiêu Đạt Được 🎯"NOR,
		"ACH603" : HIG"🏆 Nhà Vô Địch Nhiệm Vụ 🏆"NOR,
		
		// Special Achievement Titles
		"ACH999" : HIR"🔥🔥🔥 THIÊN HẠ VÔ ĐỊCH 🔥🔥🔥"NOR,
		"ACH888" : HIM"💎💎💎 BÁ CHỦ THẾ GIỚI 💎💎💎"NOR,
		"ACH777" : HIY"👑👑👑 VÕ ĐẾ TỐI THƯỢNG 👑👑👑"NOR,

		"B001" : "Sư Phụ",		//Danh hiệu sư đồ
		"B002" : "Đệ Tử",
		"B003" : "Vị Nhân Sư Biểu",
		"B004" : "Giáo Lý Thiên Hạ",

		"C001" : "Bang Chủ",		// Bang phái
		"C002" : "Phó Bang Chủ",
		"C003" : "Trưởng Lão",
		"C004" : "Đường Chủ",
		"C005" : "Hương Chủ",
		"C006" : "Tinh Anh",
		"C007" : "Thương nhân",
		"C008" : "Bang Chúng",

		"F001" : "Đào Hoa Nguyên Đại Đệ Tử",
		"F002" : "Thục Sơn Đại Đệ Tử",
		"F003" : "Cấm Vệ Quân Đại Đệ Tử",
		"F004" : "Đường Môn Đại Đệ Tử",
		"F005" : "Mao Sơn Đại Đệ Tử",
		"F006" : "Côn Luân Đại Đệ Tử",
		"F007" : "Vân Mộng Cốc Đại Đệ Tử",

		"G001" : "Gia đình anh hùng",
		"G002" : "Loạn Thế Anh Hùng",
		"G003" : "GM",
		"G004" : "Nhà phát triển trò chơi",
		"G005" : "Tổ chức sự kiện trực tuyến",
		"G006" : "Thanh tra trò chơi",
		"G007" : "Thử nghiệm",

		"M001" : "Tướng công",
		"M002" : "Nương tử",


		"P001" : "Tân binh Chiến Quốc",
		"P002" : "Ngũ Trường",
		"P003" : "Bách Phu Trường",
		"P004" : "Thiên Phu Trường",
		"P005" : "Thiên Tướng Quân",
		"P006" : "Bình Quốc Tướng Quân",
		"P007" : "An Quốc Tướng Quân",
		"P008" : "Trấn Quốc Tướng Quân",
		"P009" : "Chính Dị Tướng Quân",
		"P010" : "Phiêu Kị Đại Tướng Quân",
		"P011" : "Thiên Hạ Đại Tướng Quân",

		"S111" : "Dẫn Lộ Tiểu Đồng",	//Hoa đào源门派称谓
		"S112" : "Kình Hoa Sĩ Nữ",
		"S121" : "Đào Viên Lực Sĩ",
		"S122" : "Sở Sở Y Nhân",
		"S131" : "Tiêu Dao Tán Tiên",
		"S132" : "Huệ Chất Lan Tâm",
		"S141" : "Thế Ngoại Chân Nhân",
		"S142" : "Khuynh Quốc Khuynh Thành",

		"S211" : "Sơn Giản Linh Đồng",	//蜀山门派称谓
		"S212" : "Sơn Khê Linh Ngư",
		"S221" : "Giang Hồ Du Hiệp",
		"S222" : "Bích Thiên Nữ Hiệp",
		"S231" : "Thông Thần Đạo Giả",
		"S232" : "Hoán Thần Sứ Giả",
		"S241" : "Thiên Ngoại Phi Tiên",
		"S242" : "Cửu Thiên Tiên Nữ",

		"S311" : "Tuần Thành Tiểu Binh",	//禁卫军门派称谓
		"S312" : "Truyền Lệnh Tín Sứ",
		"S321" : "Cấm Quân Giáo Đầu",
		"S322" : "Cấm Quân Thị Vệ",
		"S331" : "Chấp Pháp Quân Môn",
		"S332" : "Nguyệt Quang Anh Hiệp",
		"S341" : "Thần Uy Tướng Quân",
		"S342" : "Nữ Kiệt Anh Hào",

		"S411" : "Môn Tiền Thị Giả",	//唐门门派称谓
		"S412" : "Tiểu Gia Bích Ngọc",
		"S421" : "Đoạt Mệnh Thần Thủ",
		"S422" : "Tú Các Thiên Kim",
		"S431" : "Vô Ảnh Thần Tông",
		"S432" : "A Na Hoa Dung",
		"S441" : "Bát Thủ La Hán",
		"S442" : "Chí Tôn Hồng Nhan",

		"S511" : "Mao Sơn Tiểu Đạo",	//茅山门派称谓
		"S512" : "Thái Hoa Tiểu Tiên",
		"S521" : "Hộ Pháp Hành Giả",
		"S522" : "U Lan Mỹ Nhân",
		"S531" : "Giáng Ma Tôn Giả",
		"S532" : "Khu Ma Nữ Sứ",
		"S541" : "Ngự Pháp Thiên Sư",
		"S542" : "Kinh Thế Ngọc Cơ",

		"S611" : "Tam Thanh Đạo Đồng",	//昆仑山门派称谓
		"S612" : "Ngọc Thanh Tú Nữ",
		"S621" : "Ngự Long Sứ Giả",
		"S622" : "Ngự Long Tiên Tử",
		"S631" : "Hỏa Long Pháp Thần",
		"S632" : "Gia Lạc Sứ Giả",
		"S641" : "Thần Long Pháp Tôn",
		"S642" : "Phi Thiên Thánh Nữ",

		"S711" : "Dược Cốc Ngoan Hài",	//云梦泽门派称谓
		"S712" : "Quỷ Linh Tinh Quái",
		"S721" : "Hồi Mệnh Thánh Thủ",
		"S722" : "Băng Tuyết Ái Nhân",
		"S731" : "Quỷ Cốc Thần Y",
		"S732" : "Tố Thủ Kỳ Tài",
		"S741" : "Tế Thế Y Tôn",
		"S742" : "Độ Thế Quan Âm",

		"V001" : "VIP",

		"X" : "Bình Giới Đầu Hàm",

		"Z001" : "Chiến Quốc Nguyên Lão",
		"Z002" : "Chiến Quốc Tân Thủ Vương",
		"Z003" : "Chiến Quốc May Mặc Đại Sư",
		"Z004" : "Chiến Quốc Rèn Đúc Đại Sư",
		"Z005" : "Chiến Quốc Luyện Đơn Đại Sư",
		"Z006" : "Chiến Quốc Cơ Quan Đại Sư",
		"Z007" : "Chiến Quốc Đầu Bếp Đại Sư",
		"Z008" : "Chiến Quốc Đệ Nhất Bang Chủ",
		"Z009" : "Tiệt Đồ Tôn Giả",
		"Z010" : "Sáng Ý Sứ Giả",
		"Z011" : "Chiến Quốc Tài Tử",
		"Z012" : "Chiến Quốc Tài Nữ",
		"Z013" : "Chiến Quốc Điêu Khắc Đại Sư",
		"Z014" : "Chiến Quốc Vương Giả",
		"Z888" : "Vô Song Thành Chủ",
		"Z889" : "Hiệu Úy Vô Song Thành",

		"Y001" : "Hiệp Khách Giang Hồ",
		"Y005" : "Anh Hùng Võ Lâm",
		"Y010" : "Võ Học Cái Thế",
		"Y015" : "Võ Lâm Kinh Hồng Ảnh",
		"Y020" : "Võ Lâm Minh Chủ",
		"Y025" : "Thiên Hạ Vô Song",
		"Y101" : "Quản Trị Game",
		"Y102" : "Sứ Giả Sự Kiện",
		"Y200" : "Địa Ngục Bá Nhân",

		"W001" : "Binh lính Vô Song Thành",
		"W002" : "Đội trưởng Vô Song Thành",
		"W003" : "Thống lĩnh Vô Song Thành",
		"W004" : "Phó soái Vô Song Thành",
		"W005" : "Đại soái Vô Song Thành",

		"E500" : "Tứ Linh Vệ Hồn",

		"E100" : "Đang tự đánh...",
]);
mapping mpShouxi = ([
		"Đào Hoa Nguyên":"F001",
		"Thục Sơn" : "F002",
		"Cấm Vệ Quân" : "F003",
		"Đường Môn" : "F004",
		"Mao Sơn" : "F005",
		"Côn Luân" : "F006",
		"Vân Mộng Cốc" : "F007",

]);

// Title Effects System
mapping mpTitleEffects = ([
	// Combat Achievement Effects
	"ACH001" : ({ "effect_glow_red", "effect_sword_sparkle" }),
	"ACH002" : ({ "effect_fire_aura", "effect_combat_flame" }),
	"ACH003" : ({ "effect_lightning_bolt", "effect_thunder_strike" }),
	"ACH004" : ({ "effect_dark_shadow", "effect_death_aura" }),
	"ACH005" : ({ "effect_crown_glow", "effect_royal_aura" }),
	"ACH006" : ({ "effect_boss_slayer", "effect_monster_hunter" }),
	"ACH007" : ({ "effect_pvp_master", "effect_arena_champion" }),
	"ACH008" : ({ "effect_arena_glory", "effect_champion_light" }),
	
	// Level Achievement Effects
	"ACH101" : ({ "effect_star_twinkle", "effect_novice_glow" }),
	"ACH102" : ({ "effect_intermediate_shine", "effect_warrior_aura" }),
	"ACH103" : ({ "effect_master_radiance", "effect_expert_glow" }),
	"ACH104" : ({ "effect_saint_halo", "effect_divine_light" }),
	"ACH105" : ({ "effect_emperor_crown", "effect_imperial_aura" }),
	
	// Skill Achievement Effects
	"ACH201" : ({ "effect_book_glow", "effect_study_aura" }),
	"ACH202" : ({ "effect_graduation_cap", "effect_master_degree" }),
	"ACH203" : ({ "effect_trophy_shine", "effect_grandmaster" }),
	"ACH204" : ({ "effect_sensei_aura", "effect_ultimate_teacher" }),
	
	// Collection Achievement Effects
	"ACH301" : ({ "effect_diamond_sparkle", "effect_treasure_hunter" }),
	"ACH302" : ({ "effect_collector_glow", "effect_antique_aura" }),
	"ACH303" : ({ "effect_rare_item_shine", "effect_unique_glow" }),
	"ACH304" : ({ "effect_perfect_collection", "effect_complete_set" }),
	
	// Social Achievement Effects
	"ACH401" : ({ "effect_friendship_glow", "effect_social_aura" }),
	"ACH402" : ({ "effect_leader_radiance", "effect_community_light" }),
	"ACH403" : ({ "effect_star_power", "effect_celebrity_glow" }),
	"ACH404" : ({ "effect_communication_king", "effect_social_master" }),
	
	// Login Achievement Effects
	"ACH501" : ({ "effect_persistence_glow", "effect_dedication_aura" }),
	"ACH502" : ({ "effect_consistency_shine", "effect_regular_light" }),
	"ACH503" : ({ "effect_loyalty_radiance", "effect_faithful_glow" }),
	"ACH504" : ({ "effect_online_king", "effect_always_here" }),
	
	// Task Achievement Effects
	"ACH601" : ({ "effect_task_complete", "effect_mission_accomplished" }),
	"ACH602" : ({ "effect_goal_achieved", "effect_target_hit" }),
	"ACH603" : ({ "effect_task_champion", "effect_mission_master" }),
	
	// Special Achievement Effects
	"ACH999" : ({ "effect_ultimate_champion", "effect_world_dominator", "effect_fire_rainbow" }),
	"ACH888" : ({ "effect_world_emperor", "effect_universe_ruler", "effect_diamond_rain" }),
	"ACH777" : ({ "effect_supreme_master", "effect_god_of_war", "effect_golden_lightning" }),
]);

void SAVE_BINARY() { }

void create()
{

}

int check_title_code(string titlecode)
{
	return stringp(mpTitle[titlecode]) ? 1 : 0;
}

void send_title(object who, string titlecode)
{
	string titlename, name;
	int position;
	if (titlecode[0..0] == "B")
	{
		if (titlecode == "B002")
			titlename = CRA + "Đệ Tử của " + who->get_save_2("baishi.shifu.name");
		else if (titlecode == "B001")
			titlename = CRA + "Sư Phụ của " + who->get_save_2("baishi.tudi.name");
		else
			titlename = CRA + mpTitle[titlecode];
	}
	else
		if (titlecode[0..0] == "C")
		{
			name = who->get_org_name();
			if (name != "")
			{
				titlename = CRE + name + " " + mpTitle[titlecode];
			}
		}
		else
			if (titlecode[0..0] == "M")
			{
				name = who->get_save_2("marry.name");
				if (stringp(name) && name != "")
				{
					if (titlecode == "M001")
						titlename = CRD + "Tướng công của " + name + "";
					else if (titlecode == "M002")
						titlename = CRD + "Nương tử của " + name + "";
				}
			}
			else
				if (titlecode[0..0] == "X")
					titlename = USER_RANK_D->get_rank(who);
				else
					titlename = mpTitle[titlecode];
	if (sizeof(titlename) == 0)
		return;
	if (titlecode[0..0] == "A" || titlecode[0..0] == "Z")
		titlename = CRF + titlename;

	if (titlecode[0..0] == "E") {
		titlename = CRE + titlename;
	}

	send_user(who, "%c%c%s", 0xA2, 1, sprintf("%-4s%s", titlecode, titlename));
}

void delete_title(object who, string titlecode)
{
	string titlename;

	titlename = mpTitle[titlecode];
	if (sizeof(titlename) == 0)
		return;
	send_user(who, "%c%c%s", 0xA2, 2, titlecode);
}

void show_title(object who, string titlecode)
{
	string titlename, name, tmp_title_code, chan;
	int position, rank, interval;
	string* mingren_titlecode = ({ "A020","A021","A022","A023", "A111","F001","F002","F003","F004","F005","F006","F007", });

	int z1, x1, y1, z = get_z(who), x = get_x(who), y = get_y(who);

	who->delete("add_mingren_power");
	USER_ENERGY_D->count_ap(who);
	USER_ENERGY_D->count_cp(who);
	if (titlecode[0..0] == "P")
	{
		sscanf(titlecode, "P%d", rank);
		if (rank < 4)
			titlename = HIW + mpTitle[titlecode];
		else if (rank < 7)
			titlename = HIG + mpTitle[titlecode];
		else if (rank < 9)
			titlename = HIB + mpTitle[titlecode];
		else if (rank < 11)
			titlename = HIY + mpTitle[titlecode];
		else if (rank < 12)
			titlename = PPM + mpTitle[titlecode];
		else
			titlename = HIR + mpTitle[titlecode];
	}
	else
		if (titlecode[0..0] == "Y")
		{
			sscanf(titlecode, "Y%d", rank);
			if (rank < 2)
				titlename = HIC + mpTitle[titlecode];
			else if (rank < 6)
				titlename = HIC + mpTitle[titlecode];
			else if (rank < 11)
				titlename = PPM + mpTitle[titlecode];
			else if (rank < 16)
				titlename = PPM + mpTitle[titlecode];
			else if (rank < 100)
				titlename = YEL + mpTitle[titlecode];
			else if (rank < 200)
				titlename = HIR + mpTitle[titlecode];
			else
				titlename = CRF + mpTitle[titlecode];	//GRN	
		}
		else
			if (titlecode[0..0] == "W")
			{
				sscanf(titlecode, "W%d", rank);
				if (rank < 10)
					titlename = CRF + mpTitle[titlecode];
				else
					titlename = HIC + mpTitle[titlecode];	//GRN	
			}
			else
				if (titlecode[0..0] == "B")
				{
					if (titlecode == "B002")
						titlename = CRA + "Đệ Tử của " + who->get_save_2("baishi.shifu.name");
					else if (titlecode == "B001")
						titlename = CRA + "Sư Phụ của " + who->get_save_2("baishi.tudi.name");
					else
						titlename = CRA + mpTitle[titlecode];
					/*else
						titlename = CRA + "Sư Phụ của "+who->get_save_2("baishi.tudi.name");*/
				}
				else
					if (titlecode[0..0] == "C")
					{
						name = who->get_org_name();
						if (name != "")
						{
							titlename = CRE + name + " " + mpTitle[titlecode];
						}
					}
					else
						if (titlecode[0..0] == "M")
						{
							name = who->get_save_2("marry.name");
							if (stringp(name) && name != "")
							{
								if (titlecode == "M001")
									titlename = CRD + "Tướng công của " + name + "";
								else if (titlecode == "M002")
									titlename = CRD + "Nương tử của " + name + "";
							}

						}
						else
							if (titlecode[0..0] == "X") {
								titlename = USER_RANK_D->get_rank(who);
							}
							else
								titlename = mpTitle[titlecode];
	if (sizeof(titlename) == 0)
		return;
	if (titlecode[0..0] == "A" || titlecode[0..0] == "Z") {
		titlename = CRF + titlename;
	}
	else if (titlecode == "V001")
		titlename = HIY + titlename;
	else if (titlecode[0..0] == "E") {
		if (titlecode == "E100"){
			titlename = HIR + titlename;
		}
		else {
			titlename = CRE + titlename;
		}
	}

	tmp_title_code = who->get_title_code();
	who->set_title("tutu", titlename);

	who->set_dame_title_code("");

	if (tmp_title_code == "Z889" || titlecode == "Z889")
	{
		CHAR_CHAR_D->init_loop_perform(who);
		who->add_to_scene(get_z(who), get_x(who), get_y(who), get_d(who));
		who->set("title_exp", 5);
	}

	if (tmp_title_code == "A018" || titlecode == "A018")
	{
		USER_ENERGY_D->count_dp(who);
		USER_ENERGY_D->count_pp(who);
	}
	if (tmp_title_code == "Y001" || titlecode == "Y001")
	{
		CHAR_CHAR_D->init_loop_perform(who);
		who->add_to_scene(get_z(who), get_x(who), get_y(who), get_d(who));
	}
	if (tmp_title_code == "Y010" || titlecode == "Y010")
	{
		CHAR_CHAR_D->init_loop_perform(who);
		who->add_to_scene(get_z(who), get_x(who), get_y(who), get_d(who));
	}
	if (tmp_title_code == "Y015" || titlecode == "Y015")
	{
		CHAR_CHAR_D->init_loop_perform(who);
		who->add_to_scene(get_z(who), get_x(who), get_y(who), get_d(who));
	}
	if (tmp_title_code == "Y025" || titlecode == "Y025")
	{
		CHAR_CHAR_D->init_loop_perform(who);
		who->add_to_scene(get_z(who), get_x(who), get_y(who), get_d(who));
	}


	if (member_array(titlecode, mingren_titlecode) != -1)
	{
		who->set("add_mingren_power", 1);
		USER_ENERGY_D->count_ap(who);
		USER_ENERGY_D->count_cp(who);
	}
	if (titlecode[0..0] == "P")
	{
		who->set_dame_title_code(titlecode);
		USER_ENERGY_D->count_ap(who);
		USER_ENERGY_D->count_cp(who);
	}
	if (titlecode[0..0] == "W")
	{
		who->set_dame_title_code(titlecode);
		USER_ENERGY_D->count_ap(who);
		USER_ENERGY_D->count_cp(who);
	}

	if (titlecode[0..0] == "E")
	{
		who->set_dame_title_code(titlecode);
	}

	who->add_to_scene(get_z(who), get_x(who), get_y(who));

	send_user(who, "%c%c%w%w%w%w%w%w%w%w%w%w%w%w%w%c%c%s", 0x3d, 163, who->get_hp(),
		who->get_max_hp(), who->get_mp(), who->get_max_mp(), who->get_ap_0(),
		who->get_ap(), who->get_dp_0(), who->get_dp(), who->get_cp_0(),
		who->get_cp(), who->get_pp_0(), who->get_pp(), who->get_sp(),
		who->get_yuan(), who->get_max_yuan(), " PK: " + who->get_pk());


	USER_ENERGY_D->count_ap(who);
	USER_ENERGY_D->count_cp(who);

	CHAR_CHAR_D->init_loop_perform(who);
	who->add_to_scene(get_z(who), get_x(who), get_y(who), get_d(who));

	if (titlecode == "M001" || titlecode == "M002") {
		send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 5915, 3, OVER_BODY, PF_ONCE);
	}

	// Achievement Title Effects Integration
	if (titlecode[0..2] == "ACH")
	{
		// Apply title effects for achievement titles
		apply_title_effect(who, titlecode);
		
		// Special effects for legendary titles
		if (titlecode == "ACH999" || titlecode == "ACH888" || titlecode == "ACH777")
		{
			// Add special visual effects for legendary titles
			set_effect(who, EFFECT_LEGENDARY_TITLE, 1);
			
			// Send special notification to all players
			send_user(get_scene_object_2(who, USER_TYPE), "%c%s", '!', 
				sprintf(HIR"🔥 %s đã đạt được danh hiệu %s! 🔥"NOR, 
				who->get_name(), titlename));
		}
	}
	else
	{
		// Remove achievement effects when switching to non-achievement titles
		if (tmp_title_code[0..2] == "ACH")
		{
			remove_title_effect(who, tmp_title_code);
			remove_effect(who, EFFECT_LEGENDARY_TITLE);
		}
	}
}

void hide_title(object who, string titlecode)
{
	who->set_dame_title_code("");

	if (who->get_title_code() == "A018")
	{
		who->set_title("", "");
		USER_ENERGY_D->count_dp(who);
		USER_ENERGY_D->count_pp(who);
	}
	else
		if (who->get_title_code() == "Y001")
		{
			who->set_title("", "");
			CHAR_CHAR_D->init_loop_perform(who);
			who->add_to_scene(get_z(who), get_x(who), get_y(who), get_d(who));
		}
		else
			if (who->get_title_code() == "Y010")
			{
				who->set_title("", "");
				CHAR_CHAR_D->init_loop_perform(who);
				who->add_to_scene(get_z(who), get_x(who), get_y(who), get_d(who));
			}
			else
				if (who->get_title_code() == "Y015")
				{
					who->set_title("", "");
					CHAR_CHAR_D->init_loop_perform(who);
					who->add_to_scene(get_z(who), get_x(who), get_y(who), get_d(who));
				}
				else
					if (who->get_title_code() == "Y025")
					{
						who->set_title("", "");
						CHAR_CHAR_D->init_loop_perform(who);
						who->add_to_scene(get_z(who), get_x(who), get_y(who), get_d(who));
					}
					else
					{
						who->delete("add_mingren_power");
						who->set_title("", "");
						USER_ENERGY_D->count_ap(who);
						USER_ENERGY_D->count_cp(who);
					}
	who->add_to_scene(get_z(who), get_x(who), get_y(who), get_d(who));

	USER_ENERGY_D->count_ap(who);
	USER_ENERGY_D->count_cp(who);

	send_user(who, "%c%c%w%w%w%w%w%w%w%w%w%w%w%w%w%c%c%s", 0x3d, 163, who->get_hp(),
		who->get_max_hp(), who->get_mp(), who->get_max_mp(), who->get_ap_0(),
		who->get_ap(), who->get_dp_0(), who->get_dp(), who->get_cp_0(),
		who->get_cp(), who->get_pp_0(), who->get_pp(), who->get_sp(),
		who->get_yuan(), who->get_max_yuan(), " PK: " + who->get_pk());
}

string get_titlename(string titlecode)
{
	string titlename;

	titlename = mpTitle[titlecode];
	if (sizeof(titlename) == 0)
		return "";
	return titlename;
}

void add_shouxi_title(object who, string fam_name)
{
	who->add_title(mpShouxi[fam_name]);
}

string get_shouxi_titlecode(string fam_name)
{
	return 	mpShouxi[fam_name];
}

// Title Effect Functions
void apply_title_effect(object who, string titlecode)
{
	if (!mpTitleEffects[titlecode])
		return;
		
	string *effects = mpTitleEffects[titlecode];
	int i, size = sizeof(effects);
	
	for (i = 0; i < size; i++)
	{
		switch (effects[i])
		{
		case "effect_glow_red":
			set_effect(who, EFFECT_TITLE_GLOW_RED, 1);
			break;
		case "effect_sword_sparkle":
			set_effect(who, EFFECT_TITLE_SWORD_SPARKLE, 1);
			break;
		case "effect_fire_aura":
			set_effect(who, EFFECT_TITLE_FIRE_AURA, 1);
			break;
		case "effect_combat_flame":
			set_effect(who, EFFECT_TITLE_COMBAT_FLAME, 1);
			break;
		case "effect_lightning_bolt":
			set_effect(who, EFFECT_TITLE_LIGHTNING_BOLT, 1);
			break;
		case "effect_thunder_strike":
			set_effect(who, EFFECT_TITLE_THUNDER_STRIKE, 1);
			break;
		case "effect_dark_shadow":
			set_effect(who, EFFECT_TITLE_DARK_SHADOW, 1);
			break;
		case "effect_death_aura":
			set_effect(who, EFFECT_TITLE_DEATH_AURA, 1);
			break;
		case "effect_crown_glow":
			set_effect(who, EFFECT_TITLE_CROWN_GLOW, 1);
			break;
		case "effect_royal_aura":
			set_effect(who, EFFECT_TITLE_ROYAL_AURA, 1);
			break;
		case "effect_star_twinkle":
			set_effect(who, EFFECT_TITLE_STAR_TWINKLE, 1);
			break;
		case "effect_novice_glow":
			set_effect(who, EFFECT_TITLE_NOVICE_GLOW, 1);
			break;
		case "effect_book_glow":
			set_effect(who, EFFECT_TITLE_BOOK_GLOW, 1);
			break;
		case "effect_study_aura":
			set_effect(who, EFFECT_TITLE_STUDY_AURA, 1);
			break;
		case "effect_diamond_sparkle":
			set_effect(who, EFFECT_TITLE_DIAMOND_SPARKLE, 1);
			break;
		case "effect_treasure_hunter":
			set_effect(who, EFFECT_TITLE_TREASURE_HUNTER, 1);
			break;
		case "effect_friendship_glow":
			set_effect(who, EFFECT_TITLE_FRIENDSHIP_GLOW, 1);
			break;
		case "effect_social_aura":
			set_effect(who, EFFECT_TITLE_SOCIAL_AURA, 1);
			break;
		case "effect_persistence_glow":
			set_effect(who, EFFECT_TITLE_PERSISTENCE_GLOW, 1);
			break;
		case "effect_dedication_aura":
			set_effect(who, EFFECT_TITLE_DEDICATION_AURA, 1);
			break;
		case "effect_task_complete":
			set_effect(who, EFFECT_TITLE_TASK_COMPLETE, 1);
			break;
		case "effect_mission_accomplished":
			set_effect(who, EFFECT_TITLE_MISSION_ACCOMPLISHED, 1);
			break;
		case "effect_ultimate_champion":
			set_effect(who, EFFECT_TITLE_ULTIMATE_CHAMPION, 1);
			break;
		case "effect_world_dominator":
			set_effect(who, EFFECT_TITLE_WORLD_DOMINATOR, 1);
			break;
		case "effect_fire_rainbow":
			set_effect(who, EFFECT_TITLE_FIRE_RAINBOW, 1);
			break;
		case "effect_world_emperor":
			set_effect(who, EFFECT_TITLE_WORLD_EMPEROR, 1);
			break;
		case "effect_universe_ruler":
			set_effect(who, EFFECT_TITLE_UNIVERSE_RULER, 1);
			break;
		case "effect_diamond_rain":
			set_effect(who, EFFECT_TITLE_DIAMOND_RAIN, 1);
			break;
		case "effect_supreme_master":
			set_effect(who, EFFECT_TITLE_SUPREME_MASTER, 1);
			break;
		case "effect_god_of_war":
			set_effect(who, EFFECT_TITLE_GOD_OF_WAR, 1);
			break;
		case "effect_golden_lightning":
			set_effect(who, EFFECT_TITLE_GOLDEN_LIGHTNING, 1);
			break;
		}
	}
}

void remove_title_effect(object who, string titlecode)
{
	if (!mpTitleEffects[titlecode])
		return;
		
	string *effects = mpTitleEffects[titlecode];
	int i, size = sizeof(effects);
	
	for (i = 0; i < size; i++)
	{
		switch (effects[i])
		{
		case "effect_glow_red":
			remove_effect(who, EFFECT_TITLE_GLOW_RED);
			break;
		case "effect_sword_sparkle":
			remove_effect(who, EFFECT_TITLE_SWORD_SPARKLE);
			break;
		case "effect_fire_aura":
			remove_effect(who, EFFECT_TITLE_FIRE_AURA);
			break;
		case "effect_combat_flame":
			remove_effect(who, EFFECT_TITLE_COMBAT_FLAME);
			break;
		case "effect_lightning_bolt":
			remove_effect(who, EFFECT_TITLE_LIGHTNING_BOLT);
			break;
		case "effect_thunder_strike":
			remove_effect(who, EFFECT_TITLE_THUNDER_STRIKE);
			break;
		case "effect_dark_shadow":
			remove_effect(who, EFFECT_TITLE_DARK_SHADOW);
			break;
		case "effect_death_aura":
			remove_effect(who, EFFECT_TITLE_DEATH_AURA);
			break;
		case "effect_crown_glow":
			remove_effect(who, EFFECT_TITLE_CROWN_GLOW);
			break;
		case "effect_royal_aura":
			remove_effect(who, EFFECT_TITLE_ROYAL_AURA);
			break;
		case "effect_star_twinkle":
			remove_effect(who, EFFECT_TITLE_STAR_TWINKLE);
			break;
		case "effect_novice_glow":
			remove_effect(who, EFFECT_TITLE_NOVICE_GLOW);
			break;
		case "effect_book_glow":
			remove_effect(who, EFFECT_TITLE_BOOK_GLOW);
			break;
		case "effect_study_aura":
			remove_effect(who, EFFECT_TITLE_STUDY_AURA);
			break;
		case "effect_diamond_sparkle":
			remove_effect(who, EFFECT_TITLE_DIAMOND_SPARKLE);
			break;
		case "effect_treasure_hunter":
			remove_effect(who, EFFECT_TITLE_TREASURE_HUNTER);
			break;
		case "effect_friendship_glow":
			remove_effect(who, EFFECT_TITLE_FRIENDSHIP_GLOW);
			break;
		case "effect_social_aura":
			remove_effect(who, EFFECT_TITLE_SOCIAL_AURA);
			break;
		case "effect_persistence_glow":
			remove_effect(who, EFFECT_TITLE_PERSISTENCE_GLOW);
			break;
		case "effect_dedication_aura":
			remove_effect(who, EFFECT_TITLE_DEDICATION_AURA);
			break;
		case "effect_task_complete":
			remove_effect(who, EFFECT_TITLE_TASK_COMPLETE);
			break;
		case "effect_mission_accomplished":
			remove_effect(who, EFFECT_TITLE_MISSION_ACCOMPLISHED);
			break;
		case "effect_ultimate_champion":
			remove_effect(who, EFFECT_TITLE_ULTIMATE_CHAMPION);
			break;
		case "effect_world_dominator":
			remove_effect(who, EFFECT_TITLE_WORLD_DOMINATOR);
			break;
		case "effect_fire_rainbow":
			remove_effect(who, EFFECT_TITLE_FIRE_RAINBOW);
			break;
		case "effect_world_emperor":
			remove_effect(who, EFFECT_TITLE_WORLD_EMPEROR);
			break;
		case "effect_universe_ruler":
			remove_effect(who, EFFECT_TITLE_UNIVERSE_RULER);
			break;
		case "effect_diamond_rain":
			remove_effect(who, EFFECT_TITLE_DIAMOND_RAIN);
			break;
		case "effect_supreme_master":
			remove_effect(who, EFFECT_TITLE_SUPREME_MASTER);
			break;
		case "effect_god_of_war":
			remove_effect(who, EFFECT_TITLE_GOD_OF_WAR);
			break;
		case "effect_golden_lightning":
			remove_effect(who, EFFECT_TITLE_GOLDEN_LIGHTNING);
			break;
		}
	}
}
