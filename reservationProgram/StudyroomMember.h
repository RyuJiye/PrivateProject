#pragma once
#include <iostream>
#include <Vector>
#include <Map>
#include <string>
using  namespace std;

class StudyroomMember {
	static vector<StudyroomMember> v;
	static map<string, int>m;
	static int memberNum;
	string id;
	string pw;
	int num;
	int bookTime[7] = { 0, };
	int bookCount = 0;

public:
	StudyroomMember(string id, string pw, int num);
	static  StudyroomMember* login();
	static void signUp();
	static void prAllMember();
	string returnID();
	static StudyroomMember& chooseMember();
	static void studyMemSave();
	void prBookCount();
	void bookCountUp();
	void bookCountDown();
	void bookTimeUp(int date);
	void bookTimeDown(int date);
	int bookTimeReturn(int date);
};
