#include <processor.h>

Processor::Decode::Decode() {
    // declaration
    uint32_t pc;
    uint32_t registers[NUM_GP_REGISTERS];
};

Processor::Decode::~Decode(){};

void Processor::Decode::step() {
    int A;
    int B;
    int imm;
};

void Processor::Decode::register_fetch(instruction_t ir, int &A, int &B,
                                       int &imm) {
    A = registers[ir.src1];
    B = registers[ir.src2];
    imm = ir.immediate;
};