#include <iostream>
#include <vector>

using namespace std;

vector<int> cur;

void permutation(vector<int> arr) {
    if(arr.size() == 1) {

    }

    for(int i : arr) {
	vector<int> sub_arr(arr.begin()+1, arr.end());
	permutation(sub_arr);
    }
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    permutation(arr);         
    return 0;
}
