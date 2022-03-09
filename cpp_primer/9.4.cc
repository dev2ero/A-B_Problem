#include <vector>

using namespace std;

bool search_vec(vector<int>::iterator beg, vector<int>::iterator end, int val) {
    for(;beg != end; beg++)
	if(*beg == val)
	    return true;
    return false;
}
