#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in_file;
    ofstream out_file;

    in_file.open("in.txt");
    out_file.open("out.txt");

    string data;
    getline(in_file, data);
    cout << data << endl;
    int a, b, c;
    in_file >> a >> b >> c;
    cout << a << b << c << endl;

    string s;
    int d, e, f;
    cin >> s;
    cin >> d >> e >> f;
    out_file << s << endl;
    out_file << d << e << f << endl;
}
