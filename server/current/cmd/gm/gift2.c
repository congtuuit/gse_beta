
// 函数：命令处理
int main( object me, string arg )
{
        int con, spi, str, cps, dex;
        int con0, spi0, str0, cps0, dex0;
        int con2, spi2, str2, cps2, dex2;
        int gift;

        if( !arg || sscanf( arg, "%d %d %d %d %d", con2, spi2, str2, cps2, dex2 ) != 5 ) return 1;

        con0 = me->get_con();
        spi0 = me->get_spi();
        str0 = me->get_str();
        cps0 = me->get_cps();
        dex0 = me->get_dex();

        con = con0 + con2;
        spi = spi0 + spi2;
        str = str0 + str2;
        cps = cps0 + cps2;
        dex = dex0 + dex2;

        if( con < con0 || spi < spi0 || str < str0 || cps < cps0 || dex < dex0 ) 
        {
                notify( "不能回调属性！" );
		return 1;
        }
        if( con == con0 && spi == spi0 && str == str0 && cps == cps0 && dex == dex0 ) 
        {
                notify( "没有改变属性。" );
		return 1;
        }

/*      if( con2 > 1 || spi2 > 1 || str2 > 1 || cps2 > 1 || dex2 > 1 )
        {
                notify( "只能一点点来！" );
		return 1;
        }       */

        gift = con2 + spi2 + str2 + cps2 + dex2;

        if( gift > me->get_gift_point() ) 
        {
                notify( "没有足够道行。" );
		return 1;
        }

        me->add_gift_point( -gift );
        me->add_con_2(con2);
        me->add_spi_2(spi2);
        me->add_str_2(str2);
        me->add_cps_2(cps2);
        me->add_dex_2(dex2);

	USER_ENERGY_D->count_max_hp(me);    // 更新，没有用 count_all_prop
	USER_ENERGY_D->count_max_mp(me);
	USER_ENERGY_D->count_cp(me);    // cp/pp 影响 ap/dp, 所以放前
	USER_ENERGY_D->count_pp(me);
	USER_ENERGY_D->count_ap(me);
	USER_ENERGY_D->count_dp(me);
	USER_ENERGY_D->count_sp(me);

        tell_user(me, "Thiết lập Hoàn thành！");

        return 1;
}
