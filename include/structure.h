#include <string>

#define UNDEFINED 0xFFFFFFFF  // used to initialize the registers
#define UNDEFINED_CHAR 0xFF
#define NUM_SP_REGISTERS 9
#define NUM_GP_REGISTERS 32
#define NUM_OPCODES 16
#define NUM_STAGES 5

static const char *reg_names[NUM_SP_REGISTERS] = {
    "PC", "NPC", "IR", "A", "B", "IMM", "COND", "ALU_OUTPUT", "LMD"};
static const char *stage_names[NUM_STAGES] = {"IF", "ID", "EX", "MEM", "WB"};
static const char *instr_names[NUM_OPCODES] = {
    "LW",   "SW",   "ADD",  "ADDI", "SUB",  "SUBI", "XOR", "BEQZ",
    "BNEZ", "BLTZ", "BGTZ", "BLEZ", "BGEZ", "JUMP", "EOP", "NOP"};

typedef enum {
    LW,
    SW,
    ADD,
    ADDI,
    SUB,
    SUBI,
    XOR,
    BEQZ,
    BNEZ,
    BLTZ,
    BGTZ,
    BLEZ,
    BGEZ,
    JUMP,
    EOP,
    NOP
} opcode_t;

typedef struct {
    opcode_t opcode;  // opcode
    unsigned src1;    // first source register in the assembly instruction (for
                      // SW, register to be written to memory)
    unsigned src2;    // second source register in the assembly instruction
    unsigned dest;    // destination register
    unsigned immediate;  // immediate field
    std::string
        label;  // for conditional branches, label of the target
                // instruction - used only for parsing/debugging purposes
} instruction_t;

typedef struct {
    int pc;         // program counter
    unsigned src1;  // first source register in the assembly instruction (for
                    // SW, register to be written to memory)
    unsigned src2;  // second source register in the assembly instruction
    unsigned immediate;  // immediate field
} decode_registers_t;