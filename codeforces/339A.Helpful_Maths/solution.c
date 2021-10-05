#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char raw_array[200];
char out_array[100];

int cmp_inc(void* a, void* b) {
    return *(char*)a < *(char*)b ? -1 : 1;
}

int main() {
    scanf("%s", raw_array);
    int raw_length = strlen(raw_array);

    int out_length = 0;
    for( int i = 0; i < raw_length; ++i ) {
        if( raw_array[i] == '+' ) continue;
        out_array[out_length++] = raw_array[i];
    }

    qsort(out_array, out_length, sizeof(char), cmp_inc);

    printf("%c", out_array[0]);
    for( int i = 1; i < out_length; ++i ) {
        printf("+%c", out_array[i]);
    }
    puts("");
    return 0;
}