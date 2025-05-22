#ifndef TERM_H
#define TERM_H

#include <intdef.h>

typedef struct _term_vec
{
    u32 len;
    v64* terms;
} term_vec_t;

void term__print_terms(term_vec_t* vec);
void term__free_vec(term_vec_t* vec);

#endif