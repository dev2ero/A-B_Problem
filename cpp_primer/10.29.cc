#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream in(argv[1]);
    istream_iterator<string> in_iter(in);
    istream_iterator<string> eof;
    vector<string> words;
    while(in_iter != eof)
	words.push_back(*in_iter++);
}
