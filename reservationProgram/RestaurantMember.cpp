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

	 
 void  RestaurantMember::signUp() {
	cout << endl << "*****ȸ������*****" << endl;
	string id, pw;
	int age;
	cout << endl << "���̵�: ";
	cin >> id;
	cout << "��й�ȣ: ";
	cin >> pw;
	cout << "����: ";
	cin >> age;
	cout << endl;
	RestaurantMember(id, pw, memberNum, age);
}

 void RestaurantMember::prAllMember() {
	cout << endl << "*�� ����Ʈ*" << endl;
	for (int i = 1; i < memberNum; i++) {
	   cout << v[i].id << "/ ";
	}
	cout << endl;
}

RestaurantMember& RestaurantMember::chooseMember() {
	cout << endl << "�� ��ȣ>> ";
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
		cout << "���� ����";
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
	cout << id << "���� ����Ƚ��: " << bookCount << endl;
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