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
		cout << "ÁÂ¼®º° ¿¹¾àÈ½¼ö:1, °í°´º° ¿¹¾àÈ½¼ö:2, µ¹¾Æ°¡±â:3 >> ";
		int m;
		cin >> m;

		if (m == 1) {
			for (int i = 0; i < 3; i++) {
				cout << i * 2 + 2 << "ÀÎ¼®: " << tabBookCount[i] << endl;
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