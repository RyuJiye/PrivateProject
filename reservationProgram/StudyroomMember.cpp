#include "StudyroomMember.h"
#include "fstream"


StudyroomMember::StudyroomMember(string id, string pw, int num) {
	this->id = id;
	this->pw = pw;
	this->num = num;
	v.push_back(*this);
	m.insert(make_pair(id, num));
	memberNum++;
}

StudyroomMember* StudyroomMember:: login() {
	string  id, pw;
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


void StudyroomMember:: signUp() {
	cout << endl << "*****회원가입*****" << endl;
	string pw;
	cout << "아이디: " << memberNum << endl;
	cout << "비밀번호: ";
	cin >> pw;
	StudyroomMember(to_string(memberNum), pw, memberNum);
}

void StudyroomMember::prAllMember() {
	cout << endl << "*고객 리스트*" << endl;
	for (int i = 1; i < memberNum; i++) {
		cout << v[i].id << "/ ";
	}
	cout << endl;
}
	
StudyroomMember& StudyroomMember:: chooseMember() {
	cout << endl << "고객 번호>> ";
	int num;
	cin >> num;
	return v[num];
}

void StudyroomMember::studyMemSave() {
	string s1 = ", ", s2 = "/ ";
	const char* file = "studyMem.txt";
	fstream fout;
	fout.open(file, ios::out | ios::trunc);
	if (!fout) {
		cout << "열기 실패";
	}
	else {
		for (int i = 1; i < v.size(); i++) {
			fout << v.at(i).id << s1 << v.at(i).pw <<s2;
		}
	}
	fout.close();
}


string StudyroomMember::returnID() {
	return id;
}

void StudyroomMember::prBookCount() {
	cout << id << "님의 예약횟수: " << bookCount << endl;
}

void StudyroomMember::bookCountUp() {
		bookCount++;
}

void StudyroomMember::bookCountDown() {
		bookCount--;
}

void StudyroomMember::bookTimeUp(int date) {
		bookTime[date]++;
}

void StudyroomMember::bookTimeDown(int date) {
		bookTime[date]++;
}

int StudyroomMember::bookTimeReturn(int date) {
	return bookTime[date];
}

vector<StudyroomMember> StudyroomMember::v;
map<string, int> StudyroomMember::m;
int StudyroomMember::memberNum = 0;
