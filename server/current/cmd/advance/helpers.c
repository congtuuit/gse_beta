
public int number = 99;
public int star = 9;

public string VIP_CHAT_CONTENTS = "../common/vipchatcontents";
public string ORG_CHAT_CONTENTS = "../common/orgchatcontents";
public string LOGIN_CONTENTS = "../common/logins.txt";
public string BAOTRI = "../common/baotri.txt";
public string DEBUG = "../common/debug.txt";
public string ALL_SERVER = "../common/server.txt";
public string FILE_ACC = "../current/taikhoan.ini";

int get_level() {return number;}
int set_level(int i){return number = i;}

int get_level_star() {return star;}
int set_level_star(int i){return star = i;}

string get_vip_chat() {
	return VIP_CHAT_CONTENTS;
}

string get_org_chat() {
	return ORG_CHAT_CONTENTS;
}

string get_login_txt() {
	return LOGIN_CONTENTS;
}

string get_baotri_txt() {
	return BAOTRI;
}

string get_debug_txt() {
	return DEBUG;
}

string get_server_txt() {
	return ALL_SERVER;
}

string get_account_txt() {
	return FILE_ACC;
}