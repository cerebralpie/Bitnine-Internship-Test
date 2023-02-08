/*
 * Bitnine Apache AGE 2023 Internship Program
 * Solution to question #1
 *
 * Author: Eduardo Monteiro de Sousa
 * github.com/cerebralpie
 */

#include "include/functions.h"
#include "include/output.h"
#include <stdlib.h>

int main()
{
    Node *add = getAdd(10, 6);
    Node *mul = getMul(5, 4);
    Node *sub = getSub(mul, add);
    Node *fib = getFib(sub);
    
    calc("Add", add);
    calc("Mul", mul);
    calc("Sub", sub);
    calc("Fib", fib);

    return EXIT_SUCCESS;
}
