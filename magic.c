#include "magic.h"
#include <math.h>
#include <stdio.h>

v64 magic__find(term_vec_t* vec)
{
    bool positive = (vec->terms[0] > 0);
    v64 i = -(vec->terms[0]);
    while (true)
    {
        if (i != 0 && vec->terms[0] % i == 0)
        {
            v64 accumulator = 0;
            
            for (u16 e = 0; e < vec->len; ++e)
                accumulator += (v64)(vec->terms[e] * (v64)pow((double)i, (double)e));
            
            if (accumulator == 0)
                return i;
        }
        if (i == vec->terms[0]) 
            break;

        if (positive)
            ++i;
            
        else 
            --i;
    }
    return 0;
}