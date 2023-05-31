#include <iostream>
#include "StudyroomMember.h"
#include "StudyroomManagerSystem.h"

using namespace std;


void  StudyroomManagerSystem::seatCountUp(int row, int col) {
		seatBookCount[row][col]++;
	}
void  StudyroomManagerSystem::seatCountDown(int row, int col) {
		seatBookCount[row][col]--;
	}
 void  StudyroomManagerSystem::genderCountUp(int n) {
		genderBookCount[n]++;
	}
 void  StudyroomManagerSystem::genderCountDown(int n) {
		genderBookCount[n]--;
	}
void  StudyroomManagerSystem::studyroomManagerSystem() {
	while (true) {
		cout << endl << "ÁÂ¼®º° ¿¹¾àÈ½¼ö:1, ¼ºº° ¿¹¾àÈ½¼ö:2, °í°´º° ¿¹¾àÈ½¼ö:3, ·Î±×¾Æ¿ô:4>>";
		int m;
		cin >> m;

		if (m == 1) {
			int num;
			cout << "ÁÂ¼®¹øÈ£>> ";
			cin >> num;
			int row = num / 10;
			int col = num % 10 - 1;
			cout << num << "¹ø ÁÂ¼®: " << seatBookCount[row][col] << endl;
		}


		else if (m == 2) {
			cout << "³²: " << genderBookCount[0] << "  ¿©: " << genderBookCount[1] << endl;
		}

		else if (m == 3) {
			StudyroomMember::prAllMember();
			StudyroomMember::chooseMember().prBookCount();
		}

		else {
			cout << "****·Î±×¾Æ¿ô ****" << endl;
			break;
		}
	}
}
int StudyroomManagerSystem::seatBookCount[15][15] = { {0,}, };
int StudyroomManagerSystem::genderBookCount[2] = { 0, };
