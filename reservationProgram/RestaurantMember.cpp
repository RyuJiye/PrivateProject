#include<iostream>
#include "RestaurantMember.h"
#include <fstream>

using namespace std;

RestaurantMember::RestaurantMember(string id, string pw, int num, int age) {
	this->id = id;
	this->pw = pw;
	this->num = num;
	this->age = age;
	memberNum++;
	v.push_back(*this);
	m.insert(make_pair(id, num));
}

 RestaurantMember* RestaurantMember::login() {
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

	 
 void  RestaurantMember::signUp() {
	cout << endl << "*****회원가입*****" << endl;
	string id, pw;
	int age;
	cout << endl << "아이디: ";
	cin >> id;
	cout << "비밀번호: ";
	cin >> pw;
	cout << "나이: ";
	cin >> age;
	cout << endl;
	RestaurantMember(id, pw, memberNum, age);
}

 void RestaurantMember::prAllMember() {
	cout << endl << "*고객 리스트*" << endl;
	for (int i = 1; i < memberNum; i++) {
	   cout << v[i].id << "/ ";
	}
	cout << endl;
}

RestaurantMember& RestaurantMember::chooseMember() {
	cout << endl << "고객 번호>> ";
	int num;
	cin >> num;
	return v[num];
}

void RestaurantMember::resMemSave() {
	string s1 = ", ", s2 = "/ ";
	const char* file = "resMem.txt";
	fstream fout;
	fout.open(file, ios::out | ios::trunc);
	if (!fout) {
		cout << "열기 실패";
	}
	else {
		for (int i = 1; i < v.size(); i++) {
			fout << v.at(i).id << s1 << v.at(i).pw << s1 << v.at(i).age << s2;
		}
	}
	fout.close();
}

string  RestaurantMember::returnID() {
	return id;
}

int  RestaurantMember::returnAge() {
	return age;
}

void  RestaurantMember::prBookCount() {
	cout << id << "님의 예약횟수: " << bookCount << endl;
}

void  RestaurantMember::bookCountUp() {
	bookCount++;
}

void  RestaurantMember::bookCountDown() {
	bookCount--;
}

vector<RestaurantMember> RestaurantMember::v;
map<string, int> RestaurantMember::m;
int RestaurantMember::memberNum = 0;