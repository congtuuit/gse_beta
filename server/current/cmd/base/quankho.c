
// 函数：命令处理
int main( object me, string arg)
{
        string blocking = "block";
        string unblock = "unblock";
        string key = "passquankho";
        string status = "statusQuanKho";

        if ( arg )
        {
        	me->set_save(key,arg);
        	me->set_save(status,blocking);
            tell_user( me, "Đã thiết lập mật khẩu thành công.");	
            notify( "Đã thiết lập mật khẩu thành công" );
        	return 1;
        }

        return 1;
}

void do_block( object me){
    string blocking = "block";
    string unblock = "unblock";
    string key = "passquankho";
    string status = "statusQuanKho";
    string pass;

    pass = me->get_save(key);

    if(pass){
        me->set_save(status,blocking);
	}

}