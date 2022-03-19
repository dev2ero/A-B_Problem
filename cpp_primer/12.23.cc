#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const char *c1 = "hello";
    const char *c2 = "world";
    char *r = new char[strlen(c1) + strlen(c2) + 1];
    delete [] r;
}
