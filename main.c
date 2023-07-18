#include <stdio.h>
#include "fibonacci.h"

int main() {
    Node* add = makeFunc(ADD);
    add->left = makeConst(10);
    add->right = makeConst(6);

    Node* mul = makeFunc(MUL);
    mul->left = makeConst(5);
    mul->right = makeConst(4);

    Node* sub = makeFunc(SUB);
    sub->left = mul;
    sub->right = add;

    Node* fibo = makeFunc(SUB);
    fibo->left = sub;
    fibo->right = NULL;

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    printf("add : %d\n", add->value);
    printf("mul : %d\n", mul->value);
    printf("sub : %d\n", sub->value);
    printf("fibo : %d\n", fibo->value);

    // Free dynamically allocated memory
    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}
