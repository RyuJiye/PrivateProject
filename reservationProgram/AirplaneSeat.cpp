#include<iostream>
#include "AirplaneSeat.h"



void AirplaneSeat::seatDataSet(int num) {
	id = "NULL";
	res = false;
	if (num == 0) {
		type = "business";
		price = 150000;
		name = "***";
	}
	else {
		type = "economy";
		price = 100000;
		name = "---";
	}
}

void AirplaneSeat::seatSet(string id, string name, bool res) {
	this->id = id;
	this->name = name;
	this->res = res;
}

void AirplaneSeat::seatReset(int num) {
	id = "NULL";
	res = false;
	if (num == 0) {
		name = "***";
	}
	else {
		name = "---";
	}
}

bool AirplaneSeat::bookCheck() {
	return res;
}

string AirplaneSeat::returnName() {
	return name;
}

string AirplaneSeat::returnID() {
	return id;
}