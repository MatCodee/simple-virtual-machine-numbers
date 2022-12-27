#include "vm.h"

vm::vm(std::vector<Instruction> instruction) {
    inst.assign(instruction.begin(),instruction.end()); // copiamos las instrucicones en la maquina virtual
    executeInstruction(inst);
    std::cout << "Inicializando la Virtual Machine" << std::endl;
}

// Esta es la funcion que vamos a ver sui las funciones cumplen con las restricciones 
void vm::executeInstruction(const std::vector<Instruction> &inst)  {
    if(stack_.empty()) {
        for(const auto &in : inst) {
            if(comprobateInstruction(in)) {
                executeProcessVm(in);
                showInstruction(in.getInstructionParams());
            } else {
                // lanzar un error de que la instruccion esta incorrecta
            }
        }
    }else {
        // clear stack
        while (!stack_.empty()) {
            stack_.pop();
        }
    }
}

// comporibaciones antes de hacer cualquier cambio dentro de la maquina virtual, comprobacion de errores
bool vm::comprobateInstruction(const Instruction &inst) const {
    ByteCode code = inst.getInstructionParams().first;
    bool in = false;
    switch (code) {
        case PUSH:
            if(inst.getInstructionParams().second != -1) {
                in = true;
            }
            break;
        case ADD:
            in = stack_.size() % 2 == 0 ? true : false;
            break;
        case SUB:
            in = stack_.size() % 2 == 0 ? true : false;
            break;
        case MUL:
            in = stack_.size() % 2 == 0 ? true : false;
            break;
        case DIV:
            in = stack_.size() % 2 == 0 ? true : false;
            break;
        case PRINT:
            in = stack_.size() % 2 == 0 ? true : false;
            break;
    default:
        return false;
    }
    return in;
}

// En el futuro no se si es necesario quirar el numeor de codigo de operacion de byteCode ya que es un maquina virtual no necesita
// tener los codigos de operacion
void vm::executeProcessVm(const Instruction &inst) {
    ByteCode code = inst.getInstructionParams().first;
    switch(code) {
        case PUSH: {
            stack_.push(inst.getInstructionParams());
        } break;
        case ADD: {
            int s1 = stack_.top().second;
            stack_.pop();
            int s2 = stack_.top().second;
            stack_.pop();
            int result = s1 + s2;
            std::pair<ByteCode,int> data(code,result);
            stack_.push(data);
        } break;
        case SUB: {
            int s1 = stack_.top().second;
            stack_.pop();
            int s2 = stack_.top().second;
            stack_.pop();
            int result = s1 - s2;
            std::pair<ByteCode,int> data(code,result);
            stack_.push(data);
        } break;
        case MUL: {
            int s1 = stack_.top().second;
            stack_.pop();
            int s2 = stack_.top().second;
            stack_.pop();
            int result = s1 * s2;
            std::pair<ByteCode,int> data(code,result);
            stack_.push(data);
        }break; 
        case DIV: {
            int s1 = stack_.top().second;
            stack_.pop();
            int s2 = stack_.top().second;
            stack_.pop();
            int result = int(s1 / s2);
            std::pair<ByteCode,int> data(code,result);
            stack_.push(data);
        } break;
        case PRINT: {
            std::cout << stack_.top().first << " " << stack_.top().second << std::endl;
            stack_.pop();
        } break;
        default:
            std::cout << "error inesperado" << std::endl;
            // lanzar un error throw
    }
}

void vm::showInstruction(const std::pair<ByteCode,int> &in) const {
    std::cout << "Operacion: " <<  stack_.top().first << " Valor: " << stack_.top().second << " Size Stack: " << stack_.size() << std::endl;
}