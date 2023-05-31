#pragma once
#include <Vector>
#include <Map>
#include <string>
using  namespace std;

class AirlineMember {
	static vector<AirlineMember> v;
	static map<string, int>m;
	static int memberNum; //¸â¹ö ¼ö
	string id;
	string pw;
	int num;
	int bookCount = 0;
	long mileage = 0;
public:
	AirlineMember(string id, string pw, int num);
	static AirlineMember* login();
	static void signUp();
	static void prAllMember();
	static AirlineMember& chooseMember();
	static void airMemSave();
	string returnID();
	void prBookCount();
	void mileageUp();
	void mileageDown();
	void bookCountUp();
	void bookCountDown();
};


