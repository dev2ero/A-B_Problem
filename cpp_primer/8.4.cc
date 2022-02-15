#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream in("data.txt");
    if(!in) {
	cerr << "open file failed" << endl;
	return -1;
    }

    string line;
    vector<string> words;

    while(getline(in, line)) {
	words.push_back(line);
    }

    in.close();

    for(string& s : words) {
	cout << s << endl;
    }

    return 0;
}
