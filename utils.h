#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

#define MEM_SIZE 32
#define NUM_REGISTERS 16
#define NUM_INSTR 30


typedef struct _y86_state {
    uint8_t memory[MEM_SIZE];    // Y86 is little endian
    uint64_t start_addr;
    uint8_t valid_mem;       // number of valid bytes
    uint64_t registers[NUM_REGISTERS];  
    uint64_t pc;
    uint8_t flags;

    _y86_state() {
        for (int i=0; i < MEM_SIZE; i++) {
            memory[i] = 0x0;
        };
        start_addr = 0;
        valid_mem = 0;
        for (int i=0; i < NUM_REGISTERS; i++) {
            registers[i] = 0;
        }
        pc = 0;
        flags = 0;
    }
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

typedef enum _reg_name_t {
    R_RAX,
    R_RCX,
    R_RDX,
    R_RBX,
    R_RSP,
    R_RBP,
    R_RSI,
    R_RDI,
    R_R8,
    R_R9,
    R_R10,
    R_R11,
    R_R12,
    R_R13,
    R_R14,
    R_RNONE
} reg_name_t;

struct inst_map_t {
    const char *inst_str;
    inst_t inst;
};

struct reg_map_t {
    const char *reg_str;
    reg_name_t reg;
};

extern struct inst_map_t inst_map[NUM_INSTR];
extern struct reg_map_t reg_map[NUM_REGISTERS];

#endif
