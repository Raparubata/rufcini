#include "input.h"
#include <stdlib.h>
#include <stdio.h>

term_vec_t* input__parse_args(int argc, char** argv)
{
    v64* term = (v64*)calloc(argc-1, sizeof(v64));
    if (!term)
    {
        perror("calloc()");
        return NULL;
    }

    for (u16 i = argc-1; i>=1; --i)
        term[argc-1-i] = atoi(argv[i]);
    
    term_vec_t* vec = (term_vec_t*)malloc(sizeof(term_vec_t));
    if (!vec)
    {
        perror("malloc()");
        return NULL;
    }
    
    vec->len = argc-1;
    vec->terms = term;

    return vec;
}