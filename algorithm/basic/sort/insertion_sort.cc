#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {4,2,6,1,6,8,3,9,2};

    for(int i = 1; i < v.size(); i++) {
	int tmp = v[i];
	int j;
	for(j = i - 1; j >= 0; j--) {
	    if(v[j] > tmp)
		v[j+1] = v[j];
	    else
		break;
	}
	v[j+1] = tmp;
    }

    for(int i : v) cout << i << " ";
}
