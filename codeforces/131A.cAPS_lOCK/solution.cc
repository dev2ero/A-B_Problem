#include <iostream>
#include <cctype>

using namespace std;

int main() {
	string s;
	cin >> s;

	if(s.size() == 1 && islower(s[0])) {
		s[0] = toupper(s[0]);
		cout << s[0] << endl;
		return 0;
	}

	bool is_all_upper = true;
	for(auto i = s.cbegin() + 1; i != s.cend(); ++i)
		if(islower(*i)) is_all_upper = false;

	if(is_all_upper)
	for(auto i = s.begin(); i != s.end(); ++i) {
		if(i == s.begin())
			isupper(*i) ? *i = tolower(*i) : *i = toupper(*i);
		else
			*i = tolower(*i);
	}

	cout << s << endl;
}
