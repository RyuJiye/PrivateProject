#pragma once
#include<string>
using namespace std;

#include "ApSchedule.h"
#include "AirlineMember.h"

class AirlineSystem{
	class ApSchedule apSchedule[5][6][7];
	string timeList[3] = { "12��","07��","17��" };
	string dateList[7] = { "2022.05.16", "2022.05.17", "2022.05.18", "2022.05.19", "2022.05.20", "2022.05.21", "2022.05.22" };
	string airportList[15] = { "��õ", "����", "����", "����", "����","��õ", "����", "����", "����", "����","��õ", "����", "����", "����", "����" };
	static AirlineMember* member;
	string airReceipt="���̵�/�����/������/��¥/�ð�/�¼���ȣ/�̸�\n";
	static string airR;
	void bookSystem1(int ap, int ld);
	void bookSystem2(int ap, int ld);
	void cancelSystem1(int ap, int ld);
	void cancelSystem2(int ap, int ld);
	void airlineBook();
	void airlineCancel();
    void airlineShow();
    void airlineBookSystem();
public:
	AirlineSystem();
	void airlineSystem();
	void airRecSave();

	friend bool ApSchedule::seatBook(string id);
	friend bool ApSchedule::seatCancel(string id);
};
