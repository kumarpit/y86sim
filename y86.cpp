#include <iostream>
#include "y86.h"

using namespace std;

// this should get a state struct
Y86Sim::Y86Sim(uint64_t start_addr, uint64_t valid_mem) {
    this->start_addr = start_addr;
    this->valid_mem = valid_mem;
    this->flags = 0;
    this->pc = 0;
}

bool Y86Sim::read_quad(uint64_t address, uint64_t &value) {  
    if (!this->is_valid_addr(address)) return false;
    auto [start, end] = this->get_addr_indices(address);
    value = 0;
    while (end >= start) {
        value = value + this->memory[end];
        if (end-- != start) value = value << 8;
    }
    return true;
}

bool Y86Sim::write_quad(uint64_t address, uint64_t value) {
    if (!this->is_valid_addr(address)) return false;
    auto [start, end] = this->get_addr_indices(address);
    for (int i=start; i <= end; i++) {
        this->memory[i] = (uint8_t) value & 0xff;
        value = value >> 8;
    }
    return true;
}

bool Y86Sim::is_valid_addr(uint64_t address) {
    if (address < this->start_addr) return false;
    int start = address - this->start_addr; //start index
    int end = start + 7; // end index
    int lastValidIndex = this->start_addr + (this->valid_mem - 1);
    if (end >= MEM_SIZE || end > lastValidIndex) {
        return false;
    };
    return true;
}

void Y86Sim::dump_state() {
    // nice terminal output
}

pair<int, int> Y86Sim::get_addr_indices(uint64_t address) {
    int start = address - this->start_addr; //start index
    int end = start + 7; // end index
    return make_pair(start, end);
}


