#include<iostream>

using namespace std;

void exgcd(int a, int b, int g, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        g = a;
    } else {
        exgcd(b, a % b, g, y, x);
        y -= x * (a / b);
    }
}

uint64_t mypow(uint64_t a, uint64_t k,uint64_t base) {
    if (k == 0) return 1;
    a %= base;

    if (k % 2 == 1) {
        // k 是奇数
        return (a * mypow(a, k - 1,base)) % base;
    } else {
        // k 是偶数
        uint64_t sub = mypow(a, k / 2,base);
        return (sub * sub) % base;
    }
}


int main() {
    int e, c;
    cin >> e >> c;

    int n = 23333 * 10007;
    int phi = (23333-1) * (10007-1);

    int a = e, b = phi, g, x, y, d;
    exgcd(a, b, g, x, y);
    d = ((x % b) + b) % b;

    cout<<mypow(c, d, n)<<endl;
    return 0;
}
