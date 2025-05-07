#include <item.h>
#include <ansi.h>

int mix_ngoc_boi(object me);
int mix_thu_cuoi(object me);

int main(object me, string arg)
{
	object* item, who, item1, item2;
	string name, file, result, type;
	int* id;
	int i, level, d;
	if (!arg) return 1;

	item = ({ 0, 0, });  id = ({ 0, 0, });

	if (sscanf(arg, "? %s", type) != 1)
	{
		notify("Bạn muốn hợp thành đồ gì?");
		return 1;
	}

	if (type == "ngocboi") {
		return mix_ngoc_boi(me);
	}

	if (type == "thucuoi") {
		return mix_thu_cuoi(me);
	}
	return 1;
}

