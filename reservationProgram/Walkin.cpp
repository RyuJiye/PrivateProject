#include "Walkin.h"


void Walkin::walkinManage() {
	while (true) {
		cout << endl << "���� ���մ� ����:1, ����ο��� ����:2, ���ư���:3 >> ";
		int m;
		cin >> m;
		if (m == 1) {
			it = v.erase(it);
			cout << v[1] << "����" << endl;
		}
		else if (m == 2) {
			if (v.size() < 2) {
				cout << "����ο�: 0��" << endl;
			}
			else {
				cout << "����ο�: " << v.size() - 2 << "��";
			}
		}
		else {
			break;
		}
	}
}

void Walkin::walkinSystem(string id) {
	while (true) {
		cout << endl << "��ũ�� ���:1, ����ȣ ����:2, ���ư���:3 >>";
		int m;
		cin >> m;
		if (m == 1) {
			cout << "2�μ� ������" << endl;
			v.push_back(id);
			if (v.size() < 2) {
				cout << "����" << endl;
			}
			else {
				cout << "����ȣ: " << v.size() - 1 << "��" << endl;
			}
		}
		else if (m == 2) {
			for (int i = 0; i < v.size(); i++) {
				if (id == v.at(i)) {
					if (i == 0 || i == 1) {
						cout << "����" << endl;
					}
					else {
						cout << "����ȣ:" << i + 1 << "��" << endl;
					}
				}
			}
		}
		else {
			break;
		}
	}
}
