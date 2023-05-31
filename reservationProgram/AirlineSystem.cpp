#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include "AirlineSystem.h"
#include "AirlineMember.h"
#include "AirlineManagerSystem.h"



	void  AirlineSystem::bookSystem1(int ap, int ld) {
		cout << airportList[ap - 1] << "-->" << airportList[ld - 1] << endl;
		int k = ld - ap;
		if (k < 0)k = k + 5;
		cout << "��¥�� ���ÿ�(2022.05.16~2022.05.22)" << endl;
		cout << "��:1, ȭ:2, ��:3,��:4,��:5,��:6,��:7 >>";
		int date;
		cin >> date;
		int time;
		cout << "07��: 1, 17��:2>>";
		cin >> time;
		cout << "���� �Է�>>";
		long price;
		cin >> price;
		if (price < 100000) {
			cout << "���� ���� ���� �¼��� �����ϴ�" << endl;
		}
		else {
			if (time == 1) {
				apSchedule[ap - 1][k - 1][date - 1].seatShow(price);
				airR = (*member).returnID() + " / " + airportList[ap - 1] + " / " + airportList[ld - 1] + " / " + dateList[date - 1] + " / " + timeList[time] + " / ";
				if (apSchedule[ap - 1][k - 1][date - 1].seatBook((*member).returnID())) {
					(*member).mileageUp();
					member->bookCountUp();
					airReceipt += (airR);
				}

			}
			else {
				apSchedule[ap - 1][k - 1 + 5][date - 1].seatShow(price);
				airR = (*member).returnID() + " / " + airportList[ap - 1] + " / " + airportList[ld - 1] + " / " + dateList[date - 1] + " / " + timeList[time] + " / ";
				if (apSchedule[ap - 1][k - 1 + 5][date - 1].seatBook((*member).returnID())) {
					(*member).mileageUp();
					member->bookCountUp();
					airReceipt += (airR);
				}
			}

			cout << endl;
		}
	}


	void  AirlineSystem::bookSystem2(int ap, int ld) {
		cout << airportList[ap - 1] << "-->" << airportList[ld - 1] << endl;
		int k = ld - ap;
		if (k < 0)k += 5;
		cout << "��¥�� ���ÿ�(2022.05.16~2022.05.23)" << endl;
		cout << "��:1, ȭ:2, ��:3,��:4,��:5,��:6,��:7 >>";
		int date;
		cin >> date;
		cout << "���� �Է�>>";
		long price;
		cin >> price;

		if (price < 100000)
		{
			cout << "���� ���� ���� �¼��� �����ϴ�." << endl;
		}
		else {

			apSchedule[ap - 1][k - 1][date - 1].seatShow(price);
			airR = (*member).returnID() + " / " + airportList[ap - 1] + " / " + airportList[ld - 1] + " / " + dateList[date - 1] + " / " + timeList[0] + " / ";
			if (apSchedule[ap - 1][k - 1][date - 1].seatBook((*member).returnID())) {
				(*member).mileageUp();
				member->bookCountUp();
				airReceipt += (airR);
			}
		}
		cout << endl;
	}


	void  AirlineSystem::cancelSystem1(int ap, int ld) {
		cout << airportList[ap - 1] << "-->" << airportList[ld - 1] << endl;
		int k = ld - ap;
		if (k < 0)k = k + 5;
		cout << "��¥�� ���ÿ�(2022.05.16~2022.05.22)" << endl;
		cout << "��:1, ȭ:2, ��:3,��:4,��:5,��:6,��:7 >>";
		int date;
		cin >> date;
		int time;

		cout << "07��: 1, 17��:2>>";
		cin >> time;
		if (time == 1) {
			apSchedule[ap - 1][k - 1][date - 1].seatShow();
			airR = (*member).returnID() + " / " + airportList[ap - 1] + " / " + airportList[ld - 1] + " / " + dateList[date - 1] + " / " + timeList[0] + " / ";
			if (apSchedule[ap - 1][k - 1][date - 1].seatCancel((*member).returnID())) {
				(*member).mileageDown();
				member->bookCountDown();
				airReceipt += (airR);
				
			}

		}
		else {
			apSchedule[ap - 1][k - 1 + 5][date - 1].seatShow();
			airR = (*member).returnID() + " / " + airportList[ap - 1] + " / " + airportList[ld - 1] + " / " + dateList[date - 1] + " / " + timeList[time] + " / ";
			if (apSchedule[ap - 1][k - 1 + 5][date - 1].seatCancel((*member).returnID())) {
				(*member).mileageDown();
				member->bookCountDown();
				airReceipt += (airR);
				
			}
		}
		cout << endl;
	}


	void AirlineSystem::cancelSystem2(int ap, int ld) {
		cout << airportList[ap - 1] << "-->" << airportList[ld - 1] << endl;
		int k = ld - ap;
		if (k < 0)k += 5;
		cout << "��¥�� ���ÿ�(2022.05.16~2022.05.23)" << endl;
		cout << "��:1, ȭ:2, ��:3,��:4,��:5,��:6,��:7 >>";
		int date;
		cin >> date;
		apSchedule[ap - 1][k - 1][date - 1].seatShow();
		airR = (*member).returnID() + " / " + airportList[ap - 1] + " / " + airportList[ld - 1] + " / " + dateList[date - 1] + " / " + timeList[0] + " / ";
		if (apSchedule[ap - 1][k - 1][date - 1].seatCancel((*member).returnID())) {
			(*member).mileageDown();
			member->bookCountDown();
			airReceipt += (airR);
			
		}
		cout << endl;
	}




	void  AirlineSystem::airlineBook() {

		int ap, ld, n;
		cout << endl << "������� �����Ͻÿ�(��õ:1, ���� : 2, ���� : 3, ���� : 4, ���� : 5)" << endl << ">>";
		cin >> ap;
		cout << "�������� �����Ͻÿ�(��õ:1, ���� : 2, ���� : 3, ���� : 4, ���� : 5)" << endl << ">>";
		cin >> ld;
		cout << "�պ�:1, ��:2 >>";
		cin >> n;
		if (n == 1) {
			int k = ld - ap;
			if (k > 0 && k < 3 || k<-2 && k>-5) {
				bookSystem1(ap, ld);
				bookSystem2(ld, ap);
			}
			else {
				bookSystem2(ap, ld);
				bookSystem1(ld, ap);
			}

		}

		else {
			int k = ld - ap;
			if (k > 0 && k < 3 || k<-2 && k>-5) {
				bookSystem1(ap, ld);
			}
			else {
				bookSystem2(ap, ld);
			}
		}
	}

	void  AirlineSystem::airlineCancel() {
		int ap, ld;
		cout << "������� �����Ͻÿ�(��õ:1, ���� : 2, ���� : 3, ���� : 4, ���� : 5)" << endl << ">>";
		cin >> ap;
		cout << "�������� �����Ͻÿ�(��õ:1, ���� : 2, ���� : 3, ���� : 4, ���� : 5)" << endl << ">>";
		cin >> ld;
		int k = ld - ap;
		if (k > 0 && k < 3 || k<-2 && k>-5) {
			cancelSystem1(ap, ld);
		}
		else {
			cancelSystem2(ap, ld);

		}
	}


	void  AirlineSystem::airlineShow() {
		int ap, ld;
		cout << "������� �����Ͻÿ�(��õ:1, ���� : 2, ���� : 3, ���� : 4, ���� : 5)" << endl << ">>";
		cin >> ap;
		cout << "�������� �����Ͻÿ�(��õ:1, ���� : 2, ���� : 3, ���� : 4, ���� : 5)" << endl << ">>";
		cin >> ld;
		cout << endl << airportList[ap - 1] << "-->" << airportList[ld - 1] << endl;
		int k = ld - ap;
		if (k < 0)k += 5;//������� ���������� �ڿ� ������ 
		if (k > 0 && k < 3 || k<-2 && k>-5) { //�װ����� 1������ 2������ Ȯ��
			for (int i = 0; i < 7; i++) {
				apSchedule[ap - 1][k - 1][i].seatShow();
				apSchedule[ap - 1][k - 1 + 5][i].seatShow();
			}
		}
		else {
			for (int i = 0; i < 7; i++) {
				apSchedule[ap - 1][k - 1][i].seatShow();
			}
		}
		cout << endl;
	}

	void  AirlineSystem::airlineBookSystem() {
		while (true) {
			int menu;
			cout << endl << "����:1, ���:2, ����:3, �α׾ƿ�:4 >>";
			cin >> menu;
			cout << endl;
			if (menu == 1) {
				airlineBook();
			}
			else if (menu == 2) {
				airlineCancel();
			}
			else if (menu == 3) {
				airlineShow();
			}
			else {
				cout << "*****�α׾ƿ�*****" << endl;
				member = NULL;
				break;
			}
		}
	}

	AirlineSystem::AirlineSystem() {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 6; j++) {
				for (int d = 0; d < 7; d++) {

					apSchedule[i][j][d].setTakeoff(airportList[i]);
					if (j < 4) {
						apSchedule[i][j][d].setLanding(airportList[i + j + 1]);
					}
					else {
						apSchedule[i][j][d].setLanding(airportList[i + j + 2]);
					}
					apSchedule[i][j][d].setDate(dateList[d]);
					apSchedule[i][j][d].setTime((j / 2) * 5 + 7);
				}
			}
		}
	}

	void  AirlineSystem::airlineSystem() {
		cout << "*****�Ѽ��װ�*****" << endl;
		while (true) {
			cout << endl << "�α���:1, ȸ������:2, ������:3 >> ";
			int n;
			cin >> n;
			if (n == 1) {
				member = AirlineMember::login();
				if (member->returnID() == "AirlineManager") {
					AirlineManagerSystem::airlineManagerSystem();
				}

				else {
					airlineBookSystem();
				}
			}

			else if (n == 2) {
				AirlineMember::signUp();
			}

			else {
				cout << "*****�Ѽ��װ� ����ý��� ����*****" << endl;
				break;
			}
		}
	}

	void AirlineSystem::airRecSave() {
		string s1 = ", ", s2 = "/ ";
		const char* file = "airReceipt.txt";
		fstream fout;
		fout.open(file, ios::out | ios::trunc);
		if (!fout) {
			cout << "���� ����";
		}
		else {
			fout << airReceipt;
		}
		fout.close();
	}

	string AirlineSystem::airR;
	class AirlineMember* AirlineSystem::member = NULL;
	