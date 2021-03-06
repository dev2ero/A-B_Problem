#include <iostream>
#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0) {}
    ~HasPtr() { delete ps; }
private:
    std::string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr &hp) {
    ps = new std::string(*hp.ps);
    i = hp.i;
}

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    auto newps = new std::string(*rhs.ps);
    delete ps;
    ps = newps;
    i = rhs.i;
    return *this;
}
