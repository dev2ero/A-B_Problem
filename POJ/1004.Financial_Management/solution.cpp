#include <iostream>

using namespace std;

int main() {
    
    double sum = 0;
    double single = 0;

    for(int i = 0; i < 12; ++i) {
        cin >> single;
        sum += single;
    }
    
    printf("$%.2f", sum/12);
    return 0;
}
