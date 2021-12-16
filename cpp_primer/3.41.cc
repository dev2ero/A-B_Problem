#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a[] = {0,1,2,3,4};
    vector<int> v(begin(a), end(a));
    for(int i : v) cout << i << " ";
}