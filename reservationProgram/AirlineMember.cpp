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
	cout << endl << "*****로그인*****" << endl;
	while (true) {
		cout << endl << "아이디: ";
		cin >> id;
		cout << "비밀번호: ";
		cin >> pw;
		if (m.find(id) == m.end()) {
			cout << "id를 잘못 입력하였습니다." << endl;
			continue;
		}
		int n = m.at(id);
		if (pw == v.at(n).pw) {
			cout << endl << "*****" << v.at(n).id << "님 환영합니다*****" << endl;
			return &v.at(n);
			break;
		}
		else {
			cout << "비밀번호가 틀렸습니다" << endl;
		}
	}
}

void  AirlineMember::signUp() {
	cout << endl << "*****회원가입*****" << endl;
	string id, pw;
	cout << "아이디: ";
	cin >> id;
	cout << "비밀번호: ";
	cin >> pw;
	AirlineMember(id, pw,memberNum); 
}

void AirlineMember::prAllMember() {
	cout << endl << "*고객 리스트*" << endl;
	for (int i = 1; i < memberNum; i++) {
		cout << v[i].id << "/ ";
	}
	cout << endl;
}

AirlineMember& AirlineMember::chooseMember() {
	cout << endl << "고객 번호>> ";
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
		cout << "열기 실패";
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
	cout << id << "님의 예약횟수: " << bookCount << endl;
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
