#include <iostream>

using namespace std;

int main() {
    int w; cin >> w;
    cout << (w > 2 && w % 2 == 0) ? string("YES") : string("NO") << endl;
    return 0;
}
