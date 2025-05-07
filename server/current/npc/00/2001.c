
#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>
#include <effect.h>

inherit OFFICER;
mapping mpBox = ([
			322086098: ([ 32*23+8  : ([ "legend2" : 32*23+9, "obj" : "item/98/0108" ,"taskid":TID_MAOSHAN,"taskno":2, "taskname":"游魂（3）(Hoàn thành)"])]),
			312214089: ([ 32*25+14 : ([ "legend2" : 32*25+15,"obj" : "item/98/0118" ,"taskid":TID_HANGUO, "taskno":20,"taskname":"Tìm hiểu bí ẩn của kho báu(Hoàn thành)"])]),
			313093144: ([ 32*26+26 : ([ "legend2" : 32*26+27,"obj" : "item/98/0125" ,"taskid":TID_HANGUO, "taskno":38,"taskname":"Tìm một cách(Hoàn thành)"])]),
			335149148: ([ 32*28+7  : ([ "legend2" : 32*28+8, "obj" : "item/98/0135" ,"taskid":TID_ZHAOGUO,"taskno":47,"taskname":"木箱的秘密（1）(Hoàn thành)"])]),
			342138125: ([ 32*29+23 : ([ "legend2" : 32*29+24,"obj" : "item/98/0142" ,"taskid":TID_QIGUO,  "taskno":29,"taskname":"Tìm kiếm kho báu(Hoàn thành)"])]),
			344148100: ([ 32*30+5  : ([ "legend2" : 32*30+6, "obj" : "item/98/0144" ,"taskid":TID_QIGUO,  "taskno":34,"taskname":"Mất và phục hồi(Hoàn thành)"])]),
			295169070: ([ 32*31+24 : ([ "legend2" : 32*31+25,"obj" : "item/98/0145" ,"taskid":TID_YANGUO, "taskno":41,"taskname":"秘密（4）(Hoàn thành)"])]),
			381089121: ([ 32*34+4  : ([ "legend2" : 32*34+5, "obj" : "item/98/0159" ,"taskid":TID_WEIGUO, "taskno":40,"taskname":"Kinh Nghiệm Tìm Báu Vật (Hoàn thành)"])]),
			011081056: ([ 32*36+17 : ([ "legend2" : 32*36+18,"obj" : "item/98/0168" ,"taskid":TID_QIGUO,  "taskno":55,"taskname":"Niết bàn(Hoàn thành)"])]),
			093192079: ([ 32*39+25 : ([ "legend2" : 32*39+26,"obj" : "item/98/0189" ,"taskid":TID_QIGUO,  "taskno":62,"taskname":"四面楚歌（2）(Hoàn thành)"])]),
			092114153: ([ 32*41+23 : ([ "legend2" : 32*41+24,"obj" : "item/98/0203" ,"taskid":TID_ZHAOGUO,"taskno":71,"taskname":"Cuộc phiêu lưu Thiên Môn(Hoàn thành)"])]),
			092088042: ([ 32*42+7  : ([ "legend2" : 32*42+8, "obj" : "item/98/0205" ,"taskid":TID_ZHAOGUO,"taskno":77,"taskname":"Tin tức chiến tranh(Hoàn thành)"])]),
			093132137: ([ 32*42+18 : ([ "legend2" : 32*42+19,"obj" : "item/98/0206" ,"taskid":TID_ZHAOGUO,"taskno":81,"taskname":"Tìm bản đồ(Hoàn thành)"])]),
			093150075: ([ 32*43+12 : ([ "legend2" : 32*43+13,"obj" : "item/98/0210" ,"taskid":TID_ZHAOGUO,"taskno":91,"taskname":"Tìm danh sách(Hoàn thành)"])]),
			391117150: ([ 32*44+18 : ([ "legend2" : 32*44+19,"obj" : "item/98/0220" ,"taskid":TID_QINGUO, "taskno":61,"taskname":"Tư vấn nhiệt tình（3）(Hoàn thành)"])]),
			392085076: ([ 32*46+21 : ([ "legend2" : 32*46+22,"obj" : "item/98/0229" ,"taskid":TID_QINGUO, "taskno":72,"taskname":"平阳之乱4(Hoàn thành)"])]),
			392012102: ([ 32*46+28 : ([ "legend2" : 32*46+29,"obj" : "item/98/0231" ,"taskid":TID_QINGUO, "taskno":75,"taskname":"炼药之路2(Hoàn thành)"])]),
			393174100: ([ 32*47+3  : ([ "legend2" : 32*47+4, "obj" : "item/98/0233" ,"taskid":TID_QINGUO, "taskno":77,"taskname":"炼药之路4(Hoàn thành)"])]),
			393011082: ([ 32*47+26 : ([ "legend2" : 32*47+27,"obj" : "item/98/0235" ,"taskid":TID_QINGUO, "taskno":87,"taskname":"索取神剑4(Hoàn thành)"])]),
			151097095: ([ 32*12+7  : ([ "legend2" : 32*12+8, "obj" : "item/98/0049" ,"taskid":TID_YANGUO, "taskno":3, "taskname":"Huyền thoại dòng sông(Hoàn thành)"])]),
			152060069: ([ 32*12+13 : ([ "legend2" : 32*12+14,"obj" : "item/98/0050" ,"taskid":TID_YANGUO, "taskno":5, "taskname":"Những rắc rối(Hoàn thành)"])]),
			152088093: ([ 32*13+1  : ([ "legend2" : 32*13+2 ,"obj" : "item/98/0051" ,"taskid":TID_YANGUO, "taskno":11,"taskname":"Bận tâm(Hoàn thành)"])]),
			152055062: ([ 32*13+4  : ([ "legend2" : 32*13+5 ,"obj" : "item/98/0052" ,"taskid":TID_YANGUO, "taskno":12,"taskname":"Truyền thuyết về lụa lạnh(Hoàn thành)"])]),
			153105074: ([ 32*13+10 : ([ "legend2" : 32*13+11,"obj" : "item/98/0053" ,"taskid":TID_YANGUO, "taskno":14,"taskname":"Huyền thoại về gương(Hoàn thành)"])]),
			152080087: ([ 32*13+13 : ([ "legend2" : 32*13+14,"obj" : "item/98/0054" ,"taskid":TID_YANGUO, "taskno":15,"taskname":"Người lính vô song(Hoàn thành)"])]),
			071078091: ([ 32*14+24 : ([ "legend2" : 32*14+25,"obj" : "item/98/0061" ,"taskid":TID_ZHAOGUO,"taskno":11,"taskname":"Những rắc rối của người hầu(Hoàn thành)"])]),
			071104110: ([ 32*15+4  : ([ "legend2" : 32*15+5 ,"obj" : "item/98/0062" ,"taskid":TID_ZHAOGUO,"taskno":14,"taskname":"Rượu ngon(Hoàn thành)"])]),
			031141102: ([ 32*15+21 : ([ "legend2" : 32*15+22,"obj" : "item/98/0067" ,"taskid":TID_ZHAOGUO,"taskno":4, "taskname":"Niềm vui thơ ấu(Hoàn thành)"])]),
			073188135: ([ 32*16+23 : ([ "legend2" : 32*16+24,"obj" : "item/98/0071" ,"taskid":TID_ZHAOGUO,"taskno":18,"taskname":"Truyền thuyết về quần áo thần(Hoàn thành)"])]),
			073140097: ([ 32*16+26 : ([ "legend2" : 32*16+27,"obj" : "item/98/0072" ,"taskid":TID_ZHAOGUO,"taskno":19,"taskname":"Một ngàn dặm đường đi bộ(Hoàn thành)"])]),
			073172131: ([ 32*17+1  : ([ "legend2" : 32*17+2 ,"obj" : "item/98/0073" ,"taskid":TID_ZHAOGUO,"taskno":20,"taskname":"Hào quang trên bầu trời đêm(Hoàn thành)"])]),
			071119117: ([ 32*17+13 : ([ "legend2" : 32*17+14,"obj" : "item/98/0074" ,"taskid":TID_ZHAOGUO,"taskno":24,"taskname":"Ánh sáng kì lạ(Hoàn thành)"])]),
			072161144: ([ 32*17+19 : ([ "legend2" : 32*17+20,"obj" : "item/98/0075" ,"taskid":TID_ZHAOGUO,"taskno":26,"taskname":"Cuộc phiêu lưu(Hoàn thành)"])]),
			072104101: ([ 32*17+22 : ([ "legend2" : 32*17+23,"obj" : "item/98/0076" ,"taskid":TID_ZHAOGUO,"taskno":27,"taskname":"Huỳnh quang bí ẩn(Hoàn thành)"])]),
			072121111: ([ 32*17+28 : ([ "legend2" : 32*17+29,"obj" : "item/98/0077" ,"taskid":TID_ZHAOGUO,"taskno":29,"taskname":"Thông điệp(Hoàn thành)"])]),
			072159142: ([ 32*18+7  : ([ "legend2" : 32*18+8 ,"obj" : "item/98/0078" ,"taskid":TID_ZHAOGUO,"taskno":32,"taskname":"Báo động(Hoàn thành)"])]),
			072116105: ([ 32*18+10 : ([ "legend2" : 32*18+11,"obj" : "item/98/0079" ,"taskid":TID_ZHAOGUO,"taskno":33,"taskname":"Thật đáng tiếc(Hoàn thành)"])]),
			164059049: ([ 32*8 +7  : ([ "legend2" : 32*8 +8 ,"obj" : "item/98/0033" ,"taskid":TID_CHUGUO, "taskno":15,"taskname":"Truy tìm kho báu đầm lầy(Hoàn thành)"])]),
			263111124: ([ 32*8 +16 : ([ "legend2" : 32*8 +17,"obj" : "item/98/0034" ,"taskid":TID_CHUGUO, "taskno":18,"taskname":"Hào Quang Kim Long(Hoàn thành)"])]),
			261112101: ([ 32*8 +19 : ([ "legend2" : 32*8 +20,"obj" : "item/98/0035" ,"taskid":TID_CHUGUO, "taskno":19,"taskname":"Lạc lối(Hoàn thành)"])]),
			262090062: ([ 32*9 +7  : ([ "legend2" : 32*9 +8 ,"obj" : "item/98/0037" ,"taskid":TID_CHUGUO, "taskno":25,"taskname":"Bí mật của Châu Phi(Hoàn thành)"])]),
			211136097: ([ 32*6 +7  : ([ "legend2" : 32*6 +8 ,"obj" : "item/98/0021" ,"taskid":TID_WEIGUO, "taskno":21,"taskname":"Giấc mơ anh hùng(Hoàn thành)"])]),
			131080105: ([ 32*6 +13 : ([ "legend2" : 32*6 +14,"obj" : "item/98/0022" ,"taskid":TID_WEIGUO, "taskno":23,"taskname":"Huyền thoại về hươu khổng lồ(Hoàn thành)"])]),
			051096140: ([ 32*20+7  : ([ "legend2" : 32*20+8 ,"obj" : "item/98/0090" ,"taskid":TID_QINGUO, "taskno":49,"taskname":"Rượu vang(Hoàn thành)"])]),
			151103054: ([ 32*10+17 : ([ "legend2" : 32*10+18,"obj" : "item/98/0043" ,"taskid":TID_QINGUO, "taskno":17,"taskname":"Tìm kiếm công thức nấu ăn(Hoàn thành)"])]),
			052118126: ([ 32*20+21 : ([ "legend2" : 32*20+22,"obj" : "item/98/0094" ,"taskid":TID_QINGUO, "taskno":24,"taskname":"Bản vẽ cung điện(Hoàn thành)"])]),
			052142115: ([ 32*20+24 : ([ "legend2" : 32*20+25,"obj" : "item/98/0095" ,"taskid":TID_QINGUO, "taskno":25,"taskname":"Gỗ gụ thiên niên kỷ(Hoàn thành)"])]),
			052144111: ([ 32*21+5  : ([ "legend2" : 32*21+6 ,"obj" : "item/98/0096" ,"taskid":TID_QINGUO, "taskno":29,"taskname":"Khó xây dựng(Hoàn thành)"])]),
			272066132: ([ 32*19+3  : ([ "legend2" : 32*19+4 ,"obj" : "item/98/0083" ,"taskid":TID_WEIGUO, "taskno":27,"taskname":"大葫芦（2）(Hoàn thành)"])]),



		]);
// 函数：获取人物造型
int get_char_picid() { return 2001; }

// 有自己的do_look函数
int is_self_look() { return 1; }

// 函数：构造处理
void create()
{
        set_name("Rương Bảo Vật");

        setup();
}

// 函数：对话处理
void do_look( object who )
{
	object item;
	int z,y,x,p,*nLegend,i,size;
	mapping mpTmp;
	y = get_y(this_object());
	x = get_x(this_object());
	z=get_z(who);
	
	if ( z == 62 && who->get_save("dodolook") == 2 )
	{
		if (get_effect(who, EFFECT_OPEN_BOX)) return;
		send_user(who, "%c%c%w%s", 0x5a, 0, 10, "Đang mở……");
		set_effect_2(who, EFFECT_OPEN_BOX, 1,10);
		return ;
	}
	if ((z==1||z==4||z==7) && who->get_legend(TASK_48, 6) && !who->get_legend(TASK_48, 7) )
	{
		if( !objectp( item = present("Tàng Bảo Đồ", who, 1, MAX_CARRY) ) || item->is_xunbao() != 1 )
		{
			if (get_effect(who, EFFECT_OPEN_BOX)) return;
			send_user(who, "%c%c%w%s", 0x5a, 0, 10, "Đang mở……");
			set_effect_2(who, EFFECT_OPEN_BOX, 1,10);
		}
	}
	if ((z==3||z==6||z==9) && who->get_legend(TASK_48, 8) && !who->get_legend(TASK_48, 9) )
	{
		if( !objectp( item = present("Gia Tộc Ngọc Bội", who, 1, MAX_CARRY) ) || item->is_xunbao() != 1 )
		{
			if (get_effect(who, EFFECT_OPEN_BOX)) return;
			send_user(who, "%c%c%w%s", 0x5a, 0, 10, "Đang mở……");
			set_effect_2(who, EFFECT_OPEN_BOX, 1,10);
		}
	}
	else if ( z == 62 && who->get_legend(TASK_NEWBIE_03, 1) && !who->get_legend(TASK_NEWBIE_03, 2) )
	{
		if( !objectp( item = present("钱老九的货物", who, 1, MAX_CARRY) ) )
		{
			if (get_effect(who, EFFECT_OPEN_BOX)) return;
			send_user(who, "%c%c%w%s", 0x5a, 0, 10, "Đang mở……");
			set_effect_2(who, EFFECT_OPEN_BOX, 1,10);
		}
	}
	else if( 

		  (x == 162 && y == 207 && z == 42  && who->get_legend(TASK_04,15) && !who->get_legend(TASK_04,16) && !who->get_save("sqcaiyi") ) ||
		  (x == 180 && y == 166 && z == 42  && who->get_legend(TASK_04,7 ) && !who->get_legend(TASK_04,8 ) && !who->get_save("yushizhengju") ) ||
		  (x == 216 && y == 100 && z == 43  && who->get_legend(TASK_04,17) && !who->get_legend(TASK_04,18) && !who->get_save("feicuizucuan") ) ||
		  (x == 42  && y == 102 && z == 43  && who->get_legend(TASK_04,13) && !who->get_legend(TASK_04,14) && !who->get_save("hujimijian") ) ||
		  (x == 161 && y == 99  && z == 81  && who->get_legend(TASK_04,9 ) && !who->get_legend(TASK_04,10) && !who->get_save("cushizhongren") ) ||
		  (x == 219 && y == 133 && z == 81  && who->get_legend(TASK_04,29) && !who->get_legend(TASK_04,30) && !who->get_save("diaobingfu") ) ||
		  (x == 220 && y == 92  && z == 311 && who->get_legend(TASK_27,12) && !who->get_legend(TASK_27,13) && !who->get_save_2("yzgmaobi") ) ||
		  (x == 214 && y == 89  && z == 312 && who->get_legend(TASK_27,12) && !who->get_legend(TASK_27,13) && !who->get_save_2("yzgyantai") ) ||
		  (x == 93  && y == 144 && z == 313 && who->get_legend(TASK_27,12) && !who->get_legend(TASK_27,13) && !who->get_save_2("yzgmokuai") ) ||
		  (x == 167 && y == 102 && z == 82  && who->get_legend(TASK_04,21) && !who->get_legend(TASK_04,22) && !who->get_save("folongzhu") )
		  )
	{
		if (get_effect(who, EFFECT_OPEN_BOX)) return;
		send_user(who, "%c%c%w%s", 0x5a, 0, 10, "Đang mở……");
		set_effect_2(who, EFFECT_OPEN_BOX, 1,10);
	}

	else
	{
		p = z*1000000 + x * 1000+y;
		if ( !mapp(mpBox[p]) )
			return ;
		nLegend = keys(mpBox[p]);
		for(i=0,size=sizeof(nLegend);i<size;i++)
		{
			mpTmp = mpBox[p][nLegend[i]];
			if ( !mapp(mpTmp) )
				continue;
			if ( !who->get_legend(nLegend[i]/32, nLegend[i]%32) || who->get_legend(mpTmp["legend2"]/32, mpTmp["legend2"]%32) )
				continue;
			if (get_effect(who, EFFECT_OPEN_BOX)) return;
			who->set("openbox",this_object());
			send_user(who, "%c%c%w%s", 0x5a, 0, 10, "Đang mở……");
			set_effect_2(who, EFFECT_OPEN_BOX, 1,10);				
			return;
		}
	}
}

// 函数：对话处理
void into_effect( object who )
{
	object item;
	int p,z,x,y;
	int i,size,*nLegend;
	mapping mpTmp;
	object obj,npc;
	string tmp;
	
	if (get_effect_3(who, EFFECT_OPEN_BOX)) return;
	send_user(who, "%c%c%c", 0x5a, 1, 1);
	z=get_z(who);
	if ( objectp(npc=who->get("openbox")) )
	{
		who->delete("openbox");
		if ( npc->get("boxname") == "Sư Môn Bảo Rương" )
		{
			"npc/90/box"->into_effect(who,npc);	
			return ;	
		}
		else if ( npc->get("boxname") == "Rương Tình Nhân" )
		{
			"npc/event/ruongpbtn"->into_effect(who,npc);	
			return ;	
		}
		else if ( npc->get_name() == "破罐子" )
		{
			"npc/00/2004"->into_effect(who,npc);	
			return ;	
		}		
		else if ( npc->get_name() == "骷髅" )
		{
			"npc/00/2005"->into_effect(who,npc);		
			return ;	
		}
		else if ( npc->get_name() == "Hoa Tơ" )
		{
			"npc/00/2006"->into_effect(who,npc);		
			return ;	
		}
		else if ( npc->get_name() == "Đá cổ" )
		{
			"npc/00/2007"->into_effect(who,npc);		
			return ;	
		}
		else if ( npc->get_name() == "大水缸" )
		{
			"npc/00/2008"->into_effect(who,npc);		
			return ;	
		}
		else if ( npc->get_name() == "神秘泥桶" )
		{
			"npc/00/2009"->into_effect(who,npc);		
			return ;	
		}
		else if ( npc->get_name() == "神笔石" )
		{
			"npc/00/2010"->into_effect(who,npc);		
			return ;	
		}
		else if ( npc->get_name() == "Cơ Quan Thạch" )
		{
			"npc/copy/0011"->into_effect(who,npc);		
			return ;	
		}
		else if ( npc->get_name() == "陵墓宝箱" )
		{
			"npc/00/2011"->into_effect(who,npc);		
			return ;	
		}
		else
		{
			x = get_x(npc);
			y = get_y(npc);
			p = z*1000000 + x * 1000+y;
			if ( !mapp(mpBox[p]) )
				return ;
			nLegend = keys(mpBox[p]);
			for(i=0,size=sizeof(nLegend);i<size;i++)
			{
				mpTmp = mpBox[p][nLegend[i]];
				if ( !mapp(mpTmp) )
					continue;
				if ( !who->get_legend(nLegend[i]/32, nLegend[i]%32) || who->get_legend(mpTmp["legend2"]/32, mpTmp["legend2"]%32) )
					continue;
				item = new(mpTmp["obj"]);
				if ( !item ) return;
				p =item->move(who, -1);
				if( p )
				{
		                        item->add_to_user(p);	
		                        who->set_legend(mpTmp["legend2"]/32, mpTmp["legend2"]%32);
		                        send_user( who, "%c%s", '!', "您获得了"HIY+item->get_name());
					send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,mpTmp["taskid"],mpTmp["taskno"],mpTmp["taskname"] );
					USER_TASK_D->send_task_intro(who,2,mpTmp["taskid"],mpTmp["taskno"]);
				}
				else
				{
		                       	destruct(item); 
		                       	send_user( who, "%c%s", '!', "Hành trang không đủ chỗ trống！");				
				}			
			}		
		}
		
		return;
	
	}
	if ( z == 62 && who->get_save("dodolook") == 2 )
	{
		item = new("item/98/0236");
		p =item->move(who, -1);
		if ( !p )
		{
	               	destruct(item); 
	               	send_user( who, "%c%s", '!', "Hành trang không đủ chỗ trống！");
	               	return ;				
		}
		item->add_to_user(p);
		who->set_save("dodolook",3);
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_DODOLOOK, 2, "" );
		send_user( who, "%c%s", '!', "您获得了玉玺！");
		send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_DODOLOOK,"寻找dodolook" ); 
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_DODOLOOK, 3, "寻回玉玺(Hoàn thành)" ); 
		return ;	
	}
	if ( (z==1||z==4||z==7) && who->get_legend(TASK_48, 6) && !who->get_legend(TASK_48, 7) )
	{
		if( !objectp( item = present("Tàng Bảo Đồ", who, 1, MAX_CARRY) ) || item->is_xunbao() != 1 )
		{
			item = new("item/98/9879");
			if ( !item ) return;
			if( USER_INVENTORY_D->can_carry(who, item)  >=1 )
			{
                                p =item->move(who, -1);
                                item->add_to_user(p);		
                                send_user( who, "%c%s", '!', "Ngươi được bản đồ kho báu!");
                                send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,103,"Kinh Nghiệm Tìm Báu Vật (Hoàn thành)" );					
                                USER_TASK_D->send_task_intro(who,2,TID_NEWBIE_01,103);
			}
			else
			{
                               	destruct(item); 
                               	send_user( who, "%c%s", '!', "Hành trang không đủ chỗ trống！");				
			}
		}
		
	}
	if ( (z==3||z==6||z==9) && who->get_legend(TASK_48, 8) && !who->get_legend(TASK_48, 9) )
	{
		if( !objectp( item = present("Gia Tộc Ngọc Bội", who, 1, MAX_CARRY) ) || item->is_xunbao() != 1 )
		{
			if( !objectp( item = present("Tàng Bảo Đồ", who, 1, MAX_CARRY) ) || item->is_xunbao() != 1 )
			{
				send_user(who,"%c%s",'!',"你的藏宝图呢?");
				return;
			}
			item->remove_from_user();
			destruct(item);	
			item = new("item/98/9880");
			if ( !item ) return;
			if( USER_INVENTORY_D->can_carry(who, item)  >=1 )
			{
                                p =item->move(who, -1);
                                item->add_to_user(p);		
                                who->set_legend(TASK_48, 9);
                                send_user( who, "%c%s", '!', "您获得了家族玉佩！");
                                send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,104,"Ngọc bội gia tộc(Hoàn thành)" );					
                                USER_TASK_D->send_task_intro(who,2,TID_NEWBIE_01,104);
			}
			else
			{
                               	destruct(item); 
                               	send_user( who, "%c%s", '!', "Hành trang không đủ chỗ trống！");				
			}
		}
		
	}
	else if (z == 62 && who->get_legend(TASK_NEWBIE_03, 1) && !who->get_legend(TASK_NEWBIE_03, 2) )
	{
		if( !objectp( item = present("钱老九的货物", who, 1, MAX_CARRY) ) )
		{
			item = new("item/98/0001");
			if ( !item ) return;
			if( USER_INVENTORY_D->can_carry(who, item)  >=1 )
			{
                                p =item->move(who, -1);
                                item->add_to_user(p);		
                                send_user( who, "%c%s", '!', "您获得了"HIY"钱老九的货物！");
                                send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,1,"取回货物(Hoàn thành)" );					
				USER_TASK_D->send_task_intro(who,2,TID_CHUGUO,1);
			}
			else
			{
                               	destruct(item); 
                               	send_user( who, "%c%s", '!', "Hành trang không đủ chỗ trống！");				
			}
		}
		
	}
	else if (z == 42 && who->get_legend(TASK_04,15) && !who->get_legend(TASK_04,16) && !who->get_save("sqcaiyi") )
	{
		item = new("item/98/0013");
		if ( !item ) return;
		 p =item->move(who, -1);
		if( p )
		{
                        item->add_to_user(p);	
                        who->set_save("sqcaiyi",1);
                        send_user( who, "%c%s", '!', "您获得了"HIY"彩衣");
		}
		else
		{
                       	destruct(item); 
                       	send_user( who, "%c%s", '!', "Hành trang không đủ chỗ trống！");				
		}
	}
	else if (z == 42 && who->get_legend(TASK_04,7) && !who->get_legend(TASK_04,8) && !who->get_save("yushizhengju") )
	{
		item = new("item/98/0010");
		if ( !item ) return;
		 p =item->move(who, -1);
		if( p )
		{
                        item->add_to_user(p);	
                        who->set_save("yushizhengju",1);
                        send_user( who, "%c%s", '!', "您获得了"HIY"证据");
		}
		else
		{
                       	destruct(item); 
                       	send_user( who, "%c%s", '!', "Hành trang không đủ chỗ trống！");				
		}
	}
	else if (z == 82 && who->get_legend(TASK_04,21) && !who->get_legend(TASK_04,22) && !who->get_save("folongzhu") )
	{
		item = new("item/98/0015");
		if ( !item ) return;
		 p =item->move(who, -1);
		if( p )
		{
                        item->add_to_user(p);	
                        who->set_save("folongzhu",1);
                        send_user( who, "%c%s", '!', "您获得了"HIY"佛龙珠");
		}
		else
		{
                       	destruct(item); 
                       	send_user( who, "%c%s", '!', "Hành trang không đủ chỗ trống！");				
		}
	}
	else if (z == 43 && who->get_legend(TASK_04,17) && !who->get_legend(TASK_04,18) && !who->get_save("feicuizucuan") )
	{
		item = new("item/98/0014");
		if ( !item ) return;
		 p =item->move(who, -1);
		if( p )
		{
                        item->add_to_user(p);	
                        who->set_save("feicuizucuan",1);
                        send_user( who, "%c%s", '!', "您获得了"HIY"翡翠珠串");
		}
		else
		{
                       	destruct(item); 
                       	send_user( who, "%c%s", '!', "Hành trang không đủ chỗ trống！");				
		}
	}
	else if (z == 43 && who->get_legend(TASK_04,13) && !who->get_legend(TASK_04,14) && !who->get_save("hujimijian") )
	{
		item = new("item/98/0012");
		if ( !item ) return;
		 p =item->move(who, -1);
		if( p )
		{
                        item->add_to_user(p);	
                        who->set_save("hujimijian",1);
                        send_user( who, "%c%s", '!', "您获得了"HIY"户籍密件");
		}
		else
		{
                       	destruct(item); 
                       	send_user( who, "%c%s", '!', "Hành trang không đủ chỗ trống！");				
		}
	}
	else if (z == 81 && who->get_legend(TASK_04,9) && !who->get_legend(TASK_04,10) && !who->get_save("cushizhongren") )
	{
		item = new("item/98/0011");
		if ( !item ) return;
		 p =item->move(who, -1);
		if( p )
		{
                        item->add_to_user(p);	
                        who->set_save("cushizhongren",1);
                        send_user( who, "%c%s", '!', "您获得了"HIY"玉龙睛");
		}
		else
		{
                       	destruct(item); 
                       	send_user( who, "%c%s", '!', "Hành trang không đủ chỗ trống！");				
		}
	}
	else if (z == 81 && who->get_legend(TASK_04,29) && !who->get_legend(TASK_04,30) && !who->get_save("diaobingfu") )
	{
		item = new("item/98/0016");
		if ( !item ) return;
		 p =item->move(who, -1);
		if( p )
		{
                        item->add_to_user(p);	
                        who->set_save("diaobingfu",1);
                        send_user( who, "%c%s", '!', "您获得了"HIY"调兵符");
		}
		else
		{
                       	destruct(item); 
                       	send_user( who, "%c%s", '!', "Hành trang không đủ chỗ trống！");				
		}
	}
	else if ( z == 311 && who->get_legend(TASK_27,12) && !who->get_legend(TASK_27,13) && !who->get_save_2("yzgmaobi") )
	{
		item = new("item/98/0127");
		if ( !item ) return;
		 p =item->move(who, -1);
		if( p )
		{
                        item->add_to_user(p);	
                        who->set_save_2("yzgmaobi",1);
                        send_user( who, "%c%s", '!', "您获得了"HIY"毛笔");
			if ( who->get_save_2("yzgmaobi") && who->get_save_2("yzgyantai")  && who->get_save_2("yzgmokuai")  )
			{
				who->set_legend(TASK_27,13);
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,37,"同心锁（2）(Hoàn thành)" );
			}
			USER_TASK_D->send_task_intro(who,2,TID_YANGUO,37);		
		}
		else
		{
                       	destruct(item); 
                       	send_user( who, "%c%s", '!', "Hành trang không đủ chỗ trống！");				
		}
	}
	else if ( z == 312 && who->get_legend(TASK_27,12) && !who->get_legend(TASK_27,13) && !who->get_save_2("yzgyantai") )
	{
		item = new("item/98/0128");
		if ( !item ) return;
		 p =item->move(who, -1);
		if( p )
		{
                        item->add_to_user(p);	
                        who->set_save_2("yzgyantai",1);
                        send_user( who, "%c%s", '!', "您获得了"HIY"砚台");
			if ( who->get_save_2("yzgmaobi") && who->get_save_2("yzgyantai")  && who->get_save_2("yzgmokuai")  )
			{
				who->set_legend(TASK_27,13);
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,37,"同心锁（2）(Hoàn thành)" );
			}
			USER_TASK_D->send_task_intro(who,2,TID_YANGUO,37);		
		}
		else
		{
                       	destruct(item); 
                       	send_user( who, "%c%s", '!', "Hành trang không đủ chỗ trống！");				
		}
	}	
	else if ( z == 313 && who->get_legend(TASK_27,12) && !who->get_legend(TASK_27,13) && !who->get_save_2("yzgmokuai") ) 
	{
		item = new("item/98/0129");
		if ( !item ) return;
		 p =item->move(who, -1);
		if( p )
		{
                        item->add_to_user(p);	
                        who->set_save_2("yzgmokuai",1);
                        send_user( who, "%c%s", '!', "您获得了"HIY"墨块");
			if ( who->get_save_2("yzgmaobi") && who->get_save_2("yzgyantai")  && who->get_save_2("yzgmokuai")  )
			{
				who->set_legend(TASK_27,13);
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,37,"同心锁（2）(Hoàn thành)" );
			}
			USER_TASK_D->send_task_intro(who,2,TID_YANGUO,37);		
		}
		else
		{
                       	destruct(item); 
                       	send_user( who, "%c%s", '!', "Hành trang không đủ chỗ trống！");				
		}
	}	
	
	
}

void effect_break(object who)
{
	set_effect(who, EFFECT_OPEN_BOX, 0);
	send_user(who, "%c%c%c", 0x5a, 1, 0);
}
