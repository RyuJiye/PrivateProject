#include "AirlineMember.h"
#include <stdio.h>
#include <iostream>
#include<fstream>
using namespace std;

AirlineMember::AirlineMember(string id, string pw, int num) {
	this->id = id;
	this->pw = pw;
	this->num = num;
	v.push_back(*this);
	m.insert(make_pair(id, num));
	memberNum++;
}



AirlineMember* AirlineMember::login() {
	string id, pw;
	cout << endl << "*****�α���*****" << endl;
	while (true) {
		cout << endl << "���̵�: ";
		cin >> id;
		cout << "��й�ȣ: ";
		cin >> pw;
		if (m.find(id) == m.end()) {
			cout << "id�� �߸� �Է��Ͽ����ϴ�." << endl;
			continue;
		}
		int n = m.at(id);
		if (pw == v.at(n).pw) {
			cout << endl << "*****" << v.at(n).id << "�� ȯ���մϴ�*****" << endl;
			return &v.at(n);
			break;
		}
		else {
			cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�" << endl;
		}
	}
}

void  AirlineMember::signUp() {
	cout << endl << "*****ȸ������*****" << endl;
	string id, pw;
	cout << "���̵�: ";
	cin >> id;
	cout << "��й�ȣ: ";
	cin >> pw;
	AirlineMember(id, pw,memberNum); 
}

void AirlineMember::prAllMember() {
	cout << endl << "*�� ����Ʈ*" << endl;
	for (int i = 1; i < memberNum; i++) {
		cout << v[i].id << "/ ";
	}
	cout << endl;
}

AirlineMember& AirlineMember::chooseMember() {
	cout << endl << "�� ��ȣ>> ";
	int num;
	cin >> num;
	return v[num];
}

void AirlineMember::airMemSave() {
	string s1 = ", ", s2 = "/ ";
	const char* file = "airMem.txt";
	fstream fout;
	fout.open(file, ios::out | ios::trunc);
	if (!fout) {
		cout << "���� ����";
	}
	else {
		for (int i = 1; i < v.size(); i++) {
			fout << v.at(i).id << s1 << v.at(i).pw << s2;
		}
	}
	fout.close();
}

string AirlineMember::returnID() {
	return id;
}

void AirlineMember::prBookCount() {
	cout << id << "���� ����Ƚ��: " << bookCount << endl;
}
void AirlineMember::mileageUp() {
	mileage += 100;
}
void AirlineMember::mileageDown() {
	mileage -= 100;
}
void AirlineMember::bookCountUp() {
	bookCount++;
}
void AirlineMember::bookCountDown() {
	bookCount--;
}

vector<AirlineMember> AirlineMember::v;
map<string, int> AirlineMember::m;
int AirlineMember::memberNum = 0;
