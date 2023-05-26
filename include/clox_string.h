#ifndef CLOX_STRING_H
#define CLOX_STRING_H

#include <stdbool.h>
#include <stddef.h>

typedef struct{
  char *buffer;
  size_t capacity;
  size_t len;
} String;

bool String_isEmpty(String s);
String String_fromCharArray(const char *arr);
#endif
