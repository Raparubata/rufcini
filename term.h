#ifndef TERM_H
#define TERM_H

#include <intdef.h>

typedef struct _term
{
    u8 power;
    v32 coeff;
} term_t;

bool term__is_null(term_t* term);
void term__print_coeff(term_t* term);

#endif