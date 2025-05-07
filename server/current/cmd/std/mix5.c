#include <item.h>
#include <ansi.h>
#include <equip.h>
#include <time.h>
#include <public.h>

int check_match(object equip, object diamond);
int mix1(object me, object * item);

int exitsIndex(int * id, object * item) {
    int i;
    int mix5 = 5;
    
    for( i = 0; i < mix5; i++ ) 
    {
        if(id[i] != 0) 
        {
            return i;
        }
    }
}

int duplicate(int value, int *ids) {
    int i, count = 0;
    int mix5 = 5;

    for (i = 0; i < mix5; i++) {
        if (ids[i] != 0 && value == ids[i]) {
            count++;
        }
    }

    if (count > 1) {
        return 1;
    }

    return 0;
}

int destructItem(int * id, object * item, object me){
    int i, j;
    int mix5 = 5;
    string legend;
    string idItem = "--";
    string name = "--";

    for( i = 0; i < mix5; i++) {
         if(id[i] != 0){
            if (duplicate(id[i], id)) {

                item[i]->remove_from_user();
                destruct(item[i]);
                //tell_user(me, "double %d", id[i]);
                return 0;
            }

            idItem = item[i]->get_user_id();
            name = item[i]->get_name();
            item[i]->remove_from_user();
            destruct(item[i]);

            legend = sprintf("@Mix 5 %s ( %d ) %s %s %s", me->get_name(), me->get_number(), me->get_id(), idItem, name);
            "/sys/user/cmd"->log_item(legend);
        }
    }
    return 1;
}



int destructItem_2(int* id, object* item, object me) {
    int i, j;
    int mix5 = 5;
    string legend;
    string idItem = "--";
    string name = "--";

    for (i = 0; i < mix5; i++) {

        if (i == 2) {
            continue;
        }

        if (id[i] != 0) {
            if (duplicate(id[i], id)) {

                item[i]->remove_from_user();
                destruct(item[i]);
                return 0;
            }

            idItem = item[i]->get_user_id();
            name = item[i]->get_name();
            item[i]->remove_from_user();
            destruct(item[i]);
        }
    }
    return 1;
}


// 函数：命令处理
int main(object me, string arg) {
    object * item, who, newItem;
    string file_log, file, name, make, result, forge, index, nameItem, path = "/item/ppvacanh/";
    int * id;
    int i,d,indexItem, flag = 0, level = 0, rate = 0;
    int countItem = 0;
    int mix5 = 5;
    int level_back_item, tmp, randomRate = 0, stoneLevel, stone;

    int iTime;
    mixed* mxTime;
    iTime = time();
    mxTime = localtime(iTime);

    if (!arg) return 1;

    item = ({ 0, 0, 0, 0, 0, });  id = ({ 0, 0, 0, 0, 0, });
    randomRate = random100();

    //block
    //return 1;

    if( sscanf( arg, "%x# %x# %x# %x# %x#", id[0],id[1],id[2],id[3], id[4] ) == mix5 )
    {
       flag = 1;
    } 
    else {
       flag = 2;
	}

    notify( "Hợp thành thất bại! %d", flag);

    for( i = 0; i < mix5; i++){
        if(id[i] != 0){
            countItem ++;
        }
    }

    switch(countItem){
        case 2:
            rate = 20;
            break;
        case 3:
            rate = 30;
            break;
        case 4:
            rate = 50;
            break;
        case 5:
            rate = 91;
            break;
    }

    if( me->get_vip() && !me->get_save_2("vip_package.trial"))
    {
        if(rate > 30){
            rate += 5;
        }
    }

    //hop linh thach
    for( i = 0; i < mix5; i ++ ) 
    {
        if(id[i] != 0) {
            if( !objectp( item[i] = present( sprintf("%x#", id[i]), me, 1, MAX_CARRY * 4 ) ) )    // 物品是否存在？
            {
                return 1;
            }

            if(i < mix5 - 1){
                if (item[i]==item[i+1]) return 1;
            }
       }
    }

    if (countItem > 1) {
        for( i = 0; i < mix5; i ++ ) 
        {
            if(id[i] != 0) 
            {
                level = item[i]->get_level();
            }
        }

        if(level > 0) 
        {
            indexItem = exitsIndex(id, item);

            if(item[indexItem]->is_diamond_2())
            {
                if (level>=10)
                {
                    notify( "Tổng hợp không thể vượt quá cấp 10。" );
                    return 1;
                }    

                for( i = 1; i < mix5; i ++ ) {
                    if(id[i] != 0) 
                    {
                        if (level!=item[i]->get_level())
                        {
                            notify( "Tổng hợp phải cùng loại。" );
                            return 1;
                        }

                        if (item[indexItem]->get_name() != item[i]->get_name()) {
                            notify("Tổng hợp phải cùng loại。");
                            return 1;
                        }
                    }
                }

                if (me->get_strength()<5)
                {
                    notify( "Thể lực của bạn quá thấp。" );
                    return 1;
                }  
        
                if (countItem < 4) {
                    rate -= (countItem * 5);
                }

                if (me->get_vip()) {
                    rate += 5;
                }

                if(randomRate < rate){
            
                    me->add_strength(-5);
                    file = get_file_name(item[indexItem]);

                    if (!destructItem(id, item, me)) {
                        notify("Hợp thành thất bại!");
                        return 0;
                    }

                    //new code
                    newItem = new(file);
                    newItem->set_level(level + 1);
                    tmp = newItem->move(me, -1);
                    if (!tmp)
                    {
                        destruct(newItem);
                        return;
                    }

                    newItem->add_to_user(tmp);

                    write_user( me, ECHO "Kết hợp thành công và nhận được %s.", newItem->get_name());
                    notify( "Kết hợp thành công và nhận được %s.", newItem->get_name());

                    file_log = sprintf("/item/Mix5Data_%d%02d%02d.dat", mxTime[TIME_YEAR], mxTime[TIME_MON] + 1, mxTime[TIME_MDAY]);
                    log_file(file_log, sprintf("%s %s (%d) %s Mix ngoc %s dung %d ti le %d \n", short_time(),me->get_name(), me->get_number(), me->get_id(), newItem->get_name(), countItem, rate));
                
                }
                else {
                    notify( "Hợp thành thất bại!");
                    destructItem(id, item, me);
                }

                return 1;
            }

            if(item[indexItem]->is_back_item())
            {
                level_back_item = item[indexItem]->level();
                if (level_back_item>=3)
                {
                    notify( "Tổng hợp không thể vượt quá." );
                    return 1;
                } 

                for( i = 1; i < mix5; i ++ ) {
                    if(id[i] != 0) 
                    {
                        if (level_back_item!=item[i]->level())
                        {
                            notify( "Tổng hợp phải cùng loại。" );
                            return 1;
                        }

                        if (item[indexItem]->get_name() != item[i]->get_name()) {
                            notify("Tổng hợp phải cùng loại。");
                            return 1;
                        }
                    }
                }

                if (me->get_strength()<5)
                {
                    notify( "Thể lực của bạn quá thấp。" );
                    return 1;
                }  

                name = item[indexItem]->get_code_item();

                switch (level_back_item)
                {
                    case 0:
                        path += name +"/"+ name+"_1";
                        break;
                    case 1:
                         path += name +"/"+ name+"_2";
                        break;
                    case 2:
                         path += name +"/"+ name+"_3";
                        break;
                }

                if (countItem < 4) {
                    rate = 5;
                }

                if (rate >= 85) {
                    rate = 100;
                }

                if (countItem >= 5) {
                    rate = 105;
                }

                if(randomRate < rate)
                {
                    me->add_strength(-5);

                    if (!destructItem(id, item, me)) {
                        notify("Hợp thành thất bại!");
                        return 0;
                    }

                    newItem = new(path);
                    tmp = newItem->move(me,-1);
                    if ( !tmp )
                    {
                        destruct(newItem);
                        return ;    
                    }
                    
                    newItem->add_to_user(tmp);

                    result = sprintf(HIY "Chúc mừng người chơi %s ghép thành công %s!", me->get_name(),newItem->get_name() );
                    write_user( me, ECHO "Kết hợp thành công và nhận được %s", newItem->get_name());
                    notify( "Kết hợp thành công và nhận được %s", newItem->get_name());
                    USER_D->user_channel(result);

                    file_log = sprintf("/item/Mix5Data_%d%02d%02d.dat", mxTime[TIME_YEAR], mxTime[TIME_MON] + 1, mxTime[TIME_MDAY]);
                    log_file(file_log, sprintf("%s %s (%d) %s Mix phi phong/canh %s dung %d ti le %d \n", short_time(), me->get_name(), me->get_number(), me->get_id(), newItem->get_name(), countItem, rate));

                }
                else {
                    notify( "Hợp thành thất bại!");
                    destructItem(id, item, me);
                }

                return 1;
            }

            if (item[indexItem]->get_item_type() == ITEM_TYPE_DIAMOND_HOLE) {
                stoneLevel = HOLE_D->get_stone_level_by_code(item[indexItem]->get_code());

                if (stoneLevel >= 3)
                {
                    notify("Tổng hợp không thể vượt quá.");
                    return 1;
                }

                for (i = 1; i < mix5; i++) {
                    if (id[i] != 0)
                    {
                        if (stoneLevel != HOLE_D->get_stone_level_by_code(item[i]->get_code()))
                        {
                            notify("Tổng hợp phải cùng loại");
                            return 1;
                        }

                        if (item[indexItem]->get_name() != item[i]->get_name()) {
                            notify("Tổng hợp phải cùng loại");
                            return 1;
                        }
                    }
                }

                if (me->get_strength() < 5)
                {
                    notify("Thể lực của bạn quá thấp");
                    return 1;
                }

                stone = item[indexItem]->get_code() % 100;
                switch (stoneLevel)
                {
                case 1:
                    path = sprintf("item/common/stone/%d", 200 + stone);
                    break;
                case 2:
                    path = sprintf("item/common/stone/%d", 300 + stone);
                    break;
                }

                if (countItem < 4) {
                    rate -= (countItem * 6);
                }

                if (randomRate < rate) {

                    me->add_strength(-5);
                    file = get_file_name(item[indexItem]);

                    if (!destructItem(id, item, me)) {
                        notify("Hợp thành thất bại!");
                        return 0;
                    }

                    newItem = new(path);
                    tmp = newItem->move(me, -1);

                    if (!tmp)
                    {
                        destruct(newItem);
                        return;
                    }

                    newItem->add_to_user(tmp);

                    write_user(me, ECHO "Kết hợp thành công và nhận được %s.", newItem->get_name());
                    notify("Kết hợp thành công và nhận được %s.", newItem->get_name());

                    file_log = sprintf("/item/Mix5Data_%d%02d%02d.dat", mxTime[TIME_YEAR], mxTime[TIME_MON] + 1, mxTime[TIME_MDAY]);
                    log_file(file_log, sprintf("%s %s (%d) %s Mix Kết TInh Thạch %s dung %d ti le %d \n", short_time(), me->get_name(), me->get_number(), me->get_id(), newItem->get_name(), countItem, rate));

                }
                else {
                    notify("Hợp thành thất bại!");
                    destructItem(id, item, me);
                }

                return 1;
            }

            if (item[indexItem]->is_thanbinh() > 0) {
                stoneLevel = item[indexItem]->tu_chat();

                if (stoneLevel >= RAT_CAO)
                {
                    notify("Tư chất đã đạt tối đa.");
                    return 1;
                }

                for (i = 1; i < mix5; i++) {
                    if (id[i] != 0)
                    {
                        if (stoneLevel != item[i]->tu_chat() )
                        {
                            notify("Tổ hợp phải cùng tư chất");
                            return 1;
                        }

                    }
                }

                if (me->get_strength() < 5)
                {
                    notify("Thể lực của bạn quá thấp");
                    return 1;
                }

                if (id[2] == 0 || !item[indexItem]) {
                    notify("Không thể xác định vật phẩm cần nâng cấp");
                    return 1;
                }

                path = item[2]->get_next_equip();

                if (countItem < 4) {
                    rate -= (countItem * 4);
                }
                else {
                    rate = 100;
                    randomRate = 1;
                }

                if (randomRate < rate) {

                    me->add_strength(-5);

                    if (!destructItem_2(id, item, me)) {
                        notify("Hợp thành thất bại!");
                        return 0;
                    }

                    newItem = new(path);
                    tmp = newItem->move(me, -1);

                    if (!tmp)
                    {
                        destruct(newItem);
                        return;
                    }

                    newItem->add_to_user(tmp);

                    write_user(me, ECHO "Kết hợp thành công và nhận được %s.", newItem->get_name());
                    notify("Kết hợp thành công và nhận được %s.", newItem->get_name());

                    file_log = sprintf("/item/Mix5TrangBiThanKhi_%d%02d%02d.dat", mxTime[TIME_YEAR], mxTime[TIME_MON] + 1, mxTime[TIME_MDAY]);
                    log_file(file_log, sprintf("%s %s (%d) %s Mix Trang bi %s dung %d ti le %d \n", short_time(), me->get_name(), me->get_number(), me->get_id(), newItem->get_name(), countItem, rate));

                }
                else {
                    notify("Hợp thành thất bại!");
                    destructItem_2(id, item, me);
                }

                return 1;

            }
        }

	}

    

    
}   
