#pragma once
class StudyroomManagerSystem {

	static int seatBookCount[15][15];
	static int genderBookCount[2];

public:
	static void seatCountUp(int row, int col);
	static void seatCountDown(int row, int col);
	static void genderCountUp(int n);
	static void genderCountDown(int n);
	static void studyroomManagerSystem();
};

