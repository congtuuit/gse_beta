
// 自动生成：/make/item/make30

inherit ITEM;
inherit COMBINED;
// 函数：叠加上限
int get_max_combined() { return 30; }

// 函数：构造处理
void create()
{
        set_name("Thịt Heo");
        set_picid_1(4218);
        set_picid_2(4218);
        set_value(50);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Băm nhỏ，Làm bánh bao với thịt lợn"; 
}

void reset()
{
        if( gone_time( get_drop_time() ) > 2400 )    // 40分钟
        {
                remove_from_scene();
                destruct( this_object() );
        }
}