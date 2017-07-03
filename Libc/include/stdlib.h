#ifndef _STDLIB_H
#define _STDLIB_H 1

#include <sys/cdefs.h>

#ifdef __cplusplus
extern "C" {
#endif

__attribute__((__noreturn__))
void abort(void);

char *itoa(int val, int base);
char *itoas(int val, char *str, int base);
char *uitoa(unsigned int val, int base);
char *uitoas(unsigned int val, char *str, int base);
char *litoa(long val, int base);
char *litoas(long val, char *str, int base);


#define OFFSETOF(TYPE, ELEMENT) ((size_t)&(((TYPE *)0)->ELEMENT))

struct _div_t {
    int quotent;
    int remainder;
};

struct _ldiv_t {
    long quotent;
    long remainder;
};

struct _lldiv_t {
    long long quotent;
    long long remainder;
};

typedef struct __div_t div_t;
typedef struct __ldiv_t ldiv_t;
typedef struct __lldiv_t lldiv_t;

div_t div(int,int);
ldiv_t ldiv(long,long);
lldiv_t lldiv(long long, long long);

#ifdef __cplusplus
}
#endif

#endif
