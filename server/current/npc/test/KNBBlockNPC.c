
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// 函数：小贩识别
//int is_item_seller() { return 1; }
int is_seller() { return 7003; }
int is_self_look() { return 1; }

// 函数：获取人物造型
int get_char_picid() { return 9815; }

// 函数：构造处理
void create()
{
        set_name(HIY"Cửa Tiệm KNB (Khóa)");
        set_real_name(HIG "Mã Đại Lang");
		
		set_2( "good", ([
				"01":"/item/test2/block/0200",
				"02":"/item/test2/block/0201",
				"03":"/item/test2/block/0202",
				"04":"/item/test2/block/TuiThuCuoi",
				"05":"/item/test2/block/TuiThanThuHoangDao",
				"06":"/item/test2/block/TuiThanThu",
				"07":"/item/test2/block/TuiPhapBao",
				"08":"/item/test2/block/0001",
				"09":"/item/test2/block/0002",
				"10":"/item/test2/block/AXPBlock",
				"11":"/item/test2/block/0033",
				"12":"/item/test2/block/0006",
				"13":"/item/test2/block/TuiQuaVoSong",
				"14":"/item/08/0014",
				"15":"/item/08/0016",
				"16":"/item/08/0017",
				"17" : "/item/sell/ruongdutru",
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
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn muốn mua vật phẩm không ? \n(Chỉ có thể mua bằng Kim Nguyên Bảo Khóa) \n \nHiện bạn đang có "HIB"%d "NOR "Kim Nguyên Bảo Khóa \n"
		ESC HIY"Mua vật phẩm\nlist %x#\n"
		//ESC"Rời khỏi",get_name(),id));
		ESC"Rời khỏi",get_name(),"sys/sys/test_db"->get_yuanbao_block(who)/10,id));	
}