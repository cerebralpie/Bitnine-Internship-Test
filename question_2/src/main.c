/*
 * Bitnine Apache AGE 2023 Internship Program
 * Solution to question #2
 *
 * Author: Eduardo Monteiro de Sousa
 * github.com/cerebralpie
 */

#include <stdlib.h>

unsigned int relation1(unsigned int n);
unsigned int relation2(unsigned int n);
unsigned int relation3(unsigned int n);

unsigned int *memo = NULL;

int main()
{
    return EXIT_SUCCESS;
}

/* Solution with simple recursion */
unsigned int relation1(unsigned int n)
{
    // This function makes use of a simple recursion
    // to calculate the nth value of the recurrence
    // relation. The main advantage of this method
    // is the reduced ammount of lines of code, while
    // its major drawbacks are the exponential time
    // complexity and waste of data memory
    
    unsigned int *values = (unsigned int *) calloc(n + 1, sizeof(unsigned int));
    values[0] = 0;
    values[1] = 1;
    values[2] = 2;

    if (n < 3)
        return values[n];
    else
        return relation1(n - 3) + relation1(n - 2);
}

/* Solution with memoization */
unsigned int relation2(unsigned int n)
{
    // This function uses the memoization technique,
    // i.e. values that have been previously calculated
    // are stored for later use. As as result, values of
    // the relation are calculated with less function calls 
    // and a reduced consumption of data memory
    
    if (memo == NULL)
    {
        memo = (unsigned int *) calloc(n + 1, sizeof(unsigned int));
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 2;
    }

    if (n < 3)
        return memo[n];
    else if (memo[n] != 0)
        return memo[n];
    else
    {
        memo[n] = relation2(n - 3) + relation2(n - 2);
        return memo[n];
    }
}

/* Bottom-up Solution */
unsigned int relation3(unsigned int n)
{
    // This function uses the Bottom-up approach
    // to calculate values more efficiently. In this
    // method, the values are stored in memory as soon
    // as they're computed in a for loop, from the lowest
    // unknown value up to the nth element. Its main advantages
    // are the linear time complexity and the reduced memory
    // usage when compared to the simple recursive method
    
    unsigned int *bottomUp = (unsigned int *) calloc(n + 1, sizeof(unsigned int));
    bottomUp[0] = 0;
    bottomUp[1] = 1;
    bottomUp[2] = 2;

    if (n > 3)
    {
        for (unsigned int i = 3; i <= n; ++i) 
        {
            bottomUp[i] = bottomUp[i - 3] + bottomUp[i - 2];
        }
    }

    return bottomUp[n];
}
