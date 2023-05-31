#include "Table.h"



	void Table::tabDataSet(int seatNum) {//처음 생상할때 정보 저장
		id = "NULL";
		name = "---";
		res = false;
		this->seatNum = seatNum;

	}

	void Table::tabSet(string id, string name) {//예약할때 정보 저장
		this->id = id;
		this->name = name;
		this->res = true;
	}

	void Table::tabReset() {//예약취소하면 정보 저장
		id = "NULL";
		name = "---";
		res = false;
	}

	bool Table::returnRes() {
		return res;
	}
	string Table::returnID() {
		return id;
	}
	string Table::returnName() {
		return name;
	}
