inherit ITEM;
inherit COMBINED;

int get_item_color() { return 1; }

// 函数：构造处理
void create()
{
        set_name("装着坏大熊的神奇葫芦");
        set_picid_1(4271);
        set_picid_2(4271);
	set_amount(1);
        set_value(50);
}

// 函数：获取描述
string get_desc() 
{ 
        return "神奇的葫芦，\n里面装着妄图偷抢Dưa hấu的坏大熊，\n将它交给Dưa hấu伯伯教训吧。"; 
}
