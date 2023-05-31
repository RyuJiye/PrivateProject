#pragma once
#include <string>
#include <Vector>
#include <Map>
using namespace std;

class RestaurantMember {
	static vector<RestaurantMember> v;
	static map<string, int>m;
	static int memberNum;
	string id;
	string pw;
	int num;
	int age;
	int bookCount = 0;

public:
	RestaurantMember(string id, string pw, int num, int age);
	static RestaurantMember* login();
	static void signUp();
	static void prAllMember();
	static RestaurantMember& chooseMember();
	static void resMemSave();
	string returnID();
	int returnAge();
	void prBookCount();
	void bookCountUp();
	void bookCountDown();
};


