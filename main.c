#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "magic.h"
#include "table.h"

int main(int argc, char** argv)
{
    printf("parsing argv...\n");
    term_vec_t* vec = input__parse_args(argc, argv);
    if (!vec)
    {
        fprintf(stderr, "error: cannot allocate memory for command line arguments\n");
        return 1;
    }

    term__print_terms(vec);
    printf("\n");

    v64 magic = magic__find(vec);
    if (magic == 0)
    {
        fprintf(stderr, "error: cannot find magic number\n");
        return 1;
    }
    printf("magic = %lld\n", magic);
    
    term_vec_t* new = table__run_division(vec, magic);
    if (!new)
    {
        fprintf(stderr, "error: cannot allocate memory to store the result\n");
        return 1;
    }

    printf("(x%+lld)(", -magic);
    term__print_terms(new);
    printf(")\n");
    term__free_vec(vec);
    return 0;
}