#include <iostream>
#include <cstdio>

using namespace std;

int count(double c) {
    int cards = 0;
    double sum = 0;
    double n = 2;
    while(sum < c) {
        sum += 1 / n;
        n++;
        cards++;
    } 
    return cards;
}

int main() {
    double c;
    for(;;) {
	scanf("%lf", &c);
        if(c < 0.01) return 0;
        cout << count(c) << " card(s)" << endl;
    }
}
