#include <npc.h>
#include <cmd.h>
#include <time.h>
#include <ansi.h>

#define FILE_SAVE "data/quantrang"SAVE_EXTENSION
#define DEBUG(arg) ;

inherit DBASE_F;
inherit SAVE_F;

static string *SchoolName = ({"Đào Hoa Nguyên","Cấm Vệ Quân","Thục Sơn","Côn Luân","Mao Sơn","Vân Mộng Cốc","Đường Môn",});
mapping Point_players;
mapping Enable_id=([]);

int xy_get_fam_id(string name);
void delete_mingren_title(object who,string titlecode);
int get_sum_skills_level(object who);
int get_mingren_power(object who);
void send_mingren_data(object who,mapping players,string type);

// 函数：生成二进制码
void SAVE_BINARY() { }

//排行数据保存
string get_save_file()	{ return FILE_SAVE; }

//初始化对象
void create()
{
	restore();
}
//对话处理
void do_look(object who)
{
	int i,size,level,point,xy_family;
	string name,family;
	if(!mapp(Point_players))
	{
		return;
	}
	send_user(who,"%c%c",0xA9,0);
	send_mingren_data(who, Point_players,"point"); //发送财富表
	
}


void do_look2(object who)
{
	int i,size,level,point,xy_family;
	string name,family;
	if(!mapp(Point_players))
	{
		return;
	}
	send_user(who,"%c%c",0xA9,0);
	send_mingren_data(who, Point_players,"point");
}

void check_time()
{
	int i,size;
	object *user;
	mixed mixtime;
	
	mixtime=localtime(get_party_time());
	if(!arrayp(user=USER_D->get_user())) return;
	size=sizeof(user);
	for(i=0;i<size;i++)
	{	
		__FILE__->check_mingren_downline(user[i]);
	}
	__FILE__->create_mingren_board();	
}

void create_mingren_board()
{
	int i ,j,size1,size2,id;
	mapping expTmp,cashTmp,teacherTmp,gongdeTmp,diziTmp;
	string *key,*xy_delete_id=({});
	string *titlecode=({"A020","A021","A022","A023"});
	object who;
	
	xy_delete_id=keys(Enable_id);
	size1=sizeof(xy_delete_id);
	size2=sizeof(titlecode);
	
	Enable_id=([]);		
	save();
}


//检查更新名人堂
void check_mingren_downline(object who)
{
	__FILE__->sort_board(who,"point_player","point");
}

int xy_get_fam_id(string name)
{
	switch(name)
	{
		case "Vô Môn Phái" :
			return 0;
			break;
		case "Đào Hoa Nguyên" :
			return 1;
			break;
		case "Thục Sơn" :
			return 2;
			break;	
		case "Cấm Vệ Quân" :
			return 3;
			break;
		case "Đường Môn" :
			return 4;
			break;
		case "Mao Sơn" :
			return 5;
			break;
		case "Côn Luân" :
			return 6;
			break;
		case "Vân Mộng Cốc" :
			return 7;
			break;
	}
}


void sort_board(object who,string type,string power_name)
{
	int i ,size,id,id1,id2,pos,tmp_pos;
	mapping power=([]);
	
	id=who->get_number();
	power["point"] = who->get_save_2("quantrang.core");
	if(get_save_2(sprintf("%s.%d",type,id)))
	{
		if(get_save_2(sprintf("%s.%d.%s",type,id,power_name))!=power[power_name])
		{
			set_save_2(sprintf("%s.%d.%s",type,id,power_name),power[power_name]);
			pos=get_save_2(sprintf("%s.%d.pos",type,id)); //当前玩家第pos名
		}
	}
	else if( (size=get_save_2(sprintf("%s.size",type)))<10)
	{
		
		pos=size+1;
		set_save_2(sprintf("%s.pos.%d",type,pos),id); 
		set_save_2(sprintf("%s.size",type),pos);
		set_save_2(sprintf("%s.%d.%s",type,id,power_name),power[power_name]);
		set_save_2(sprintf("%s.%d.pos",type,id),pos);
		set_save_2(sprintf("%s.%d.account",type,id),who->get_id());
		set_save_2(sprintf("%s.%d.id",type,id),who->get_number());
		set_save_2(sprintf("%s.%d.name",type,id),who->get_name());
		set_save_2(sprintf("%s.%d.family",type,id),who->get_fam_name());
		
	}
	else 
	{
		id1=get_save_2(sprintf("%s.pos.%d",type,size));//取最后一个位置上玩家的ID
		if(get_save_2(sprintf("%s.%d.%s",type,id1,power_name))<power[power_name])
		{
			pos=size;
			delete_save_2(sprintf("%s.%d",type,id1)); //删除最后位置上玩家信息
			set_save_2(sprintf("%s.size",type),pos);//重设当前表数记录数
			set_save_2(sprintf("%s.pos.%d",type,pos),id);
			set_save_2(sprintf("%s.%d.%s",type,id,power_name),power[power_name]);
			set_save_2(sprintf("%s.%d.pos",type,id),pos); //排名
			set_save_2(sprintf("%s.%d.account",type,id),who->get_id());
			set_save_2(sprintf("%s.%d.id",type,id),who->get_number());
			set_save_2(sprintf("%s.%d.name",type,id),who->get_name());
			set_save_2(sprintf("%s.%d.family",type,id),who->get_fam_name());
			
		}
	}
	if(pos)
	{
		id=get_save_2(sprintf("%s.pos.%d",type,pos));
		id1=get_save_2(sprintf("%s.pos.%d",type,pos+1));
		id2=get_save_2(sprintf("%s.pos.%d",type,pos-1));
		if(get_save_2(sprintf("%s.%d.%s",type,id1,power_name))&&(get_save_2(sprintf("%s.%d.%s",type,id,power_name))<get_save_2(sprintf("%s.%d.%s",type,id1,power_name))))
		{
			size=get_save_2(sprintf("%s.size",type));
			for(i=pos;i<size;i++)
			{
				id=get_save_2(sprintf("%s.pos.%d",type,i));
				id1=get_save_2(sprintf("%s.pos.%d",type,i+1));
				if(get_save_2(sprintf("%s.%d.%s",type,id,power_name))<get_save_2(sprintf("%s.%d.%s",type,id1,power_name)))
				{
					set_save_2(sprintf("%s.pos.%d",type,i),id1);
					set_save_2(sprintf("%s.%d.pos",type,id1),i);
					set_save_2(sprintf("%s.pos.%d",type,i+1),id);
					set_save_2(sprintf("%s.%d.pos",type,id),i+1);	
				}
			}
		}
		else
		{
			for(i=pos;i>1;i--)
			{
				id=get_save_2(sprintf("%s.pos.%d",type,i));
				id2=get_save_2(sprintf("%s.pos.%d",type,i-1));
				if(get_save_2(sprintf("%s.%d.%s",type,id,power_name))>get_save_2(sprintf("%s.%d.%s",type,id2,power_name)))
				{
					set_save_2(sprintf("%s.pos.%d",type,i),id2);
					set_save_2(sprintf("%s.%d.pos",type,id2),i);
					set_save_2(sprintf("%s.pos.%d",type,i-1),id);
					set_save_2(sprintf("%s.%d.pos",type,id),i-1);	
				}
			}
		}
		
	}
	save();
}


string get_top_data(object who, string type, string power_name) {
	int i, size, id, level, pos, tudi, point, xy_family;
	string name, family;
	mapping expTmp, cashTmp, teacherTmp, gongdeTmp, diziTmp;
	mapping players;
	string result = "";

	if (mapp(cashTmp = get_save_2(type)))
	{
		players = copy(cashTmp);
		Point_players = copy(cashTmp);
	}
	if (mapp(Point_players))
	{
		size = Point_players["size"];
		if (size > 5) {
			size = 5;
		}

		for (i = 0; i < size; i++)
		{
			id = Point_players["pos"][sprintf("%d", i + 1)];
			pos = Point_players[sprintf("%d", id)]["pos"];
			name = Point_players[sprintf("%d", id)]["name"];
			family = Point_players[sprintf("%d", id)]["family"];
			xy_family = xy_get_fam_id(family);

			point = Point_players[sprintf("%d", id)]["point"];

			if (i == 0) {
				result += sprintf("%d."HIR" %d điểm _ %s\n",i+1, point, name);
			} else
			if (i == 1) {
				result += sprintf("%d."HIB" %d điểm _ %s\n", i + 1, point, name);
			} else
			if (i == 2) {
				result += sprintf("%d."HIC" %d điểm _ %s\n", i + 1, point, name);
			} else
			result += sprintf("%d. %s %d\n", i + 1, name, point);

			//send_user(who,"%c%c%c%c%s",0xA9,2,pos,xy_family,name);
			//tell_user(who, "sorted: %s", name);
		}

		return result;
	}
	return result;
}

void send_mingren_data(object who,mapping players,string type)
{
	int i,size,id,level,pos,tudi,point,xy_family;
	string name,family;

	if(mapp(players))
	{
		size=players["size"];
		for(i=0;i<size;i++)
		{
			id=players["pos"][sprintf("%d",i+1)];
			pos=players[sprintf("%d",id)]["pos"];
			name=players[sprintf("%d",id)]["name"];
			family=players[sprintf("%d",id)]["family"];
			xy_family=xy_get_fam_id(family);
			switch(type)
			{
				case "point":
					send_user(who,"%c%c%c%c%s",0xA9,5,pos,xy_family,name);
					break;
				
			}

			//tell_user(who, "sorted: %s", name);
		}
	}
}
