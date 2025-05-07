
inherit RESOURCE;

void create()
{
        set_name("%s");
        set("time", 1);
        set_reset_file("/sys/item/stuff");	// 函数：Thiết lập 刷新文件
        set_tool_type(16);			// 函数：Thiết lập 工具类型
        set_pf_name("采矿");			// 函数：Thiết lập 技能名称
        set_stuff_number(%d);			// 函数：Thiết lập 资源编号
        set_stuff_number2(212);			// 函数：附加资源编号
        set_tool_level(%d);			// 函数：Thiết lập 工具等级
        set_reset_time(%d);			// 函数：Thiết lập 刷新时间
        set_skill_exp(0);			// 函数：Thiết lập 采集经验奖励
        set_skill_level(%d);			// 函数：Thiết lập 对应的技能等级
        set_this_skill(670);			// 函数：Thiết lập 对应的技能类型
        set_char_picid(%d);			// 函数：Thiết lập 人物造型
        setup();
}