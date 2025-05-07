
#include <ansi.h>
#include <item.h>
#include <equip.h>

#define hole_1 "▼"
#define hole_2 "◆"
#define hole_3 "✸"

int Kim = 1;
int Moc = 2;
int Tho = 3;
int Thuy = 4;
int Hoa = 5;

int* ngu_hanh_indexs = ({ Kim,Moc,Tho,Thuy,Hoa,});
string* ngu_hanh_names = ({ "Kim","Mộc","Thổ","Thuỷ","Hoả", });
string* ngu_hanh_colors = ({ ""HIY"",""HIG"",""WHT"",""HIC"",""HIR"", });

int* tuong_sinh_indexs = ({ Kim, Thuy, Moc, Hoa, Tho, Kim, });
int* tuong_khac_indexs = ({ Kim, Moc, Tho, Thuy, Hoa, });

int position(int* array, int value) {
	int i, n;
	n = sizeof(array);

	for (i = 0; i < n; i++) {
		if (array[i] == value) {
			return i;
		}
	}
}

int Abs(int value) {
	if (value < 0) {
		return value * (-1);
	}
	else {
		return value;
	}
}

int get_tuong_sinh(int myNguHanh, int whoNguHanh) {

	int i, n, myPos, whoPos;
	
	myPos = position(tuong_sinh_indexs, myNguHanh);
	whoPos = position(tuong_sinh_indexs, whoNguHanh);

	if ((myPos + 1) == whoPos) {
		return -5;
	}
	else if (myPos == whoPos) {
		return 0;
	}
	else {
		return 5;
	}

}

int get_tuong_khac(int myNguHanh, int whoNguHanh) {
	int i, subValue, myPos, whoPos, result, isTangDan;

	myPos = position(tuong_khac_indexs, myNguHanh);//1
	whoPos = position(tuong_khac_indexs, whoNguHanh);//1

	subValue = whoPos - myPos;
	isTangDan = 0;
	if (subValue > 0) {
		isTangDan = 1;
	}
	else {
		isTangDan = 0;
	}

	subValue = Abs(subValue);
	switch (subValue)
	{
	case 0:
		result = 15;
		break;
	case 1:
		if (isTangDan==1) {
			result = 30;
		}
		else {
			result = -15;
		}

		break;
	case 2:
		if (isTangDan==1) {
			result = 20;
		}
		else {
			result = 10;
		}

		break;
	case 3:
		if (isTangDan==1) {
			result = 10;
		}
		else {
			result = 20;
		}
		break;
	case 4:

		if (isTangDan == 1) {
			result = -15;
		}
		else {
			result = 30;
		}
		
		break;
	}

	return result;
}

int get_tuong_khac_giap(int myNguHanh, int whoNguHanh) {
	int i, subValue, myPos, whoPos, result, isTangDan;

	//4 0
	myPos = position(tuong_khac_indexs, myNguHanh);//1
	whoPos = position(tuong_khac_indexs, whoNguHanh);//1

	subValue = whoPos - myPos;
	isTangDan = 0;
	if (subValue > 0) {
		isTangDan = 1;
	}
	else {
		isTangDan = 0;
	}

	subValue = Abs(subValue);
	switch (subValue)
	{
	case 0:
		result = 5;
		break;
	case 1:
		if (isTangDan == 1) {
			result = 10;
		}
		else {
			result = -5;
		}

		break;
	case 2:
		if (isTangDan == 1) {
			result = 5;
		}
		else {
			result = 5;
		}

		break;
	case 3:
		if (isTangDan == 1) {
			result = 5;
		}
		else {
			result = 5;
		}
		break;
	case 4:
		result = -5;

		if (myPos == 4 && whoPos == 0) {
			result = 10;
		}

		break;
	}

	return result;
}

int get_nguhanh_rate(object me, int type) {
	int item;
	int result = -1;
	switch (type)
	{
	case WEAPON_TYPE:
		if (item = me->get_equip(type)) {
			result = item->get_nh();
		}
		break;

	case ARMOR_TYPE:
		if (item = me->get_equip(type)) {
			result = item->get_nh();
		}
		break;
	}

	return result;
}

int is_nguhanh(object me) {
	int item1, item2;
	int result = 0;
	
	if (item1 = me->get_equip(WEAPON_TYPE)) {
		result += item1->get_nh();
	}

	if (item2 = me->get_equip(ARMOR_TYPE)) {
		result += item2->get_nh();
	}

	if (result > 0) {
		return 1;
	}

	return result;
}

int isExist(int value) {
	if (value > 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int counting_tuongsinh_rate(object me, object who) {
	object* myItem, yourItem;
	int myWeapon, yourWeapon, yourSuit, myWeaponNguHanh, whoWeaponNguHanh, whoSuitNguHanh, rateWeapon, rateSuit, rateTuongSinh, myTuongSinh, result;
	int resultDefault, tmpSuit, tmpWeapon;

	myWeaponNguHanh = -1;
	whoWeaponNguHanh = -1;
	whoSuitNguHanh = -1;
	result = 0;

	resultDefault = 0;
	tmpWeapon = 0;
	tmpSuit = 0;

	if (myWeapon = me->get_equip(WEAPON_TYPE)) {
		myWeaponNguHanh = myWeapon->get_nh();
	}

	if (yourWeapon = who->get_equip(WEAPON_TYPE)) {
		whoWeaponNguHanh = yourWeapon->get_nh();
	}
	if (yourSuit = who->get_equip(ARMOR_TYPE)) {
		whoSuitNguHanh = yourSuit->get_nh();
	}

	//Tuong sinh
	if (isExist(myWeaponNguHanh) && isExist(whoWeaponNguHanh)) {
		result += get_tuong_sinh(myWeaponNguHanh, whoWeaponNguHanh);
	}
	if (isExist(myWeaponNguHanh) && isExist(whoSuitNguHanh)) {
		result += get_tuong_sinh(myWeaponNguHanh, whoSuitNguHanh);
	}

	return result;
}

int counting_tuongkhac_giap_rate(object me, object who) {
	object* myItem, yourItem;
	int myWeapon, yourWeapon, yourSuit, myWeaponNguHanh, whoWeaponNguHanh, whoSuitNguHanh, rateWeapon, rateSuit, rateTuongSinh, myTuongSinh, result;
	int resultDefault, tmpSuit, tmpWeapon;

	myWeaponNguHanh = -1;
	whoWeaponNguHanh = -1;
	whoSuitNguHanh = -1;
	result = 0;

	resultDefault = 0;
	tmpWeapon = 0;
	tmpSuit = 0;

	if (myWeapon = me->get_equip(WEAPON_TYPE)) {
		myWeaponNguHanh = myWeapon->get_nh();
	}

	if (yourWeapon = who->get_equip(WEAPON_TYPE)) {
		whoWeaponNguHanh = yourWeapon->get_nh();
	}
	if (yourSuit = who->get_equip(ARMOR_TYPE)) {
		whoSuitNguHanh = yourSuit->get_nh();
	}
	
	if (isExist(myWeaponNguHanh) && isExist(whoSuitNguHanh)) {
		result -= get_tuong_khac_giap(myWeaponNguHanh, whoSuitNguHanh);
	}

	return result;
}

int counting_tuongkhac_vk_rate(object me, object who) {
	object* myItem, yourItem;
	int myWeapon, yourWeapon, yourSuit, myWeaponNguHanh, whoWeaponNguHanh, whoSuitNguHanh, rateWeapon, rateSuit, rateTuongSinh, myTuongSinh, result;
	int resultDefault, tmpSuit, tmpWeapon;

	myWeaponNguHanh = -1;
	whoWeaponNguHanh = -1;
	whoSuitNguHanh = -1;
	result = 0;

	resultDefault = 0;
	tmpWeapon = 0;
	tmpSuit = 0;

	if (myWeapon = me->get_equip(WEAPON_TYPE)) {
		myWeaponNguHanh = myWeapon->get_nh();
	}

	if (yourWeapon = who->get_equip(WEAPON_TYPE)) {
		whoWeaponNguHanh = yourWeapon->get_nh();
	}
	if (yourSuit = who->get_equip(ARMOR_TYPE)) {
		whoSuitNguHanh = yourSuit->get_nh();
	}

	//Tuong khac
	if (isExist(myWeaponNguHanh) && isExist(whoWeaponNguHanh)) {
		result += get_tuong_khac(myWeaponNguHanh, whoWeaponNguHanh);
	}

	return result;
}

int counting_nguhanh_rate(object me, object who) {
	object* myItem, yourItem;
	int myWeapon, yourWeapon, yourSuit, myWeaponNguHanh, whoWeaponNguHanh, whoSuitNguHanh, rateWeapon, rateSuit, rateTuongSinh, myTuongSinh, result;
	int resultDefault, tmpSuit, tmpWeapon;

	myWeaponNguHanh = -1;
	whoWeaponNguHanh = -1;
	whoSuitNguHanh = -1;
	result = 0;

	resultDefault = 0;
	tmpWeapon = 0;
	tmpSuit = 0;

	if (myWeapon = me->get_equip(WEAPON_TYPE)) {
		myWeaponNguHanh = myWeapon->get_nh();
	}

	if (yourWeapon = who->get_equip(WEAPON_TYPE)) {
		whoWeaponNguHanh = yourWeapon->get_nh();
	}
	if (yourSuit = who->get_equip(ARMOR_TYPE)) {
		whoSuitNguHanh = yourSuit->get_nh();
	}

	//Tuong sinh
	/*if (isExist(myWeaponNguHanh) && isExist(whoWeaponNguHanh)) {
		result += get_tuong_sinh(myWeaponNguHanh, whoWeaponNguHanh);
	}
	if (isExist(myWeaponNguHanh) && isExist(whoSuitNguHanh)) {
		result += get_tuong_sinh(myWeaponNguHanh, whoSuitNguHanh);
	}*/



	//Tuong khac

	/*if (isExist(myWeaponNguHanh) && isExist(whoSuitNguHanh)) {
		result -= get_tuong_sinh(myWeaponNguHanh, whoSuitNguHanh);
	}*/

	if (isExist(myWeaponNguHanh) && isExist(whoSuitNguHanh)) {
		result += get_tuong_khac_giap(myWeaponNguHanh, whoSuitNguHanh);
	}

	if (isExist(myWeaponNguHanh) && isExist(whoWeaponNguHanh)) {
		result += get_tuong_khac(myWeaponNguHanh, whoWeaponNguHanh);
	}

	return result;
}

string valueToString(int value) {

	if (value > 0) {
		return sprintf("+%d", value);
	}
	else {
		return sprintf("%d", value);
	}
	
}
 
string string_4_nguhanh(int index, int itemType) {

	string strResult;

	if (itemType == WEAPON_TYPE) {
		strResult = HIG"Gây thêm sát thương hệ " + /*ngu_hanh_colors[index]+ */ngu_hanh_names[index] + " +15%\n";
		switch (index)
		{
			//Kim
		case 0:
			strResult += HIG"Kháng " + ngu_hanh_names[index] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[index])));

			strResult += HIG"Kháng " + ngu_hanh_names[1] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[1])));
			strResult += HIG"Kháng " + ngu_hanh_names[2] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[2])));
			strResult += HIG"Kháng " + ngu_hanh_names[3] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[3])));
			strResult += HIG"Kháng " + ngu_hanh_names[4] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[4])));

			break;

			//Moc
		case 1:
			strResult += HIG"Kháng " + ngu_hanh_names[index] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[index])));

			strResult += HIG"Kháng " + ngu_hanh_names[0] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[0])));
			strResult += HIG"Kháng " + ngu_hanh_names[2] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[2])));
			strResult += HIG"Kháng " + ngu_hanh_names[3] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[3])));
			strResult += HIG"Kháng " + ngu_hanh_names[4] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[4])));
			break;

			//Tho
		case 2:
			strResult += HIG"Kháng " + ngu_hanh_names[index] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[index])));

			strResult += HIG"Kháng " + ngu_hanh_names[0] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[0])));
			strResult += HIG"Kháng " + ngu_hanh_names[1] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[1])));
			strResult += HIG"Kháng " + ngu_hanh_names[3] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[3])));
			strResult += HIG"Kháng " + ngu_hanh_names[4] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[4])));
			break;

			//Thuy
		case 3:
			strResult += HIG"Kháng " + ngu_hanh_names[index] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[index])));

			strResult += HIG"Kháng " + ngu_hanh_names[0] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[0])));
			strResult += HIG"Kháng " + ngu_hanh_names[1] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[1])));
			strResult += HIG"Kháng " + ngu_hanh_names[2] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[2])));
			strResult += HIG"Kháng " + ngu_hanh_names[4] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[4])));
			break;

			//Hoa
		case 4:

			strResult += HIG"Kháng " + ngu_hanh_names[index] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[index])));

			strResult += HIG"Kháng " + ngu_hanh_names[0] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[0])));
			strResult += HIG"Kháng " + ngu_hanh_names[1] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[1])));
			strResult += HIG"Kháng " + ngu_hanh_names[2] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[2])));
			strResult += HIG"Kháng " + ngu_hanh_names[3] + sprintf(": %s%%\n", valueToString(get_tuong_khac(index + 1, ngu_hanh_indexs[3])));
			break;
		}
	}
	else if(itemType == ARMOR_TYPE) {
		strResult = HIG"Giảm sát thương hệ " + /*ngu_hanh_colors[index]+ */ngu_hanh_names[index] + " +5%\n";
		switch (index)
		{
			//Kim
		case 0:
			//strResult += HIG"Kháng " + ngu_hanh_names[index] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[index])));

			strResult += HIG"Kháng " + ngu_hanh_names[1] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[1])));
			strResult += HIG"Kháng " + ngu_hanh_names[2] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[2])));
			strResult += HIG"Kháng " + ngu_hanh_names[3] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[3])));
			strResult += HIG"Kháng " + ngu_hanh_names[4] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[4])));

			break;

			//Moc
		case 1:
			//strResult += HIG"Kháng " + ngu_hanh_names[index] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[index])));

			strResult += HIG"Kháng " + ngu_hanh_names[0] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[0])));
			strResult += HIG"Kháng " + ngu_hanh_names[2] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[2])));
			strResult += HIG"Kháng " + ngu_hanh_names[3] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[3])));
			strResult += HIG"Kháng " + ngu_hanh_names[4] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[4])));
			break;

			//Tho
		case 2:
			//strResult += HIG"Kháng " + ngu_hanh_names[index] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[index])));

			strResult += HIG"Kháng " + ngu_hanh_names[0] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[0])));
			strResult += HIG"Kháng " + ngu_hanh_names[1] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[1])));
			strResult += HIG"Kháng " + ngu_hanh_names[3] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[3])));
			strResult += HIG"Kháng " + ngu_hanh_names[4] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[4])));
			break;

			//Thuy
		case 3:
			//strResult += HIG"Kháng " + ngu_hanh_names[index] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[index])));

			strResult += HIG"Kháng " + ngu_hanh_names[0] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[0])));
			strResult += HIG"Kháng " + ngu_hanh_names[1] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[1])));
			strResult += HIG"Kháng " + ngu_hanh_names[2] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[2])));
			strResult += HIG"Kháng " + ngu_hanh_names[4] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[4])));
			break;

			//Hoa
		case 4:

			//strResult += HIG"Kháng " + ngu_hanh_names[index] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[index])));

			strResult += HIG"Kháng " + ngu_hanh_names[0] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[0])));
			strResult += HIG"Kháng " + ngu_hanh_names[1] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[1])));
			strResult += HIG"Kháng " + ngu_hanh_names[2] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[2])));
			strResult += HIG"Kháng " + ngu_hanh_names[3] + sprintf(": %s%%\n", valueToString(get_tuong_khac_giap(index + 1, ngu_hanh_indexs[3])));
			break;
		}
	}

	return strResult;
}

string get_tuchat_desc(int tuChat) {
	string result;
	switch (tuChat)
	{
	case THAP:
		result = WHT"Thấp";
		break;
	case CAO:
		result = YEL"Cao";
		break;
	case RAT_CAO:
		result = HIY"Rất cao";
		break;
	default:
		result = BLK"Rất thấp";
		break;
	}

	return result;
}