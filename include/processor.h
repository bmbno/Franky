#include <structure.h>

#include <cstdint>

#define memory_latency 100

class Processor {
    int *gp_register;

    Processor(int num_registers = 3);
    ~Processor();
    void step();

    class Fetch {
        uint32_t pc;

        Fetch();
        ~Fetch();
        void step();
        opcode_t fetch_instruction(int pc);
    };

    class Decode {
        uint32_t pc;
        // instruction class

        Decode();
        ~Decode();
        void step();
    };

    class Execution {
        uint32_t pc;
        int source1;
        int source2;
        int immediate;
        uint32_t destination;

        Execution();
        ~Execution();
        void step();
        int alu(int a, int b, opcode_t instruction);
        bool branch(int a, opcode_t instruction);
    };

    class Memory {
        int *_memory;
        uint32_t pc;
        bool branch_taken;
        int alu_out;
        uint32_t memory_input;
        uint32_t destination;

        Memory(uint32_t memory_size = 0X4000);
        ~Memory();
        void step();
        uint32_t load(uint32_t address);
        void store(uint32_t address, uint32_t value);
    };

    class WriteBack {
        int alu_out;
        uint32_t destination;
        uint32_t memory_out;

        WriteBack();
        ~WriteBack();
        void step();
    };

    class Instruction {};
};
