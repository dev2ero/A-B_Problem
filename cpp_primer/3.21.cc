#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v(10);
    for(vector<int>::iterator i = v.begin(); i != v.end(); ++i) cin >> *i;

    // for(vector<int>::const_iterator i = v.cbegin(); i != v.cend()-1; ++i) cout << (*i) + (*(i+1)) << " ";

    vector<int>::const_iterator f = v.cbegin();
    vector<int>::const_iterator e = v.cend()-1;
    for(; f + 1 != e; f++, e--) cout << (*f) + (*e) << " ";
}
