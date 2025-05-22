#include "term.h"
#include <stdio.h>
#include <stdlib.h>

void print_coeff(v64 term)
{
    if (term == 1)
        printf("+x");

    else if (term == -1)
        printf("-x");

    else if (term == 0)
        return;
    
    else
        printf("%+lldx", term);

    return;
}


void term__print_terms(term_vec_t* vec)
{
    v64 count = vec->len-1;
    v64* term = vec->terms;
    while (count >= 0)
    {
        if (count == 1)
            print_coeff(term[count]);

        else if (count == 0)
            printf("%+lld", term[count]);

        else
        {
            print_coeff(term[count]);
            if (term[count] != 0) printf("^%lld", count);
        }
        --count;
    }
    return;
}

void term__free_vec(term_vec_t* vec)
{
    free(vec->terms);
    free(vec);
    return;
}