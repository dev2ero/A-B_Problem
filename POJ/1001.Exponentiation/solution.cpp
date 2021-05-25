#include <iostream>
#include <string>
#include <algorithm>

//#define DEBUG 

using namespace std;


void plusString(string& str1, string str2) {
    
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    str1.size() < str2.size() ? str1.resize(str2.size(), '0') : str2.resize(str1.size(), '0') ;
    
    int add = 0;
    for(int i = 0; i < str1.size(); ++i) {
        int out = str1[i] - '0' + str2[i] - '0' + add;
        str1[i] = out % 10 + '0';
        add = out / 10;
    }

    if(add != 0) str1.push_back(add + '0');

    reverse(str1.begin(), str1.end());
    return;
}


string format(string raw, int bits, bool is_integer) {
    if(is_integer) {
        for(;;) {
            if(raw[0] == '0') raw.erase(raw.begin());
            else break;
        }
    } else {
        raw.insert(raw.begin() + (raw.size() - bits), '.');
        for(;;) {
            if(raw[0] == '0') raw.erase(raw.begin());
            else break;
        }
        for(;;) {
            if(raw[raw.size() - 1] == '0') raw.erase(raw.end() - 1);
            else break;
        }
        if(raw[raw.size() - 1] == '.') raw.erase(raw.end() - 1);
    }
    if(raw == "") return "0";
    else return raw;
}


struct BigNum {
    string num_str;

    BigNum() : num_str("") {}

    BigNum(string num_str) : num_str(num_str) {}

    int size() const {
        return this->num_str.size();
    }

    char operator[] (int i) const {
        return this->num_str[i];
    }
};


BigNum operator* (const BigNum& num1, const BigNum& num2) {
    string ans("0");

    for(int i = num1.size() - 1; i >= 0; --i) {
        string temp;
        int add = 0;

        temp.resize(num1.size() - 1 - i, '0');

        for(int j = num2.size() - 1; j >= 0; --j) {
            int out = (num1[i] - '0') * (num2[j] - '0') + add;
            temp.push_back(out % 10 + '0');
            add = out / 10;
        }

        if(add != 0) temp.push_back(add + '0');

        reverse(temp.begin(), temp.end());
#ifdef DEBUG
        cout << "ans " << ans << " temp " << temp << endl;
#endif
        plusString(ans, temp);
    }

    return BigNum(ans);
}


int main() {
#ifdef DEBUG
    string a, b;
    cin >> a >> b;
    cout << (BigNum(a) * BigNum(b)).num_str << endl << endl;
#endif
    string R; int n;

    while(cin >> R >> n) {
        BigNum ori_sum("1");
        BigNum base; int mag;

#ifdef DEBUG
        cout << endl << "Handle " << R << " " << n << endl;
#endif
        bool is_integer;
        if(R.find('.') != R.npos) {
            is_integer = false;
            mag = R.size() - 1 - R.find('.');
            R.erase(R.begin() + R.find('.'));
            base.num_str = R;
        } else {
            is_integer = true;
            mag = 0;
            base.num_str = R;
        }

#ifdef DEBUG
        cout << "Filter " << base.num_str << " " << mag << endl;
#endif

        int n_backup = n;
        while(n > 0) {
#ifdef DEBUG
            cout << "ori_sum " << ori_sum.num_str << " base " << base.num_str << endl;
#endif
            if(n & 1) ori_sum = ori_sum * base;
            base = base * base;
            n >>= 1;
        }

        cout << format(ori_sum.num_str, mag*n_backup, is_integer) << endl;
    }

    return 0;
}
