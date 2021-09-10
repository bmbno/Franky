#include <processor.h>
Processor::Processor(int memory_size = 4000, int num_registers = 3)
{
    _memory = new int(memory_size);
    _register = new int(num_registers);
}
Processor::~Processor()
{
    delete _memory;
    delete _register;
}
