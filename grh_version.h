#pragma once

//
// grh_version.h
//
// version 1.0 2025-09-26
//

#define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

// Macros to assist with displaying values at build time
//
#define XSTR(x) STR(x)
#define STR(x) #x

#define DO_PRAGMA(x) _Pragma(#x)

//
// GCC Version macros
// GCC_VERSION is a numeric value that can be used for comparisons
//
#define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

#define GCC_VERSION_STR \
    "GCC Version: " XSTR(__GNUC__) "." XSTR(__GNUC_MINOR__) "." XSTR(__GNUC_PATCHLEVEL__)

// Macros to display version information at build time
//
#define DISPLAY_GCC_VERSION \
    DO_PRAGMA(message(GCC_VERSION_STR))

#define DISPLAY_CPP_VERSION \
    DO_PRAGMA(message("C++ Version: " XSTR(__cplusplus)))

// End of grh_version.h
