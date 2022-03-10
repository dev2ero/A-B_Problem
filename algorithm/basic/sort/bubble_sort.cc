#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr = {3,1,4,2,5,9};

    for(int j = 0; j < arr.size(); ++j)
	for(auto i = arr.begin(); i != arr.end()-1; ++i)
	    if( *i > *(i+1) ) swap(*i, *(i+1));

    for(int i : arr) cout << i << " ";
    cout << endl;
    return 0;
}
