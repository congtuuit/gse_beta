
// 函数：能否特殊指令
void can_perform(object me)
{
        //	Chiến đấu
        // send_user( me,"%c%c%c%w%w%w%w%w%c%s",0xa5,5,5,00014,00015,00061,00900,00999,15,"Chiến Đấu với 1 số kỹ năng và động tác thường dùng đến, bao gồm tự động xạ kích, tự động công kích, sử dụng pháp bảo và sử dụng tín vật.");
        send_user(me, "%c%c%c%w%w%w%w%w%c%s", 0xa5, 5, 5, 00014, 00015, 00061, 00900, 00999, 15, "Chiến Đấu với 1 số kỹ năng và động tác thường dùng đến, bao gồm tự động xạ kích, tự động công kích, sử dụng pháp bảo và sử dụng tín vật.");
        //	Truy tìm
        send_user(me, "%c%c%c%w%w%w%c%s", 0xa5, 5, 3, 00031, 00032, 00041, 10, "Truy tìm Người chơi 1 số kỹ năng phải dùng đến khi thực hiện nhiệm vụ sứ mệnh và nhiệm vụ phụ tá.");
        //	Động tác
        send_user(me, "%c%c%c%w%w%w%w%w%c%s", 0xa5, 5, 5, 00012, 00051, 00011, 00021, 00022, 13, "Động tác 1 số kỹ năng và động tác người chơi thường dùng, bao gồm bày bán, bắt Bảo Thú, đi theo, đẩy thi thể và vứt bỏ thi thể.");
        
        //	Hệ thống
        // send_user( me,"%c%c%c%w%w%c%s",0xa5,5,2,00099, 00098,13,"Hệ thống với 1 số kỹ năng giúp đỡ người chơi trong quá trình hành tẩu giang hồ.");

        send_user( me,"%c%c%c%w%w%c%s",0xa5,5,2,00099, 00098,13,"Hệ thống với 1 số kỹ năng giúp đỡ người chơi trong quá trình hành tẩu giang hồ.");

        // if (is_god(me))
        // {
        //         // send_user(me, "%c%c%c%w%c%s", 0xa5, 5, 1, 00099, 13, "Hệ thống với 1 số kỹ năng giúp đỡ người chơi trong quá trình hành tẩu giang hồ.");

        //         // có auto
        //          send_user( me,"%c%c%c%w%w%c%s",0xa5,5,2,00099, 10099,13,"Hệ thống với 1 số kỹ năng giúp đỡ người chơi trong quá trình hành tẩu giang hồ.");

        //         // send_user(me, "%c%c%c%w%w%c%s", 0xa5, 5, 2, 00098, 00099, 13, "Hệ thống với 1 số kỹ năng giúp đỡ người chơi trong quá trình hành tẩu giang hồ.");
        // }
        // else
        // {
        //         // có auto
        //         send_user( me,"%c%c%c%w%w%c%s",0xa5,5,2,00099, 10099,13,"Hệ thống với 1 số kỹ năng giúp đỡ người chơi trong quá trình hành tẩu giang hồ.");

        //         // send_user( me,"%c%c%c%w%c%s"0xa5,5,2,00099,13,"Hệ thống với 1 số kỹ năng giúp đỡ người chơi trong quá trình hành tẩu giang hồ.");

        //         // send_user( me,"%c%c%c%w%w%c%s",0xa5,5,2,00099, 00098,13,"Hệ thống với 1 số kỹ năng giúp đỡ người chơi trong quá trình hành tẩu giang hồ.");
        // }

        __DIR__ "00011"->can_perform(me);

        __DIR__ "00014"->can_perform(me);
        __DIR__ "00015"->can_perform(me);

        __DIR__ "00012"->can_perform(me);
        //        __DIR__ "00013"->can_perform(me);

        __DIR__ "00021"->can_perform(me);
        __DIR__ "00022"->can_perform(me);

        __DIR__ "00031"->can_perform(me);
        __DIR__ "00032"->can_perform(me);

        __DIR__ "00041"->can_perform(me);
        __DIR__ "00051"->can_perform(me);
        __DIR__ "00061"->can_perform(me);

        __DIR__ "00098"->can_perform(me);

        __DIR__ "00099"->can_perform(me);

        //__DIR__ "10010"->can_perform(me);
        // __DIR__ "00101"->can_perform(me);
        //    __DIR__ "00075"->can_perform(me);
}

// 函数：删除特殊指令
void remove_perform(object me)
{
        send_user(me, "%c%w%w", 0x50, 0xffff, 00011);
        send_user(me, "%c%w%w", 0x50, 0xffff, 00012);
        send_user(me, "%c%w%w", 0x50, 0xffff, 00013);
        send_user(me, "%c%w%w", 0x50, 0xffff, 00014);
        send_user(me, "%c%w%w", 0x50, 0xffff, 00015);
        send_user(me, "%c%w%w", 0x50, 0xffff, 00021);
        send_user(me, "%c%w%w", 0x50, 0xffff, 00022);

        send_user(me, "%c%w%w", 0x50, 0xffff, 00031);
        send_user(me, "%c%w%w", 0x50, 0xffff, 00032);

        send_user(me, "%c%w%w", 0x50, 0xffff, 00041);
        send_user(me, "%c%w%w", 0x50, 0xffff, 00051);
}
