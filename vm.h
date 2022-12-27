#include <iostream>
#include <vector>
#include <stack>
#include <ctype.h>

#ifndef VM_H
#define VM_H

#include "byteCode.h"
#include "Instruction.h"

class vm {
private:
    std::vector<Instruction> inst;
    std::stack<std::pair<ByteCode,int>> stack_;
public:
    vm(std::vector<Instruction> instruction);
    void executeInstruction(const std::vector<Instruction> &isnt);
    void executeProcessVm(const Instruction &inst);
    bool comprobateInstruction(const Instruction &inst) const;
    void showInstruction(const std::pair<ByteCode,int> &in) const;
};

#endif