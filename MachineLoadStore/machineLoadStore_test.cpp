#include "machineLoadStore.h"
#include <stdio.h>
#include <stdint.h>

#define MAX 256

int main() {
    uint16_t mem[MAX] = {0};

    mem[10] = 123;  

    // program:
    mem[0] = (1 << 8);  //IDLE
    mem[1] = (1 << 8);  //IDLE
    mem[2] = (2 << 8) | (0 << 4) | 10; // LDR 
    mem[3] = (3 << 8) | (0 << 4) | 11; // STR 
    mem[4] = (4 << 8); // HALT

    MLoadStore(mem);

    return 0;
}
