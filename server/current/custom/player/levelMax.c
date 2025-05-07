
public int number = 99;
public int star = 9;

public string VIP_CHAT_CONTENTS = "../freeCommon/vipchatcontents.txt";
public string ORG_CHAT_CONTENTS = "../freeCommon/orgchatcontents.txt";
public string LOGIN_CONTENTS = "../freeCommon/logins.txt";
public string BAOTRI = "../freeCommon/baotri.txt";
public string DEBUG = "../freeCommon/debug.txt";
public string ALL_SERVER = "../freeCommon/server.txt";


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