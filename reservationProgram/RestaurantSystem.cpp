// 7�� ���� ���� �Ұ�
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
				tabSchedule[0][j][k].tabScheduleDataSet(k * 2 + 10, dateList[j], 4, 2);//2�� ���̺� 
				tabSchedule[1][j][k].tabScheduleDataSet(k * 2 + 10, dateList[j], 6, 4);
				tabSchedule[2][j][k].tabScheduleDataSet(k * 2 + 10, dateList[j], 2, 6);
			}
		}
	}


	void RestaurantSystem::tabScheduleShow(int n, int d) {
		cout << dateList[d - 1] << '\t';
		cout << n * 2 + 2 << "�μ�" << endl;
		for (int i = 0; i < 6; i++) {
			tabSchedule[n][d - 1][i].tabShow();  
		}
	}

	void RestaurantSystem::restaurantBook() {
		cout << endl<< "��¥�� ���ÿ�(2022.05.16~2022.05.23)" << endl;
		cout << "��:1, ȭ:2, ��:3,��:4,��:5,��:6,��:7 >>";
		int date;
		cin >> date;
		cout << "�ο� �Է�(6�� ����) >>";
		int peopleNum;
		cin >> peopleNum;
		cout << endl;
		int n = (peopleNum - 1) / 2;
		tabScheduleShow(n, date);
		cout << "�ð� �Է�>>";
		int time;
		cin >> time;
		resR = (*member).returnID() + " / " + to_string(peopleNum) + " / " + dateList[date - 1] + " / " + to_string(time) + "�� / ";
		if (tabSchedule[n][date - 1][(time - 10) / 2].tabBook(member->returnID())) {
			member->bookCountUp();
			RestaurantManagerSystem::tabCountUp(n);
			resReceipt += (resR);
		}
	}

	void RestaurantSystem::restaurantCancel() {
		cout << endl<< "��¥�� ���ÿ�(2022/05/16~2022/05/23)" << endl;
		cout << "��:1, ȭ:2, ��:3,��:4,��:5,��:6,��:7 >>";
		int date;
		cin >> date;
		cout << "�ο� �Է�>>" << endl;
		int peopleNum;
		cin >> peopleNum;
		int n = (peopleNum - 1) / 2;
		tabScheduleShow(n, date);
		cout << endl << "�ð� �Է�>>";
		int time;
		cin >> time;
		resR = (*member).returnID() + " / " + to_string(peopleNum) + " / " + dateList[date - 1] + " / " + to_string(time) + "�� / ";
		if (tabSchedule[n][date - 1][(time - 10) / 2].tabCancel(member->returnID())) {
			member->bookCountDown();
			RestaurantManagerSystem::tabCountDown(n);
			resReceipt += (resR);
		}
	}
	void RestaurantSystem::restaurantShow() {
		cout << endl<< "��¥�� ���ÿ�(2022/05/16~2022/05/23)" << endl;
		cout << "��:1, ȭ:2, ��:3,��:4,��:5,��:6,��:7 >>";
		int date;
		cin >> date;
		cout << "�ο� �Է�>>" << endl;
		int peopleNum;
		cin >> peopleNum;
		int seatNum = (peopleNum - 1) / 2;
		tabScheduleShow(seatNum, date);
	}

	void RestaurantSystem::restaurantBookSystem() {

		while (true) {
			int menu;
			cout << endl << "����:1, ���:2, ����:3, ���ư���:4 >>";
			cin >> menu;
			if (menu == 1) {
				if (member->returnAge() > 7) {
					restaurantBook();
				}
				else {
					cout << "7�� ���ϴ� ������ �Ұ��� �մϴ�";
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
			cout << endl << "�α���:1, ȸ������:2, ������:3 >>";
			int n;
			cin >> n;
			if (n == 1) {
				member = RestaurantMember::login();
				if (member->returnID() == "Restaurant") {
					while (true) {
						cout << "���м�:1, ��ũ�� ����:2, �α׾ƿ�:3 >>";
						int m;
						cin >> m;
						if (m == 1) {
							RestaurantManagerSystem::restaurantManagerSystem();
						}
						else if (m == 2) {
							w.walkinManage();
						}
						else {
							cout << endl << "*****�α׾ƿ�*****" << endl;
							member = NULL;
							break;
						}
					}
				}
				else {
					while (true) {
						cout << "����ý���:1, ��ũ�� �ý���:2, �α׾ƿ�:3 >>";
						int m;
						cin >> m;
						if (m == 1) {
							restaurantBookSystem();
						}
						else if (m == 2) {
							w.walkinSystem(member->returnID());
						}
						else {
							cout << endl << "*****�α׾ƿ�*****" << endl;
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
				cout << "*****�Ĵ� ����ý��� ����*****" << endl;
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
			cout << "���� ����";
		}
		else {
			fout << resReceipt;
		}
		fout.close();
	}

	string RestaurantSystem::resR;
	RestaurantMember* RestaurantSystem::member = NULL;