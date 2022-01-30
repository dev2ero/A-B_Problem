#include<iostream>
#include<string>
using namespace std;

class NoDefault {
public:
	int val;
	NoDefault(int i) : val(i) {}
};

class C {
public:
	NoDefault nd;
	C (int i = 0) : nd(i) {}
};
