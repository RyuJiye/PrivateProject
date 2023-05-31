//#pragma once
#include <string>
using namespace std;
#include "StudyroomMember.h"
#include "StudyroomSchedule.h"

class StudyroomSystem {
	static StudyroomMember* member;
	class StudyroomSchedule** stroomSchedule = new StudyroomSchedule * [7];
	string dateList[7] = { "2022.05.16", "2022.05.17", "2022.05.18", "2022.05.19", "2022.05.20", "2022.05.21", "2022.05.22" };
	string stroomReceipt = "아이디/날짜/시간/좌석번호/나이/성별/이름\n";
	static string stroomR;
	void studyroomBook();
	void studyroomCancel();
	void studyroomShow();
	void studyroomBookSystem();

public:
	StudyroomSystem();
	void studyroomSystem();
	void stroomRecSave();
	friend bool StudyroomSchedule::seatBook(string id);
	friend bool StudyroomSchedule::seatCancel(string id);
};

