/*
 * Bitnine Apache AGE 2023 Internship Program
 * Solution to question #1
 *
 * Author: Eduardo Monteiro de Sousa
 * github.com/cerebralpie
 */

#include "node.h"


// Function-like macros with support for int and
// Node* arguments
#define getAdd(a, b) _Generic((a),              \
                              int: getAddInt,   \
                              Node*: getAddNode \
                              )(a, b)

#define getSub(a, b) _Generic((a),              \
                              int: getSubInt,   \
                              Node*: getSubNode \
                              )(a, b)

#define getMul(a, b) _Generic((a),              \
                              int: getMulInt,   \
                              Node*: getMulNode \
                              )(a, b)

#define getFib(a)    _Generic((a),              \
                              int: getFibInt,   \
                              Node*: getFibNode \
                              )(a)

Node *getAddNode(Node const *elem1, Node const *elem2)
{
    // Check whether the element type is valid
    // Supported types are integer_t and float_t
    if (elem1->type > 1 || elem2->type > 1)
        return NULL;
        
    Node *result = (Node *) malloc(sizeof(Node));
    result->type = elem1->type;
    result->value = elem1->value + elem2->value;

    return result;
}

Node *getAddInt(int32_t elem1, int32_t elem2)
{
    Node *result = (Node *) malloc(sizeof(Node));
    result->type = integer_t;
    result->value = elem1 + elem2;

    return result;
}

Node *getSubNode(Node const *elem1, Node const *elem2)
{
    if (elem1->type > 1 || elem2->type > 1)
        return NULL;

    Node *result = (Node *) malloc(sizeof(Node));
    result->type = elem1->type;
    result->value = elem1->value - elem2->value;

    return result;
}

Node *getSubInt(int32_t elem1, int32_t elem2)
{
    Node *result = (Node *) malloc(sizeof(Node));
    result->type = integer_t;
    result->value = elem1 - elem2;

    return result;
}

Node *getMulNode(Node const *elem1, Node const *elem2)
{
    if (elem1->type > 1 || elem2->type > 1)
        return NULL;

    Node *result = (Node *) malloc(sizeof(Node));
    result->type = elem1->type;
    result->value = elem1->value * elem2->value;

    return result;
}

Node *getMulInt(int32_t elem1, int32_t elem2)
{
    Node *result = (Node *) malloc(sizeof(Node));
    result->type = integer_t;
    result->value = elem1 * elem2;

    return result;
}

Node *getFibNode(Node const *elem)
{
    // Check whether the element is of a valid
    // type (integer_t only) and whether its value
    // is non-negative
    if (elem->type != 0 || elem->value < 0)
        return NULL;

    uint32_t *values = (uint32_t *) calloc(elem->value, sizeof(uint32_t));
    values[0] = 0;
    values[1] = 1;
    values[2] = 1;

    Node *result = (Node *) malloc(sizeof(Node));
    result->type = integer_t;

    // Generate the Fibonacci sequence up to
    // the element's value
    if (elem->value > 2)
    {
        for (int i = 3; i <= elem->value; i++)
        {
           values[i] = values[i - 1] + values[i - 2]; 
        }
    } 

    result->value = values[elem->value];

    return result;
}

Node *getFibInt(int32_t elem)
{
    // Check whether the element is a
    // non-negative value
    if (elem < 0)
        return NULL;

    uint32_t *values = (uint32_t *) calloc(elem, sizeof(uint32_t));
    values[0] = 0;
    values[1] = 1;
    values[2] = 1;

    Node *result = (Node *) malloc(sizeof(Node));
    result->type = integer_t;

    if (elem > 2)
    {
        for (int i = 3; i <= elem; i++)
        {
           values[i] = values[i - 1] + values[i - 2]; 
        }
    } 

    result->value = values[elem];

    return result;
}
