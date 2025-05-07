#include <cmd.h>
#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>
#include <time.h>
#include <city.h>
#include <npc.h>
#include <skill.h>

int ON = 1;
int OFF = 0;

int FEE_1 = 5;
int FEE_2 = 10;
int FEE_3 = 15;
int FEE_4 = 20;
int FEE_5 = 25;

int getFee(object me, int feeType, int hours) {

	int totalFee = feeType * hours;

	int currentYuanbao = "sys/sys/test_db"->get_yuanbao(me);
	if (currentYuanbao < totalFee)
	{
		notify("Số dư của bạn không đủ");
		return 0;
	}

	"sys/sys/test_db"->add_yuanbao(me, -totalFee);
	MAILBOX->sys_mail(me->get_id(), me->get_number(), sprintf("Bạn dùng %d Ngân Bảo sử dụng chức năng mở rộng", totalFee));

	return 1;
}

int main(object me, string arg)
{
	int type, numberOder;
	int fee = 0;

	if (arg) 
	{
		if (sscanf(arg, "%d %d", type, numberOder) == 2) {

			switch(type)
			{
				case 1:
				case 2:
				case 3:
					if (type == 1)
					{
						fee = getFee(me, FEE_1, numberOder);
					}

					if (type == 2)
					{
						fee = getFee(me, FEE_2, numberOder);
					}

					if (type == 3)
					{
						fee = getFee(me, FEE_3, numberOder);
					}

					if (fee == 1)
					{
						tell_user(me, sprintf(HIR"Chức năng mở rộng %d", type));

						//Hoi HP
						set_effect_2(me, EFFECT_XUESHI_HP,  1800, 2);
						me->set_save("stone_hp", 40);
						send_user( me, "%c%w%w%c", 0x81, 2, 3600 * numberOder, EFFECT_GOOD );

						//Hoi MP
						set_effect_2(me, EFFECT_FALISHI_MP,  1800, 2);
						me->set_save("stone_mp", 40);
						send_user( me, "%c%w%w%c", 0x81, 4, 3600 * numberOder, EFFECT_GOOD );
					}
					break;
				case 4:
					fee = getFee(me, FEE_4, numberOder);
					if (fee == 1)
					{
						tell_user(me,HIR"Chức năng mở rộng 4");

						//allow auto farm
						me->set_save_2("autoFarm", time() + (3600 * numberOder));
						tell_user(me,HIC"Bạn có thể sử dụng bật/tắt tự động đánh trong kỹ năng trợ giúp");

						//Hoi HP
						set_effect_2(me, EFFECT_XUESHI_HP,  1800, 2);
						me->set_save("stone_hp", 40);
						send_user( me, "%c%w%w%c", 0x81, 2, 3600 * numberOder, EFFECT_GOOD );

						//Hoi MP
						set_effect_2(me, EFFECT_FALISHI_MP,  1800, 2);
						me->set_save("stone_mp", 40);
						send_user( me, "%c%w%w%c", 0x81, 4, 3600 * numberOder, EFFECT_GOOD );
					}
					break;
				case 5:
					fee = getFee(me, FEE_5, numberOder);
					if (fee == 1)
					{
						tell_user(me, sprintf(HIR"Kích hoạt chức năng mở rộng %d", type));

						//allow auto farm
						me->set_save_2("autoFarm", time() + (3600 * numberOder));
						tell_user(me,HIC"Bạn có thể sử dụng bật/tắt tự động đánh trong kỹ năng trợ giúp");

						//Hoi HP
						set_effect_2(me, EFFECT_XUESHI_HP,  1800, 2);
						me->set_save("stone_hp", 100);
						send_user( me, "%c%w%w%c", 0x81, 2, 3600 * numberOder, EFFECT_GOOD );

						//Hoi MP
						set_effect_2(me, EFFECT_FALISHI_MP,  1800, 2);
						me->set_save("stone_mp", 100);
						send_user( me, "%c%w%w%c", 0x81, 4, 3600 * numberOder, EFFECT_GOOD );
					}
					break;
			}
		}
	}
	return 1;
}