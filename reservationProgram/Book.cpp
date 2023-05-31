
#include "RestaurantSystem.h"
#include "AirlineSystem.h"
#include "StudyroomSystem.h"
#include <iostream>


using  namespace std;

int main() {
	AirlineSystem a;
	RestaurantSystem r;
	StudyroomSystem s;
	while (true) {
		cout << "*****종합 예약 시스템*****" << endl;
		cout << "항공사:1, 식당:2, 독서실:3, 끝내기:4 >>";
		int m;
		cin >> m;
		if (m == 1) {
			a.airlineSystem();
		}
		else if (m == 2) {
			r.restaurantSystem();
		}
		else if (m == 3)
		{
			s.studyroomSystem();
		}
		else {
			cout << "*****종합 예약 시스템 종료*****";
			break;
		}
	}
	AirlineMember::airMemSave();
	a.airRecSave();
	StudyroomMember::studyMemSave();
	s.stroomRecSave();
	RestaurantMember::resMemSave();
	r.resRecSave();
	return 0;
}