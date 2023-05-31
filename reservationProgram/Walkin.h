#pragma once
#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Walkin {
	vector<string>v;
	vector<string>::iterator it = v.begin();

public:
	void walkinManage();
	void walkinSystem(string id);
};