

class Processor
{
    int *_memory;
    int *_register;

    Processor(int memory_size = 4000, int num_registers = 3);
    ~Processor();

    class Fetch
    {
    };

    class Decode
    {
    };

    class Execution
    {
        enum opcode
        {
            ADD,
            SUB,
            MULT,
            DIV,
            JMP,
            JMPE,
            JMPNE,
            JMPG,
            JMPGE,
            JMPL,
            JMPLE,
            SHIFTL,
            SHIFTR,
            LD,
            ST,
            MOV,
            AND,
            OR,
            NOT,
            XOR
        };

        int alu(int a, int b, opcode instruction){};
    };

    class Memory
    {
    };

    class WriteBack
    {
    };
};
