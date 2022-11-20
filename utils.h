#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

#define NUM_INSTR 30

typedef struct _y86_state {
    uint8_t memory[1024];
    uint8_t start_addr;
    uint8_t valid_mem;
    uint64_t registers[16];
    uint64_t pc;
    uint8_t flags;
} y86_state;

typedef struct _y86_inst {
    uint8_t rA;
    uint8_t rB;
    uint64_t constval;
    char instruction[10];  // null terminated
} y86_inst;

typedef enum _inst_t {
    I_NOP,
    I_HALT,
    I_RRMOVQ,
    I_IRMOVQ,
    I_RMMOVQ,
    I_MRMOVQ,
    I_PUSHQ,
    I_POPQ,
    I_CALL,
    I_RET,
    I_J,
    I_JEQ,
    I_JNE,
    I_JL,
    I_JLE,
    I_JG,
    I_JGE,
    I_ADDQ,
    I_SUBQ,
    I_MULQ,
    I_MODQ,
    I_DIVQ,
    I_ANDQ,
    I_XORQ,
    I_CMOVEQ,
    I_CMOVNE,
    I_CMOVL,
    I_CMOVLE,
    I_CMOVG,
    I_CMOVGE,
    I_INVALID
} inst_t;

/* validate instruction, if valid return corresponding enum */
inst_t inst_to_enum(const char *str);

struct inst_map_t {
        const char *inst_str;
        inst_t inst;
};


#endif
