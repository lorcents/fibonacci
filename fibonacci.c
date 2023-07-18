#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

Node* makeConst(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = CONST;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* makeFunc(TypeTag type) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void calc(Node* node) {
    if (node->type == CONST) {
        return;
    }

    if (node->type == ADD) {
        calc(node->left);
        calc(node->right);
        node->value = addFunc(node->left->value, node->right->value);
    } else if (node->type == SUB) {
        calc(node->left);
        calc(node->right);
        node->value = subFunc(node->left->value, node->right->value);
    } else if (node->type == MUL) {
        calc(node->left);
        calc(node->right);
        node->value = mulFunc(node->left->value, node->right->value);
    } else if (node->type == DIV) {
        calc(node->left);
        calc(node->right);
        node->value = divFunc(node->left->value, node->right->value);
    }
}

int addFunc(int a, int b) {
    return a + b;
}

int subFunc(int a, int b) {
    return a - b;
}

int mulFunc(int a, int b) {
    return a * b;
}

int divFunc(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero.\n");
        return 0;
    }
}
