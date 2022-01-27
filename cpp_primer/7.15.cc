class Person {
private:
	string strName;
	string strAddress;
public:
	Person() = default;
	Person(const string &name, const string &addr) {
		strName = name;
		strAddress = addr;
	}
	Person(const std::istream &is) {
		is >> *this;
	}
public:
	string getName() const { return strName; }
	string getAddress() const { return strAddress; }
};
