#pragma once
#include <string>
using namespace std;

class AirplaneSeat {
	string id;
	string name;
	bool res;
	int num;
	string type;
	int price;
public:
	void seatDataSet(int num);
	void seatSet(string id, string name, bool res);
	void seatReset(int num);
	bool bookCheck();
    string returnName();
	string returnID();
};