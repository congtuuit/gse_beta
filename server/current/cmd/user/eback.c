
#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>

int main(object me, string arg)
{
	switch (arg)
	{
		case "off":
			me->set_save_2("back_item_effect", 0);
			tell_user(me, ECHO"Đã ẩn hiệu ứng");

			/*CHAR_CHAR_D->init_loop_perform(me);
			send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 4176, 1, OVER_BODY, PF_STOP);*/
			CHAR_CHAR_D->init_loop_perform(me);
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
			break;
		case "on":
			me->set_save_2("back_item_effect", 1);
			tell_user(me, ECHO"Hiệu ứng vật phẩm đeo được bật");
			CHAR_CHAR_D->init_loop_perform(me);
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));

			break;
		default:
			break;
	}

	return 1;
}