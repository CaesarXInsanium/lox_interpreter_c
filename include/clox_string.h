#ifndef CLOX_STRING_H
#define CLOX_STRING_H

#include <stdbool.h>
#include <stddef.h>

// type to hold my shitty String type
// this struct owns the buffer pointer, allocated on heap
typedef struct{
  char *buffer;
  size_t capacity;
  size_t len;
} String;

String newString(int capacity);

bool String_isEmpty(String s);
// easy way of building String "shit like this"
String String_fromCharArray(const char *arr);
#endif
