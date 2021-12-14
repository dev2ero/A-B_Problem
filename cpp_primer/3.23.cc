#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9,0};
    for(vector<int>::iterator i = v.begin();
    i != v.end();
    ++i) (*i) *= 2;
    for(int i : v) cout << i << " ";
}