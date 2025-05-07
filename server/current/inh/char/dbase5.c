
private static mapping mpHP = ([ ]);
private static mapping mpMP = ([ ]);
private static mapping mpAP = ([ ]);
private static mapping mpDP = ([ ]);
private static mapping mpCP = ([ ]);
private static mapping mpPP = ([ ]);
private static mapping mpSP = ([ ]);
private static mapping mpOther = ([ ]);

mapping get_temp_hp_dbase() { return copy(mpHP); }
mapping get_temp_mp_dbase() { return copy(mpMP); }
mapping get_temp_ap_dbase() { return copy(mpAP); }
mapping get_temp_dp_dbase() { return copy(mpDP); }
mapping get_temp_cp_dbase() { return copy(mpCP); }
mapping get_temp_pp_dbase() { return copy(mpPP); }
mapping get_temp_sp_dbase() { return copy(mpSP); }
mapping get_temp_other_dbase() { return copy(mpOther); }

void init_temp_hp_dbase() { mpHP = ([ ]); }
void init_temp_mp_dbase() { mpMP = ([ ]); }
void init_temp_ap_dbase() { mpAP = ([ ]); }
void init_temp_dp_dbase() { mpDP = ([ ]); }
void init_temp_cp_dbase() { mpCP = ([ ]); }
void init_temp_pp_dbase() { mpPP = ([ ]); }
void init_temp_sp_dbase() { mpSP = ([ ]); }
void init_temp_other_dbase() { mpOther = ([ ]); }

mixed get_temp_hp( string key ) { return mpHP[key]; }
mixed get_temp_mp( string key ) { return mpMP[key]; }
mixed get_temp_ap( string key ) { return mpAP[key]; }
mixed get_temp_dp( string key ) { return mpDP[key]; }
mixed get_temp_cp( string key ) { return mpCP[key]; }
mixed get_temp_pp( string key ) { return mpPP[key]; }
mixed get_temp_sp( string key ) { return mpSP[key]; }
mixed get_temp_other( string key ) { return mpOther[key]; }

mixed set_temp_hp( string key, mixed value ) { return mpHP[key] = value; }
mixed set_temp_mp( string key, mixed value ) { return mpMP[key] = value; }
mixed set_temp_ap( string key, mixed value ) { return mpAP[key] = value; }
mixed set_temp_dp( string key, mixed value ) { return mpDP[key] = value; }
mixed set_temp_cp( string key, mixed value ) { return mpCP[key] = value; }
mixed set_temp_pp( string key, mixed value ) { return mpPP[key] = value; }
mixed set_temp_sp( string key, mixed value ) { return mpSP[key] = value; }
mixed set_temp_other( string key, mixed value ) { return mpOther[key] = value; }

mixed add_temp_hp( string key, mixed value )
{
        mixed old;

        if( !( old = get_temp_hp(key) ) ) 
                return set_temp_hp(key, value);
        else    return set_temp_hp(key, old + value);
}

mixed add_temp_mp( string key, mixed value )
{
        mixed old;

        if( !( old = get_temp_mp(key) ) ) 
                return set_temp_mp(key, value);
        else    return set_temp_mp(key, old + value);
}

mixed add_temp_ap( string key, mixed value )
{
        mixed old;

        if( !( old = get_temp_ap(key) ) ) 
                return set_temp_ap(key, value);
        else    return set_temp_ap(key, old + value);
}

mixed add_temp_dp( string key, mixed value )
{
        mixed old;

        if( !( old = get_temp_dp(key) ) ) 
                return set_temp_dp(key, value);
        else    return set_temp_dp(key, old + value);
}

mixed add_temp_cp( string key, mixed value )
{
        mixed old;

        if( !( old = get_temp_cp(key) ) ) 
                return set_temp_cp(key, value);
        else    return set_temp_cp(key, old + value);
}

mixed add_temp_pp( string key, mixed value )
{
        mixed old;

        if( !( old = get_temp_pp(key) ) ) 
                return set_temp_pp(key, value);
        else    return set_temp_pp(key, old + value);
}

mixed add_temp_sp( string key, mixed value )
{
        mixed old;

        if( !( old = get_temp_sp(key) ) ) 
                return set_temp_sp(key, value);
        else    return set_temp_sp(key, old + value);
}

mixed add_temp_other( string key, mixed value )
{
        mixed old;

        if( !( old = get_temp_other(key) ) ) 
                return set_temp_other(key, value);
        else    return set_temp_other(key, old + value);
}

void delete_temp_hp( string key ) { map_delete(mpHP, key); }
void delete_temp_mp( string key ) { map_delete(mpMP, key); }
void delete_temp_ap( string key ) { map_delete(mpAP, key); }
void delete_temp_dp( string key ) { map_delete(mpDP, key); }
void delete_temp_cp( string key ) { map_delete(mpCP, key); }
void delete_temp_pp( string key ) { map_delete(mpPP, key); }
void delete_temp_sp( string key ) { map_delete(mpSP, key); }
void delete_temp_other( string key ) { map_delete(mpOther, key); }
