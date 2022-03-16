#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v = {3,1,4,1,5,9};
    sort(v.begin(), v.end());
    for(int i : v) cout << i << " ";
}
