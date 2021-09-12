#include <math.h>
#include <stdlib.h>
#include <structure.h>

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

class ASM_Parser {
   public:
    ASM_Parser(const char *asm_filename, uint32_t base_address,
               uint32_t program_size);
    ~ASM_Parser();
    instruction_t *load_program();

   private:
    instruction_t *instr_memory;
    uint32_t instr_base_address;
    const char *filename;
};