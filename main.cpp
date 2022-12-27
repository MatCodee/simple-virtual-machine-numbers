#include <iostream>
#include <vector>

#include "vm.h"

int main() {
    std::cout << "Simple Virtual Machine" << std::endl;

    std::vector<Instruction> instructions {
        Instruction(PUSH,1),
        Instruction(PUSH,2),
        Instruction(ADD,-1),
        Instruction(PUSH,100),
    };
    vm virtualMachine(instructions);

    return 0;
}