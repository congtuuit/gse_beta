
#include <time.h>
#include <ansi.h>
#include <cmd.h>

#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

void generate_scum();
void destroy_scum();
void CreateNguHoTuong();
void check_time2();

int* nScene = ({ 289,273,80,324,269,54,165 });
string* schoolname = ({ "Đào Hoa Nguyên", "Thục Sơn", "Cấm Vệ Quân", "Đường Môn", "Mao Sơn", "Côn Luân", "Vân Mộng Cốc", });
object* Scum;
mapping mpNianshou;
// 函数：生成二进制码
void SAVE_BINARY() { }

int main( object me, string arg )
{
	object who;
    int i, size, a1, a2, a3, a4;
    int amount, value;
    string partyName, type;
    if( is_player(me) ) 
    {
        notify( "Ngươi không đủ quyền hạn" );
	    return 1;
    }
    if(sscanf( arg, "%s %s", partyName, type) == 2){
	    
        switch (partyName)
        {

            case "nguho":
				if (type == "on") {
					CreateNguHoTuong();

				}
				else {
					check_time2();
				}
                break;
        }
    }
	
    return 1;
}


void CreateNguHoTuong() {
	Scum = ({});
	generate_scum();
}

void check_time2()
{
	int i, size;

	for (i = 0, size = sizeof(Scum); i < size; i++)
	{
		if (!objectp(Scum[i]))
			continue;

		Scum[i]->remove_from_scene();
		destruct(Scum[i]);
	}
	//Scum -= ({ 0 });

	CHAT_D->sys_channel(0, HIY"Ngũ Hổ Tướng Chiến Trận đã kết thúc!");
	CHAT_D->sys_channel(0, HIY"Ngũ Hổ Tướng Chiến Trận đã kết thúc!");
}

void generate_scum()
{
	int i, size, z, p, x, y, j;
	object npc1;
	object npc2;
	object npc3;
	object npc4;
	object npc5;

	int mapId = 375;

	destroy_scum();
	//1
	npc1 = new("/npc/event/PhoBan/5Boss/Boss1-CVQ");
	npc1->add_to_scene(mapId, 133, 35);
	Scum += ({ npc1 });
	CHAT_D->sys_channel(0, HIC "Nghe nói Ngũ Hổ Tướng "HIG"Tử Long"HIC" đã xuất hiện tại Ngũ Hổ Tướng Chiến Trận");
	//2
	npc2 = new("/npc/event/PhoBan/5Boss/Boss2-DM");
	npc2->add_to_scene(mapId, 68, 110);
	Scum += ({ npc2 });
	CHAT_D->sys_channel(0, HIC "Nghe nói Ngũ Hổ Tướng "HIG"Nhạc Phi"HIC" đã xuất hiện tại Ngũ Hổ Tướng Chiến Trận");
	//3
	npc3 = new("/npc/event/PhoBan/5Boss/Boss3-CVQ");
	npc3->add_to_scene(mapId, 112, 106);
	Scum += ({ npc3 });
	CHAT_D->sys_channel(0, HIC "Nghe nói Ngũ Hổ Tướng "HIG"Quan Vũ"HIC" đã xuất hiện tại Ngũ Hổ Tướng Chiến Trận");
	//4
	npc4 = new("/npc/event/PhoBan/5Boss/Boss4-CVQ");
	npc4->add_to_scene(mapId, 163, 102);
	Scum += ({ npc4 });
	CHAT_D->sys_channel(0, HIC "Nghe nói Ngũ Hổ Tướng "HIG"Hạng Vũ"HIC" đã xuất hiện tại Ngũ Hổ Tướng Chiến Trận");

	//5
	npc5 = new("/npc/event/PhoBan/5Boss/Boss5-CVQ");
	npc5->add_to_scene(mapId, 160, 127);
	Scum += ({ npc5 });
	CHAT_D->sys_channel(0, HIC "Nghe nói Ngũ Hổ Tướng "HIG"Tôn Vũ"HIC" đã xuất hiện tại Ngũ Hổ Tướng Chiến Trận");

	log_file("boss.txt", short_time() + " Ngũ Hổ Tướng xuất hiện\n");

	call_out("check_time2", 10800);

}

void destroy_scum()
{
	int i, size;
	for (i = 0, size = sizeof(Scum); i < size; i++)
	{
		if (!objectp(Scum[i]))
			continue;
		if (!Scum[i]->get("busy"))
		{
			Scum[i]->remove_from_scene();
			destruct(Scum[i]);
		}
		else
			Scum[i]->set("overdue", 1);
	}

	Scum -= ({ 0 });
}