
void can_perform( object me )
{
        __DIR__ "00900"->can_perform(me);
}

void remove_perform( object me )
{
        send_user(me, "%c%w%w", 0x50, 0xffff, 00900);
}
