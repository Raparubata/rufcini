#include "table.h"
#include <stdlib.h>

term_t* table__run_division(term_t* term, v64 magic)
{
    v64 sum = 0;
    v64 product = 0;
    term_t* a = term;
    v64 count = 0;
    while (!term__is_null(a))
    {
        ++a; 
        ++count;
    }
    v64 highest = count-1;
    term_t* new = (term_t*)calloc(count, sizeof(term_t));
    for (u16 current = highest; current > 0; --current)
    {
        term_t* c_term = &term[current];
        sum = c_term->coeff + product;
        product = sum * magic;
        term_t* c_new = &new[current-1];
        c_new->coeff = sum;
        c_new->power = current-1;
    }
    if (term[0].coeff + product != 0)
    {
        free(new);
        return NULL;
    }
    else
    {
        return new;
    }
}