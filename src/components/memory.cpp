#include <processor.h>

Processor::Memory::Memory(uint32_t memory_size = 0X4000) {
    _memory = new int[memory_size];
    uint32_t pc;
    bool branch_taken;
    int alu_out;
    uint32_t memory_input;
    uint32_t destination;
};

Processor::Memory::~Memory() {
    // Delete memory
    delete _memory;
}

uint32_t Processor::Memory::load(uint32_t address) {
    // Access memory
    return _memory[address];
};

void Processor::Memory::store(uint32_t address, uint32_t value) {
    // Store memory at address
    _memory[address] = value;
};