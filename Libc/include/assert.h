#ifndef LIBRE_C_ASSERT_H
#define LIBRE_C_ASSERT_H 1
#include "config.h"

#ifdef __cplusplus //if c++
    extern "C"{
#endif
#ifndef NEED_ASSERT
#ifdef NDEBUG
#define assert(expression)        ((void) 0)
#else //NDEBUG
#undef assert(expression)
#define assert(expression) if(!(expression)){\
  char *message = "Assertion failed:" #expression "";\
  printf("%s\nFile: %s \nLine: %s\n",message,__FILE__,itoa(__LINE__,10));\
}\

#define NEED_ASSERT 1
#endif // NDEBUG
#else //NEED_ASSERT

#endif //NEED_ASSERT


#ifdef __cplusplus //if c++
    }
#endif


#endif // LIBRE_C_ASSERT_H
