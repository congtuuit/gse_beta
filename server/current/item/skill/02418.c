
// 自动生成：/make/item/make95

inherit "/inh/item/book3";

// 函数：构造处理
void create()
{
        set_name("Càn Khôn Nhất Khí");
        set_picid_1(9808);
        set_picid_2(9808);
        set_unit("本");
        set_value(3000);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Bộ sách ghi lại Kỹ năng cấp 150 của Cấm Vệ Quân \nSau khi sử dụng sẽ học được kĩ năng cấp 150 Bá Vương Nhất Khí \nBá Vương Thương Pháp."; 
}

// 函数：获取门派名称
string get_family_name() { return " Cấm Vệ Quân"; }

// 函数：获取技能号码
int get_skill_id() { return 0241; }

// 函数：获取技能要求等级
int get_skill_level() { return 150; }

// 函数：获取特技标志
string get_perform_id() { return "02418"; }

// 函数：获取技能名称
string get_skill_name() { return "Bá Vương Thương Pháp"; }
