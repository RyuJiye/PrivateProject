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
	cout << time << "��: ";
	for (int i = 0; i < tabNum; i++) {
		cout << table[i].returnName() << '\t';
	}
	cout << endl;
}

bool TabSchedule::tabBook(string id) {
	while (true) {
		int num;
		cout << "���̺� ��ȣ>>";
		cin >> num;

		if (table[num - 1].returnRes() == false) {
			string name;
			cout << "�̸� �Է�>> ";
			cin >> name;
			table[num - 1].tabSet(id, name);
			RestaurantSystem::resR += to_string(num) + " / " + table[num - 1].returnName()+ '\n';
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


	bool TabSchedule::tabCancel(string id) {
		while (true) {
			int num;
			cout << "�¼���ȣ>> ";
			cin >> num;
			if (table[num - 1].returnID().compare(id)) {
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
				RestaurantSystem::resR += to_string(num) + " / " + table[num - 1].returnName() + "  *�������*" + '\n';
				table[num - 1].tabReset();
				return true;
				break;
			}
		}
	}
