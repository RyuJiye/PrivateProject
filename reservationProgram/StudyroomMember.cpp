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


void StudyroomMember:: signUp() {
	cout << endl << "*****ȸ������*****" << endl;
	string pw;
	cout << "���̵�: " << memberNum << endl;
	cout << "��й�ȣ: ";
	cin >> pw;
	StudyroomMember(to_string(memberNum), pw, memberNum);
}

void StudyroomMember::prAllMember() {
	cout << endl << "*�� ����Ʈ*" << endl;
	for (int i = 1; i < memberNum; i++) {
		cout << v[i].id << "/ ";
	}
	cout << endl;
}
	
StudyroomMember& StudyroomMember:: chooseMember() {
	cout << endl << "�� ��ȣ>> ";
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
		cout << "���� ����";
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
	cout << id << "���� ����Ƚ��: " << bookCount << endl;
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
