#include <iostream>

using namespace std;

int main() {
	string s; cin >> s;
	int status = 0;

	for(char c : s) {
		switch(status) {
			case 0:
				if(c == 'h') status++;
				break;
			case 1:
				if(c == 'e') status++;
				break;
			case 2:
				if(c == 'l') status++;
				break;
			case 3:
				if(c == 'l') status++;
				break;
			case 4:
				if(c == 'o') {
					cout << "YES" << endl;
					return 0;
				}
		}
	}
	cout << "NO" << endl;
	return 0;
}
