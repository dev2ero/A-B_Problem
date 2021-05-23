#include<iostream>
#include<string>
#include<vector>

using namespace std;

constexpr char base64_char[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

struct InvalidBase64 {};

char base64_char_convert(char c) {
	for (size_t i = 0; i < sizeof(base64_char); ++i)
		if (base64_char[i] == c) return i;
	throw InvalidBase64(); // Invalid base64 character
}

vector<char> base64_decode(const string& src) {
	vector<char> ret;
    ret.reserve(src.length() * 3 / 4);
	for (size_t i = 0; i < src.length(); i += 4) {
		char b1 = base64_char_convert(src[i]);
		char b2 = base64_char_convert(src[i + 1]);

		ret.push_back((b1 << 2) | ((b2 >> 4 & 0b11))); // 1st 6bits, 2nd high 2bits

		if (src[i + 2] == '=') break;
		char b3 = base64_char_convert(src[i + 2]);
		ret.push_back(((b2 & 0b1111) << 4) | ((b3 >> 2) & 0b1111)); // 2nd low 4bits, 3rd high 4bits

		if (src[i + 3] == '=') break;
		char b4 = base64_char_convert(src[i + 3]);
		ret.push_back(((b3 & 0b11) << 6) | b4); // 3rd low 2bits, 4th 6bits
	}
	return ret;
}

int main() {
    string base64Str;
    cin >> base64Str;
    vector<char> vec = base64_decode(base64Str);
    for(char c : vec) {
        printf("%2X", c);
    }
    return 0;
}
