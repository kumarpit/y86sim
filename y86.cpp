#include <iostream>
#include "y86.h"

using namespace std;

// this should get a state struct
Y86Sim::Y86Sim(uint64_t start_addr, uint64_t valid_mem) {
    this->state.start_addr = start_addr;
    this->state.valid_mem = valid_mem;
    this->state.flags = 0;
    this->state.pc = 0;
}

bool Y86Sim::read_quad(uint64_t address, uint64_t &value) {  
    if (!this->is_valid_addr(address)) return false;
    auto [start, end] = this->get_addr_indices(address);
    value = 0;
    while (end >= start) {
        value = value + this->state.memory[end];
        if (end-- != start) value = value << 8;
    }
    return true;
}

bool Y86Sim::write_quad(uint64_t address, uint64_t value) {
    if (!this->is_valid_addr(address)) return false;
    auto [start, end] = this->get_addr_indices(address);
    for (int i=start; i <= end; i++) {
        this->state.memory[i] = (uint8_t) value & 0xff;
        value = value >> 8;
    }
    return true;
}

bool Y86Sim::is_valid_addr(uint64_t address) {
    if (address < this->state.start_addr) return false;
    int start = address - this->state.start_addr; //start index
    int end = start + 7; // end index
    int lastValidIndex = start + this->state.valid_mem - 1;
    if (end >= MEM_SIZE || end > lastValidIndex) {
        return false;
    };
    return true; 
}

void Y86Sim::dump_state() {
    cout << "PC: " << this->state.pc << "       " << "FLAGS: " << this->state.flags << endl;
    cout << "\n";
    for (int i=0; i < NUM_REGISTERS; i++) {
        cout << reg_map[i].reg_str << ": " << this->state.registers[i] << endl;
    }
    cout << "\n";
    for (int i=0; i < MEM_SIZE / 16; i++) {
        cout << hex << this->state.start_addr + i << ": ";
        for (int j=i*16; j < ((i*16) + 16); j++) {
            cout << this->state.memory[j] << " ";
        }
        cout << "\n";
    }
}

pair<int, int> Y86Sim::get_addr_indices(uint64_t address) {
    int start = address - this->state.start_addr; //start index
    int end = start + 7; // end index
    return make_pair(start, end);
}


