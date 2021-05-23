#include<iostream>
#include<cstring>

using namespace std;

int F[10000][2500];

void getF() {
    for (int i = 3; i < 10000; i++)
    {
        int in = 0;
        int j;
        for (j = 1; j <= F[i - 1][0]; j++)
        {
            F[i][j] = F[i - 1][j] + F[i - 2][j] + in;
            in = F[i][j] / 10;
            F[i][j] = F[i][j] % 10;
            F[i][0]++;
        }
        if (in)
        {
            F[i][j] = in;
            F[i][0]++;
        }
    }
}

int main() {
    memset(F, 0, sizeof(F));
    F[1][1] = 1; F[1][0] = 1;
    F[2][1] = 1; F[2][0] = 1;

    getF();

    int index;
    while(cin >> index) {
        for (int j = F[index][0]; j >= 1; j--) cout << F[index][j];
        cout << endl;           
    }
}
