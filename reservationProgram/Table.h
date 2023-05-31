#pragma once
#include <string>
using namespace std;

class Table {
	int seatNum;//ÀÎ¿ø¼ö
	string id;
	string name;
	bool res;
public:
	void tabDataSet(int seatNum);
	void tabSet(string id, string name);
	void tabReset();
	bool returnRes();
	string returnID();
	string returnName();
};