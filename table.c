#include "table.h"
#include <stdlib.h>
#include <stdio.h>

term_vec_t* table__run_division(term_vec_t* vec, v64 magic)
{
    v64 sum = 0;
    v64 product = 0;
    v64 highest = vec->len - 1;
    v64* new = (v64*)calloc(highest, sizeof(v64));
    if (!new)
    {
        perror("calloc()");
        return NULL;
    }

    for (u16 current = highest; current > 0; --current)
    {
        v64* c_term = &vec->terms[current];
        sum = *c_term + product;
        product = sum * magic;
        v64* c_new = &new[current-1];
        *c_new = sum;
    }
    if (vec->terms[0] + product != 0)
    {
        free(new);
        fprintf(stderr, "error: remainder of the division is %d, should be 0\n", vec->terms[0] + product);
        return NULL;
    }
    else
    {
        term_vec_t* new_vec = malloc(sizeof(term_vec_t));
        if (!new_vec)
        {
            perror("malloc()");
            free(new);
            return NULL;
        }
        new_vec->len = highest;
        new_vec->terms = new;
        return new_vec;
    }
}