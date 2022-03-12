#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v = {1,2,3,4,4,5,5,5,6,6,7};
    list<int> l;

    unique_copy(v.begin(), v.end(), back_inserter(l));

    for(int i : l) cout << i << " ";
}
