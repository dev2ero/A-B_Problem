#include <vector>

using namespace std;

vector<int>::iterator search_vec(vector<int>::iterator beg, vector<int>::iterator end, int val) {
    for(;beg != end; beg++)
	if(*beg == val)
	    return beg;
    return end;
}
