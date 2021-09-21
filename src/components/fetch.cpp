#include <processor.h>

Processor::Fetch::Fetch(uint32_t memory_size = 50) {
    uint32_t pc;
    instr_memory = new instruction_t[memory_size];
};

Processor::Fetch::~Fetch() {
    // delete instr_memory pointer
    delete instr_memory;
};

void Processor::Fetch::step(){

};

opcode_t Processor::Fetch::fetch_instruction(uint32_t) {
    instruction_t ir;
    ir = instr_memory[pc];
    return ir.opcode;
};

uint32_t Processor::Fetch::adder(uint32_t pc) {
    uint32_t npc = pc + 4;
    return npc;
};

bool Processor::Fetch::check_branch(bool stall) {
    bool branch_stall = false;
    // if (!stall) {

    // }
    return branch_stall;
};