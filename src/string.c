#include "clox_string.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool String_isEmpty(String s) {
  return s.buffer == NULL || (s.len == 0 || s.capacity == 0);
}
String String_fromCharArray(const char *arr) {
  String result;
  int len = strlen(arr);
  char *buffer = (char *)malloc(sizeof(char) * len);
  strcpy(buffer, arr);
  result.buffer = buffer;
  result.len = len;
  result.capacity = len;
  return result;
}

void String_drop(String s) {
#ifndef N_DEBUG
  printf("Freeing string with size: %d bytes\t, Contents:\n\"\"\"%s\"\"\"",
         (int)s.len, s.buffer);
#endif
  free(s.buffer);
  s.capacity = 0;
  s.len = 0;
  s.buffer = NULL;
}
