
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

// 函数：构造处理
void create()
{
        set_name( "Tử Sâm Đơn Gia Tăng" );
        set_picid_1(9167);
        set_picid_2(9167);
        set_unit( "粒" );
        set_value(50);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Tăng 10000 điểm tiềm năng, thời gian tái sử dụng 1 giây";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me )
{	
      	if( gone_time( me->get_time("eat_zs") ) < 1 )
        {
                send_user( me, "%c%s", '!', sprintf("Sử dụng Tử Sâm Đơn phải chờ %d giây", 1 - gone_time( me->get_time("eat_zs") ) ) );
                return 0;
        }        
	me->set_time( "eat_zs", time() );  
        me->add_potential(10000);
        return 1;
}
