// 7세 이하 예약 불가
#include <iostream>
#include <Vector>
#include <Map>
#include <string>
#include <fstream>
using namespace std;
#include "RestaurantSystem.h"
#include"RestaurantMember.h"
#include "TabSchedule.h"
#include "RestaurantManagerSystem.h"


RestaurantSystem::RestaurantSystem() {
		RestaurantMember::RestaurantMember("Restaurant", "restaurant", 0, 0);
		for (int i = 0; i < 3; i++) {
			tabSchedule[i] = new TabSchedule * [7];
			for (int j = 0; j < 7; j++) {
				tabSchedule[i][j] = new TabSchedule[6];
			}
		}
		for (int j = 0; j < 7; j++) {
			for (int k = 0; k < 6; k++) {
				tabSchedule[0][j][k].tabScheduleDataSet(k * 2 + 10, dateList[j], 4, 2);//2인 테이블에 
				tabSchedule[1][j][k].tabScheduleDataSet(k * 2 + 10, dateList[j], 6, 4);
				tabSchedule[2][j][k].tabScheduleDataSet(k * 2 + 10, dateList[j], 2, 6);
			}
		}
	}


	void RestaurantSystem::tabScheduleShow(int n, int d) {
		cout << dateList[d - 1] << '\t';
		cout << n * 2 + 2 << "인석" << endl;
		for (int i = 0; i < 6; i++) {
			tabSchedule[n][d - 1][i].tabShow();  
		}
	}

	void RestaurantSystem::restaurantBook() {
		cout << endl<< "날짜를 고르시오(2022.05.16~2022.05.23)" << endl;
		cout << "월:1, 화:2, 수:3,목:4,금:5,토:6,일:7 >>";
		int date;
		cin >> date;
		cout << "인원 입력(6인 이하) >>";
		int peopleNum;
		cin >> peopleNum;
		cout << endl;
		int n = (peopleNum - 1) / 2;
		tabScheduleShow(n, date);
		cout << "시간 입력>>";
		int time;
		cin >> time;
		resR = (*member).returnID() + " / " + to_string(peopleNum) + " / " + dateList[date - 1] + " / " + to_string(time) + "시 / ";
		if (tabSchedule[n][date - 1][(time - 10) / 2].tabBook(member->returnID())) {
			member->bookCountUp();
			RestaurantManagerSystem::tabCountUp(n);
			resReceipt += (resR);
		}
	}

	void RestaurantSystem::restaurantCancel() {
		cout << endl<< "날짜를 고르시오(2022/05/16~2022/05/23)" << endl;
		cout << "월:1, 화:2, 수:3,목:4,금:5,토:6,일:7 >>";
		int date;
		cin >> date;
		cout << "인원 입력>>" << endl;
		int peopleNum;
		cin >> peopleNum;
		int n = (peopleNum - 1) / 2;
		tabScheduleShow(n, date);
		cout << endl << "시간 입력>>";
		int time;
		cin >> time;
		resR = (*member).returnID() + " / " + to_string(peopleNum) + " / " + dateList[date - 1] + " / " + to_string(time) + "시 / ";
		if (tabSchedule[n][date - 1][(time - 10) / 2].tabCancel(member->returnID())) {
			member->bookCountDown();
			RestaurantManagerSystem::tabCountDown(n);
			resReceipt += (resR);
		}
	}
	void RestaurantSystem::restaurantShow() {
		cout << endl<< "날짜를 고르시오(2022/05/16~2022/05/23)" << endl;
		cout << "월:1, 화:2, 수:3,목:4,금:5,토:6,일:7 >>";
		int date;
		cin >> date;
		cout << "인원 입력>>" << endl;
		int peopleNum;
		cin >> peopleNum;
		int seatNum = (peopleNum - 1) / 2;
		tabScheduleShow(seatNum, date);
	}

	void RestaurantSystem::restaurantBookSystem() {

		while (true) {
			int menu;
			cout << endl << "예약:1, 취소:2, 보기:3, 돌아가기:4 >>";
			cin >> menu;
			if (menu == 1) {
				if (member->returnAge() > 7) {
					restaurantBook();
				}
				else {
					cout << "7세 이하는 예약이 불가능 합니다";
				}
			}
			else if (menu == 2) {
				restaurantCancel();
			}
			else if (menu == 3) {
				restaurantShow();
			}
			else {
				break;
			}
		}
	}


	void RestaurantSystem::restaurantSystem() {
		while (true) {
			cout << endl << "로그인:1, 회원가입:2, 끝내기:3 >>";
			int n;
			cin >> n;
			if (n == 1) {
				member = RestaurantMember::login();
				if (member->returnID() == "Restaurant") {
					while (true) {
						cout << "고객분석:1, 워크인 관리:2, 로그아웃:3 >>";
						int m;
						cin >> m;
						if (m == 1) {
							RestaurantManagerSystem::restaurantManagerSystem();
						}
						else if (m == 2) {
							w.walkinManage();
						}
						else {
							cout << endl << "*****로그아웃*****" << endl;
							member = NULL;
							break;
						}
					}
				}
				else {
					while (true) {
						cout << "예약시스템:1, 워크인 시스템:2, 로그아웃:3 >>";
						int m;
						cin >> m;
						if (m == 1) {
							restaurantBookSystem();
						}
						else if (m == 2) {
							w.walkinSystem(member->returnID());
						}
						else {
							cout << endl << "*****로그아웃*****" << endl;
							member = NULL;
							break;
						}
					}
				}
			}

			else if (n == 2) {
				RestaurantMember::signUp();
			}

			else {
				cout << "*****식당 예약시스템 종료*****" << endl;
				break;
			}
		}
	}

	void RestaurantSystem::resRecSave() {
		string s1 = ", ", s2 = "/ ";
		const char* file = "resReceipt.txt";
		fstream fout;
		fout.open(file, ios::out | ios::trunc);
		if (!fout) {
			cout << "열기 실패";
		}
		else {
			fout << resReceipt;
		}
		fout.close();
	}

	string RestaurantSystem::resR;
	RestaurantMember* RestaurantSystem::member = NULL;