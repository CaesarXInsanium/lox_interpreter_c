#include "clox_string.h"
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

bool String_isEmpty(String s){
  return s.len == 0;
}
String String_fromCharArray(const char *arr){
  String result;
  int len = strlen(arr);
  char *buffer = (char *)malloc(sizeof(char) * len);
  strcpy(buffer, arr);
  result.buffer = buffer;
  result.len = len;
  result.capacity = len;
  return result;
}

