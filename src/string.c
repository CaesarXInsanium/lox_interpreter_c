#include "clox_string.h"
#include "clox_error.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

String nullString(void){
  String r = {
    .buffer = NULL,
    .len = 0,
    .capacity = 0,
  };
  return r;
}
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

String String_fromSlice(const String str, size_t start, size_t end){
  // remember to leave last byte as null terminator
  size_t len = end - start + 1;
  String result;
  if (len <= 1){
    had_error = true;
    error_type = CLOX_ERROR_EMPTY_STRING;
    result = nullString();
    return result;
  }
  result.buffer = malloc(sizeof(char) * len);
  result.len = len;
  result.capacity = len;
  //spooky pointer arithmetic
  char *start_offset = str.buffer + start;
  memcpy(result.buffer, start_offset, len - 1);
  result.buffer[len-1] = '\0';
  printf("Sliced string: %s\n", result.buffer);
  return result;
}

String *String_toHeap(String text) {
  String *result = malloc(sizeof(String));
  result->len = text.len;
  result->capacity = text.capacity;
  result->buffer = text.buffer;
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

void String_destroy(String *s){
  String_drop(*s);
  free(s);
}
