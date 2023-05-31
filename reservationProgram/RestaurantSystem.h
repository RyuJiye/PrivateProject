#pragma once
#include "Walkin.h"
#include "RestaurantMember.h"
#include "TabSchedule.h"

class RestaurantSystem {
	class TabSchedule*** tabSchedule = new TabSchedule * *[3];
	string dateList[7] = { "2022.05.16", "2022.05.17", "2022.05.18", "2022.05.19", "2022.05.20", "2022.05.21", "2022.05.22" };
	static RestaurantMember* member;
	Walkin w;
	string resReceipt = "아이디/인원/날짜/시간/좌석번호/이름\n";
	static string resR;
public:
	RestaurantSystem();
	void tabScheduleShow(int n, int d);
	void restaurantBook();
	void restaurantCancel();
	void restaurantShow();
	void restaurantBookSystem();
	void restaurantSystem();
	void resRecSave();

	friend bool TabSchedule::tabBook(string id);
	friend bool TabSchedule::tabCancel(string id);
};


