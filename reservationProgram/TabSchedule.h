#pragma once
#include<iostream>
#include<string>
using namespace std;

#include "Table.h"

class TabSchedule {//몇날 몇시 몇인 테이블 관리 
	class Table* table;
	int time;
	string date;
	int tabNum;//테이블 수

public:
	void tabScheduleDataSet(int time, string date, int tabNum, int seatNum);
	void tabShow();
	bool tabBook(string id);
	bool tabCancel(string id);

};