#ifndef CLOX_RUN_H
#define CLOX_RUN_H

#include "clox_error.h"
#include "clox_string.h"
#include <stdio.h>

#ifndef MAX_REPL_CHAR_SIZE
#define MAX_REPL_CHAR_SIZE 256
#endif

CLOX_ERROR run_file(const char *path);
CLOX_ERROR run_prompt(void);
CLOX_ERROR run(String source);

FILE *open_path(const char *path);
void load_source(FILE *fp, String *target);
// read from stdout and return String of inputted characters
void read_line(String *target);
#endif
