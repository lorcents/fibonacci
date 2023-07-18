#ifndef FIBONACCI_H
#define FIBONACCI_H

typedef struct Node Node;

typedef enum TypeTag {
    CONST,
    ADD,
    SUB,
    MUL,
    DIV,
} TypeTag;

typedef int (*OperationFunc)(int, int);

struct Node {
    TypeTag type;
    int value;
    Node* left;
    Node* right;
};

Node* makeConst(int value);
Node* makeFunc(TypeTag type);
void calc(Node* node);
int addFunc(int a, int b);
int subFunc(int a, int b);
int mulFunc(int a, int b);
int divFunc(int a, int b);

#endif /* FIBONACCI_H */
