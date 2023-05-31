#pragma once
#include <string>
#include "StudyroomSeat.h"
using namespace std;
class StudyroomSchedule {//몇날 몇시
	class StudyroomSeat** seat = new StudyroomSeat * [15];
	int time;
	string date;

	bool genderCheck(int row, int col, string gender);
public:
	StudyroomSchedule();
	bool seatBook(string id);
	bool seatCancel(string id);
	void seatShow();
	void setTime(int time);
	void setDate(string date);
};

