/* =========================================================================
|  @File   : main.cpp
|  @Brief  : The main file to handle my project command line.
|  @Author : Nghia Lam <nghialam12795@gmail.com>
|  @License: (C) Copyright 2020 by Nghia Lam.
|
|            This project is free software; you can redistribute it and/or
|            modify it under the terms of the MIT license. See LICENSE for
|            details.
|  ========================================================================= */

#include "utils.h"

#define VERSION "0.0.1"

INTERNAL void PrintHelp() {
  printf("Usage: \n");
  printf("  project -l language\n");
  printf("\n");
  printf("Optional:\n");
  printf("  project [OPTION]\n\n");
  printf("  -h,  --help               Display this help message\n");
  printf("  -v,  --version            Display the version number\n");
  printf("\n");
}

int main(int argc, const char** argv) {
  // Handle args
  // ----
  // NOTE(Nghia Lam): Consume the project executable name
  NextArg(&argc, &argv);
  while (argc > 0) {
    const char* arg = NextArg(&argc, &argv);

    if (arg[0] != '-') {
      ERROR(
          "\n"
          "Unknown input !!\n"
          "Please use 'project --help' for more information\n");

    } else if (MatchOpt(arg, "h", "help")) {
      PrintHelp();
      exit(EXIT_SUCCESS);
    } else if (MatchOpt(arg, "v", "version")) {
      printf("project command line version " VERSION "\n");
      exit(EXIT_SUCCESS);
    }
  }

  return EXIT_SUCCESS;
}
