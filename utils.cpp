#include <cstring>
#include "utils.h"

struct inst_map_t inst_map[NUM_INSTR] = {
    { "nop", I_NOP},
    { "halt", I_HALT},
    { "rrmovq", I_RRMOVQ},
    { "irmovq", I_IRMOVQ},
    { "rmmovq", I_RMMOVQ},
    { "mrmovq", I_MRMOVQ},
    { "pushq", I_PUSHQ},
    { "popq", I_POPQ},
    { "call", I_CALL},
    { "ret", I_RET},
    { "j", I_J},
    { "jeq", I_JEQ},
    { "jne", I_JNE},
    { "jl", I_JL},
    { "jle", I_JLE},
    { "jg", I_JG},
    { "jge", I_JGE},
    { "addq", I_ADDQ},
    { "subq", I_SUBQ},
    { "mulq", I_MULQ},
    { "modq", I_MODQ},
    { "divq", I_DIVQ},
    { "andq", I_ANDQ},
    { "xorq", I_XORQ},
    { "cmoveq", I_CMOVEQ},
    { "cmovne", I_CMOVNE},
    { "cmovl", I_CMOVL},
    { "cmovle", I_CMOVLE},
    { "cmovg", I_CMOVG},
    { "cmovge", I_CMOVGE }
};

inst_t inst_to_enum(const char *str) {
    for (int i = 0; i < NUM_INSTR; i++) {
        if (strcmp(str, inst_map[i].inst_str) == 0) {
            return inst_map[i].inst;
        }
    }
    return I_INVALID;
};