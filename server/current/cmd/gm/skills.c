
// 函数：命令处理
int main( object me, string arg )
{
        mapping skls;
        object who = me;
        string *name, file;
        int skill, i, size;

        if( is_player(me) ) 
        {
                notify( "。" );
		return 1;
        }

        if( arg && !( who = find_any_char(arg) ) ) 
        {
                notify( "Bạn không thể tìm thấy người này。" );
		return 1;
        }

        if( !sizeof( skls = who->get_skill_dbase() ) )
        {
                tell_user( me, who->get_name() + "Không có bất kỳ kỹ năng nào。" );
		return 1;
        }
        
        name = sort_array( keys(skls), 1 );
        tell_user( me, who->get_name() + "Kỹ năng：" );
        for( i = 0, size = sizeof(name); i < size; i ++ )
        {
                skill = to_int( name[i] );
                file = SKILL->get_skill_file(skill);
                file = load_object(file) ? file->get_name() : "－－－－";
                tell_user( me, "%s %-12s %3d/%5d", name[i], file, who->get_skill(skill), who->get_skill_degree(skill) );
        }

        return 1;
}
