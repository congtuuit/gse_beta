
#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <public.h>

#include <map.h>
#include <city.h>

inherit "/inh/std/virtual";

#define SANTACLAUS	"npc/party/santaclaus"

mapping mpTree1 = ([
    1:({ ({53,144}), ({149,138}), }),
        80 : ({ ({292,183}), }),
]);

mapping mpTree2 = ([
    1:({ ({193,148}),({146,153}),({182,153}),({160,148}), }),
        10 : ({ ({130,113}), ({135,117}) , ({139,198}),({143,195}) }),
        20 : ({ ({228,84}),({167,87}),({172,93}),({230,93}), }),
        30 : ({ ({191,80}),({173,94}),({229,96}),({202,78}), }),
        40 : ({ ({270,113}),({265,117}),({258,191}),({264,196}), }),
        50 : ({ ({128,114}),({134,118}),({118,172}), }),
        60 : ({ ({242,169}),({247,173}),({138,184}),({133,188}), }),
        70 : ({ ({181,219}),({251,187}),({217,245}),({232,217}), }),
        80 : ({ ({220,49}),({189,70}),({161,75}),({214,117}),({209,121}),({324,132}),({311,140}), }),
        289 : ({ ({49,59}), ({66,62}) }),
        165 : ({ ({90,30}), ({110,30}) }),
        269 : ({ ({253,166}), ({265,188}) }),
        273 : ({ ({185,140}),({197,155}),({216,170}), }),
        54 : ({ ({140,115}),({127,126}),({114,138}), }),
        324 : ({ ({99,115}), ({119,156}) }),
        886 : ({ ({112,92}), ({136,110}) }),
]);

int main( object me, string arg )
{
        mapping skls;
        object *inv, *item;
        string cmd0, cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, cmd7, cmd8,cmd9,cmd10,cmd11,cmd12,cmd13,cmd14,cmd15,cmd16,cmd17,cmd18,cmd19;
        string *name, file;
        int family, level, level2, weapon, armor;
        int p, i, size, size2;

        int z, x, y, j, count, * nZ, * nXy;
        object* nObj, tree, thisItem;
        mixed* nPoint;

        if( is_player(me) ) 
        {
                notify( "Bạn không có đặc quyền" );
		return 1;
        }


        if( arg ==0  )
        {

        	cmd1 = "bian 10\n";
        	cmd2 = "bian 11\n";

        	cmd3 = "bian 301\n";
        	cmd4 = "bian 402\n";
        	cmd5 = "bian 4145\n";
        	cmd6 = "bian 4143\n";

        	cmd10 = "bian 9972\n";

        	cmd11 = "bian 7739\n";
        	cmd12 = "bian 8250\n";
        	cmd13 = "bian 8267\n";
        	cmd14 = "bian 8200\n";
        	cmd15 = "bian 9012\n";
        	cmd16 = "bian 7028\n";
        	cmd17 = "bian 7014\n";
        	cmd18 = "bian 7019\n";
        	cmd19 = "bian 7044\n";
        	cmd0 = "bian cancel\n";

                send_user( me, "%c%s", ':', "您想把自己设为哪种门派？\n"
                        ESC "Xoa cay noel_ tet\n" + cmd1 +
                        ESC "Toa cay noel\n" + cmd2 +
                        ESC "Nhện.\n" + cmd3 +
                        ESC "Rùa.\n" + cmd4 +
                        ESC "Đậu.\n" + cmd5 +
                        ESC "Thần tướng.\n" + cmd6 +
                        ESC "Santa Claus\n" + cmd10 +
                        ESC "Than rung\n" + cmd11 +
                        ESC "Meo Trang\n" + cmd12 +
                        ESC "Tiên Bướm\n" + cmd13 +
                        ESC "Bụt\n" + cmd14 +
                        ESC "Tiên Hoa\n" + cmd15 +
                        ESC "Ông Già Noel Phản Loạn\n" + cmd16 +
                        ESC "道长\n" + cmd17 +
                        ESC "Núi lửa\n" + cmd18 +
                        ESC "Huỷ bỏ biến thân\n" + cmd0);
                return 1;
        }
        if (arg=="cancel")
        {
        	me->set_save("temp_act", 0);
        	me->add_to_scene( get_z(me), get_x(me), get_y(me));
        	return 1;
        }

        i = to_int(arg);
        if (i == 10) {
           
            nZ = keys(mpTree1);
            for (j = 0, count = sizeof(nZ); j < count; j++)
            {
                z = nZ[j];
                nPoint = mpTree1[z];

                for (i = 0, size = sizeof(nPoint); i < size; i++)
                {
                    nXy = nPoint[i];
                    x = nXy[0];
                    y = nXy[1];

                    if (have_scene_object(z, x, y, CHAR_TYPE, 1))
                    {
                        item = get_scene_object(z, x, y, CHAR_TYPE, 1);
                        if (item[0]) {
                            item[0]->remove_from_scene();
                            destruct(item[0]);
                        }
                    }
                }
            }

            nZ = keys(mpTree2);
            for (j = 0, count = sizeof(nZ); j < count; j++)
            {
                z = nZ[j];
                nPoint = mpTree2[z];

                for (i = 0, size = sizeof(nPoint); i < size; i++)
                {
                    nXy = nPoint[i];
                    x = nXy[0];
                    y = nXy[1];

                    if (have_scene_object(z, x, y, CHAR_TYPE, 1))
                    {
                        item = get_scene_object(z, x, y, CHAR_TYPE, 1);
                        if (item[0]) {
                            item[0]->remove_from_scene();
                            destruct(item[0]);
                        }
                    }
                }
            }

            me->set_save("temp_act", 0);
            me->add_to_scene(get_z(me), get_x(me), get_y(me));
            return 1;
            
        } if (i == 11) {
            "sys/party/christmas"->generate_tree();
            return 1;

        }
        else {
            me->set_save("temp_act", i);
            me->add_to_scene(get_z(me), get_x(me), get_y(me));
        }
        
       

        return 1;
}
