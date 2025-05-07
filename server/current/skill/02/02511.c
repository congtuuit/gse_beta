
// 物理技能  TIPS:[PF_HIT]

#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0251
#define THIS_PERFORM    02511
#define PF_START       "02511"
#define PF_NAME        "蛟龙入海"

#define SKILL_LEVEL     10
#define TIME_INTERVAL   0
#define SUB_MP          me->get_pf_value(THIS_SKILL, SKILL_LEVEL_SQUARE, 3, 1300)    // 警告：me 得准备好
#define SUB_YUAN        0
#define ADD_AP          me->get_pf_value_2(THIS_SKILL, SKILL_LEVEL_SQUARE, 36, 80)    // 警告：me 得准备好

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

// 函数：获取法力
int get_sub_mp( object me ) 
{ 
        int level = me->get_skill(THIS_SKILL);
        return SUB_MP; 
}

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        return sprintf( "［" PF_NAME "］单体近身攻击，提升 %d 点攻击力。消耗法力：%d，消耗元气：%d，再次使用需间隔 %d 秒，%s%d 级可用\n",
                ADD_AP, SUB_MP, SUB_YUAN, TIME_INTERVAL, level < SKILL_LEVEL ? HIR : "", SKILL_LEVEL );
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // 小心准备 me

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "Sử dụng “ %s ”cần %d điểm Pháp Lực.", PF_NAME, mp );
                return 1;
        }

        if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "Sử dụng “ %s ”cần %d điểm Nguyên khí.", PF_NAME, SUB_YUAN );
                return 1;
        }

        if( me->get_weapon_code() != STICK ) 
        {
                printf( ECHO "使用“" PF_NAME "”得装备棍。" );
                return 1;
        }

        me->set_perform_enable_time( time() );
        USER_SKILL_D->cancel_enabled_perform( me, __FILE__ );
        me->set_perform_file(__FILE__);
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_LOOP );

        write_user(me, ECHO "您的“" PF_NAME "”已经准备好了。");

        return 1;
}

// 函数：特殊技处理(动作)
int perform_action( object me, object who )
{
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // 小心准备 me

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "Sử dụng “ %s ”cần %d điểm Pháp Lực.", PF_NAME, mp );
                return 1;
        }

        if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "Sử dụng “ %s ”cần %d điểm Nguyên khí.", PF_NAME, SUB_YUAN );
                return 1;
        }

        if( me->get_weapon_code() != STICK ) 
        {
                printf( ECHO "使用“" PF_NAME "”得装备棍。" );
                return 1;
        }

        if( !CHAR_FIGHT_D->attack_action(me, who, 31) ) return 1;

        me->add_mp(-mp);
        me->add_yuan( -SUB_YUAN );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        return 2;    // 执行成功
}

// 函数：特殊技处理
int perform_done( object me, object who )
{
        int level, mp;        

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

//      if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // 小心准备 me

/*      if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "Sử dụng “ %s ”cần %d điểm Pháp Lực.", PF_NAME, mp );
                return 1;
        }       */

/*      if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "Sử dụng “ %s ”cần %d điểm Nguyên khí.", PF_NAME, SUB_YUAN );
                return 1;
        }       */

        if( me->get_weapon_code() != STICK ) 
        {
                printf( ECHO "使用“" PF_NAME "”得装备棍。" );
                return 1;
        }

        me->set_perform_file(0);
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP );    // 删除聚气

        CHAR_FIGHT_D->attack_done(me, who, HIT_STICK, ADD_AP);    // 小心准备 me

        return 2;    // 执行成功
}

// 函数：获取特技类型
int get_perform_type() { return ON_ME; }

// 函数：能否使用特技
void can_perform( object me )
{
        int level, interval, interval2;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) 
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
                return;
        }

        interval = TIME_INTERVAL;    // 小心准备 me
        interval2 = interval - gone_time( me->get_perform(PF_START) );
        if( interval2 < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), interval, 0, PF_NAME );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), interval, interval2, PF_NAME );
}
