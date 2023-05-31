
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
		cout << "*****���� ���� �ý���*****" << endl;
		cout << "�װ���:1, �Ĵ�:2, ������:3, ������:4 >>";
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
			cout << "*****���� ���� �ý��� ����*****";
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