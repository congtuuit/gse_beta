
// 函数：命令处理
int main(object me, string arg)
{
        int which;

        if (is_player(me))
        {
                notify("。");
                return 1;
        }

        if (!arg || arg == "")
        {
                tell_user(me, "Phương pháp mật mã：%d", get_crypt_code());
                return 1;
        }

        which = to_int(arg);
        set_crypt_code(which);

        tell_user(me, "Thiết lập 加密方法：%d", get_crypt_code());

        return 1;
}

int get_crypt_code()
{
        return get_crypt_code();
}

int set_crypt_code(int i)
{
        return set_crypt_code(i);
}