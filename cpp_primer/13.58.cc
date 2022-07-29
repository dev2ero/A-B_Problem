#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Foo {
public:
    Foo sorted() &&;
    Foo sorted() const &;
private:
    vector<int> data;
};

Foo Foo::sorted() && {
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const & {
    Foo ret(*this);
    return ret.sorted();
}
