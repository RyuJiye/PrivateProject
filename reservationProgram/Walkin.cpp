#include "Walkin.h"


void Walkin::walkinManage() {
	while (true) {
		cout << endl << "다음 대기손님 입장:1, 대기인원수 보기:2, 돌아가기:3 >> ";
		int m;
		cin >> m;
		if (m == 1) {
			it = v.erase(it);
			cout << v[1] << "입장" << endl;
		}
		else if (m == 2) {
			if (v.size() < 2) {
				cout << "대기인원: 0팀" << endl;
			}
			else {
				cout << "대기인원: " << v.size() - 2 << "팀";
			}
		}
		else {
			break;
		}
	}
}

void Walkin::walkinSystem(string id) {
	while (true) {
		cout << endl << "워크인 대기:1, 대기번호 보기:2, 돌아가기:3 >>";
		int m;
		cin >> m;
		if (m == 1) {
			cout << "2인석 웨이팅" << endl;
			v.push_back(id);
			if (v.size() < 2) {
				cout << "입장" << endl;
			}
			else {
				cout << "대기번호: " << v.size() - 1 << "번" << endl;
			}
		}
		else if (m == 2) {
			for (int i = 0; i < v.size(); i++) {
				if (id == v.at(i)) {
					if (i == 0 || i == 1) {
						cout << "입장" << endl;
					}
					else {
						cout << "대기번호:" << i + 1 << "번" << endl;
					}
				}
			}
		}
		else {
			break;
		}
	}
}
