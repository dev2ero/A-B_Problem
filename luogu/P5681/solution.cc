#include <iostream>
#include <cstring>

using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    a * a > b * c ? puts("Alice") : puts("Bob");
    return 0;
}
