
#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <cmd.h>
#include <ansi.h>

inherit OFFICER;

// 函数：师父识别
int is_master() { return 1; }

// 函数：获取门派名称
string get_fam_name() { return "Đào Hoa Nguyên"; }

// 函数：获取升级顺序
int get_fam_order() { return 3; }

// 函数：获取人物造型
int get_char_picid() { return 5601; }

// 函数：小贩识别
int is_seller() { return 1; }

// 有自己的do_look函数
int is_self_look() { return 1; }

int get_level() { return 90; }

void do_skill();
void do_quest();
void do_giveup();
void do_giveup2();
void do_apprentice(string arg);
void accept_quest();
void task_info();

// 函数：构造处理
void create()
{
        set_name( "Vô Tư" );
        
        set_skill(0211, 90);
        set_skill(0371, 90);
        set_skill(0212, 90);
        set_skill(0372, 90);
        set_skill(0316, 90);
        set_skill(0373, 90);
        set_skill(0317, 90);
        set_skill(0374, 90);
        set_skill(0319, 90);
        set_skill(0375, 90);
        set_2( "talk", ([
                "skills"                : (: do_skill :),
                "quest"                 : (: do_quest :),
                "giveup"                : (: do_giveup :),
                "giveup2"               : (: do_giveup2 :),
                "apprentice"            : (: do_apprentice :), 
                "accept_quest"            : (: accept_quest :),   
                "task_info"             : (: task_info :),                     
        ]));
        set_2( "good", ([
        	"01" : "/item/70/0010",
        	"02" : "/item/70/1020",                
        	"03" : "/item/60/0010",
        	"04" : "/item/60/1020",
        	"05" : "/item/61/0010",
        	"06" : "/item/61/1020",
        	"07" : "/item/65/0010",
        	"08" : "/item/65/1020",
        	"09" : "/item/66/0010",
        	"10" : "/item/66/1020",                
        	"11" : "/item/88/0010",
        	"12" : "/item/88/1020",
        	"13" : "/item/87/1010",
        	"14" : "/item/87/1020",              
        ]) );   
        setup();
}

// 函数：点击出现界面
void do_look( object who ) { TASK_MASTER_D->do_look( who, this_object() ); }

// 函数：技能学习界面
void do_skill(  ) { LEARN_CMD->learn_menu( this_player(), this_object() ); }

// 函数：Nhận nhiệm vụ
void do_quest(  ) { TASK_MASTER_D->do_quest( this_player(), this_object() ); }

// 函数：取消任务
void do_giveup(  ) { TASK_MASTER_D->do_giveup( this_player(), this_object() ); }

// 函数：取消任务2
void do_giveup2(  ) { TASK_MASTER_D->do_giveup2( this_player(), this_object() ); }

// 函数：拜师
void do_apprentice( string arg  ) { TASK_APPRENTICE_D->do_apprentice( this_player(), this_object(), arg ); }
//Nhận nhiệm vụ
void accept_quest(  ) { TASK_MASTER_D->accept_quest( this_player(), this_object() ); }
//任务信息
void task_info(  ) { TASK_MASTER_D->task_info( this_player(), this_object() ); }

// 接收心爱物品
int accept_object( object player, object obj ) 
{
	object who = this_object();
	return TASK_MASTER_D->accept_object( who, player, obj ); 
}

// 函数：删除师门技能
void delete_family_skill( object who )
{
        mapping skls;
        object file;
        string *name, result;
        int skill, level, i, size;

        skls = get_skill_dbase();
        name = keys(skls);
        size = sizeof(name);
        result = sprintf( "您决定脱离“%s”门下！损失：", get_fam_name() );
        for( i = 0; i < size; i ++ )
        {
                skill = to_int( name[i] );
                if( level = who->get_skill(skill) )
                {
                        if( file = load_object( SKILL->get_skill_file(skill) ) ) 
                                result = sprintf("%s%s(%d) ", result, file->get_name(), level);
                        else    result = sprintf("%s%s(%d) ", result, name[i], level);
                }
                who->delete_skill(skill);
        }

        who->log_legend(result);
}
