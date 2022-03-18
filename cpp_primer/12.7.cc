#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> new_vector(void) {
    return make_shared<vector<int>>();
}

void read_ints(shared_ptr<vector<int>> spv) {
    int v;
    while(cin >> v)
        spv->push_back(v);
}

void print_ints(shared_ptr<vector<int>> spv) {
    for(const auto &v : *spv)
        cout << v << " ";
    cout << endl;
}

int main() {
    auto spv = new_vector();
    read_ints(spv);
    print_ints(spv);
}
