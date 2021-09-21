#include <processor.h>
Processor::Processor(int num_registers = 3) {
    gp_register = new int(num_registers);
    clock_cycle = 0;
    stall = false;
}
Processor::~Processor() {
    // delete general purpose registers
    delete gp_register;
    delete clock_cycle;
    delete stall;
}

void Processor::step(){
    // Fetch *fetch_obj = new Fetch();
    // Decode decode_obj();
    // Execution exe_obj();
    // Memory mem_obj();
    // WriteBack wb_obj();

    // fetch_obj.step();
    // decode_obj.step();
    // exe_obj.step();
    // mem_obj.step();
    // wb_obj.step();
};