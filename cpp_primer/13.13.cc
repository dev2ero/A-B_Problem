#include <iostream>
#include <vector>

using namespace std;

struct X {
    X() { cout << "X()" << endl; }
    X(const X&) { cout << "X(const X&)" << endl; }
    X& operator=(const X &rhs) {
	cout << "=(const X&)" << endl;
	return *this;
    }
    ~X() { cout << "~X()" << endl; }
};

void f1(X x) {

}

void f2(X &x) {

}

int main() {
    cout << "X x" << endl;
    X x;
    cout << endl;

    cout << "f1(x)" << endl;
    f1(x);
    cout << endl;

    cout << "f2(x)" << endl;
    f2(x);
    cout << endl;

    cout << "new x" << endl;
    X *px = new X;
    cout << endl;

    cout << "push_back" << endl;
    vector<X> vx;
    vx.push_back(x);
    cout << endl;

    cout << "delete px" << endl;
    delete px;
    cout << endl;

    cout << "X y = x; y = x" << endl;
    X y = x;
    y = x;
    cout << endl;
}
