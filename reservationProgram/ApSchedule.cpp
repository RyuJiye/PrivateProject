#include <iostream>
#include "ApSchedule.h"
#include "AirlineManagerSystem.h"
#include "AirlineSystem.h"
using namespace std;

ApSchedule::ApSchedule() {
	for (int i = 0; i < 8; i++) {
		seat[i].seatDataSet(i);
	}
}

void ApSchedule::setTime(int time) {
	this->time = time;
}

void ApSchedule::setDate(string date) {
	this->date = date;
}

void ApSchedule::setTakeoff(string takeoff) {
	this->takeoff = takeoff;
}

void ApSchedule::setLanding(string landing) {
	this->landing = landing;
}

bool ApSchedule::seatBook(string id) {
	while (true) {
		int num;
		cout << endl << "좌석번호>> ";
		cin >> num;
		if (!seat[num - 1].bookCheck()) { //빈 좌석이라면
			string name;
			cout << "이름 입력>> ";
			cin >> name;
			seat[num - 1].seatSet(id, name, true);
			cout << "*예약 완료*" << endl;
			AirlineManagerSystem::seatCountUp(num - 1);
			AirlineSystem::airR += to_string(num) + " / " + name + '\n';
			return true;
			break;
		}
		else {
			string s;
		    cout << "이미 예약된 좌석입니다. 다시 입력하시겠습니까? (네/아니오)>> ";
			cin >> s;
			if (s == "아니오") {
				return false;
				break;
			}
		}
	}
}

bool ApSchedule::seatCancel(string id) {
	while (true) {
		int num;
		cout << endl << "좌석번호>> ";
		cin >> num;
		if (seat[num - 1].returnID().compare(id)) {
			string s;
			cout << "회원님이 선택한 자리가 아닙니다. 다시 입력하시겠습니까? (네/아니오)>> ";
			cin >> s;
			if (s == "네") {
				continue;
			}
			else {
				return false;
				break;
			}
		}
		else {
			cout << "*예약 취소 완료*";
			AirlineSystem::airR += to_string(num) + " / " + seat[num-1].returnName() + "  *예약취소*" + '\n';
			seat[num - 1].seatReset(num - 1); 
			AirlineManagerSystem::seatCountDown(num - 1);
			return true;
			break;
		}
	}
}

void ApSchedule::seatShow(long price) {//예산 범위 입력받기, 출력
	cout << endl << date << "   ";
	cout.width(2);
	cout.fill('0');
	cout << time << "시:" << endl;
	if (price >= 150000) {
		cout << endl;
		for (int i = 0; i < 8; i++) {
			cout << seat[i].returnName() << '\t';
		}
		cout << endl;
	}//예산 범위 내에 있는 것만 보여주기,  선택했을때만 있는 기능

	else {
		for (int i = 1; i < 8; i++) {
			cout << seat[i].returnName() << '\t';
		}
		cout << endl << "이코노미 좌석만 이용가능(2~8번)" << endl;
	}
}

