#include<iostream>

#define MAXN 101000

using namespace std;

int main() {
    int shop;
    cin >> shop;
    int shop_list[MAXN] = {0};
    for(int i = 0; i < shop; i++) {
        int value; cin >> value;
        shop_list[value]++;
    }

    for(int i = 1; i < MAXN; i++) {
        shop_list[i] += shop_list[i-1];
    }

    int day; cin >> day;
    for(int i = 0; i < day; i++) {
        int coin; cin >> coin;
        if(coin >= MAXN - 1) {
            cout << shop_list[MAXN-1] << endl;
        }
        else {
            cout << shop_list[coin] << endl;
        }
    }

}