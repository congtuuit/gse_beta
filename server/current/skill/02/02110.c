
// 物理技能  TIPS:[PF_HIT]

#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0211
#define THIS_PERFORM    02110
#define PF_START       "02110"
#define PF_NAME        "Hắc hổ đào tâm"

#define SKILL_LEVEL     1
#define TIME_INTERVAL   1
#define SUB_MP          0
#define SUB_YUAN        2
#define ADD_AP          20 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10*8
#define ADD_ENMITY	240 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10*80 + ret

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

// 函数:获取法力
int get_sub_mp( object me ) { return SUB_MP; }

// 函数:获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\nCông kích cận chiến.\n    Quyền pháp tấn công căn bản, tăng thêm điểm ngoại công khi tấn công mục tiêu. Tăng thêm 1% sát thương theo lượng máu bản thân";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC" %s (Cấp %d )\n " NOR "Võ công yêu cầu: Cấp %d \n Nguyên khí tiêu hao: %d điểm\n Tái sử dụng sau: %d giây\n    Quyền pháp tấn công căn bản, tăng thêm %d điểm ngoại công khi tấn công mục tiêu.\n " HIC"Cấp tiếp theo:\n "NOR"Võ công yêu cầu: "HIR"Cấp %d \n" NOR "    Quyền pháp tấn công căn bản, tăng thêm %d điểm ngoại công khi tấn công mục tiêu.", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_YUAN, TIME_INTERVAL, ADD_AP, cur_level*10+SKILL_LEVEL, ADD_AP + 8);
        return result;
}

// 函数:命令处理
int main( object me, object who, int x, int y, string arg )
{
        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;

        if( me->get_mp() < SUB_MP )
        {
                printf( ECHO "Sử dụng \" %s \"cần %d điểm Pháp Lực.", PF_NAME, SUB_MP );
                return 1;
        }
        if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "Sử dụng \" %s \"cần %d điểm Nguyên khí.", PF_NAME, SUB_YUAN);
                return 1;
        }        
        if( me->get_weapon_code() != UNARMED ) 
        {
                printf( ECHO "Sử dụng \"" PF_NAME "\" phải trang bị triển thủ" );
                return 1;
        }
	if( !CHAR_FIGHT_D->attack_action(me, who, 19) ) return 1;
	me->add_yuan( -SUB_YUAN );
	set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
        me->add_2("go_count.count2", 5);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%s", who->get_char_id() ) );
	    send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_LOOP );

        return 1;
}

// 函数:特殊技处理(动作)
int perform_action( object me, object who )
{
        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;

        if( me->get_mp() < SUB_MP ) 
        {
                printf( ECHO "Sử dụng \" %s \"cần %d điểm Pháp Lực.", PF_NAME, SUB_MP );
                return 1;
        }
        if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "Sử dụng \" %s \"cần %d điểm Nguyên khí.", PF_NAME, SUB_YUAN);
                return 1;
        }
        if( me->get_weapon_code() != UNARMED ) 
        {
                printf( ECHO "Sử dụng \"" PF_NAME "\" phải trang bị triển thủ" );
                return 1;
        }

        if( !CHAR_FIGHT_D->attack_action(me, who, 19) ) return 1;        

        me->add_mp( -SUB_MP );
	me->add_yuan( -SUB_YUAN );
	me->set_perform( PF_START, time() );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        return 2;    // 执行成功
}


int perform_action_npc(object me, object who)
{
    int addAP;

    if (!CHAR_FIGHT_D->attack_action(me, who, 19)) return 0;

    set_heart_state(me, FIGHT_STAT);
    set_heart_count_2(me, 7);
    me->set_perform_file(__FILE__);

    CHAR_FIGHT_D->attack_done(me, who, HIT_UNARMED, ADD_AP);

    send_user(me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0);

    return 1;
}

// 函数:特殊技处理
int perform_done( object me, object who )
{
        int level, ret, addAP;        

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

//      if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;

/*      if( me->get_mp() < SUB_MP ) 
        {
                printf( ECHO "Sử dụng \" %s \"cần %d điểm Pháp Lực.", PF_NAME, SUB_MP );
                return 1;
        }       */

        if( me->get_weapon_code() != UNARMED ) 
        {
                printf( ECHO "Sử dụng \"" PF_NAME "\" phải trang bị triển thủ" );
                return 1;
        }

        me->set_perform_file(0);
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP );    // 删除聚气

        addAP = me->get_hp() /100;
        addAP = addAP + ADD_AP;

        ret = CHAR_FIGHT_D->attack_done(me, who, HIT_UNARMED, addAP);    // 小心准备 me
        
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,ADD_ENMITY);        

        return 2;    // 执行成功
}


// 函数:特殊技处理
int cast_done( object me )
{
        int level, ret, addAP;
        object who;
        string arg;   
	if( !stringp( arg = me->get_cast_arg() ) ) return 1;
	if( !objectp( who = find_char(arg) ) ) return 1;
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP );    // 删除聚气

        addAP = me->get_hp() / 100;
        addAP = addAP + ADD_AP;
        ret = CHAR_FIGHT_D->attack_done(me, who, HIT_UNARMED, addAP);    // 小心准备 me
        
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,ADD_ENMITY);        

        return 2;    // 执行成功
}

// 函数:获取特技类型
int get_perform_type() { return ON_CHAR; }

// 函数:能否使用特技
void can_perform( object me )
{
        int interval;
        string name;

        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) 
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
                return;
        }
	name = sprintf(" %s (Cấp %d )", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/10+1);
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
        send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, SUB_YUAN, 1, 1, 9, 5, 0);
}
