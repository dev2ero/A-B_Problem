std::istream &read(std::istream &is, Person& per) {
	is >> per.strName >> per.strAddress;
	return is;
}

str::ostream &print(std::ostream &os, const Person& per) {
	os << per.getName() << per.getAddress() << endl;
	return os;
}
