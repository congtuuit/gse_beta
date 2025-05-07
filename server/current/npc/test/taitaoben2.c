/*------------------------------------
    Tái Tạo by Ben
------------------------------------*/
#include <npc.h>
#include <item.h>
#include <ansi.h>
#include <task.h>
#include <music.h>
#include <equip.h>
void taitao(object item, int abc);
void giamngoc(object item);

//
//int* ben_vukhi = ({ 20, 0, 56, 0, 180, 0, 0, 50, 0,
//    40, 0, 56, 0, 180, 0, 0, 50, 0, 22, 0,
//    60, 0, 240, 0, 60, 0, 0, 44, 0,
//    60, 0, 240, 0, 60, 0, 0, 20, 0,
//    0, 60, 0, 0, 72, 51, 0, 40, 0,
//    0, 40, 0, 0, 72, 51, 0, 24, 0,
//    63, 0, 240, 0, 0, 0, 22, 48, 0,
//    63, 0, 240, 0, 0, 0, 22, 20, 0,
//    52, 0, 220, 0, 72, 0, 0, 40, 0,
//    52, 0, 220, 0, 72, 0, 0, 18, 0,
// 40, 0, 0, 80, 0, 70, 0, 36, 0, 32, 0, 0, 80, 0, 70, 0, 20, 0, 0, 50, 140, 0, 0, 50, 0, 40, 0, 0, 50, 140, 0, 0, 50, 0, 20, 0, 0,
// 65, 0, 160, 0, 50, 0, 40, 0, 0,
// 58, 0, 160, 0, 50, 0, 20, 0, 0, 48, 140, 140, 0, 0, 0, 40, 0, 0, 48, 140, 140, 0, 0, 0, 22, 20, 63,
// 58, 0, 0, 0, 0, 0, 44, 40, 63, 53, 0, 0, 0, 0, 0, });
//int* ben_ao = ({
//    22, 14, 400, 0, 100, 0, 35,
//    44, 28, 400, 0, 100, 0, 35,
//    22, 14, 0, 0, 110, 40, 40, 44, 28, 0, 0, 110, 40, 40, 24, 12, 450, 0, 80, 0, 20, 48, 24, 450, 0, 80, 0, 20, 20, 14, 0, 0, 60, 50, 72, 40, 28, 0, 0, 60, 50, 72, 12, 24, 0, 480, 40, 68, 0, 24, 48, 0, 480, 40, 68, 0, 12, 24, 0, 400, 45, 75, 0, 24, 48, 0, 400, 45, 75, 0, 14, 24, 200, 0, 55, 70, 0, 28, 48, 200, 0, 55, 70, 0, 24, 24, 0, 0, 110, 75, 0, 48, 48, 0, 0, 110, 75, 0, });
//int* ben_non = ({ 12, 6, 200, 0, 60, 40, 0, 24, 12, 200, 0, 60, 40, 0, 12, 6, 0, 0, 62, 48, 40, 26, 14, 0, 0, 62, 48, 40, 14, 4, 280, 0, 55, 25, 0, 28, 10, 280, 0, 55, 25, 0, 8, 6, 0, 0, 40, 50, 60, 16, 12, 0, 0, 40, 50, 60, 6, 10, 0, 250, 30, 60, 0, 12, 20, 0, 250, 30, 60, 0, 6, 10, 100, 0, 30, 64, 0, 12, 20, 100, 0, 30, 64, 0, 8, 10, 100, 200, 35, 0, 0, 16, 20, 100, 200, 35, 0, 0, 14, 10, 0, 0, 62, 64, 0, 28, 20, 0, 0, 62, 64, 0, });
//int* ben_giay = ({ 6, 6, 0, 180, 0, 50, 0, 50, 12, 12, 0, 180, 0, 50, 0, 50, 6, 8, 0, 0, 0, 54, 30, 55, 12, 16, 0, 0, 0, 54, 30, 55, 6, 6, 0, 220, 0, 46, 20, 0, 12, 12, 0, 220, 0, 46, 20, 0, 2, 12, 0, 130, 0, 35, 0, 80, 4, 24, 0, 130, 0, 35, 0, 80, 2, 4, 0, 0, 200, 30, 60, 0, 4, 8, 0, 0, 200, 30, 60, 0, 2, 4, 0, 0, 180, 30, 65, 0, 4, 8, 0, 0, 180, 30, 65, 0, 2, 4, 0, 80, 180, 0, 60, 0, 4, 8, 0, 80, 180, 0, 60, 0, 6, 0, 6, 0, 0, 54, 65, 0, 12, 0, 12, 0, 0, 54, 65, 0, });
//int* ben_yeudoi = ({ 10, 10, 250, 0, 60, 35, 0, 20, 20, 250, 0, 60, 35, 0, 10, 10, 0, 0, 66, 40, 15, 20, 20, 0, 0, 66, 40, 15, 10, 10, 300, 0, 55, 25, 0, 20, 20, 300, 0, 55, 25, 0, 10, 10, 0, 0, 40, 45, 30, 20, 20, 0, 0, 40, 45, 30, 10, 10, 0, 300, 40, 55, 0, 20, 20, 0, 300, 40, 55, 0, 10, 10, 0, 250, 40, 57, 0, 20, 20, 0, 250, 40, 57, 0, 10, 10, 100, 250, 0, 57, 0, 10, 10, 0, 0, 66, 57, 0, 20, 20, 0, 0, 66, 57, 0, });
//int* ben_hanglien = ({ 0, 10, 0, 0, 0, 400, 0, 0, 50, 10, 0, 20, 0, 0, 0, 400, 0, 0, 50, 10, 0, 10, 0, 0, 30, 400, 0, 0, 54, 0, 0, 20, 0, 0, 30, 400, 0, 0, 54, 0, 0, 10, 0, 0, 0, 400, 0, 0, 50, 10, 0, 20, 0, 0, 0, 400, 0, 0, 50, 10, 0, 10, 0, 0, 0, 300, 0, 0, 50, 20, 0, 20, 0, 0, 0, 300, 0, 0, 50, 20, 20, 12, 0, 0, 30, 0, 400, 0, 70, 0, 40, 24, 0, 0, 30, 0, 400, 0, 70, 0, 20, 10, 0, 0, 0, 200, 350, 0, 80, 0, 40, 20, 0, 0, 0, 200, 350, 0, 80, 0, 20, 10, 0, 0, 0, 250, 400, 0, 75, 0, 40, 20, 0, 0, 0, 250, 400, 0, 75, 0, 20, 0, 20, 30, 30, 0, 0, 0, 0, 0, 40, 0, 40, 30, 30, 0, 0, 0, 0, 0, });
//

int* ben_vukhi = ({ 20, 0, 56, 0, 120, 0, 0, 50, 0,
    40, 0, 56, 0, 120, 0, 0, 50, 0, 22, 0,
    60, 0, 240, 0, 60, 0, 0, 44, 0,
    60, 0, 240, 0, 60, 0, 0, 20, 0,
    0, 60, 0, 0, 72, 51, 0, 40, 0,
    0, 40, 0, 0, 72, 51, 0, 24, 0,
    63, 0, 240, 0, 0, 0, 22, 48, 0,
    63, 0, 240, 0, 0, 0, 22, 20, 0,
    52, 0, 150, 0, 72, 0, 0, 40, 0,
    52, 0, 150, 0, 72, 0, 0, 18, 0,
 40, 0, 0, 80, 0, 70, 0, 36, 0, 32, 0, 0, 80, 0, 70, 0, 20, 0, 0, 50, 140, 0, 0, 50, 0, 40, 0, 0, 50, 140, 0, 0, 50, 0, 20, 0, 0,
 65, 0, 160, 0, 50, 0, 40, 0, 0,
 58, 0, 160, 0, 50, 0, 20, 0, 0, 48, 140, 140, 0, 0, 0, 40, 0, 0, 48, 140, 140, 0, 0, 0, 22, 20, 63,
 58, 0, 0, 0, 0, 0, 44, 40, 63, 53, 0, 0, 0, 0, 0, });

//int* ben_ao = ({
//    22, 14, 400, 0, 100, 0, 35,
//    44, 28, 400, 0, 100, 0, 35,
//    22, 14, 0, 0, 110, 40, 40, 44, 28, 0, 0, 110, 40, 40, 24, 12, 150, 0, 80, 0, 20, 48, 24, 150, 0, 80, 0, 20, 20, 14, 0, 0, 60, 50, 72, 40, 28, 0, 0, 60, 50, 72, 12, 24, 0, 320, 40, 68, 0, 24, 48, 0, 320, 40, 68, 0, 12, 24, 0, 220, 45, 75, 0, 24, 48, 0, 220, 45, 75, 0, 14, 24, 135, 0, 55, 70, 0, 28, 48, 135, 0, 55, 70, 0, 24, 24, 0, 0, 110, 75, 0, 48, 48, 0, 0, 110, 75, 0, });

int* ben_ao = ({
    22, 14, 300, 0, 100, 0, 35,
    44, 28, 300, 0, 100, 0, 35,
    22, 14, 0, 0, 110, 40, 40, 44, 28, 0, 0, 110, 40, 40, 24, 12, 350, 0, 80, 0, 20, 48, 24, 350, 0, 80, 0, 20, 20, 14, 0, 0, 60, 50, 72, 40, 28, 0, 0, 60, 50, 72, 12, 24, 0, 380, 40, 68, 0, 24, 48, 0, 380, 40, 68, 0, 12, 24, 0, 400, 45, 75, 0, 24, 48, 0, 400, 45, 75, 0, 14, 24, 200, 0, 55, 70, 0, 28, 48, 200, 0, 55, 70, 0, 24, 24, 0, 0, 110, 75, 0, 48, 48, 0, 0, 110, 75, 0, });


int* ben_non = ({ 12, 6, 200, 0, 60, 40, 0, 24, 12, 200, 0, 60, 40, 0, 12, 6, 0, 0, 62, 48, 40, 26, 14, 0, 0, 62, 48, 40, 14, 4, 280, 0, 55, 25, 0, 28, 10, 280, 0, 55, 25, 0, 8, 6, 0, 0, 40, 50, 60, 16, 12, 0, 0, 40, 50, 60, 6, 10, 0, 250, 30, 60, 0, 12, 20, 0, 250, 30, 60, 0, 6, 10, 100, 0, 30, 64, 0, 12, 20, 100, 0, 30, 64, 0, 8, 10, 100, 200, 35, 0, 0, 16, 20, 100, 200, 35, 0, 0, 14, 10, 0, 0, 62, 64, 0, 28, 20, 0, 0, 62, 64, 0, });
int* ben_giay = ({ 6, 6, 0, 150, 0, 50, 0, 50, 12, 12, 0, 150, 0, 50, 0, 50, 6, 8, 0, 0, 0, 54, 30, 55, 12, 16, 0, 0, 0, 54, 30, 55, 6, 6, 0, 110, 0, 46, 20, 0, 12, 12, 0, 110, 0, 46, 20, 0, 2, 12, 0, 130, 0, 35, 0, 80, 4, 24, 0, 130, 0, 35, 0, 80, 2, 4, 0, 0, 135, 30, 60, 0, 4, 8, 0, 0, 135, 30, 60, 0, 2, 4, 0, 0, 100, 30, 65, 0, 4, 8, 0, 0, 100, 30, 65, 0, 2, 4, 0, 80, 150, 0, 60, 0, 4, 8, 0, 80, 100, 0, 60, 0, 6, 0, 6, 0, 0, 54, 65, 0, 12, 0, 12, 0, 0, 54, 65, 0, });
int* ben_yeudoi = ({ 10, 10, 165, 0, 60, 35, 0, 20, 20, 165, 0, 60, 35, 0, 10, 10, 0, 0, 66, 40, 15, 20, 20, 0, 0, 66, 40, 15, 10, 10, 200, 0, 55, 25, 0, 20, 20, 200, 0, 55, 25, 0, 10, 10, 0, 0, 40, 45, 30, 20, 20, 0, 0, 40, 45, 30, 10, 10, 0, 200, 40, 55, 0, 20, 20, 0, 200, 40, 55, 0, 10, 10, 0, 165, 40, 57, 0, 20, 20, 0, 165, 40, 57, 0, 10, 10, 100, 165, 0, 57, 0, 10, 10, 0, 0, 66, 57, 0, 20, 20, 0, 0, 66, 57, 0, });
int* ben_hanglien = ({ 0, 10, 0, 0, 0, 340, 0, 0, 50, 10, 0, 20, 0, 0, 0, 340, 0, 0, 50, 10, 0, 10, 0, 0, 30, 340, 0, 0, 54, 0, 0, 20, 0, 0, 30, 340, 0, 0, 54, 0, 0, 10, 0, 0, 0, 340, 0, 0, 50, 10, 0, 20, 0, 0, 0, 340, 0, 0, 50, 10, 0, 10, 0, 0, 0, 200, 0, 0, 50, 20, 0, 20, 0, 0, 0, 200, 0, 0, 50, 20, 20, 12, 0, 0, 30, 0, 240, 0, 70, 0, 40, 24, 0, 0, 30, 0, 240, 0, 70, 0, 20, 10, 0, 0, 0, 135, 300, 0, 80, 0, 40, 20, 0, 0, 0, 135, 350, 0, 80, 0, 20, 10, 0, 0, 0, 165, 340, 0, 75, 0, 40, 20, 0, 0, 0, 165, 340, 0, 75, 0, 20, 0, 20, 30, 30, 0, 0, 0, 0, 0, 40, 0, 40, 30, 30, 0, 0, 0, 0, 0, });

void taitao(object item, int abc)
{
    int pos, family, level, ran, i, j, less, value, value1, value2, value3, value4, value5, point, mau;
    object me = this_player(), ben;
    if (!clonep(item)) return;
    family = item->get_family();
    if (family == 9) family = 2;
    if (family > 8) family = 8;
    if (family <= 0) family = 8;
    level = item->get_level();
    point = level / 6 + random(5 + level / 24);
    mau = item->get_item_color();
    ben = new(get_file_name(item));

    if (item->get_equip_type()== WEAPON_TYPE && item->is_thanbinh() == 1) {
        return;
    }

    switch (item->get_equip_type())
    {
    case WEAPON_TYPE:
        switch (family)
        {
        case 1: pos = 8 * 9; break;
        case 2:
            if (item->get_weapon_type() == SWORD) pos = 4 * 9;
            else pos = 0;
            break;
        case 3:
            if (item->get_weapon_type() == SPEAR) pos = 2 * 9;
            else pos = 6 * 9;
            break;
        case 4: pos = 10 * 9; break;
        case 5: pos = 12 * 9; break;
        case 6: pos = 14 * 9; break;
        case 7: pos = 16 * 9; break;
        default: pos = 18 * 9; break;
        }
        if (level >= 80) pos += 9;
        if (pos >= sizeof(ben_vukhi)) return;
        if (item->get_weapon_type() == SWORD) { item->set("ap", ben->get("ap")); item->set("cp", ben->get("cp")); item->add("cp", ben_vukhi[pos + 1]); }
        else { item->set("cp", ben->get("cp")); item->set("ap", ben->get("ap")); item->add("ap", ben_vukhi[pos]); }
        item->set("hp", ben->get("hp"));
        item->set("mp", ben->get("mp"));
        item->set("dp", ben->get("dp"));
        item->set("pp", ben->get("pp"));
        item->set("sp", ben->get("sp"));
        ran = random(10000);
        less = 10000;
        j = 0;
        for (i = 2; i < 9; i++)
        {
            if (ben_vukhi[pos + i] != 0)
            {
                value = ben_vukhi[pos + i] * point * ran / 100000;
                less -= ran;
                j++;
                if (j >= 2)
                    ran = less;
                else
                    ran = random(less);
                switch (i)
                {
                case 2:
                    if (item->get_weapon_type() != SWORD)
                    {
                        if (abc == 1) item->add("ap", value);
                        else if (abc == 2) item->add("ap", value * 2);
                    }

                    if (item->get_name() == "Bích Vân Đao") {
                        if (item->get("ap") > 630) {
                            item->set("ap", 630);
                            item->add("ap", random(20));
                        }
                    }

                    if (item->get_name() == "Bích Vân Thương") {
                        if (item->get("ap") > 550) {
                            item->set("ap", 550);
                            item->add("ap", random(50));
                        }
                    }

                    if (item->get_name() == "Bích Vân Quyền Thủ") {
                        if (item->get("ap") > 550) {
                            item->set("ap", 550);
                            item->add("ap", random(50));
                        }
                    }

                    if (item->get_name() == "Bích Vân Tiễn") {
                        if (item->get("ap") > 520) {
                            item->set("ap", 520);
                            item->add("ap", random(10));
                        }
                    }

                    break;
                case 3:
                    if (item->get_weapon_type() == SWORD)
                    {
                        if (abc == 1) item->add("cp", value);
                        else if (abc == 2) item->add("cp", value * 2);

                        if (item->get_name() == "Thừa Ảnh Kiếm") {
                            item->add("cp", random(80));
                        }

                        if (item->get_name() == "Bích Vân Kiếm") {
                            item->add("cp", random(25));
                        }

                        
                        if (item->get_name() == "Xích Tiêu") {
                            if (item->get("cp") > 250) {
                                item->set("cp", 430 + random(190));
                            }
                        }

                    }
                    break;
                case 4:
                    item->add("hp", value);
                    break;
                case 5:
                    item->add("mp", 0);
                    break;
                case 6:
                    item->add("dp", 0);
                    break;
                case 7:
                    item->add("pp", 0);
                    break;
                case 8:
                    item->add("sp", value / 5);
                    break;
                }
                if (less <= 0) break;
            }
        }

        break;
    case ARMOR_TYPE:
        pos = (family - 1) * 14;
        if (pos < 0) pos = 0;
        if (level >= 80) pos += 7;
        if (pos >= sizeof(ben_ao)) return;
        item->set("hp", ben->get("hp"));
        item->set("mp", ben->get("mp"));
        item->set("dp", ben->get("dp"));
        item->add("dp", ben_ao[pos]);
        item->set("pp", ben->get("pp"));
        item->add("pp", ben_ao[pos + 1]);
        item->set("sp", ben->get("sp"));
        ran = random(10000);
        less = 10000;
        for (i = 2; i < 7; i++)
        {
            if (ben_ao[pos + i] != 0)
            {
                value = ben_ao[pos + i] * point * ran / 100000;
                less -= ran;
                j++;
                if (j >= 2)
                    ran = less;
                else
                    ran = random(less);
                switch (i)
                {
                case 2:
                    if (family != 6 && family != 4)
                    {
                        if (abc == 1) item->add("hp", value);
                        else if (abc == 2) item->add("hp", value * 2);
                    }
                    break;
                case 3:
                    if (family == 6 || family == 7) item->add("mp", value);
                    break;
                case 4:
                    if (abc == 1) item->add("dp", value);
                    else if (abc == 2) item->add("dp", value * 2);
                    break;
                case 5:
                    if (abc == 1) item->add("pp", value);
                    else if (abc == 2) item->add("pp", value * 2);
                    break;
                case 6:
                    if (family == 4) {
                        if (abc == 1) item->add("sp", value);
                        else if (abc == 2) item->add("sp", value * 2);
                    }
                    break;
                }
                if (less <= 0) break;
            }
        }

        //96-97
        if (item->get_level() == 96) {
            if (item->get("dp") > 700) {
                item->set("dp", 700 - random(70));
            }
        }

        if (item->get_level() == 97) {
            if (item->get("pp") > 550) {
                item->set("pp", 550 - random(55));
            }
        }

        /*AO HUYET LONG*/
        if (mau == 5) {
            switch (family) {
                //DHN
            case 1:
                if ((item->get("dp+") + item->get("dp")) > 400) {
                    item->set("dp", 400 - item->get("dp+") - random(80));

                    item->set("dp", item->get("dp") + (item->get("dp")* 20 / 100));
                }
                
                if ((item->get("hp+") + item->get("hp")) > 1300) {
                    item->set("hp", 1300 - item->get("hp+") - random(285));
                }
                
                if ((item->get("pp+") + item->get("pp")) > 380) {
                    item->set("pp", 380 - item->get("pp+") - random(38));
                }
                break;
                //TS
            case 2:
                if ((item->get("dp+") + item->get("dp")) > 750) {
                    item->set("dp", 750 - item->get("dp+") - random(200));
                }

                if ((item->get("pp+") + item->get("pp")) > 380) {
                    item->set("pp", 380 - item->get("pp+") - random(38));
                }
                break;
                //CVQ
            case 3:
                if ((item->get("dp+") + item->get("dp")) > 430) {
                    item->set("dp", 430 - item->get("dp+") - random(150));
                }
                if ((item->get("hp+") + item->get("hp")) > 1300) {
                    item->set("hp", 1300 - item->get("hp+") - random(220));
                }
                break;
                //DM
            case 4:
                if ((item->get("dp+") + item->get("dp")) > 550) {
                    item->set("dp", 550 - item->get("dp+") - random(150));
                }
                if ((item->get("pp+") + item->get("pp")) > 310) {
                    item->set("pp", 310 - item->get("pp+") - random(110));
                }
                if ((item->get("sp+") + item->get("sp")) > 230) {
                    item->set("sp", 230 - item->get("sp+") - random(150));
                }
                break;
                //MS
            case 5:
                if ((item->get("dp+") + item->get("dp")) > 400) {
                    item->set("dp", 400 - item->get("dp+") - random(150));
                }
                if ((item->get("pp+") + item->get("pp")) > 660) {
                    item->set("pp", 660 - item->get("pp+") - random(150));
                }
                break;
                //CL
            case 6:
                if ((item->get("dp+") + item->get("dp")) > 400) {
                    item->set("dp", 400 - item->get("dp+") - random(150));
                }
                if ((item->get("pp+") + item->get("pp")) > 660) {
                    item->set("pp", 660 - item->get("pp+") - random(150));
                }
                break;
                //VMC
            case 7:
                if ((item->get("dp+") + item->get("dp")) > 500) {
                    item->set("dp", 500 - item->get("dp+") - random(150));
                }
                if ((item->get("pp+") + item->get("pp")) > 600) {
                    item->set("pp", 600 - item->get("pp+") - random(150));
                }
                if ((item->get("hp+") + item->get("hp")) > 600) {
                    item->set("hp", 600 - item->get("hp+") - random(150));
                }
                if ((item->get("mp+") + item->get("mp")) > 600) {
                    item->set("mp", 600 - item->get("mp+") - random(150));
                }
                break;
            }

            item->set("hp", item->get("hp") + (item->get("hp")* 20 / 100));
            item->set("mp", item->get("mp") + (item->get("mp")* 20 / 100));
            item->set("dp", item->get("dp") + (item->get("dp")* 20 / 100));
            item->set("pp", item->get("pp") + (item->get("pp")* 20 / 100));
            item->set("ap", item->get("ap") + (item->get("ap")* 20 / 100));
            item->set("cp", item->get("cp") + (item->get("cp")* 20 / 100));
        }
        /*End*/

        break;
    case HEAD_TYPE:
        pos = (family - 1) * 14;
        if (pos < 0) pos = 0;
        if (level >= 80) pos += 7;
        if (pos >= sizeof(ben_non)) return;
        item->set("hp", ben->get("hp"));
        item->set("mp", ben->get("mp"));
        item->set("dp", ben->get("dp"));
        item->add("dp", ben_non[pos]);
        item->set("pp", ben->get("pp"));
        item->add("pp", ben_non[pos + 1]);
        item->set("sp", ben->get("sp"));
        ran = random(10000);
        less = 10000;
        j = 0;
        for (i = 2; i < 7; i++)
        {
            if (ben_non[pos + i] != 0)
            {
                value = ben_non[pos + i] * point * ran / 100000;
                less -= ran;
                j++;
                if (j >= 2)
                    ran = less;
                else
                    ran = random(less);
                switch (i)
                {
                case 2:
                    if (family != 6 && family != 4)
                    {
                        if (abc == 1) item->add("hp", value);
                        else if (abc == 2) item->add("hp", value * 2);
                    }
                    break;
                case 3:
                    if (family == 6 || family == 7) item->add("mp", value);
                    break;
                case 4:
                    if (abc == 1) item->add("dp", value);
                    else if (abc == 2) item->add("dp", value * 2);
                    break;
                case 5:
                    if (abc == 1) item->add("pp", value);
                    else if (abc == 2) item->add("pp", value * 2);
                    break;
                case 6:
                    if (family == 4) {
                        if (abc == 1) item->add("sp", value);
                        else if (abc == 2) item->add("sp", value * 2);
                    }
                    break;
                }
                if (less <= 0) break;
            }
        }


        //96-97
        if (item->get_level() == 96) {
            if (item->get("dp") > 430) {
                item->set("dp", 430 - random(43));
            }
        }

        if (item->get_level() == 97) {
            if (item->get("pp") > 400) {
                item->set("pp", 400 - random(40));
            }
        }

        /*MU HUYET LONG*/
        if (mau == 5) {
            switch (family) {
                //DHN
            case 1:
                if ((item->get("dp+") + item->get("dp")) > 300) {
                    item->set("dp", 300 - item->get("dp+") - random(120));
                }

                if ((item->get("hp+") + item->get("hp")) > 1100) {
                    item->set("hp", 1100 - item->get("hp+") - random(200));
                }

                if ((item->get("pp+") + item->get("pp")) > 200) {
                    item->set("pp", 200 - item->get("pp+") - random(50));
                }
                break;
                //TS
            case 2:
                if ((item->get("dp+") + item->get("dp")) > 500) {
                    item->set("dp", 500 - item->get("dp+") - random(220));
                }

                if ((item->get("pp+") + item->get("pp")) > 230) {
                    item->set("pp", 230 - item->get("pp+") - random(150));
                }
                break;
                //CVQ
            case 3:
                if ((item->get("dp+") + item->get("dp")) > 450) {
                    item->set("dp", 450 - item->get("dp+") - random(200));
                }

                if ((item->get("pp+") + item->get("pp")) > 230) {
                    item->set("pp", 230 - item->get("pp+") - random(150));
                }
                if ((item->get("hp+") + item->get("hp")) > 1100) {
                    item->set("hp", 1100 - item->get("hp+") - random(200));
                }
                break;
                //DM
            case 4:
                if ((item->get("dp+") + item->get("dp")) > 350) {
                    item->set("dp", 350 - item->get("dp+") - random(180));
                }

                if ((item->get("pp+") + item->get("pp")) > 300) {
                    item->set("pp", 300 - item->get("pp+") - random(150));
                }
                if ((item->get("sp+") + item->get("sp")) > 170) {
                    item->set("sp", 170 - item->get("sp+") - random(75));
                }
                break;
                //MS
            case 5:
                if ((item->get("dp+") + item->get("dp")) > 300) {
                    item->set("dp", 300 - item->get("dp+") - random(150));
                }
                if ((item->get("pp+") + item->get("pp")) > 550) {
                    item->set("pp", 550 - item->get("pp+") - random(150));
                }
                break;
                //CL
            case 6:
                if ((item->get("dp+") + item->get("dp")) > 300) {
                    item->set("dp", 300 - item->get("dp+") - random(150));
                }
                if ((item->get("pp+") + item->get("pp")) > 550) {
                    item->set("pp", 550 - item->get("pp+") - random(150));
                }
                break;
                //VMC
            case 7:
                if ((item->get("dp+") + item->get("dp")) > 300) {
                    item->set("dp", 300 - item->get("dp+") - random(150));
                }
                if ((item->get("pp+") + item->get("pp")) > 550) {
                    item->set("pp", 550 - item->get("pp+") - random(150));
                }
                if ((item->get("hp+") + item->get("hp")) > 400) {
                    item->set("hp", 400 - item->get("hp+") - random(150));
                }
                if ((item->get("mp+") + item->get("mp")) > 550) {
                    item->set("mp", 550 - item->get("mp+") - random(150));
                }
                break;
            }

            item->set("hp", item->get("hp") + (item->get("hp")* 20 / 100));
            item->set("mp", item->get("mp") + (item->get("mp")* 20 / 100));
            item->set("dp", item->get("dp") + (item->get("dp")* 20 / 100));
            item->set("pp", item->get("pp") + (item->get("pp")* 20 / 100));
            item->set("ap", item->get("ap") + (item->get("ap")* 20 / 100));
            item->set("cp", item->get("cp") + (item->get("cp")* 20 / 100));

        }
        /*End*/
        break;
    case NECK_TYPE:
        pos = (family - 1) * 20;
        if (pos < 0) pos = 0;
        if (level >= 80) pos += 10;
        if (pos >= sizeof(ben_hanglien)) return;
        item->set("hp", ben->get("hp"));
        item->set("mp", ben->get("mp"));
        item->set("dp", ben->get("dp"));
        item->set("cp", ben->get("cp"));
        item->add("cp", ben_hanglien[pos]);
        item->set("pp", ben->get("pp"));
        item->add("pp", ben_hanglien[pos + 1]);
        item->set("ap", ben->get("ap"));
        item->add("ap", ben_hanglien[pos + 2]);
        item->set("sp", ben->get("sp"));
        ran = random(10000);
        less = 10000;
        j = 0;
        for (i = 3; i < 10; i++)
        {
            if (ben_hanglien[pos + i] != 0)
            {
                value = ben_hanglien[pos + i] * point * ran / 100000;
                less -= ran;
                j++;
                if (j >= 2)
                    ran = less;
                else
                    ran = random(less);
                switch (i)
                {
                case 3:
                    if (family == 8)
                    {
                        if (abc == 1) item->add("ap", value);
                        else if (abc == 2) item->add("ap", value * 5 / 2);
                    }
                    break;
                case 4:
                    if (abc == 1) item->add("cp", value);
                    else if (abc == 2) item->add("cp", value * 2);
                    break;
                case 5:
                    if (abc == 1) item->add("hp", value);
                    else if (abc == 2) item->add("hp", value * 2);
                    break;
                case 6:
                    item->add("mp", 0);
                    break;
                case 7:
                    item->add("dp", 0);
                    break;
                case 8:
                    if (abc == 1) item->add("pp", value);
                    else if (abc == 2) item->add("pp", value * 2);
                    break;
                case 9:
                    if (family == 4) {
                        if (abc == 1) item->add("sp", value);
                        else if (abc == 2) item->add("sp", value * 2);
                    }
                    break;
                }
                if (less <= 0) break;
            }
        }
        
        
        if (item->get_level() == 105 && mau == 2) {
            switch (item->get_family())
            {
            case 1:
               //*DHN
                if ( item->get("hp") > 600) {
                    item->set("hp", 800 + random(400));
                }
                break;
            case 2:
                //*TS
                if (item->get("hp") > 450) {
                    item->set("hp", 850 + random(600));
                }
                //if (item->get("cp") > 115) {
                    //item->set("cp", random(215));
                //}
                break;
            case 3:
                //*CVQ
                if (item->get("hp") > 1200) {
                    item->set("hp", random(1200));
                }
                break;
            case 4:
                //*DM
                if (item->get("hp") > 900) {
                    item->set("hp", random(900));
                }
                break;
            case 5:
                //*MS
                if (item->get("cp") > 250) {
                    item->set("cp", random(250));
                }
                break;
            case 6:
                //*CL
                if (item->get("hp") > 900) {
                    item->set("hp", random(900));
                }
                break;
            case 7:
                //*VMC
                if (item->get("hp") > 900) {
                    item->set("hp", random(400));
                }
                break;
            }
            
            
        }

        /*HL HUYET LONG*/
        if (mau == 5) {
            switch (family) {
                //DHN
            case 1:
                if ((item->get("dp+") + item->get("dp")) > 150) {
                    item->set("dp", 150 - item->get("dp+") - random(150));
                }

                if ((item->get("hp+") + item->get("hp")) > 1200) {
                    item->set("hp", 1200 - item->get("hp+") - random(320));
                }

                break;
                //TS
            case 2:
                if ((item->get("hp+") + item->get("hp")) > 1100) {
                    item->set("hp", 1100 - item->get("hp+") - random(100));
                }

                if ((item->get("pp+") + item->get("pp")) > 200) {
                    item->set("pp", 200 - item->get("pp+") - random(100));
                }
                if ((item->get("cp+") + item->get("cp")) > 30) {
                    item->set("cp", 30 - item->get("cp+") - random(15));
                }
                break;
                //CVQ
            case 3:
                if ((item->get("hp+") + item->get("hp")) > 1150) {
                    item->set("hp", 1150 - item->get("hp+") - random(280));
                }

                if ((item->get("pp+") + item->get("pp")) > 250) {
                    item->set("pp", 250 - item->get("pp+") - random(200));
                }
                break;
                //DM
            case 4:
                if ((item->get("hp+") + item->get("hp")) > 890) {
                    item->set("hp", 890 - item->get("hp+") - random(100));
                }

                if ((item->get("pp+") + item->get("pp")) > 180) {
                    item->set("pp", 180 - item->get("pp+") - random(200));
                }
                break;
                //MS
            case 5:
                if ((item->get("cp+") + item->get("cp")) > 0 || (item->get("cp+") + item->get("cp")) >= 350) {
                    item->set("cp", random(350));
                }

                if ((item->get("pp+") + item->get("pp")) > 250) {
                    item->set("pp", 250 - item->get("pp+") - random(100));
                }
                if ((item->get("hp+") + item->get("hp")) >= 190) {
                    item->set("hp", 550 - item->get("hp+") + random(100));
                }
                break;
                //CL
            case 6:
                if ((item->get("cp+") + item->get("cp")) > 0 || (item->get("cp+") + item->get("cp")) >= 350)
                {
                    item->set("cp", random(130));
                }

                if ((item->get("pp+") + item->get("pp")) > 250) {
                    item->set("pp", 250 - item->get("pp+") - random(100));
                }
                if ((item->get("hp+") + item->get("hp")) > 600) {
                    item->set("hp", 600 - item->get("hp+") - random(100));
                }
                break;
                //VMC
            case 7:
                if ((item->get("cp+") + item->get("cp")) > 0) {
                    item->set("cp", random(100));
                }

                if ((item->get("pp+") + item->get("pp")) > 250) {
                    item->set("pp", 250 - item->get("pp+") - random(100));
                }

                if ((item->get("hp+") + item->get("hp")) > 600) {
                    item->set("hp", 600 - item->get("hp+") - random(150));
                }

                if ((item->get("mp+") + item->get("mp")) > 600) {
                    item->set("mp", 600 - item->get("mp+") - random(150));
                }
                break;
            }

            item->set("hp", item->get("hp") + (item->get("hp")* 20 / 100));
            item->set("mp", item->get("mp") + (item->get("mp")* 20 / 100));
            item->set("dp", item->get("dp") + (item->get("dp")* 20 / 100));
            item->set("pp", item->get("pp") + (item->get("pp")* 20 / 100));
            item->set("ap", item->get("ap") + (item->get("ap")* 20 / 100));
            item->set("cp", item->get("cp") + (item->get("cp")* 20 / 100));
        }
        /*End*/
        break;
    case WAIST_TYPE:
        pos = (family - 1) * 14;
        if (pos < 0) pos = 0;
        if (level >= 80 && family != 7) pos += 7;
        if (pos >= sizeof(ben_yeudoi)) return;
        item->set("hp", ben->get("hp"));
        item->set("mp", ben->get("mp"));
        item->set("dp", ben->get("dp"));
        item->add("dp", ben_yeudoi[pos]);
        item->set("pp", ben->get("pp"));
        item->add("pp", ben_yeudoi[pos + 1]);
        item->set("sp", ben->get("sp"));
        ran = random(10000);
        less = 10000;
        j = 0;
        for (i = 2; i < 7; i++)
        {
            if (ben_yeudoi[pos + i] != 0)
            {
                value = ben_yeudoi[pos + i] * point * ran / 100000;
                less -= ran;
                j++;
                if (j >= 2)
                    ran = less;
                else
                    ran = random(less);
                switch (i)
                {
                case 2:
                    if (abc == 1) item->add("hp", value);
                    else if (abc == 2) item->add("hp", value * 2);
                    break;
                case 3:
                    if (abc == 1) item->add("mp", value);
                    else if (abc == 2) item->add("mp", value * 2);
                    break;
                case 4:
                    if (abc == 1) item->add("dp", value);
                    else if (abc == 2) item->add("dp", value * 2);
                    break;
                case 5:
                    if (abc == 1) item->add("pp", value);
                    else if (abc == 2) item->add("pp", value * 2);
                    break;
                case 6:
                    if (family == 4) {
                        if (abc == 1) item->add("sp", value);
                        else if (abc == 2) item->add("sp", value * 2);
                    }
                    break;
                }
                if (less <= 0) break;
            }

           
        }

        /*YD HUYET LONG*/
        if (mau == 5) {
            switch (family) {
                //DHN
            case 1:
                if ((item->get("dp+") + item->get("dp")) > 350) {
                    item->set("dp", 350 - item->get("dp+") - random(50));
                }

                if ((item->get("hp+") + item->get("hp")) > 1100) {
                    item->set("hp", 1100 - item->get("hp+") - random(200));
                }

                if ((item->get("pp+") + item->get("pp")) > 250) {
                    item->set("pp", 250 - item->get("pp+") - random(50));
                }
                break;
                //TS
            case 2:
                if ((item->get("dp+") + item->get("dp")) > 420) {
                    item->set("dp", 420 - item->get("dp+") - random(100));
                }

                if ((item->get("pp+") + item->get("pp")) > 230) {
                    item->set("pp", 230 - item->get("pp+") - random(50));
                }
                break;
                //CVQ
            case 3:
                if ((item->get("dp+") + item->get("dp")) >= 250) {
                    item->set("dp", 250 - item->get("dp+") - random(50));
                }

                if ((item->get("pp+") + item->get("pp")) >= 250) {
                    item->set("pp", 250 - item->get("pp+") - random(50));
                }
                if ((item->get("hp+") + item->get("hp")) >= 1100) {
                    item->set("hp", 1100 - item->get("hp+") - random(50));
                }
                break;
                //DM
            case 4:
                if ((item->get("dp+") + item->get("dp")) >= 120) {
                    item->set("dp", 120 - item->get("dp+") - random(50));
                }

                if ((item->get("pp+") + item->get("pp")) >= 350) {
                    item->set("pp", 350 - item->get("pp+") - random(50));
                }
                if ((item->get("sp+") + item->get("sp")) >= 175) {
                    item->set("sp", 175 - item->get("sp+") - random(50));
                }
                break;
                //MS
            case 5:
                if ((item->get("dp+") + item->get("dp")) >= 350) {
                    item->set("dp", 350 - item->get("dp+") - random(50));
                }
                if ((item->get("pp+") + item->get("pp")) >= 450) {
                    item->set("pp", 450 - item->get("pp+") - random(50));
                }
                if ((item->get("hp+") + item->get("hp")) >= 200) {
                    item->set("hp", 200 - item->get("hp") + random(300));
                }
                break;
                //CL
            case 6:
                if ((item->get("dp+") + item->get("dp")) >= 350) {
                    item->set("dp", 350 - item->get("dp+") - random(50));
                }
                if ((item->get("pp+") + item->get("pp")) >= 450) {
                    item->set("pp", 450 - item->get("pp+") - random(50));
                }
                break;
                //VMC
            case 7:

                if ((item->get("dp+") + item->get("dp")) > 0) {
                    item->set("dp", random(120));
                }

                if ((item->get("pp+") + item->get("pp")) >= 550) {
                    item->set("pp", 550 - item->get("pp+") - random(100));
                }
                if ((item->get("hp+") + item->get("hp")) >= 400) {
                    item->set("hp", 400 - item->get("hp+") - random(100));
                }
                if ((item->get("mp+") + item->get("mp")) >= 550) {
                    item->set("mp", 550 - item->get("mp+") - random(100));
                }
                break;
            }

            item->set("hp", item->get("hp") + (item->get("hp")* 20 / 100));
            item->set("mp", item->get("mp") + (item->get("mp")* 20 / 100));
            item->set("dp", item->get("dp") + (item->get("dp")* 20 / 100));
            item->set("pp", item->get("pp") + (item->get("pp")* 20 / 100));
            item->set("ap", item->get("ap") + (item->get("ap")* 20 / 100));
            item->set("cp", item->get("cp") + (item->get("cp")* 20 / 100));
        }
        /*End*/
        break;
    case BOOTS_TYPE:
        pos = (family - 1) * 16;
        if (pos < 0) pos = 0;
        if (level >= 80) pos += 8;
        if (pos >= sizeof(ben_giay)) return;
        item->set("hp", ben->get("hp"));
        item->set("mp", ben->get("mp"));
        item->set("dp", ben->get("dp"));
        item->add("dp", ben_giay[pos]);
        item->set("pp", ben->get("pp"));
        item->add("pp", ben_giay[pos + 2]);
        item->set("sp", ben->get("sp"));
        item->add("sp", ben_giay[pos + 1]);
        ran = random(10000); //100
        less = 10000;       //10000
        j = 0;
        for (i = 3; i < 8; i++)
        {
            if (ben_giay[pos + i] != 0)
            {
                value = ben_giay[pos + i] * point * ran / 100000;
                less -= ran;
                j++;
                if (j >= 2)
                    ran = less;
                else
                    ran = random(less);
                switch (i)
                {
                case 3:
                    if (family != 6 && family != 4)
                    {
                        value = value + random(100);
                    }

                    item->add("hp", value);
                    break;
                case 4:
                    item->add("mp", 0);
                    break;
                case 5:
                    if (family != 4)
                    {
                        if (abc == 1) item->add("dp", value);
                        else if (abc == 2) item->add("dp", value * 2);
                    }
                    else
                    {
                        if (abc == 1) item->add("dp", value / 3);
                        else if (abc == 2) item->add("dp", value);
                    }
                    break;
                case 6:
                    item->add("pp", 0);
                    break;
                case 7:
                    if (family == 4)
                    {
                        if (abc == 1)
                        {
                            if (mau == 1) item->add("sp", value / 2);
                            else if (mau == 2) item->add("sp", value);
                        }
                        else if (abc == 2)
                        {
                            if (mau == 1) item->add("sp", value);
                            else if (mau == 2) item->add("sp", value * 2);
                        }
                    }
                    break;
                }
                if (less <= 0) break;
            }
        }

        //96-97
        if (item->get_level() == 96) {
            if (item->get("dp") > 300) {
                item->set("dp", 300 - random(30));
            }
        }

        if (item->get_level() == 97) {
            if (item->get("pp") > 250) {
                item->set("pp", 250 - random(25));
            }
        }

        /*GIAY HUYET LONG*/
        if (mau == 5) {
            switch (family) {
                //DHN
            case 1:
                if ((item->get("dp+") + item->get("dp")) > 200) {
                    item->set("dp", 200 - item->get("dp+") - random(100));
                }

                if ((item->get("hp+") + item->get("hp")) > 800) {
                    item->set("hp", 800 - item->get("hp+") - random(150));
                }

                break;
                //TS
            case 2:
                if ((item->get("dp+") + item->get("dp")) > 310) {
                    item->set("dp", 310 - item->get("dp+") - random(50));
                }

                if ((item->get("pp+") + item->get("pp")) > 180) {
                    item->set("pp", 180 - item->get("pp+") - random(20));
                }
                break;
                //CVQ
            case 3:
                if ((item->get("dp+") + item->get("dp")) > 150) {
                    item->set("dp", 150 - item->get("dp+") - random(50));
                }

                if ((item->get("pp+") + item->get("pp")) > 150) {
                    item->set("pp", 150 - item->get("pp+") - random(50));
                }

                if ((item->get("hp+") + item->get("hp")) > 520) {
                  item->set("hp", 520 - random(item->get("hp+")) + 150);
                }
                break;
                //DM
            case 4:
                if (item->get("hp") > 50) {
                    item->set("hp", random(70));
                }

                if ((item->get("hp+") + item->get("hp")) > 50) {
                    item->add("sp", random(70));
                }
                else {
                    if ((item->get("hp+") + item->get("hp")) > 25) {
                        item->add("sp", 200 + random(57));
                    }
                    else {
                        item->add("sp", 247 + random(10));
                    }
                }
                    
                if ((item->get("dp+") + item->get("dp")) > 60) {
                    item->set("dp", 60 - item->get("dp+") - random(50));
                }

                if ((item->get("sp+") + item->get("sp")) > 420) {
                    item->set("sp", 420 - item->get("sp+") - random(150));
                }
                break;
                //MS
            case 5:
                if ((item->get("dp+") + item->get("dp")) > 300) {
                    item->set("dp", 300 - item->get("dp+") - random(150));
                }
                if ((item->get("pp+") + item->get("pp")) > 450) {
                    item->set("pp", 450 - item->get("pp+") - random(150));
                }
                break;
                //CL
            case 6:
                if ((item->get("dp+") + item->get("dp")) > 200) {
                    item->set("dp", 200 - item->get("dp+") - random(150));
                }
                if ((item->get("pp+") + item->get("pp")) > 450) {
                    item->set("pp", 450 - item->get("pp+") - random(150));
                }
                break;
                //VMC
            case 7:
                if ((item->get("dp+") + item->get("dp")) > 170) {
                    item->set("dp", 170 - item->get("dp+") - random(50));
                }
                if ((item->get("pp+") + item->get("pp")) > 350) {
                    item->set("pp", 350 - item->get("pp+") - random(50));
                }
                if ((item->get("hp+") + item->get("hp")) > 400) {
                    item->set("hp", 400 - item->get("hp+") - random(100));
                }
                if ((item->get("mp+") + item->get("mp")) > 450) {
                    item->set("mp", 450 - item->get("mp+") - random(100));
                }
                break;
            }

            item->set("hp", item->get("hp") + (item->get("hp")* 20 / 100));
            item->set("mp", item->get("mp") + (item->get("mp")* 20 / 100));
            item->set("dp", item->get("dp") + (item->get("dp")* 20 / 100));
            item->set("pp", item->get("pp") + (item->get("pp")* 20 / 100));
            item->set("ap", item->get("ap") + (item->get("ap")* 20 / 100));
            item->set("cp", item->get("cp") + (item->get("cp")* 20 / 100));
            item->set("sp", item->get("sp") + (item->get("sp")* 20 / 100));
        }
        /*End*/
        break;
    }
}
/*
void giamngoc( object item )
{
    int cap, nhat, nhat1, nhat2, nhat3, nhat4, nhat5, nhat6, nhat7, nhat9, nhat10;
    object nhat8;
    string ngoc, ngoc123, *ngocben, ben, ben1, ben2, ben3, ben4, ben5, ben6, ben7, ben8, ben9, ben10;
    string bennhat1,bennhat2,bennhat3,bennhat4,bennhat5,bennhat6,bennhat7,bennhat8,bennhat9,bennhat10;
    string *ngoc8 = ({"8","8","8","8","8","8","8","8","8","8"});
    if( !clonep(item) ) return;
    ngoc = item->get("make");
    if (ngoc==0) ngoc = "";
    cap = strlen(ngoc);
    ben1 = "item/93/9301"->get_diamond_type(); ben2 = "item/93/9302"->get_diamond_type();
    ben3 = "item/93/9303"->get_diamond_type(); ben4 = "item/93/9304"->get_diamond_type();
    ben5 = "item/93/9305"->get_diamond_type(); ben6 = "item/93/9306"->get_diamond_type();
    ben7 = "item/93/9307"->get_diamond_type(); ben8 = "item/93/9308"->get_diamond_type();
    ben9 = "item/93/9309"->get_diamond_type(); ben10 = "item/93/9310"->get_diamond_type();
    bennhat1 = "item/93/9301"->get_diamond_index(); bennhat2 = "item/93/9302"->get_diamond_index();
    bennhat3 = "item/93/9303"->get_diamond_index(); bennhat4 = "item/93/9304"->get_diamond_index();
    bennhat5 = "item/93/9305"->get_diamond_index(); bennhat6 = "item/93/9306"->get_diamond_index();
    bennhat7 = "item/93/9307"->get_diamond_index(); bennhat8 = "item/93/9308"->get_diamond_index();
    bennhat9 = "item/93/9309"->get_diamond_index(); bennhat10 = "item/93/9310"->get_diamond_index();
//	nhat1 = "item/93/9301"->get_diamond_add(); nhat2 = "item/93/9302"->get_diamond_add();
//	nhat3 = "item/93/9303"->get_diamond_add(); nhat4 = "item/93/9304"->get_diamond_add();
//	nhat5 = "item/93/9305"->get_diamond_add(); nhat6 = "item/93/9306"->get_diamond_add();
//	nhat7 = "item/93/9307"->get_diamond_add(); nhat8 = "item/93/9308"->get_diamond_add();
//	nhat9 = "item/93/9309"->get_diamond_add(); nhat10 = "item/93/9310"->get_diamond_add();
            if ( ngoc8[cap]==bennhat8 )
            {
            nhat8 = new("item/93/9308");
            nhat8->set_level(cap);
            item->add(ben8, -nhat8->get_diamond_add());
        //    ngoc -= bennhat8;
        //	ngoc123 = replace_string(ngoc, ngoc8[cap],"");
            item->set("make", ngoc);
            }
}*/