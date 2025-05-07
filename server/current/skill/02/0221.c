
inherit SKILL;

void create() 
{ 
        set_number(0221);
        set_name( "Thiên La Đao Pháp" );
}

void can_perform( object me )
{
	__DIR__ "02210"->can_perform(me);
        __DIR__ "02211"->can_perform(me);
        __DIR__ "02212"->can_perform(me);
        __DIR__ "02213"->can_perform(me);
        __DIR__ "02214"->can_perform(me);
        __DIR__ "02215"->can_perform(me);
        __DIR__ "02216"->can_perform(me);
		__DIR__ "02217"->can_perform(me);
		__DIR__ "02218"->can_perform(me);
}

void remove_perform( object me )
{
	    send_user( me, "%c%w%w", 0x50, 0xffff, 02210 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02211 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02212 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02213 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02214 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02215 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02216 );
}

void recount_char( object me ) {
    USER_ENERGY_D->count_ap(me);
    USER_ENERGY_D->count_dp(me);
    USER_ENERGY_D->count_hit_rate(me); 
}

string get_desc() 
{
        return "[Thiên La Đao Pháp]Chiêu thức Đao pháp do tổ sư Thái Hư Chân Nhân sáng lập. Mỗi cấp gia tăng 8 điểm sát thương Ngoại Công và 0.25% Chính Xác\n";
}
