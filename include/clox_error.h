#ifndef CLOX_ERROR_H
#define CLOX_ERROR_H
#include <stdbool.h>
#include <stdio.h>
#include "clox_string.h"
typedef enum {
  CLOX_SUCCESS,
  CLOX_ERROR_EOF,
  CLOX_ERROR_GENERIC_ERR,
  CLOX_ERROR_FILE_NOT_FOUND,
} CLOX_ERROR;

static bool had_error;
static CLOX_ERROR error_type;

void error(int line, const String message);
void report(FILE *stream, int line, const String where, const String message);
String explain_error(CLOX_ERROR err);

#endif
