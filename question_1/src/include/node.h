/*
 * Bitnine Apache AGE 2023 Internship Program
 * Solution to question #1
 *
 * Author: Eduardo Monteiro de Sousa
 * github.com/cerebralpie
 */

#include <stdint.h>

typedef enum {
    integer_t,
    float_t,
    bool_t,
    char_t
} TypeTag;

typedef struct {
    TypeTag type;
    uint32_t value;
} Node;
