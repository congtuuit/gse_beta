#include <ansi.h>
#include <item.h>
#include <skill.h>
#include <public.h>

inherit ITEM;

#define _SKILL 74225
int get_item_value() { return 180; }
int get_item_value_2() { return 180; }

int get_type() {

	if (_SKILL >= 74201) {
		return 2;
	}
	else {
		return 1;
	}

}

int get_item_color()
{
	int skill, i;

	skill = to_int(get("special"));
	i = skill / 100 % 10;
	return i;
}
int get_item_type() { return ITEM_TYPE_SPECIAL; }
int is_pet_item() { return 1; }
void create()
{
	set_name("Tinh Nguyên Đơn");
	set_picid_1(9980);
	set_picid_2(9980);
	set_value(10000);
	"quest/pet"->init_item_skill(this_object(), get_type());
	if (get_type() == 1) {
		"quest/pet"->get_drop_skill1();
	}
	else {
		"quest/pet"->get_drop_skill2();
	}

	this_object()->set("special", sprintf("%d", to_int(_SKILL)));
}
string get_desc()
{
	int skill;
	object oSki;
	string desc;

	skill = to_int(get("special"));
	if (skill == 74101)			//修复BUG
	{
		"quest/pet"->init_item_skill(this_object(), 2);
		skill = to_int(get("special"));
	}
	if (!skill || !(oSki = load_object(SKILL->get_perform_file(skill))))
		return "";
	desc = "quest/pet"->get_skill_desc(skill);
	if (!desc)
		return sprintf("Kỹ năng bao hàm: %s \n", oSki->get_name());
	return sprintf("Kỹ năng bao hàm: %s \n %s ", oSki->get_name(), desc);
}
string get_special_desc(string cSpecial)
{
	int skill;
	object oSki;
	string desc;

	skill = to_int(cSpecial);
	if (!skill || !(oSki = load_object(SKILL->get_perform_file(skill))))
		return "";
	desc = "quest/pet"->get_skill_desc(skill);
	if (!desc)
		return sprintf("Kỹ năng bao hàm: %s \n", oSki->get_name());
	return sprintf("Kỹ năng bao hàm: %s \n %s ", oSki->get_name(), desc);
}
