#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {5,3,6,3,9,2,5,9,1,4,2,9};

    for(int i = 0; i < v.size() - 1; i++) {
	int ith = i;
	for(int j = i + 1; j < v.size(); j++)
	    if(v[j] < v[ith])
		ith = j;
	swap(v[i], v[ith]);
    }

    for(int i : v) cout << i << " ";
}
