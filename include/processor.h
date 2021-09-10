

class Processor {        
    int *_memory;
    int *_register;

    Processor(int memory_size=4000, int num_registers=3);
    ~Processor();

    class Fetch{};

    class Decode{};

    class Execution{};

    class Memory{};

    class WriteBack{};
    
    

};
    
