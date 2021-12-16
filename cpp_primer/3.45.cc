#include <iostream>
#include <vector>

using namespace std;

int main() {
    using int_arr = int[4];
    int_arr m[3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    for(auto i : m)
        for(int j = 0; j < 3; ++j)
            cout << i[j] << " ";
}