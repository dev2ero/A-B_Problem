#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5};
    for(int &i : v) i%2 == 1 ? i*=2 : 0;
    for(int i : v)  cout << i << " ";
}