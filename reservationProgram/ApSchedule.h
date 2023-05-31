#pragma once
#include <string>
#include "AirplaneSeat.h"
class ApSchedule {//몇날 몇시 어디에서 어디로 비행기
	class AirplaneSeat* seat = new  AirplaneSeat[8];
	int time;
	string date;
	string takeoff;
	string landing;
public:
	ApSchedule();
	void setTime(int time);
	void setDate(string date);
    void setTakeoff(string takeoff);
    void setLanding(string landing);
    bool seatBook(string id);	
    bool seatCancel(string id);
	void seatShow(long price = 150000);	
};
