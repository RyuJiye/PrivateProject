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
		cout << "날짜를 고르시오(2022.05.16~2022.05.22)" << endl;
		cout << "월:1, 화:2, 수:3,목:4,금:5,토:6,일:7 >>";
		int date;
		cin >> date;
		int time;
		cout << "07시: 1, 17시:2>>";
		cin >> time;
		cout << "예산 입력>>";
		long price;
		cin >> price;
		if (price < 100000) {
			cout << "예산 범위 내에 좌석이 없습니다" << endl;
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
		cout << "날짜를 고르시오(2022.05.16~2022.05.23)" << endl;
		cout << "월:1, 화:2, 수:3,목:4,금:5,토:6,일:7 >>";
		int date;
		cin >> date;
		cout << "예산 입력>>";
		long price;
		cin >> price;

		if (price < 100000)
		{
			cout << "예산 범위 내에 좌석이 없습니다." << endl;
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
		cout << "날짜를 고르시오(2022.05.16~2022.05.22)" << endl;
		cout << "월:1, 화:2, 수:3,목:4,금:5,토:6,일:7 >>";
		int date;
		cin >> date;
		int time;

		cout << "07시: 1, 17시:2>>";
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
		cout << "날짜를 고르시오(2022.05.16~2022.05.23)" << endl;
		cout << "월:1, 화:2, 수:3,목:4,금:5,토:6,일:7 >>";
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
		cout << endl << "출발지를 선택하시오(인천:1, 김포 : 2, 제주 : 3, 김해 : 4, 포항 : 5)" << endl << ">>";
		cin >> ap;
		cout << "도착지를 선택하시오(인천:1, 김포 : 2, 제주 : 3, 김해 : 4, 포항 : 5)" << endl << ">>";
		cin >> ld;
		cout << "왕복:1, 편도:2 >>";
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
		cout << "출발지를 선택하시오(인천:1, 김포 : 2, 제주 : 3, 김해 : 4, 포항 : 5)" << endl << ">>";
		cin >> ap;
		cout << "도착지를 선택하시오(인천:1, 김포 : 2, 제주 : 3, 김해 : 4, 포항 : 5)" << endl << ">>";
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
		cout << "출발지를 선택하시오(인천:1, 김포 : 2, 제주 : 3, 김해 : 4, 포항 : 5)" << endl << ">>";
		cin >> ap;
		cout << "도착지를 선택하시오(인천:1, 김포 : 2, 제주 : 3, 김해 : 4, 포항 : 5)" << endl << ">>";
		cin >> ld;
		cout << endl << airportList[ap - 1] << "-->" << airportList[ld - 1] << endl;
		int k = ld - ap;
		if (k < 0)k += 5;//출발지가 도착지보다 뒤에 있으면 
		if (k > 0 && k < 3 || k<-2 && k>-5) { //항공권이 1개인지 2개인지 확인
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
			cout << endl << "예약:1, 취소:2, 보기:3, 로그아웃:4 >>";
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
				cout << "*****로그아웃*****" << endl;
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
		cout << "*****한성항공*****" << endl;
		while (true) {
			cout << endl << "로그인:1, 회원가입:2, 끝내기:3 >> ";
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
				cout << "*****한성항공 예약시스템 종료*****" << endl;
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
			cout << "열기 실패";
		}
		else {
			fout << airReceipt;
		}
		fout.close();
	}

	string AirlineSystem::airR;
	class AirlineMember* AirlineSystem::member = NULL;
	