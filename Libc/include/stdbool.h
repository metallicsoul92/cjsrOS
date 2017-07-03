#ifndef STDBOOL_H_
#define STDBOOL_H_

#include "sys/cdefs.h"

#if __LIBRE_C_LIBC
typedef uint8 __bool;
#undef bool
#define bool __bool
#define true 1
#define false 0
#endif //LIBRE_C_LIBC



#define __BOOL_DEFINED 1


#endif //
