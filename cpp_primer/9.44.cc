#include <iostream>
#include <vector>
#include <string>

using namespace std;

void replace_string(string &s, const string &oldVal, const string &newVal) {
    int p = 0;
    while((p = s.find(oldVal, p)) != string::npos) {
	s.replace(p, oldVal.size(), newVal);
	p += newVal.size();
    }
}
