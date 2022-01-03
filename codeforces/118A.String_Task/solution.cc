#include <iostream>
#include <cctype>

using namespace std;

int main() {
	string input;
	string output;
	string a("AOYEUIaoyeui");
	cin >> input;
	for(char c : input) {
		if(a.find(c) != a.npos) continue;
		output += '.';
		if(isupper(c)) output += tolower(c);
		else output += c;
	}
	cout << output << endl;
}
