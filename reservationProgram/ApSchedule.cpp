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
		cout << endl << "�¼���ȣ>> ";
		cin >> num;
		if (!seat[num - 1].bookCheck()) { //�� �¼��̶��
			string name;
			cout << "�̸� �Է�>> ";
			cin >> name;
			seat[num - 1].seatSet(id, name, true);
			cout << "*���� �Ϸ�*" << endl;
			AirlineManagerSystem::seatCountUp(num - 1);
			AirlineSystem::airR += to_string(num) + " / " + name + '\n';
			return true;
			break;
		}
		else {
			string s;
		    cout << "�̹� ����� �¼��Դϴ�. �ٽ� �Է��Ͻðڽ��ϱ�? (��/�ƴϿ�)>> ";
			cin >> s;
			if (s == "�ƴϿ�") {
				return false;
				break;
			}
		}
	}
}

bool ApSchedule::seatCancel(string id) {
	while (true) {
		int num;
		cout << endl << "�¼���ȣ>> ";
		cin >> num;
		if (seat[num - 1].returnID().compare(id)) {
			string s;
			cout << "ȸ������ ������ �ڸ��� �ƴմϴ�. �ٽ� �Է��Ͻðڽ��ϱ�? (��/�ƴϿ�)>> ";
			cin >> s;
			if (s == "��") {
				continue;
			}
			else {
				return false;
				break;
			}
		}
		else {
			cout << "*���� ��� �Ϸ�*";
			AirlineSystem::airR += to_string(num) + " / " + seat[num-1].returnName() + "  *�������*" + '\n';
			seat[num - 1].seatReset(num - 1); 
			AirlineManagerSystem::seatCountDown(num - 1);
			return true;
			break;
		}
	}
}

void ApSchedule::seatShow(long price) {//���� ���� �Է¹ޱ�, ���
	cout << endl << date << "   ";
	cout.width(2);
	cout.fill('0');
	cout << time << "��:" << endl;
	if (price >= 150000) {
		cout << endl;
		for (int i = 0; i < 8; i++) {
			cout << seat[i].returnName() << '\t';
		}
		cout << endl;
	}//���� ���� ���� �ִ� �͸� �����ֱ�,  ������������ �ִ� ���

	else {
		for (int i = 1; i < 8; i++) {
			cout << seat[i].returnName() << '\t';
		}
		cout << endl << "���ڳ�� �¼��� �̿밡��(2~8��)" << endl;
	}
}

