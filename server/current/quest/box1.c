#include <equip.h>

void check_item();

string *FileTable1 = ({
	"cash",
	"cash",
	"cash",
	"cash",
	"cash",
	"cash",
	"item/08/0001",//cql
	"item/08/0001",//cql
	"item/08/0001",//cql
	"item/08/0001",//cql
	"item/sell/0002",//mau
	"item/sell/0002",//mau
	"item/sell/0002",//mau
	"item/sell/0002",//mau
	"item/sell/0004",//mana
	"item/sell/0004",//mana
	"item/sell/0004",//mana
	"item/sell/0004",//mana
	"item/sell/0044",//tethe bao ngoc
	"item/sell/0044",//tethe bao ngoc
	"item/sell/0044",//tethe bao ngoc
	"/item/test2/block/tuiphapbao",
	"/item/test2/block/tuiphapbao",
	"/item/test2/block/tuiphapbao",
	"/item/sell/9301",
	"/item/sell/9302",
	"/item/sell/9303",
	"/item/sell/9304",
	"/item/sell/9305",
	"/item/sell/9306",
	"/item/sell/9307",
	"/item/sell/9308",
	"/item/sell/9309",
	"/item/sell/9310",
	"/item/test2/block/0007",
	"/item/test2/block/0009",
	"/item/test2/block/0033",
	"/item/test2/block/0033",
	"/item/test2/block/0033",
	"/item/test2/block/banhkem",
	"/item/test2/block/banhkem",
	"/item/test2/block/banhkem",

	"/item/common/dacuonghoa",
	"/item/common/dacuonghoa",
	"/item/common/dacuonghoa",
	"/item/common/dacuonghoa",
	"/item/common/dacuonghoa",
	"/item/common/dacuonghoa",
	"/item/common/dacuonghoa",
	"/item/common/dacuonghoa",

	"cash",
	"cash",
	"cash",
	"cash",
	"cash",
	"cash",
	"item/08/0001",//cql
	"item/08/0001",//cql
	"item/08/0001",//cql
	"item/08/0001",//cql
	"item/sell/0002",//mau
	"item/sell/0002",//mau
	"item/sell/0002",//mau
	"item/sell/0002",//mau
	"item/sell/0004",//mana
	"item/sell/0004",//mana
	"item/sell/0004",//mana
	"item/sell/0004",//mana
	"item/sell/0044",//tethe bao ngoc
	"item/sell/0044",//tethe bao ngoc
	"item/sell/0044",//tethe bao ngoc
	"/item/test2/block/tuiphapbao",
	"/item/test2/block/tuiphapbao",
	"/item/test2/block/tuiphapbao",
	"/item/sell/9301",
	"/item/sell/9302",
	"/item/sell/9303",
	"/item/sell/9304",
	"/item/sell/9305",
	"/item/sell/9306",
	"/item/sell/9307",
	"/item/sell/9308",
	"/item/sell/9309",
	"/item/sell/9310",
	"/item/test2/block/0007",
	"/item/test2/block/0009",
	"/item/test2/block/0033",
	"/item/test2/block/0033",
	"/item/test2/block/0033",
	"/item/test2/block/banhkem",
	"/item/test2/block/banhkem",
	"/item/test2/block/banhkem",
	
	"/item/common/dacuonghoa",
	"/item/common/dacuonghoa",
	"/item/common/dacuonghoa",
	"/item/common/dacuonghoa",
	"/item/common/dacuonghoa",
	"/item/common/dacuonghoa",
	"/item/common/dacuonghoa",
		"/item/pet/hon",
		"/item/pet/hon",
		"/item/pet/hon",
		"/item/pet/hon",
		"/item/pet/hon",
		"/item/pet/hon",
});

string *FileTable2 = ({
	"cash",
	"cash",
	"cash",
	"cash",
	"cash",
	"cash",
	"cash",
	"cash",
	"cash",
	"/item/mop/9512",
	"/item/mop/9522",
	"/item/mop/9532",
	"/item/mop/9542",
	"/item/mop/9552",
	"/item/mop/9562",
	"item/common/banhngot",
	"item/common/banhngot",
	"item/common/banhngot",
	"item/common/banhngot",
	"item/common/banhngot",
	"item/common/banhngot",
	"item/common/banhngot",
	"item/common/banhngot",
	"item/common/banhngot",
	"/item/95/0104",
	"/item/95/0109",
	"/item/95/0111",
	"/item/95/0121",
	"/item/95/0131",
	"/item/95/0141",
	"/item/95/0151",
	"/item/95/0161",
	"/item/95/0202",
	"/item/95/0401",
	"/item/95/0402",
	"/item/95/0403",
	"/item/95/0404",
	"/item/common/dacuonghoa",
	"/item/common/dacuonghoa",
	"/item/common/dacuonghoa",
	"/item/common/dacuonghoa",
	"/item/common/dacuonghoa",
	"/item/common/dacuonghoa",
	"/item/common/dacuonghoa",


	"item/08/0001",//cql
	"item/08/0001",//cql
	"item/08/0001",//cql
	"item/08/0001",//cql
	"item/sell/0002",//mau
	"item/sell/0002",//mau
	"item/sell/0002",//mau
	"item/sell/0002",//mau
	"item/sell/0004",//mana
	"item/sell/0004",//mana
	"item/sell/0004",//mana
	"item/sell/0004",//mana
	"item/sell/0044",//tethe bao ngoc
	"item/sell/0044",//tethe bao ngoc
	"item/sell/0044",//tethe bao ngoc
	"/item/test2/block/tuiphapbao",
	"/item/test2/block/tuiphapbao",
	"/item/test2/block/tuiphapbao",

	"/item/sell/9301",
	"/item/sell/9302",
	"/item/sell/9303",
	"/item/sell/9304",
	"/item/sell/9305",
	"/item/sell/9306",
	"/item/sell/9307",
	"/item/sell/9308",
	"/item/sell/9309",
	"/item/sell/9310",
	"/item/test2/block/0007",
	"/item/test2/block/0009",

	"/item/test2/block/0033",
	"/item/test2/block/0033",
	"/item/test2/block/0033",
	"/item/test2/block/banhkem",
	"/item/test2/block/banhkem",
	"/item/test2/block/banhkem",

	//Nhap mon
	/*"/item/95/0211",
	"/item/95/0212",
	"/item/95/0316",
	"/item/95/0317",
	"/item/95/0319",
	"/item/95/0221",
	"/item/95/0231",
	"/item/95/0222",
	"/item/95/0325",
	"/item/95/0329",
	"/item/95/0241",
	"/item/95/0251",
	"/item/95/0242",
	"/item/95/0348",
	"/item/95/0349",
	"/item/95/0261",
	"/item/95/0363",
	"/item/95/0364",
	"/item/95/0365",
	"/item/95/0368",
	"/item/95/0271",
	"/item/95/0413",
	"/item/95/0414",
	"/item/95/0417",
	"/item/95/0418",
	"/item/95/0421",
	"/item/95/0422",
	"/item/95/0423",
	"/item/95/0424",
	"/item/95/0425",
	"/item/95/0281",
	"/item/95/0501",
	"/item/95/0511",
	"/item/95/0531",
	"/item/95/0591",*/


	"/item/91/9125",
	"/item/91/9150",
	"/item/91/9160",
	"/item/91/9161",
	"/item/91/9162",
	"/item/91/9163",
	"/item/91/9164",
	"/item/91/9165",

	/*"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",
	"/item/44/4488",*/
		"/item/common/box/tukim/item/tuidacuonghoa5",
		"/item/common/box/tukim/item/tuidacuonghoa5",
		"/item/common/box/tukim/item/tuidacuonghoa5",
		"/item/common/box/tukim/item/tuidacuonghoa5",
		"/item/common/box/tukim/item/tuidacuonghoa5",
	"/item/91/9167",//tsd
	"/item/91/9167",//tsd
	"/item/91/9167",//tsd
	"/item/91/9167",//tsd
	"/item/91/9167",//tsd
	"/item/91/9167",//tsd
		"/item/test/vosongdiemphieu",
		"/item/test/vosongdiemphieu",
		"/item/test/vosongdiemphieu",
		"/item/test/vosongdiemphieu",
		"/item/test/vosongdiemphieu",
		"/item/test/vosongdiemphieu",
		"/item/test/vosongdiemphieu",

		"/item/pet/hon",
		"/item/pet/hon",
		"/item/pet/hon",
		"/item/pet/hon",
		"/item/pet/hon",
		"/item/pet/hon",


});

string *FileTable3 = ({
	"/item/std/6007",
	"/item/test/vosongdiemphieu",
	"/item/test/vosongdiemphieu",
	"/item/test/vosongdiemphieu",
	"/item/test/vosongdiemphieu",
	"/item/test/vosongdiemphieu",
	"/item/test/vosongdiemphieu",
	"/item/test/vosongdiemphieu",
	"/item/91/9167",
	"/item/91/9167",

	"/item/common/box/tukim/item/tuidacuonghoa5",
	"/item/common/box/tukim/item/tuidacuonghoa5",
	"/item/common/box/tukim/item/tuidacuonghoa5",
	"/item/common/box/tukim/item/tuidacuonghoa5",
	"/item/common/box/tukim/item/tuidacuonghoa5",
	"/item/pet/hon",
	"/item/pet/hon",
	"/item/pet/hon",
	"/item/pet/hon",
	"/item/pet/hon",
	"/item/pet/hon",

});	

object * get_item()
{
	int i, rand, size;
	string file;
	string * line;
	object * all, item;
	all = ({ });	

	rand = random(sizeof(FileTable3));
	file = FileTable3[rand];
	if (file=="cash")
	{
		item = new ("/item/std/0001");
		item->set_value(10000);
	}
	else
		item = new (file);
	all += ({ item });

	line = copy(FileTable2);

	for (i=0;i<2;i++)
	{
		size = sizeof(line);
		file = line[random(size)];

		if (file == "cash")
		{
			item = new ("/item/std/0001");
			item->set_value(20000);
		}
		else
			item = new (file);

		all += ({ item });
		line -= ({ file });
		
	}

	line = copy(FileTable1);
	for (i=0;i<5;i++)
	{
		size = sizeof(line);
		file = line[random(size)];
		if (file=="cash")
		{
			item = new ("/item/std/0001");
			item->set_value(10000);
		}	
		else	
		{		
			item = new (file);
			if (item->get_max_combined()>1) 
			{
				if (item->get_stuff_type()>0)
					item->set_amount(5);
				else
					item->set_amount(2);
			}
			else if (item->get_equip_type()>0 && item->get_equip_type()!=HAND_TYPE)
			{
				"/sys/item/equip"->init_equip_prop_1(item);
				item->set_hide(0);
			}			
		}
		all += ({ item });
		line -= ({ file });
	}	
	return all;
}


void check_item()
{
	int i, size;
	size = sizeof(FileTable1);
	for (i = 0;i<size;i++)
	{
		if (FileTable1[i]=="cash") continue;
		if(!load_object(FileTable1[i]))
		{
			log_file("test.dat", FileTable1[i]+" error\n");
		}
	}
	size = sizeof(FileTable2);
	for (i = 0;i<size;i++)
	{
		if (FileTable2[i]=="cash") continue;
		if(!load_object(FileTable2[i]))
		{
			log_file("test.dat", FileTable2[i]+" error\n");
		}
	}
	size = sizeof(FileTable3);
	for (i = 0;i<size;i++)
	{
		if (FileTable3[i]=="cash") continue;
		if(!load_object(FileTable3[i]))
		{
			log_file("test.dat", FileTable3[i]+" error\n");
		}
	}		
}		