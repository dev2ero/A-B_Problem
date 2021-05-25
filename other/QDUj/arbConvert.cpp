#define BIG_NUMBER_CONVERT_BUFFER_SIZE 1024

static int getValue(char ch);
static void reverseStr(unsigned char* src, int len);

/*
大数字串进制转换。
注：
1. 转换复用了 srcData 空间，该字段数据会被改变
2. 输入字串区分大小写，按进制 11 - 36 以大写的英文字母表示，37 - 62 以小写英文字母表示
   即输入 16 进制，则字串中的英文字母必须为大写
3. 转换缓冲 buffer 默认为 1024，可用按照实际需求更改

params：
    srcData：传入的字串，需要以 '\0' 结尾
    destData：传出的字串，需要估计好大致空间
    srcBase：原字串进制，范围 2 - 62
    destBase：目标进制，范围 2 - 62
return：
    编码长度，出错返回负数
*/
int bigNumConvert(unsigned char* srcData, unsigned char* destData, int srcBase, int destBase) {

    char byteIndex[63] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    unsigned char buffer[BIG_NUMBER_CONVERT_BUFFER_SIZE] = { 0x00 };
    unsigned char *pbuffer = buffer;
    unsigned char* src = srcData;
    unsigned char* pos = srcData;
    unsigned char* dest = destData;
    int temp = 0;

    if (src == NULL
        || dest == NULL
        || (srcBase <= 1 || srcBase >= 62)
        || (destBase <= 1 || destBase >= 62)) {
        return -1;
    }

    while (*src) {
        while (*pos) {
            temp *= srcBase;
            temp += getValue(*pos++);
            if (temp < destBase) {
                *pbuffer++ = '0';
                continue;
            }
            else {
                *pbuffer++ = byteIndex[(temp / destBase)];
                temp %= destBase;
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
