#include <iostream>

using namespace std;

int main() {
	string s = "hello, world!";
	for(auto i = s.begin(); i != s.end();){
		if(ispunct(*i)) {
			s.erase(i);
		} else {
			i++;
		}
	}
	cout << s << endl;
}
