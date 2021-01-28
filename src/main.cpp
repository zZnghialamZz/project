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

#include "main.h"
#include "utils.h"

#include <stdio.h>

INTERNAL void Help() {
  printf("\n");
  printf("Usage: \n");
  printf("  project -l language\n");
  printf("\n");
  printf("Optional:\n");
  printf("  project [OPTION]\n\n");
  printf("  -h,  --help         Display this help message\n");
  printf("  -v,  --version      Display the version number\n");
  printf("  -g,  --git          Initialise a git repo in the project folder\n");
  printf("  -n,  --name <str>   Setup project name\n");
  printf("  -e,  --exe <str>    Setup executable name\n");
  printf("\n");
  exit(EXIT_SUCCESS);
}

INTERNAL void Version() {
  printf("\n");
  printf("project %d.%d.%d\n", P_VER_MAJOR, P_VER_MINOR, P_VER_PATCH);
  printf("-----------------------------------------------------------------\n");
  printf("(C) Copyright 2020 by Nghia Lam.\n\n");
  printf("MIT License.\n\n");
  printf("Permission is hereby granted, free of charge, to any person\n");
  printf("obtaining a copy of this software and associated documentation\n");
  printf("files (the 'Software'), to deal in the Software without\n");
  printf("restriction, including without limitation the rights to use, copy\n");
  printf("modify, merge, publish, distribute, sublicense,and/or sell copies\n");
  printf("of the Software, and to permit persons to whom the Software is\n");
  printf("furnished to do so, subject to the following conditions: \n\n");
  printf("The above copyright notice and this permission notice shall be\n");
  printf("included in all copies or substantial portions of the Software\n\m");
  printf("THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,\n");
  printf("EXPRESS OR IMPLIED,INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF\n");
  printf("MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND\n");
  printf("NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT\n");
  printf("HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,\n");
  printf("WHETHER IN AN ACTION OF CONTRACT,TORT OR OTHERWISE, ARISING FROM,\n");
  printf("OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER\n");
  printf("DEALINGS IN THE SOFTWARE.\n");
  printf("-----------------------------------------------------------------\n");
  exit(EXIT_SUCCESS);
}

int main(int argc, const char** argv) {
  // Init default
  bool _git_init     = false;
  bool _project_name = "";
  bool _exe_name     = "";

  // Handle args
  // ----
  // NOTE(Nghia Lam): Consume the project executable name.
  NextArg(&argc, &argv);
  while (argc > 0) {
    const char* arg = NextArg(&argc, &argv);

    if (arg[0] != '-')
      ERROR(
          "\n"
          "Unknown input !!\n"
          "Please use 'project --help' for more information\n");

    else if (MatchOpt(arg, "h", "help"))
      Help();

    else if (MatchOpt(arg, "v", "version"))
      Version();

    else if (MatchOpt(arg, "g", "git"))
      _git_init = true;

    else
      ERROR("Invalid arguments '%s'", arg);
  }

  return EXIT_SUCCESS;
}
