#include <asmparser.h>

using namespace std;

ASM_Parser::ASM_Parser(const char *asm_filename, uint32_t base_address,
                       uint32_t program_size) {
    filename = asm_filename;
    instr_base_address = base_address;
    instr_memory = new instruction_t[program_size];
}

ASM_Parser::~ASM_Parser() {
    delete filename;
    delete instr_memory;
};

instruction_t *ASM_Parser::load_program() {
    /* creating a map with the valid opcodes and with the valid labels */
    map<string, opcode_t> opcodes;  // for opcodes
    map<string, unsigned> labels;   // for branches
    for (int i = 0; i < NUM_OPCODES; i++)
        opcodes[string(instr_names[i])] = (opcode_t)i;

    /* opening the assembly file */
    ifstream fin(filename, ios::in | ios::binary);
    if (!fin.is_open()) {
        cerr << "error: open file " << filename << " failed!" << endl;
        exit(-1);
    }

    /* parsing the assembly file line by line */
    string line;
    unsigned instruction_nr = 0;
    while (getline(fin, line)) {
        // set the instruction field
        char *str = const_cast<char *>(line.c_str());

        // tokenize the instruction
        char *token = strtok(str, " \t");
        map<string, opcode_t>::iterator search = opcodes.find(token);
        if (search == opcodes.end()) {
            // this is a label for a branch - extract it and save it in the
            // labels map
            string label = string(token).substr(0, string(token).length() - 1);
            labels[label] = instruction_nr;
            // move to next token, which must be the instruction opcode
            token = strtok(NULL, " \t");
            search = opcodes.find(token);
            if (search == opcodes.end())
                cout << "ERROR: invalid opcode: " << token << " !" << endl;
        }
        instr_memory[instruction_nr].opcode = search->second;

        // reading remaining parameters
        char *par1;
        char *par2;
        char *par3;
        switch (instr_memory[instruction_nr].opcode) {
            case ADD:
            case SUB:
            case XOR:
                par1 = strtok(NULL, " \t");
                par2 = strtok(NULL, " \t");
                par3 = strtok(NULL, " \t");
                instr_memory[instruction_nr].dest = atoi(strtok(par1, "R"));
                instr_memory[instruction_nr].src1 = atoi(strtok(par2, "R"));
                instr_memory[instruction_nr].src2 = atoi(strtok(par3, "R"));
                break;
            case ADDI:
            case SUBI:
                par1 = strtok(NULL, " \t");
                par2 = strtok(NULL, " \t");
                par3 = strtok(NULL, " \t");
                instr_memory[instruction_nr].dest = atoi(strtok(par1, "R"));
                instr_memory[instruction_nr].src1 = atoi(strtok(par2, "R"));
                instr_memory[instruction_nr].immediate = strtoul(par3, NULL, 0);
                break;
            case LW:
                par1 = strtok(NULL, " \t");
                par2 = strtok(NULL, " \t");
                instr_memory[instruction_nr].dest = atoi(strtok(par1, "R"));
                instr_memory[instruction_nr].immediate =
                    strtoul(strtok(par2, "()"), NULL, 0);
                instr_memory[instruction_nr].src1 = atoi(strtok(NULL, "R"));
                break;
            case SW:
                par1 = strtok(NULL, " \t");
                par2 = strtok(NULL, " \t");
                instr_memory[instruction_nr].src1 = atoi(strtok(par1, "R"));
                instr_memory[instruction_nr].immediate =
                    strtoul(strtok(par2, "()"), NULL, 0);
                instr_memory[instruction_nr].src2 = atoi(strtok(NULL, "R"));
                break;
            case BEQZ:
            case BNEZ:
            case BLTZ:
            case BGTZ:
            case BLEZ:
            case BGEZ:
                par1 = strtok(NULL, " \t");
                par2 = strtok(NULL, " \t");
                instr_memory[instruction_nr].src1 = atoi(strtok(par1, "R"));
                instr_memory[instruction_nr].label = par2;
                break;
            case JUMP:
                par2 = strtok(NULL, " \t");
                instr_memory[instruction_nr].label = par2;
            default:
                break;
        }

        /* increment instruction number before moving to next line */
        instruction_nr++;
    }
    // reconstructing the labels of the branch operations
    int i = 0;
    while (true) {
        instruction_t instr = instr_memory[i];
        if (instr.opcode == EOP) break;
        if (instr.opcode == BLTZ || instr.opcode == BNEZ ||
            instr.opcode == BGTZ || instr.opcode == BEQZ ||
            instr.opcode == BGEZ || instr.opcode == BLEZ ||
            instr.opcode == JUMP) {
            instr_memory[i].immediate = (labels[instr.label] - i - 1) << 2;
        }
        i++;
    }
}
