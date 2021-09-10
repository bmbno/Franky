#include <processor.h>
Processor::Processor(int num_registers = 3) {
    gp_register = new int(num_registers);
}
Processor::~Processor() {
    // delete general purpose registers
    delete gp_register;
}