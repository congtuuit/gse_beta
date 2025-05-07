
#define SAVE_FILE       "data/id" SAVE_EXTENSION

private int Id;
private int ItemId;

private int NewUser;
private int CharNumber;
private int LoginPlayer;

private int UserCount;
private int CountTime;
private int MaxUser;

private int Buyer;
private int BuyCount;
private int BuyPoint;

private int CardCount;

private int QuitCount;
private int ReconnectCount;
private int NetdeadCount;
private int KickCount;

private int TransId = 10000;

void SAVE_BINARY() { }

void create()
{
	restore_object(SAVE_FILE);
	if (TransId < 10000) TransId = 10000;
}

int get_value(string key) {
	string* line, * data;
	int i, size, value;
	line = explode(read_file(SAVE_FILE), "\n");
	for (i = 0, size = sizeof(line); i < size; i++) {
		data = explode(line[i], " ");
		if (data[0] == key) {
			value = to_int(data[1]);
			return value;
		}
	}

	return value;
}

int add_max_id(int number)
{
	if (number > Id)
	{
		Id = number;
		save_object(SAVE_FILE);
	}

	return Id;
}

int zero_max_id()
{
	return Id = 0;
}

int get_max_id() { 
	Id = get_value("Id");
	return Id;
}

int add_max_itemid(int number)
{
	ItemId = get_value("ItemId");
	ItemId += number;
	save_object(SAVE_FILE);
	return ItemId;
}

int zero_max_itemid()
{
	return ItemId = 0;
}

int get_max_itemid() { 
	ItemId = get_value("ItemId");
	return ItemId; 
}

int add_newuser(int flag)
{
	return NewUser += flag;
}

int add_charnumber(int flag)
{
	return CharNumber += flag;
}

int add_loginplayer(int flag)
{
	return LoginPlayer += flag;
}

int get_newuser()
{
	NewUser = get_value("NewUser");
	return NewUser;
}

int get_charnumber()
{
	CharNumber = get_value("CharNumber");
	return CharNumber;
}

int get_loginplayer()
{
	LoginPlayer = get_value("LoginPlayer");
	return LoginPlayer;
}

int add_usercount(int flag)
{
	UserCount += flag;
	CountTime++;
	if (MaxUser < flag) MaxUser = flag;
	return flag;
}

int get_avguser()
{
	UserCount = get_value("UserCount");
	CountTime = get_value("CountTime");

	if (CountTime == 0) return 0;
	else return UserCount / CountTime;
}

int get_maxuser() { 
	MaxUser = get_value("MaxUser");
	return MaxUser;
}

int add_buy(int count, int point)
{
	Buyer++;
	BuyCount += count;
	BuyPoint += point;
	return Buyer;
}

int get_buyer() { 
	Buyer = get_value("Buyer");
	return Buyer;
}

int get_buycount() { 
	BuyCount = get_value("BuyCount");
	return BuyCount; 
}

int get_buypoint() { 
	BuyPoint = get_value("BuyPoint");
	return BuyPoint; 
}

int add_cardcount(int count)
{
	CardCount += count;
	return CardCount;
}

int get_cardcount() {
	CardCount = get_value("CardCount");
	return CardCount;
}

int init_login()
{
	NewUser = 0; CharNumber = 0; LoginPlayer = 0;
	return 1;
}

int init_count()
{
	UserCount = 0; CountTime = 0; MaxUser = 0; CardCount = 0;
	return 1;
}

int init_buy()
{
	Buyer = 0; BuyCount = 0; BuyPoint = 0;
}

int set_quit_count(int i) { return QuitCount = i; }

int add_quit_count(int i) { return QuitCount += i; }

int get_quit_count() { 
	QuitCount = get_value("QuitCount");
	return QuitCount;
}

int set_reconnect_count(int i) { return ReconnectCount = i; }

int add_reconnect_count(int i) { return ReconnectCount += i; }

int get_reconnect_count() { 
	ReconnectCount = get_value("ReconnectCount");
	return ReconnectCount;
}

int set_netdead_count(int i) { return NetdeadCount = i; }

int add_netdead_count(int i) { return NetdeadCount += i; }

int get_netdead_count() {
	NetdeadCount = get_value("NetdeadCount");
	return NetdeadCount;
}

int set_kick_count(int i) { return KickCount = i; }

int add_kick_count(int i) { return KickCount += i; }

int get_kick_count() { 
	KickCount = get_value("KickCount");
	return KickCount;
}

int get_transid() {
	TransId = get_value("TransId");
	return TransId;
}

int add_transid(int i) { TransId += i; save_object(SAVE_FILE); return TransId; }
