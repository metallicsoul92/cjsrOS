cmake_minimum_required(VERSION 2.8)

project(libre-c)

 set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ffreestanding -Wall -Wextra -std=c99 -nostdlib")


#Version System
set (LIB_C_VERSION_MAJ 0)
set (LIB_C_VERSION_MIN 1)
set (LIB_C_VERSION_BUG 0)
set (LIB_C_VERSION
    ${LIB_C_VERSION_MAJ}.${LIB_C_VERSION_MIN}.${LIB_C_VERSION_BUG})

#Platform Detection
IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
   # Mac OS X specific code
   SET(__OSX__ 1)


ELSEIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    # Linux specific code
    SET(__LINUX__ 1)


ELSEIF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    # Windows specific code
    SET(__WINDOWS__ ON)

ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

#Compiler Detection
IF(MINGW)
SET(__mingw__ 1)
ELSEIF(MSYS)
SET(__msys__ 1)
ELSEIF(CYGWIN)
SET(__cygwin__ 1)
ELSEIF(BORLAND)
SET(__borland__ 1)
ELSEIF(MSVC)
SET(__msvc__ 1)
ELSEIF(CMAKE_COMPILER_IS_GNUCC)
SET(__gcc__ 1)
ELSE(CMAKE_COMPILER_IS_GNUCXX)
SET(__gxx__ 1)
ENDIF(MINGW)


#This Sets whether it is multithreaded or not
SET(__MT_ENABLED 1)

#This option is if cmake is passed -DKernel
option(Kernel "Is this a kernel?")

configure_file (
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

# set up include-directories
include_directories(
  "${PROJECT_SOURCE_DIR}"   # to find config.h.in
  "${PROJECT_BINARY_DIR}")  # to find bin/config.h

file(GLOB includes "include/*.h" "include/*/*.h" "bin/config.h")
file(GLOB sources "src/*.c" "src/*/*.c")

if(Kernel)
set(__ISLIBK__ 1)
add_library(libre-k ${includes} ${sources})
set_target_properties(libre-k PROPERTIES LINKER_LANGUAGE C)

else()
add_library(libre-c  ${includes} ${sources})
set_target_properties(libre-c PROPERTIES LINKER_LANGUAGE C)

endif()



if(Kernel)
install(TARGETS libre-k DESTINATION lib)
else()
install(TARGETS libre-c DESTINATION lib)
endif()
