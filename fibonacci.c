#include <stdio.h>
#include <stdlib.h>

// Enum to represent arithmetic operations
typedef enum {
    CONSTANT,
    ADD,
    SUB,
    MUL,
    DIV
} TypeTag;

// Structure to represent a node in the expression tree
typedef struct Node {
    TypeTag type;
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node with a constant value
Node* makeConstant(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = CONSTANT;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to create a new node with an arithmetic operation
Node* makeFunc(TypeTag type, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    node->left = left;
    node->right = right;
    return node;
}

// Function to evaluate the expression tree and return the result
int evaluate(Node* node) {
    if (node == NULL) {
        return 0;
    }

    if (node->type == CONSTANT) {
        return node->value;
    }

    int leftValue = evaluate(node->left);
    int rightValue = evaluate(node->right);

    switch (node->type) {
        case ADD:
            return leftValue + rightValue;
        case SUB:
            return leftValue - rightValue;
        case MUL:
            return leftValue * rightValue;
        case DIV:
            return leftValue / rightValue;
        // Handle any other necessary cases here
        default:
            return 0;
    }
}

// Function to handle memory deallocation of the expression tree
void freeTree(Node* node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main() {
    Node* add = makeFunc(ADD, makeConstant(10), makeConstant(6));
    Node* mul = makeFunc(MUL, makeConstant(5), makeConstant(4));
    Node* sub = makeFunc(SUB, mul, add);
    Node* fibo = makeFunc(SUB, sub, NULL);

    printf("add : %d\n", evaluate(add));
    printf("mul : %d\n", evaluate(mul));
    printf("sub : %d\n", evaluate(sub));
    printf("fibo : %d\n", evaluate(fibo));

    // Free allocated memory
    freeTree(add);
    freeTree(mul);
    freeTree(sub);
    freeTree(fibo);

    return 0;
}
