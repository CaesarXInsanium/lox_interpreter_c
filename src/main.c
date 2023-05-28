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
    String source;

    FILE *source_file_fp = open_path(argc[1]);
    load_source(source_file_fp, &source);
    if (had_error) {
      String loading_message = String_fromCharArray("loading source code");
      report(stderr, -1, loading_message,
             explain_error(error_type));


      String_drop(loading_message);
      return EXIT_FAILURE;
    }
    run(source);

    // remember to call this function at the end of the scope of a String
    // instance
    String_drop(source);
  } else {
    CLOX_ERROR err = run_prompt();
    had_error = err != CLOX_SUCCESS ? true : false;
    if (had_error) {
      error_type = err;
    }

    String mes = String_fromCharArray("Failed in running prompt");

    error(1, mes);
    explain_error(err);

    // free
    String_drop(mes);
  }
  return EXIT_SUCCESS;
}
