
inherit SKILL;
//强化技能标志
int is_enhance_skill() {return 1;}

// 函数：构造处理
void create() 
{ 
        set_number(0331);
        set_name( "Cường Hoá Thiên La Đao Pháp" );
}

// 函数：重计属性
void recount_char( object me ) 
{ 
//	USER_ENERGY_D->count_max_hp(me); 
	USER_ENERGY_D->count_ap(me); 
}

// 函数：获取描述
string get_desc() 
{
        return "［Cường Hoá Thiên La Đao Pháp］Gia tăng lực công kích khi sử dụng đao,mỗi cấp tăng 3 điểm.";
}
