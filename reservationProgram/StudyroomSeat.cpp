#include "StudyroomSeat.h"

	void StudyroomSeat::seatDataSet(int num) {
		id = "NULL";
		name = "------";
		res = false;
		gender = "-";
		age = 0;
		this->num = num;
	}

	void StudyroomSeat::seatSet(string id, string name, bool res, string gender, int age) {
		this->id = id;
		this->name = name;
		this->res = res;
		this->gender = gender;
		this->age = age;
	}

	void StudyroomSeat::seatReset() {
		id = "NULL";
		name = "---";
		res = false;
		gender = "-";
		age = 0;
	}

	string StudyroomSeat::returnGender() {
		return gender;
	}
	bool StudyroomSeat::resReturn() {
		return res;
	}
	string StudyroomSeat::returnID() {
		return id;
	}
	string StudyroomSeat::nameReturn() {
		return name;
	}

	int StudyroomSeat::returnAge() {
		return age;
	}