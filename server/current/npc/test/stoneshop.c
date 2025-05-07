#include <npc.h>
#include <item.h>
#include <ansi.h>
#include <task.h>
#include <music.h>
#include <equip.h>
inherit OFFICER;

int get_char_picid() { return 5505; }
int is_seller() { return 1; }
int is_self_look() { return 1; }
void do_welcome(string arg);
void create()
{	  
        set_name("Shop Đã Khảm Nạm");
		set_2( "good", ([
                "01" : "/item/common/stone/101",
                "02" : "/item/common/stone/102",
                "03" : "/item/common/stone/103",
                "04" : "/item/common/stone/104",
                "05" : "/item/common/stone/105",
                "06" : "/item/common/stone/201",
                "07" : "/item/common/stone/202",
                "08" : "/item/common/stone/203",
                "09" : "/item/common/stone/204",
                "10" : "/item/common/stone/205",
                "11" : "/item/common/stone/301",
                "12" : "/item/common/stone/302",
                "13" : "/item/common/stone/303",
                "14" : "/item/common/stone/304",
                "15" : "/item/common/stone/305",
                "16" : "/item/common/stone/duclo",
                "17" : "/item/common/stone/tinhthach",
                "18" : "/item/common/stone/xoa",
                "19" : "/item/common/stone/kt",
        ]) );
		
        setup();

}

void do_look( object player )
{
	object npc = this_object();

    send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s :\n" + "Mùa thi cử lần này ta nhất định sẽ đỗ Trạng Nguyên !\n"
        ESC "Mua vật phẩm \nlist %x#\n"
        ESC "Rời khỏi\nCLOSE\n", npc->get_name(), getoid(npc), getoid(npc), getoid(npc)));

	
}

