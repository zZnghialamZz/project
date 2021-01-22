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

#include "utils.h"

bool MatchOpt(const char* opt, const char* chr, const char* name) {
  if (*opt == '-') {
    opt++;
    if (*opt == '-') {
      return strcmp(opt + 1, name) == 0;
    }
    return strcmp(opt, chr) == 0;
  }
  return false;
}

const char* NextArg(int* argc, const char*** argv) {
  if (*argc == 0) {
    ERROR("Expected additional argument(s)");
  }
  (*argc)--;
  return *(*argv)++;
}
