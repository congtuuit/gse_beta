#include <item.h>
#include <effect.h>
#include <skill.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>
#include <music.h>

inherit ITEM;
inherit USABLE;
inherit COMBINED;

#define CONFIG_THUCUOI      "custom/player/thucuoiexp"

#define ITEM_USE_TYPE 	"add_hp"
#define ITEM_USE_TIME	300

int get_item_value() { return 200; }
int get_item_value_2() { return 200; }

int get_item_number() { return 999; }
int get_item_type_2() { return ITEM_TYPE_2_ADD_HP; }

// 函数：获取装备颜色：灰色
int get_item_color() { return 2; }

//lv2
int Hoa_Dai_Hung = 29;
int Hoa_Ho_Ly = 27;
int Than_Voi_Dia = 31;
int Thuy_Long_Quy = 33;
int Tuan_Loc_Do = 38;

//lv1
int Dai_Hung = 28;
int Ho_Ly = 26;
int Than_Voi = 30;
int Long_Quy = 32;
int Tuan_Loc = 39;

void create()
{
    set_name("Hỏa Thạch");
    set_picid_1(4051);
    set_picid_2(4051);
    set_value(1);
    set_amount(1);
}

// 函数：获取描述
string get_desc()
{
	return "Hỏa thạch chứa đựng năng lượng rất lớn. Là loại thức ăn yêu thích của Thần Thú\nKinh nghiệm luyện hóa: +2 \n (Tái sử dụng sau 300 giây)";
}

// 函数：使用效果
int get_use_effect(object me) { return __FILE__->get_use_effect_callout(me, this_object()); }

// 函数：使用效果(在线更新)
int get_use_effect_callout(object me, object item)
{
	int type;
	object who, npc;
	int i, size, x, y, z, p, thucuoi, exp, maxexp;
	int exitsItem;

	if (get_item_type_2() == ITEM_TYPE_2_ADD_HP) type = EFFECT_USE_ITEM_1;

	if (!me->get_ride())
	{
		notify("Hãy cưỡi Thần Thú trước khi luyện hóa");
		return 0;
	}
	else {

		exitsItem = TASK_LEGEND_D->check_task_item_amount(me, item->get_name());

		if (exitsItem <= 0) {
			notify("Không tìm thấy Hỏa Thạch.");
			return 0;
		}

		if (get_effect(me, type))
		{
			send_user(me, "%c%s", '!', sprintf("Thời gian đóng băng của vật phẩm còn %d giây", get_effect(me, type)));
			return 0;
		}

		thucuoi = me->get_ride();

		//check than thu

		if (thucuoi == Hoa_Ho_Ly 
			|| thucuoi == Hoa_Dai_Hung
			|| thucuoi == Than_Voi_Dia
			|| thucuoi == Thuy_Long_Quy
			|| thucuoi == Tuan_Loc_Do
			|| thucuoi == Dai_Hung
			|| thucuoi == Ho_Ly
			|| thucuoi == Than_Voi
			|| thucuoi == Long_Quy
			|| thucuoi == Tuan_Loc)
		{
			if (me->get_save(sprintf("thucuoi.%d.level", thucuoi)) == 3) {
				notify("Ngươi đã luyện hóa loại thú cưỡi này đạt cấp độ tối đa rồi.");
			}

			if (me->get_save(sprintf("thucuoi.%d.level", thucuoi)) > 0) {
				exp = me->get_save(sprintf("thucuoi.%d.exp", thucuoi));
				maxexp = me->get_save(sprintf("thucuoi.%d.maxexp", thucuoi));
				if ((exp + 2) <= maxexp) {
					set_effect(me, type, ITEM_USE_TIME);
					send_user(me, "%c%c%c%w", 0x30, get_item_type_2(), 0, ITEM_USE_TIME);

					me->add_save(sprintf("thucuoi.%d.exp", thucuoi), 2);
					
					TASK_LEGEND_D->check_task_item1(me, item->get_name(), 1);
					send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9154, 1, OVER_BODY, PF_ONCE);
				}
				else {
					notify("Mức độ luyện hóa đã đạt mức tối đa, bạn hãy đến NPC để nâng cấp.");
				}
			}
			else {
				set_effect(me, type, ITEM_USE_TIME);
				send_user(me, "%c%c%c%w", 0x30, get_item_type_2(), 0, ITEM_USE_TIME);

				if (thucuoi == Hoa_Ho_Ly
					|| thucuoi == Hoa_Dai_Hung
					|| thucuoi == Than_Voi_Dia
					|| thucuoi == Thuy_Long_Quy
					|| thucuoi == Tuan_Loc_Do) 
				{
					me->set_save(sprintf("thucuoi.%d.level", thucuoi), CONFIG_THUCUOI->get_level_2());
					me->set_save(sprintf("thucuoi.%d.exp", thucuoi), 2);
					me->set_save(sprintf("thucuoi.%d.maxexp", thucuoi), CONFIG_THUCUOI->get_expmax2());
				}
				else {
					me->set_save(sprintf("thucuoi.%d.level", thucuoi), CONFIG_THUCUOI->get_level_1());
					me->set_save(sprintf("thucuoi.%d.exp", thucuoi), 2);
					me->set_save(sprintf("thucuoi.%d.maxexp", thucuoi), CONFIG_THUCUOI->get_expmax());
				}

				TASK_LEGEND_D->check_task_item1(me, item->get_name(), 1);
				send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9154, 1, OVER_BODY, PF_ONCE);
			}

			tell_user(me, sprintf("Mức độ luyện hóa Thần Thú đạt: %d / %d", me->get_save(sprintf("thucuoi.%d.exp", thucuoi)), me->get_save(sprintf("thucuoi.%d.maxexp", thucuoi))));
		}
		else {
			notify("Không thể sử dụng Hỏa Thạch cho thú cưỡi này.");
		}
	}

	return 0;
}

