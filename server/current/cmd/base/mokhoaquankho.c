


// 函数：命令处理
int main( object me, string arg)
{
        string blocking = "block";
        string unblock = "unblock";
        string key = "passquankho";
        string status = "statusQuanKho";

        string pass;

        if ( arg )
        {
        	pass = me->get_save(key);

            if(arg == pass) {
        	    me->set_save(status,unblock);
                tell_user( me, "Đã mở khóa.");	
                notify( "Đã mở khóa" );
			}
            else{
            notify( "Mật khẩu không đúng, vui lòng kiểm tra lại." );
            
			}
        	return 1;
        }

        return 1;
}
