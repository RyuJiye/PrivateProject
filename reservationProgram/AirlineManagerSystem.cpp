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
		cout << endl << "�¼��� ����Ƚ��:1, ���� ����Ƚ��:2, �α׾ƿ�:3>>";
		int m;
		cin >> m;
		if (m == 1) {
			for (int i = 0; i < 8; i++) {
				cout << i + 1 << "�� �¼�: " << seatBookCount[i] << endl;
			}
		}
		else if (m == 2) {
			AirlineMember::prAllMember();
			AirlineMember::chooseMember().prBookCount();
		}
		else {
			cout << "****�α׾ƿ� ****" << endl;
			break;
		}
	}
}
int AirlineManagerSystem::seatBookCount[8] = { 0, };