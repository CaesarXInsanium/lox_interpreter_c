#include "clox_error.h"
#include "clox_string.h"
#include <stdbool.h>
#include <stdio.h>

void error(int line, const String message) {
  String s = String_fromCharArray("");
  report(stderr, line, s, message);

  // free the memory
  String_drop(s);
}
void report(FILE *stream, int line, const String where, const String message) {
  fprintf(stream, "Line: %d, had error {%s}\nhere -> %s\n", line,
          message.buffer, where.buffer);
}

String explain_error(CLOX_ERROR err) {
  switch (err) {
  case CLOX_SUCCESS:
    return String_fromCharArray("No Error, Success");
  case CLOX_ERROR_EOF:
    return String_fromCharArray("Reached End of File Prematurely or something");
  case CLOX_ERROR_GENERIC_ERR:
    return String_fromCharArray("Unknown Error, Or Lazy error, figure it out");
    break;
  case CLOX_ERROR_FILE_NOT_FOUND:
    return String_fromCharArray("provided filepath is not found");
  default:
    return String_fromCharArray("This should not happen");
  }
}

void current_error(void) {
  if (had_error){
    String s = explain_error(error_type);
    error(0, s);
    String_drop(s);
  }
}
