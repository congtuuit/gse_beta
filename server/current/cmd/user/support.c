#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>
#include <time.h>

#define PF_NAME        "Trợ giúp trò chơi"
#define TITLE        "sys/sys/title"

int showUniformFamily(object me) {
	int family;
	string name;
	name = me->get_fam_name();

	switch (name)
	{
	case "Đào Hoa Nguyên":
		family = 2;
		break;
	case "Cấm Vệ Quân":
		family = 4;
		break;
	case "Thục Sơn":
		family = 3;
		break;
	case "Đường Môn":
		family = 5;
		break;
	case "Côn Luân":
		family = 6;
		break;
	case "Mao Sơn":
		family = 8;
		break;
	case "Vân Mộng Cốc":
		family = 7;
		break;
	}

	return family;
}

void hide_uniform(object me) {

	int gender, p, i, z;
	object* objs, target;
	int currentFashion;

	gender = me->get_gender();
	currentFashion = me->get_save_2("marry_fashion.code");

	if (me->get_save_2("fashion.backup") == 0) {
		if (currentFashion != showUniformFamily(me)) {
			me->set_save_2("fashion.backup", showUniformFamily(me));
		}
		else {
			me->set_save_2("fashion.backup", currentFashion);
		}
	}
	else {
		if (currentFashion != showUniformFamily(me) && me->get_save_2("fashion.backup") != showUniformFamily(me)) {
			me->set_save_2("fashion.backup", showUniformFamily(me));
		}
	}

	if (me->get_save_2("fashion.backup") != currentFashion) {

		me->set_save_2("marry_fashion.code", me->get_save_2("fashion.backup"));
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));

		me->set_save_2("fashion.backup", currentFashion);
		send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 42431, 1, OVER_BODY, PF_ONCE);
	}
}

void hide_support_skills(object me, int type) {
	int hide, p, i, z;
	object* objs, target;
	string strText;

	//hide = me->get_save_2("hideSkill");

	switch (type)
	{
	case 1:
		me->set_save_2("hideSkill", 0);
		strText = sprintf(HIC"Hiện"NOR);
		break;
	default:
		me->set_save_2("hideSkill", 1);
		strText = sprintf(HIC"Ẩn"NOR);
		break;
	}

	send_user(me, "%c%s", ';', sprintf("Đã %s Kỹ Năng Trợ Giúp. Vui lòng đăng nhập lại.", strText));
}

void open_stored(object me) {
	object target;
	object* objs;
	int size, i;

	objs = children("/npc/base/1001");
	size = sizeof(objs);

	for (i = 0; i < size; i++)
	{
		if (objectp(objs[i]) )
		{
			target = objs[i];
			break;
		}
	}

	if (target) {
		me->set("pawn_time", time());
		"/cmd/std/pawn"->do_list(me, sprintf("%x#", getoid(target)), 1);
	}
}

void menu(object me, int key) {

	string result, *titles;
	int flag = 0, i;

	result = sprintf(PF_NAME + ":\nVui lòng chọn tính năng cần hỗ trợ!\n");
	switch (key)
	{
	case 1:
		result += sprintf(ESC "Ẩn tóc/nón\ntoc an\n");
		result += sprintf(ESC "Hiện tóc/nón\ntoc hien\n");
		result += sprintf(ESC "Ẩn / Hiện ngoại trang\nsupport ? 12\n");
		flag = 1;
		break;
	case 12:
		hide_uniform(me);
		break;
	case 2:
		result += sprintf(ESC "Bật\neback on\n");
		result += sprintf(ESC "Tắt\neback off\n");
		flag = 1;
		break;
	case 3:
		result += sprintf(ESC "Hiện kỹ năng bổ trợ\nsupport ? 31\n");
		result += sprintf(ESC "Ẩn kỹ năng bổ trợ\nsupport ? 32\n");
		flag = 1;
		break;
	case 31:
		hide_support_skills(me, 1);
		break;
	case 32:
		hide_support_skills(me, 0);
		break;
	case 4:
		if (me->get_cash() < 10000) {
			tell_user(me, ECHO"Ngươi không đủ 10.000 lượng để sử dụng tính năng này.");
		}
		else {
			tell_user(me, ECHO"Bạn bị trừ 10.000 lượng khi sử dụng kho từ xa.");
			me->add_cash(-10000);
			open_stored(me);
		}
		
		break;

	case 5:
		titles = me->get_array_title();
		for (i = 0; i < sizeof(titles); i++) {
			result += sprintf(ESC "%s\nsupport %s %s\n", TITLE->get_titlename(titles[i]), "!", titles[i]);
		}

		flag = 1;
		break;
	default:
		tell_user(me, ECHO"Không hỗ trợ tính năng này!");
		flag = 1;
		break;
	}

	result += sprintf(ESC "Đóng.\nCLOSE\n");
	if (flag == 1) {
		send_user(me, "%c%c%w%s", ':', 3, 0, result);
	}

}

void showTitle(object me, string titleCode) {
	me->set_save("my_title", titleCode);
	me->show_title(titleCode);
}

int main(object me, string arg)
{
	int key;
	string titleKey = "!", titleCode;
	if (sscanf(arg, "? %d", key) == 1) {
		menu(me, key);
	}
	else if (sscanf(arg, "%s %s", titleKey, titleCode) == 2) {
		if (titleKey == "!")
			showTitle(me, titleCode);
	} else {
	}

	return 1;
}