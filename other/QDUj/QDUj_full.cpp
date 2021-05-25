#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

constexpr char base64_char[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char base64_char_convert(char c) {
        for (size_t i = 0; i < sizeof(base64_char); ++i)
                if (base64_char[i] == c) return i;
        return 0;
}

vector<unsigned char> base64_decode(const string& src) {
        vector<unsigned char> ret;
        ret.reserve(src.length() * 3 / 4);
        for (size_t i = 0; i < src.length(); i += 4) {
                unsigned char b1 = base64_char_convert(src[i]);
                unsigned char b2 = base64_char_convert(src[i + 1]);

                ret.push_back((b1 << 2) | ((b2 >> 4 & 0b11))); // 1st 6bits, 2nd high 2bits

                if (src[i + 2] == '=') break;
                unsigned char b3 = base64_char_convert(src[i + 2]);
                ret.push_back(((b2 & 0b1111) << 4) | ((b3 >> 2) & 0b1111)); // 2nd low 4bits, 3rd high 4bits

                if (src[i + 3] == '=') break;
                unsigned char b4 = base64_char_convert(src[i + 3]);
                ret.push_back(((b3 & 0b11) << 6) | b4); // 3rd low 2bits, 4th 6bits
        }
        return ret;
}


static int getValue(char ch) {
    if (ch >= '0'&&ch <= '9') {
        return ch - '0';
    }
    else if (ch >= 'A'&&ch <= 'Z') {
        return ch - 'A' + 10;
    }
    else {
        return ch - 'a' + 36;
    }
}

static void reverseStr(unsigned char* src, int len) {
    int i = 0, j = len - 1;
    unsigned char temp = 0;
    while (i < j) {
        temp = src[i];
        src[i++] = src[j];
        src[j--] = temp;
    }
}

int bigNumConvert(unsigned char* srcData, unsigned char* destData) {

    char byteIndex[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unsigned char buffer[1024] = { 0x00 };
    unsigned char *pbuffer = buffer;
    unsigned char* src = srcData;
    unsigned char* pos = srcData;
    unsigned char* dest = destData;
    int temp = 0;

    while (*src) {
        while (*pos) {
            temp *= 16;
            temp += getValue(*pos++);
            if (temp < 36) {
                *pbuffer++ = '0';
                continue;
            }
            else {
                *pbuffer++ = byteIndex[(temp / 36)];
                temp %= 36;
            }
        }
        *dest++ = byteIndex[temp];
        for (pos = buffer; pos < pbuffer && *pos == '0'; pos++);
        memcpy(src, pos, pbuffer - pos);
        src[pbuffer - pos] = 0;
        pos = src;
        pbuffer = buffer;
        temp = 0;
    }

    reverseStr(destData, dest - destData);
    destData[dest - destData] = 0x00;
    return dest - destData;
}

unsigned char src[1024], dst[1024];

int main() {
    string base64Str;
    cin >> base64Str;
    vector<unsigned char> vec = base64_decode(base64Str);
    
    int index = 0;
    for(auto c : vec) {
        sprintf((char *)(src + index), "%2X", c);
        index += 2;
    }

    bigNumConvert(src, dst);
    cout << dst << endl;
    return 0;
}
