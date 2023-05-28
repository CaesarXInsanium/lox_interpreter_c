#ifndef CLOX_ERROR_H
#define CLOX_ERROR_H
#include "clox_string.h"
#include <stdbool.h>
#include <stdio.h>
typedef enum {
  CLOX_SUCCESS,
  CLOX_ERROR_EOF,
  CLOX_ERROR_GENERIC_ERR,
  CLOX_ERROR_FILE_NOT_FOUND,
  CLOX_ERROR_EMPTY_STRING,
  CLOX_ERROR_UNTERMINATED_STRING,
} CLOX_ERROR;

static bool had_error;
static CLOX_ERROR error_type;

// generic error logging that outouts to stder
void error(int line, const String message);
// logs error message to target stream
void report(FILE *stream, int line, const String where, const String message);
// takes Error enum and returns explanation on what is means
String explain_error(CLOX_ERROR err);

// prints out the information about the current error
void current_error(void);

#endif
