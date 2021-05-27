#include <iostream>
#include <string>
#include <unordered_map>

#define UNCODE(a) (a>='A'?((a>'Q'?(a-'A'-1):(a-'A'))/3+2):a-'0')  

//#define DEBUG

using namespace std;

string automata(const string& raw) {
    string cooked;
    for(char c : raw) {
        if(c == '-') continue;
        else cooked.push_back(UNCODE(c) + '0');
    }
    cooked.insert(3, "-");
    return cooked;
}

int main() {
    int loop;
    cin >> loop;

    unordered_map<string, int> sn;
    
    while(loop--) {
        string raw;
        cin >> raw;
        sn[automata(raw)]++;
    }
#ifdef DEBUG
    for( const auto& [key, value] : sn ) 
        std::cout << "Key:[" << key << "] Value:[" << value << "]\n";
#endif

    for( const auto& [key, value] : sn ) 
        if(value > 1) cout << key << " " << value << endl;
    
    return 0;
}
