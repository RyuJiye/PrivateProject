#include <iostream>
#include "StudyroomSchedule.h"
#include "StudyroomSeat.h"
#include "StudyroomManagerSystem.h"
#include "StudyroomSystem.h"

using namespace std;

	bool  StudyroomSchedule::genderCheck(int row, int col, string gender) {
		if (row != 0 && seat[row - 1][col].returnGender() == gender) {//단축계산 row!=0 이 거짓이면, 즉 row=0이면 다른 피연산자는 계산되지 않음
			return 1;
		}

		else if (row != 14 && seat[row + 1][col].returnGender() == gender) {
			return 1;
		}
		else if (col != 0 && seat[row][col - 1].returnGender() == gender) {
			return 1;
		}
		else if (col != 14 && seat[row][col + 1].returnGender() == gender) {
			return 1;
		}
		else {
			return 0;
		}
	}

	StudyroomSchedule::StudyroomSchedule() {
		for (int i = 0; i < 15; i++) {
			seat[i] = new StudyroomSeat[15];
		}
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				seat[i][j].seatDataSet(i * 10 + j + 1);
			}
		}
	}


	bool  StudyroomSchedule::seatBook(string id) {

		while (true) {
			int num;
			cout << "좌석번호>> ";
			cin >> num;
			int row = num / 10;
			int col = num % 10 - 1;
			if (seat[row][col].resReturn() == false) {
				int age;
				cout << "나이 입력>> ";
				cin >> age;
				if (age <= 13) {
					cout << "13세 이하는 예약이 불가능합니다";
					return false;
					break;
				}
				string name;
				cout << "성별 입력(남/여)>> ";
				string gender;
				cin >> gender;

				if (genderCheck(row, col, gender)) {
					string s;
					cout << "앞뒤양옆에 같은 성별이 있습니다. 다른 좌석을 선택하십시오>> " << endl;
					continue;
				}
				cout << "이름 입력>> ";
				cin >> name;
				seat[row][col].seatSet(id, name, true, gender, age);
				StudyroomManagerSystem::seatCountUp(row, col);
				if (gender == "남") {
					StudyroomManagerSystem::genderCountUp(0);
				}
				else {
					StudyroomManagerSystem::genderCountUp(1);
				}
				StudyroomSystem::stroomR += to_string(num) + " / " + to_string(age) + " / " + gender + " / " + name + "\n";
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


	bool  StudyroomSchedule::seatCancel(string id) {
		while (true) {
			int num;
			cout << "좌석번호>> ";
			cin >> num;
			int row = num / 10;
			int col = num % 10 - 1;
			if (seat[row][col].returnID().compare(id)) {
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
				cout << "*****예약 취소되었습니다*****";
				StudyroomSystem::stroomR += to_string(num) + " / " + to_string(seat[row][col].returnAge()) + " / " + seat[row][col].returnGender() + " / " + seat[row][col].nameReturn() + "  *예약취소*\n";
				seat[row][col].seatReset();
				StudyroomManagerSystem::seatCountUp(row, col);
				if (seat[row][col].returnGender() == "남") {
					StudyroomManagerSystem::genderCountUp(0);
				}
				else {
					StudyroomManagerSystem::genderCountUp(1);
				}
				return true;
				break;
			}
		}
	}

	void  StudyroomSchedule::seatShow() {
		cout << endl << date << "   ";
		cout.width(2);
		cout.fill('0');
		cout << time << "시:" << endl;
		for (int i = 0; i < 15; i++) {
			cout << endl;
			for (int j = 0; j < 15; j++) {
				cout << seat[i][j].nameReturn() << "(" << seat[i][j].returnGender() << ")" << "\t";
			}
			cout << endl;
		}
	}

	void  StudyroomSchedule::setTime(int time) {
		this->time = time;
	}

	void  StudyroomSchedule::setDate(string date) {
		this->date = date;
	}
