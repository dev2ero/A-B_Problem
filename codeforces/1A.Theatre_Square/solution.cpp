#include <iostream>


int main() {
    long long n, m, a;
    std::cin >> n >> m >> a;
    std::cout << (n / a + (bool)(n % a) ) * (m / a + (bool)(m % a)) << std::endl;
    return 0;
}
