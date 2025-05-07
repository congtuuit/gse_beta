
#include <npc.h>
#include <ansi.h>
#include <city.h>
#include <effect.h>
#include <public.h>
#include <action.h>

// 函数：命令处理
int main( object me, string arg)
{
        string blocking = "block";
        string unblock = "unblock";
        string key = "passquankho";
        string status = "statusQuanKho";

        string pass;

       int index,pos,size,id,i;  
		object *objs, target;

        if ( arg )
        {
        	pass = me->get_save(key);

            if(arg == pass) {
        	    me->set_save(status,unblock);
                tell_user( me, "Đã mở khóa.");	
				notify( "Đã mở khóa" );

                if (get_z(me)==001)
					objs = children("/npc/base/0001");
					else if (get_z(me)==010)
					objs = children("/npc/base/1001");
					else if (get_z(me)==020)
					objs = children("/npc/base/2001");
					else if (get_z(me)==030)
					objs = children("/npc/base/3001");
					else if (get_z(me)==040)
					objs = children("/npc/base/4001");
					else if (get_z(me)==050)
					objs = children("/npc/base/5001");
					else if (get_z(me)==060)
					objs = children("/npc/base/6001");
					else if (get_z(me)==070)
					objs = children("/npc/base/7001");
					else if (get_z(me)==080)
					objs = children("/npc/base/8001");
					else if (get_z(me)==549)
					objs = children("/npc/base/0911");
					else
					objs = children("/npc/base/1001");

					size = sizeof(objs);

					if (size==0) return 0;

					for (i=0;i<size;i++)
					{
						if (objectp(objs[i]) )
						{
							target = objs[i];
							break;
						}
					}
					if (!target) return 0;	

					me->set("pawn_time", time());
					"/cmd/std/pawn"->do_list(me, sprintf("%x#", getoid(target)), 1);
					return 0;
			}
            else{

                notify( "Mật khẩu không đúng, vui lòng kiểm tra lại." );
            
			}
        	return 1;
        } 

        return 1;
}

void do_open(object me, int open){
	int index,pos,size,id,i;  
		object *objs, target;

	if(open == 1) 
	{
        if (get_z(me)==001)
			objs = children("/npc/base/0001");
			else if (get_z(me)==010)
			objs = children("/npc/base/1001");
			else if (get_z(me)==020)
			objs = children("/npc/base/2001");
			else if (get_z(me)==030)
			objs = children("/npc/base/3001");
			else if (get_z(me)==040)
			objs = children("/npc/base/4001");
			else if (get_z(me)==050)
			objs = children("/npc/base/5001");
			else if (get_z(me)==060)
			objs = children("/npc/base/6001");
			else if (get_z(me)==070)
			objs = children("/npc/base/7001");
			else if (get_z(me)==080)
			objs = children("/npc/base/8001");
			else if (get_z(me)==549)
			objs = children("/npc/base/0911");
			else
			objs = children("/npc/base/1001");

			size = sizeof(objs);

			if (size==0) return 0;

			for (i=0;i<size;i++)
			{
				if (objectp(objs[i]) )
				{
					target = objs[i];
					break;
				}
			}
			if (!target) return 0;	

			me->set("pawn_time", time());
			"/cmd/std/pawn"->do_list(me, sprintf("%x#", getoid(target)), 1);
			return 0;
	}
}