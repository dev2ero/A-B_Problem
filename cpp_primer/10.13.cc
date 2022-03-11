#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool five_or_more(const string &s1) {
    return s1.size() >= 5;
}

int main(int argc, char *argv[]) {
    ifstream in(argv[1]);
    vector<string> words;
    string word;
    while(in >> word)
	words.push_back(word);
    auto iter = partition(words.begin(), words.end(), five_or_more);
}
