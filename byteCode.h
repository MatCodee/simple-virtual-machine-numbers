
#ifndef BYTECODE_H
#define BYTECODE_H

// Simple Byte Code
enum ByteCode {
    PUSH,   // coloca un elemtno en la pila, requiere parametro
    ADD,    // saca los 2 ultimos elementos de la pila 
    SUB,    // resta 2 elementos de la pila y coloca un nuevo valor en la pila
    MUL,    // saca dos elementos los multiplica y genera uno nuevo
    DIV,    // divide 2 elementos de la pila y colora el resultado
    PRINT,  // saca el ultimp valor de la pila
};
#endif