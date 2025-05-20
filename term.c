#include "term.h"
#include <stdio.h>

bool term__is_null(term_t* term)
{
    return (term->coeff == 0 && term->power == 0);
}

void term__print_coeff(term_t *term)
{
    if (term->coeff == 1)
        printf("+x");

    else if (term->coeff == -1)
        printf("-x");

    else if (term->coeff == 0)
        return;
    
    else
        printf("%+dx", term->coeff);

    return;
}
