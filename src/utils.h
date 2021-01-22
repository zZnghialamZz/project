/* =========================================================================
|  @File   : utils.h
|  @Brief  : Utilities fie for my project command line.
|  @Author : Nghia Lam <nghialam12795@gmail.com>
|  @License: (C) Copyright 2020 by Nghia Lam.
|
|            This project is free software; you can redistribute it and/or
|            modify it under the terms of the MIT license. See LICENSE for
|            details.
|  ========================================================================= */

#ifndef PROJECT_UTILS_H_
#define PROJECT_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ----------------------------------------------------------------------------
// Macro helpers
// ----------------------------------------------------------------------------

#define INTERNAL      static  // Function only belong to this translation unit.
#define GLOBAL        static  // Variable global to all translation unit.
#define LOCAL_PERSIST static  // Dont use this in release code <- Thread unsafe.

#define ERROR(...)                                                             \
  do {                                                                         \
    fprintf(stderr, "Error: ");                                                \
    fprintf(stderr, __VA_ARGS__);                                              \
    fprintf(stderr, "\n");                                                     \
    exit(EXIT_FAILURE);                                                        \
  } while (0)

// ----------------------------------------------------------------------------
// Function helpers
// ----------------------------------------------------------------------------

bool MatchOpt(const char* opt, const char* chr, const char* name);
const char* NextArg(int* argc, const char*** argv);

#endif  // PROJECT_UTILS_H_
