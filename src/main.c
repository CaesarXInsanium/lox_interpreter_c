#include "arg.h"
#include "clox_error.h"
#include "clox_string.h"
#include "run.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static bool had_error = false;
static CLOX_ERROR error_type = CLOX_SUCCESS;

int main(int argv, char **argc) {
  if (argv > 2) {
    printf("Correct Usage: clox [script]\n");
    exit(EXIT_FAILURE);
  } else if (argv == 2) {
    FILE *source_file_fp = open_path(argc[1]);
    String source;
    load_source(source_file_fp, &source);
    if (had_error) {
      report(stderr, -1, String_fromCharArray("loading source code"),
             explain_error(error_type));
      return EXIT_FAILURE;
    }
    run(source);
  } else {
    CLOX_ERROR err = run_prompt();
    had_error = err != CLOX_SUCCESS ? true : false;
    if (had_error) {
      error_type = err;
    }
    error(1, String_fromCharArray("Failed in Running Prompt"));
    explain_error(err);
  }
  return EXIT_SUCCESS;
}
