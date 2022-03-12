#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

bool check_size(const string &s, string::size_type sz) {
    return s.size() <= sz;
}

void biggies(vector<int> &vc, const string &s) {
    auto p = find_if(vc.begin(), vc.end(),
			bind(check_size, s, placeholders::_1));
    cout << p - vc.begin() + 1 << endl;
}

int main() {
    vector<int> v = {1,2,3,4,5,6,7};
    biggies(v, "hello");
    return 0;
}
