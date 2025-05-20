#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "magic.h"
#include "table.h"

int main(int argc, char** argv)
{
    term_t* term = input__parse_args(argc, argv);
    if (!term)
    {
        fprintf(stderr, "error: cannot allocate memory for command line arguments\n");
        return 1;
    }

    term_t* aterm = term;
    v64 count;
    while (!term__is_null(aterm))
    {
        ++aterm; 
        ++count;
    }

    --aterm;

    do
    {
        if (aterm->power == 1)
            term__print_coeff(aterm);

        else if (aterm->power == 0)
            printf("%+d", aterm->coeff);

        else
        {
            term__print_coeff(aterm);
            if (aterm->coeff != 0) printf("^%d", aterm->power);
        }

    } while ((aterm--)->power != 0);
    printf("\n");

    v64 magic = magic__find(term);
    if (magic == 0)
    {
        fprintf(stderr, "error: cannot find magic number\n");
        return 1;
    }
    printf("magic = %lld\n", magic);
    
    term_t* new = table__run_division(term, magic);

    aterm = new;
    while (!term__is_null(aterm))
    {
        ++aterm; 
    }
    --aterm;
    printf("(x%+lld)(", -magic);
    do
    {
        if (aterm->power == 1)
            term__print_coeff(aterm);

        else if (aterm->power == 0)
            printf("%+d", aterm->coeff);

        else
        {
            term__print_coeff(aterm);
            if (aterm->coeff != 0) printf("^%d", aterm->power);
        }

    } while ((aterm--)->power != 0);
    printf(")\n");
    free(term);
    free(new);
    return 0;
}