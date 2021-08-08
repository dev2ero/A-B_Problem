#include <iostream>

using namespace std;


int main() {
    int n; cin >> n;
    int count[5] = {0};

    int group;
    while(n--) {
        cin >> group;
        count[group]++;
    }

    int result = count[4];
    result += count[3];
    result += count[2] / 2;

    if(count[2] % 2) {
        result += 1;
        count[1] -= 2;
    }
    result += (count[1] - count[3] < 0) ? 0 : (count[1] - count[3] + 3) / 4;

    cout << result << endl;
}
