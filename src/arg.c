#include "arg.h"

int print_args(int argv, char **argc) {
  for (int i = 0; i < argv; i++) {
    printf("Arg #%d: %s\n", i, argc[i]);
  }
  return EXIT_SUCCESS;
}
