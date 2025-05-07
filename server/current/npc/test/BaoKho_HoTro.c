
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// 函数：小贩识别
//int is_item_seller() { return 1; }
int is_seller() { return 7001; }
int is_self_look() { return 1; }

// 函数：获取人物造型
//int get_char_picid() { return 9815; }
int get_char_picid() { return 4984; }
//int get_char_picid() { return 0701; }
//int get_char_picid() { return 9966; }

// 函数：构造处理
void create()
{
        set_name(HIB"Cửa Tiệm Bảo Khố");
        set_real_name(HIR "Vô Hậu");
		
		set_2( "good", ([
				"01" : "/item/test2/TuiPhapBao",
				"02" : "/item/TuiLinhThach/NgauNhien/4",
				"03" : "/item/test2/TuiThanThu",
				"04" : "/item/test2/TuiThuCuoi",
				"05" : "/item/test2/TuiThanThuHoangDao",
				"06" : "/item/08/0001",
				"07" : "/item/test2/AXP",
				"08" : "/item/test2/LTDB",
				"09" : "/item/test2/TuiQuaVoSong",
				"10" : "/item/test2/TheGiamGia",
				"11" : "/item/08/0017",

				//"11" : "/item/test2/TanNienLeBao",
				//"12" : "/item/test2/Phao",
				//"13" : "/item/test2/KyLan",
				//"14" : "/item/sell/0032",
				//"15" : "/item/sell/1032",
				//"16" : "/item/sell/3032",
				//"17" : "/item/ppvacanh/vgpp/vgpp",
				//"18" : "/item/ppvacanh/canhnam/canhnam",
        ]) );

        setup();
}
/*
void do_look( object who ) 
{
	int id = getoid( this_object() );
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn muốn mua vật phẩm không ? \n(Chỉ có thể mua bằng Kim Nguyên Bảo ) \n \nHiện bạn đang có "HIB"%d "NOR "Kim Nguyên Bảo \n"
		ESC HIY"Mua vật phẩm\nlist %x#\n"
		ESC"Rời khỏi",get_name(),"sys/sys/test_db"->get_yuanbao(who)/10,id));	
}
*/

void do_look( object who ) 
{
	int id = getoid( this_object() );
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn muốn mua vật phẩm không ? \n(Chỉ có thể mua bằng Kim Nguyên Bảo ) \n \nHiện bạn đang có "HIB"%d "NOR "Kim Nguyên Bảo \n"
		ESC HIY"Mua vật phẩm\nlist %x#\n"
		//ESC"Rời khỏi",get_name(),id));
		ESC"Rời khỏi",get_name(),"sys/sys/test_db"->get_yuanbao(who)/10,id));	
}