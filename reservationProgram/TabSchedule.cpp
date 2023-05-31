#include "TabSchedule.h"
#include "RestaurantSystem.h"


void TabSchedule::tabScheduleDataSet(int time, string date, int tabNum, int seatNum) {
	this->time = time;
	this->date = date;
	this->tabNum = tabNum;
	table = new Table[tabNum];
	for (int i = 0; i < tabNum; i++) {
	table[i].tabDataSet(seatNum);
	}
}

void TabSchedule::tabShow() {
	cout.width(2);
	cout.fill('0');
	cout << time << "시: ";
	for (int i = 0; i < tabNum; i++) {
		cout << table[i].returnName() << '\t';
	}
	cout << endl;
}

bool TabSchedule::tabBook(string id) {
	while (true) {
		int num;
		cout << "테이블 번호>>";
		cin >> num;

		if (table[num - 1].returnRes() == false) {
			string name;
			cout << "이름 입력>> ";
			cin >> name;
			table[num - 1].tabSet(id, name);
			RestaurantSystem::resR += to_string(num) + " / " + table[num - 1].returnName()+ '\n';
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


	bool TabSchedule::tabCancel(string id) {
		while (true) {
			int num;
			cout << "좌석번호>> ";
			cin >> num;
			if (table[num - 1].returnID().compare(id)) {
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
				RestaurantSystem::resR += to_string(num) + " / " + table[num - 1].returnName() + "  *예약취소*" + '\n';
				table[num - 1].tabReset();
				return true;
				break;
			}
		}
	}
