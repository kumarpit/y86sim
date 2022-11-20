#ifndef Y86_H
#define Y86_H

#include <stdint.h>

#define FLAG_O 0x10
#define FLAG_Z 0x40
#define FLAG_S 0x80

#define MEM_SIZE 1024
#define NUM_REGISTERS 16

class Y86Sim {
    public:
        uint8_t memory[MEM_SIZE];          // Y86 is little endian
        uint64_t start_addr;
        uint64_t valid_mem;                // number of valid bytes
        uint64_t registers[NUM_REGISTERS];
        uint64_t pc;
        uint64_t flags;

        Y86Sim(uint64_t start_addr, uint64_t valid_mem);

        bool read_quad(uint64_t address, uint64_t &value);
        bool write_quad(uint64_t address, uint64_t value);
        void dump_state();
    
    private:
        bool is_valid_addr(uint64_t address);
        std::pair<int, int> get_addr_indices(uint64_t address);    
};


#endif