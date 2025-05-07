inherit ITEM;
inherit COMBINED;
inherit USABLE;

int get_item_color() { return 1; }

void create()
{
        set_name("Bánh Chưng");
        set_picid_1(3301);
        set_picid_2(3301);
        set_amount(1);
        set_value(60);
}

void reset()
{
        if( gone_time( get_drop_time() ) > 3000 )
        {
            remove_from_scene();
            destruct( this_object() );
        }
}

string get_desc() 
{ 
        return "Một trong những loại bánh đặc trưng cho ngày Tết."; 
}
