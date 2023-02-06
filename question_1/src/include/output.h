/*
 * Bitnine Apache AGE 2023 Internship Program
 * Solution to question #1
 *
 * Author: Eduardo Monteiro de Sousa
 * github.com/cerebralpie
 */

#include <stdio.h>
#include <inttypes.h>

void calc(char const *msg, Node const *elem)
{
    printf("%s: ", msg);
    printf("%" PRIu32 "\n", elem->value);
}
