#pragma once
#include <string>
using namespace std;
class StudyroomSeat {
	string id;
	int num;
	string name;
	bool res;
	string gender;
	int age;

public:
	void seatDataSet(int num);
	void seatSet(string id, string name, bool res, string gender, int age);
	void seatReset();
	string returnGender();
	bool resReturn();
	string returnID();
	string nameReturn();
	int returnAge();
};