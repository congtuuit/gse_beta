

inherit RESOURCE;

// 函数：构造处理
void create()
{
	set_char_picid(%d);			// 函数：Thiết lập 人物造型
        set_name("%s");			// 函数：Thiết lập 称谓
        set("time", 1+random(3));		// 函数：Thiết lập 资源量
        set_reset_file("/sys/item/stuff3");	// 函数：Thiết lập 刷新文件
        set_tool_type(21);			// 函数：Thiết lập 工具类型
        set_pf_name("食材");			// 函数：Thiết lập 技能名称
        set_stuff_number(%d);			// 函数：Thiết lập 资源编号
        set_tool_level(0);			// 函数：Thiết lập 工具等级
        set_reset_time(600);			// 函数：Thiết lập 刷新时间
        set_skill_exp(%d);			// 函数：Thiết lập 采集经验奖励
        set_skill_level(%d);			// 函数：Thiết lập 对应的技能等级
        set_this_skill(610);			// 函数：Thiết lập 对应的技能类型
        setup();
}