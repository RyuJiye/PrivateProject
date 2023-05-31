#include <iostream>
using namespace std;

#include "RestaurantManagerSystem.h"
#include "RestaurantMember.h"

void RestaurantManagerSystem::tabCountUp(int n) {
	tabBookCount[n]++;
}

void RestaurantManagerSystem::tabCountDown(int n) {
	tabBookCount[n]--;
}

void RestaurantManagerSystem::restaurantManagerSystem() {
	while (true) {
		cout << "�¼��� ����Ƚ��:1, ���� ����Ƚ��:2, ���ư���:3 >> ";
		int m;
		cin >> m;

		if (m == 1) {
			for (int i = 0; i < 3; i++) {
				cout << i * 2 + 2 << "�μ�: " << tabBookCount[i] << endl;
			}
		}
		else if (m == 2) {
			RestaurantMember::prAllMember();
			RestaurantMember::chooseMember().prBookCount();
		}

		else {
			break;
		}
	}
}
int RestaurantManagerSystem::tabBookCount[3] = { 0, };