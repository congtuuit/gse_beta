
// 自动生成：/make/equip/makesuit

#include <equip.h>
#include <level.h>
#include <item.h>

inherit ARMOR;
//套装组件标志
int is_suit()	{ return 1;}	
//第几套
int get_equip_serial() { return 1; }	//第几套
// 函数：适用门派
int get_family() { return 7; }
//套装名字
string get_suit_name() { return "Linh Hồ"; }
// 函数：构造处理
void create()
{
        set_name("Linh hồ bì y");
        set_picid_1(6162);
        set_picid_2(6162);

        set_level(65);
        set_value(15000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 154);
        set("cp+", 0);
        set("pp+", 255);
        set("sp+", 0);
        set("hp+", 70);
        set("mp+", 127);
	set_item_color(3);	//紫色
	set_bind(4);		//捡取绑定
	set_hide(0);		//已鉴定
        setup();
}

// 函数：获取描述
string get_desc()
{
        return "Linh hồ皮衣";
}

// 函数：获取套装描述
string get_suit_desc()
{
        return "Linh hồ套装其中之一,相传穿上\n全套就会拥有神秘的力量";
}

