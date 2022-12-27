#include <iostream>

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "byteCode.h"

class Instruction {
    private:
        std::pair<ByteCode,int> instruction_params;
    public:
        Instruction(ByteCode code) {
            instruction_params.first = code;
            instruction_params.second = -1;
        }
        Instruction(ByteCode code,int value) {
            instruction_params.first = code;
            instruction_params.second = value;
        }
        void getInstructionShow() const  {
            std::cout << instruction_params.first << " " << instruction_params.second << std::endl;
        }
        std::pair<ByteCode,int> getInstructionParams() const { return instruction_params; }
};

#endif