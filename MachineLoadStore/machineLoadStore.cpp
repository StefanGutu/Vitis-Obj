#include "machineLoadStore.h"


// 15 - 8 | 7 - 4 | 3 - 0| 
void MLoadStore(uint16_t mem[MAX]){

#pragma HLS INTERFACE m_axi port=mem
#pragma HLS INTERFACE s_axilite port=return

    uint16_t pc = 0;
    uint16_t reg[16] = {0};

    while(1){
        uint16_t instr = mem[pc];

        uint8_t opcode = (instr >> 8) & 0xFF;
        uint8_t rx = (instr >> 4) & 0xF;
        uint8_t ry = instr & 0xF;

        switch (opcode)
        {
        case 1:
            //IDLE
            break;
        case 2:
            //LOAD: LDR rx, [ry]
            reg[rx] = mem[reg[ry]];
            break;
        case 3:
            //STORE: STR rx, [ry]
            mem[reg[ry]] = reg[rx];
            break;
        case 4:
            //HALT
            return;
        default:
            break;
        }
        

        pc++;
    }
}