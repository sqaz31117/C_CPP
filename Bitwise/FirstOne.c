#include <stdio.h>

int FindFirstOne(unsigned short input) {
    int test_bit = 0x8000;
    int cnt = 15;
    while ((input & test_bit) >> cnt != 1) {
        cnt--;
        test_bit >>= 1;
    }
    return cnt;
}

int main() {
    // 求一個數的最高位1在第幾位
    // e.g. 32 = 2^5 => 最高位在第5位
    unsigned short input = 0x18;    // 0000 0000 0001 0010
    printf("%d\n", FindFirstOne(input));
}