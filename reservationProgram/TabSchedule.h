#pragma once
#include<iostream>
#include<string>
using namespace std;

#include "Table.h"

class TabSchedule {//� ��� ���� ���̺� ���� 
	class Table* table;
	int time;
	string date;
	int tabNum;//���̺� ��

public:
	void tabScheduleDataSet(int time, string date, int tabNum, int seatNum);
	void tabShow();
	bool tabBook(string id);
	bool tabCancel(string id);

};