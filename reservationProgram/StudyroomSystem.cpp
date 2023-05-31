#include <iostream>
#include <Vector>
#include <Map>
#include <string>
#include <fstream>
#include "StudyroomSystem.h"
#include "StudyroomSchedule.h"
#include "StudyroomMember.h"
#include "StudyroomManagerSystem.h"

using namespace std;


	void StudyroomSystem::studyroomBook() {
		cout << endl<<"날짜를 고르시오(2022/05/16~2022/05/23)" << endl;
		cout << "월:1, 화:2, 수:3,목:4,금:5,토:6,일:7 >>";
		int date;
		cin >> date;
		if (member->bookTimeReturn(date - 1) < 4) {
			cout << "시간 입력(09~23)>>";
			int time;
			cin >> time;
			stroomSchedule[date - 1][time - 9].seatShow();
			stroomR = (*member).returnID() + " / " + dateList[date - 1] + " / " + to_string(time) + "시 / " + " / ";
			if (stroomSchedule[date - 1][time - 9].seatBook(member->returnID())) {
				member->bookTimeUp(date - 1);
				member->bookCountUp();
				stroomReceipt += (stroomR);
			}
		}
		else {
			cout << "해당 날짜의 예약시간을 초과했습니다";
		}
	}

	void StudyroomSystem::studyroomCancel() {
		cout << endl << "날짜를 고르시오(2022/05/16~2022/05/23)" << endl;
		cout << "월:1, 화:2, 수:3,목:4,금:5,토:6,일:7 >>";
		int date;
		cin >> date;
		cout << "시간 입력(09~23)>>";
		int time;
		cin >> time;
		stroomSchedule[date - 1][time - 9].seatShow();
		stroomR = (*member).returnID() + " / " + dateList[date - 1] + " / " + to_string(time) + "시 / " + " / ";
		if (stroomSchedule[date - 1][time - 9].seatCancel((*member).returnID())) {
			member->bookTimeDown(date - 1);
			member->bookCountDown();
			stroomReceipt += (stroomR);
		}
	}
	void StudyroomSystem::studyroomShow() {
		cout << "날짜를 고르시오(2022/05/16~2022/05/23)" << endl;
		cout << "월:1, 화:2, 수:3,목:4,금:5,토:6,일:7 >>";
		int date;
		cin >> date;
		cout << "시간 입력(09~23)>>";
		int time;
		cin >> time;
		stroomSchedule[date - 1][time - 9].seatShow();
	}

	void StudyroomSystem::studyroomBookSystem() {
		while (true) {
			int menu;
			cout << endl << "예약:1, 취소:2, 보기:3, 로그아웃:4 >>";
			cin >> menu;
			if (menu == 1) {
				studyroomBook();
			}
			else if (menu == 2) {
				studyroomCancel();
			}
			else if (menu == 3) {
				studyroomShow();
			}
			else {
				cout << "*****로그아웃*****" << endl;
				member = NULL;
				break;
			}
		}
	}


	StudyroomSystem::StudyroomSystem() {
		StudyroomMember::StudyroomMember("0", "studyroom", 0);

		for (int i = 0; i < 7; i++) {
			stroomSchedule[i] = new StudyroomSchedule[15];
			for (int j = 0; j < 15; j++) {
				stroomSchedule[i][j].setDate(dateList[i]);
				stroomSchedule[i][j].setTime(j + 9);
			}
		}
	}

	void StudyroomSystem::studyroomSystem() {

		while (true) {
			cout << endl << "로그인:1, 회원가입:2, 끝내기:3 >>";
			int n;
			cin >> n;
			if (n == 1) {
				member = StudyroomMember::login();
				if (member->returnID() == "0") {
					StudyroomManagerSystem::studyroomManagerSystem();
				}

				else {
					studyroomBookSystem();
				}
			}

			else if (n == 2) {
				StudyroomMember::signUp();
			}

			else {
				cout << "*****독서실 예약시스템 종료*****" << endl;
				break;
			}
		}
	}

	void StudyroomSystem::stroomRecSave() {
		string s1 = ", ", s2 = "/ ";
		const char* file = "stroomReceipt.txt";
		fstream fout;
		fout.open(file, ios::out | ios::trunc);
		if (!fout) {
			cout << "열기 실패";
		}
		else {
			fout << stroomReceipt;
		}
		fout.close();
	}

	string StudyroomSystem::stroomR;

	StudyroomMember* StudyroomSystem::member = NULL;