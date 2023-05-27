#include "clox_string.h"
#include <stdbool.h>
#include <stddef.h>
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
