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
String nullString(void);

bool String_isEmpty(String s);
// easy way of building String "shit like this"
String String_fromCharArray(const char *arr);

// create new string from slice
String String_fromSlice(String str, size_t start, size_t end);

// moves a string to head. Should be treated as having moved ownership outside of current scope
// does not deallocate buffer, must be handled seperatly
String *String_toHeap(String text);

// FUNCTION MUST BE CALLED  AT END OF SCOPE OR MEMORY LEAK HAPPENS
void String_drop(String s);

void String_destroy(String *s);
#endif
