#include <iostream>
#include <bitset>

using namespace std;

int main() {
    bitset<8> b;
    
    b = 3;
    cout << b << " : ";
    cout << b.to_ulong() << endl;

    b = b << 3;
    cout << b << " : ";
    cout << b.to_ulong() << endl;

    b  = b >> 1;
    cout << b << " : ";
    cout << b.to_ulong() << endl;
    
    b &= 0x08;
    cout << b << " : ";
    cout << b.to_ulong() << endl;
    
    b |= 0x0f;
    cout << b << " : ";
    cout << b.to_ulong() << endl;
    
    b = ~b;
    cout << b << " : ";
    cout << b.to_ulong() << endl;
    
    b ^= 0x55;
    cout << b << " : ";
    cout << b.to_ulong() << endl;
}
