#include <processor.h>

#include <iostream>

int Processor::Execution::alu(int a, int b, opcode instruction) {
    int result;
    switch (instruction) {
        case ADD:
            result = a + b;
            break;
        case SUB:
            result = a - b;
            break;
        case MULT:
            result = a * b;
            break;
        case DIV:
            result = a / b;
            break;
        case JMP:
            result = a + b;
            break;
        case JMPE:
            result = a + b;
            break;
        case JMPNE:
            result = a + b;
            break;
        case JMPG:
            result = a + b;
            break;
        case JMPGE:
            result = a + b;
            break;
        case JMPL:
            result = a + b;
            break;
        case JMPLE:
            result = a + b;
            break;
        case SHIFTL:
            result = a << b;
            break;
        case SHIFTR:
            result = a >> b;
            break;
        case LD:
            result = a + b;
            break;
        case ST:
            result = a + b;
            break;
        case MOV:
            result = a + b;
            break;
        case AND:
            result = a && b;
            break;
        case OR:
            result = a || b;
            break;
        case NOT:
            result = ~a;
            break;
        case XOR:
            result = a ^ b;
            break;
        case NOP:
            result = NULL;
            break;
        default:
            std::cout << "Error \n";
            break;
    }

    return result;
};