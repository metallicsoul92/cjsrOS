#ifndef CONFIG_H_
#define CONFIG_H_

//Versioning information
#define LIB_C_VERSION_MAJ "0"
#define LIB_C_VERSION_MIN "1"
#define LIB_C_VERSION_BUG "0"
#define LIB_C_VERSION "0.1.0"

//Platform Detection
/* #undef __OSX__ */
#define __LINUX__ 1
/* #undef __WINDOWS__ */

//Compiler Detection
/* #undef __mingw__ */
/* #undef __msys__ */
/* #undef __cygwin__ */
/* #undef __borland__ */
/* #undef __msvc__ */
#define __gcc__ 1
/* #undef __gxx__ */

//Compiler Identification
#define __c_compilerID__ "GNU"
#define __cxx_compilerID__ "GNU"
//Features:
#define __MT_ENABLED 1

//Is it a kernel Library?
/* #undef __ISLIBK__ */

#endif
