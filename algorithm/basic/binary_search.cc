#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &v, int target) {
    int ret = -1;
    int start = 0, end = v.size() - 1, mid;
    while(start <= end) {
        mid = start + ((end - start) >> 1);
        if(v[mid] < target)
            start = mid + 1;
        else if(v[mid] > target)
            end = mid - 1;
        else {
            ret = mid;
            break;
        }
    }
    return ret;
}

int main() {
    vector<int> v = {1,3,4,6,7,9,24,676,8987};
    cout << binary_search(v, 6) << endl;
}
