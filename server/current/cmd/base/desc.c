
#include <ansi.h>
#include <item.h>
#include <equip.h>
#include <action.h>
#include <effect.h>

int main(object me, string arg)
{
	mapping	list;
	object map, leader, who, * inv, pawn, item, fileobj;
	string* key, id, name, name2, prop, color, result, file, special;
	int what, level, use, maxuse, point, locktime, lockutil;
	int min, sec, z, x, y, i, size, p;
	int iVip;
	string trangThaiTanCong = "";

	if (!arg) return 1;
	key = explode(arg, " ");
	if (sizeof(key) == 3) switch (key[0])
	{
	case "loop":	what = to_int(key[2]);
		name = key[1];
		if (!objectp(who = find_char(name)))	return 1;
		result = CHAR_CHAR_D->get_loop_desc(who, what);
		if (result != "" && result != 0)
		{
			z = strchr(result, '%');
			if (z >= 0)
			{
				log_file("error_loop.txt", sprintf("error:%d prop=%s\n", what, prop));
			}
		}
		else
		{
			log_file("error_loop.txt", sprintf("error2:%d prop=%s\n", what, prop));
			break;
		}
		if (me == who)
			send_user(me, "%c%w%s", 0x82, what, CHAR_CHAR_D->get_loop_desc(who, what));
		else
		{
			send_user(me, "%c%d%w%s", 0x84, getoid(who), what, CHAR_CHAR_D->get_loop_desc(who, what));
		}
		break;
	}
	else if (sizeof(key) == 2 && key[0] == "changpingnew")
	{
		if (key[1] == "yes")
			"npc/88/8800"->enter_changping(me);

		else if (key[1] == "yes2") {
			if (me->get_save("nhandoict") < 1)
			{
				if ("sys/sys/test_db"->get_yuanbao(me) < 50)
				{
					notify("Không đủ 5 Kim Nguyên Bảo");
					return;
				}
				"sys/sys/test_db"->add_yuanbao(me, -50);
				me->set_save("nhandoict", 1);
				"npc/88/8800"->enter_changping(me);
			}
			else
			{
				"npc/88/8800"->enter_changping(me);
			}
		}
		else if (key[1] == "no")
			"npc/88/8800"->refuse_changping(me);
		else if (key[1] == "leave")
			"npc/88/8800"->leave_changping(me);
	}
	//Changping_2
	else if (sizeof(key) == 2 && key[0] == "changpingnew_2")
	{
		if (key[1] == "yes")
			"npc/88/8800"->enter_changping_2(me);
		else if (key[1] == "no")
			"npc/88/8800"->refuse_changping_2(me);
		else if (key[1] == "leave")
			"npc/88/8800"->leave_changping_2(me);
	}
	else if (sizeof(key) == 2 && key[0] == "?")
	{
		item = find_any_object(key[1]);
		if (!item)
			return;
		result = ITEM_ITEM_D->get_look_string(me, item);
		send_user(me, "%c%d%s", 0x39, getoid(item), result);
		send_user(me, "%c%d%s", 0x31, getoid(item), result);
	}
	else if (sizeof(key) == 2 && key[0] == "product")
	{
		what = to_int(key[1]);
		if (what < 1000) file = sprintf("/item/stuff/%04d", what);
		else file = "/quest/product"->get_product_file(what);
		if (file != "") fileobj = load_object(file);
		if (fileobj)
		{
			result = "/sys/item/item"->get_look_string(me, fileobj, 0);
			send_user(me, "%c%c%w%s", 0x60, 11, what, result);
		}
	}
	else if (arg[< 1] == '#' && sscanf(arg, "%d %x#", x, y) == 2)
	{
		if (!objectp(who = find_player(sprintf("%d", x)))) return 1;
		inv = who->get_all_equip();
		for (i = 0, size = sizeof(inv); i < size; i++) if (objectp(item = inv[i]))
		{
			if (getoid(item) == y)
			{
				result = ITEM_ITEM_D->get_look_string(me, item);
				send_user(me, "%c%d%s", 0x39, getoid(item), result);
				send_user(me, "%c%d%s", 0x31, getoid(item), result);
				return 1;
			}
		}
		inv = all_inventory(who, 1, MAX_CARRY);
		for (i = 0, size = sizeof(inv); i < size; i++) if (objectp(item = inv[i]))
		{
			if (getoid(item) == y)
			{
				result = ITEM_ITEM_D->get_look_string(me, item);
				send_user(me, "%c%d%s", 0x39, getoid(item), result);
				send_user(me, "%c%d%s", 0x31, getoid(item), result);
				return 1;
			}
		}
		send_user(me, "%c%d%s", 0x39, y, "Trên người chơi không tìm thấy vật phẩm này.");
	}
	else if (sscanf(arg, "%s %s", id, prop) == 2) switch (id)
	{
	case	"skl":	what = to_int(prop);
		if (item = load_object(SKILL->get_skill_file(what)))
		{
			if (item->is_vita_skill())
				send_user(me, "%c%c%w%s", 0x60, 2, what, item->get_desc());
			else
				send_user(me, "%c%w%s", 0x35, what, item->get_desc());
		}
		break;

	case "skill":	what = to_int(prop);
		if (item = load_object(SKILL->get_skill_file(what)))
			send_user(me, "%c%w%s", 0x36, what, item->get_desc());
		break;

	case "pf":	what = to_int(prop);
		if (item = load_object(SKILL->get_perform_file(what)))
		{
			if (item->is_vita_skill())
				send_user(me, "%c%c%w%d%s", 0x60, 4, what / 1000 * 10, what, item->get_desc());
			if (item->is_pet_skill())
				send_user(me, "%c%c%d%d%s", 0xA1, 21, 0, what, item->get_desc(me));
			else
				send_user(me, "%c%w%s", 0x37, what, item->get_desc(me));
		}
		break;

	case "team":	// 查看队友信息

		if (!stringp(name = me->get_leader())) return 1;
		if (!objectp(who = find_player(prop))) return 1;
		if (!stringp(result = who->get_leader())) return 1;
		if (name != result) return 1;

		map = get_map_object(get_z(who));
		name = map ? map->get_name() : "Bản đồ vô danh";

		result = sprintf("ＩＤ：%d\nĐánh giá：%d\nnước：%s\nvị trí：%s (%d, %d)\n",
			who->get_number(), who->get_level(), who->get_city_name(), name, get_x(who), get_y(who));

		if ((name = me->get_leader())
			&& (leader = find_player(name))
			&& leader->get_bonus_member() == who)
			result += HIY "Ông đã được đưa người mới\n" NOR;

		send_user(me, "%c%d%s", 0x38, who->get_number(), result);

		break;

	case	"npc":	// 查看天兵信息

		if (!objectp(who = find_char(prop)))	return 1;

		if (!who->is_zombie() || who->get_owner() != me) return 1;

		if (!inside_screen_2(me, who))
		{
			notify("Bạn cách %s quá xa rồi.", who->get_name());
			return 1;
		}

		if (!is_god(me) && gone_time(who->get("desc")) < 60)
		{
			who->set("desc", time());    // 不能频繁查看
			return 1;
		}
		if (who->is_jiguan())
		{
			return 1;
		}
		who->set("desc", time());
		min = NPC_SLAVE_D->upgrade_level_need(who);
		if (min < 0) min = 0;
		if (who->get_level_2() < 3)
		{
			tell_user(me, "%s \nCấp bậc: %4d       Cấp bậc: %4d cấp \n Thăng cấp cần: %d   điểm kinh nghiệm \n "
				"Khí Huyết: %4d / %4d      Ma Lực: %4d / %4d \n"
				"Ngoại Công: %4d  -  %4d      Ngoại Kháng: %4d  -  %4d \n"
				"Nội Công: %4d  -  %4d      Nội Kháng: %4d  -  %4d \n"
				"Thân Thủ: %4d \n",
				who->get_name(), who->get_level(), who->get_level_2(), min,
				who->get_hp(), who->get_max_hp(), who->get_mp(), who->get_max_mp(),
				who->get_ap_0(), who->get_ap(), who->get_dp_0(), who->get_dp(),
				who->get_cp_0(), who->get_cp(), who->get_pp_0(), who->get_pp(), who->get_sp());
		}
		else
		{
			tell_user(me, "%s \nCấp bậc： %4d	    Cấp bậc： %4d cấp \nCấp bậc đã đạt tối đa \n"
				"Khí Huyết: %4d / %4d      Ma Lực: %4d / %4d \n"
				"Ngoại Công: %4d  -  %4d      Ngoại Kháng: %4d  -  %4d \n"
				"Nội Công: %4d  -  %4d      Nội Kháng: %4d  -  %4d \n"
				"Thân Thủ: %4d \n",
				who->get_name(), who->get_level(), who->get_level_2(),
				who->get_hp(), who->get_max_hp(), who->get_mp(), who->get_max_mp(),
				who->get_ap_0(), who->get_ap(), who->get_dp_0(), who->get_dp(),
				who->get_cp_0(), who->get_cp(), who->get_pp_0(), who->get_pp(), who->get_sp());

		}
		break;

	case "user":	// 查看玩家信息

		if (!objectp(who = find_player(prop))) return 1;

		if (!inside_screen_2(me, who))
		{
			notify("Bạn cách %s quá xa rồi.", who->get_name());
			return 1;
		}

		if (who->get_attack_mode() != 1) {
			trangThaiTanCong = "Chiến đấu!";
		}
		else {
			trangThaiTanCong = "Hòa bình.";
		}

		if (!who->get_save_2("marry"))
		{
			tell_user(me, "Tên nhân vật: "
				HIC "%s "NOR "         Số ID: ( "HIY "%d "NOR " )\n Môn phái: "
				HIY "%s \n Quốc gia: %s \n Bang phái: "HIC "%s \n Ngoại hiệu: %s \n Cấp độ hiện tại: "
				HIC "%d "NOR "         Rank: "HIC"%s "NOR"(%d điểm)\n"
				HIY " Điểm PK: %d. \n"HIC" %s "NOR "vẫn còn "HIY"độc thân"
				NOR ".\n Trạng thái: %s\n"
				HIY " Điểm cống hiến: %d.\n"
				HIR " Lực chiến: %s\n",
				who->get_name(), who->get_number(),
				who->get_fam_name() == "" ? "－－" : who->get_fam_name(),
				who->get_city_name() == "" ? "－－" : who->get_city_name(),
				who->get_org_name() == "" ? "－－" : who->get_org_name(),
				who->get_title() == "" ? "－－" : who->get_title(),
				who->get_level(),who->get_save_2("ranked.name"), who->get_save_2("ranked.point"),who->get_pk(), who->get_name(), trangThaiTanCong, who->get_save_2("donate.total"), who->tinh_luc_chien());
		}
		else
		{
			tell_user(me, "Tên nhân vật: "HIC "%s "NOR "         Số ID: ( "HIY "%d "NOR " )\n Môn phái: "
				HIY "%s \n Quốc gia: %s \n Bang phái: "HIC "%s \n Ngoại hiệu: %s \n Cấp độ hiện tại: "
				HIC "%d "NOR "         Rank: "HIC" %s "NOR"(%d điểm)\n"
				HIY " Điểm PK: %d. \n "HIC" %s "NOR " đã "HIY"Kết Hôn "NOR "với "HIC"%s "NOR ". \nTrạng thái: %s\n"
				HIY " Điểm cống hiến: %d.\n"
				HIR " Lực chiến: %s\n",
				who->get_name(), who->get_number(),
				who->get_fam_name() == "" ? "－－" : who->get_fam_name(),
				who->get_city_name() == "" ? "－－" : who->get_city_name(),
				who->get_org_name() == "" ? "－－" : who->get_org_name(),
				who->get_title() == "" ? "－－" : who->get_title(),
				who->get_level(), who->get_save_2("ranked.name"), who->get_save_2("ranked.point"), who->get_pk(), who->get_name(), who->get_save_2("marry.name"), trangThaiTanCong, who->get_save_2("donate.total"), who->tinh_luc_chien());
		}
		break;

	case "char":	// 查看玩家装备

		if (!objectp(who = find_player(prop))) return 1;

		if ((is_gm2(who) || is_god(who) || is_gm3(who)) && (is_player(me)))
		{
			write_user(me, HIR"Bạn không thể xem thông tin người này.");
			return 1;
		}
		/*
				if( !inside_screen_2(me, who) )
				{
					notify(	"Bạn cách %s quá xa rồi.", who->get_name() );
					return 1;
				}
		*/
		send_user(me, "%c%c%s", 0x56, 0, sprintf("%s(%d)\n%s\n%s\n%s\n%s\n",
			who->get_name(), who->get_number(),
			who->get_city_name() == "" ? "－－" : who->get_city_name(),
			who->get_fam_name() == "" ? "－－" : who->get_fam_name(),
			who->get_org_name() == "" ? "－－" : who->get_org_name(),
			who->get_title()));
		//		if (MAIN_D->get_host_type()!=1000)
		if ("/sys/sys/count"->get_new_person()) {
			send_user(me, "%c%c%d%w%w%w%w%w%w%w%w%w%w%s", 0x56, 0xfe,
				who->get_armor_code(), who->get_armor_color_1(), who->get_hair(),
				who->get_hair_color(), who->get_back(), who->get_back_color(), who->get_back2(), who->get_back2_color(),
				who->get_weapon_code_2(), who->get_weapon_color(), who->get_weapon_color_2(),
				USER_RANK_D->get_rank(who));
		}
		else {
			send_user(me, "%c%c%d%w%w%s", 0x56, 0xff,
				who->get_armor_code(), who->get_armor_color_1(), who->get_weapon_code_2(),
				USER_RANK_D->get_rank(who));
		}

		inv = who->get_all_equip();
		for (i = 0, size = sizeof(inv); i < size; i++) if (objectp(item = inv[i]))
			send_user(me, "%c%c%w%w%c%s", 0x56, get_d(item),
				item->get_picid_2(), item->get_amount(), item->get_item_color(),
				sprintf("%-40s%s", item->get_name(), ITEM_ITEM_D->get_look_string(me, item)));

		level = me->get_level();  point = who->get_level();
		if ((level <= point - 10) && is_player(me))
		{
			if (gone_time(who->get_time("desc_char")) > 300)    // 五分钟后显示
				write_user(who, "Bạn phát hiện " HIY " %s " NOR " đang nhìn bạn với ánh mắt ngưỡng mộ và ghen ghét.", me->get_name());
			who->set_time("desc_char", time());
		}
		else if ((level < point + 10) && is_player(me))
		{
			if (random(2))	if (gone_time(who->get_time("desc_char")) > 300)
				write_user(who, "Bạn cảm giác như có ai đó đang nhìn chăm chăm vào bạn.");
			who->set_time("desc_char", time());
		}

		break;

	default:	name = id;  what = to_int(prop);

		if (!objectp(who = find_char(name)))	return 1;
		if (!who->is_seller() && !who->is_seller_2() && !who->is_banker() && !who->is_trader() && !who->is_store_open() && !who->is_bonus_seller() && !who->is_item_seller()) return 1;

		if (!inside_screen_2(me, who))
		{
			if (who->is_banker() && (time() - me->get("pawn_time") <= 300));
			else
			{
				notify("Bạn cách %s quá xa rồi.", who->get_name());
				return 1;
			}
		}

		if (who->is_seller() || who->is_seller_2() || who->is_item_seller())
		{
			if (!stringp(name = who->get_2(sprintf("good.%02d", what)))) return 1;
			name->do_look_2(me, what, 1);
		}
		else if (who->is_banker())
		{
			pawn = new(PAWN);
			pawn->set_id(me->get("pawn#"));
			pawn->set_owner(me->get_id());

			list = pawn->get_pawn();
			destruct(pawn);

			if (!mapp(list) || !sizeof(list)) return 1;
			if (!stringp(prop = list[sprintf("%02d", what)])) return	1;
			/*
						if( !sscanf( prop, "%s;%*s", name ) || !load_object(name) ) return 1;

						result = "";
						switch(	name->get_item_type() )
						{
				 case ITEM_TYPE_EQUIP :	if( sscanf( prop, "%s;%d;%d;%d;%s;[%s]%d,%d", name, size, use, maxuse, prop, id, locktime, lockutil ) != 8 )
							{
								send_user( me, "%c%c%s", 0x34, what, "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。" );
								return 1;
							}
							if( !sscanf(prop, "%s-1-:%d,%*s", name2, point)	) point	= 0;	// 免装备等级
							level =	name->get_level() - me->get_equip_less_level() - point;
							if( level < 0 )	level =	0;
							if (name->get_stuff_type()==0)
								result += sprintf( "耐久度: %d / %d\n",	use / 100, maxuse / 100	);
							else
								result += sprintf( "使用次数: %d / %d\n", use /	100, maxuse / 100 );
							if (name->get_stuff_type()==0)
							{
								if (level>0) result += sprintf(	"装备要求: %s%d	级\n", level > me->get_level() ? HIR : NOR,  name->get_level() );
							}
							else
							{
								if (level>0) result += sprintf(	"技能要求: %s%d	级\n", NOR,  name->get_level() );
							}

							name2 =	me->get_fam_name();

							switch(	name->get_equip_type() )
							{
							   case HEAD_TYPE :
							   case ARMOR_TYPE :
									if( name->get_gender() == 1 )
										result += sprintf( "适用于: %s男性\n", me->get_gender()	== 1 ? NOR : HIR );
									else
									if( name->get_gender() == 2 )
										result += sprintf( "适用于: %s女性\n", me->get_gender()	== 2 ? NOR : HIR );
									// break;    //	同下面共用，不能有 break;

								  default :	switch(	name->get_family() )
									{
			//						default	: result += "适用门派: －－\n";	 break;
									   case 1 :	result += sprintf( "适用门派: %s Đào Hoa Nguyên\n",
											name2 != "Đào Hoa Nguyên" ? HIR	: NOR );  break;
									   case 2 :	result += sprintf( "适用门派: %s Thục Sơn\n",
											name2 != "Thục Sơn"	? HIR :	NOR );	break;
									   case 3 :	result += sprintf( "适用门派: %s Cấm Vệ Quân\n",
											name2 != "Cấm Vệ Quân" ? HIR	: NOR );  break;
									   case 4 :	result += sprintf( "适用门派: %s Đường Môn\n",
											name2 != "Đường Môn"	? HIR :	NOR );	break;
									   case 5 :	result += sprintf( "适用门派: %s Mao Sơn\n",
											name2 != "Mao Sơn"	? HIR :	NOR );	break;
									   case 6 :	result += sprintf( "适用门派: %s Côn Luân\n",
											name2 != "Côn Luân" ? HIR	: NOR );  break;
									   case 7 :	result += sprintf( "适用门派: %s Vân Mộng Cốc\n",
											name2 != "Vân Mộng Cốc" ? HIR	: NOR );  break;
									}
									break;
							 case WEAPON_TYPE :	switch(	name->get_family() )
									{
			//						default	: result += "适用门派: －－\n";	 break;
									   case 1 :	result += sprintf( "适用门派: %s Đào Hoa Nguyên\n",
											name2 != "Đào Hoa Nguyên" ? HIR	: NOR );  break;
									   case 2 :	result += sprintf( "适用门派: %s Thục Sơn\n",
											name2 != "Thục Sơn"	? HIR :	NOR );	break;
									   case 3 :	result += sprintf( "适用门派: %s Cấm Vệ Quân\n",
											name2 != "Cấm Vệ Quân" ? HIR	: NOR );  break;
									   case 4 :	result += sprintf( "适用门派: %s Đường Môn\n",
											name2 != "Đường Môn"	? HIR :	NOR );	break;
									   case 5 :	result += sprintf( "适用门派: %s Mao Sơn\n",
											name2 != "Mao Sơn"	? HIR :	NOR );	break;
									   case 6 :	result += sprintf( "适用门派: %s Côn Luân\n",
											name2 != "Côn Luân" ? HIR	: NOR );  break;
									   case 7 :	result += sprintf( "适用门派: %s Vân Mộng Cốc\n",
											name2 != "Vân Mộng Cốc" ? HIR	: NOR );  break;
									   case 9 :	result += sprintf( "适用门派: %s Vân Mộng Cốc, Thục Sơn, Mao Sơn, Côn Luân\n",
											(name2 != "Vân Mộng Cốc" && name2 != "Mao Sơn" && name2 != "Thục Sơn" && name2 != "Côn Luân" ) ? HIR	: NOR );  break;
									}
									break;
							}
							switch(	name->get_item_color() )
							{
							  default :	color =	"";  break;
							   case 1 :	color =	HIC;  break;
							   case 2 :	color =	HIY;  break;
							   case 3 :	color =	HIG;  break;
							}
							if( prop != "" )
							{
								key = explode(prop, ",");
								size = sizeof(key);
								for( i = 0;i < size; i ++ )
								{
									if( !sscanf( key[i], "%s:%d", name2, point ) )	continue;
									if (name2=="hide"&&point>0)
									{
										size = -1;
										id = "";
										result += HIR "未鉴定";
										break;
									}
								}
								if (size==-1) break;
								for( i = 0;i < size; i ++ )
								{
									if( !sscanf( key[i], "|%s:%d", name2, point ) )	continue;
									result += ITEM_EQUIP_D->get_chinese_prop_string_3(name,	name2, point, color);
								}
								if( !sscanf(prop, "%s+:%d,%*s",	name2, point) )	point =	0;
							}


							id = "";  if( point ) id = sprintf("%+d", point);

							break;

				  case ITEM_TYPE_TALISMAN :	if( sscanf( prop, "%s;%d;%d;%d;%d;[%s]%d,%d", name, size, use, maxuse, point, id, locktime, lockutil ) != 8 )
							{
								send_user( me, "%c%c%s", 0x34, what, "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。" );
								return 1;
							}

							result += sprintf( "耐久度: %d / %d\n",	use / 100, maxuse / 100	);
							if (name->get_stuff_type()==0) result += sprintf( "%d 级法宝\n", name->get_level() );
							else result += sprintf( "装备要求 %d 级\n", name->get_level() );

							switch(	name->get_talisman_type() )
							{
							  default :	break;

							   case 2 :	// Cửu Long Thần Hỏa
								result += sprintf( "气血: %d / %d\n", point, name->get_max_hp()	);
								break;
							   case 9 :	// 招魂幡
								if( point < name->get_time_interval() )
									result += sprintf( HIR "%d％ 准备中\n",	point *	100 / name->get_time_interval()	);
								else	result += HIG "100％ 准备好\n";
								break;
							}

							switch(	name->get_level() )
							{
							  default :	color =	"";  break;
							   case 2 :	color =	HIC;  break;
							   case 3 :	color =	HIY;  break;
							}
							id = "";

							break;

				  case ITEM_TYPE_FLAG :	if( sscanf( prop, "%s;%d;[%s]%d,%d", name, size, id, locktime, lockutil	) != 5 )
							{
								send_user( me, "%c%c%s", 0x34, what, "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。" );
								return 1;
							}

							name2 =	me->get_fam_name();
							result += sprintf( "适用门派: %s Vân Mộng Cốc\n", name2 != "Vân Mộng Cốc" ? HIR : NOR );

							color =	"";  id	= "";

							break;

				  case ITEM_TYPE_POISON   :	if( sscanf( prop, "%s;%d;[%s]%d,%d", name, size, id, locktime, lockutil	) != 5 )
							{
								send_user( me, "%c%c%s", 0x34, what, "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。" );
								return 1;
							}

							name2 =	me->get_fam_name();
			//				result += sprintf( "适用门派: %s Đường Môn\n", name2 != "Đường Môn" ? HIR : NOR );

							if( point = name->get_poison() ) result	+= ITEM_EQUIP_D->get_chinese_prop_string(name,	 "@" , point);

							color =	"";  id	= "";

							break;

				  case ITEM_TYPE_POISON_2 :	if( sscanf( prop, "%s;%d;%d;[%s]%d,%d",	name, size, point, id, locktime, lockutil ) != 6 )
							{
								send_user( me, "%c%c%s", 0x34, what, "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。" );
								return 1;
							}
							result += sprintf( "毒性: %d\n", point );

							color =	"";  id	= "";

							break;

				case ITEM_TYPE_BOOK   :
				case ITEM_TYPE_BOOK_2 :	if( sscanf( prop, "%s;%d;[%s]%d,%d", name, size, id, locktime, lockutil	) != 5 )
							{
								send_user( me, "%c%c%s", 0x34, what, "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。" );
								return 1;
							}
							if( ( name2 = name->get_family_name() )	!= "" )
								   result += sprintf( "适用门派: %s%s\n", name2 != me->get_family_name() ? HIR : NOR, name2	);

							color =	"";  id	= "";

							break;

				  case ITEM_TYPE_TREASURE :	if( sscanf( prop, "%s;%d;%d;%d;%d;[%s]%d,%d", name, size, z, x,	y, id, locktime, lockutil ) != 8 )
							{
								send_user( me, "%c%c%s", 0x34, what, "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。" );
								return 1;
							}
							if( map	= get_map_object(z) ) result +=	sprintf( "位置:	%s(%d,%d)\n", map->get_name(), x, y );

							color =	"";  id	= "";

							break;

				 case ITEM_TYPE_DIAMOND_2 :	if( sscanf( prop, "%s;%d;%d;[%s]%d,%d",	name, size, point, id, locktime, lockutil ) != 6 )
							{
								send_user( me, "%c%c%s", 0x34, what, "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。" );
								return 1;
							}
							color =	"";  id	= "";  if( point ) id =	sprintf("%+d", point);

							break;

				 case ITEM_TYPE_POTENTIAL :	if( sscanf( prop, "%s;%d;%d;[%s]%d,%d",	name, size, point, id, locktime, lockutil ) != 6 )
							{
								send_user( me, "%c%c%s", 0x34, what, "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。" );
								return 1;
							}
							if( point ) result += sprintf( "tiềm năng: %+d\n", point );

							color =	"";  id	= "";

							break;
				case ITEM_TYPE_SPECIAL :if( sscanf( prop, "%s;%d;%s;[%s]%d,%d", name, size, special,id, locktime, lockutil	) != 6 )
							{
								send_user( me, "%c%c%s", 0x34, what, "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。" );
								return 1;
							}
							color =	"";  id	= "";
			//				result = name->get_special_desc(special);
						send_user( me, "%c%c%s", 0x34, what, sprintf( "%s%s%s\n%s%s",
							color, name->get_name(), id, name->get_special_desc(special), result ) );

							return;
						  default :	if( sscanf( prop, "%s;%d;[%s]%d,%d", name, size, id, locktime, lockutil	) != 5 )
							{
								send_user( me, "%c%c%s", 0x34, what, "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。" );
								return 1;
							}
							color =	"";  id	= "";

							break;
						}
						if ( name->is_suit() )
							result += name->get_suit_desc();
			*/
			result = ITEM_ITEM_D->get_pawn_string(me, prop);
			send_user(me, "%c%c%s", 0x34, what, result);
		}
		else if (who->is_trader())
		{
			if (!stringp(name = who->get_2(sprintf("good.%02d", what)))) return 1;
			send_user(me, "%c%c%s", 0x33, what,
				sprintf("%s\nGiá mua %d lượng\nDư %d cái\n", name->get_desc(),
					name->get_buy_price() + name->get_buy_range() * who->get_buy_rate() / 1000,
					who->get_2(sprintf("list.%02d", what))));
		}
		else if (who->is_store_open())
		{
			if (!mapp(list = who->get_store_dbase()) || !(size = sizeof(key = keys(list))))
			{
				notify(who->get_name() + "Gì đó tất cả đều bán hết");
				return 1;
			}
			if ((item = number_present(who, what, 1, MAX_CARRY)) && list[sprintf("%02d", what)] > 0)
				item->do_look_2(me, what, 1);
		}
		if (who->is_bonus_seller())
		{
			if (!stringp(name = who->get_2(sprintf("good.%02d", what)))) return 1;
			name->do_look_2(me, what, 1);
		}

		break;
	}
	else if (sscanf(arg, "%d,%d", x, y) == 2)
	{
		if (!objectp(item = get_xy_object(get_z(me), x, y, ITEM_TYPE))) return 1;

		if (!inside_screen_2(me, item))
		{
			notify("Bạn cách %s quá xa rồi.", item->get_name());
			return 1;
		}
		else	item->do_look(me);
	}
	else switch (arg)
	{
	case "me":
		if (!me->is_die())
		{
			me->do_look(me);
			return 1;
		}
		if (get_effect(me, EFFECT_USER_DIE_5))	return 1;
		if (get_effect(me, EFFECT_USER_DIE_9))
		{
			result = "Bạn chết rồi, bạn có những lựa chọn sau:\n";
			if (me->get_vip() && "item/sell/0061"->check_revive(me))
			{
				iVip = 1;
				result += ESC "Sử dụng VIP để hồi sinh tại chỗ miễn phí.\ndesc vip_revive19\n";
			}
			if (objectp(item = present("Phục Sinh Đơn", me, 1, MAX_CARRY)))
			{
				min = 1;
				result += ESC"Sử dụng "HIY "Phục Sinh Đơn "NOR " hồi sinh tại chỗ.\ndesc revive19\n";
			}
			if (iVip || min)
			{
				send_user(me, "%c%s", ':', result +
					ESC "Chờ tự động hồi sinh.\nCLOSE\n");
			}
			return 1;	// 如果有其他死亡状态处理程序，则取消复活D
		}
		if (me->get_vip() && "item/sell/0061"->check_revive(me))
		{
			iVip = 1;
		}
		if (me->get_level() < 15)    // 死亡新手保护
		{

			result = "Bạn chết rồi, bạn có những lựa chọn sau:\n";
			if (iVip)
			{
				result += ESC "Sử dụng VIP để hồi sinh tại chỗ miễn phí.\ndesc vip_revive1\n";
				result += ESC "Sử dụng VIP để hồi sinh ngẫu nhiên vị trí trong khu vực.\ndesc vip_revive2\n";
			}
			if (is_gm3(me))
			{
				result += ESC"Hồi sinh tại chỗ\nsetdie 0\n";
				result += ESC"Giết chết GM thưởng\ngmdrop\n";
			}
			else
				if (me->get_level() < 10)
					result += ESC"Hồi sinh tại chỗ (hồi phục 1 nửa Khí Huyết và Ma Lực)\ndesc revive2\n";
			send_user(me, "%c%s", ':', result +
				ESC "Lập tức Hồi sinh.\ndesc revive\n");
		}
		else if (me->is_die() == 2 && objectp(who = me->get("pf.05114")))
		{
			result = sprintf("Bạn đã chết, có thể lựa chọn tự động hồi sinh hoặc chờ Vân Mộng Cốc cứu chữa, giảm bớt tổn thất nhưng sẽ phải trả tiền thuốc men.\n"
				ESC "%s(%d) cứu sống.\ndesc revive$\n", who->get_name(), who->get_number());
			if (iVip)
			{
				result += ESC "Sử dụng VIP để hồi sinh tại chỗ miễn phí.\ndesc vip_revive1\n";
				result += ESC "Sử dụng VIP để hồi sinh ngẫu nhiên vị trí trong khu vực.\ndesc vip_revive2\n";
			}
			if (me->get_skill(329) >= 26 && "/skill/03/03293"->if_can_perform(me))
			{
				result += ESC"Sử dụng Quy Nguyên Thuật hồi sinh.\npf3 3293\n";
			}
			if (objectp(item = present("Phục Sinh Đơn", me, 1, MAX_CARRY)))
			{
				result += ESC"Sử dụng "HIY "Phục Sinh Đơn "NOR " hồi sinh tại chỗ.\ndesc revive1\n";
				result += ESC"Sử dụng "HIY "Phục Sinh Đơn "NOR "hồi sinh vị trí ngẫu nhiên trong khu vực.\ndesc revive11\n";
			}
			if (is_gm3(me))
			{
				result += ESC"Hồi sinh tại chỗ\nsetdie 0\n";
				result += ESC"Giết chết GM thưởng\ngmdrop\n";
			}
			send_user(me, "%c%s", ':', result +
				ESC "Lập tức hồi sinh.\ndesc revive\n" +
				ESC "Chờ người đến cứu.\nCLOSE\n");

		}
		else
		{
			result = "Bạn đã chết, có thể lựa chọn tự động hồi sinh hoặc chờ Vân Mộng Cốc cứu chữa, giảm bớt tổn thất nhưng sẽ phải trả tiền thuốc men.\n";
			if (iVip)
			{
				result += ESC "Sử dụng VIP để hồi sinh tại chỗ miễn phí.\ndesc vip_revive1\n";
				result += ESC "Sử dụng VIP để hồi sinh ngẫu nhiên vị trí trong khu vực.\ndesc vip_revive2\n";
			}
			if (me->get_skill(329) >= 26 && "/skill/03/03293"->if_can_perform(me))
			{
				result += ESC"Sử dụng Quy Nguyên Thuật hồi sinh.\npf3 3293\n";
			}
			if (objectp(item = present("Phục Sinh Đơn", me, 1, MAX_CARRY)))
			{
				result += ESC"Sử dụng "HIY "Phục Sinh Đơn "NOR " hồi sinh tại chỗ.\ndesc revive1\n";
				result += ESC"Sử dụng "HIY "Phục Sinh Đơn "NOR "hồi sinh vị trí ngẫu nhiên trong khu vực.\ndesc revive11\n";
			}
			if (is_gm3(me))
			{
				result += ESC"Hồi sinh tại chỗ\nsetdie 0\n";
				result += ESC"Giết chết GM thưởng\ngmdrop\n";
			}
			send_user(me, "%c%s", ':', result +
				ESC "Lập tức Hồi sinh.\ndesc revive\n" +
				ESC "Chờ người đến cứu.\nCLOSE\n");
		}

		break;

	case "revive":

		if (!me->is_die()) return 1;
		if (get_effect(me, EFFECT_USER_DIE_5))	return 1;
		if (get_effect(me, EFFECT_USER_DIE_9))	return 1;	// 如果有其他死亡状态处理程序，则取消复活
		set_effect(me, EFFECT_USER_DIE, 1);
		break;

	case "revive$":

		if (me->is_die() != 2)	return 1;
		if (!objectp(who = me->get("pf.05114"))) return 1;
		me->set_die(0);
		set_effect(me, EFFECT_USER_DIE, 0);
		level = who->get_skill(511);
		if (level > 0)
		{
			me->set_hp(50 + (level - 13) / 20 * 100);
			me->set_mp(80 + (level - 13) / 20 * 160);
		}
		else
			me->set_hp(me->get_max_hp() / 10);

		point = me->get_cash() / 100 * 3;    //	小心溢出
		me->add_cash2(-point);  me->add_gold_log("give", point);
		me->log_money("被救活", -point);
		who->add_cash2(point);  who->add_gold_log("give2", point);
		who->log_money("救人", point);
		if (point > 0)
		{
			result = sprintf("Cứu sống %s,%d,%s,%s %s,%d,%s,%s ngân lượng 0 %d 0 %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), point, get_z(me), get_x(me), get_y(me));
			"/sys/user/cmd"->log_item(result);
		}
		write_user(me, ECHO "%s(%d) cứu sống bạn, ngân lượng %+d。", who->get_name(), who->get_number(), -point);
		write_user(who, ECHO "Bạn cứu sống %s(%d) ngân lượng %+d。", me->get_name(), me->get_number(), point);
		z = get_z(me);
		x = me->get("pf.x");
		y = me->get("pf.y");
		if (x > 0 && y > 0)
		{
			p = get_valid_xy(z, x, y, IS_CHAR_BLOCK);
			if (p > 0)
			{
				x = p / 1000;  y = p % 1000;
				me->add_to_scene(z, x, y);
			}
		}

		me->set_login_flag(2);	  // 跳转保护
		set_invisible(me, 1);
		set_effect(me, EFFECT_USER_LOGIN, 2);

		if (map = get_map_object(get_z(me)))
		{
			name = map ? map->get_name() : "无名地图";
			//CHAT_D->rumor_channel( 0, sprintf( HIM "听闻%s在%s大显神通，救活了%s。", who->get_name(), name, me->get_name() ) );
		}
		break;
	case "revive19":	//战场复生丹Hồi sinh tại chỗ
		if (!get_effect(me, EFFECT_USER_DIE_9))
			return;
		if (objectp(item = present("Phục Sinh Đơn", me, 1, MAX_CARRY)))
		{
			set_effect(me, EFFECT_USER_DIE_9, 0);
			item->revive(me, 1);
		}
		break;
	case "revive1":
		if (objectp(item = present("Phục Sinh Đơn", me, 1, MAX_CARRY)))
			item->revive(me, 1);
		break;
	case "revive11":
		if (objectp(item = present("Phục Sinh Đơn", me, 1, MAX_CARRY)))
			item->revive(me, 2);
		break;
	case "revive2":
		if (me->get_level() < 10)
		{
			set_effect(me, EFFECT_USER_DIE, 0);
			me->set_die(0);
			me->set_hp(me->get_max_hp() / 2);
			me->set_mp(me->get_max_mp() / 2);

			me->set_login_flag(2);    // 跳转保护
			set_invisible(me, 1);
			set_effect(me, EFFECT_USER_LOGIN, 2);
		}
		break;
	case "vip_revive19":	//战场vipHồi sinh tại chỗ
		if (!get_effect(me, EFFECT_USER_DIE_9))
			return;
		if (me->get_vip() && "item/sell/0061"->check_revive(me))
		{
			"item/sell/0061"->add_revive(me, 1);
			set_effect(me, EFFECT_USER_DIE_9, 0);
			me->set_die(0);
			me->set_hp(me->get_max_hp());
			me->set_mp(me->get_max_mp());

			me->set_login_flag(2);    // 跳转保护
			set_invisible(me, 1);
			set_effect(me, EFFECT_USER_LOGIN, 2);
		}
		break;
	case "vip_revive1":	//vipHồi sinh tại chỗ
		if (me->get_vip() && "item/sell/0061"->check_revive(me))
		{
			"item/sell/0061"->add_revive(me, 1);
			set_effect(me, EFFECT_USER_DIE, 0);
			me->set_die(0);
			me->set_hp(me->get_max_hp());
			me->set_mp(me->get_max_mp());

			me->set_login_flag(2);    // 跳转保护
			set_invisible(me, 1);
			set_effect(me, EFFECT_USER_LOGIN, 2);
		}
		break;
	case "vip_revive2":	//vip随机跳转点中复活
		if (me->get_vip() && "item/sell/0061"->check_revive(me))
		{
			"item/sell/0061"->add_revive(me, 1);
			set_effect(me, EFFECT_USER_DIE, 0);
			me->set_die(0);
			me->set_hp(me->get_max_hp());
			me->set_mp(me->get_max_mp());

			me->set_login_flag(2);    // 跳转保护
			set_invisible(me, 1);
			set_effect(me, EFFECT_USER_LOGIN, 2);
			z = get_z(me);
			p = get_jumpin(z, -1);
			if (p)
			{
				x = p / 1000;  y = p % 1000;
				me->add_to_scene(z, x, y, 3, 9413);
			}
		}
		break;
	case "tiger_next":
		"npc/party/gtt_active_angel"->call_out_next_stage(me);
		break;
	case "tiger_drop":
		"npc/party/gtt_active_angel"->give_up_the_activity(me);
		break;
	default:
		switch (arg)
		{
		case "1":	item = me->get_equip(HEAD_TYPE);  break;
		case "2":	item = me->get_equip(NECK_TYPE);  break;
		case "3":	item = me->get_equip(WEAPON_TYPE);  break;
		case "4":	item = me->get_equip(ARMOR_TYPE);  break;
		case "5":	item = me->get_equip(WAIST_TYPE);  break;
		case "6":	item = me->get_equip(BOOTS_TYPE);  break;
		case "7":	item = me->get_equip(HAND_TYPE);  break;
		case "8":	item = me->get_equip(FAMILY_TYPE);  break;
		case "9": item = me->get_equip(BACK_TYPE);  break;
		case "10": item = me->get_equip(FASHION_TYPE);  break;
		case "25": return USER_INVENTORY_D->send_carry_desc(me, 0);
		case "49": return USER_INVENTORY_D->send_carry_desc(me, 1);
		case "73": return USER_INVENTORY_D->send_carry_desc(me, 2);
		default:	item = present(arg, me, 0, 0);	break;
		}

		if (objectp(item))
		{
			result = ITEM_ITEM_D->get_look_string(me, item);
			if (item) {
				send_user(me, "%c%d%s", 0x31, getoid(item), result);
			}

		}

		break;
	}

	return 1;
}
