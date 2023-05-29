#ifndef OPERATION_H

typedef int (*BinaryOperation)(int, int);
typedef int (*UnaryOperation)(int);

BinaryOperation* enregistreBin();

#endif