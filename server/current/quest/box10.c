#include <equip.h>
#include <item.h>
#include <public.h>

void check_item();
string* FileTable1 = ({
		"/item/common/box/tukim/item/cqdp",
		"/item/common/box/tukim/item/cqdp",
		"/item/common/box/tukim/item/cqdp",
		"/item/common/box/tukim/item/cqdp",
		"/item/common/box/tukim/item/cqdp",
		"/item/common/box/tukim/item/manhngocboi",
		"/item/common/box/tukim/item/manhngocboi",
		"/item/common/box/tukim/item/manhngocboi",
		"/item/common/box/tukim/item/manhngocboi",
		"/item/common/box/tukim/item/manhthucuoi",
		"/item/common/box/tukim/item/manhthucuoi",
		"/item/common/box/tukim/item/manhthucuoi",
		"/item/common/box/tukim/item/manhthucuoi",
		"/item/common/box/tukim/item/cqdp",
		"/item/common/box/tukim/item/cqdp",
		"/item/common/box/tukim/item/cqdp",
		"/item/common/box/tukim/item/cqdp",
		"/item/common/box/tukim/item/cqdp",

		"/item/common/box/tukim/item/tuitukim55",
			"/item/common/box/tukim/item/tuitukim55",
			"/item/common/box/tukim/item/tuitukim85",
			"/item/common/box/tukim/item/tuitukim85",

		"/item/common/box/tukim/item/tuidacuonghoa5",
		"/item/common/box/tukim/item/tuidacuonghoa5",
		"/item/common/box/tukim/item/tuidacuonghoa5",
		"/item/common/box/tukim/item/tuidacuonghoa5",
		"/item/common/box/tukim/item/tuidacuonghoa5",
		"/item/common/box/tukim/item/tuidacuonghoa5",
		"/item/common/box/tukim/item/tuidacuonghoa5",
		"/item/common/box/tukim/item/taitaohoan",
		"/item/common/box/tukim/item/taitaohoan",
		"/item/common/box/tukim/item/cqdp",
		"/item/common/box/tukim/item/cqdp",
		"/item/common/box/tukim/item/cqdp",
		"/item/common/box/tukim/item/cqdp",
		"/item/common/box/tukim/item/cqdp",
		"/item/common/box/tukim/item/manhngocboi",
		"/item/common/box/tukim/item/manhngocboi",
		"/item/common/box/tukim/item/manhngocboi",
		"/item/common/box/tukim/item/manhngocboi",
		"/item/common/box/tukim/item/manhthucuoi",
		"/item/common/box/tukim/item/manhthucuoi",
		"/item/common/box/tukim/item/manhthucuoi",
		"/item/common/box/tukim/item/manhthucuoi",
		"/item/common/box/tukim/item/cqdp",
		"/item/common/box/tukim/item/cqdp",
		"/item/common/box/tukim/item/cqdp",
		"/item/common/box/tukim/item/cqdp",
		"/item/common/box/tukim/item/cqdp",
		"/item/common/box/tukim/item/tuidacuonghoa5",
		"/item/common/box/tukim/item/tuidacuonghoa5",
		"/item/common/box/tukim/item/tuidacuonghoa5",
		"/item/common/box/tukim/item/tuidacuonghoa5",
		"/item/common/box/tukim/item/tuidacuonghoa5",
		"/item/common/box/tukim/item/tuidacuonghoa5",
		"/item/common/box/tukim/item/tuidacuonghoa5",
		"/item/common/box/tukim/item/taitaohoan",
		"/item/common/box/tukim/item/taitaohoan",

		"/item/common/box/tukim/item/tuitukim55",
			"/item/common/box/tukim/item/tuitukim55",
			"/item/common/box/tukim/item/tuitukim55",
			"/item/common/box/tukim/item/tuitukim85",
			"/item/common/box/tukim/item/tuitukim85",
	});

string* FileTable2 = ({
			"/item/common/box/tukim/item/ngoc25",
			"/item/common/box/tukim/item/ngoc25",
			"/item/common/box/tukim/item/tuitukim55",
			"/item/common/box/tukim/item/tuitukim85",
			"/item/common/box/tukim/item/taitaohoan",
			"/item/common/box/tukim/item/taitaohoan",
			"/item/common/box/tukim/item/taitaohoan",
			"/item/common/box/tukim/item/taitaohoan",
			"/item/common/box/tukim/item/taitaohoan",
			"/item/common/box/tukim/item/ve5sao",
			"/item/common/box/tukim/item/ve5sao",
			"/item/common/box/tukim/item/ve5sao",
			"/item/common/box/tukim/item/ve5sao",
			"/item/common/box/tukim/item/tuidacuonghoa10",
			"/item/common/box/tukim/item/tuidacuonghoa10",
			"/item/common/box/tukim/item/tuidacuonghoa10",
			"/item/common/box/tukim/item/tuidacuonghoa10",
			"/item/common/box/tukim/item/tuidacuonghoa10",
			"/item/common/box/tukim/item/tuivsdp50",
			"/item/common/box/tukim/item/tuivsdp50",
			"/item/common/box/tukim/item/tuivsdp50",
			"/item/common/box/tukim/item/tuivsdp50",
			"/item/common/box/tukim/item/tuivsdp50",
			"/item/common/box/tukim/item/tuivsdp50",
			"/item/common/box/tukim/item/sieutriduoc",
			"/item/common/box/tukim/item/sieutriduoc",
			"/item/common/box/tukim/item/sieutriduoc",

			"/item/common/box/tukim/item/1005",
			"/item/common/box/tukim/item/1007",
			"/item/common/box/tukim/item/ngoc25",
			"/item/common/box/tukim/item/ngoc25",
			"/item/common/box/tukim/item/11055",
			"/item/common/box/tukim/item/11057",

			"/item/common/box/tukim/item/sieutriduoc",
			"/item/common/box/tukim/item/sieutriduoc",
			"/item/common/box/tukim/item/sieutriduoc",
			"/item/common/box/tukim/item/sieutriduoc",
			"/item/common/box/tukim/item/sieutriduoc",

			"/item/common/box/tukim/item/ngoc25",
			"/item/common/box/tukim/item/ngoc25",
			"/item/common/box/tukim/item/tuitukim55",
			"/item/common/box/tukim/item/tuitukim55",
			"/item/common/box/tukim/item/tuitukim55",
			"/item/common/box/tukim/item/tuitukim55",
			"/item/common/box/tukim/item/tuitukim85",
			"/item/common/box/tukim/item/tuitukim85",
			"/item/common/box/tukim/item/tuitukim85",
			"/item/common/box/tukim/item/tuitukim85",
			"/item/common/box/tukim/item/taitaohoan",
			"/item/common/box/tukim/item/taitaohoan",
			"/item/common/box/tukim/item/taitaohoan",
			"/item/common/box/tukim/item/taitaohoan",
			"/item/common/box/tukim/item/taitaohoan",
			"/item/common/box/tukim/item/ve5sao",
			"/item/common/box/tukim/item/ve5sao",
			"/item/common/box/tukim/item/ve5sao",
			"/item/common/box/tukim/item/ve5sao",
			"/item/common/box/tukim/item/tuidacuonghoa10",
			"/item/common/box/tukim/item/tuidacuonghoa10",
			"/item/common/box/tukim/item/tuidacuonghoa10",
			"/item/common/box/tukim/item/tuidacuonghoa10",
			"/item/common/box/tukim/item/tuidacuonghoa10",
			"/item/common/box/tukim/item/tuivsdp50",
			"/item/common/box/tukim/item/tuivsdp50",
			"/item/common/box/tukim/item/tuivsdp50",
			"/item/common/box/tukim/item/tuivsdp50",
			"/item/common/box/tukim/item/tuivsdp50",
			"/item/common/box/tukim/item/sieutriduoc",
			"/item/common/box/tukim/item/sieutriduoc",
			"/item/common/box/tukim/item/sieutriduoc",

			"/item/common/box/tukim/item/1005",
			"/item/common/box/tukim/item/1007",
			"/item/common/box/tukim/item/ngoc25",
			"/item/common/box/tukim/item/ngoc25",
			"/item/common/box/tukim/item/11055",
			"/item/common/box/tukim/item/11057",

			"/item/common/box/tukim/item/sieutriduoc",
			"/item/common/box/tukim/item/sieutriduoc",
			"/item/common/box/tukim/item/sieutriduoc",
			"/item/common/box/tukim/item/sieutriduoc",
			"/item/common/box/tukim/item/sieutriduoc",


			"/item/pet/hon",
			"/item/pet/hon",
			"/item/pet/hon",
			"/item/pet/hon",
			"/item/pet/hon",
			"/item/pet/hon",
	});


string* FileTable3 = ({
	"/item/pet/hon",
	"/item/pet/hon",
	"/item/common/box/tukim/item/ve5sao",
	"/item/common/box/tukim/item/tuidacuonghoa20",
	"/item/common/box/tukim/item/tuidacuonghoa20",
	"/item/common/box/tukim/item/canhden",
	"/item/common/box/tukim/item/2001",
	"/item/pet/hon",
	"/item/pet/hon",
	"/item/pet/hon",
	"/item/common/box/tukim/item/2101",
	"/item/common/box/tukim/item/ve5sao",
	"/item/common/box/tukim/item/tuidacuonghoa20",
	"/item/common/box/tukim/item/canhdo",
	"/item/common/box/tukim/item/tuidacuonghoa20",
	"/item/common/box/tukim/item/2001",
	"/item/common/box/tukim/item/2101",
	"/item/common/box/tukim/item/ve5sao",
	"/item/common/box/tukim/item/tuidacuonghoa20",
	"/item/common/box/tukim/item/canhden",
	"/item/common/box/tukim/item/tuidacuonghoa20",
	"/item/common/box/tukim/item/2001",
	"/item/common/box/tukim/item/2101",
	"/item/common/box/tukim/item/canhdo",
	"/item/pet/hon",
	"/item/pet/hon",
	"/item/common/box/tukim/item/ve5sao",
	"/item/common/box/tukim/item/tuidacuonghoa20",
	"/item/common/box/tukim/item/canhdo",
	"/item/common/box/tukim/item/tuidacuonghoa20",
	"/item/common/box/tukim/item/2001",
	"/item/common/box/tukim/item/2101",

});


object* get_item()
{
	int i, rand, size, isTrangBi = 0;
	string file;
	string* line;
	object* all, item;
	all = ({ });

	rand = random(sizeof(FileTable3));
	file = FileTable3[rand];

	item = new (file);
	all += ({ item });

	line = copy(FileTable2);
	for (i = 0; i < 2; i++)
	{
		size = sizeof(line);
		file = line[random(size)];
		item = new (file);

		all += ({ item });
		line -= ({ file });

	}

	line = copy(FileTable1);
	for (i = 0; i < 5; i++)
	{
		size = sizeof(line);
		file = line[random(size)];
		item = new (file);

		all += ({ item });
		line -= ({ file });
	}

	return all;
}

void check_item()
{
	int i, size;
	size = sizeof(FileTable1);
	for (i = 0; i < size; i++)
	{
		if (FileTable1[i] == "cash") continue;
		if (!load_object(FileTable1[i]))
		{
			log_file("test.dat", FileTable1[i] + " error\n");
		}
	}
	size = sizeof(FileTable2);
	for (i = 0; i < size; i++)
	{
		if (FileTable2[i] == "cash") continue;
		if (!load_object(FileTable2[i]))
		{
			log_file("test.dat", FileTable2[i] + " error\n");
		}
	}
	size = sizeof(FileTable3);
	for (i = 0; i < size; i++)
	{
		if (FileTable3[i] == "cash") continue;
		if (!load_object(FileTable3[i]))
		{
			log_file("test.dat", FileTable3[i] + " error\n");
		}
	}
}