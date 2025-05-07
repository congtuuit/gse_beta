
#include <effect.h>

private static object Enemy;            // 攻击对象：传统的做法，就是通常讲的对手
private static object Enemy3;           // 攻击对象：用于物理攻击(普通、特殊技)记录向谁攻击，之后取回，显示攻击结果

private static object Manager;          // 本帮总管：用于帮派战争

private static string ForceCmd;         // 预执行命令
private static string Perform;          // 特殊技文件
private static string Perform2;         // 特殊技文件(循环)
private static string Cast;             // 特殊技文件(远程)
private static string CastArg;          // 特殊技参数
private static string Progress;          // 带进度条的文件
private static string ProgressArg;       // 带进度条的参数

private static mapping mpLoop = ([ ]);          // 特殊技数据集(持续)
private mapping mpPerform = ([ ]);       // 特殊技数据集

private static int *LoopPf = ({ });             // 持续效果数组    // [法术效果][法术速度][遮挡]

private static mapping mpEnmity = ([ ]); 	//仇恨集合

private static int Enmity;			//是否开发仇恨Thiết lập 
// -------------------------------------------------------------

// 函数：获取攻击对象
object get_enemy() { return Enemy; }

// 函数：Thiết lập 攻击对象
object set_enemy( object who ) { return Enemy = who; }

// 函数：获取攻击对象
object get_enemy_3() { return Enemy3; }

// 函数：Thiết lập 攻击对象
object set_enemy_3( object who ) { return Enemy3 = who; }

// 函数：获取本帮总管
object get_manager() { return Manager; }

// 函数：Thiết lập 本帮总管
object set_manager( object who ) { return Manager = who; }

// 函数：获取预执行命令
string get_force_command() { return ForceCmd; }

// 函数：Thiết lập 预执行命令
string set_force_command( string cmd ) { return ForceCmd = cmd; }

// 函数：获取特殊技文件
string get_perform_file() { return Perform; }

// 函数：Thiết lập 特殊技文件
string set_perform_file( string file ) { return Perform = file; }

// 函数：获取特殊技文件(循环)
string get_perform_2_file() { return Perform2; }

// 函数：Thiết lập 特殊技文件(循环)
string set_perform_2_file( string file ) { return Perform2 = file; }

// 函数：获取特殊技文件(远程)
string get_cast_file() { return Cast; }

// 函数：Thiết lập 特殊技文件(远程)
string set_cast_file( string file ) { return Cast = file; }

// 函数：获取特殊技参数
string get_cast_arg() { return CastArg; }

// 函数：Thiết lập 特殊技参数
string set_cast_arg( string arg ) { return CastArg = arg; }

// 函数：获取进度条相关文件
string get_progress_file() { return Progress; }

// 函数：Thiết lập 进度条相关文件
string set_progress_file( string file ) { return Progress = file; }

// 函数：获取进度条相关参数
string get_progress_arg() { return ProgressArg; }

// 函数：Thiết lập 进度条相关参数
string set_progress_arg( string arg ) { return ProgressArg = arg; }
// -------------------------------------------------------------

// 函数：是否有持续特殊技
int get_loop_size() { return sizeof(mpLoop); }

// 函数：获取特殊技数据集(持续)
mapping get_loop_dbase() { return copy(mpLoop); }

// 函数：初始特殊技数据集(持续)
void init_loop_dbase() { mpLoop = ([ ]); }

// 函数：获取特殊技数据集
mapping get_perform_dbase() { return copy(mpPerform); }

// 函数：初始特殊技数据集
void init_perform_dbase() { mpPerform = ([ ]); }

// -------------------------------------------------------------

// 函数：获取特殊技内容(持续)
mixed get_loop( string key ) { return mpLoop[key]; }

// 函数：Thiết lập 特殊技内容(持续)
mixed set_loop( string key, mixed value ) { return mpLoop[key] = value; }

// 函数：添加特殊技内容(持续)
mixed add_loop( string key, mixed value )
{
        mixed old;

        if( !( old = get_loop(key) ) ) 
                return set_loop(key, value);
        else    return set_loop(key, old + value);
}

// 函数：删除特殊技内容(持续)
void delete_loop( string key ) { map_delete(mpLoop, key); }

// -------------------------------------------------------------

// 函数：获取特殊技内容
mixed get_perform( string key ) 
{ 
	if (mpPerform==0) mpPerform = ([]);
	return mpPerform[key]; 
}

// 函数：Thiết lập 特殊技内容
mixed set_perform( string key, mixed value ) 
{ 
	if (mpPerform==0) mpPerform = ([]);
	return mpPerform[key] = value; 
}	

// 函数：添加特殊技内容
mixed add_perform( string key, mixed value )
{
        mixed old;
	if (mpPerform==0) mpPerform = ([]);
        if( !( old = get_perform(key) ) ) 
                return set_perform(key, value);
        else    return set_perform(key, old + value);
}

// 函数：删除特殊技内容
void delete_perform( string key ) 
{ 
	if (mpPerform==0) mpPerform = ([]);
	map_delete(mpPerform, key); 
}

// -------------------------------------------------------------

// 函数：持续效果数组
int *get_loop_pf() { return copy(LoopPf); }

// 函数：持续效果数组
int *set_loop_pf( int *pf ) { return LoopPf = pf; }

// -------------------------------------------------------------

// 函数：开始战斗
void start_fight( object who )
{
        object me = this_object();
        object soldier, *zombie, owner1, owner2, map;
        int i, size;

        if( !who || who == me || Enemy == who ) return;

        if( !inside_screen_2(me, who) ) return;
        if( !who->can_be_fighted(me) || !me->can_fight(who) ) return;    // 能打才设标志，会影响召唤兽

        Enemy = who;
        set_heart_count(me, 1);    // 重设心跳标志(主), 0.? 秒进入心跳(马上启动心跳)
        set_heart_beat(1);
        owner1 = me, owner2 = who;
        if (owner1->get_owner()) owner1 = owner1->get_owner();
        if (owner2->get_owner()) owner2 = owner2->get_owner();
        map = get_map_object(get_z(me));

		if (map && map->get_client_id()!=885 && map->get_client_id() != 893 && !map->is_virtual_scene() && !MAP_D->is_inside_battle( get_z(me) )  && owner1->is_user() && owner2->is_user())
        {
        	owner1->set_attack_mode(me->get_attack_mode());
		    owner1->set_pk(owner1->get_pk());

        	owner2->set_attack_mode(owner2->get_attack_mode());
		    owner2->set_pk(owner2->get_pk());
        }

        set_heart_idle(me, 0);    // 清除空闲心跳
        if (who->get_action_mode()==1 && who->is_npc() && who->get_enemy()==0)
        	who->start_fight(me);        
}

// 函数：停止战斗
void stop_fight()
{
        object owner;

        if(     objectp( owner = this_object()->get_owner() )    // 停止主人攻击
        &&      owner->get_enemy() == Enemy )
                owner->set_enemy(0);

        Enemy = 0;
}
//仇恨值的函数：
mapping get_all_enmity() { return mpEnmity; }
mapping set_all_enmity(mapping mpTmp) 
{ 
	if ( !mapp(mpTmp) )
		mpTmp = ([]);
	return mpEnmity=mpTmp; 
}
int get_enmity(string id) { return mpEnmity[id]; }
int set_enmity(string id, int i) { return mpEnmity[id]=i; }
//Thiết lập 仇恨开放标志
int set_enmity_flag(int i) { return Enmity=i; }		

int get_enmity_flag() { return Enmity; }
