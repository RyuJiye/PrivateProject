#include <iostream>
#include "StudyroomSchedule.h"
#include "StudyroomSeat.h"
#include "StudyroomManagerSystem.h"
#include "StudyroomSystem.h"

using namespace std;

	bool  StudyroomSchedule::genderCheck(int row, int col, string gender) {
		if (row != 0 && seat[row - 1][col].returnGender() == gender) {//������ row!=0 �� �����̸�, �� row=0�̸� �ٸ� �ǿ����ڴ� ������ ����
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
			cout << "�¼���ȣ>> ";
			cin >> num;
			int row = num / 10;
			int col = num % 10 - 1;
			if (seat[row][col].resReturn() == false) {
				int age;
				cout << "���� �Է�>> ";
				cin >> age;
				if (age <= 13) {
					cout << "13�� ���ϴ� ������ �Ұ����մϴ�";
					return false;
					break;
				}
				string name;
				cout << "���� �Է�(��/��)>> ";
				string gender;
				cin >> gender;

				if (genderCheck(row, col, gender)) {
					string s;
					cout << "�յھ翷�� ���� ������ �ֽ��ϴ�. �ٸ� �¼��� �����Ͻʽÿ�>> " << endl;
					continue;
				}
				cout << "�̸� �Է�>> ";
				cin >> name;
				seat[row][col].seatSet(id, name, true, gender, age);
				StudyroomManagerSystem::seatCountUp(row, col);
				if (gender == "��") {
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
				cout << "�̹� ����� �¼��Դϴ�. �ٽ� �Է��Ͻðڽ��ϱ�? (��/�ƴϿ�)>> ";
				cin >> s;
				if (s == "�ƴϿ�") {
					return false;
					break;
				}
			}
		}
	}


	bool  StudyroomSchedule::seatCancel(string id) {
		while (true) {
			int num;
			cout << "�¼���ȣ>> ";
			cin >> num;
			int row = num / 10;
			int col = num % 10 - 1;
			if (seat[row][col].returnID().compare(id)) {
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
				cout << "*****���� ��ҵǾ����ϴ�*****";
				StudyroomSystem::stroomR += to_string(num) + " / " + to_string(seat[row][col].returnAge()) + " / " + seat[row][col].returnGender() + " / " + seat[row][col].nameReturn() + "  *�������*\n";
				seat[row][col].seatReset();
				StudyroomManagerSystem::seatCountUp(row, col);
				if (seat[row][col].returnGender() == "��") {
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
		cout << time << "��:" << endl;
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
