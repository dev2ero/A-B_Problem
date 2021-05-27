#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n; cin >> n;
    vector<int> array(n);
    for(int i = array.begin(); i != array.end(); ++i) cin >> array[i];
    
    long long count[5e6+5];
    for(int i = array.begin(); i != array.end(); ++i) count[array[i]]++;
    
    sort(array.begin(), array.end());
    array.erase(unique(array.begin(), array.end()), array.end());


}
