#include <iostream>
#include <vector>
#include <string>

using namespace std;

void replace_string(string &s, const string &oldVal, const string &newVal) {
    auto l = oldVal.size();
    if(!l) return;

    auto iter = s.begin();
    while(iter <= s.end() - l) {
	auto iter1 = iter;
	auto iter2 = oldVal.begin();
	while(iter2 != oldVal.end() && *iter1 == *iter2) {
	    iter1++;
	    iter2++;
	}
	if(iter2 == oldVal.end()) {
	    iter = s.erase(iter, iter1);
	    if(newVal.size()) {
		iter2 = newVal.end();
		do {
		    iter2--;
		    iter = s.insert(iter, *iter2);
		} while(iter2 > newVal.begin());
	    }
	    iter += newVal.size();
	} else iter++;
    }
}
