
#include <equip.h>

// 函数：命令处理
int main( object me, string arg )
{
        object *inv, obj, who = me;
        string str, result = "";
        int len, i, size;

        if( is_player(me) ) 
        {
                notify( "Bạn không có đủ quyền。" );
		return 1;
        }

        if( arg && !( who = find_any_char(arg) ) ) 
        {
                notify( "Bạn không thể tìm người đàn ông này.。" );
		return 1;
        }

        tell_user( me, who->get_name() + "Nó được trang bị.：" );
        if( objectp( obj = who->get_equip(HEAD_TYPE) ) ) tell_user( me, 
                sprintf( "Mũ.：(%d)%s %x# [%s]", get_d(obj), obj->get_name(), getoid(obj), obj->get_user_id()) );
        if( objectp( obj = who->get_equip(NECK_TYPE) ) ) tell_user( me, 
                sprintf( "HL：(%d)%s %x# [%s]", get_d(obj), obj->get_name(), getoid(obj), obj->get_user_id()));
        if( objectp( obj = who->get_equip(WEAPON_TYPE) ) ) tell_user( me, 
                sprintf( "Vũ khí：(%d)%s %x# [%s]", get_d(obj), obj->get_name(), getoid(obj), obj->get_user_id()));
        if( objectp( obj = who->get_equip(ARMOR_TYPE) ) ) tell_user( me, 
                sprintf( "Áo：(%d)%s %x# [%s]", get_d(obj), obj->get_name(), getoid(obj), obj->get_user_id()));
        if( objectp( obj = who->get_equip(WAIST_TYPE) ) ) tell_user( me, 
                sprintf( "YD：(%d)%s %x# [%s]", get_d(obj), obj->get_name(), getoid(obj), obj->get_user_id()));
        if( objectp( obj = who->get_equip(BOOTS_TYPE) ) ) tell_user( me, 
                sprintf( "Giày：(%d)%s %x# [%s]", get_d(obj), obj->get_name(), getoid(obj), obj->get_user_id()));
        if( objectp( obj = who->get_equip(HAND_TYPE) ) ) tell_user( me, 
                sprintf( "Pháp bảo：(%d)%s %x# [%s]", get_d(obj), obj->get_name(), getoid(obj), obj->get_user_id()));

        if( !sizeof_inventory(who, 1, MAX_CARRY) ) 
        {
                tell_user( me,  "%s Không có gì trên người.。", who->get_name() );
		return 1;
        }

        inv = all_inventory(who, 1, MAX_CARRY);
        size = sizeof(inv);
        for( i = 0, len = 0; i < size; i ++ )
        {
                if( !inv[i]->is_combined() )
                        str = sprintf( "(%d)%s %x# [%s]", get_d( inv[i] ), inv[i]->get_name(), getoid( inv[i] ) , inv[i]->get_user_id());
                else    str = sprintf( "(%d)%s:%d %x# [%s]", get_d( inv[i] ), inv[i]->get_name(), inv[i]->get_amount(), getoid( inv[i] ), inv[i]->get_user_id());
                len += strlen(str) + 2;
                if( len >= OUTPUT_WIDTH )
                {
                        len = strlen(str);
                        result = sprintf( "%s\n%s ", result, str );
                }
                else    result = sprintf( "%s%s ", result, str );
        }
        tell_user( me, "%s Cơ thể đã：\n%s", who->get_name(), result );

        return 1;
}
