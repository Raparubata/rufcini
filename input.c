#include "input.h"
#include <stdlib.h>
#include <stdio.h>

term_t* input__parse_args(int argc, char** argv)
{
    term_t* term = calloc(argc, sizeof(term_t));
    if (!term)
    {
        perror("calloc()");
        return NULL;
    }

    for (u16 i = argc-1; i>=1; --i)
    {
        term[argc-1-i].power = argc-1-i;
        term[argc-1-i].coeff = atoi(argv[i]);
    }
    return term;
}