
private int *Effect = ({ });    // 征状存盘数据

int *get_effect_data() { return copy(Effect); }

int save()
{
        string file = this_object()->get_save_file();
        if( !stringp(file) ) return 0;
        Effect = get_effect_dbase( this_object() );
        return save_object(file);
}

int restore()
{
        string file;
        int flag;

        if( !stringp( file = this_object()->get_save_file() ) ) return 0;
        flag = restore_object(file);
        if( !arrayp(Effect) ) Effect = ({ });
        set_effect_dbase( this_object(), Effect );

        return flag;
}

int backup()
{
        string file = this_object()->get_save_file();
        if( !stringp(file) ) return 0;
        file += "_bak";    // file = sprintf( "%s.%d", file, time() );
        Effect = get_effect_dbase( this_object() );
        return save_object(file);
}
