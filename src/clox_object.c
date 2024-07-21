#include <stdio.h>
#include <clox_object.h>
#include <stdlib.h>
#include <clox_string.h>

void LoxObject_destroy(LoxObject *obj);

double parse_double(const String str){
  char *remainder = NULL;
  return strtod(str.buffer, &remainder);
}
