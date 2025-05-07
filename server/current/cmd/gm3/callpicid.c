
#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>

void checkingId(object me, int picId) {

    object item, who;
    string* weapon, file;
    string cmd1, cmd2, cmd3, cmd4;
    object* inv;
    int family, z, x, y, p, i, size;
    string nameRootObject, nameItem, path, amount;
    int intAmount, next;
    
    inv = all_inventory(me, 1, MAX_CARRY * 4);
    for (i = 0, size = sizeof(inv); i < size; i++) if (objectp(item = inv[i]))
    {
        item->remove_from_user();
        destruct(item);
    }

    for (i = 0; i < 24; i++) {
        item = new ("/item/08/0853");
        //item = new ("/item/trangbi110/vukhi/719130");
        item->set_picid_1(picId + i);
        item->set_picid_2(picId + i);
        if (p = item->move(me, -1))
        {
            item->add_to_user(p);
        }
    }

    tell_user(me, sprintf("checking from %d to %d", picId, picId + 23));

    if (intAmount + 23 > 9999) {
        tell_user(me, sprintf("End"));

        return;
    }

    //call_out("checkingId", 2 ,me, picId + 23);
}
int main( object me, string arg )
{
        object item, who;
        string *weapon, file;
        string cmd1, cmd2, cmd3, cmd4;
        object* inv;
        int family, z, x, y, p, i, size;

        string nameRootObject, nameItem, path, amount;
        int intAmount;

        if( is_player(me) ) 
        {
		    return 1;
        }

        z = get_z(me), x = get_x(me), y = get_y(me);
         
        if( sscanf( arg, "%d", intAmount) == 1 )
        {
            checkingId(me, intAmount);
        }
             
        return 1;
}
