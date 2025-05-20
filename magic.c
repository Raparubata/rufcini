#include "magic.h"
#include <math.h>
#include <stdio.h>

v64 magic__find(term_t* term)
{
    bool positive = (term[0].coeff > 0);
    v64 i = -(term[0].coeff);
    while (true)
    {
        if (term[0].coeff %i == 0)
        {
            v64 accumulator = 0;
            
            for (term_t* e = &term[0]; !term__is_null(e); ++e)
                accumulator += (v64)(e->coeff * (v64)pow((double)i, (double)e->power));
            
            if (accumulator == 0)
                return i;
        }
        if (i == term[0].coeff) break;
        if (positive) ++i;
        else --i;
    }
    return 0;
}