#include "Table.h"



	void Table::tabDataSet(int seatNum) {//ó�� �����Ҷ� ���� ����
		id = "NULL";
		name = "---";
		res = false;
		this->seatNum = seatNum;

	}

	void Table::tabSet(string id, string name) {//�����Ҷ� ���� ����
		this->id = id;
		this->name = name;
		this->res = true;
	}

	void Table::tabReset() {//��������ϸ� ���� ����
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
