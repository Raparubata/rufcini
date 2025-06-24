#ifndef __INTDEF_H__
#define __INTDEF_H__

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t v8;
typedef int16_t v16;
typedef int32_t v32;
typedef int64_t v64;

#ifndef true
#   define true 1
#endif
#ifndef false
#   define false 0
#endif

#endif