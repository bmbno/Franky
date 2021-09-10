#include <processor.h>
int Processor::Execution::alu(int a, int b, opcode instruction)
{
    int result;
    switch (instruction)
    {
    case ADD:
        result = a + b;
        break;
    case SUB:
        result = a - b;
        break;
    }

    return result;
};