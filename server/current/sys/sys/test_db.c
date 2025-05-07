#include <time.h>

int get_yuanbao(object me) {
	return me->get_save("yuanbao");
}

int set_yuanbao(object me, int yuanbao) {
	return me->set_save("yuanbao", yuanbao);
}

int add_yuanbao(object me, int yuanbao) {
	return me->add_save("yuanbao", yuanbao);
}

int get_yuanbao_block(object me) {
	return me->get_save("yuanbao_block");
}

int set_yuanbao_block(object me, int yuanbao) {
	return me->set_save("yuanbao_block", yuanbao);
}

int add_yuanbao_block(object me, int yuanbao) {
	return me->add_save("yuanbao_block", yuanbao);
}