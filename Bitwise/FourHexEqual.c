#include <stdio.h>
#include <stdbool.h>

bool FourHexEqual(unsigned short input) {
    unsigned short hex[4];

    hex[0] = input & 0x000F;
    hex[1] = (input & 0x00F0) >> 4;
    hex[2] = (input & 0x0F00) >> 8;
    hex[3] =(input & 0xF000) >> 12;
    
    return ((hex[0] == hex[1]) && (hex[1] == hex[2]) && (hex[2] == hex[3]));
}

int main() {
    // Test: 0x1111 -> yes, 0x1101 -> no
    if (FourHexEqual(0x1101)) {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
}