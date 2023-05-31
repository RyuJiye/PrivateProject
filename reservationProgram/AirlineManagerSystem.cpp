#include<iostream>
#include"AirlineMember.h"
#include "AirlineManagerSystem.h"

void AirlineManagerSystem::seatCountUp(int n) {
		seatBookCount[n]++;
	}
void AirlineManagerSystem::seatCountDown(int n) {
		seatBookCount[n]--;
	}

void AirlineManagerSystem::airlineManagerSystem() {
	while (true) {
		cout << endl << "ÁÂ¼®º° ¿¹¾àÈ½¼ö:1, °í°´º° ¿¹¾àÈ½¼ö:2, ·Î±×¾Æ¿ô:3>>";
		int m;
		cin >> m;
		if (m == 1) {
			for (int i = 0; i < 8; i++) {
				cout << i + 1 << "¹ø ÁÂ¼®: " << seatBookCount[i] << endl;
			}
		}
		else if (m == 2) {
			AirlineMember::prAllMember();
			AirlineMember::chooseMember().prBookCount();
		}
		else {
			cout << "****·Î±×¾Æ¿ô ****" << endl;
			break;
		}
	}
}
int AirlineManagerSystem::seatBookCount[8] = { 0, };